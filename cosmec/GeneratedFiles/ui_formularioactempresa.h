/********************************************************************************
** Form generated from reading UI file 'formularioactempresa.ui'
**
** Created: Thu 4. Jul 22:43:08 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULARIOACTEMPRESA_H
#define UI_FORMULARIOACTEMPRESA_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formularioActEmpresa
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QDoubleSpinBox *doubleSpinBox;
    QComboBox *comboBox;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *formularioActEmpresa)
    {
        if (formularioActEmpresa->objectName().isEmpty())
            formularioActEmpresa->setObjectName(QString::fromUtf8("formularioActEmpresa"));
        formularioActEmpresa->resize(688, 488);
        formLayoutWidget = new QWidget(formularioActEmpresa);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(170, 110, 441, 126));
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

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBox);

        lineEdit_3 = new QLineEdit(formLayoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_3);

        label = new QLabel(formularioActEmpresa);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 60, 141, 16));
        pushButton = new QPushButton(formularioActEmpresa);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(400, 430, 75, 23));
        pushButton_2 = new QPushButton(formularioActEmpresa);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(490, 430, 75, 23));

        retranslateUi(formularioActEmpresa);

        QMetaObject::connectSlotsByName(formularioActEmpresa);
    } // setupUi

    void retranslateUi(QWidget *formularioActEmpresa)
    {
        formularioActEmpresa->setWindowTitle(QApplication::translate("formularioActEmpresa", "formularioActEmpresa", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("formularioActEmpresa", "ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("formularioActEmpresa", "Nombre", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("formularioActEmpresa", "Costo hora", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("formularioActEmpresa", "categor\303\255a", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("formularioActEmpresa", "Actividades de la Empresa", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("formularioActEmpresa", "Crear", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("formularioActEmpresa", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class formularioActEmpresa: public Ui_formularioActEmpresa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIOACTEMPRESA_H
