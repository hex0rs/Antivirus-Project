#ifndef STATE_H
#define STATE_H

#include <QWidget>

namespace Ui {
class State;
}

class State : public QWidget
{
    Q_OBJECT
    
public:
    explicit State(QWidget *parent = 0);
    ~State();
    
    Ui::State * getUi(){
        return ui;
    }
    
private:
    Ui::State *ui;
};

#endif // STATE_H
