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
	QString text="Ingrese los datos como se indica a continuaci�n:\n\n\n"
		"Id:\t\t\tN�mero �nico asignado a esta herramienta. Se llenar� automaticamente\n\n"
		"Nombre:\t\tCorresponde al nombre de la nueva herramienta\n\n"
		"Valor unitario:\t\tCosto de la herramienta por unidad\n\n"
		"Vida �til:\t\tTiempo durante el cual la herramienta funciona adecuadamente\n\n"
		"Depreciaci�n:\t\tSe calcular� autom�ticamente\n\n"
		"Costo hora:\t\tSe calcular� autom�ticamente\n\n"
		"Cantidad anual:\tCantidad de herramientas que se consumir�n por a�o\n\n"
		"Costo total:\t\tSe calcular� autom�ticamente\n\n"
		"M�quina:\t\tM�quina que utiliza esta herramienta";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}