/********************************************************************************
** Form generated from reading UI file 'formularioherr.ui'
**
** Created: Thu 1. Aug 22:55:14 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULARIOHERR_H
#define UI_FORMULARIOHERR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formularioHerr
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QLabel *label_3;
    QLineEdit *lineEdit_5;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_5;
    QSpinBox *spinBox;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QLabel *label_8;
    QSpinBox *spinBox_2;
    QLabel *label_9;
    QLineEdit *lineEdit_3;
    QLabel *label_10;
    QLineEdit *lineEdit_6;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *formularioHerr)
    {
        if (formularioHerr->objectName().isEmpty())
            formularioHerr->setObjectName(QString::fromUtf8("formularioHerr"));
        formularioHerr->resize(700, 550);
        formularioHerr->setMinimumSize(QSize(700, 500));
        formularioHerr->setStyleSheet(QString::fromUtf8("QWidget#formularioHerr{\n"
"background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(221, 235, 255, 255), stop:0.522727 rgba(255, 255, 255, 255));\n"
"border: 1px solid black;\n"
"}\n"
".QFrame {\n"
" border: 1px inset gray;\n"
" border-radius: 5px;\n"
" background:  transparent;\n"
"}\n"
"QLabel#label {/*titulos de p\303\241g*/\n"
"border: 1px inset gray;\n"
" border-radius: 5px;\n"
"font: bold 12pt \"Calibri\";\n"
"background:rgb(0, 85, 127);\n"
"color:white;\n"
"qproperty-alignment: AlignCenter\n"
"}\n"
"QLabel{\n"
"border: 0px;\n"
"font: 11pt \"Arial\";\n"
"background: transparent;\n"
"}\n"
"QPushButton#pushButton_3{ /*ayuda*/\n"
"  border: 1px inset darkblue;\n"
"  border-radius:12px;\n"
" font: bold 12pt \"Calibri\";\n"
"}\n"
".QPushButton {\n"
"background: qlineargradient(\n"
"  x1:0, y1:0, x2:0, y2:1,\n"
"  stop:0 #68778e,\n"
"  stop: 0.4 #5c637d\n"
"  stop: 0.5 #717990,\n"
"  stop:1 #bec1d2\n"
" );\n"
" color: white;\n"
"}\n"
"QLineEdit {\n"
"     border: 1px inset darkblue;\n"
"    "
                        " border-radius: 5px;\n"
"     background:white;\n"
"     selection-background-color: darkgray;\n"
" }"));
        verticalLayout = new QVBoxLayout(formularioHerr);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(formularioHerr);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 30));

        horizontalLayout_5->addWidget(label);

        pushButton_3 = new QPushButton(formularioHerr);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(25, 25));
        pushButton_3->setMaximumSize(QSize(25, 25));

        horizontalLayout_5->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 6, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setVerticalSpacing(20);
        label_2 = new QLabel(formularioHerr);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit_4 = new QLineEdit(formularioHerr);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        lineEdit_4->setMinimumSize(QSize(300, 0));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_4);

        label_3 = new QLabel(formularioHerr);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_5 = new QLineEdit(formularioHerr);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_5);

        label_4 = new QLabel(formularioHerr);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        doubleSpinBox = new QDoubleSpinBox(formularioHerr);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximum(1e+09);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox);

        label_5 = new QLabel(formularioHerr);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        spinBox = new QSpinBox(formularioHerr);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(999999999);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBox);

        label_6 = new QLabel(formularioHerr);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        lineEdit = new QLineEdit(formularioHerr);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit);

        label_7 = new QLabel(formularioHerr);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        lineEdit_2 = new QLineEdit(formularioHerr);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(false);

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_2);

        label_8 = new QLabel(formularioHerr);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_8);

        spinBox_2 = new QSpinBox(formularioHerr);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(999999999);

        formLayout->setWidget(6, QFormLayout::FieldRole, spinBox_2);

        label_9 = new QLabel(formularioHerr);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_9);

        lineEdit_3 = new QLineEdit(formularioHerr);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEdit_3);

        label_10 = new QLabel(formularioHerr);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_10);

        lineEdit_6 = new QLineEdit(formularioHerr);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setEnabled(false);

        formLayout->setWidget(8, QFormLayout::FieldRole, lineEdit_6);

        comboBox = new QComboBox(formularioHerr);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(9, QFormLayout::FieldRole, comboBox);


        horizontalLayout_2->addLayout(formLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        label_11 = new QLabel(formularioHerr);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setPixmap(QPixmap(QString::fromUtf8("../Win32/Release/costo_herramienta.png")));

        horizontalLayout_4->addWidget(label_11);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(formularioHerr);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(formularioHerr);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(formularioHerr);

        QMetaObject::connectSlotsByName(formularioHerr);
    } // setupUi

    void retranslateUi(QWidget *formularioHerr)
    {
        formularioHerr->setWindowTitle(QApplication::translate("formularioHerr", "formularioHerr", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("formularioHerr", "Herramienta", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("formularioHerr", "?", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("formularioHerr", "ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("formularioHerr", "Nombre", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("formularioHerr", "Valor unitario [$]", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("formularioHerr", "Vida \303\272til [a\303\261os]", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("formularioHerr", "Depreciaci\303\263n [$]", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("formularioHerr", "Costo hora [$/h]", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("formularioHerr", "Cantidad anual [u]", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("formularioHerr", "Costo total [$]", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("formularioHerr", "M\303\241quina", 0, QApplication::UnicodeUTF8));
        label_11->setText(QString());
        pushButton->setText(QApplication::translate("formularioHerr", "Crear", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("formularioHerr", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class formularioHerr: public Ui_formularioHerr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIOHERR_H
