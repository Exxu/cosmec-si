#ifndef FORMULARIOHERR_H
#define FORMULARIOHERR_H

#include <QWidget>
#include <QtGui/QMessageBox>
#include "ui_formularioherr.h"

class formularioHerr : public QWidget
{
	Q_OBJECT

public:
	formularioHerr(QWidget *parent = 0);
	~formularioHerr();

//private:
	Ui::formularioHerr ui;

private slots:
		void labelCombo(QString actual);
		void ayuda();
};

#endif // FORMULARIOHERR_H
