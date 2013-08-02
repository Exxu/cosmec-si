#include "formularioinsumos.h"

formularioInsumos::formularioInsumos(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(labelCombo(QString)));
	connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(ayuda()));
}

formularioInsumos::~formularioInsumos()
{

}
void formularioInsumos::labelCombo(QString actual){
	ui.lineEdit_5->setText(actual);
}
void formularioInsumos::ayuda(){
	QMessageBox msgBox;
	QString text="Ingrese los datos como se indica a continuaci�n:\n\n\n"
		"ID:\t\t\tN�mero �nico asignado a este cargo. Se llenar� automaticamente\n\n"
		"Nombre:\t\tCorresponde al nombre del insumo\n\n"
		"Valor unitario:\t\tCosto del insumo por unidad\n\n"
		"Cantidad anual:\tCantidad de este insumo que su utiliza por a�o\n\n"
		"Valor total:\t\tSe calcular� autom�ticamente\n\n"
		"Costo hora:\t\tSe calcular� autom�ticamente\n\n"
		"M�quina:\t\tM�quina asociada a este insumo";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}