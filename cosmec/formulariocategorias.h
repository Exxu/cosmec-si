#ifndef FORMULARIOCATEGORIAS_H
#define FORMULARIOCATEGORIAS_H

#include <QWidget>
#include <QtGui/QMessageBox>
#include "ui_formulariocategorias.h"

class formularioCategorias : public QWidget
{
	Q_OBJECT

public:
	formularioCategorias(QWidget *parent = 0);
	~formularioCategorias();

//private:
	Ui::formularioCategorias ui;
	private slots:
		void ayuda();
};

#endif // FORMULARIOCATEGORIAS_H
