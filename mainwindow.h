#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    float pKp;
    float piKp, piTi;

private slots:
    void makePlot();

    void on_pKp_valueChanged(double arg1);

    void on_piKp_valueChanged(double arg1);

    void on_piTi_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
