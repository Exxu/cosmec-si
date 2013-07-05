/********************************************************************************
** Form generated from reading UI file 'formulariocategorias.ui'
**
** Created: Thu 4. Jul 19:18:34 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULARIOCATEGORIAS_H
#define UI_FORMULARIOCATEGORIAS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formularioCategorias
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *formularioCategorias)
    {
        if (formularioCategorias->objectName().isEmpty())
            formularioCategorias->setObjectName(QString::fromUtf8("formularioCategorias"));
        formularioCategorias->resize(400, 300);
        formLayoutWidget = new QWidget(formularioCategorias);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(90, 80, 160, 80));
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

        label = new QLabel(formularioCategorias);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 40, 46, 13));
        pushButton = new QPushButton(formularioCategorias);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 240, 75, 23));
        pushButton_2 = new QPushButton(formularioCategorias);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 240, 75, 23));

        retranslateUi(formularioCategorias);

        QMetaObject::connectSlotsByName(formularioCategorias);
    } // setupUi

    void retranslateUi(QWidget *formularioCategorias)
    {
        formularioCategorias->setWindowTitle(QApplication::translate("formularioCategorias", "formularioCategorias", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("formularioCategorias", "ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("formularioCategorias", "Nombre", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("formularioCategorias", "Categor\303\255as de Actividades de la Empresa", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("formularioCategorias", "Crear", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("formularioCategorias", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class formularioCategorias: public Ui_formularioCategorias {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIOCATEGORIAS_H
