#include "mainwindow.h"
#include "ui_mainwindow.h"

#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenuBar *mBar = menuBar();
    setMenuBar(mBar);

    // 增加文件菜单项
    QMenu *pFile = mBar->addMenu("File");
    QAction *openFile = pFile->addAction("OPen");
    QAction *newFile = pFile->addAction("New");
    QAction *quit = pFile->addAction("Exit");

    // 增加工具栏
    tBar = new QToolBar();
    this->addToolBar(tBar);

    // 增加打开文件快捷工具
    openBtn = new QPushButton(this);
    QPixmap pix;
    pix.load(":/images/document-open.png");
    openBtn->setFixedSize(pix.width(), pix.height());
    openBtn->setIcon(QIcon(pix));
    openBtn->setStyleSheet("QPushButton{border:0px;}");
    tBar->addWidget(openBtn);

    // 增加退出快捷工具
    quitBtn = new QPushButton(this);
    QPixmap pix2;
    pix2.load(":/images/gtk-quit.png");
    quitBtn->setFixedSize(pix2.width(), pix2.height());
    quitBtn->setIcon(QIcon(pix2));
    quitBtn->setStyleSheet("QPushButton{border:0px;}");
    tBar->addWidget(quitBtn);




    // 菜单项里的退出信号连接
    connect(quit, &QAction::triggered, this, [=]() {
        this->close();
    });
    // 退出的快捷方式连接
    connect(quitBtn, &QPushButton::clicked, this, [=]() {
        this->close();
    });

    connect(openFile, &QAction::triggered, this, [=]() {
        QString path = QFileDialog::getOpenFileName(this, "Open File", "../", "Text(*.txt)");
        cout << path;
        if(path.isEmpty() == false) {
            QFile file(path);
            bool isOk = file.open(QIODevice::ReadOnly);
            if(isOk) {
                QByteArray array;
                while(file.atEnd() == false) {
                    array += file.readLine();
                }
                tEdit->setText(QString(array));
            }
        }
    });


    tEdit = new QTextEdit(this);
    this->setCentralWidget(tEdit);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTool(QString iconPath)
{

}

