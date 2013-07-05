/********************************************************************************
** Form generated from reading UI file 'formulariocargos.ui'
**
** Created: Fri 5. Jul 17:35:34 2013
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formularioCargos
{
public:
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *formularioCargos)
    {
        if (formularioCargos->objectName().isEmpty())
            formularioCargos->setObjectName(QString::fromUtf8("formularioCargos"));
        formularioCargos->resize(688, 488);
        label = new QLabel(formularioCargos);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 40, 46, 13));
        formLayoutWidget = new QWidget(formularioCargos);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(250, 90, 160, 80));
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

        pushButton = new QPushButton(formularioCargos);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(370, 400, 75, 23));
        pushButton_2 = new QPushButton(formularioCargos);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(460, 400, 75, 23));

        retranslateUi(formularioCargos);

        QMetaObject::connectSlotsByName(formularioCargos);
    } // setupUi

    void retranslateUi(QWidget *formularioCargos)
    {
        formularioCargos->setWindowTitle(QApplication::translate("formularioCargos", "formularioCargos", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("formularioCargos", "Cargos", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("formularioCargos", "ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("formularioCargos", "Nombre ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("formularioCargos", "Salario", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("formularioCargos", "Crear", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("formularioCargos", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class formularioCargos: public Ui_formularioCargos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIOCARGOS_H
