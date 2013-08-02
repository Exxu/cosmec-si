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
	QString text="Ingrese los datos como se indica a continuaci�n:\n\n\n"
		"ID:\t\tN�mero �nico asignado a la nueva actividad. Se llena autom�ticamente.\n\n"
		"Nombre:\tCorresponde al nombre de la actividad que realizar� la empresa\n\n"
		"Costo hora:\tCosto relacionado a la ejecuci�n de esta actividad\n\n"
		"Categor�a:\tCorresponde al tipo de actividad a la cual pertenece";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}