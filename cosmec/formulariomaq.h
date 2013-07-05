#ifndef FORMULARIOMAQ_H
#define FORMULARIOMAQ_H

#include <QWidget>
#include <QFileDialog>
#include <QtGui/QPlainTextEdit>
#include "ui_formulariomaq.h"

class formularioMaq : public QWidget
{
	Q_OBJECT

public:
	formularioMaq(QWidget *parent = 0);
	~formularioMaq();

//private:
	Ui::formularioMaq ui;

private slots:
	void pathDialog();
};

#endif // FORMULARIOMAQ_H
