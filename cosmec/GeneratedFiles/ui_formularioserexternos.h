/********************************************************************************
** Form generated from reading UI file 'formularioserexternos.ui'
**
** Created: Fri 5. Jul 17:35:34 2013
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formularioSerExternos
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *formularioSerExternos)
    {
        if (formularioSerExternos->objectName().isEmpty())
            formularioSerExternos->setObjectName(QString::fromUtf8("formularioSerExternos"));
        formularioSerExternos->resize(688, 488);
        formLayoutWidget = new QWidget(formularioSerExternos);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(210, 170, 160, 80));
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

        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        lineEdit_2 = new QLineEdit(formLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        doubleSpinBox = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximum(1e+09);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox);

        label = new QLabel(formularioSerExternos);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 90, 141, 16));
        pushButton = new QPushButton(formularioSerExternos);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 330, 75, 23));
        pushButton_2 = new QPushButton(formularioSerExternos);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 340, 75, 23));

        retranslateUi(formularioSerExternos);

        QMetaObject::connectSlotsByName(formularioSerExternos);
    } // setupUi

    void retranslateUi(QWidget *formularioSerExternos)
    {
        formularioSerExternos->setWindowTitle(QApplication::translate("formularioSerExternos", "formularioSerExternos", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("formularioSerExternos", "ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("formularioSerExternos", "Nombre", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("formularioSerExternos", "Costo hora", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("formularioSerExternos", "Servicios Externos", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("formularioSerExternos", "Crear", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("formularioSerExternos", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class formularioSerExternos: public Ui_formularioSerExternos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIOSEREXTERNOS_H
