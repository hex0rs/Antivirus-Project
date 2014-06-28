#include "advanced.h"
#include "ui_advanced.h"

Advanced::Advanced(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Advanced)
{
    ui->setupUi(this);
}

Advanced::~Advanced()
{
    delete ui;
}

Ui::Advanced *Advanced::getUi(){
    return ui;
}
