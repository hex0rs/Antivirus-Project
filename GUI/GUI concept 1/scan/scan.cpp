#include "scan.h"
#include "ui_scan.h"

Scan::Scan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scan)
{
    ui->setupUi(this);
}

Scan::~Scan()
{
    delete ui;
}

Ui::Scan *Scan::getUi(){
    return ui;
}
