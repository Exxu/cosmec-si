#include "formulariocargos.h"

formularioCargos::formularioCargos(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(ayuda()));
}

formularioCargos::~formularioCargos()
{

}
void formularioCargos::ayuda(){
	QMessageBox msgBox;
	QString text="Ingrese los datos como se indica a continuación:\n\n\n";
	msgBox.setText(text);
	msgBox.setWindowTitle("Ayuda");
	msgBox.setIcon(QMessageBox::Information);
	msgBox.exec();
}
