#include "formularioherr.h"

formularioHerr::formularioHerr(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QImage formula("costo_herramienta.png");
	ui.label_11->setPixmap(QPixmap::fromImage(formula));
	ui.label_11->setScaledContents(true);
	connect(ui.comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(labelCombo(QString)));
	connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(ayuda()));
}

formularioHerr::~formularioHerr()
{

}
void formularioHerr::labelCombo(QString actual){
	ui.lineEdit_6->setText(actual);
}
void formularioHerr::ayuda(){
	QMessageBox msgBox;
	QString text="Ingrese los datos como se indica a continuación:\n\n\n"
		"Id:\t\t\tNúmero único asignado a esta herramienta. Se llenará automaticamente\n\n"
		"Nombre:\t\tCorresponde al nombre de la nueva herramienta\n\n"
		"Valor unitario:\t\tCosto de la herramienta por unidad\n\n"
		"Vida útil:\t\tTiempo durante el cual la herramienta funciona adecuadamente\n\n"
		"Depreciación:\t\tSe calculará automáticamente\n\n"
		"Costo hora:\t\tSe calculará automáticamente\n\n"
		"Cantidad anual:\tCantidad de herramientas que se consumirán por año\n\n"
		"Costo total:\t\tSe calculará automáticamente\n\n"
		"Máquina:\t\tMáquina que utiliza esta herramienta";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}