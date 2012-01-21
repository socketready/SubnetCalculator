#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    update_view();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_txtStartIP_editingFinished()
{
    update_view();
}

void MainWindow::on_spbSubnet_valueChanged(const QString &arg1)
{
    update_view();
}

void MainWindow::update_view()
{
    ipv.refresh(ui->txtStartIP->text().toStdString(), ui->spbSubnet->value());

    ui->lblBroadcastBin->setText(QString::fromStdString(ipv.b_getbroadcast()));
    ui->lblBroadcastDec->setText(QString::fromStdString(ipv.getbroadcast()));
    ui->lblBroadcastHex->setText(QString::fromStdString(ipv.h_getbroadcast()));

    ui->lblWildcardBin->setText(QString::fromStdString(ipv.b_getwildcard()));
    ui->lblWildcardDec->setText(QString::fromStdString(ipv.getwildcard()));
    ui->lblWildcardHex->setText(QString::fromStdString(ipv.h_getwildcard()));

    ui->lblNetmaskBin->setText(QString::fromStdString(ipv.b_getnetmask()));
    ui->lblNetmaskDec->setText(QString::fromStdString(ipv.getnetmask()));
    ui->lblNetmaskHex->setText(QString::fromStdString(ipv.h_getnetmask()));

    ui->lblNetworkBin->setText(QString::fromStdString(ipv.b_getnetwork()));
    ui->lblNetworkDec->setText(QString::fromStdString(ipv.getnetwork()));
    ui->lblNetworkHex->setText(QString::fromStdString(ipv.h_getnetwork()));

    ui->lblHostmaxBin->setText(QString::fromStdString(ipv.b_gethostmax()));
    ui->lblHostmaxDec->setText(QString::fromStdString(ipv.gethostmax()));
    ui->lblHostmaxHex->setText(QString::fromStdString(ipv.h_gethostmax()));

    ui->lblHostminBin->setText(QString::fromStdString(ipv.b_gethostmin()));
    ui->lblHostminDec->setText(QString::fromStdString(ipv.gethostmin()));
    ui->lblHostminHex->setText(QString::fromStdString(ipv.h_gethostmin()));

    ui->lblMaxHosts->setText(QString::fromStdString(ipv.getmaxhosts()));
}
