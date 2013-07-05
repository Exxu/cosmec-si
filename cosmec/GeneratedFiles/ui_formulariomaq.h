/********************************************************************************
** Form generated from reading UI file 'formulariomaq.ui'
**
** Created: Fri 5. Jul 17:35:34 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULARIOMAQ_H
#define UI_FORMULARIOMAQ_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formularioMaq
{
public:
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *spinBox;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QSpinBox *spinBox_2;
    QLabel *label_11;
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *formularioMaq)
    {
        if (formularioMaq->objectName().isEmpty())
            formularioMaq->setObjectName(QString::fromUtf8("formularioMaq"));
        formularioMaq->resize(739, 488);
        label = new QLabel(formularioMaq);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 671, 31));
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignCenter);
        formLayoutWidget = new QWidget(formularioMaq);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(60, 70, 331, 407));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(15);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);

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

        lineEdit_3 = new QLineEdit(formLayoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        spinBox = new QSpinBox(formLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(999999999);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBox);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_8);

        lineEdit_5 = new QLineEdit(formLayoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setEnabled(false);

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_5);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_9);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_10);

        label_12 = new QLabel(formLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_12);

        label_13 = new QLabel(formLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_13);

        label_14 = new QLabel(formLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout->setWidget(11, QFormLayout::LabelRole, label_14);

        lineEdit_7 = new QLineEdit(formLayoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setEnabled(false);

        formLayout->setWidget(9, QFormLayout::FieldRole, lineEdit_7);

        lineEdit_8 = new QLineEdit(formLayoutWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setEnabled(false);

        formLayout->setWidget(10, QFormLayout::FieldRole, lineEdit_8);

        lineEdit_9 = new QLineEdit(formLayoutWidget);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setEnabled(false);

        formLayout->setWidget(11, QFormLayout::FieldRole, lineEdit_9);

        lineEdit_10 = new QLineEdit(formLayoutWidget);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setEnabled(false);

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEdit_10);

        doubleSpinBox_2 = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setMaximum(1e+09);

        formLayout->setWidget(3, QFormLayout::FieldRole, doubleSpinBox_2);

        doubleSpinBox_3 = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setMaximum(1e+09);

        formLayout->setWidget(8, QFormLayout::FieldRole, doubleSpinBox_3);

        spinBox_2 = new QSpinBox(formLayoutWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(999999999);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBox_2);

        label_11 = new QLabel(formularioMaq);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(470, 130, 181, 151));
        label_11->setFrameShape(QFrame::Panel);
        label_11->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(formularioMaq);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 290, 181, 23));
        plainTextEdit = new QPlainTextEdit(formularioMaq);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setEnabled(false);
        plainTextEdit->setGeometry(QRect(473, 330, 181, 41));
        pushButton_2 = new QPushButton(formularioMaq);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(580, 450, 75, 23));
        pushButton_3 = new QPushButton(formularioMaq);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(480, 450, 75, 23));

        retranslateUi(formularioMaq);

        QMetaObject::connectSlotsByName(formularioMaq);
    } // setupUi

    void retranslateUi(QWidget *formularioMaq)
    {
        formularioMaq->setWindowTitle(QApplication::translate("formularioMaq", "formularioMaq", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("formularioMaq", "FORMULARIO DE M\303\201QUINAS", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("formularioMaq", "Serie", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("formularioMaq", "C\303\263digo ESPE", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("formularioMaq", "Nombre", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("formularioMaq", "Costo", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("formularioMaq", "Vida \303\272til", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("formularioMaq", "Horas de trabajo anuales", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("formularioMaq", "Depreciaci\303\263n", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("formularioMaq", "Costo Hora", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("formularioMaq", "Presupuesto anual", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("formularioMaq", "Consumo de agua", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("formularioMaq", "Consumo de luz", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("formularioMaq", "costo hora cotizaci\303\263n", 0, QApplication::UnicodeUTF8));
        label_11->setText(QString());
        pushButton->setText(QApplication::translate("formularioMaq", "A\303\261adir imagen", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("formularioMaq", "Guardar", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("formularioMaq", "Crear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class formularioMaq: public Ui_formularioMaq {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARIOMAQ_H
