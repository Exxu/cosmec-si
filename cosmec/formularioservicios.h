#ifndef FORMULARIOSERVICIOS_H
#define FORMULARIOSERVICIOS_H

#include <QWidget>
#include "ui_formularioservicios.h"
#include <math.h>

class formularioServicios : public QWidget
{
	Q_OBJECT

public:
	formularioServicios(QWidget *parent = 0);
	~formularioServicios();

//private:
	Ui::formularioServicios ui;
private:
	double redondear(double num);

private slots:
	void labelCombo(QString actual);
	void consumo_hora(double consumo);
	void consumo_hora2(int tiempo);
	void costo_hora(double consumo);
	void costo_hora2(int tiempo);
	void costo_hora3(double unitario);
};

#endif // FORMULARIOSERVICIOS_H
