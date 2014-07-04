#ifndef SCANINI_H
#define SCANINI_H

#include <QWidget>

namespace Ui {
class scanini;
}

class scanini : public QWidget
{
    Q_OBJECT
    
public:
    explicit scanini(QWidget *parent = 0);
    ~scanini();
    
    Ui::scanini * getUi();

private:
    Ui::scanini *ui;
};

#endif // SCANINI_H
