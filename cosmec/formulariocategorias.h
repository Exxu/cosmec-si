#ifndef FORMULARIOCATEGORIAS_H
#define FORMULARIOCATEGORIAS_H

#include <QWidget>
#include "ui_formulariocategorias.h"

class formularioCategorias : public QWidget
{
	Q_OBJECT

public:
	formularioCategorias(QWidget *parent = 0);
	~formularioCategorias();

//private:
	Ui::formularioCategorias ui;
};

#endif // FORMULARIOCATEGORIAS_H
