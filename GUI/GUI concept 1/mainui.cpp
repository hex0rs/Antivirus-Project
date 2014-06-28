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
    
//    setting.show();
//    scan.show();
//    state.show();
    
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
    setting.setParent(ui->tabWidget);
    setting.show();
    
    QEventLoop loop;
    for(int i=-100;i<=-50;i++){
        setting.move(i,0);    
        
        QTimer::singleShot(0.5,&loop,SLOT(quit()));
        loop.exec();
    }
    for(int i=-100;i<=-50;i++){
        setting.move(i,0);        
        QTimer::singleShot(1,&loop,SLOT(quit()));
        loop.exec();
    }
    for(int i=-50;i<=0;i++){
        setting.move(i,0);        
        QTimer::singleShot(0.000001,&loop,SLOT(quit()));
        loop.exec();
    }
    
}

void MainUi::on_scanPushButton_clicked()
{
    QEventLoop loop;
    scan.setParent(ui->tabWidget);
    scan.show();
    
    int k=-200;
    for(int i=0;i<=2000;i++){
        setting.move(i,0);
        if(k!=0){
        scan.move(k,0);
        }
        k++;
        QTimer::singleShot(0.000001,&loop,SLOT(quit()));
        loop.exec();
    }
}
