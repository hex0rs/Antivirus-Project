#ifndef SCAN_H
#define SCAN_H

#include <QWidget>

#include "scan/scanini.h"

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

    scanini scaninim;
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Scan *ui;
};

#endif // SCAN_H
