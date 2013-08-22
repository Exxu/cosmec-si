/********************************************************************************
** Form generated from reading UI file 'formulariocargos.ui'
**
** Created: Wed 21. Aug 21:47:35 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULARIOCARGOS_H
#define UI_FORMULARIOCARGOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formularioCargos
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *formularioCargos)
    {
        if (formularioCargos->objectName().isEmpty())
            formularioCargos->setObjectName(QString::fromUtf8("formularioCargos"));
        formularioCargos->resize(350, 250);
        formularioCargos->setMinimumSize(QSize(350, 250));
        formularioCargos->setStyleSheet(QString::fromUtf8("QWidget#formularioCargos{\n"
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
"  stop:1"
                        " #bec1d2\n"
" );\n"
" color: white;\n"
"}\n"
"QLineEdit {\n"
"     border: 1px inset darkblue;\n"
"     border-radius: 5px;\n"
"     background:white;\n"
"     selection-background-color: darkgray;\n"
" }"));
        verticalLayout = new QVBoxLayout(formularioCargos);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(formularioCargos);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(label);

        pushButton_3 = new QPushButton(formularioCargos);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(25, 25));
        pushButton_3->setMaximumSize(QSize(25, 25));

        horizontalLayout_3->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setVerticalSpacing(20);
        label_2 = new QLabel(formularioCargos);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formularioCargos);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formularioCargos);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        lineEdit = new QLineEdit(formularioCargos);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setMinimumSize(QSize(200, 0));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        lineEdit_2 = new QLineEdit(formularioCargos);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        doubleSpinBox = new QDoubleSpinBox(formularioCargos);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximum(1e+09);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox);


        horizontalLayout_2->addLayout(formLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(formularioCargos);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(formularioCargos);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(formularioCargos);

        QMetaObject::connectSlotsByName(formularioCargos);
    } // setupUi

    void retranslateUi(QWidget *formularioCargos)
    {
        formularioCargos->setWindowTitle(QApplication::translate("formularioCargos", "formularioCargos", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("formularioCargos", "Cargos", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("formularioCargos", "?", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("formularioCargos", "ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("formularioCargos", "Nombre ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("formularioCargos", "Salario [$]", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("formularioCargos", "Crear", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("formularioCargos", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class formularioCargos: public Ui_formularioCargos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIOCARGOS_H
