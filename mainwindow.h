#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ipconvertor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void update_view();
    ~MainWindow();
    
private slots:


    void on_txtStartIP_editingFinished();
    void on_spbSubnet_valueChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    IPConvertor ipv;
};

#endif // MAINWINDOW_H
