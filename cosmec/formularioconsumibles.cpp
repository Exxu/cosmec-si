#include "formularioconsumibles.h"

formularioConsumibles::formularioConsumibles(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QImage formula("costo_cons.png");
	ui.label_8->setPixmap(QPixmap::fromImage(formula));
	ui.label_8->setScaledContents(true);
	connect(ui.comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(labelCombo(QString)));
}

formularioConsumibles::~formularioConsumibles()
{

}

void formularioConsumibles::labelCombo(QString actual){
	ui.lineEdit_4->setText(actual);
}