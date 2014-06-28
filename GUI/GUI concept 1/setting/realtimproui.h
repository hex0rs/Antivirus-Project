#ifndef REALTIMPROUI_H
#define REALTIMPROUI_H

#include <QWidget>

namespace Ui {
class RealTimProUi;
}

class RealTimProUi : public QWidget
{
    Q_OBJECT
    
public:
    explicit RealTimProUi(QWidget *parent = 0);
    ~RealTimProUi();
    
    Ui::RealTimProUi * getUi(){
        return ui;
    }
private:
    Ui::RealTimProUi *ui;
};

#endif // REALTIMPROUI_H
