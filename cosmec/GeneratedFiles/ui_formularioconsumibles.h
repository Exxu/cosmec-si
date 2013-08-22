/********************************************************************************
** Form generated from reading UI file 'formularioconsumibles.ui'
**
** Created: Wed 21. Aug 21:47:35 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULARIOCONSUMIBLES_H
#define UI_FORMULARIOCONSUMIBLES_H

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
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formularioConsumibles
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_7;
    QLineEdit *lineEdit_4;
    QComboBox *comboBox;
    QLabel *label_9;
    QPlainTextEdit *plainTextEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *formularioConsumibles)
    {
        if (formularioConsumibles->objectName().isEmpty())
            formularioConsumibles->setObjectName(QString::fromUtf8("formularioConsumibles"));
        formularioConsumibles->resize(500, 471);
        formularioConsumibles->setStyleSheet(QString::fromUtf8("QWidget#formularioConsumibles{\n"
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
"QLabel#label_11 {/*foto*/\n"
"border: 1px inset gray;\n"
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
"  s"
                        "top:1 #bec1d2\n"
" );\n"
" color: white;\n"
"}\n"
"QLineEdit {\n"
"     border: 1px inset darkblue;\n"
"     border-radius: 5px;\n"
"     background:white;\n"
"     selection-background-color: darkgray;\n"
" }"));
        verticalLayout = new QVBoxLayout(formularioConsumibles);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(formularioConsumibles);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 30));

        horizontalLayout_5->addWidget(label);

        pushButton_3 = new QPushButton(formularioConsumibles);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(25, 25));
        pushButton_3->setMaximumSize(QSize(25, 25));

        horizontalLayout_5->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 8, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setVerticalSpacing(15);
        label_2 = new QLabel(formularioConsumibles);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit = new QLineEdit(formularioConsumibles);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setMinimumSize(QSize(300, 20));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(formularioConsumibles);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_2 = new QLineEdit(formularioConsumibles);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(200, 20));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_4 = new QLabel(formularioConsumibles);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        doubleSpinBox = new QDoubleSpinBox(formularioConsumibles);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMinimumSize(QSize(0, 20));
        doubleSpinBox->setMaximum(1e+09);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox);

        label_7 = new QLabel(formularioConsumibles);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        lineEdit_4 = new QLineEdit(formularioConsumibles);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setEnabled(false);
        lineEdit_4->setMinimumSize(QSize(0, 20));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_4);

        comboBox = new QComboBox(formularioConsumibles);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(0, 20));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox);

        label_9 = new QLabel(formularioConsumibles);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_9);

        plainTextEdit = new QPlainTextEdit(formularioConsumibles);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setMinimumSize(QSize(0, 40));

        formLayout->setWidget(5, QFormLayout::FieldRole, plainTextEdit);


        horizontalLayout_3->addLayout(formLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        label_8 = new QLabel(formularioConsumibles);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setPixmap(QPixmap(QString::fromUtf8("costo_cons.png")));

        horizontalLayout_4->addWidget(label_8);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(formularioConsumibles);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(formularioConsumibles);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(formularioConsumibles);

        QMetaObject::connectSlotsByName(formularioConsumibles);
    } // setupUi

    void retranslateUi(QWidget *formularioConsumibles)
    {
        formularioConsumibles->setWindowTitle(QApplication::translate("formularioConsumibles", "formularioConsumibles", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("formularioConsumibles", "Consumibles", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("formularioConsumibles", "?", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("formularioConsumibles", "ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("formularioConsumibles", "Nombre", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("formularioConsumibles", "Valor unitario [$]", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("formularioConsumibles", "M\303\241quina", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("formularioConsumibles", "Aplicaciones", 0, QApplication::UnicodeUTF8));
        label_8->setText(QString());
        pushButton->setText(QApplication::translate("formularioConsumibles", "Crear", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("formularioConsumibles", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class formularioConsumibles: public Ui_formularioConsumibles {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIOCONSUMIBLES_H
