#include "formularioservicios.h"

formularioServicios::formularioServicios(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(labelCombo(QString)));
	connect(ui.doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(consumo_hora(double)));
	connect(ui.spinBox,SIGNAL(valueChanged(int)),this,SLOT(consumo_hora2(int)));
	connect(ui.doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(costo_hora(double)));
	connect(ui.spinBox,SIGNAL(valueChanged(int)),this,SLOT(costo_hora2(int)));
	connect(ui.doubleSpinBox_2,SIGNAL(valueChanged(double)),this,SLOT(costo_hora3(double)));
}

formularioServicios::~formularioServicios()
{

}
void formularioServicios::labelCombo(QString actual){
	ui.lineEdit_6->setText(actual);
}
double formularioServicios::redondear(double num){
	double val;
	double scale = 0.01;  // i.e. round to nearest one-hundreth
	val = floor(num / scale + 0.5) * scale;
	return val;
}
void formularioServicios::consumo_hora(double consumo){
	if(consumo!=0 &&ui.spinBox->value()!=0){
		double resultado=redondear(consumo/ui.spinBox->value());
		ui.lineEdit_3->setText(QString::number(resultado));
	}
}
void formularioServicios::consumo_hora2(int tiempo){
	if(ui.doubleSpinBox->value()!=0 &&tiempo!=0){
		double resultado=redondear(ui.doubleSpinBox->value()/tiempo);
		ui.lineEdit_3->setText(QString::number(resultado));
	}
}
void formularioServicios::costo_hora(double consumo){
	if(consumo!=0 &&ui.spinBox->value()!=0&&ui.doubleSpinBox_2->value()!=0){
		double resultado=redondear((consumo/ui.spinBox->value())*ui.doubleSpinBox_2->value());
		ui.lineEdit_4->setText(QString::number(resultado));
	}
}
void formularioServicios::costo_hora2(int tiempo){
	if(ui.doubleSpinBox->value()!=0 &&tiempo!=0&&ui.doubleSpinBox_2->value()!=0){
		double resultado=redondear((ui.doubleSpinBox->value()/tiempo)*ui.doubleSpinBox_2->value());
		ui.lineEdit_4->setText(QString::number(resultado));
	}
}
void formularioServicios::costo_hora3(double unitario){
	if(ui.doubleSpinBox->value()!=0 &&ui.spinBox->value()!=0&&unitario!=0){
		double resultado=redondear((ui.doubleSpinBox->value()/ui.spinBox->value())*unitario);
		ui.lineEdit_4->setText(QString::number(resultado));
	}
}