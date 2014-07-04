#ifndef ADVANCED_H
#define ADVANCED_H

#include <QWidget>

namespace Ui {
class Advanced;
}

class Advanced : public QWidget
{
    Q_OBJECT
    
public:
    explicit Advanced(QWidget *parent = 0);
    ~Advanced();
    
    Ui::Advanced * getUi();
    
private:
    Ui::Advanced *ui;
};

#endif // ADVANCED_H
