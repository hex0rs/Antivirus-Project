#include "scan.h"
#include "ui_scan.h"

#include "scan/scanini.h"
#include "ui_scanini.h"

Scan::Scan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scan)
{
    ui->setupUi(this);

    scaninim.setParent(ui->appscan);
}

Scan::~Scan()
{
    delete ui;
}

Ui::Scan *Scan::getUi(){
    return ui;
}

void Scan::on_pushButton_clicked()
{

}

void Scan::on_pushButton_2_clicked()
{


}
