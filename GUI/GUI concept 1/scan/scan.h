#ifndef SCAN_H
#define SCAN_H

#include <QWidget>

namespace Ui {
class Scan;
}

class Scan : public QWidget
{
    Q_OBJECT
    
public:
    explicit Scan(QWidget *parent = 0);
    ~Scan();
    
    Ui::Scan *getUi();
    
private:
    Ui::Scan *ui;
};

#endif // SCAN_H
