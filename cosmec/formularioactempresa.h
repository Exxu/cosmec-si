#ifndef FORMULARIOACTEMPRESA_H
#define FORMULARIOACTEMPRESA_H

#include <QWidget>
#include "ui_formularioactempresa.h"

class formularioActEmpresa : public QWidget
{
	Q_OBJECT

public:
	formularioActEmpresa(QWidget *parent = 0);
	~formularioActEmpresa();

//private:
	Ui::formularioActEmpresa ui;

private slots:
	void labelCombo(QString actual);
};

#endif // FORMULARIOACTEMPRESA_H
