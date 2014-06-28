#ifndef EXCLUDEDFILETYPE_H
#define EXCLUDEDFILETYPE_H

#include <QWidget>

namespace Ui {
class ExcludedFileType;
}

class ExcludedFileType : public QWidget
{
    Q_OBJECT
    
public:
    explicit ExcludedFileType(QWidget *parent = 0);
    ~ExcludedFileType();
    
    Ui::ExcludedFileType * getUi(){
        return ui;
    }
private:
    Ui::ExcludedFileType *ui;
};

#endif // EXCLUDEDFILETYPE_H
