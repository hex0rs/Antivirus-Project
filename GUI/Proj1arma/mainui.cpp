#include "mainui.h"
#include "ui_mainui.h"

#include "setting/setting.h"
#include "ui_setting.h"

#include "scan/scan.h"
#include "ui_scan.h"

#include "state/state.h"
#include "ui_state.h"

#include <QTimer>
#include<QEventLoop>


MainUi::MainUi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainUi)
{
    ui->setupUi(this);
    
    state.setParent(ui->tabWidget);
    state.show();


}

MainUi::~MainUi()
{
    delete ui;
}

Ui::MainUi *MainUi::getUi() {
    return ui;
}

void MainUi::on_close_clicked()
{
//    exit(0);
    close();
}

void MainUi::on_min_clicked()
{
    showMinimized();
}

void MainUi::on_settingPushButton_clicked()
{
//    ui->tabWidget = setting.getUi()->tabSetting;
//    setting.getUi()->tabSetting->show();
    scan.hide();
    state.hide();
    setting.setParent(ui->tabWidget);
    setting.show();
    
    QEventLoop loop;
    for(int i=-50;i<=0;i++){
        setting.move(i,0);    
        
        QTimer::singleShot(0.1,&loop,SLOT(quit()));
        loop.exec();
    }
    
}

void MainUi::on_scanPushButton_clicked()
{
    setting.hide();
    state.hide();
    scan.setParent(ui->tabWidget);
    scan.show();
    QEventLoop loop;
    for(int i=-50;i<=0;i++){
        scan.move(i,0);
        //scan.styleSheet("opacity: "+i+";");
        QTimer::singleShot(0.1,&loop,SLOT(quit()));
        loop.exec();
    }
}

void MainUi::on_statePushButton_clicked()
{
    setting.hide();
    scan.hide();
    state.setParent(ui->tabWidget);
    state.show();

    QEventLoop loop;
    for(int i=-50;i<=0;i++){
        state.move(i,0);

        QTimer::singleShot(0.1,&loop,SLOT(quit()));
        loop.exec();
    }

}
