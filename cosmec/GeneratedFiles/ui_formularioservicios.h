/********************************************************************************
** Form generated from reading UI file 'formularioservicios.ui'
**
** Created: Thu 4. Jul 19:34:39 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULARIOSERVICIOS_H
#define UI_FORMULARIOSERVICIOS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formularioServicios
{
public:
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QDoubleSpinBox *doubleSpinBox;
    QSpinBox *spinBox;
    QLineEdit *lineEdit_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QLabel *label_9;
    QLineEdit *lineEdit_5;
    QLabel *label_10;
    QLineEdit *lineEdit_6;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *formularioServicios)
    {
        if (formularioServicios->objectName().isEmpty())
            formularioServicios->setObjectName(QString::fromUtf8("formularioServicios"));
        formularioServicios->resize(688, 488);
        label = new QLabel(formularioServicios);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 30, 151, 16));
        formLayoutWidget = new QWidget(formularioServicios);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(230, 100, 241, 256));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        lineEdit_2 = new QLineEdit(formLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        doubleSpinBox = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximum(1e+09);

        formLayout->setWidget(3, QFormLayout::FieldRole, doubleSpinBox);

        spinBox = new QSpinBox(formLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(999999999);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox);

        lineEdit_3 = new QLineEdit(formLayoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_3);

        doubleSpinBox_2 = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setMaximum(1e+09);

        formLayout->setWidget(5, QFormLayout::FieldRole, doubleSpinBox_2);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_8);

        lineEdit_4 = new QLineEdit(formLayoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setEnabled(false);

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_4);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_9);

        lineEdit_5 = new QLineEdit(formLayoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEdit_5);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_10);

        lineEdit_6 = new QLineEdit(formLayoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setEnabled(false);

        formLayout->setWidget(8, QFormLayout::FieldRole, lineEdit_6);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(9, QFormLayout::FieldRole, comboBox);

        pushButton = new QPushButton(formularioServicios);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(510, 420, 75, 23));
        pushButton_2 = new QPushButton(formularioServicios);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(590, 420, 75, 23));

        retranslateUi(formularioServicios);

        QMetaObject::connectSlotsByName(formularioServicios);
    } // setupUi

    void retranslateUi(QWidget *formularioServicios)
    {
        formularioServicios->setWindowTitle(QApplication::translate("formularioServicios", "formularioServicios", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("formularioServicios", "Servicios b\303\241sicos", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("formularioServicios", "ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("formularioServicios", "Nombre", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("formularioServicios", "Tiempo de cosumo [horas]", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("formularioServicios", "Consumo tota del serviciol", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("formularioServicios", "Consumo por hora", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("formularioServicios", "Costo por unidad consumida", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("formularioServicios", "Costo hora servicio", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("formularioServicios", "Unidad", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("formularioServicios", "M\303\241quina", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("formularioServicios", "Crear", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("formularioServicios", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class formularioServicios: public Ui_formularioServicios {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIOSERVICIOS_H
