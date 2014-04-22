/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *pic;
    QFrame *frame;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QFrame *frame_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(845, 542);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/avlogo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        MainWindow->setDockNestingEnabled(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pic = new QLabel(centralWidget);
        pic->setObjectName(QStringLiteral("pic"));
        pic->setGeometry(QRect(10, 20, 311, 71));
        pic->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/banner.png")));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 845, 542));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QStringLiteral("color: rgb(26, 162, 162);"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(2);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(334, 420, 159, 70));
        pushButton->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/scan.png);\n"
"border:none;"));
        pushButton->setAutoRepeat(false);
        pushButton->setAutoDefault(false);
        pushButton->setFlat(true);
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(690, 41, 101, 41));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/setting.png);\n"
"border: none;"));
        pushButton_3->setFlat(true);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 490, 101, 41));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/quar.png);\n"
"border: none;"));
        pushButton_2->setFlat(true);
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(798, 3, 26, 25));
        pushButton_5->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/min.png);\n"
"border: none;"));
        pushButton_5->setFlat(false);
        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(818, 3, 25, 25));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_4->setFont(font2);
        pushButton_4->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/close.png);\n"
"border: none;"));
        pushButton_4->setAutoDefault(false);
        pushButton_4->setDefault(false);
        pushButton_4->setFlat(true);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(3, 90, 839, 21));
        frame_2->setStyleSheet(QStringLiteral("color: rgb(26, 162, 162);"));
        frame_2->setFrameShape(QFrame::HLine);
        frame_2->setFrameShadow(QFrame::Plain);
        frame_2->setLineWidth(4);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(260, 130, 371, 281));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/etio.png")));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(270, 120, 371, 281));
        label_2->raise();
        pushButton->raise();
        pushButton_3->raise();
        pushButton_2->raise();
        pushButton_5->raise();
        pushButton_4->raise();
        frame_2->raise();
        label->raise();
        MainWindow->setCentralWidget(centralWidget);
        frame->raise();
        pic->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Antivirus Project", 0));
        pic->setText(QString());
        pushButton->setText(QString());
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
        pushButton_5->setText(QString());
        pushButton_4->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
