#ifndef SETTING_H
#define SETTING_H

#include <QWidget>

#include "setting/advanced.h"
#include "setting/realtimproui.h"
#include "setting/excludedfiletype.h"


namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT
    
public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();
    Ui::Setting * getUi();
    
    Advanced advanced ;
    RealTimProUi realTimProUim;
    ExcludedFileType excludedFileType;
    
private slots:
    void on_advancedButton_clicked();
    
    void on_realTimeButton_clicked();
    
    
    
private:
    Ui::Setting *ui;
};

#endif // SETTING_H
