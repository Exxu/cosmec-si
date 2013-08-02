#include "formulariocargos.h"

formularioCargos::formularioCargos(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(ayuda()));
}

formularioCargos::~formularioCargos()
{

}
void formularioCargos::ayuda(){
	QMessageBox msgBox;
	QString text="Ingrese los datos como se indica a continuaci�n:\n\n\n"
		"ID:\t\tN�mero �nico asignado a este cargo. Se llenar� automaticamente\n\n"
		"Nombre:\tNobre del nuevo cargo de trabajo\n\n"
		"Salario:\t\tSalario mensualnasociado a este cargo de trabajo";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}
