#include "formularioactempresa.h"

formularioActEmpresa::formularioActEmpresa(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(labelCombo(QString)));
	connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(ayuda()));
}

formularioActEmpresa::~formularioActEmpresa()
{

}
void formularioActEmpresa::labelCombo(QString actual){
	ui.lineEdit_3->setText(actual);
}
void formularioActEmpresa::ayuda(){
	QMessageBox msgBox;
	QString text="Ingrese los datos como se indica a continuación:\n\n\n";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}