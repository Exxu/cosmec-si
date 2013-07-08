#include "formularioactempresa.h"

formularioActEmpresa::formularioActEmpresa(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(labelCombo(QString)));
}

formularioActEmpresa::~formularioActEmpresa()
{

}
void formularioActEmpresa::labelCombo(QString actual){
	ui.lineEdit_3->setText(actual);
}