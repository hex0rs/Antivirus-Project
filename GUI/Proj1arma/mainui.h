#ifndef MAINUI_H
#define MAINUI_H

#include <QMainWindow>

#include "setting/setting.h"
#include "state/state.h"
#include "scan/scan.h"


namespace Ui {
class MainUi;
}

class MainUi : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainUi(QWidget *parent = 0);
    ~MainUi();
    
    Ui::MainUi * getUi();
    
    Scan    scan;
    State   state;
    Setting setting;
    
private slots:
    void on_close_clicked();
    
    void on_min_clicked();
    
    void on_settingPushButton_clicked();
    
    void on_scanPushButton_clicked();
    
    void on_statePushButton_clicked();

private:
    Ui::MainUi *ui;
    
};

#endif // MAINUI_H
