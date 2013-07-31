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
	connect(ui.pushButton_4,SIGNAL(clicked()),this,SLOT(ayuda()));
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
void formularioMaq::ayuda(){
	QMessageBox msgBox;
	QString text="Ingrese los datos como se indica a continuaci�n:\n\n\n"
"Serie:\t\tN�mero de identificaci�n de la m�quina\n\n"
"Codigo ESPE:\tCorresponde al c�digo asignado por la Unidad de Planta F�sica de la ESPE a la m�quina\n\n"
"Nombre:\tCorresponde al nombre con el que se le conoce a la m�quina\n\n"
"Costo:\t\tEs la inversi�n que implic� la compra de la m�quina (en d�lares)\n\n"
"Vida �til:\tEs el tiempo (en a�os) durante el cual la m�quina funcionar� adecuadamente\n\n"
"Disponibilidad anual de la m�quina:\tEs el tiempo (en horas) en que se podr� usar la m�quina durante un a�o, tomando en cuenta una jornada de 8 horas diarias y 240 d�as laborables al a�o\n\n"
"Depreciaci�n:\tSe calcular� autom�ticamente\n\n"
"Costo hora:\tSe calcular� autom�ticamente\n\n"
"Presupuesto anual de mantenimiento correctivo:\tLa cantidad de dinero previstas para reparaciones de la m�quina durante el a�o\n\n"
"Servicios p�blicos:\tCosto de servicios b�sicos asociados a la m�quina. Dato informativo\n\n"
"Herramientas:\t\tN�mero de herramientas asociadas a esta m�quina\n\n"
"Consumibles:\t\tN�mero de consumibles asociados a esta m�quina\n\n"
"Mantenimiento:\tPresupuesto total de mantenimiento para esta m�quina\n\n"
"Costo hora cotizaci�n:\tCosto de la m�quina por hora de servicio para calcular las cotizaciones";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}