#include "scanini.h"
#include "ui_scanini.h"

scanini::scanini(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scanini)
{
    ui->setupUi(this);

}

scanini::~scanini()
{
    delete ui;
}

Ui::scanini *scanini::getUi(){
    return ui;
}
