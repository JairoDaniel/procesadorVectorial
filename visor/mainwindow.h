#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void test();
    //REGV
    std::string regA, regB, regWR;
    std::string upperF, lowerF, regRD, wrF, wrFO;
    //ALU
    std::string op;
    //LSU
    std::string flagM;
    std::string RD, WR;
    //REGE
    std::string rdFE, wrFE;
    std::string regAE, regWRE;


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
