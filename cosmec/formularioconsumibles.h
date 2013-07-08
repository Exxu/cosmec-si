#ifndef FORMULARIOCONSUMIBLES_H
#define FORMULARIOCONSUMIBLES_H

#include <QWidget>
#include "ui_formularioconsumibles.h"
#include <math.h>

class formularioConsumibles : public QWidget
{
	Q_OBJECT

public:
	formularioConsumibles(QWidget *parent = 0);
	~formularioConsumibles();

//private:
	Ui::formularioConsumibles ui;

private slots:
	void labelCombo(QString actual);
};

#endif // FORMULARIOCONSUMIBLES_H
