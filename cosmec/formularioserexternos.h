#ifndef FORMULARIOSEREXTERNOS_H
#define FORMULARIOSEREXTERNOS_H

#include <QWidget>
#include <QtGui/QMessageBox>
#include "ui_formularioserexternos.h"

class formularioSerExternos : public QWidget
{
	Q_OBJECT

public:
	formularioSerExternos(QWidget *parent = 0);
	~formularioSerExternos();

//private:
	Ui::formularioSerExternos ui;

	private slots:
		void ayuda();
};

#endif // FORMULARIOSEREXTERNOS_H
