#include "formularioconsumibles.h"

formularioConsumibles::formularioConsumibles(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QImage formula("costo_cons.png");
	ui.label_8->setPixmap(QPixmap::fromImage(formula));
	ui.label_8->setScaledContents(true);
	connect(ui.comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(labelCombo(QString)));
	connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(ayuda()));
}

formularioConsumibles::~formularioConsumibles()
{

}

void formularioConsumibles::labelCombo(QString actual){
	ui.lineEdit_4->setText(actual);
}
void formularioConsumibles::ayuda(){
	QMessageBox msgBox;
	QString text="Ingrese los datos como se indica a continuación:\n\n\n"
		"ID:\t\tNúmero único asignado a este consumible. Se llenará automáticamente\n\n"
		"Nombre:\tCorresponde al nombre de este consumible\n\n"
		"Valor unitario:\tCosto de una unidad de este consumible\n\n"
		"Costo hora:\tSe calculará automáticamente\n\n"
		"Máquina:\tMáquina a la que está asociado este consumible\n\n"
		"Aplicaciones:\tSituaciones o proyectos en los cuales este consumible es usado frecuentemente.";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}