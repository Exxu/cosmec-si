#ifndef FORMULARIOMAQ_H
#define FORMULARIOMAQ_H

#include <QWidget>
#include <QFileDialog>
#include <QtGui/QPlainTextEdit>
#include "ui_formulariomaq.h"
#include <QtDebug>
#include <math.h>

class formularioMaq : public QWidget
{
	Q_OBJECT

public:
	formularioMaq(QWidget *parent = 0);
	~formularioMaq();

//private:
	Ui::formularioMaq ui;

private:
	double redondear(double num);

private slots:
	void pathDialog();
	void calcularDepre(double costo);
	void calcularDepre2(int vida);
	void costo_hora(double costo);
	void costo_hora2(int horas);
	void costo_hora3(int vida);
};

#endif // FORMULARIOMAQ_H
