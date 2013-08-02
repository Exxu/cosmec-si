#ifndef FORMULARIOINSUMOS_H
#define FORMULARIOINSUMOS_H

#include <QWidget>
#include <QtGui/QMessageBox>
#include "ui_formularioinsumos.h"

class formularioInsumos : public QWidget
{
	Q_OBJECT

public:
	formularioInsumos(QWidget *parent = 0);
	~formularioInsumos();

//private:
	Ui::formularioInsumos ui;

private slots:
	void labelCombo(QString actual);
	void ayuda();
};

#endif // FORMULARIOINSUMOS_H
