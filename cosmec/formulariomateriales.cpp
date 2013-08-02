#include "formulariomateriales.h"

formularioMateriales::formularioMateriales(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(ayuda()));
}

formularioMateriales::~formularioMateriales()
{

}
void formularioMateriales::ayuda(){
	QMessageBox msgBox;
	QString text="Ingrese los datos como se indica a continuaci�n:\n\n\n"
		"ID:\t\tN�mero �nico asignado a este cargo. Se llenar� autom�ticamente\n\n"
		"Nombre:\tCorrespone al nombre del material\n\n"
		"Geometr�a:\tForma en la que se compra el material. Ej. cilindro, plancha, etc\n\n"
		"Dimensiones:\tMedidas correspondientes a la geometr�a en que se presenta el material\n\n"
		"Unidades:\tCorrespondiente a las dimensiones\n\n"
		"Costo hora:\tSe calcular� autom�ticamente\n\n"
		"Aplicaciones:\tSiruaciones o proyectos en que se usa este material";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}