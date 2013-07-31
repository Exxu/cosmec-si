#include "formularioacttrabajo.h"

formularioActTrabajo::formularioActTrabajo(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(labelCombo(QString)));
	connect(ui.doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(costo_hora(double)));
	connect(ui.spinBox,SIGNAL(valueChanged(int)),this,SLOT(costo_hora2(int)));
	connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(ayuda()));
}

formularioActTrabajo::~formularioActTrabajo()
{

}

double formularioActTrabajo::redondear(double num){
	double val;
	double scale = 0.01;  // i.e. round to nearest one-hundreth
	val = floor(num / scale + 0.5) * scale;
	return val;
}
void formularioActTrabajo::labelCombo(QString actual){
	ui.lineEdit_5->setText(actual);
}
void formularioActTrabajo::costo_hora(double valor){
	if(valor!=0&&ui.spinBox->value()!=0){
		double resultado=redondear(valor/ui.spinBox->value());
		ui.lineEdit_3->setText(QString::number(resultado));
	}
}
void formularioActTrabajo::costo_hora2(int hora){
	if(ui.doubleSpinBox->value()!=0&&hora!=0){
		double resultado=redondear(ui.doubleSpinBox->value()/hora);
		ui.lineEdit_3->setText(QString::number(resultado));
	}
}
void formularioActTrabajo::ayuda(){
	QMessageBox msgBox;
	QString text="Ingrese los datos como se indica a continuaci�n:\n\n\n";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}
