/********************************************************************************
** Form generated from reading UI file 'formulariomateriales.ui'
**
** Created: Wed 17. Jul 09:43:16 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULARIOMATERIALES_H
#define UI_FORMULARIOMATERIALES_H

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

class Ui_formularioMateriales
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *formularioMateriales)
    {
        if (formularioMateriales->objectName().isEmpty())
            formularioMateriales->setObjectName(QString::fromUtf8("formularioMateriales"));
        formularioMateriales->resize(400, 350);
        formularioMateriales->setMinimumSize(QSize(350, 250));
        formularioMateriales->setStyleSheet(QString::fromUtf8("QWidget#formularioMateriales{\n"
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
"     bac"
                        "kground:white;\n"
"     selection-background-color: darkgray;\n"
" }"));
        verticalLayout = new QVBoxLayout(formularioMateriales);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(formularioMateriales);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(6);
        formLayout->setVerticalSpacing(20);
        label_2 = new QLabel(formularioMateriales);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formularioMateriales);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit = new QLineEdit(formularioMateriales);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setMinimumSize(QSize(200, 0));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        lineEdit_2 = new QLineEdit(formularioMateriales);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        lineEdit_3 = new QLineEdit(formularioMateriales);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_5 = new QLabel(formularioMateriales);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formularioMateriales);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        lineEdit_4 = new QLineEdit(formularioMateriales);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_4);

        doubleSpinBox = new QDoubleSpinBox(formularioMateriales);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximum(1e+09);

        formLayout->setWidget(4, QFormLayout::FieldRole, doubleSpinBox);

        label_4 = new QLabel(formularioMateriales);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);


        horizontalLayout_2->addLayout(formLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(formularioMateriales);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(formularioMateriales);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(formularioMateriales);

        QMetaObject::connectSlotsByName(formularioMateriales);
    } // setupUi

    void retranslateUi(QWidget *formularioMateriales)
    {
        formularioMateriales->setWindowTitle(QApplication::translate("formularioMateriales", "formularioMateriales", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("formularioMateriales", "Materiales", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("formularioMateriales", "ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("formularioMateriales", "Nombre", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("formularioMateriales", "Geometr\303\255a", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("formularioMateriales", "Dimensiones", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("formularioMateriales", "Costo hora", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("formularioMateriales", "Crear", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("formularioMateriales", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class formularioMateriales: public Ui_formularioMateriales {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIOMATERIALES_H
