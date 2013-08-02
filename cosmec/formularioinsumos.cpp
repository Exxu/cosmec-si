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
	QString text="Ingrese los datos como se indica a continuación:\n\n\n"
		"ID:\t\t\tNúmero único asignado a este cargo. Se llenará automaticamente\n\n"
		"Nombre:\t\tCorresponde al nombre del insumo\n\n"
		"Valor unitario:\t\tCosto del insumo por unidad\n\n"
		"Cantidad anual:\tCantidad de este insumo que su utiliza por año\n\n"
		"Valor total:\t\tSe calculará automáticamente\n\n"
		"Costo hora:\t\tSe calculará automáticamente\n\n"
		"Máquina:\t\tMáquina asociada a este insumo";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}