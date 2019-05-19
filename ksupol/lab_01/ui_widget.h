/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *ShiftButton;
    QPushButton *ScaleButton;
    QPushButton *TurnButton;
    QPushButton *ProjectP;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_4;
    QLabel *label_16;
    QLineEdit *ShiftX;
    QLineEdit *ShiftY;
    QLineEdit *ShiftZ;
    QLabel *label_17;
    QLineEdit *ScaleX;
    QLineEdit *ScaleY;
    QLineEdit *ScaleZ;
    QLineEdit *TurnAngle;
    QLineEdit *CenterX;
    QLineEdit *CenterY;
    QLineEdit *CenterZ;
    QLabel *label_18;
    QLabel *label_5;
    QRadioButton *CheckX;
    QRadioButton *CheckY;
    QRadioButton *CheckZ;
    QPushButton *ProjectC;
    QPushButton *OpenFile;
    QPushButton *SaveModel;
    QLineEdit *Distance;
    QLabel *label_6;
    QLabel *label_19;
    QLabel *label_20;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1100, 710);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(700, 0, 400, 711));
        QFont font;
        font.setKerning(true);
        groupBox->setFont(font);
        groupBox->setAutoFillBackground(true);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 200, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 140, 200, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 270, 200, 20));
        ShiftButton = new QPushButton(groupBox);
        ShiftButton->setObjectName(QStringLiteral("ShiftButton"));
        ShiftButton->setGeometry(QRect(10, 100, 141, 27));
        ScaleButton = new QPushButton(groupBox);
        ScaleButton->setObjectName(QStringLiteral("ScaleButton"));
        ScaleButton->setGeometry(QRect(10, 230, 141, 27));
        TurnButton = new QPushButton(groupBox);
        TurnButton->setObjectName(QStringLiteral("TurnButton"));
        TurnButton->setGeometry(QRect(10, 320, 141, 27));
        ProjectP = new QPushButton(groupBox);
        ProjectP->setObjectName(QStringLiteral("ProjectP"));
        ProjectP->setGeometry(QRect(10, 390, 141, 27));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 30, 120, 20));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 50, 120, 20));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 160, 111, 20));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 550, 151, 20));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(160, 550, 21, 20));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(160, 570, 21, 20));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 290, 111, 20));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(130, 160, 21, 20));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(130, 180, 21, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(250, 290, 67, 17));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 70, 120, 20));
        ShiftX = new QLineEdit(groupBox);
        ShiftX->setObjectName(QStringLiteral("ShiftX"));
        ShiftX->setGeometry(QRect(120, 30, 113, 20));
        ShiftY = new QLineEdit(groupBox);
        ShiftY->setObjectName(QStringLiteral("ShiftY"));
        ShiftY->setGeometry(QRect(120, 50, 113, 20));
        ShiftZ = new QLineEdit(groupBox);
        ShiftZ->setObjectName(QStringLiteral("ShiftZ"));
        ShiftZ->setGeometry(QRect(120, 70, 113, 20));
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(130, 200, 21, 20));
        ScaleX = new QLineEdit(groupBox);
        ScaleX->setObjectName(QStringLiteral("ScaleX"));
        ScaleX->setGeometry(QRect(150, 160, 113, 20));
        ScaleY = new QLineEdit(groupBox);
        ScaleY->setObjectName(QStringLiteral("ScaleY"));
        ScaleY->setGeometry(QRect(150, 180, 113, 20));
        ScaleZ = new QLineEdit(groupBox);
        ScaleZ->setObjectName(QStringLiteral("ScaleZ"));
        ScaleZ->setGeometry(QRect(150, 200, 113, 20));
        TurnAngle = new QLineEdit(groupBox);
        TurnAngle->setObjectName(QStringLiteral("TurnAngle"));
        TurnAngle->setGeometry(QRect(130, 290, 113, 20));
        CenterX = new QLineEdit(groupBox);
        CenterX->setObjectName(QStringLiteral("CenterX"));
        CenterX->setGeometry(QRect(180, 550, 113, 20));
        CenterY = new QLineEdit(groupBox);
        CenterY->setObjectName(QStringLiteral("CenterY"));
        CenterY->setGeometry(QRect(180, 570, 113, 20));
        CenterZ = new QLineEdit(groupBox);
        CenterZ->setObjectName(QStringLiteral("CenterZ"));
        CenterZ->setGeometry(QRect(180, 590, 113, 20));
        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(160, 590, 21, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 620, 31, 17));
        CheckX = new QRadioButton(groupBox);
        CheckX->setObjectName(QStringLiteral("CheckX"));
        CheckX->setEnabled(true);
        CheckX->setGeometry(QRect(50, 620, 41, 20));
        CheckX->setChecked(true);
        CheckY = new QRadioButton(groupBox);
        CheckY->setObjectName(QStringLiteral("CheckY"));
        CheckY->setGeometry(QRect(90, 620, 41, 20));
        CheckZ = new QRadioButton(groupBox);
        CheckZ->setObjectName(QStringLiteral("CheckZ"));
        CheckZ->setGeometry(QRect(130, 620, 41, 20));
        ProjectC = new QPushButton(groupBox);
        ProjectC->setObjectName(QStringLiteral("ProjectC"));
        ProjectC->setGeometry(QRect(10, 490, 141, 27));
        OpenFile = new QPushButton(groupBox);
        OpenFile->setObjectName(QStringLiteral("OpenFile"));
        OpenFile->setGeometry(QRect(180, 660, 99, 27));
        SaveModel = new QPushButton(groupBox);
        SaveModel->setObjectName(QStringLiteral("SaveModel"));
        SaveModel->setGeometry(QRect(290, 660, 99, 27));
        Distance = new QLineEdit(groupBox);
        Distance->setObjectName(QStringLiteral("Distance"));
        Distance->setGeometry(QRect(220, 460, 113, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 360, 231, 20));
        label_19 = new QLabel(groupBox);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 430, 231, 20));
        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(10, 460, 211, 20));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Widget", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", 0));
        label_2->setText(QApplication::translate("Widget", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0));
        label_3->setText(QApplication::translate("Widget", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", 0));
        ShiftButton->setText(QApplication::translate("Widget", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", 0));
        ScaleButton->setText(QApplication::translate("Widget", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
        TurnButton->setText(QApplication::translate("Widget", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", 0));
        ProjectP->setText(QApplication::translate("Widget", "\320\241\320\277\321\200\320\276\320\265\321\206\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
        label_7->setText(QApplication::translate("Widget", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 dX:", 0));
        label_8->setText(QApplication::translate("Widget", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 dY:", 0));
        label_9->setText(QApplication::translate("Widget", "\320\232\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202:", 0));
        label_10->setText(QApplication::translate("Widget", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213 \321\206\320\265\320\275\321\202\321\200\320\260:", 0));
        label_11->setText(QApplication::translate("Widget", "X", 0));
        label_12->setText(QApplication::translate("Widget", "Y", 0));
        label_13->setText(QApplication::translate("Widget", "\320\243\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260:", 0));
        label_14->setText(QApplication::translate("Widget", "X", 0));
        label_15->setText(QApplication::translate("Widget", "Y", 0));
        label_4->setText(QApplication::translate("Widget", "[\320\263\321\200\320\260\320\264\321\203\321\201\321\213]", 0));
        label_16->setText(QApplication::translate("Widget", "\320\241\320\274\320\265\321\211\320\265\320\275\320\270\320\265 dZ:", 0));
        ShiftX->setText(QApplication::translate("Widget", "10", 0));
        ShiftY->setText(QApplication::translate("Widget", "10", 0));
        ShiftZ->setText(QApplication::translate("Widget", "10", 0));
        label_17->setText(QApplication::translate("Widget", "Z", 0));
        ScaleX->setText(QApplication::translate("Widget", "2", 0));
        ScaleY->setText(QApplication::translate("Widget", "2", 0));
        ScaleZ->setText(QApplication::translate("Widget", "2", 0));
        TurnAngle->setText(QApplication::translate("Widget", "10", 0));
        CenterX->setText(QApplication::translate("Widget", "0", 0));
        CenterY->setText(QApplication::translate("Widget", "0", 0));
        CenterZ->setText(QApplication::translate("Widget", "0", 0));
        label_18->setText(QApplication::translate("Widget", "Z", 0));
        label_5->setText(QApplication::translate("Widget", "\320\236\321\201\321\214:", 0));
        CheckX->setText(QApplication::translate("Widget", "X", 0));
        CheckY->setText(QApplication::translate("Widget", "Y", 0));
        CheckZ->setText(QApplication::translate("Widget", "Z", 0));
        ProjectC->setText(QApplication::translate("Widget", "\320\241\320\277\321\200\320\276\320\265\321\206\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
        OpenFile->setText(QApplication::translate("Widget", "Open file", 0));
        SaveModel->setText(QApplication::translate("Widget", "Save", 0));
        Distance->setText(QApplication::translate("Widget", "500", 0));
        label_6->setText(QApplication::translate("Widget", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\276\320\265 \320\277\321\200\320\276\320\265\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0));
        label_19->setText(QApplication::translate("Widget", "\320\246\320\265\320\275\321\202\321\200\320\260\320\273\321\214\320\275\320\276\320\265 \320\277\321\200\320\276\320\265\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0));
        label_20->setText(QApplication::translate("Widget", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\275\320\260\320\261\320\273\321\216\320\264\320\260\321\202\320\265\320\273\321\217", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
