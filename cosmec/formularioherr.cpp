#include "formularioherr.h"

formularioHerr::formularioHerr(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QImage formula("costo_herramienta.png");
	ui.label_11->setPixmap(QPixmap::fromImage(formula));
	ui.label_11->setScaledContents(true);
	connect(ui.comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(labelCombo(QString)));
}

formularioHerr::~formularioHerr()
{

}
void formularioHerr::labelCombo(QString actual){
	ui.lineEdit_6->setText(actual);
}