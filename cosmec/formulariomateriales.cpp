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
	QString text="Ingrese los datos como se indica a continuación:\n\n\n"
		"ID:\t\tNúmero único asignado a este cargo. Se llenará automáticamente\n\n"
		"Nombre:\tCorrespone al nombre del material\n\n"
		"Geometría:\tForma en la que se compra el material. Ej. cilindro, plancha, etc\n\n"
		"Dimensiones:\tMedidas correspondientes a la geometría en que se presenta el material\n\n"
		"Unidades:\tCorrespondiente a las dimensiones\n\n"
		"Costo hora:\tSe calculará automáticamente\n\n"
		"Aplicaciones:\tSiruaciones o proyectos en que se usa este material";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}