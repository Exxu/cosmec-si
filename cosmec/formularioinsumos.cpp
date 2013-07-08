#include "formularioinsumos.h"

formularioInsumos::formularioInsumos(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(labelCombo(QString)));
}

formularioInsumos::~formularioInsumos()
{

}
void formularioInsumos::labelCombo(QString actual){
	ui.lineEdit_5->setText(actual);
}