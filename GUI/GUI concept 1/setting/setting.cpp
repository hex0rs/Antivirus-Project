#include "setting.h"
#include "ui_setting.h"

#include "setting/advanced.h"
#include "setting/realtimproui.h"
#include "setting/excludedfiletype.h"

#include "ui_advanced.h"
#include "ui_realtimproui.h"
#include "ui_excludedfiletype.h"



Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    
    
    
}

Setting::~Setting()
{
    delete ui;
}

Ui::Setting *Setting::getUi(){
    return ui;
}

void Setting::on_advancedButton_clicked()
{
    advanced.setParent(ui->appSetting);
    advanced.show();
    
}

void Setting::on_realTimeButton_clicked()
{
    realTimProUim.setParent(ui->appSetting);
    realTimProUim.show();
    
}
