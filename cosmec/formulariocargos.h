#ifndef FORMULARIOCARGOS_H
#define FORMULARIOCARGOS_H

#include <QWidget>
#include <QtGui/QMessageBox>
#include "ui_formulariocargos.h"

class formularioCargos : public QWidget
{
	Q_OBJECT

public:
	formularioCargos(QWidget *parent = 0);
	~formularioCargos();

//private:
	Ui::formularioCargos ui;
	private slots:
		void ayuda();
};

#endif // FORMULARIOCARGOS_H
