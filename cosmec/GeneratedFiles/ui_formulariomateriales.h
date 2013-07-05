/********************************************************************************
** Form generated from reading UI file 'formulariomateriales.ui'
**
** Created: Thu 4. Jul 19:18:33 2013
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formularioMateriales
{
public:
    QWidget *formLayoutWidget;
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
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *formularioMateriales)
    {
        if (formularioMateriales->objectName().isEmpty())
            formularioMateriales->setObjectName(QString::fromUtf8("formularioMateriales"));
        formularioMateriales->resize(688, 488);
        formLayoutWidget = new QWidget(formularioMateriales);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(230, 110, 331, 261));
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

        lineEdit_3 = new QLineEdit(formLayoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        lineEdit_4 = new QLineEdit(formLayoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_4);

        doubleSpinBox = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximum(1e+09);

        formLayout->setWidget(4, QFormLayout::FieldRole, doubleSpinBox);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        label = new QLabel(formularioMateriales);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 60, 46, 13));
        pushButton = new QPushButton(formularioMateriales);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 440, 75, 23));
        pushButton_2 = new QPushButton(formularioMateriales);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(470, 440, 75, 23));

        retranslateUi(formularioMateriales);

        QMetaObject::connectSlotsByName(formularioMateriales);
    } // setupUi

    void retranslateUi(QWidget *formularioMateriales)
    {
        formularioMateriales->setWindowTitle(QApplication::translate("formularioMateriales", "formularioMateriales", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("formularioMateriales", "ID", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("formularioMateriales", "Nombre", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("formularioMateriales", "Geometr\303\255a", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("formularioMateriales", "Dimensiones", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("formularioMateriales", "Costo hora", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("formularioMateriales", "Materiales", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("formularioMateriales", "Crear", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("formularioMateriales", "Guardar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class formularioMateriales: public Ui_formularioMateriales {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIOMATERIALES_H
