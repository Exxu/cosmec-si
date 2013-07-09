#include "formulariomaq.h"

formularioMaq::formularioMaq(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QImage formula("costo_maq.png");
	ui.label_17->setPixmap(QPixmap::fromImage(formula));
	ui.label_17->setScaledContents(true);

	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(pathDialog()));
	connect(ui.doubleSpinBox_2,SIGNAL(valueChanged(double)),this,SLOT(calcularDepre(double)));
	connect(ui.spinBox,SIGNAL(valueChanged(int)),this,SLOT(calcularDepre2(int)));
	connect(ui.doubleSpinBox_2,SIGNAL(valueChanged(double)),this,SLOT(costo_hora(double)));
	connect(ui.spinBox_2,SIGNAL(valueChanged(int)),this,SLOT(costo_hora2(int)));
	connect(ui.spinBox,SIGNAL(valueChanged(int)),this,SLOT(costo_hora3(int)));
}

formularioMaq::~formularioMaq()
{
	
}

void formularioMaq::pathDialog(){
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
		"/home",
		tr("Images (*.png *.xpm *.jpg)"));

	ui.plainTextEdit->setPlainText(fileName);
	if(fileName!=""){
		QImage foto(fileName);
		ui.label_11->setPixmap(QPixmap::fromImage(foto));
		ui.label_11->setScaledContents(true);
	}
}

void formularioMaq::calcularDepre(double costo){
	if(costo!=0 &&ui.spinBox->value()!=0){
		double resultado=redondear(costo/ui.spinBox->value());
		ui.lineEdit_5->setText(QString::number(resultado));
	}
}
void formularioMaq::calcularDepre2(int vida){
	if(ui.doubleSpinBox_2->value()!=0 &&vida!=0){
		double resultado=redondear(ui.doubleSpinBox_2->value()/vida);
		ui.lineEdit_5->setText(QString::number(resultado));
	}
}
void formularioMaq::costo_hora(double costo){
	if(costo!=0 &&ui.spinBox_2->value()!=0&&ui.spinBox->value()!=0){
		double resultado=redondear((2*costo)/(ui.spinBox->value()*ui.spinBox_2->value()));
		ui.lineEdit_10->setText(QString::number(resultado));
	}
}
void formularioMaq::costo_hora2(int horas){
	if(ui.doubleSpinBox_2->value()!=0 &&horas!=0&&ui.spinBox->value()!=0){
		double resultado=redondear((2*ui.doubleSpinBox_2->value())/(horas*ui.spinBox->value()));
		ui.lineEdit_10->setText(QString::number(resultado));
	}
}
void formularioMaq::costo_hora3(int vida){
	if(ui.doubleSpinBox_2->value()!=0 &&vida!=0&&ui.spinBox_2->value()!=0){
		double resultado=redondear((2*ui.doubleSpinBox_2->value())/(vida*ui.spinBox_2->value()));
		ui.lineEdit_10->setText(QString::number(resultado));
	}
}
double formularioMaq::redondear(double num){
	double val;
	double scale = 0.01;  // i.e. round to nearest one-hundreth
	val = floor(num / scale + 0.5) * scale;
	return val;
}