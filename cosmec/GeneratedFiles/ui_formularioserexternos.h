/********************************************************************************
** Form generated from reading UI file 'formularioserexternos.ui'
**
** Created: Sat 6. Jul 20:40:30 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULARIOSEREXTERNOS_H
#define UI_FORMULARIOSEREXTERNOS_H

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

class Ui_formularioSerExternos
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *formularioSerExternos)
    {
        if (formularioSerExternos->objectName().isEmpty())
            formularioSerExternos->setObjectName(QString::fromUtf8("formularioSerExternos"));
        formularioSerExternos->resize(350, 250);
        formularioSerExternos->setMinimumSize(QSize(350, 250));
        formularioSerExternos->setStyleSheet(QString::fromUtf8("QWidget#formularioSerExternos{\n"
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
"     border-radius: 5px;\n"
"     ba"
                        "ckground:white;\n"
"     selection-background-color: darkgray;\n"
" }"));
        verticalLayout = new QVBoxLayout(formularioSerExternos);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(formularioSerExternos);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setVerticalSpacing(20);
        label_2 = new QLabel(formularioSerExternos);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formularioSerExternos);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit = new QLineEdit(formularioSerExternos);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setMinimumSize(QSize(200, 0));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        lineEdit_2 = new QLineEdit(formularioSerExternos);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_4 = new QLabel(formularioSerExternos);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        doubleSpinBox = new QDoubleSpinBox(formularioSerExternos);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximum(1e+09);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox);


        horizontalLayout->addLayout(formLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(formularioSerExternos);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(formularioSerExternos);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(formularioSerExternos);

        QMetaObject::connectSlotsByName(formularioSerExternos);
    } // setupUi

    void retranslateUi(QWidget *formularioSerExternos)
    {
        formularioSerExternos->setWindowTitle(QApplication::translate("formularioSerExternos", "formularioSerExternos", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("formularioSerExternos", "Servicios Externos", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("formularioSerExternos", "ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("formularioSerExternos", "Nombre", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("formularioSerExternos", "Costo hora", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("formularioSerExternos", "Crear", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("formularioSerExternos", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class formularioSerExternos: public Ui_formularioSerExternos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIOSEREXTERNOS_H
