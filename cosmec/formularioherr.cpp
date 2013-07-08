#include "formularioherr.h"

formularioHerr::formularioHerr(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(labelCombo(QString)));
}

formularioHerr::~formularioHerr()
{

}
void formularioHerr::labelCombo(QString actual){
	ui.lineEdit_6->setText(actual);
}