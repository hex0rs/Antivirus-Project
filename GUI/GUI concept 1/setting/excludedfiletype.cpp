#include "excludedfiletype.h"
#include "ui_excludedfiletype.h"

ExcludedFileType::ExcludedFileType(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExcludedFileType)
{
    ui->setupUi(this);
}

ExcludedFileType::~ExcludedFileType()
{
    delete ui;
}
