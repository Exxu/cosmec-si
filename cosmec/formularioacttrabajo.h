#ifndef FORMULARIOACTTRABAJO_H
#define FORMULARIOACTTRABAJO_H

#include <QWidget>
#include <QtGui/QMessageBox>
#include "ui_formularioacttrabajo.h"
#include <math.h>

class formularioActTrabajo : public QWidget
{
	Q_OBJECT

public:
	formularioActTrabajo(QWidget *parent = 0);
	~formularioActTrabajo();

//private:
	Ui::formularioActTrabajo ui;
private:
	double redondear(double numero);

private slots:
	void labelCombo(QString actual);
	/*void costo_hora(double valor);
	void costo_hora2(int hora);*/
	void ayuda();
	
};

#endif // FORMULARIOACTTRABAJO_H
