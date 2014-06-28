#include "realtimproui.h"
#include "ui_realtimproui.h"

RealTimProUi::RealTimProUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RealTimProUi)
{
    ui->setupUi(this);
}

RealTimProUi::~RealTimProUi()
{
    delete ui;
}
