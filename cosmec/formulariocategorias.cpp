#include "formulariocategorias.h"

formularioCategorias::formularioCategorias(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(ayuda()));
}

formularioCategorias::~formularioCategorias()
{

}

void formularioCategorias::ayuda(){
	QMessageBox msgBox;
	QString text="Ingrese los datos como se indica a continuaci�n:\n\n\n"
		"ID:\t\tN�mero �nico asignado a esta categor�a. Se llena autom�ticamente\n\n"
		"Nombre:\tCorresponde al nombre de de la nueva categor�a";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}