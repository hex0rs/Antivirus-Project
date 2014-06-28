#include "mainui.h"
#include <QApplication>

#include "setting/setting.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    MainUi w;
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();
    
//    Setting se;
//    se.show();
    
    return a.exec();
}
