#include "formularioserexternos.h"

formularioSerExternos::formularioSerExternos(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(ayuda()));
}

formularioSerExternos::~formularioSerExternos()
{

}
void formularioSerExternos::ayuda(){
	QMessageBox msgBox;
	QString text="Ingrese los datos como se indica a continuación:\n\n\n"
		"ID:\t\tNúmero único asignado a este cargo. Se llenará automáticamente\n\n"
		"Nombre:\tCorresponde al nombre del servicio a contratar\n\n"
		"Costo hora:\tCosto de contratar el servicio";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}