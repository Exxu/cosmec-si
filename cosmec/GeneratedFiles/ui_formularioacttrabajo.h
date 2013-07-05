/********************************************************************************
** Form generated from reading UI file 'formularioacttrabajo.ui'
**
** Created: Fri 5. Jul 17:35:34 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULARIOACTTRABAJO_H
#define UI_FORMULARIOACTTRABAJO_H

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

class Ui_formularioActTrabajo
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QSpinBox *spinBox;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *formularioActTrabajo)
    {
        if (formularioActTrabajo->objectName().isEmpty())
            formularioActTrabajo->setObjectName(QString::fromUtf8("formularioActTrabajo"));
        formularioActTrabajo->resize(688, 488);
        formLayoutWidget = new QWidget(formularioActTrabajo);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(110, 100, 461, 253));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_2 = new QLineEdit(formLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        spinBox = new QSpinBox(formLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(999999999);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        doubleSpinBox = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximum(1e+09);

        formLayout->setWidget(3, QFormLayout::FieldRole, doubleSpinBox);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        lineEdit_3 = new QLineEdit(formLayoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_3);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        lineEdit_5 = new QLineEdit(formLayoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setEnabled(false);

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_5);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(6, QFormLayout::FieldRole, comboBox);

        label = new QLabel(formularioActTrabajo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 40, 141, 16));
        pushButton = new QPushButton(formularioActTrabajo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(500, 440, 75, 23));
        pushButton_2 = new QPushButton(formularioActTrabajo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(590, 440, 75, 23));

        retranslateUi(formularioActTrabajo);

        QMetaObject::connectSlotsByName(formularioActTrabajo);
    } // setupUi

    void retranslateUi(QWidget *formularioActTrabajo)
    {
        formularioActTrabajo->setWindowTitle(QApplication::translate("formularioActTrabajo", "formularioActTrabajo", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("formularioActTrabajo", "ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("formularioActTrabajo", "Nombre", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("formularioActTrabajo", "Horas de trabajo mensual", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("formularioActTrabajo", "Valor mensual de la actividad", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("formularioActTrabajo", "Costo hora", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("formularioActTrabajo", "Cargo", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("formularioActTrabajo", "Actividades de trabajo", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("formularioActTrabajo", "Crear", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("formularioActTrabajo", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class formularioActTrabajo: public Ui_formularioActTrabajo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIOACTTRABAJO_H
