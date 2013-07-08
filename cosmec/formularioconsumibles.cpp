#include "formularioconsumibles.h"

formularioConsumibles::formularioConsumibles(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(labelCombo(QString)));
}

formularioConsumibles::~formularioConsumibles()
{

}

void formularioConsumibles::labelCombo(QString actual){
	ui.lineEdit_4->setText(actual);
}