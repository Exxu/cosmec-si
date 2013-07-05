#include "formulariomaq.h"

formularioMaq::formularioMaq(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(pathDialog()));
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
