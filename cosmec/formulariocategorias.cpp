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
	QString text="Ingrese los datos como se indica a continuación:\n\n\n"
		"ID:\t\tNúmero único asignado a esta categoría. Se llena automáticamente\n\n"
		"Nombre:\tCorresponde al nombre de de la nueva categoría";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}