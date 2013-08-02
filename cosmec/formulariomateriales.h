#ifndef FORMULARIOMATERIALES_H
#define FORMULARIOMATERIALES_H

#include <QWidget>
#include <QtGui/QMessageBox>
#include "ui_formulariomateriales.h"

class formularioMateriales : public QWidget
{
	Q_OBJECT

public:
	formularioMateriales(QWidget *parent = 0);
	~formularioMateriales();

//private:
	Ui::formularioMateriales ui;

	private slots:
		void ayuda();
};

#endif // FORMULARIOMATERIALES_H
