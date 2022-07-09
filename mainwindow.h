#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QPushButton>
#include <QPixmap>
#include <QTextEdit>
#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include <QByteArray>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addTool(QString iconPath);

private:
    Ui::MainWindow *ui;

    QToolBar *tBar;

    QPushButton *openBtn;
    QPushButton *quitBtn;

    QTextEdit *tEdit;

};

#endif // MAINWINDOW_H
