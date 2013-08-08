#include "cosmec.h"

int filaEdit=-1;
bool comboH=false,comboG=false;

struct repcot {
	int id;
	QString maquina;
	int costo;
};
TiXmlElement* tabla_herramientasss(XmlExcel archivo,db basedatos,PGconn *conn,TiXmlElement * row, TiXmlElement * table,char maquina[20]){
	int n;
	char sql[600];
	list <hoja> list_filas;
	char nombre[50], titulo_aux[200];
	basedatos.consulta_maquina(conn,maquina,nombre);
	n=sprintf(titulo_aux,"HERRAMIENTAS DE LA MAQUINA: %s",nombre);
	//list_filas=archivo.row_anadido_menu(list_filas,1);
	row=archivo.crear_cell_tabla_titulo(titulo_aux,"String","3");
	table->LinkEndChild(row);
	list_filas=basedatos.consulta_menus(conn,list_filas,"1");
	n=sprintf(sql,"SELECT a.nombre_herramienta, a.costo_unitario, a.depreciacion, a.costo_hora FROM herramientas AS a, maquinas AS b WHERE b.serie=a.serie_maquinas and b.serie=%s",maquina);
	list_filas=basedatos.consulta(conn,list_filas,sql); //lee de la base de datos y almacena en la lista
	table=archivo.row_lista_anadido_dato(table,list_filas);
	row=archivo.salto_linea();
	int aux1=list_filas.size()-1;
	char aux2[50]="=SUM(R[-7]C:R[-1]C)";
	n=sprintf (aux2, "=SUM(R[-%d]C:R[-1]C)", aux1);
	//printf(aux2);
	//char a=getchar();
	archivo.crear_linea(row,"Costo Hora Total","String","4",true,false);
	archivo.crear_linea(row,aux2,"Number","5",false,true);
	table->LinkEndChild(row);
	return table;
}
TiXmlElement* tabla_herramientasss2(XmlExcel archivo,db basedatos,PGconn *conn,TiXmlElement * row, TiXmlElement * table,char maquina[20]){
	int n;
	char sql[1000];
	list <hoja> list_filas;
	char nombre[50], total[50], titulo_aux[200];
	basedatos.consulta_maquina(conn,maquina,nombre);
	basedatos.consulta_suma(conn,maquina,total);
	n=sprintf(titulo_aux,"MANO DE OBRA DE LA MAQUINA: %s",nombre);
	//list_filas=archivo.row_anadido_menu(list_filas,1);
	row=archivo.crear_cell_tabla_titulo(titulo_aux,"String","4");
	table->LinkEndChild(row);
	list_filas=basedatos.consulta_menus(conn,list_filas,"2");
	//n=sprintf(sql,"SELECT c.nombre,d.nombre AS nombre_cargo,c.hora_mensual,c.costo_mes,c.costo_hora FROM maquinas AS a, mano_obra AS b, actividades_trabajo AS c, cargo AS d WHERE a.serie=b.serie_maquinas AND b.id_actividad_actividades_trabajo=c.id_actividad AND c.id_cargo_cargo=d.id_cargo and a.serie=%s",maquina);
	n=sprintf(sql,"SELECT c.nombre,d.nombre AS nombre_cargo,c.hora_mensual,c.costo_mes,c.costo_mes*100/%s as promedio FROM maquinas AS a, mano_obra AS b, actividades_trabajo AS c, cargo AS d WHERE a.serie=b.serie_maquinas AND b.id_actividad_actividades_trabajo=c.id_actividad AND c.id_cargo_cargo=d.id_cargo and a.serie=%s",total,maquina);
	list_filas=basedatos.consulta(conn,list_filas,sql); //lee de la base de datos y almacena en la lista
	table=archivo.row_lista_anadido_dato(table,list_filas);
	row=archivo.salto_linea();
	int aux1=list_filas.size()-1;
	char aux2[50]="=SUM(R[-7]C:R[-1]C)";
	n=sprintf (aux2, "=SUM(R[-%d]C:R[-1]C)", aux1);
	//printf(aux2);
	//char a=getchar();
	archivo.crear_linea(row,"Valor de mano de obra","String","4",true,false);
	archivo.crear_linea(row,aux2,"Number","5",false,true);
	table->LinkEndChild(row);
	return table;
}
TiXmlElement* tabla_herramientasss3(XmlExcel archivo,db basedatos,PGconn *conn,TiXmlElement * row, TiXmlElement * table,char maquina[20]){
	int n;
	char sql[1000];
	list <hoja> list_filas;
	char nombre[50], titulo_aux[200];
	basedatos.consulta_maquina(conn,maquina,nombre);
	n=sprintf(titulo_aux,"CONSUMIBLES DE LA MAQUINA: %s",nombre);
	//list_filas=archivo.row_anadido_menu(list_filas,1);
	row=archivo.crear_cell_tabla_titulo(titulo_aux,"String","2");
	table->LinkEndChild(row);
	list_filas=basedatos.consulta_menus(conn,list_filas,"3");
	n=sprintf(sql,"SELECT a.nombre_consumible, a.costo_unitario,a.costo_hora FROM consumible AS a, maquinas AS b WHERE b.serie=a.serie_maquinas and b.serie=%s",maquina);
	list_filas=basedatos.consulta(conn,list_filas,sql); //lee de la base de datos y almacena en la lista
	table=archivo.row_lista_anadido_dato(table,list_filas);
	row=archivo.salto_linea();
	int aux1=list_filas.size()-1;
	char aux2[50]="=SUM(R[-7]C:R[-1]C)";
	n=sprintf (aux2, "=SUM(R[-%d]C:R[-1]C)", aux1);
	//printf(aux2);
	//char a=getchar();
	archivo.crear_linea(row,"Costo Hora total","String","3",true,false);
	archivo.crear_linea(row,aux2,"Number","4",false,true);
	table->LinkEndChild(row);
	return table;
}
TiXmlElement* tabla_herramientasss4(XmlExcel archivo,db basedatos,PGconn *conn,TiXmlElement * row, TiXmlElement * table,char maquina[20]){
	int n;
	char sql[1000];
	list <hoja> list_filas;
	char nombre[50], titulo_aux[200];
	basedatos.consulta_cargos(conn,maquina,nombre);
	n=sprintf(titulo_aux,"REPORTE DE ACTIVIDADES DE: %s",nombre);
	//list_filas=archivo.row_anadido_menu(list_filas,1);
	row=archivo.crear_cell_tabla_titulo(titulo_aux,"String","2");
	table->LinkEndChild(row);
	list_filas=basedatos.consulta_menus(conn,list_filas,"4");
	n=sprintf(sql,"SELECT c.nombre,c.hora_mensual,c.costo_mes FROM actividades_trabajo AS c, cargo AS d WHERE  d.id_cargo=c.id_cargo_cargo and d.id_cargo=%s ORDER BY d.nombre",maquina);
	list_filas=basedatos.consulta(conn,list_filas,sql); //lee de la base de datos y almacena en la lista
	table=archivo.row_lista_anadido_dato(table,list_filas);
	row=archivo.salto_linea();
	int aux1=list_filas.size()-1;
	char aux2[50];
	n=sprintf (aux2, "=SUM(R[-%d]C:R[-1]C)", aux1);
	//printf(aux2);
	//char a=getchar();
	archivo.crear_linea(row,"Salario","String","3",true,false);
	archivo.crear_linea(row,aux2,"Number","4",false,true);
	table->LinkEndChild(row);
	row=archivo.salto_linea();
	aux1+=1;
	n=sprintf (aux2, "=SUM(R[-%d]C[-1]:R[-2]C[-1])", aux1);
	archivo.crear_linea(row,"Horas de trabajo total","String","3",true,false);
	archivo.crear_linea(row,aux2,"Number","4",false,true);
	table->LinkEndChild(row);
	return table;
}

TiXmlElement* tabla_herramientasss5(XmlExcel archivo,db basedatos,PGconn *conn,TiXmlElement * row, TiXmlElement * table,char maquina[20]){
	int n;
	char sql[1000];
	list <hoja> list_filas;
	char nombre[50], titulo_aux[200];
	basedatos.consulta_maquina(conn,maquina,nombre);
	n=sprintf(titulo_aux,"MANTENIMIENTO DE LA MAQUINA: %s",nombre);
	//list_filas=archivo.row_anadido_menu(list_filas,1);
	row=archivo.crear_cell_tabla_titulo(titulo_aux,"String","4");
	table->LinkEndChild(row);
	list_filas=basedatos.consulta_menus(conn,list_filas,"5");
	//SELECT c.modelo,c.horas_trabajo_anual,c.presupuesto_anual,b.nombre,b.costo_unitario,b.cantidad_anual,b.valor_total,b.costo_hora FROM mantenimiento_preventivo AS b, maquinas AS c WHERE b.serie_maquinas=c.serie ORDER BY c.modelo
	//SELECT b.nombre,b.costo_unitario,b.cantidad_anual,b.valor_total,b.costo_hora FROM mantenimiento_preventivo AS b, maquinas AS c WHERE b.serie_maquinas=c.serie ORDER BY c.modelo
	n=sprintf(sql,"select b.nombre,b.costo_unitario,b.cantidad_anual,b.valor_total,b.costo_hora FROM mantenimiento_preventivo AS b, maquinas AS c WHERE b.serie_maquinas=c.serie and c.serie=%s ORDER BY c.modelo",maquina);
	list_filas=basedatos.consulta(conn,list_filas,sql); //lee de la base de datos y almacena en la lista
	table=archivo.row_lista_anadido_dato(table,list_filas);
	row=archivo.salto_linea();
	int aux1=list_filas.size()-1;
	char aux2[50]="=SUM(R[-7]C:R[-1]C)";
	n=sprintf (aux2, "=SUM(R[-%d]C:R[-1]C)", aux1);
	archivo.crear_linea(row,"Costo Mantenimiento Preventivo:","String","4",true,false);
	archivo.crear_linea(row,aux2,"Number","5",false,true);
	archivo.crear_linea(row,aux2,"Number","6",false,true);
	table->LinkEndChild(row);
	row=archivo.salto_linea();
	archivo.crear_linea(row,"Costo Mantenimiento Correctivo:","String","4",true,false);
	list_filas.clear();
	n=sprintf(sql,"select presupuesto_anual as presupuesto, presupuesto_anual/horas_trabajo_anual as horas_anual  from maquinas where serie=%s",maquina);
	list_filas=basedatos.consulta(conn,list_filas,sql); //lee de la base de datos y almacena en la lista
	table=archivo.row_lista_anadido_dato(row,table,list_filas);
	row=archivo.salto_linea();
	archivo.crear_linea(row,"Costo Mantenimiento:","String","4",true,false);
	archivo.crear_linea(row,"=SUM(R[-2]C:R[-1]C)","Number","5",false,true);
	archivo.crear_linea(row,"=SUM(R[-2]C:R[-1]C)","Number","6",false,true);
	table->LinkEndChild(row);
	return table;
}

TiXmlElement* tabla_herramientasss6(XmlExcel archivo,db basedatos,PGconn *conn,TiXmlElement * row, TiXmlElement * table,char maquina[20]){
	int n;
	char sql[1000];
	list <hoja> list_filas;
	char nombre[50], titulo_aux[200];
	//basedatos.consulta_cargos(conn,maquina,nombre);
	//n=sprintf(titulo_aux,"REPORTE DE ACTIVIDADES DE: %s",nombre);
	//list_filas=archivo.row_anadido_menu(list_filas,1);
	row=archivo.crear_cell_tabla_titulo("Lista de Maquinas en el sistema","String","6");
	table->LinkEndChild(row);
	list_filas=basedatos.consulta_menus(conn,list_filas,"6");
	strcpy(sql,"SELECT serie,modelo,costo,vida_util, horas_trabajo_anual, deprecicacion, costo_hora FROM maquinas");
	list_filas=basedatos.consulta(conn,list_filas,sql); //lee de la base de datos y almacena en la lista
	table=archivo.row_lista_anadido_dato(table,list_filas);
	return table;
}
TiXmlElement* tabla_herramientasss7(XmlExcel archivo,db basedatos,PGconn *conn,TiXmlElement * row, TiXmlElement * table,char maquina[20]){
	int n;
	char sql[1000];
	list <hoja> list_filas;
	char nombre[50], titulo_aux[200];
	basedatos.consulta_maquina(conn,maquina,nombre);
	n=sprintf(titulo_aux,"SERVICIOS BASICOS DE LA MAQUINA: %s",nombre);
	//list_filas=archivo.row_anadido_menu(list_filas,1);
	row=archivo.crear_cell_tabla_titulo(titulo_aux,"String","5");
	table->LinkEndChild(row);
	list_filas=basedatos.consulta_menus(conn,list_filas,"7");
	//SELECT c.modelo,c.horas_trabajo_anual,c.presupuesto_anual,b.nombre,b.costo_unitario,b.cantidad_anual,b.valor_total,b.costo_hora FROM mantenimiento_preventivo AS b, maquinas AS c WHERE b.serie_maquinas=c.serie ORDER BY c.modelo
	//SELECT b.nombre,b.costo_unitario,b.cantidad_anual,b.valor_total,b.costo_hora FROM mantenimiento_preventivo AS b, maquinas AS c WHERE b.serie_maquinas=c.serie ORDER BY c.modelo
	n=sprintf(sql,"SELECT a.nombre_servi, a.consumo_serv, a.unidad, a.consumo_hora, a.costo_consu, a.costo_hora FROM serv_basico AS a, maquinas AS b WHERE a.serie_maquinas=b.serie and b.serie=%s",maquina);
	list_filas=basedatos.consulta(conn,list_filas,sql); //lee de la base de datos y almacena en la lista
	table=archivo.row_lista_anadido_dato(table,list_filas);
	row=archivo.salto_linea();
	int aux1=list_filas.size();
	char aux2[50]="=SUM(R[-7]C:R[-1]C)";
	n=sprintf (aux2, "=SUM(R[-%d]C:R[-1]C)", aux1);
	archivo.crear_linea(row,"Costo Total:","String","6",true,false);
	archivo.crear_linea(row,aux2,"Number","7",false,true);
	table->LinkEndChild(row);
	row=archivo.salto_linea();
	table->LinkEndChild(row);
	return table;
}
cosmec::cosmec(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	QImage espe("espe.png");
	ui.label_8->setPixmap(QPixmap::fromImage(espe));
	ui.label_8->setScaledContents(true);

	QImage mecanica("lmecanica.png");
	ui.label_9->setPixmap(QPixmap::fromImage(mecanica));
	ui.label_9->setScaledContents(true);

	ui.stackedWidget->setCurrentIndex(0);
	ui.menuArchivos->setEnabled(false);
	ui.menuCotizaciones->setEnabled(false);
	ui.menuReportes->setEnabled(false);
	ui.actionUsuarios->setEnabled(false);
	
	//CENTRAR DATOS DE LAS TABLAS
	connect(ui.tableWidget,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_2,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_3,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_4,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_5,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_6,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_7,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_8,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_9,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_10,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_11,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_12,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_13,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_14,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_15,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_16,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_17,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	connect(ui.tableWidget_24,SIGNAL(itemChanged(QTableWidgetItem*)),this,SLOT(centrarItem(QTableWidgetItem*)));
	
	//Parametros Base de datos
	QFile file("in.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
		QMessageBox msgBox;
		msgBox.setText("Error al cargar configuracion de conexion host, se coloca como default localhost");
		msgBox.exec();
		host="localhost";
		pass2 ="merlin";
		usuario="postgres";
		puerto="5432";
		iva=0.12;
		vcomp=0.3;
	}else{
		QTextStream stream(&file);
		host = stream.readLine();
		pass2 = stream.readLine();
		usuario=stream.readLine();
		puerto=stream.readLine();
		iva=(QString(stream.readLine()).toDouble())/100;
		vcomp=0.3;
		ui.ip->setText(host);
		ui.usuario->setText(usuario);
		ui.passw->setText(pass2);
		ui.port->setText(puerto);
		ui.lineEdit_7->setText(QString::number(iva*100));
	}
	conexion();
	connect(ui.actionConfiguracion, SIGNAL(triggered()),this, SLOT(setconfig()));
    connect(ui.editconfig,SIGNAL(toggled(bool)),this,SLOT(configurar()));
    connect(ui.cargarconfig, SIGNAL(clicked()),this, SLOT(conexion()));
	connect(ui.actionExportar_a_PDF,SIGNAL(triggered()),this,SLOT(setgenerador()));
	connect(ui.actionExportar_a_Exel,SIGNAL(triggered()),this,SLOT(setreporteexel()));
	//cotizacion
	//connect(ui.comboBox_3,SIGNAL(currentIndexChanged(int)),this,SLOT(combocotizacion(int)));
	//connect(ui.comboBox_5,SIGNAL(currentIndexChanged(int)),this,SLOT(combocotizacion2(int)));
	//reportes
	connect(ui.genreport,SIGNAL(clicked()),this,SLOT(reportgenerador()));
	connect(ui.pushButton_31,SIGNAL(clicked()),this,SLOT(reporteexel()));
	
	//desplegar pantallas de menú
	connect(ui.actionMaquina, SIGNAL(triggered()),this, SLOT(setmaquina()));
	connect(ui.actionHerramientas, SIGNAL(triggered()),this, SLOT(setherramienta()));
	connect(ui.actionConsumibles, SIGNAL(triggered()),this, SLOT(setconsumible()));
	connect(ui.actionConsumo_de_Energia, SIGNAL(triggered()),this, SLOT(setenergia()));
	connect(ui.actionMantenimiento, SIGNAL(triggered()),this, SLOT(setmantenimiento()));
	connect(ui.actionMano_de_Obra, SIGNAL(triggered()),this, SLOT(setmanoobra()));
	connect(ui.actionActividades, SIGNAL(triggered()),this, SLOT(setactividades()));
    connect(ui.actionMano_de_Obra_2, SIGNAL(triggered()),this, SLOT(setactividadesMo()));
	connect(ui.actionNueva, SIGNAL(triggered()),this, SLOT(setnuevaCotizacion()));
	connect(ui.actionBuscar, SIGNAL(triggered()),this, SLOT(setbuscarCotizacion()));
	connect(ui.actionMateriales, SIGNAL(triggered()),this, SLOT(setmateriales()));
	connect(ui.actionReportes_de_cotizaciones,SIGNAL(triggered()),this,SLOT(setrptcotizaciones()));
	connect(ui.actionServicios_Externos, SIGNAL(triggered()),this, SLOT(setServiciosExternos()));
	connect(ui.actionUsuarios,SIGNAL(triggered()),this,SLOT(setUsuarios()));
	connect(ui.actionBuscarReg,SIGNAL(triggered()),this,SLOT(setBusqueda()));
	connect(ui.pushButton_rpt,SIGNAL(clicked()),this,SLOT(botonLimpiarRpt()));
	connect(ui.pushButton_xls,SIGNAL(clicked()),this,SLOT(botonLimpiarExcel()));

	//mano de obra - cargos
	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(agregarfila())); //boton +
	//connect(ui.pushButton_5,SIGNAL(toggled(bool)),this,SLOT(actualizar())); //boton editar estados
	connect(ui.pushButton_2,SIGNAL(clicked()),this,SLOT(eliminarFila())); //boton -
	//connect(ui.tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(filaEditable(int,int))); //boton editar accion
	connect(ui.pushButton_5,SIGNAL(clicked()),this,SLOT(editarCargo()));
	fcargo=new formularioCargos;
	connect(fcargo->ui.pushButton,SIGNAL(clicked()),this,SLOT(nuevoCargo()));
	connect(fcargo->ui.pushButton_2,SIGNAL(clicked()),this,SLOT(updateCargo()));

	//mano de obra - actividades
	connect(ui.pushButton_4,SIGNAL(clicked()),this,SLOT(agregarfilaMo())); //boton +
	//connect(ui.pushButton_6,SIGNAL(toggled(bool)),this,SLOT(actualizarMo())); //boton editar estados
	connect(ui.pushButton_3,SIGNAL(clicked()),this,SLOT(eliminarFilaMo())); //boton -
	//connect(ui.tableWidget_2,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(filaEditableMo(int,int))); //boton editar accion
	connect(ui.pushButton_6,SIGNAL(clicked()),this,SLOT(editarActTrab()));
	fActTrab=new formularioActTrabajo;
	connect(fActTrab->ui.pushButton,SIGNAL(clicked()),this,SLOT(nuevaActTrab()));
	connect(fActTrab->ui.pushButton_2,SIGNAL(clicked()),this,SLOT(updateActTrab()));

	//maquina
	connect(ui.pushButton_22,SIGNAL(clicked()),this,SLOT(agregarfilaMaq())); //boton +
	//connect(ui.pushButton_23,SIGNAL(toggled(bool)),this,SLOT(actualizarMaq())); //boton editar estados
	connect(ui.pushButton_23,SIGNAL(clicked()),this,SLOT(editarMaq()));
	connect(ui.pushButton_24,SIGNAL(clicked()),this,SLOT(eliminarFilaMaq())); //boton -
	//connect(ui.tableWidget_3,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(filaEditableMaq(int,int))); //boton editar accion
	fmaquina=new formularioMaq;
	connect(fmaquina->ui.pushButton_3,SIGNAL(clicked()),this,SLOT(nuevaMaq()));
	connect(fmaquina->ui.pushButton_2,SIGNAL(clicked()),this,SLOT(updateMaq()));

	//servicios externos
	connect(ui.pushButton_37,SIGNAL(clicked()),this,SLOT(agregarfilaSExternos())); //boton +
	//connect(ui.pushButton_32,SIGNAL(toggled(bool)),this,SLOT(actualizarSExternos())); //boton editar estados
	connect(ui.pushButton_33,SIGNAL(clicked()),this,SLOT(eliminarFilaSExternos())); //boton -
	//connect(ui.tableWidget_15,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(filaEditableSExternos(int,int))); //boton editar accion
	connect(ui.pushButton_32,SIGNAL(clicked()),this,SLOT(editarSExterno()));
	fexternos=new formularioSerExternos;
	connect(fexternos->ui.pushButton,SIGNAL(clicked()),this,SLOT(nuevoSExterno()));
	connect(fexternos->ui.pushButton_2,SIGNAL(clicked()),this,SLOT(updateSExterno()));

	//materiales
	connect(ui.pushButton_44,SIGNAL(clicked()),this,SLOT(agregarfilaMat())); //boton +
	//connect(ui.pushButton_41,SIGNAL(toggled(bool)),this,SLOT(actualizarMat())); //boton editar estados
	connect(ui.pushButton_43,SIGNAL(clicked()),this,SLOT(eliminarFilaMat())); //boton -
	//connect(ui.tableWidget_14,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(filaEditableMat(int,int))); //boton editar accion
	connect(ui.pushButton_41,SIGNAL(clicked()),this,SLOT(editarMat()));
	fmateriales=new formularioMateriales;
	connect(fmateriales->ui.pushButton,SIGNAL(clicked()),this,SLOT(nuevoMat()));
	connect(fmateriales->ui.pushButton_2,SIGNAL(clicked()),this,SLOT(updateMat()));
	
	//herramientas
	connect(ui.pushButton_27,SIGNAL(clicked()),this,SLOT(agregarfilaHe())); //boton +
	//connect(ui.pushButton_25,SIGNAL(toggled(bool)),this,SLOT(actualizarHe())); //boton editar estados
	connect(ui.pushButton_26,SIGNAL(clicked()),this,SLOT(eliminarFilaHe())); //boton -
	//connect(ui.tableWidget_4,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(filaEditableHe(int,int))); //boton editar accion
	connect(ui.pushButton_25,SIGNAL(clicked()),this,SLOT(editarHerr()));
	fherr=new formularioHerr;
	connect(fherr->ui.pushButton,SIGNAL(clicked()),this,SLOT(nuevaHerr()));
	connect(fherr->ui.pushButton_2,SIGNAL(clicked()),this,SLOT(updateHerr()));

	//consumibles
	connect(ui.pushButton_29,SIGNAL(clicked()),this,SLOT(agregarfilaCons())); //boton +
	//connect(ui.pushButton_30,SIGNAL(toggled(bool)),this,SLOT(actualizarCons())); //boton editar estados
	connect(ui.pushButton_28,SIGNAL(clicked()),this,SLOT(eliminarFilaCons())); //boton -
	//connect(ui.tableWidget_5,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(filaEditableCons(int,int))); //boton editar accion
	connect(ui.pushButton_30,SIGNAL(clicked()),this,SLOT(editarCons()));
	fcons=new formularioConsumibles;
	connect(fcons->ui.pushButton,SIGNAL(clicked()),this,SLOT(nuevoCons()));
	connect(fcons->ui.pushButton_2,SIGNAL(clicked()),this,SLOT(updateCons()));

	//servicios básicos
	connect(ui.pushButton_8,SIGNAL(clicked()),this,SLOT(agregarfilaSer())); //boton +
	//connect(ui.pushButton_9,SIGNAL(toggled(bool)),this,SLOT(actualizarSer())); //boton editar estados
	connect(ui.pushButton_7,SIGNAL(clicked()),this,SLOT(eliminarFilaSer())); //boton -
	//connect(ui.tableWidget_6,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(filaEditableSer(int,int))); //boton editar accion
	connect(ui.pushButton_9,SIGNAL(clicked()),this,SLOT(editarSbasico()));
	fser=new formularioServicios;
	connect(fser->ui.pushButton,SIGNAL(clicked()),this,SLOT(nuevoSbasico()));
	connect(fser->ui.pushButton_2,SIGNAL(clicked()),this,SLOT(updateSbasico()));

	//mtto - insumos
	connect(ui.pushButton_15,SIGNAL(clicked()),this,SLOT(agregarfilaMtto())); //boton +
	//connect(ui.pushButton_14,SIGNAL(toggled(bool)),this,SLOT(actualizarMtto())); //boton editar estados
	connect(ui.pushButton_13,SIGNAL(clicked()),this,SLOT(eliminarFilaMtto())); //boton -
	//connect(ui.tableWidget_7,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(filaEditableMtto(int,int))); //boton editar accion
	connect(ui.pushButton_14,SIGNAL(clicked()),this,SLOT(editarInsumo()));
	finsumo=new formularioInsumos;
	connect(finsumo->ui.pushButton,SIGNAL(clicked()),this,SLOT(nuevoInsumo()));
	connect(finsumo->ui.pushButton_2,SIGNAL(clicked()),this,SLOT(updateInsumo()));

	//mtto - preventivo y correctivo
	//connect(ui.pushButton_11,SIGNAL(clicked()),this,SLOT(agregarfilaPrev())); //boton +
	//connect(ui.pushButton_10,SIGNAL(toggled(bool)),this,SLOT(actualizarPrev())); //boton editar estados
	//connect(ui.pushButton_12,SIGNAL(clicked()),this,SLOT(eliminarFilaPrev())); //boton -
	//connect(ui.tableWidget_8,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(filaEditablePrev(int,int))); //boton editar accion

	//actividades - categorías
	connect(ui.pushButton_16,SIGNAL(clicked()),this,SLOT(agregarfilaActC())); //boton +
	//connect(ui.pushButton_18,SIGNAL(toggled(bool)),this,SLOT(actualizarActC())); //boton editar estados
	connect(ui.pushButton_17,SIGNAL(clicked()),this,SLOT(eliminarFilaActC())); //boton -
	//connect(ui.tableWidget_9,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(filaEditableActC(int,int))); //boton editar accion
	connect(ui.pushButton_18,SIGNAL(clicked()),this,SLOT(editarCat()));
	fcat=new formularioCategorias;
	connect(fcat->ui.pushButton,SIGNAL(clicked()),this,SLOT(nuevaCat()));
	connect(fcat->ui.pushButton_2,SIGNAL(clicked()),this,SLOT(updateCat()));

	//actividades - actividades
	connect(ui.pushButton_20,SIGNAL(clicked()),this,SLOT(agregarfilaActAct())); //boton +
	//connect(ui.pushButton_19,SIGNAL(toggled(bool)),this,SLOT(actualizarActAct())); //boton editar estados
	connect(ui.pushButton_21,SIGNAL(clicked()),this,SLOT(eliminarFilaActAct())); //boton -
	//connect(ui.tableWidget_10,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(filaEditableActAct(int,int))); //boton editar accion
	connect(ui.pushButton_19,SIGNAL(clicked()),this,SLOT(editarActE()));
	fActEmp=new formularioActEmpresa;
	connect(fActEmp->ui.pushButton,SIGNAL(clicked()),this,SLOT(nuevaActE()));
	connect(fActEmp->ui.pushButton_2,SIGNAL(clicked()),this,SLOT(updateActE()));
	
	//actividades - Maquina
	connect(ui.pushButton_39,SIGNAL(clicked()),this,SLOT(agregarfilaMaqActividades())); //boton +
	//connect(ui.pushButton_40,SIGNAL(toggled(bool)),this,SLOT(actualizarMaqActividades())); //boton editar estados
	connect(ui.pushButton_38,SIGNAL(clicked()),this,SLOT(eliminarFilaMaqActividades())); //boton -
	//connect(ui.tableWidget_13,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(filaEditableMaqActividades(int,int))); //boton editar accion

	//buscar cotización
	connect(ui.radioButton_c,SIGNAL(clicked()),this,SLOT(habilitarBuscarCotizacion()));
	connect(ui.radioButton_2,SIGNAL(clicked()),this,SLOT(habilitarBuscarRuc()));
	connect(ui.radioButton_15,SIGNAL(clicked()),this,SLOT(habilitarBuscarProyecto()));
	connect(ui.radioButton_16,SIGNAL(clicked()),this,SLOT(habilitarBuscarFecha()));
	connect(ui.pushButton_36,SIGNAL(clicked()),this,SLOT(buscarCotizacion()));
	connect(ui.commandLinkButton_2,SIGNAL(clicked()),this,SLOT(resultadoCotizacion()));
	connect(ui.pushButton_35,SIGNAL(clicked()),this,SLOT(detalle()));
	connect(ui.commandLinkButton_4,SIGNAL(clicked()),this,SLOT(imprimirCotizacion()));
	connect(ui.modificar,SIGNAL(clicked()),this,SLOT(modificarCotizacion()));
	//nueva cotización
	/*connect(ui.pushButton_32,SIGNAL(clicked()),this,SLOT(sumarHerramienta()));*/
	connect(ui.pushButton_10,SIGNAL(clicked()),this,SLOT(sumarConsumible()));
	connect(ui.pushButton_34,SIGNAL(clicked()),this,SLOT(eliminarPrimeraCotizacion()));
	connect(ui.commandLinkButton,SIGNAL(clicked()),this,SLOT(segundaParte()));
	connect(ui.pushButton_71,SIGNAL(clicked()),this,SLOT(sumarMaq()));
	connect(ui.pushButton_72,SIGNAL(clicked()),this,SLOT(sumarActividad()));
	connect(ui.pushButton_73,SIGNAL(clicked()),this,SLOT(sumarMo()));
	//connect(ui.pushButton_37,SIGNAL(clicked()),this,SLOT(eliminarSegundaCotizacion()));
	//connect(ui.commandLinkButton_3,SIGNAL(clicked()),this,SLOT(terminarCotizacion()));
	//connect(ui.pushButton_42,SIGNAL(clicked()),this,SLOT(cancelarCotizacion()));
	connect(ui.pushButton_74,SIGNAL(clicked()),this,SLOT(sumarServExt()));
	connect(ui.pushButton_93,SIGNAL(clicked()),this,SLOT(sumarMaterial()));

	//USUARIOS
	connect(ui.pushButton_11,SIGNAL(clicked()),this,SLOT(verificarUsuario()));
	connect(ui.pushButton_12,SIGNAL(clicked()),this,SLOT(agregarUser()));
	connect(ui.pushButton_40,SIGNAL(clicked()),this,SLOT(modificarUser()));

	//INICIO
	connect(ui.commandInicio,SIGNAL(clicked()),this,SLOT(setInicio()));

	//BUSQUEDA FORMULARIOS
	connect(ui.comboBox_2,SIGNAL(currentIndexChanged(int)),this,SLOT(cambiarCombo(int)));
	connect(ui.pushButton_42,SIGNAL(clicked()),this,SLOT(tablaBusqueda()));
	connect(ui.pushButton_45,SIGNAL(clicked()),this,SLOT(mostrarFormlleno()));
	
	//CALCULOS EN TIEMPO REAL
	connect(fcons->ui.doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(costo_hora_consumibles(double)));
	//connect(fcons->ui.spinBox,SIGNAL(valueChanged(int)),this,SLOT(costo_hora_consumibles2(int)));
	connect(fcons->ui.comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(costo_hora_consumibles3(int)));
	
	connect(fherr->ui.doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(depre_herramientas(double)));
	connect(fherr->ui.spinBox,SIGNAL(valueChanged(int)),this,SLOT(depre_herramientas2(int)));
	connect(fherr->ui.spinBox_2,SIGNAL(valueChanged(int)),this,SLOT(depre_herramientas3(int)));

	connect(fherr->ui.doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(costo_hora_herramientas(double)));
	connect(fherr->ui.spinBox_2,SIGNAL(valueChanged(int)),this,SLOT(costo_hora_herramientas2(int)));
	connect(fherr->ui.comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(costo_hora_herramientas3(int)));

	connect(fherr->ui.doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(costo_total_herramientas(double)));
	connect(fherr->ui.spinBox_2,SIGNAL(valueChanged(int)),this,SLOT(costo_total_herramientas2(int)));
	connect(fherr->ui.spinBox,SIGNAL(valueChanged(int)),this,SLOT(costo_total_herramientas4(int)));
	connect(fherr->ui.comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(costo_total_herramientas3(int)));

	connect(finsumo->ui.doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(valor_total_insumo(double)));
	connect(finsumo->ui.spinBox,SIGNAL(valueChanged(int)),this,SLOT(valor_total_insumo2(int)));

	connect(finsumo->ui.doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(costo_hora_insumo(double)));
	connect(finsumo->ui.spinBox,SIGNAL(valueChanged(int)),this,SLOT(costo_hora_insumo2(int)));
	connect(finsumo->ui.comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(costo_hora_insumo3(int)));

	connect(fActTrab->ui.comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(costo_hora_actrab2(int)));
	connect(fActTrab->ui.spinBox,SIGNAL(valueChanged(int)),this,SLOT(costo_hora_actrab(int)));

	//vaciar tabla busqueda
	connect(ui.comboBox_2,SIGNAL(currentIndexChanged(int)),this,SLOT(borrartablaSlot(int)));
	connect(ui.comboBox_3,SIGNAL(currentIndexChanged(int)),this,SLOT(borrartablaSlot(int)));
	//cambio cmbo
	connect(ui.comboBox_5,SIGNAL(currentIndexChanged(int)),this,SLOT(cambiarcomboconsumible(int)));
}	

cosmec::~cosmec()
{

}
void cosmec::comboMaq(QTableWidget *tableNum,int fil, int col){
	comboMaquina=new QComboBox(this);
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	respuesta.exec("SELECT a.serie,a.modelo||' ('||a.cod_espe||')' FROM maquinas AS a ORDER BY a.modelo");
	record = respuesta.record();
	tamquery1=respuesta.size();
	idmaquinas=new int[tamquery1];
	int fila=0;
	while(respuesta.next()){
		QString uno;
		idmaquinas[fila]=respuesta.value(0).toInt();
		uno=respuesta.value(1).toString();
		comboMaquina->addItem(uno);
		fila++;
	}
	tableNum->setCellWidget(fil,col,comboMaquina);
	
}
void cosmec::comboCat(QTableWidget *tableNum,int fil, int col){
	comboCategoria=new QComboBox(this);
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	respuesta.exec("SELECT a.id_categoria_actividades,a.nombre FROM categoria_actividades AS a ORDER BY a.nombre");
	record = respuesta.record();
	tamquery1=respuesta.size();
	idactividades=new int[tamquery1];
	int fila=0;
	while(respuesta.next()){
		QString uno;
		idactividades[fila]=respuesta.value(0).toInt();
		uno=respuesta.value(1).toString();
		comboCategoria->addItem(uno);
		fila++;
	}
	tableNum->setCellWidget(fil,col,comboCategoria);
}
void cosmec::comboCargo(QTableWidget *tableNum,int fil, int col){
	comboCarg=new QComboBox(this);
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	respuesta.exec("SELECT a.id_cargo,a.nombre FROM cargo AS a ORDER BY a.nombre");
	record = respuesta.record();
	tamquery1=respuesta.size();
	idcargo=new int[tamquery1];
	int fila=0;
	while(respuesta.next()){
		QString uno;
		idcargo[fila]=respuesta.value(0).toInt();
		uno=respuesta.value(1).toString();
		comboCarg->addItem(uno);
		fila++;
	}
	tableNum->setCellWidget(fil,col,comboCarg);
}

void cosmec::comboActividades(QTableWidget *tableNum,int fil, int col){
	comboAct=new QComboBox(this);
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	respuesta.exec("SELECT c.id_actividad, c.nombre FROM actividades_trabajo AS c ORDER BY id_actividad");
	record = respuesta.record();
	tamquery1=respuesta.size();
	idact=new int[tamquery1];
	int fila=0;
	while(respuesta.next()){
		QString uno;
		idact[fila]=respuesta.value(0).toInt();
		uno=respuesta.value(1).toString();
		comboAct->addItem(uno);
		qDebug()<<idact[fila];
		fila++;
	}
	tableNum->setCellWidget(fil,col,comboAct);
	cosmecdb.close();
}
void cosmec::comboinsumos(QTableWidget *tableNum,int fil, int col){
	comboInsumo=new QComboBox(this);
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	respuesta.exec("SELECT a.id_insumo, a.nombre FROM insumos AS a ORDER BY a.id_insumo");
	record = respuesta.record();
	tamquery1=respuesta.size();
	idinsumocombo=new int[tamquery1];
	int fila=0;
	while(respuesta.next()){
		QString uno;
		idinsumocombo[fila]=respuesta.value(0).toInt();
		uno=respuesta.value(1).toString();
		comboInsumo->addItem(uno);
		fila++;
	}
	tableNum->setCellWidget(fil,col,comboInsumo);
}
//mano de obra - cargos
void cosmec::filaEditable(int row,int column)
{
	bool actChecked=ui.pushButton_5->isChecked();
	bool ultF= (row+1)==ui.tableWidget->rowCount();
	
	if(actChecked&&filaEdit==-1){ //para saber q fila
		filaEdit=row;
	}

	if((actChecked&&filaEdit==row)||(ultF&&!actChecked)){
		ui.tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
	}

	else{
		if(actChecked&&filaEdit!=row){
			QMessageBox msgBox;
			msgBox.setText("Solo puede editar una fila a la vez");
			msgBox.exec();
		}
		ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
}
void cosmec::eliminarFila()
{
	QString sql;
	int currentRow=ui.tableWidget->currentRow();
	if(currentRow==-1 ||(currentRow==ui.tableWidget->rowCount()-1)){
		QMessageBox msgBox;
		msgBox.setText("No hay fila seleccionada");
		msgBox.exec();
	}else{
		QTableWidgetItem *itab1 = ui.tableWidget->item(currentRow,0);
		int id=QString(itab1->text()).toInt();
		sql=QString("DELETE FROM cargo WHERE id_cargo=%1").arg(id);
		insertarsql(sql);
		sql="SELECT a.id_cargo,a.nombre,a.salario FROM cargo AS a";
		llenartabla(ui.tableWidget,sql);
		comboCargo(ui.tableWidget_2,ui.tableWidget_2->rowCount()-1,1);
	}
}
void cosmec::actualizar()
{
	if(ui.pushButton_5->isChecked()){
		ui.pushButton_5->setText("Guardar");
		ui.pushButton->setEnabled(false);
		ui.pushButton_2->setEnabled(false);
		ui.menuBar->setEnabled(false);
	}
	else
	{
		QString sql;
		QTableWidgetItem *itab1 = ui.tableWidget->item(filaEdit,0);
		QTableWidgetItem *itab2 = ui.tableWidget->item(filaEdit,1);
		QTableWidgetItem *itab3 = ui.tableWidget->item(filaEdit,2);
		if (((itab2!=0&& itab2->text().isEmpty()==false) && (itab3!=0&& itab3->text().isEmpty()==false))){
			int id=QString(itab1->text()).toInt();
			QString nombre=itab2->text();
			double salario=QString(itab3->text()).toDouble();
			sql=QString("UPDATE cargo SET nombre='%1', salario=%2 "
				"WHERE id_cargo=%3").arg(nombre).arg(salario).arg(id);
			insertarsql(sql);
			sql="SELECT a.id_cargo,a.nombre,a.salario FROM cargo AS a";
			llenartabla(ui.tableWidget,sql);
			comboCargo(ui.tableWidget_2,ui.tableWidget_2->rowCount()-1,1);
		}
		filaEdit=-1;
		comboH=false;
		ui.pushButton_5->setText("Actualizar");
		ui.pushButton->setEnabled(true);
		ui.pushButton_2->setEnabled(true);
		ui.menuBar->setEnabled(true);
	}
}
void cosmec::agregarfila(){
	/*const int currentRow =ui.tableWidget->rowCount();  
	QTableWidgetItem *itab2 = ui.tableWidget->item(currentRow-1,1);
	QTableWidgetItem *itab3 = ui.tableWidget->item(currentRow-1,2);
	QString sql;
	if(currentRow!=0){	
		if (((itab2!=0&& itab2->text().isEmpty()==false) && (itab3!=0&& itab3->text().isEmpty()==false))||(currentRow==0)){
		
			QString nombre=itab2->text();
			double salario=QString(itab3->text()).toDouble();
			sql=QString("INSERT INTO cargo(nombre, salario)"
				"VALUES ('%1',%2)").arg(nombre).arg(salario);
			insertarsql(sql);
			sql="SELECT a.id_cargo,a.nombre,a.salario FROM cargo AS a";
			llenartabla(ui.tableWidget,sql);
			comboCargo(ui.tableWidget_2,ui.tableWidget_2->rowCount()-1,1);
		}else{
			QMessageBox msgBox;
			msgBox.setText("Error: Un dato esta vacio");
			msgBox.exec();
		}
	}else{
		ui.tableWidget_2->insertRow(currentRow);
		comboCargo(ui.tableWidget_2,ui.tableWidget_2->rowCount()-1,1);
	}*/
	limpiarFCargo();

	fcargo->ui.pushButton_2->setVisible(false); //guardar
	fcargo->ui.pushButton->setVisible(true); //crear
	fcargo->show();

}

void cosmec::nuevoCargo(){
	QString sql;
	//quitar combobox y poner texto
	QString nombre=fcargo->ui.lineEdit_2->text();
	double salario=fcargo->ui.doubleSpinBox->value();
	if(nombre!="" && salario!=0){
		sql=QString("INSERT INTO cargo(nombre, salario)"
			"VALUES ('%1',%2)").arg(nombre).arg(salario);
		insertarsql(sql);
		sql="SELECT a.id_cargo,a.nombre,a.salario FROM cargo AS a";
		llenartabla(ui.tableWidget,sql);

		limpiarFCargo();
		fcargo->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
void cosmec::editarCargo(){
	limpiarFCargo();
	fcargo->ui.pushButton_2->setVisible(true); //guardar
	fcargo->ui.pushButton->setVisible(false); //crear

	int filh=ui.tableWidget->currentRow();
	if((filh!=ui.tableWidget->rowCount()-1)&&(filh>=0)){

		QTableWidgetItem *itab1 = ui.tableWidget->item(filh,0);
		QTableWidgetItem *itab2 = ui.tableWidget->item(filh,1);
		QTableWidgetItem *itab3 = ui.tableWidget->item(filh,2);

		QString id=itab1->text();
		QString nombre=itab2->text();
		QString salario=itab3->text();

		fcargo->ui.lineEdit->setText(id);
		fcargo->ui.lineEdit_2->setText(nombre);
		fcargo->ui.doubleSpinBox->setValue(QString(salario).toDouble());

		fcargo->show();
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("Seleccione un registro!");
		msgBox.exec();
	}

}
void cosmec::updateCargo(){
	QString sql;
	//quitar combobox y poner texto
	int id=QString(fcargo->ui.lineEdit->text()).toInt();
	QString nombre=fcargo->ui.lineEdit_2->text();
	double salario=fcargo->ui.doubleSpinBox->value();
	if(nombre!="" && salario!=0){
		sql=QString("UPDATE cargo SET nombre='%1', salario=%2 "
			"WHERE id_cargo=%3").arg(nombre).arg(salario).arg(id);
		insertarsql(sql);
		sql="SELECT a.id_cargo,a.nombre,a.salario FROM cargo AS a";
		llenartabla(ui.tableWidget,sql);

		limpiarFCargo();
		fcargo->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
//maquinaria
void cosmec::filaEditableMaq(int row,int column)
{
	bool actChecked=ui.pushButton_23->isChecked();
	bool ultF= (row+1)==ui.tableWidget_3->rowCount();
	
	if(actChecked&&filaEdit==-1){ //para saber q fila
		filaEdit=row;
	}

	if((actChecked&&filaEdit==row)||(ultF&&!actChecked)){
		ui.tableWidget_3->setEditTriggers(QAbstractItemView::DoubleClicked);
	}
	else{
		if(actChecked&&filaEdit!=row){
			QMessageBox msgBox;
			msgBox.setText("Solo puede editar una fila a la vez");
			msgBox.exec();
		}
		ui.tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
}
void cosmec::eliminarFilaMaq()
{
	int currentRow=ui.tableWidget_3->currentRow();
	QString sql;
	if(currentRow==-1||(currentRow==ui.tableWidget_3->rowCount()-1)){
		QMessageBox msgBox;
		msgBox.setText("No hay fila seleccionada");
		msgBox.exec();
	}else{
		QTableWidgetItem *itab1 = ui.tableWidget_3->item(currentRow,0);
		sql=QString("DELETE FROM maquinas WHERE serie=%1").arg(itab1->text());
		insertarsql(sql);
		sql="SELECT a.serie,a.cod_espe,a.modelo,a.costo,a.vida_util,a.horas_trabajo_anual,a.deprecicacion,a.costo_hora,a.presupuesto_anual FROM maquinas AS a ORDER BY a.modelo";
		llenartabla(ui.tableWidget_3,sql);
	}
	
}
void cosmec::actualizarMaq()
{
	if(ui.pushButton_23->isChecked()){
		ui.pushButton_23->setText("Guardar");
		ui.pushButton_22->setEnabled(false);
		ui.pushButton_24->setEnabled(false);
		ui.menuBar->setEnabled(false);
	}
	else
	{
		QString sql;
		QTableWidgetItem *itab1 = ui.tableWidget_3->item(filaEdit,0);
		QTableWidgetItem *itab2 = ui.tableWidget_3->item(filaEdit,1);
		QTableWidgetItem *itab3 = ui.tableWidget_3->item(filaEdit,2);
		QTableWidgetItem *itab4 = ui.tableWidget_3->item(filaEdit,3);
		QTableWidgetItem *itab5 = ui.tableWidget_3->item(filaEdit,4);
		QTableWidgetItem *itab6 = ui.tableWidget_3->item(filaEdit,5);
		QTableWidgetItem *itab7 = ui.tableWidget_3->item(filaEdit,6);
		QTableWidgetItem *itab8 = ui.tableWidget_3->item(filaEdit,7);
		QTableWidgetItem *itab9 = ui.tableWidget_3->item(filaEdit,8);
		if (((itab1!=0&& itab1->text().isEmpty()==false) && (itab2!=0&& itab2->text().isEmpty()==false) && (itab3!=0&& itab3->text().isEmpty()==false) && (itab4!=0&& itab4->text().isEmpty()==false)  && (itab5!=0&& itab5->text().isEmpty()==false) && (itab6!=0&& itab6->text().isEmpty()==false) && (itab9!=0&& itab9->text().isEmpty()==false))){
			QString serie=itab1->text();
			QString codespe=itab2->text();
			QString modelo=itab3->text();
			QString costo=itab4->text();
			QString vida=itab5->text();
			QString horas=itab6->text();
			QString presu=itab9->text();
			double depre=QString(costo).toDouble()/QString(vida).toDouble();
			double costo_hora=(2*QString(costo).toDouble())/(QString(horas).toDouble()*QString(vida).toDouble());
			sql=QString("UPDATE maquinas SET modelo='%2',cod_espe='%9',costo=%3,vida_util=%4,horas_trabajo_anual=%5,deprecicacion=%6,costo_hora=%7,presupuesto_anual=%8 WHERE serie=%1").arg(serie.toInt()).arg(modelo).arg(costo.toDouble()).arg(vida.toInt()).arg(horas.toInt()).arg(depre).arg(costo_hora).arg(presu.toDouble()).arg(codespe);
			qDebug()<<sql;
			insertarsql(sql);
			sql="SELECT a.serie,a.cod_espe,a.modelo,a.costo,a.vida_util,a.horas_trabajo_anual,a.deprecicacion,a.costo_hora,a.presupuesto_anual FROM maquinas AS a ORDER BY a.modelo";
			llenartabla(ui.tableWidget_3,sql);
		}
			//-------------------------
		filaEdit=-1;
		comboH=false;
		ui.pushButton_23->setText("Actualizar");
		ui.pushButton_22->setEnabled(true);
		ui.pushButton_24->setEnabled(true);
		ui.menuBar->setEnabled(true);
	}
}
void cosmec::agregarfilaMaq(){
	limpiarFMaq();
	QImage imagen2;
	fmaquina->ui.label_11->setPixmap(QPixmap::fromImage(imagen2));
	fmaquina->ui.pushButton_3->setVisible(true);
	fmaquina->ui.pushButton_2->setVisible(false);
	fmaquina->ui.pushButton->setVisible(true);
	fmaquina->ui.plainTextEdit->setVisible(true);
	fmaquina->ui.lineEdit->setEnabled(true);//lineEdit de maquina
	fmaquina->show();
}
void cosmec::nuevaMaq(){
	
	QString sql;
	QString path;
	QString serie=fmaquina->ui.lineEdit->text();
	QString codigo=fmaquina->ui.lineEdit_2->text();
	QString nombre=fmaquina->ui.lineEdit_3->text();
	double costo=fmaquina->ui.doubleSpinBox_2->value();
	int vida=fmaquina->ui.spinBox->value();
	int horas_anuales=fmaquina->ui.spinBox_2->value();
	double presupuesto=fmaquina->ui.doubleSpinBox_3->value();
	
	path=fmaquina->ui.plainTextEdit->toPlainText();
	QImage imagen(path);
	imagen=imagen.scaled(200,200);
	QSqlQuery query(cosmecdb);
	QByteArray ba;
	QBuffer buffer(&ba);
	imagen.save(&buffer,"PNG");
    
	if(serie!="" && codigo!="" && nombre!="" && costo!=0 && vida!=0 && horas_anuales!=0 && presupuesto!=0){
		double depre=costo/vida;
		double costo_hora=(2*costo)/(horas_anuales*vida);
		fmaquina->ui.lineEdit_5->setText(QString::number(depre));
		fmaquina->ui.lineEdit_10->setText(QString::number(costo_hora));

		sql=QString("INSERT INTO maquinas (serie,modelo,costo,vida_util,horas_trabajo_anual,deprecicacion,costo_hora,presupuesto_anual, "
			"cod_espe) VALUES (%1,'%2',%3,%4,%5,%6,%7,%8,'%9')").arg(serie.toInt()).arg(nombre).arg(costo).arg(vida).arg(horas_anuales).arg(depre).arg(costo_hora).arg(presupuesto).arg(codigo);
		insertarsql(sql);
				
		cosmecdb.open();
		query.prepare( "UPDATE maquinas SET imagen=decode(:photo,'hex') WHERE serie=:serie" );
		query.bindValue(":photo",ba.toHex()); // without toBase64()
		query.bindValue(":serie",serie);
		query.exec();
        
		sql="SELECT a.serie,a.cod_espe,a.modelo,a.costo,a.vida_util,a.horas_trabajo_anual,a.deprecicacion,a.costo_hora,a.presupuesto_anual FROM maquinas AS a ORDER BY a.modelo";
		llenartabla(ui.tableWidget_3,sql);

		limpiarFMaq();
		fmaquina->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}


}

void cosmec::editarMaq(){
	QString sql;
	QImage image;
	QPixmap* pixmap;
	QByteArray im;
	limpiarFMaq();
	fmaquina->ui.pushButton_3->setVisible(false);
	fmaquina->ui.pushButton_2->setVisible(true);
	fmaquina->ui.pushButton->setVisible(true);
	fmaquina->ui.plainTextEdit->setVisible(true);
	fmaquina->ui.lineEdit->setEnabled(false);

	int film=ui.tableWidget_3->currentRow();

	if((film!=ui.tableWidget_3->rowCount()-1)&&(film>=0)){
		QTableWidgetItem *itab1 = ui.tableWidget_3->item(film,0);
		QTableWidgetItem *itab2 = ui.tableWidget_3->item(film,1);
		QTableWidgetItem *itab3 = ui.tableWidget_3->item(film,2);
		QTableWidgetItem *itab4 = ui.tableWidget_3->item(film,3);
		QTableWidgetItem *itab5 = ui.tableWidget_3->item(film,4);
		QTableWidgetItem *itab6 = ui.tableWidget_3->item(film,5);
		QTableWidgetItem *itab7 = ui.tableWidget_3->item(film,6);
		QTableWidgetItem *itab8 = ui.tableWidget_3->item(film,7);
		QTableWidgetItem *itab9 = ui.tableWidget_3->item(film,8);

		QString serie=itab1->text();
		QString codespe=itab2->text();
		QString modelo=itab3->text();
		QString costo=itab4->text();
		QString vida=itab5->text();
		QString horas=itab6->text();
		QString presu=itab9->text();
		QString depre=itab7->text();
		QString costo_hora=itab8->text();
		
		fmaquina->ui.lineEdit->setText(serie);
		fmaquina->ui.lineEdit_2->setText(codespe);
		fmaquina->ui.lineEdit_3->setText(modelo);
		fmaquina->ui.lineEdit_5->setText(depre);
		fmaquina->ui.lineEdit_10->setText(costo_hora);
		fmaquina->ui.doubleSpinBox_2->setValue(QString(costo).toDouble());
		fmaquina->ui.doubleSpinBox_3->setValue(QString(presu).toDouble());
		fmaquina->ui.spinBox->setValue(QString(vida).toInt());
		fmaquina->ui.spinBox_2->setValue(QString(horas).toInt());

		sql=QString("SELECT encode(imagen,'base64') FROM maquinas WHERE serie=%1").arg(serie);
		im=sql_record(sql,0).toByteArray();
		qDebug()<<"imagen"<<im;
		image = QImage::fromData(QByteArray::fromBase64(im),"PNG");
		fmaquina->ui.label_11->setPixmap(QPixmap::fromImage(image));

		fmaquina->show();
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("Seleccione un registro!");
		msgBox.exec();
	}
}
void cosmec::updateMaq(){
	QString sql;
	QString path;
	QByteArray ba;
	QSqlQuery query(cosmecdb);
	QBuffer buffer(&ba);

	QString serie=fmaquina->ui.lineEdit->text();
	QString codigo=fmaquina->ui.lineEdit_2->text();
	QString nombre=fmaquina->ui.lineEdit_3->text();
	double costo=fmaquina->ui.doubleSpinBox_2->value();
	int vida=fmaquina->ui.spinBox->value();
	int horas_anuales=fmaquina->ui.spinBox_2->value();
	double presupuesto=fmaquina->ui.doubleSpinBox_3->value();
	path=fmaquina->ui.plainTextEdit->toPlainText();

	if(path==""){
		QImage imagen();
		fmaquina->ui.label_11->pixmap()->save(&buffer,"PNG");
	}else{
		QImage imagen(path);
		imagen=imagen.scaled(200,200);
		imagen.save(&buffer,"PNG");
	}

	cosmecdb.open();
	query.prepare( "UPDATE maquinas SET imagen=decode(:photo,'hex') WHERE serie=:serie" );
	query.bindValue(":photo",ba.toHex()); // without toBase64()
	query.bindValue(":serie",serie);
	query.exec();

	if(serie!="" && codigo!="" && nombre!="" && costo!=0 && vida!=0 && horas_anuales!=0 && presupuesto!=0){
		double depre=costo/vida;
		double costo_hora=(2*costo)/(horas_anuales*vida);
		fmaquina->ui.lineEdit_5->setText(QString::number(depre));
		fmaquina->ui.lineEdit_10->setText(QString::number(costo_hora));

		sql=QString("UPDATE maquinas SET modelo='%2',cod_espe='%9',costo=%3,vida_util=%4,horas_trabajo_anual=%5,"
			" deprecicacion=%6,costo_hora=%7,presupuesto_anual=%8 WHERE serie=%1").arg(serie.toInt()).arg(nombre).arg(costo).arg(vida).arg(horas_anuales).arg(depre).arg(costo_hora).arg(presupuesto).arg(codigo);
		insertarsql(sql);
		sql="SELECT a.serie,a.cod_espe,a.modelo,a.costo,a.vida_util,a.horas_trabajo_anual,a.deprecicacion,a.costo_hora,a.presupuesto_anual FROM maquinas AS a ORDER BY a.modelo";
		llenartabla(ui.tableWidget_3,sql);
		limpiarFMaq();
		fmaquina->close();
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}

}
//servicios externos
void cosmec::filaEditableSExternos(int row,int column)
{
	bool actChecked=ui.pushButton_32->isChecked();
	bool ultF= (row+1)==ui.tableWidget_15->rowCount();

	if(actChecked&&filaEdit==-1){ //para saber q fila
		filaEdit=row;
	}

	if((actChecked&&filaEdit==row)||(ultF&&!actChecked)){
		ui.tableWidget_15->setEditTriggers(QAbstractItemView::DoubleClicked);
	}
	else{
		if(actChecked&&filaEdit!=row){
			QMessageBox msgBox;
			msgBox.setText("Solo puede editar una fila a la vez");
			msgBox.exec();
		}
		ui.tableWidget_15->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
}
void cosmec::eliminarFilaSExternos()
{
	int currentRow=ui.tableWidget_15->currentRow();
	QString sql;
	if(currentRow==-1||(currentRow==ui.tableWidget_15->rowCount()-1)){
		QMessageBox msgBox;
		msgBox.setText("No hay fila seleccionada");
		msgBox.exec();
	}else{
		QTableWidgetItem *itab1 = ui.tableWidget_15->item(currentRow,0);
		sql=QString("DELETE FROM servicios_externos	WHERE id_servicios=%1").arg(itab1->text());
		insertarsql(sql);
		sql="SELECT id_servicios, nombre_srevicio, costo_hora FROM servicios_externos";
		llenartabla(ui.tableWidget_15,sql);
		
	}

}
void cosmec::actualizarSExternos()
{
	if(ui.pushButton_32->isChecked()){
		ui.pushButton_32->setText("Guardar");
		ui.pushButton_33->setEnabled(false);
		ui.pushButton_37->setEnabled(false);
		ui.menuBar->setEnabled(false);
	}
	else
	{
		QString sql;
		QTableWidgetItem *itab1 = ui.tableWidget_15->item(filaEdit,0);
		QTableWidgetItem *itab2 = ui.tableWidget_15->item(filaEdit,1);
		QTableWidgetItem *itab3 = ui.tableWidget_15->item(filaEdit,2);

		if (((itab2!=0&& itab2->text().isEmpty()==false) && (itab3!=0&& itab3->text().isEmpty()==false))){
			QString idSEx=itab1->text();
			QString nombre=itab2->text();
			double costo=QString(itab3->text()).toDouble();
			
			sql=QString("UPDATE servicios_externos SET nombre_srevicio='%1', costo_hora=%2"
				" WHERE id_servicios=%3").arg(nombre).arg(costo).arg(idSEx);
			insertarsql(sql);
			sql="SELECT id_servicios, nombre_srevicio, costo_hora FROM servicios_externos";
			llenartabla(ui.tableWidget_15,sql);
			
		}
		//-------------------------
		filaEdit=-1;
		comboH=false;
		ui.pushButton_32->setText("Actualizar");
		ui.pushButton_37->setEnabled(true);
		ui.pushButton_33->setEnabled(true);
		ui.menuBar->setEnabled(true);
	}
}
void cosmec::agregarfilaSExternos(){
	/*const int currentRow =ui.tableWidget_15->rowCount();
	if(currentRow!=0){
		QTableWidgetItem *itab1 = ui.tableWidget_15->item(currentRow-1,0);
		QTableWidgetItem *itab2 = ui.tableWidget_15->item(currentRow-1,1);
		QTableWidgetItem *itab3 = ui.tableWidget_15->item(currentRow-1,2);


		if (((itab2!=0&& itab2->text().isEmpty()==false) && (itab3!=0&& itab3->text().isEmpty()==false))||(currentRow==0)){
			QString sql;
			//QString idSEx=itab1->text();
			QString nombre=itab2->text();
			double costo=QString(itab3->text()).toDouble();

			sql=QString("INSERT INTO servicios_externos(nombre_srevicio, costo_hora)"
				" VALUES ('%1',%2)").arg(nombre).arg(costo);
			insertarsql(sql);
			sql="SELECT id_servicios,nombre_srevicio, costo_hora FROM servicios_externos";
			llenartabla(ui.tableWidget_15,sql);
			

		}else{
			QMessageBox msgBox;
			msgBox.setText("Error: Un dato esta vacio");
			msgBox.exec();
		}
	}else{
		ui.tableWidget_15->insertRow(currentRow);
	}*/
	limpiarFSexternos();
	fexternos->ui.pushButton_2->setVisible(false); //guardar
	fexternos->ui.pushButton->setVisible(true); //crear
	
	fexternos->show();
}


void cosmec::nuevoSExterno(){
	QString sql;
	//datos
	QString nombre=fexternos->ui.lineEdit_2->text();
	double costo=fexternos->ui.doubleSpinBox->value();
	if(nombre!="" && costo!=0){
		sql=QString("INSERT INTO servicios_externos(nombre_srevicio, costo_hora)"
			" VALUES ('%1',%2)").arg(nombre).arg(costo);
		insertarsql(sql);
		sql="SELECT id_servicios,nombre_srevicio, costo_hora FROM servicios_externos";
		llenartabla(ui.tableWidget_15,sql);

		limpiarFSexternos();
		fexternos->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
void cosmec::editarSExterno(){
	limpiarFSexternos();
	fexternos->ui.pushButton_2->setVisible(true); //guardar
	fexternos->ui.pushButton->setVisible(false); //crear

	int filh=ui.tableWidget_15->currentRow();
	if((filh!=ui.tableWidget_15->rowCount()-1)&&(filh>=0)){
		QTableWidgetItem *itab1 = ui.tableWidget_15->item(filh,0);
		QTableWidgetItem *itab2 = ui.tableWidget_15->item(filh,1);
		QTableWidgetItem *itab3 = ui.tableWidget_15->item(filh,2);

		QString id=itab1->text();
		QString nombre=itab2->text();
		QString costo=itab3->text();

		fexternos->ui.lineEdit->setText(id);
		fexternos->ui.lineEdit_2->setText(nombre);
		fexternos->ui.doubleSpinBox->setValue(QString(costo).toDouble());
		fexternos->show();

	}
	else{
		QMessageBox msgBox;
		msgBox.setText("Seleccione un registro!");
		msgBox.exec();
	}	
}
void cosmec::updateSExterno(){
	QString sql;
	//datos
	int idSEx=QString(fexternos->ui.lineEdit->text()).toInt();
	QString nombre=fexternos->ui.lineEdit_2->text();
	double costo=fexternos->ui.doubleSpinBox->value();
	if(nombre!="" && costo!=0){
		sql=QString("UPDATE servicios_externos SET nombre_srevicio='%1', costo_hora=%2"
			" WHERE id_servicios=%3").arg(nombre).arg(costo).arg(idSEx);
		insertarsql(sql);
		sql="SELECT id_servicios,nombre_srevicio, costo_hora FROM servicios_externos";
		llenartabla(ui.tableWidget_15,sql);

		limpiarFSexternos();
		fexternos->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
//materiales
void cosmec::filaEditableMat(int row,int column)
{
	bool actChecked=ui.pushButton_41->isChecked();
	bool ultF= (row+1)==ui.tableWidget_14->rowCount();

	if(actChecked&&filaEdit==-1){ //para saber q fila
		filaEdit=row;
	}

	if((actChecked&&filaEdit==row)||(ultF&&!actChecked)){
		ui.tableWidget_14->setEditTriggers(QAbstractItemView::DoubleClicked);
	}
	else{
		if(actChecked&&filaEdit!=row){
			QMessageBox msgBox;
			msgBox.setText("Solo puede editar una fila a la vez");
			msgBox.exec();
		}
		ui.tableWidget_14->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
}
void cosmec::eliminarFilaMat()
{
	int currentRow=ui.tableWidget_14->currentRow();
	QString sql;
	if(currentRow==-1||(currentRow==ui.tableWidget_14->rowCount()-1)){
		QMessageBox msgBox;
		msgBox.setText("No hay fila seleccionada");
		msgBox.exec();
	}else{
		QTableWidgetItem *itab1 = ui.tableWidget_14->item(currentRow,0);
		sql=QString("DELETE FROM materiales WHERE id_material=%1").arg(itab1->text());
		insertarsql(sql);
		sql="SELECT id_material, nombre, geometria, unidades, dimencion, costo,aplicacion"
			" FROM materiales";
		llenartabla(ui.tableWidget_14,sql);
	}

}
void cosmec::actualizarMat()
{
	if(ui.pushButton_41->isChecked()){
		ui.pushButton_41->setText("Guardar");
		ui.pushButton_44->setEnabled(false);
		ui.pushButton_43->setEnabled(false);
		ui.menuBar->setEnabled(false);
	}
	else
	{
		QString sql;
		QTableWidgetItem *itab1 = ui.tableWidget_14->item(filaEdit,0);
		QTableWidgetItem *itab2 = ui.tableWidget_14->item(filaEdit,1);
		QTableWidgetItem *itab3 = ui.tableWidget_14->item(filaEdit,2);
		QTableWidgetItem *itab4 = ui.tableWidget_14->item(filaEdit,3);
		QTableWidgetItem *itab5 = ui.tableWidget_14->item(filaEdit,4);
		if (((itab1!=0&& itab1->text().isEmpty()==false) &&(itab2!=0&& itab2->text().isEmpty()==false) && (itab3!=0&& itab3->text().isEmpty()==false) && (itab4!=0&& itab4->text().isEmpty()==false) && (itab5!=0&& itab5->text().isEmpty()==false))){
			QString id=itab1->text();
			QString material=itab2->text();
			QString geometria=itab3->text();
			QString dimensiones=itab4->text();
			QString costo=itab5->text();
			sql=QString("UPDATE materiales SET  nombre='%1', geometria='%2', dimencion='%3', costo=%4 "
				"WHERE id_material=%5").arg(material).arg(geometria).arg(dimensiones).arg(costo).arg(id);
			insertarsql(sql);
			sql="SELECT id_material, nombre, geometria, dimencion, costo"
				" FROM materiales";
			llenartabla(ui.tableWidget_14,sql);
		}
		//-------------------------
		filaEdit=-1;
		comboH=false;
		ui.pushButton_41->setText("Actualizar");
		ui.pushButton_43->setEnabled(true);
		ui.pushButton_44->setEnabled(true);
		ui.menuBar->setEnabled(true);
	}
}
void cosmec::agregarfilaMat(){
	/*const int currentRow =ui.tableWidget_14->rowCount();

	if(currentRow!=0){
		QTableWidgetItem *itab2 = ui.tableWidget_14->item(currentRow-1,1);
		QTableWidgetItem *itab3 = ui.tableWidget_14->item(currentRow-1,2);
		QTableWidgetItem *itab4 = ui.tableWidget_14->item(currentRow-1,3);
		QTableWidgetItem *itab5 = ui.tableWidget_14->item(currentRow-1,4);

		if (((itab2!=0&& itab2->text().isEmpty()==false) && (itab3!=0&& itab3->text().isEmpty()==false) && (itab4!=0&& itab4->text().isEmpty()==false) && (itab5!=0&& itab5->text().isEmpty()==false))||(currentRow==0)){
			QString sql;
			QString material=itab2->text();
			QString geometria=itab3->text();
			QString dimensiones=itab4->text();
			QString costo=itab5->text();
			sql=QString("INSERT INTO materiales(nombre, geometria, dimencion, costo)"
				"VALUES ('%1','%2','%3',%4)").arg(material).arg(geometria).arg(dimensiones).arg(costo);
			insertarsql(sql);
			sql="SELECT id_material, nombre, geometria, dimencion, costo"
			" FROM materiales";
			llenartabla(ui.tableWidget_14,sql);
		}else{
			QMessageBox msgBox;
			msgBox.setText("Error: Un dato esta vacio");
			msgBox.exec();
		}
	}else{
		ui.tableWidget_14->insertRow(currentRow);
	}*/
	limpiarFMateriales();
	fmateriales->ui.pushButton_2->setVisible(false); //guardar
	fmateriales->ui.pushButton->setVisible(true); //crear

	fmateriales->show();
}
void cosmec::nuevoMat(){
	QString sql;
	//datos
	QString material=fmateriales->ui.lineEdit_2->text();
	QString geometria=fmateriales->ui.lineEdit_3->text();
	QString dimensiones=fmateriales->ui.lineEdit_4->text();
	double costo=fmateriales->ui.doubleSpinBox->value();
	QString aplicacion=fmateriales->ui.plainTextEdit->toPlainText();
	QString unidad=fmateriales->ui.lineEdit_5->text();

	if(material!="" && geometria!="" && dimensiones!="" && costo!=0 && unidad!="" && aplicacion!=""){
		sql=QString("INSERT INTO materiales(nombre, geometria, unidades, dimencion, costo, aplicacion)"
			"VALUES ('%1','%2','%3','%4',%5,'%6')").arg(material).arg(geometria).arg(unidad).arg(dimensiones).arg(costo).arg(aplicacion);
		insertarsql(sql);
		sql="SELECT id_material, nombre, geometria, unidades, dimencion, costo, aplicacion"
			" FROM materiales";
		llenartabla(ui.tableWidget_14,sql);

		limpiarFSexternos();
		fmateriales->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
void cosmec::editarMat(){
	limpiarFMateriales();
	fmateriales->ui.pushButton_2->setVisible(true); //guardar
	fmateriales->ui.pushButton->setVisible(false); //crear

	int filh=ui.tableWidget_14->currentRow();
	if((filh!=ui.tableWidget_14->rowCount()-1)&&(filh>=0)){
		QTableWidgetItem *itab1 = ui.tableWidget_14->item(filh,0);
		QTableWidgetItem *itab2 = ui.tableWidget_14->item(filh,1);
		QTableWidgetItem *itab3 = ui.tableWidget_14->item(filh,2);
		QTableWidgetItem *itab4 = ui.tableWidget_14->item(filh,3);
		QTableWidgetItem *itab5 = ui.tableWidget_14->item(filh,4);
		QTableWidgetItem *itab6 = ui.tableWidget_14->item(filh,5);
		QTableWidgetItem *itab7 = ui.tableWidget_14->item(filh,6);

		QString id=itab1->text();
		QString material=itab2->text();
		QString geometria=itab3->text();
		QString unidad=itab4->text();
		QString dimensiones=itab5->text();
		QString costo=itab6->text();
		QString aplicacion=itab7->text();

		fmateriales->ui.lineEdit->setText(id);
		fmateriales->ui.lineEdit_2->setText(material);
		fmateriales->ui.lineEdit_3->setText(geometria);
		fmateriales->ui.lineEdit_4->setText(dimensiones);
		fmateriales->ui.lineEdit_5->setText(unidad);
		fmateriales->ui.doubleSpinBox->setValue(QString(costo).toDouble());
		fmateriales->ui.plainTextEdit->setPlainText(aplicacion);
		fmateriales->show();
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("Seleccione un registro!");
		msgBox.exec();
	}
}
void cosmec::updateMat(){
	QString sql;
	//datos
	QString id=fmateriales->ui.lineEdit->text();
	QString material=fmateriales->ui.lineEdit_2->text();
	QString geometria=fmateriales->ui.lineEdit_3->text();
	QString dimensiones=fmateriales->ui.lineEdit_4->text();
	double costo=fmateriales->ui.doubleSpinBox->value();
	QString aplicacion=fmateriales->ui.plainTextEdit->toPlainText();
	QString unidad=fmateriales->ui.lineEdit_5->text();

	if(material!="" && geometria!="" && dimensiones!="" && costo!=0){
		sql=QString("UPDATE materiales SET  nombre='%1', geometria='%2', dimencion='%3', costo=%4, aplicacion='%5',unidades='%6' "
			"WHERE id_material=%7").arg(material).arg(geometria).arg(dimensiones).arg(costo).arg(aplicacion).arg(unidad).arg(id);
		insertarsql(sql);
		sql="SELECT id_material, nombre, geometria, unidades, dimencion, costo, aplicacion"
			" FROM materiales";
		llenartabla(ui.tableWidget_14,sql);

		limpiarFSexternos();
		fmateriales->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
//herramientas
void cosmec::filaEditableHe(int row,int column)
{
	bool actChecked=ui.pushButton_25->isChecked();
	bool ultF= (row+1)==ui.tableWidget_4->rowCount();
	
	if(actChecked&&filaEdit==-1){ //para saber q fila
		filaEdit=row;
	}
		
	if((actChecked&&filaEdit==row)||(ultF&&!actChecked)){ //validar fila editable
		if(actChecked&&column==7){
			comboH=true; //para saber si hay combo
			comboMaq(ui.tableWidget_4,row,7);
		}
		ui.tableWidget_4->setEditTriggers(QAbstractItemView::DoubleClicked);
	}
	else{
		if(actChecked&&filaEdit!=row){
			QMessageBox msgBox;
			msgBox.setText("Solo puede editar una fila a la vez");
			msgBox.exec();
		}
		ui.tableWidget_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
}
void cosmec::eliminarFilaHe()
{
	int currentRow=ui.tableWidget_4->currentRow();
	QString sql;
	if(currentRow==-1||(currentRow==ui.tableWidget_4->rowCount()-1)){
		QMessageBox msgBox;
		msgBox.setText("No hay fila seleccionada");
		msgBox.exec();
	}else{
		QTableWidgetItem *itab1 = ui.tableWidget_4->item(currentRow,0);
		sql=QString("DELETE FROM herramientas WHERE id_herramienta=%1").arg(itab1->text());
		insertarsql(sql);
		QString sql="SELECT a.id_herramienta,a.nombre_herramienta,a.cantidad_anual,a.costo_unitario,a.vida_util,a.depreciacion,a.costo_hora,b.modelo FROM maquinas AS b,herramientas AS a WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
		llenartabla(ui.tableWidget_4,sql);
	}
}
void cosmec::actualizarHe()
{
	int id;
	QString sql;
	if(ui.pushButton_25->isChecked()){
		ui.pushButton_25->setText("Guardar");
		ui.pushButton_27->setEnabled(false);
		ui.pushButton_26->setEnabled(false);
		ui.menuBar->setEnabled(false);
	}
	else
	{	
		//quitar combobox y poner texto
		QTableWidgetItem *itab1 = ui.tableWidget_4->item(filaEdit,0);
		QTableWidgetItem *itab2 = ui.tableWidget_4->item(filaEdit,1);
		QTableWidgetItem *itab3 = ui.tableWidget_4->item(filaEdit,2);
		QTableWidgetItem *itab4 = ui.tableWidget_4->item(filaEdit,3);
		QTableWidgetItem *itab5 = ui.tableWidget_4->item(filaEdit,4);
		//datos
		if ((itab2!=0&& itab2->text().isEmpty()==false) && (itab3!=0&& itab3->text().isEmpty()==false) && (itab4!=0&& itab4->text().isEmpty()==false) && (itab5!=0&& itab5->text().isEmpty()==false)){
			int id_herramiento=QString(itab1->text()).toInt();
			if(comboH){
				QComboBox* anterio=(QComboBox*)ui.tableWidget_4->cellWidget(filaEdit,7);
				id=idmaquinas[anterio->currentIndex()];
			}else{
				id=sql_herramienta(id_herramiento,9).toInt();
			}
			
			QString nombre=itab2->text();
			int cantidad=QString(itab3->text()).toInt();
			double costo=QString(itab4->text()).toDouble();
			int vida=QString(itab5->text()).toInt();
			int hora=sql_maquina(id,5).toInt();
			double costo_cant=costo*cantidad;
			//calculos
			double depre=costo_cant/vida;
			double costo_hora=costo_cant/hora;
			double depre_hora=depre/hora;
			double costo_total=costo_hora+depre_hora;
			sql=QString("UPDATE herramientas SET nombre_herramienta='%1', costo_unitario=%2, vida_util=%3,depreciacion=%4, valor_hora=%5, depreciacion_hora=%6, costo_hora=%7,cantidad_anual=%8,serie_maquinas=%9 WHERE id_herramienta=%10").arg(nombre).arg(costo).arg(vida).arg(depre).arg(costo_hora).arg(depre_hora).arg(costo_total).arg(cantidad).arg(id).arg(id_herramiento);
			qDebug()<<sql;
			insertarsql(sql);
			QString sql="SELECT a.id_herramienta,a.nombre_herramienta,a.cantidad_anual,a.costo_unitario,a.vida_util,a.depreciacion,a.costo_hora,b.modelo FROM maquinas AS b,herramientas AS a WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
			llenartabla(ui.tableWidget_4,sql);
			comboMaq(ui.tableWidget_4,ui.tableWidget_4->rowCount()-1,7);
		}else{
			QMessageBox msgBox;
			msgBox.setText("Error: Un dato esta vacio");
			msgBox.exec();
		}
		filaEdit=-1;
		comboH=false;
		ui.pushButton_25->setText("Actualizar");
		ui.pushButton_27->setEnabled(true);
		ui.pushButton_26->setEnabled(true);
		ui.menuBar->setEnabled(true);
	}
}
void cosmec::agregarfilaHe(){
	limpiarFHerr();

	fherr->ui.pushButton_2->setVisible(false); //guardar
	fherr->ui.pushButton->setVisible(true); //crear
	//llenar combobox maq
	QString sql="SELECT a.serie,a.modelo,a.cod_espe FROM maquinas AS a ORDER BY a.modelo";
	llenarcombomaq(sql,fherr->ui.comboBox);
	fherr->show();
}
void cosmec::nuevaHerr(){
	QString sql;
	//datos
	int fila=fherr->ui.comboBox->currentIndex();
	int id_maquina=idmaquinas[fila];
	QString nombre=fherr->ui.lineEdit_5->text();
	int cantidad=fherr->ui.spinBox_2->value();
	double costo=fherr->ui.doubleSpinBox->value();
	int vida=fherr->ui.spinBox->value();
	int horas=sql_maquina(id_maquina,5).toInt();
	if(id_maquina!=0 && nombre!="" && costo!=0 && vida!=0 && horas!=0 && cantidad!=0 ){
		double costo_cant=costo*cantidad;
		//calculos
		double depre=(costo_cant/vida);
		double unitario_hora=(costo_cant/horas);
		double depre_hora=depre/horas;
		double costo_total=unitario_hora+depre_hora;
		sql=QString("INSERT INTO herramientas(nombre_herramienta,costo_unitario,vida_util,depreciacion, "
			"valor_hora,depreciacion_hora,costo_hora,cantidad_anual,serie_maquinas) VALUES ('%1',%2,%3,%4,%5,%6,%7,%8,%9)").arg(nombre).arg(costo).arg(vida).arg(depre).arg(unitario_hora).arg(depre_hora).arg(costo_total).arg(cantidad).arg(id_maquina);
		insertarsql(sql);
		sql="SELECT a.id_herramienta,a.nombre_herramienta,a.cantidad_anual,a.costo_unitario,a.vida_util,a.depreciacion,a.costo_hora,b.modelo FROM maquinas AS b,herramientas AS a WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
		llenartabla(ui.tableWidget_4,sql);

		limpiarFHerr();
		fherr->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
void cosmec::editarHerr(){
	limpiarFHerr();
	fherr->ui.pushButton_2->setVisible(true); //guardar
	fherr->ui.pushButton->setVisible(false); //crear
	
	int filh=ui.tableWidget_4->currentRow();
	if((filh!=ui.tableWidget_4->rowCount()-1)&&(filh>=0)){
		
		QTableWidgetItem *itab1 = ui.tableWidget_4->item(filh,0);
		QTableWidgetItem *itab2 = ui.tableWidget_4->item(filh,1);
		QTableWidgetItem *itab3 = ui.tableWidget_4->item(filh,2);
		QTableWidgetItem *itab4 = ui.tableWidget_4->item(filh,3);
		QTableWidgetItem *itab5 = ui.tableWidget_4->item(filh,4);
		QTableWidgetItem *itab6 = ui.tableWidget_4->item(filh,5);
		QTableWidgetItem *itab7 = ui.tableWidget_4->item(filh,6);
		QTableWidgetItem *itab8 = ui.tableWidget_4->item(filh,7);
		
		QString id_herramiento=itab1->text();
		QString nombre=itab2->text();
		QString cantidad=itab3->text();
		QString costo=itab4->text();
		QString vida=itab5->text();
		QString depre=itab6->text();
		QString costo_hora=itab7->text();
		QString maquina=itab8->text();

		fherr->ui.lineEdit_4->setText(id_herramiento);
		fherr->ui.lineEdit_5->setText(nombre);
		fherr->ui.doubleSpinBox->setValue(QString(costo).toDouble());
		fherr->ui.spinBox->setValue(QString(vida).toInt());
		fherr->ui.lineEdit->setText(depre);
		fherr->ui.lineEdit_2->setText(costo_hora);
		fherr->ui.spinBox_2->setValue(QString(cantidad).toInt());
		fherr->ui.lineEdit_3->setText(QString::number(QString(costo_hora).toDouble()*QString(cantidad).toInt()));
		fherr->ui.lineEdit_6->setText(maquina);
		//llenar combobox maq
		QString sql="SELECT a.serie,a.modelo,a.cod_espe FROM maquinas AS a ORDER BY a.modelo";
		llenarcombomaq(sql,fherr->ui.comboBox);
		int tam=fherr->ui.comboBox->count();
		int id=sql_herramienta(QString(id_herramiento).toInt(),9).toInt();
		int index=buscarid(idmaquinas,id,tam);
		fherr->ui.comboBox->setCurrentIndex(index);
		fherr->show();
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("Seleccione un registro!");
		msgBox.exec();
	}
}
void cosmec::updateHerr(){
	QString sql;
	int id_herramiento=QString(fherr->ui.lineEdit_4->text()).toInt();
	int id_maquina=sql_herramienta(id_herramiento,9).toInt();
	QString nombre=fherr->ui.lineEdit_5->text();
	int cantidad=fherr->ui.spinBox_2->value();
	double costo=fherr->ui.doubleSpinBox->value();
	int vida=fherr->ui.spinBox->value();
	int hora=sql_maquina(id_maquina,5).toInt();
	if(id_herramiento!=0 && id_maquina!=0 && nombre!="" && costo!=0 && vida!=0 && hora!=0 && cantidad!=0 ){
		//calculos
		double costo_cant=costo*cantidad;
		double depre=costo_cant/vida;
		double costo_hora=costo_cant/hora;
		double depre_hora=depre/hora;
		double costo_total=costo_hora+depre_hora;
		sql=QString("UPDATE herramientas SET nombre_herramienta='%1', costo_unitario=%2, vida_util=%3,depreciacion=%4, valor_hora=%5, "
			"depreciacion_hora=%6, costo_hora=%7,cantidad_anual=%8,serie_maquinas=%9 WHERE id_herramienta=%10").arg(nombre).arg(costo).arg(vida).arg(depre).arg(costo_hora).arg(depre_hora).arg(costo_total).arg(cantidad).arg(id_maquina).arg(id_herramiento);
		insertarsql(sql);
		sql="SELECT a.id_herramienta,a.nombre_herramienta,a.cantidad_anual,a.costo_unitario,a.vida_util,a.depreciacion,a.costo_hora,b.modelo FROM maquinas AS b,herramientas AS a WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
		llenartabla(ui.tableWidget_4,sql);

		limpiarFHerr();
		fherr->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
//consumibles
void cosmec::filaEditableCons(int row,int column)
{
	bool actChecked=ui.pushButton_30->isChecked();
	bool ultF= (row+1)==ui.tableWidget_5->rowCount();

	if(actChecked&&filaEdit==-1){
		filaEdit=row;
	}

	if((actChecked&&filaEdit==row)||(ultF&&!actChecked)){
		if(actChecked&&column==5){
			comboH=true;
			comboMaq(ui.tableWidget_5,row,5);
		}
		ui.tableWidget_5->setEditTriggers(QAbstractItemView::DoubleClicked);
	}
	else{
		if(actChecked&&filaEdit!=row){
			QMessageBox msgBox;
			msgBox.setText("Solo puede editar una fila a la vez");
			msgBox.exec();
		}
		ui.tableWidget_5->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
}
void cosmec::eliminarFilaCons()
{
	int currentRow=ui.tableWidget_5->currentRow();
	QString sql;
	if(currentRow==-1||(currentRow==ui.tableWidget_5->rowCount()-1)){
		QMessageBox msgBox;
		msgBox.setText("No hay fila seleccionada");
		msgBox.exec();
	}else{
		QTableWidgetItem *itab1 = ui.tableWidget_5->item(currentRow,0);
		sql=QString("DELETE FROM consumible WHERE id_consumible=%1").arg(itab1->text());
		insertarsql(sql);
		QString sql="SELECT a.id_consumible,a.nombre_consumible,a.costo_unitario,a.costo_hora,b.modelo,a.aplicacion FROM maquinas AS b,consumible AS a WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
		llenartabla(ui.tableWidget_5,sql);
	}
}
void cosmec::actualizarCons()
{
	int id;
	QString sql;
	if(ui.pushButton_30->isChecked()){
		ui.pushButton_30->setText("Guardar");
		ui.pushButton_29->setEnabled(false);
		ui.pushButton_28->setEnabled(false);
		ui.menuBar->setEnabled(false);
	}
	else
	{
		//quitar combobox y poner texto
		QTableWidgetItem *itab1 = ui.tableWidget_5->item(filaEdit,0);
		QTableWidgetItem *itab2 = ui.tableWidget_5->item(filaEdit,1);
		QTableWidgetItem *itab3 = ui.tableWidget_5->item(filaEdit,2);
		QTableWidgetItem *itab4 = ui.tableWidget_5->item(filaEdit,3);
		//datos
		if((itab2!=0&& itab2->text().isEmpty()==false) && (itab3!=0&& itab3->text().isEmpty()==false) && (itab4!=0&& itab4->text().isEmpty()==false)){
			int id_consumible=QString(itab1->text()).toInt();
			if(comboH){
				QComboBox* anterio=(QComboBox*)ui.tableWidget_5->cellWidget(filaEdit,5);
				id=idmaquinas[anterio->currentIndex()];
			}else{
				id=sql_consumibles(id_consumible,5).toInt();
			}
			QString nombre=itab2->text();
			int cantidad=QString(itab3->text()).toInt();
			double costo=QString(itab4->text()).toDouble();
			int horas=sql_maquina(id,5).toInt();
			double costo_cant=costo*cantidad;
			qDebug()<<horas;
			//calculos
			double costo_hora=costo_cant/horas;
			sql=QString("UPDATE consumible SET nombre_consumible='%1', costo_unitario=%2, costo_hora=%3, cantidad_anual=%4, " 
				"serie_maquinas=%5 WHERE id_consumible=%6").arg(nombre).arg(costo).arg(costo_hora).arg(cantidad).arg(id).arg(id_consumible);
			insertarsql(sql);
			sql="SELECT a.id_consumible,a.nombre_consumible,a.cantidad_anual,a.costo_unitario,a.costo_hora,b.modelo FROM maquinas AS b,consumible AS a WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
			llenartabla(ui.tableWidget_5,sql);
			comboMaq(ui.tableWidget_5,ui.tableWidget_5->rowCount()-1,5);
		}else{
			QMessageBox msgBox;
			msgBox.setText("Error: Un dato esta vacio");
			msgBox.exec();
		}
		filaEdit=-1;
		comboH=false;
		ui.pushButton_30->setText("Actualizar");
		ui.pushButton_29->setEnabled(true);
		ui.pushButton_28->setEnabled(true);
		ui.menuBar->setEnabled(true);
	}
}
void cosmec::agregarfilaCons(){
	/*const int currentRow =ui.tableWidget_5->rowCount();  
	QTableWidgetItem *itab2 = ui.tableWidget_5->item(currentRow-1,1);
	QTableWidgetItem *itab3 = ui.tableWidget_5->item(currentRow-1,2);
	QTableWidgetItem *itab4 = ui.tableWidget_5->item(currentRow-1,3);
	if(currentRow!=0){
		if (((itab2!=0&& itab2->text().isEmpty()==false) && (itab3!=0&& itab3->text().isEmpty()==false) && (itab4!=0&& itab4->text().isEmpty()==false))||(currentRow==0)){
			//quitar combobox y poner texto
			QComboBox* anterio=(QComboBox*)ui.tableWidget_5->cellWidget(currentRow-1,5);
			QString sql;
			//datos
			int fila=anterio->currentIndex();
			QString nombre=itab2->text();
			int cantidad=QString(itab3->text()).toInt();
			double costo=QString(itab4->text()).toDouble();
			int horas=sql_maquina(idmaquinas[fila],5).toInt();
			double costo_cant=costo*cantidad;
			//calculos
			double costo_hora=costo_cant/horas;
			sql=QString("INSERT INTO consumible(nombre_consumible, costo_unitario, costo_hora,cantidad_anual," 
				"serie_maquinas) VALUES ('%1',%2,%3,%4,%5)").arg(nombre).arg(costo).arg(costo_hora).arg(cantidad).arg(idmaquinas[fila]);
			insertarsql(sql);
			sql="SELECT a.id_consumible,a.nombre_consumible,a.cantidad_anual,a.costo_unitario,a.costo_hora,b.modelo FROM maquinas AS b,consumible AS a WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
			llenartabla(ui.tableWidget_5,sql);
			comboMaq(ui.tableWidget_5,ui.tableWidget_5->rowCount()-1,5);
		}else{
			QMessageBox msgBox;
			msgBox.setText("Error: Un dato esta vacio");
			msgBox.exec();	
		}
	}else{
		ui.tableWidget_5->insertRow(currentRow);
		comboMaq(ui.tableWidget_5,ui.tableWidget_5->rowCount()-1,5);
	}*/
	limpiarFCons();

	fcons->ui.pushButton->setVisible(true);//crear
	fcons->ui.pushButton_2->setVisible(false); //guardar
	
	//llenar combobox maq
	QString sql="SELECT a.serie,a.modelo,a.cod_espe FROM maquinas AS a ORDER BY a.modelo";
	llenarcombomaq(sql,fcons->ui.comboBox);

	fcons->show();
}
void cosmec::nuevoCons(){
	QString sql;
	//datos
	int fila=fcons->ui.comboBox->currentIndex();
	int id_maquina=idmaquinas[fila];
	QString nombre=fcons->ui.lineEdit_2->text();
	QString aplicacion=fcons->ui.plainTextEdit->toPlainText();
	//int cantidad=fcons->ui.spinBox->value();
	int cantidad=1;
	double costo=fcons->ui.doubleSpinBox->value();
	int horas=sql_maquina(id_maquina,5).toInt();
	if(id_maquina!=0 && nombre!="" && costo!=0 && aplicacion!=""){
		//calculos
		double costo_cant=costo*cantidad;
		double costo_hora=costo_cant/horas;
		sql=QString("INSERT INTO consumible(nombre_consumible, costo_unitario, costo_hora," 
			"serie_maquinas,aplicacion) VALUES ('%1',%2,%3,%4,'%5')").arg(nombre).arg(costo).arg(costo_hora).arg(idmaquinas[fila]).arg(aplicacion);
		insertarsql(sql);
		sql="SELECT a.id_consumible,a.nombre_consumible,a.costo_unitario,b.modelo,a.aplicacion FROM maquinas AS b,consumible AS a WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
		llenartabla(ui.tableWidget_5,sql);

		limpiarFCons();
		fcons->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
void cosmec::editarCons(){
	limpiarFCons();
	fcons->ui.pushButton->setVisible(false);//crear
	fcons->ui.pushButton_2->setVisible(true); //guardar
	
	int filh=ui.tableWidget_5->currentRow();
	if((filh!=ui.tableWidget_5->rowCount()-1)&&(filh>=0)){

		QTableWidgetItem *itab1 = ui.tableWidget_5->item(filh,0);
		QTableWidgetItem *itab2 = ui.tableWidget_5->item(filh,1);
		QTableWidgetItem *itab3 = ui.tableWidget_5->item(filh,2);
		//QTableWidgetItem *itab4 = ui.tableWidget_5->item(filh,3);
		QTableWidgetItem *itab5 = ui.tableWidget_5->item(filh,3);
		QTableWidgetItem *itab6 = ui.tableWidget_5->item(filh,4);

		QString id_consumible=itab1->text();
		QString nombre=itab2->text();
		QString costo=itab3->text();
		//QString costo_hora=itab4->text();
		QString maquina=itab5->text();
		QString aplicacion=itab6->text();
		
		fcons->ui.lineEdit->setText(id_consumible);
		fcons->ui.lineEdit_2->setText(nombre);
		fcons->ui.doubleSpinBox->setValue(QString(costo).toDouble());
		//fcons->ui.lineEdit_3->setText(costo_hora);
		fcons->ui.lineEdit_4->setText(maquina);
		fcons->ui.plainTextEdit->setPlainText(aplicacion);

		//llenar combobox maq
		QString sql="SELECT a.serie,a.modelo,a.cod_espe FROM maquinas AS a ORDER BY a.modelo";
		llenarcombomaq(sql,fcons->ui.comboBox);

		int tam=fcons->ui.comboBox->count();
		int id=sql_consumibles(QString(id_consumible).toInt(),4).toInt();
		int index=buscarid(idmaquinas,id,tam);
		fcons->ui.comboBox->setCurrentIndex(index);
		fcons->show();
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("Seleccione un registro!");
		msgBox.exec();
	}
}
void cosmec::updateCons(){
	QString sql;
	//datos
	int id_consumible=QString(fcons->ui.lineEdit->text()).toInt();
	int fila=fcons->ui.comboBox->currentIndex();
	int id=idmaquinas[fila];
	QString nombre=fcons->ui.lineEdit_2->text();
	QString aplicaciones=fcons->ui.plainTextEdit->toPlainText();
	//int cantidad=fcons->ui.spinBox->value();
	int cantidad=1;
	double costo=fcons->ui.doubleSpinBox->value();
	int horas=sql_maquina(id,5).toInt();
	if(id!=0 && cantidad!=0 && nombre!="" && costo!=0 && horas!=0){
		//calculos
		double costo_cant=costo*cantidad;
		double costo_hora=costo_cant/horas;
		sql=QString("UPDATE consumible SET nombre_consumible='%1', costo_unitario=%2, costo_hora=%3," 
			"serie_maquinas=%4,aplicacion='%5' WHERE id_consumible=%6").arg(nombre).arg(costo).arg(costo_hora).arg(id).arg(aplicaciones).arg(id_consumible);
		insertarsql(sql);
		sql="SELECT a.id_consumible,a.nombre_consumible,a.costo_unitario,b.modelo,a.aplicacion FROM maquinas AS b,consumible AS a WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
		llenartabla(ui.tableWidget_5,sql);

		limpiarFCons();
		fcons->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
//servicios básicos
void cosmec::filaEditableSer(int row,int column)
{
	bool actChecked=ui.pushButton_9->isChecked();
	bool ultF= (row+1)==ui.tableWidget_6->rowCount();

	if(actChecked&&filaEdit==-1){
		filaEdit=row;
	}

	if((actChecked&&filaEdit==row)||(ultF&&!actChecked)){
		if(actChecked&&column==7)
		{
			comboH=true;
			comboMaq(ui.tableWidget_6,row,7);
		}
		ui.tableWidget_6->setEditTriggers(QAbstractItemView::DoubleClicked);
	}
	else{
		if(actChecked&&filaEdit!=row){
			QMessageBox msgBox;
			msgBox.setText("Solo puede editar una fila a la vez");
			msgBox.exec();
		}
		ui.tableWidget_6->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
}
void cosmec::eliminarFilaSer()
{
	int currentRow=ui.tableWidget_6->currentRow();
	QString sql;
	if(currentRow==-1||(currentRow==ui.tableWidget_6->rowCount()-1)){
		QMessageBox msgBox;
		msgBox.setText("No hay fila seleccionada");
		msgBox.exec();
	}else{
		sql=QString("DELETE FROM serv_basico WHERE id_serv_basico=%1").arg(idenergia[currentRow]);
		insertarsql(sql);
		QString sql="SELECT a.nombre_servi, a.tipo_consum, a.unidad, a.consumo_serv, a.consumo_hora, "
			"a.costo_consu, a.costo_hora, b.modelo FROM serv_basico AS a, maquinas AS b WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
		cargaridenergia();
		llenartabla(ui.tableWidget_6,sql);
		if(ui.tableWidget_6->rowCount()!=0){
			comboMaq(ui.tableWidget_6,ui.tableWidget_6->rowCount()-1,7);
		}
	}
}
void cosmec::actualizarSer()
{
	QString sql;
	if(ui.pushButton_9->isChecked()){
		ui.pushButton_9->setText("Guardar");
		ui.pushButton_8->setEnabled(false);
		ui.pushButton_7->setEnabled(false);
		ui.menuBar->setEnabled(false);
	}
	else
	{
		int serie;
		QTableWidgetItem *itab1 = ui.tableWidget_6->item(filaEdit,0);
		QTableWidgetItem *itab2 = ui.tableWidget_6->item(filaEdit,1);
		QTableWidgetItem *itab3 = ui.tableWidget_6->item(filaEdit,2);
		QTableWidgetItem *itab4 = ui.tableWidget_6->item(filaEdit,3);
		QTableWidgetItem *itab6 = ui.tableWidget_6->item(filaEdit,5);
		
		if ((itab1!=0&& itab1->text().isEmpty()==false) && (itab2!=0&& itab2->text().isEmpty()==false) && (itab3!=0&& itab3->text().isEmpty()==false) && (itab4!=0&& itab4->text().isEmpty()==false) && (itab6!=0&& itab6->text().isEmpty()==false)){
			int id_energia=idenergia[filaEdit];
			if(comboH){
				QComboBox* anterio=(QComboBox*)ui.tableWidget_6->cellWidget(filaEdit,7);
				serie=idmaquinas[anterio->currentIndex()];
			}else{
				sql=QString("SELECT serie_maquinas FROM serv_basico WHERE id_serv_basico=%1").arg(id_energia);
				serie=sql_general(sql,0).toInt();
			}
			QString nombre=itab1->text();
			int horas=QString(itab2->text()).toInt();
			QString unidades=itab3->text();
			double consumo=QString(itab4->text()).toDouble();
			double costo_hora=QString(itab6->text()).toDouble();
			//calculos
			double consum_hora=consumo/horas;
			double costo_serv=consum_hora*costo_hora;

			sql=QString("UPDATE serv_basico	SET nombre_servi='%1', tipo_consum=%2, consumo_serv=%3, "
					"consumo_hora=%4, costo_consu=%5, costo_hora=%6, unidad='%7', serie_maquinas=%8 "
					"WHERE id_serv_basico=%9 ").arg(nombre).arg(horas).arg(consumo).arg(consum_hora).arg(costo_hora).arg(costo_serv).arg(unidades).arg(serie).arg(id_energia);
			insertarsql(sql);
			
			sql="SELECT a.nombre_servi, a.tipo_consum, a.unidad, a.consumo_serv, a.consumo_hora, "
				"a.costo_consu, a.costo_hora, b.modelo FROM serv_basico AS a, maquinas AS b WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
			cargaridenergia();
			llenartabla(ui.tableWidget_6,sql);
			comboMaq(ui.tableWidget_6,ui.tableWidget_6->rowCount()-1,7);
		}else{
			QMessageBox msgBox;
			msgBox.setText("Error: Un dato esta vacio");
			msgBox.exec();
		}
		filaEdit=-1;
		comboH=false;
		ui.pushButton_9->setText("Actualizar");
		ui.pushButton_8->setEnabled(true);
		ui.pushButton_7->setEnabled(true);
		ui.menuBar->setEnabled(true);
	}
}
void cosmec::agregarfilaSer(){
	/*const int currentRow =ui.tableWidget_6->rowCount();  
	QTableWidgetItem *itab1 = ui.tableWidget_6->item(currentRow-1,0);
	QTableWidgetItem *itab2 = ui.tableWidget_6->item(currentRow-1,1);
	QTableWidgetItem *itab3 = ui.tableWidget_6->item(currentRow-1,2);
	QTableWidgetItem *itab4 = ui.tableWidget_6->item(currentRow-1,3);
    //QTableWidgetItem *itab5 = ui.tableWidget_6->item(currentRow-1,4);
	QTableWidgetItem *itab6 = ui.tableWidget_6->item(currentRow-1,5);
	//QTableWidgetItem *itab7 = ui.tableWidget_6->item(currentRow-1,6);
	
	if(currentRow!=0){
		if (((itab1!=0&& itab1->text().isEmpty()==false) && (itab2!=0&& itab2->text().isEmpty()==false) && (itab3!=0&& itab3->text().isEmpty()==false) && (itab4!=0&& itab4->text().isEmpty()==false) && (itab6!=0&& itab6->text().isEmpty()==false))||(currentRow==0)){
			//quitar combobox y poner texto
			QComboBox* anterio=(QComboBox*)ui.tableWidget_6->cellWidget(currentRow-1,7);
			QString sql;
			//datos
			QString nombre=itab1->text();
			int horas=QString(itab2->text()).toInt();
			QString unidades=itab3->text();
			double consumo=QString(itab4->text()).toDouble();
			double costo_hora=QString(itab6->text()).toDouble();
			int fila=anterio->currentIndex();
			int serie=idmaquinas[fila];
			//calculos
			double consum_hora=consumo/horas;
			double costo_serv=consum_hora*costo_hora;
			sql=QString("INSERT INTO serv_basico(nombre_servi, tipo_consum, consumo_serv, consumo_hora, "
				"costo_consu, costo_hora, unidad, serie_maquinas) VALUES ('%1',%2,%3,%4,%5,%6,'%7',%8)").arg(nombre).arg(horas).arg(consumo)
				.arg(consum_hora).arg(costo_hora).arg(costo_serv).arg(unidades).arg(idmaquinas[fila]);
			insertarsql(sql);
			sql="SELECT a.nombre_servi, a.tipo_consum, a.unidad, a.consumo_serv, a.consumo_hora, "
				"a.costo_consu, a.costo_hora, b.modelo FROM serv_basico AS a, maquinas AS b WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
			cargaridenergia();
			llenartabla(ui.tableWidget_6,sql);
			comboMaq(ui.tableWidget_6,ui.tableWidget_6->rowCount()-1,7);
		}else{
			QMessageBox msgBox;
			msgBox.setText("Error: Un dato esta vacio");
			msgBox.exec();
		}
	}else{
		ui.tableWidget_6->insertRow(currentRow);
		comboMaq(ui.tableWidget_6,ui.tableWidget_6->rowCount()-1,7);
	}*/

	limpiarFser();
	fser->ui.pushButton_2->setVisible(false); //guardar
	fser->ui.pushButton->setVisible(true); //crear
	
	//llenar combobox maq
	QString sql="SELECT a.serie,a.modelo,a.cod_espe FROM maquinas AS a ORDER BY a.modelo";
	llenarcombomaq(sql,fser->ui.comboBox);
	fser->show();
}
void cosmec::nuevoSbasico(){
	QString sql;
	//datos
	QString nombre=fser->ui.lineEdit_2->text();
	int horas=fser->ui.spinBox->value();
	QString unidades=fser->ui.lineEdit_5->text();
	double consumo=fser->ui.doubleSpinBox->value();
	double costo_hora=fser->ui.doubleSpinBox_2->value();
	int fila=fser->ui.comboBox->currentIndex();
	int serie=idmaquinas[fila];
	if(nombre!="" && horas!=0 && unidades!="" && consumo!=0 && costo_hora!=0 && serie!=0){
		//calculos
		double consum_hora=consumo/horas;
		double costo_serv=consum_hora*costo_hora;
		sql=QString("INSERT INTO serv_basico(nombre_servi, tipo_consum, consumo_serv, consumo_hora, "
			"costo_consu, costo_hora, unidad, serie_maquinas) VALUES ('%1',%2,%3,%4,%5,%6,'%7',%8)").arg(nombre).arg(horas).arg(consumo)
			.arg(consum_hora).arg(costo_hora).arg(costo_serv).arg(unidades).arg(idmaquinas[fila]);
		insertarsql(sql);
		sql="SELECT a.nombre_servi, a.tipo_consum, a.unidad, a.consumo_serv, a.consumo_hora, "
			"a.costo_consu, a.costo_hora, b.modelo FROM serv_basico AS a, maquinas AS b WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
		cargaridenergia();
		llenartabla(ui.tableWidget_6,sql);

		limpiarFser();
		fser->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
void cosmec::editarSbasico(){
	limpiarFser();
	fser->ui.pushButton_2->setVisible(true); //guardar
	fser->ui.pushButton->setVisible(false); //crear
	
	int filh=ui.tableWidget_6->currentRow();
	if((filh!=ui.tableWidget_6->rowCount()-1)&&(filh>=0)){
		
		QTableWidgetItem *itab1 = ui.tableWidget_6->item(filh,0);
		QTableWidgetItem *itab2 = ui.tableWidget_6->item(filh,1);
		QTableWidgetItem *itab3 = ui.tableWidget_6->item(filh,2);
		QTableWidgetItem *itab4 = ui.tableWidget_6->item(filh,3);
		QTableWidgetItem *itab5 = ui.tableWidget_6->item(filh,4);
		QTableWidgetItem *itab6 = ui.tableWidget_6->item(filh,5);
		QTableWidgetItem *itab7 = ui.tableWidget_6->item(filh,6);
		QTableWidgetItem *itab8 = ui.tableWidget_6->item(filh,7);
		
		QString id_servicio=QString::number(idenergia[filh]);
		QString nombre=itab1->text();
		QString tiempo_consumo=itab2->text();
		QString unidades=itab3->text();
		QString consumo_total=itab4->text();
		QString consumo_hora=itab5->text();
		QString costo_unidad=itab6->text();
		QString costo_hora_servicio=itab7->text();
		QString maquina=itab8->text();

		fser->ui.lineEdit->setText(id_servicio);
		fser->ui.lineEdit_2->setText(nombre);
		fser->ui.spinBox->setValue(QString(tiempo_consumo).toInt());
		fser->ui.doubleSpinBox->setValue(QString(consumo_total).toDouble());
		fser->ui.lineEdit_3->setText(consumo_hora);
		fser->ui.doubleSpinBox_2->setValue(QString(costo_unidad).toDouble());
		fser->ui.lineEdit_4->setText(costo_hora_servicio);
		fser->ui.lineEdit_5->setText(unidades);
		fser->ui.lineEdit_6->setText(maquina);
		
		//llenar combobox maq
		QString sql="SELECT a.serie,a.modelo,a.cod_espe FROM maquinas AS a ORDER BY a.modelo";
		llenarcombomaq(sql,fser->ui.comboBox);
		
		int tam=fser->ui.comboBox->count();
		sql=QString("SELECT serie_maquinas FROM serv_basico WHERE id_serv_basico=%1").arg(id_servicio);
		int id=sql_general(sql,0).toInt();
		int index=buscarid(idmaquinas,id,tam);
		fser->ui.comboBox->setCurrentIndex(index);

		fser->show();

	}
	else{
		QMessageBox msgBox;
		msgBox.setText("Seleccione un registro!");
		msgBox.exec();
	}
}
void cosmec::updateSbasico(){
	QString sql;
	//datos
	int id_energia=QString(fser->ui.lineEdit->text()).toInt();
	QString nombre=fser->ui.lineEdit_2->text();
	int horas=fser->ui.spinBox->value();
	QString unidades=fser->ui.lineEdit_5->text();
	double consumo=fser->ui.doubleSpinBox->value();
	double costo_hora=fser->ui.doubleSpinBox_2->value();
	int fila=fser->ui.comboBox->currentIndex();
	int serie=idmaquinas[fila];
	if(nombre!="" && horas!=0 && unidades!="" && consumo!=0 && costo_hora!=0 && serie!=0){
		//calculos
		double consum_hora=consumo/horas;
		double costo_serv=consum_hora*costo_hora;
		sql=QString("UPDATE serv_basico	SET nombre_servi='%1', tipo_consum=%2, consumo_serv=%3, "
			"consumo_hora=%4, costo_consu=%5, costo_hora=%6, unidad='%7', serie_maquinas=%8 "
			"WHERE id_serv_basico=%9 ").arg(nombre).arg(horas).arg(consumo).arg(consum_hora).arg(costo_hora).arg(costo_serv).arg(unidades).arg(serie).arg(id_energia);
		insertarsql(sql);
		sql="SELECT a.nombre_servi, a.tipo_consum, a.unidad, a.consumo_serv, a.consumo_hora, "
			"a.costo_consu, a.costo_hora, b.modelo FROM serv_basico AS a, maquinas AS b WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
		cargaridenergia();
		llenartabla(ui.tableWidget_6,sql);

		limpiarFser();
		fser->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
//mtto insumos
void cosmec::filaEditableMtto(int row,int column)
{
	bool actChecked=ui.pushButton_14->isChecked();
	bool ultF= (row+1)==ui.tableWidget_7->rowCount();

	if(actChecked&&filaEdit==-1){
		filaEdit=row;
	}

	if((actChecked&&filaEdit==row)||(ultF&&!actChecked)){
		if(actChecked&&column==5)
		{
			comboH=true;
			comboMaq(ui.tableWidget_7,row,5);
		}
		ui.tableWidget_7->setEditTriggers(QAbstractItemView::DoubleClicked);
	}
	else{
		if(actChecked&&filaEdit!=row){
			QMessageBox msgBox;
			msgBox.setText("Solo puede editar una fila a la vez");
			msgBox.exec();
		}
		ui.tableWidget_7->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
}
void cosmec::eliminarFilaMtto()
{
	int currentRow=ui.tableWidget_7->currentRow();
	QString sql;
	if(currentRow==-1||(currentRow==ui.tableWidget_7->rowCount()-1)){
		QMessageBox msgBox;
		msgBox.setText("No hay fila seleccionada");
		msgBox.exec();
	}else{
		sql=QString("DELETE FROM mantenimiento_preventivo"
			" WHERE id_insumo=%1").arg(idinsumo[currentRow]);
		insertarsql(sql);

		QString sql="SELECT a.nombre, a.costo_unitario, a.cantidad_anual, "
			"a.valor_total, a.costo_hora, b.modelo FROM mantenimiento_preventivo AS a,maquinas AS b WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
		llenartabla(ui.tableWidget_7,sql);
		llenartabla(ui.tableWidget_7,sql);
		cargaridinsumo();

		sql="SELECT SUM(a.costo_hora) AS suma_prev, b.presupuesto_anual, round(cast(b.presupuesto_anual/b.horas_trabajo_anual AS numeric),2) AS costo_hora, "
			"round(cast((b.presupuesto_anual/b.horas_trabajo_anual)+(SUM(a.costo_hora)) as numeric),2) AS costo_total, b.modelo FROM mantenimiento_preventivo AS a, "
			"maquinas AS b WHERE a.serie_maquinas=b.serie GROUP BY b.serie ORDER BY b.modelo";
		llenartabla(ui.tableWidget_8,sql);
		llenartabla(ui.tableWidget_8,sql);
	}
}
void cosmec::actualizarMtto()
{
	if(ui.pushButton_14->isChecked()){
		ui.pushButton_14->setText("Guardar");
		ui.pushButton_15->setEnabled(false);
		ui.pushButton_13->setEnabled(false);
		ui.menuBar->setEnabled(false);
	}
	else
	{
		QTableWidgetItem *itab1 = ui.tableWidget_7->item(filaEdit,0);
		QTableWidgetItem *itab2 = ui.tableWidget_7->item(filaEdit,1);
		QTableWidgetItem *itab3 = ui.tableWidget_7->item(filaEdit,2);
		int id_maquina;
		QString sql;
		if (((itab1!=0&& itab1->text().isEmpty()==false)&& (itab2!=0&& itab2->text().isEmpty()==false) && (itab3!=0&& itab3->text().isEmpty()==false))){
			if(comboH){
				QComboBox* anterio=(QComboBox*)ui.tableWidget_7->cellWidget(filaEdit,5);
				id_maquina=idmaquinas[anterio->currentIndex()];
			}else{
				sql=QString("SELECT * FROM mantenimiento_preventivo WHERE id_insumo=%1").arg(idinsumo[filaEdit]);
				id_maquina=sql_general(sql,6).toInt();
			}
			int horas=sql_maquina(id_maquina,5).toInt();
			qDebug()<<horas;
			QString nombre=itab1->text();
			double costo_unitari=QString(itab2->text()).toDouble();
			int cantidad_anual=QString(itab3->text()).toInt();
			double valor_total=costo_unitari*cantidad_anual;
			double costo_hora=valor_total/horas;
			sql=QString("UPDATE mantenimiento_preventivo SET nombre='%1', costo_unitario=%2,"
				"cantidad_anual=%3, valor_total=%4,costo_hora=%5, serie_maquinas=%6"
				"WHERE id_insumo=%7").arg(nombre).arg(costo_unitari).arg(cantidad_anual).arg(valor_total).arg(costo_hora).arg(id_maquina).arg(idinsumo[filaEdit]);
			insertarsql(sql);
			sql="SELECT a.nombre, a.costo_unitario, a.cantidad_anual, "
				"a.valor_total, a.costo_hora, b.modelo FROM mantenimiento_preventivo AS a,maquinas AS b WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
			llenartabla(ui.tableWidget_7,sql);
			cargaridinsumo();

			sql="SELECT SUM(a.costo_hora) AS suma_prev, b.presupuesto_anual, round(cast(b.presupuesto_anual/b.horas_trabajo_anual AS numeric),2) AS costo_hora, "
				"round(cast((b.presupuesto_anual/b.horas_trabajo_anual)+(SUM(a.costo_hora)) as numeric),2) AS costo_total, b.modelo FROM mantenimiento_preventivo AS a, "
				"maquinas AS b WHERE a.serie_maquinas=b.serie GROUP BY b.serie ORDER BY b.modelo";
			llenartabla(ui.tableWidget_8,sql);

			comboMaq(ui.tableWidget_7,ui.tableWidget_7->rowCount()-1,5);
		}else{
			QMessageBox msgBox;
			msgBox.setText("Error: Un dato esta vacio");
			msgBox.exec();
		}
		filaEdit=-1;
		comboH=false;
		ui.pushButton_14->setText("Actualizar");
		ui.pushButton_15->setEnabled(true);
		ui.pushButton_13->setEnabled(true);
		ui.menuBar->setEnabled(true);
	}
}
void cosmec::agregarfilaMtto(){
	/*const int currentRow =ui.tableWidget_7->rowCount();  
	QTableWidgetItem *itab1 = ui.tableWidget_7->item(currentRow-1,0);
	QTableWidgetItem *itab2 = ui.tableWidget_7->item(currentRow-1,1);
	QTableWidgetItem *itab3 = ui.tableWidget_7->item(currentRow-1,2);
	

	if (((itab1!=0&& itab1->text().isEmpty()==false)&& (itab2!=0&& itab2->text().isEmpty()==false) && (itab3!=0&& itab3->text().isEmpty()==false))||(currentRow==0)){
		if(currentRow!=0){
			//quitar combobox y poner texto
			QString sql;
			QComboBox* anterio=(QComboBox*)ui.tableWidget_7->cellWidget(currentRow-1,5);
			int fila=anterio->currentIndex();
			int horas=sql_maquina(idmaquinas[fila],5).toInt();
			QString nombre=itab1->text();
			double costo_unitari=QString(itab2->text()).toDouble();
			int cantidad_anual=QString(itab3->text()).toInt();
			double valor_total=costo_unitari*cantidad_anual;
			double costo_hora=valor_total/horas;
			sql=QString("INSERT INTO mantenimiento_preventivo(nombre, costo_unitario, cantidad_anual, valor_total," 
				"costo_hora, serie_maquinas) VALUES ('%1',%2,%3,%4,%5,%6)").arg(nombre).arg(costo_unitari).arg(cantidad_anual).arg(valor_total).arg(costo_hora).arg(idmaquinas[fila]);
			insertarsql(sql);
			sql="SELECT a.nombre, a.costo_unitario, a.cantidad_anual, "
				"a.valor_total, a.costo_hora, b.modelo FROM mantenimiento_preventivo AS a,maquinas AS b WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
			llenartabla(ui.tableWidget_7,sql);
			cargaridinsumo();

			sql="SELECT SUM(a.costo_hora) AS suma_prev, b.presupuesto_anual, round(cast(b.presupuesto_anual/b.horas_trabajo_anual AS numeric),2) AS costo_hora, "
				"round(cast((b.presupuesto_anual/b.horas_trabajo_anual)+(SUM(a.costo_hora)) as numeric),2) AS costo_total, b.modelo FROM mantenimiento_preventivo AS a, "
				"maquinas AS b WHERE a.serie_maquinas=b.serie GROUP BY b.serie ORDER BY b.modelo";
			llenartabla(ui.tableWidget_8,sql);
			
			comboMaq(ui.tableWidget_7,ui.tableWidget_7->rowCount()-1,5);
		}else{
			QMessageBox msgBox;
			msgBox.setText("Error: Un dato esta vacio");
			msgBox.exec();
		}
	}else{
		ui.tableWidget_7->insertRow(currentRow);
		comboMaq(ui.tableWidget_7,ui.tableWidget_7->rowCount()-1,5);
	}*/
	limpiarFInsumos();

	finsumo->ui.pushButton_2->setVisible(false); //guardar
	finsumo->ui.pushButton->setVisible(true); //crear
	
	//llenar combobox maq
	QString sql="SELECT a.serie,a.modelo,a.cod_espe FROM maquinas AS a ORDER BY a.modelo";
	llenarcombomaq(sql,finsumo->ui.comboBox);
	
	finsumo->show();
}

void cosmec::nuevoInsumo(){
	QString sql;
	//datos
	int fila=finsumo->ui.comboBox->currentIndex();
	int id_maquinas=idmaquinas[fila];
	QString nombre=finsumo->ui.lineEdit_2->text();
	double costo_unitari=finsumo->ui.doubleSpinBox->value();
	int cantidad_anual=finsumo->ui.spinBox->value();
	int horas=sql_maquina(idmaquinas[fila],5).toInt();
	if(id_maquinas!=0 && nombre!="" && costo_unitari!=0 && cantidad_anual!=0 && horas!=0){
		//calculos
		double valor_total=costo_unitari*cantidad_anual;
		double costo_hora=valor_total/horas;
		sql=QString("INSERT INTO mantenimiento_preventivo(nombre, costo_unitario, cantidad_anual, valor_total," 
			"costo_hora, serie_maquinas) VALUES ('%1',%2,%3,%4,%5,%6)").arg(nombre).arg(costo_unitari).arg(cantidad_anual).arg(valor_total).arg(costo_hora).arg(idmaquinas[fila]);
		insertarsql(sql);
		sql="SELECT a.nombre, a.costo_unitario, a.cantidad_anual, "
			"a.valor_total, a.costo_hora, b.modelo FROM mantenimiento_preventivo AS a,maquinas AS b WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
		llenartabla(ui.tableWidget_7,sql);
		cargaridinsumo();

		sql="SELECT SUM(a.costo_hora) AS suma_prev, b.presupuesto_anual, round(cast(b.presupuesto_anual/b.horas_trabajo_anual AS numeric),2) AS costo_hora, "
			"round(cast((b.presupuesto_anual/b.horas_trabajo_anual)+(SUM(a.costo_hora)) as numeric),2) AS costo_total, b.modelo FROM mantenimiento_preventivo AS a, "
			"maquinas AS b WHERE a.serie_maquinas=b.serie GROUP BY b.serie ORDER BY b.modelo";
		llenartabla(ui.tableWidget_8,sql);

		limpiarFInsumos();
		finsumo->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
void cosmec::editarInsumo(){
	limpiarFInsumos();

	finsumo->ui.pushButton_2->setVisible(true); //guardar
	finsumo->ui.pushButton->setVisible(false); //crear

	int filh=ui.tableWidget_7->currentRow();
	if((filh!=ui.tableWidget_7->rowCount()-1)&&(filh>=0)){
		QTableWidgetItem *itab1 = ui.tableWidget_7->item(filh,0);
		QTableWidgetItem *itab2 = ui.tableWidget_7->item(filh,1);
		QTableWidgetItem *itab3 = ui.tableWidget_7->item(filh,2);
		QTableWidgetItem *itab4 = ui.tableWidget_7->item(filh,3);
		QTableWidgetItem *itab5 = ui.tableWidget_7->item(filh,4);
		QTableWidgetItem *itab6 = ui.tableWidget_7->item(filh,5);

		QString nombre=itab1->text();
		QString costo_unitario=itab2->text();
		QString cantidad=itab3->text();
		QString valor_total=itab4->text();
		QString costo_hora=itab5->text();
		QString maquina=itab6->text();
		QString id_insumo=QString::number(idinsumo[filh]);

		finsumo->ui.lineEdit->setText(id_insumo);
		finsumo->ui.lineEdit_2->setText(nombre);
		finsumo->ui.lineEdit_3->setText(valor_total);
		finsumo->ui.lineEdit_4->setText(costo_hora);
		finsumo->ui.lineEdit_5->setText(maquina);
		finsumo->ui.doubleSpinBox->setValue(QString(costo_unitario).toDouble());
		finsumo->ui.spinBox->setValue(QString(cantidad).toInt());
		
		//llenar combobox maq
		QString sql="SELECT a.serie,a.modelo,a.cod_espe FROM maquinas AS a ORDER BY a.modelo";
		llenarcombomaq(sql,finsumo->ui.comboBox);
		int tam=finsumo->ui.comboBox->count();
		sql=QString("SELECT * FROM mantenimiento_preventivo WHERE id_insumo=%1").arg(id_insumo);
		int id=sql_general(sql,6).toInt();
		int index=buscarid(idmaquinas,id,tam);
		finsumo->ui.comboBox->setCurrentIndex(index);

		finsumo->show();

	}
	else{
		QMessageBox msgBox;
		msgBox.setText("Seleccione un registro!");
		msgBox.exec();
	}
}
void cosmec::updateInsumo(){
	QString sql;
	//datos
	int id_insumo=QString(finsumo->ui.lineEdit->text()).toInt();
	int fila=finsumo->ui.comboBox->currentIndex();
	int id_maquinas=idmaquinas[fila];
	QString nombre=finsumo->ui.lineEdit_2->text();
	double costo_unitari=finsumo->ui.doubleSpinBox->value();
	int cantidad_anual=finsumo->ui.spinBox->value();
	int horas=sql_maquina(id_maquinas,5).toInt();
	if(id_maquinas!=0 && nombre!="" && costo_unitari!=0 && cantidad_anual!=0 && horas!=0){
		//calculos
		double valor_total=costo_unitari*cantidad_anual;
		double costo_hora=valor_total/horas;
		sql=QString("UPDATE mantenimiento_preventivo SET nombre='%1', costo_unitario=%2,"
			"cantidad_anual=%3, valor_total=%4,costo_hora=%5, serie_maquinas=%6"
			"WHERE id_insumo=%7").arg(nombre).arg(costo_unitari).arg(cantidad_anual).arg(valor_total).arg(costo_hora).arg(id_maquinas).arg(id_insumo);
		insertarsql(sql);
		sql="SELECT a.nombre, a.costo_unitario, a.cantidad_anual, "
			"a.valor_total, a.costo_hora, b.modelo FROM mantenimiento_preventivo AS a,maquinas AS b WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
		llenartabla(ui.tableWidget_7,sql);
		cargaridinsumo();

		sql="SELECT SUM(a.costo_hora) AS suma_prev, b.presupuesto_anual, round(cast(b.presupuesto_anual/b.horas_trabajo_anual AS numeric),2) AS costo_hora, "
			"round(cast((b.presupuesto_anual/b.horas_trabajo_anual)+(SUM(a.costo_hora)) as numeric),2) AS costo_total, b.modelo FROM mantenimiento_preventivo AS a, "
			"maquinas AS b WHERE a.serie_maquinas=b.serie GROUP BY b.serie ORDER BY b.modelo";
		llenartabla(ui.tableWidget_8,sql);

		limpiarFInsumos();
		finsumo->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
/*//mtto - preventivo y correctivo
void cosmec::filaEditablePrev(int row,int column)
{
	bool actChecked=ui.pushButton_10->isChecked();
	bool ultF= (row+1)==ui.tableWidget_8->rowCount();

	if(actChecked&&filaEdit==-1){
		filaEdit=row;
	}

	if((actChecked&&filaEdit==row)||(ultF&&!actChecked)){
		if(actChecked&&column==4)
		{
			comboH=true;
			comboMaq(ui.tableWidget_8,row,4);
		}
		ui.tableWidget_8->setEditTriggers(QAbstractItemView::DoubleClicked);
	}
	else{
		if(actChecked&&filaEdit!=row){
			QMessageBox msgBox;
			msgBox.setText("Solo puede editar una fila a la vez");
			msgBox.exec();
		}
		ui.tableWidget_8->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
}
void cosmec::eliminarFilaPrev()
{
	int currentRow=ui.tableWidget_8->currentRow();
	QString sql;
	if(currentRow==-1){
		QMessageBox msgBox;
		msgBox.setText("No hay fila seleccionada");
		msgBox.exec();
	}else{
		
	}
	ui.tableWidget_8->removeRow(currentRow);
}
void cosmec::actualizarPrev()
{
	if(ui.pushButton_10->isChecked()){
		ui.pushButton_10->setText("Guardar");
		ui.pushButton_11->setEnabled(false);
		ui.pushButton_12->setEnabled(false);
		ui.menuBar->setEnabled(false);
	}
	else
	{
		if(comboH){
			QComboBox* anterio=(QComboBox*)ui.tableWidget_8->cellWidget(filaEdit,4);
			QString tAnterior=anterio->currentText();
			ui.tableWidget_8->removeCellWidget(filaEdit,4);
			QTableWidgetItem *itemA = new QTableWidgetItem;
			itemA->setText(tAnterior);
			ui.tableWidget_8->setItem(filaEdit,4,itemA);
		}
		filaEdit=-1;
		comboH=false;
		ui.pushButton_10->setText("Actualizar");
		ui.pushButton_11->setEnabled(true);
		ui.pushButton_12->setEnabled(true);
		ui.menuBar->setEnabled(true);
	}
}
void cosmec::agregarfilaPrev(){
	const int currentRow =ui.tableWidget_8->rowCount();  
	QTableWidgetItem *itab1 = ui.tableWidget_8->item(currentRow-1,0);
	QTableWidgetItem *itab2 = ui.tableWidget_8->item(currentRow-1,1);
	QTableWidgetItem *itab3 = ui.tableWidget_8->item(currentRow-1,2);
	QTableWidgetItem *itab4 = ui.tableWidget_8->item(currentRow-1,3);
	if(currentRow!=0){
		if (((itab1!=0&& itab1->text().isEmpty()==false)&&(itab2!=0&& itab2->text().isEmpty()==false)&& (itab3!=0&& itab3->text().isEmpty()==false)&& (itab4!=0&& itab4->text().isEmpty()==false))||(currentRow==0)){
			//quitar combobox y poner texto
			QComboBox* anterio=(QComboBox*)ui.tableWidget_8->cellWidget(currentRow-1,4);
			QString tAnterior=anterio->currentText();
			ui.tableWidget_8->removeCellWidget(currentRow-1,4);
			QTableWidgetItem *itemA = new QTableWidgetItem;
			itemA->setText(tAnterior);
			ui.tableWidget_8->setItem(currentRow-1,4,itemA);
		}else{
			QMessageBox msgBox;
			msgBox.setText("Error: Un dato esta vacio");
			msgBox.exec();
		}
	}else{
		ui.tableWidget_8->insertRow(currentRow);
		comboMaq(ui.tableWidget_8,ui.tableWidget_8->rowCount()-1,4);
	}
}

*///actividades - categorias
void cosmec::filaEditableActC(int row,int column)
{
	bool actChecked=ui.pushButton_18->isChecked();
	bool ultF= (row+1)==ui.tableWidget_9->rowCount();
	
	if(actChecked&&filaEdit==-1){
		filaEdit=row;
	}

	if((actChecked&&filaEdit==row)||(ultF&&!actChecked)){
		ui.tableWidget_9->setEditTriggers(QAbstractItemView::DoubleClicked);
	}
	else{
		if(actChecked&&filaEdit!=row){
			QMessageBox msgBox;
			msgBox.setText("Solo puede editar una fila a la vez");
			msgBox.exec();
		}
		ui.tableWidget_9->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
}
void cosmec::eliminarFilaActC()
{
	int currentRow=ui.tableWidget_9->currentRow();
	QString sql;
	if(currentRow==-1||(currentRow==ui.tableWidget_9->rowCount()-1)){
		QMessageBox msgBox;
		msgBox.setText("No hay fila seleccionada");
		msgBox.exec();
	}else{
		QTableWidgetItem *itab1 = ui.tableWidget_9->item(currentRow,0);
		int id_cat=QString(itab1->text()).toInt();
		sql=QString("DELETE FROM actividades WHERE id_categoria_actividades_categoria_actividades=%1").arg(id_cat);
		insertarsql(sql);
		sql=QString("DELETE FROM categoria_actividades WHERE id_categoria_actividades=%1").arg(id_cat);
		insertarsql(sql);
		sql="SELECT a.id_categoria_actividades, a.nombre FROM categoria_actividades AS a";
		llenartabla(ui.tableWidget_9,sql);
		llenartabla(ui.tableWidget_9,sql);
		sql="SELECT a.id_actividad, a.nombre, a.costo_hora, b.nombre AS cargo FROM actividades AS a, categoria_actividades AS b WHERE a.id_categoria_actividades_categoria_actividades=b.id_categoria_actividades";
		llenartabla(ui.tableWidget_10,sql);
		llenartabla(ui.tableWidget_10,sql);
	}
}
void cosmec::actualizarActC()
{
	if(ui.pushButton_18->isChecked()){
		ui.pushButton_18->setText("Guardar");
		ui.pushButton_16->setEnabled(false);
		ui.pushButton_17->setEnabled(false);
		ui.menuBar->setEnabled(false);
	}
	else
	{
		QTableWidgetItem *itab1 = ui.tableWidget_9->item(filaEdit,0);
		QTableWidgetItem *itab2 = ui.tableWidget_9->item(filaEdit,1);
		QString sql;
		if (((itab2!=0 && itab2->text().isEmpty()==false))){
			int id_cat=QString(itab1->text()).toInt();
			QString nombre=itab2->text();
			sql=QString("UPDATE categoria_actividades SET nombre='%1' "
				"WHERE id_categoria_actividades=%2").arg(nombre).arg(id_cat);
			insertarsql(sql);
			sql="SELECT a.id_categoria_actividades, a.nombre FROM categoria_actividades AS a";
			llenartabla(ui.tableWidget_9,sql);
			llenartabla(ui.tableWidget_9,sql);
			sql="SELECT a.id_actividad, a.nombre, a.costo_hora, b.nombre AS cargo FROM actividades AS a, categoria_actividades AS b WHERE a.id_categoria_actividades_categoria_actividades=b.id_categoria_actividades";
			llenartabla(ui.tableWidget_10,sql);
			llenartabla(ui.tableWidget_10,sql);
			//leer la base de máquinas para tener datos
			comboCat(ui.tableWidget_10,ui.tableWidget_10->rowCount()-1,3);
		}
		filaEdit=-1;
		comboH=false;
		ui.pushButton_18->setText("Actualizar");
		ui.pushButton_16->setEnabled(true);
		ui.pushButton_17->setEnabled(true);
		ui.menuBar->setEnabled(true);
	}
}
void cosmec::agregarfilaActC(){
	/*const int currentRow =ui.tableWidget_9->rowCount();  
	QTableWidgetItem *itab2 = ui.tableWidget_9->item(currentRow-1,1);
	if(currentRow!=0){
		if (((itab2!=0 && itab2->text().isEmpty()==false))||(currentRow==0)){
			QString nombre=itab2->text();
			QString sql;
			sql=QString("INSERT INTO categoria_actividades(nombre) VALUES ('%1')").arg(nombre);
			insertarsql(sql);
			sql="SELECT a.id_categoria_actividades, a.nombre FROM categoria_actividades AS a";
			llenartabla(ui.tableWidget_9,sql);
			llenartabla(ui.tableWidget_9,sql);
			sql="SELECT a.id_actividad, a.nombre, a.costo_hora, b.nombre AS cargo FROM actividades AS a, categoria_actividades AS b WHERE a.id_categoria_actividades_categoria_actividades=b.id_categoria_actividades";
			llenartabla(ui.tableWidget_10,sql);
			llenartabla(ui.tableWidget_10,sql);
			//leer la base de máquinas para tener datos
	     	comboCat(ui.tableWidget_10,ui.tableWidget_10->rowCount()-1,3);
		}else{
			QMessageBox msgBox;
			msgBox.setText("Error: Un dato esta vacio");
			msgBox.exec();	
		}
	}else{
		ui.tableWidget_10->insertRow(currentRow);
		comboCat(ui.tableWidget_10,ui.tableWidget_10->rowCount()-1,3);
	}*/
	limpiarFCat();

	fcat->ui.pushButton_2->setVisible(false); //guardar
	fcat->ui.pushButton->setVisible(true); //crear

	fcat->show();

}

void cosmec::nuevaCat(){
	QString sql;
	//quitar combobox y poner texto
	QString nombre=fcat->ui.lineEdit_2->text();
	if(nombre!=""){
		sql=QString("INSERT INTO categoria_actividades(nombre) VALUES ('%1')").arg(nombre);
		insertarsql(sql);
		sql="SELECT a.id_categoria_actividades, a.nombre FROM categoria_actividades AS a";
		llenartabla(ui.tableWidget_9,sql);
		llenartabla(ui.tableWidget_9,sql);
		sql="SELECT a.id_actividad, a.nombre, a.costo_hora, b.nombre AS cargo FROM actividades AS a, categoria_actividades AS b WHERE a.id_categoria_actividades_categoria_actividades=b.id_categoria_actividades";
		llenartabla(ui.tableWidget_10,sql);
		llenartabla(ui.tableWidget_10,sql);

		limpiarFCat();
		fcat->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
void cosmec::editarCat(){
	limpiarFCat();
	fcat->ui.pushButton_2->setVisible(true); //guardar
	fcat->ui.pushButton->setVisible(false); //crear

	int filh=ui.tableWidget_9->currentRow();
	if((filh!=ui.tableWidget_9->rowCount()-1)&&(filh>=0)){
		QTableWidgetItem *itab1 = ui.tableWidget_9->item(filh,0);
		QTableWidgetItem *itab2 = ui.tableWidget_9->item(filh,1);

		QString id=itab1->text();
		QString categoria=itab2->text();

		fcat->ui.lineEdit->setText(id);
		fcat->ui.lineEdit_2->setText(categoria);
		fcat->show();
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("Seleccione un registro!");
		msgBox.exec();
	}
}
void cosmec::updateCat(){
	QString sql;
	int id_cat=QString(fcat->ui.lineEdit->text()).toInt();
	QString nombre=fcat->ui.lineEdit_2->text();
	if(nombre!=""){
		sql=QString("UPDATE categoria_actividades SET nombre='%1' "
			"WHERE id_categoria_actividades=%2").arg(nombre).arg(id_cat);
		insertarsql(sql);
		sql="SELECT a.id_categoria_actividades, a.nombre FROM categoria_actividades AS a";
		llenartabla(ui.tableWidget_9,sql);
		llenartabla(ui.tableWidget_9,sql);
		sql="SELECT a.id_actividad, a.nombre, a.costo_hora, b.nombre AS cargo FROM actividades AS a, categoria_actividades AS b WHERE a.id_categoria_actividades_categoria_actividades=b.id_categoria_actividades";
		llenartabla(ui.tableWidget_10,sql);
		llenartabla(ui.tableWidget_10,sql);

		limpiarFCat();
		fcat->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
//actividades - actividades
void cosmec::filaEditableActAct(int row,int column)
{
	bool actChecked=ui.pushButton_19->isChecked();
	bool ultF= (row+1)==ui.tableWidget_10->rowCount();

	if(actChecked&&filaEdit==-1){
		filaEdit=row;
	}

	if((actChecked&&filaEdit==row)||(ultF&&!actChecked)){
		if(actChecked&&column==3)
		{
			comboH=true;
			comboCat(ui.tableWidget_10,row,3);
		}
		ui.tableWidget_10->setEditTriggers(QAbstractItemView::DoubleClicked);
	}
	else{
		if(actChecked&&filaEdit!=row){
			QMessageBox msgBox;
			msgBox.setText("Solo puede editar una fila a la vez");
			msgBox.exec();
		}
		ui.tableWidget_10->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
}
void cosmec::eliminarFilaActAct()
{
	QString sql;
	int currentRow=ui.tableWidget_10->currentRow();
	if(currentRow==-1||(currentRow==ui.tableWidget_10->rowCount()-1)){
		QMessageBox msgBox;
		msgBox.setText("No hay fila seleccionada");
		msgBox.exec();
	}else{
		QTableWidgetItem *itab1 = ui.tableWidget_10->item(currentRow,0);
		int id_acti=QString(itab1->text()).toInt();
		sql=QString("DELETE FROM actividades WHERE id_actividad=%1").arg(id_acti);
		insertarsql(sql);
		sql="SELECT a.id_categoria_actividades, a.nombre FROM categoria_actividades AS a";
		llenartabla(ui.tableWidget_9,sql);
		llenartabla(ui.tableWidget_9,sql);
		sql="SELECT a.id_actividad, a.nombre, a.costo_hora, b.nombre AS cargo FROM actividades AS a, categoria_actividades AS b WHERE a.id_categoria_actividades_categoria_actividades=b.id_categoria_actividades";
		llenartabla(ui.tableWidget_10,sql);
		llenartabla(ui.tableWidget_10,sql);
	}
}
void cosmec::actualizarActAct()
{
	if(ui.pushButton_19->isChecked()){
		ui.pushButton_19->setText("Guardar");
		ui.pushButton_20->setEnabled(false);
		ui.pushButton_21->setEnabled(false);
		ui.menuBar->setEnabled(false);
	}
	else
	{
		QString sql;
		int id_cargo;
		QTableWidgetItem *itab1 = ui.tableWidget_10->item(filaEdit,0);
		QTableWidgetItem *itab2 = ui.tableWidget_10->item(filaEdit,1);
		QTableWidgetItem *itab3 = ui.tableWidget_10->item(filaEdit,2);
		if (((itab2!=0&& itab2->text().isEmpty()==false)&& (itab3!=0&& itab3->text().isEmpty()==false))){	
			int id_actividad=QString(itab1->text()).toInt();
			if(comboH){
				QComboBox* anterio=(QComboBox*)ui.tableWidget_10->cellWidget(filaEdit,3);
				id_cargo=idactividades[anterio->currentIndex()];
			}else{
				sql=QString("SELECT id_categoria_actividades_categoria_actividades FROM actividades WHERE id_actividad=%1").arg(id_actividad);
				id_cargo=sql_general(sql,0).toInt();	
			}
			QString nombre=itab2->text();
			double costo_hora=QString(itab3->text()).toDouble();
			sql=QString("UPDATE actividades	SET nombre='%1', costo_hora=%2, id_categoria_actividades_categoria_actividades=%3"
				"WHERE id_actividad=%4").arg(nombre).arg(costo_hora).arg(id_cargo).arg(id_actividad);
			insertarsql(sql);
			sql="SELECT a.id_categoria_actividades, a.nombre FROM categoria_actividades AS a";
			llenartabla(ui.tableWidget_9,sql);
			llenartabla(ui.tableWidget_9,sql);
			sql="SELECT a.id_actividad, a.nombre, a.costo_hora, b.nombre AS cargo FROM actividades AS a, categoria_actividades AS b WHERE a.id_categoria_actividades_categoria_actividades=b.id_categoria_actividades";
			llenartabla(ui.tableWidget_10,sql);
			llenartabla(ui.tableWidget_10,sql);
			comboCat(ui.tableWidget_10,ui.tableWidget_10->rowCount()-1,3);
		}else{
			QMessageBox msgBox;
			msgBox.setText("Error: Un dato esta vacio");
			msgBox.exec();
		}
		filaEdit=-1;
		comboH=false;
		ui.pushButton_19->setText("Actualizar");
		ui.pushButton_20->setEnabled(true);
		ui.pushButton_21->setEnabled(true);
		ui.menuBar->setEnabled(true);
	}
}
void cosmec::agregarfilaActAct(){
	/*QString sql;
	const int currentRow =ui.tableWidget_10->rowCount();  
	//QTableWidgetItem *itab1 = ui.tableWidget_10->item(currentRow-1,0);
	QTableWidgetItem *itab2 = ui.tableWidget_10->item(currentRow-1,1);
	QTableWidgetItem *itab3 = ui.tableWidget_10->item(currentRow-1,2);
	if(currentRow!=0){
		if (((itab2!=0&& itab2->text().isEmpty()==false)&& (itab3!=0&& itab3->text().isEmpty()==false))||(currentRow==0)){
		
			//quitar combobox y poner texto
			QComboBox* anterio=(QComboBox*)ui.tableWidget_10->cellWidget(currentRow-1,3);
			int id_cargo=idactividades[anterio->currentIndex()];
			QString nombre=itab2->text();
			double costo_hora=QString(itab3->text()).toDouble();
			sql=QString("INSERT INTO actividades(nombre, costo_hora, id_categoria_actividades_categoria_actividades)"
				" VALUES ('%1',%2,%3)").arg(nombre).arg(costo_hora).arg(id_cargo);
			insertarsql(sql);
			sql="SELECT a.id_categoria_actividades, a.nombre FROM categoria_actividades AS a";
			llenartabla(ui.tableWidget_9,sql);
			llenartabla(ui.tableWidget_9,sql);
			sql="SELECT a.id_actividad, a.nombre, a.costo_hora, b.nombre AS cargo FROM actividades AS a, categoria_actividades AS b WHERE a.id_categoria_actividades_categoria_actividades=b.id_categoria_actividades";
			llenartabla(ui.tableWidget_10,sql);
			llenartabla(ui.tableWidget_10,sql);
			comboCat(ui.tableWidget_10,ui.tableWidget_10->rowCount()-1,3);
		}else{
			QMessageBox msgBox;
			msgBox.setText("Error: Un dato esta vacio");
			msgBox.exec();
		}
	}else{
		ui.tableWidget_10->insertRow(currentRow);
		comboCat(ui.tableWidget_10,ui.tableWidget_10->rowCount()-1,3);
	}*/
	limpiarFActE();

	fActEmp->ui.pushButton_2->setVisible(false); //guardar
	fActEmp->ui.pushButton->setVisible(true); //crear

	//llenar combo con categoria
	QString sql="SELECT a.id_categoria_actividades,a.nombre FROM categoria_actividades AS a ORDER BY a.nombre";
	llenarcombocat(sql,fActEmp->ui.comboBox);
	fActEmp->show();
}

void cosmec::nuevaActE(){
	QString sql;
	//quitar combobox y poner texto
	int id_categoria=idcategoria[fActEmp->ui.comboBox->currentIndex()];
	QString nombre=fActEmp->ui.lineEdit_2->text();
	double costo_hora=fActEmp->ui.doubleSpinBox->value();
	if(id_categoria!=0 && nombre!="" && costo_hora!=0){
		sql=QString("INSERT INTO actividades(nombre, costo_hora, id_categoria_actividades_categoria_actividades)"
			" VALUES ('%1',%2,%3)").arg(nombre).arg(costo_hora).arg(id_categoria);
		insertarsql(sql);
		sql="SELECT a.id_categoria_actividades, a.nombre FROM categoria_actividades AS a";
		llenartabla(ui.tableWidget_9,sql);
		llenartabla(ui.tableWidget_9,sql);
		sql="SELECT a.id_actividad, a.nombre, a.costo_hora, b.nombre AS cargo FROM actividades AS a, categoria_actividades AS b WHERE a.id_categoria_actividades_categoria_actividades=b.id_categoria_actividades";
		llenartabla(ui.tableWidget_10,sql);
		llenartabla(ui.tableWidget_10,sql);

		limpiarFActE();
		fActEmp->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
void cosmec::editarActE(){
	limpiarFActE();
	fActEmp->ui.pushButton_2->setVisible(true); //guardar
	fActEmp->ui.pushButton->setVisible(false); //crear

	int filh=ui.tableWidget_10->currentRow();
	if((filh!=ui.tableWidget_10->rowCount()-1)&&(filh>=0)){
		QTableWidgetItem *itab1 = ui.tableWidget_10->item(filh,0);
		QTableWidgetItem *itab2 = ui.tableWidget_10->item(filh,1);
		QTableWidgetItem *itab3 = ui.tableWidget_10->item(filh,2);
		QTableWidgetItem *itab4 = ui.tableWidget_10->item(filh,3);

		QString id=itab1->text();
		QString	actividad=itab2->text();
		QString	costo_hora=itab3->text();
		QString	categoria=itab4->text();

		fActEmp->ui.lineEdit->setText(id);
		fActEmp->ui.lineEdit_2->setText(actividad);
		fActEmp->ui.lineEdit_3->setText(categoria);
		fActEmp->ui.doubleSpinBox->setValue(QString(costo_hora).toDouble());
		
		//llenar combo con categoria
		QString sql="SELECT a.id_categoria_actividades,a.nombre FROM categoria_actividades AS a ORDER BY a.nombre";
		llenarcombocat(sql,fActEmp->ui.comboBox);
		int tam=fActEmp->ui.comboBox->count();
		sql=QString("SELECT id_categoria_actividades_categoria_actividades FROM actividades WHERE id_actividad=%1").arg(id);
		int id_categoria=sql_general(sql,0).toInt();
		int index=buscarid(idcategoria,id_categoria,tam);
		
		fActEmp->ui.comboBox->setCurrentIndex(index);
		fActEmp->show();
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("Seleccione un registro!");
		msgBox.exec();
	}

}
void cosmec::updateActE(){
	QString sql;
	//quitar combobox y poner texto
	int id_actividad=QString(fActEmp->ui.lineEdit->text()).toInt();
	int id_categoria=idcategoria[fActEmp->ui.comboBox->currentIndex()];
	QString nombre=fActEmp->ui.lineEdit_2->text();
	double costo_hora=fActEmp->ui.doubleSpinBox->value();
	if(id_categoria!=0 && nombre!="" && costo_hora!=0){
		sql=QString("UPDATE actividades	SET nombre='%1', costo_hora=%2, id_categoria_actividades_categoria_actividades=%3"
			"WHERE id_actividad=%4").arg(nombre).arg(costo_hora).arg(id_categoria).arg(id_actividad);
		insertarsql(sql);
		sql="SELECT a.id_categoria_actividades, a.nombre FROM categoria_actividades AS a";
		llenartabla(ui.tableWidget_9,sql);
		llenartabla(ui.tableWidget_9,sql);
		sql="SELECT a.id_actividad, a.nombre, a.costo_hora, b.nombre AS cargo FROM actividades AS a, categoria_actividades AS b WHERE a.id_categoria_actividades_categoria_actividades=b.id_categoria_actividades";
		llenartabla(ui.tableWidget_10,sql);
		llenartabla(ui.tableWidget_10,sql);

		limpiarFActE();
		fActEmp->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}
}
//mano de obra - actividades
void cosmec::filaEditableMo(int row,int column)
{
	bool actChecked=ui.pushButton_6->isChecked();
	bool ultF= (row+1)==ui.tableWidget_2->rowCount();

	if(actChecked&&filaEdit==-1){
		filaEdit=row;
	}

	if((actChecked&&filaEdit==row)||(ultF&&!actChecked)){
		if(actChecked&&column==1)
		{
			comboH=true;
			comboCargo(ui.tableWidget_2,row,1);
		}
		ui.tableWidget_2->setEditTriggers(QAbstractItemView::DoubleClicked);
	}
	else{
		if(actChecked&&filaEdit!=row){
			QMessageBox msgBox;
			msgBox.setText("Solo puede editar una fila a la vez");
			msgBox.exec();
		}
		ui.tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}
}
void cosmec::eliminarFilaMo()
{
	int currentRow=ui.tableWidget_2->currentRow();
	QString sql;
	if(currentRow==-1||(currentRow==ui.tableWidget_2->rowCount()-1)){
		QMessageBox msgBox;
		msgBox.setText("No hay fila seleccionada");
		msgBox.exec();
	}else{
		sql=QString("DELETE FROM actividades_trabajo"
			" WHERE id_actividad=%1").arg(idactividades[currentRow]);
		insertarsql(sql);
		cargaridactividades();
		sql="SELECT b.nombre, a.nombre AS nombre_cargo, b.hora_mensual, b.costo_mes, b.costo_hora FROM cargo AS a,actividades_trabajo AS b WHERE a.id_cargo=b.id_cargo_cargo ORDER BY a.nombre";
		llenartabla(ui.tableWidget_2,sql);
		if(ui.tableWidget_2->rowCount()!=0){
			comboCargo(ui.tableWidget_2,ui.tableWidget_2->rowCount()-1,1);
		}
	}
}
void cosmec::actualizarMo()
{
	QString sql;
	int id_cargo;
	if(ui.pushButton_6->isChecked()){
		ui.pushButton_6->setText("Guardar");
		ui.pushButton_4->setEnabled(false);
		ui.pushButton_3->setEnabled(false);
		ui.menuBar->setEnabled(false);
	}
	else
	{	
		QTableWidgetItem *itab1 = ui.tableWidget_2->item(filaEdit,0);
		QTableWidgetItem *itab3 = ui.tableWidget_2->item(filaEdit,2);
		QTableWidgetItem *itab4 = ui.tableWidget_2->item(filaEdit,3);
		if (((itab1!=0&&itab1->text().isEmpty()==false)&& (itab3!=0&& itab3->text().isEmpty()==false)&& (itab4!=0&& itab4->text().isEmpty()==false))){
			int id_actividad=idactividades[filaEdit];
			if(comboH){
				QComboBox* anterio=(QComboBox*)ui.tableWidget_2->cellWidget(filaEdit,1);
				id_cargo=idcargo[anterio->currentIndex()];
			}else{
				sql=QString("SELECT * FROM actividades_trabajo WHERE id_actividad=%1").arg(id_actividad);
				id_cargo=sql_general(sql,5).toInt();
			}
			//datos
			QString nombre=itab1->text();
			int horas_mes=QString(itab3->text()).toInt();
			double costo_mes=QString(itab4->text()).toDouble();
			//calculos
			double costo_hora=costo_mes/horas_mes;
			sql=QString("UPDATE actividades_trabajo	SET nombre='%1', hora_mensual=%2, costo_mes=%3, costo_hora=%4, " 
				"id_cargo_cargo=%5 WHERE id_actividad=%6").arg(nombre).arg(horas_mes).arg(costo_mes).arg(costo_hora).arg(id_cargo).arg(id_actividad);
			insertarsql(sql);
			cargaridactividades();
			sql="SELECT b.nombre, a.nombre AS nombre_cargo, b.hora_mensual, b.costo_mes, b.costo_hora FROM cargo AS a,actividades_trabajo AS b WHERE a.id_cargo=b.id_cargo_cargo ORDER BY a.nombre";
			llenartabla(ui.tableWidget_2,sql);
			comboCargo(ui.tableWidget_2,ui.tableWidget_2->rowCount()-1,1);
		}
		filaEdit=-1;
		comboH=false;
		ui.pushButton_6->setText("Actualizar");
		ui.pushButton_4->setEnabled(true);
		ui.pushButton_3->setEnabled(true);
		ui.menuBar->setEnabled(true);
	}
}
void cosmec::agregarfilaMo(){
	/*const int currentRow =ui.tableWidget_2->rowCount();  
	QTableWidgetItem *itab1 = ui.tableWidget_2->item(currentRow-1,0);
	QTableWidgetItem *itab3 = ui.tableWidget_2->item(currentRow-1,2);
	QTableWidgetItem *itab4 = ui.tableWidget_2->item(currentRow-1,3);
	
	if (((itab1!=0&&itab1->text().isEmpty()==false)&& (itab3!=0&& itab3->text().isEmpty()==false)&& (itab4!=0&& itab4->text().isEmpty()==false))||(currentRow==0)){
		if(currentRow!=0){
			//quitar combobox y poner texto
			QComboBox* anterio=(QComboBox*)ui.tableWidget_2->cellWidget(currentRow-1,1);
			QString sql;
			//datos
			int fila=anterio->currentIndex();
			int id_cargo=idcargo[fila];
			QString nombre=itab1->text();
			int horas_mes=QString(itab3->text()).toInt();
			double costo_mes=QString(itab4->text()).toDouble();
			//calculos
			double costo_hora=costo_mes/horas_mes;
			sql=QString("INSERT INTO actividades_trabajo(nombre, hora_mensual, costo_mes, costo_hora, id_cargo_cargo) VALUES ('%1',%2,%3,%4,%5)").arg(nombre).arg(horas_mes).arg(costo_mes).arg(costo_hora).arg(id_cargo);
			insertarsql(sql);
			cargaridactividades();
			sql="SELECT b.nombre, a.nombre AS nombre_cargo, b.hora_mensual, b.costo_mes, b.costo_hora FROM cargo AS a,actividades_trabajo AS b WHERE a.id_cargo=b.id_cargo_cargo ORDER BY a.nombre";
			llenartabla(ui.tableWidget_2,sql);
			comboCargo(ui.tableWidget_2,ui.tableWidget_2->rowCount()-1,1);
		}else{
			QMessageBox msgBox;
			msgBox.setText("Error: Un dato esta vacio");
			msgBox.exec();
		}
	}else{
		ui.tableWidget_2->insertRow(currentRow);
		comboCargo(ui.tableWidget_2,ui.tableWidget_2->rowCount()-1,1);
	}*/
	limpiarFActTrab();
	
	fActTrab->ui.pushButton_2->setVisible(false); //guardar
	fActTrab->ui.pushButton->setVisible(true); //crear
	//llenar combo cargo
	QString sql="SELECT a.id_cargo,a.nombre FROM cargo AS a ORDER BY a.nombre";
	llenarcombocargo(sql,fActTrab->ui.comboBox);
	
	fActTrab->show();

}
void cosmec::nuevaActTrab(){
	QString sql;
	//datos
	int fila=fActTrab->ui.comboBox->currentIndex();
	int id_cargo=idcargo[fila];
	QString nombre=fActTrab->ui.lineEdit_2->text();
	int horas_mes=fActTrab->ui.spinBox->value();
	double costo_mes=fActTrab->ui.doubleSpinBox->value();
	if(id_cargo!=0 && horas_mes!=0 && nombre!="" && costo_mes!=0){
		//calculos
		double costo_hora=costo_mes/horas_mes;
		sql=QString("INSERT INTO actividades_trabajo(nombre, hora_mensual, costo_mes, costo_hora, id_cargo_cargo) VALUES ('%1',%2,%3,%4,%5)").arg(nombre).arg(horas_mes).arg(costo_mes).arg(costo_hora).arg(id_cargo);
		insertarsql(sql);
		cargaridactividades();
		sql="SELECT b.nombre, a.nombre AS nombre_cargo, b.hora_mensual, b.costo_mes, b.costo_hora FROM cargo AS a,actividades_trabajo AS b WHERE a.id_cargo=b.id_cargo_cargo ORDER BY a.nombre";
		llenartabla(ui.tableWidget_2,sql);

		limpiarFActTrab();
		fActTrab->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}	
}
void cosmec::editarActTrab(){
	limpiarFActTrab();
	fActTrab->ui.pushButton_2->setVisible(true); //guardar
	fActTrab->ui.pushButton->setVisible(false); //crear

	int filh=ui.tableWidget_2->currentRow();
	if((filh!=ui.tableWidget_2->rowCount()-1)&&(filh>=0)){
		QTableWidgetItem *itab1 = ui.tableWidget_2->item(filh,0);
		QTableWidgetItem *itab2 = ui.tableWidget_2->item(filh,1);
		QTableWidgetItem *itab3 = ui.tableWidget_2->item(filh,2);
		QTableWidgetItem *itab5 = ui.tableWidget_2->item(filh,4);
		QTableWidgetItem *itab4 = ui.tableWidget_2->item(filh,3);
		
		QString id=QString::number(idactividades[filh]);
		QString nombre=itab1->text();
		QString	cargo=itab2->text();
		QString	horas_mes=itab3->text();
		QString	costo_actividad=itab4->text();
		QString	costo_hora=itab5->text();

		fActTrab->ui.lineEdit->setText(id);
		fActTrab->ui.lineEdit_2->setText(nombre);
		fActTrab->ui.lineEdit_3->setText(costo_hora);
		fActTrab->ui.lineEdit_5->setText(cargo);
		fActTrab->ui.spinBox->setValue(QString(horas_mes).toInt());
		fActTrab->ui.doubleSpinBox->setValue(QString(costo_actividad).toDouble());
		
		//llenar combo cargo
		QString sql="SELECT a.id_cargo,a.nombre FROM cargo AS a ORDER BY a.nombre";
		llenarcombocargo(sql,fActTrab->ui.comboBox);
		int tam=fActTrab->ui.comboBox->count();
		sql=QString("SELECT * FROM actividades_trabajo WHERE id_actividad=%1").arg(id);
		int id_bus=sql_general(sql,5).toInt();
		int index=buscarid(idcargo,id_bus,tam);
		
		fActTrab->ui.comboBox->setCurrentIndex(index);
		fActTrab->show();

	}
	else{
		QMessageBox msgBox;
		msgBox.setText("Seleccione un registro!");
		msgBox.exec();
	}
}
void cosmec::updateActTrab(){
	QString sql;
	//datos
	int id_actividad=QString(fActTrab->ui.lineEdit->text()).toInt();
	int fila=fActTrab->ui.comboBox->currentIndex();
	int id_cargo=idcargo[fila];
	QString nombre=fActTrab->ui.lineEdit_2->text();
	int horas_mes=fActTrab->ui.spinBox->value();
	double costo_mes=fActTrab->ui.doubleSpinBox->value();
	if(id_cargo!=0 && horas_mes!=0 && nombre!="" && costo_mes!=0){
		//calculos
		double costo_hora=costo_mes/horas_mes;
		sql=QString("UPDATE actividades_trabajo	SET nombre='%1', hora_mensual=%2, costo_mes=%3, costo_hora=%4, " 
			"id_cargo_cargo=%5 WHERE id_actividad=%6").arg(nombre).arg(horas_mes).arg(costo_mes).arg(costo_hora).arg(id_cargo).arg(id_actividad);
		insertarsql(sql);
		cargaridactividades();
		sql="SELECT b.nombre, a.nombre AS nombre_cargo, b.hora_mensual, b.costo_mes, b.costo_hora FROM cargo AS a,actividades_trabajo AS b WHERE a.id_cargo=b.id_cargo_cargo ORDER BY a.nombre";
		llenartabla(ui.tableWidget_2,sql);

		limpiarFActTrab();
		fActTrab->close();
	}else{
		QMessageBox msgBox;
		msgBox.setText("Todos los campos deben llenarse y los valores deben ser mayores a 0");
		msgBox.exec();
	}	
}
//cambiar de widget en stack
void cosmec::setgenerador(){
	limpiarRep();
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	respuesta.exec("SELECT a.serie, a.modelo,a.cod_espe FROM maquinas AS a ORDER BY a.modelo");
	tamquery1=respuesta.size();
	idquery1=new int[tamquery1];
	int b=0;
	while(respuesta.next()){
		idquery1[b]=respuesta.value(0).toInt();
		ui.combobasicos->addItem(respuesta.value(1).toString()+"("+respuesta.value(2).toString()+")");
		ui.comboconsuibles->addItem(respuesta.value(1).toString()+"("+respuesta.value(2).toString()+")");
		ui.comboherramientas->addItem(respuesta.value(1).toString()+"("+respuesta.value(2).toString()+")");
		ui.combomanoobra->addItem(respuesta.value(1).toString()+"("+respuesta.value(2).toString()+")");
		ui.combomaqmantenimiento->addItem(respuesta.value(1).toString()+"("+respuesta.value(2).toString()+")");
		b++;
	}

	respuesta.exec("SELECT a.id_cargo, a.nombre FROM cargo AS a");
	tamquery2=respuesta.size();
	idquery2=new int[tamquery2];
	b=0;
	while(respuesta.next()){
		idquery2[b]=respuesta.value(0).toInt();
		ui.comboactividades->addItem(respuesta.value(1).toString());
		b++;
	}
	cosmecdb.close();
	ui.stackedWidget->setCurrentIndex(9);
}
void cosmec::setreporteexel(){
	limpiarExcel();
	//llenar combobox maquinas
	QString sql="SELECT a.serie,a.modelo,a.cod_espe FROM maquinas AS a ORDER BY a.modelo";
	llenarcombomaq(sql,ui.comboBox_4);
	llenarcombomaq(sql,ui.comboBox_7);
	llenarcombomaq(sql,ui.comboBox_12);
	llenarcombomaq(sql,ui.comboBox_8);
	llenarcombomaq(sql,ui.comboBox_10);
	//llenar combo cargo
	sql="SELECT a.id_cargo,a.nombre FROM cargo AS a ORDER BY a.nombre";
	llenarcombocargo(sql,ui.comboBox_9);

	ui.stackedWidget->setCurrentIndex(10);
}
void cosmec::setconfig(){
	ui.stackedWidget->setCurrentIndex(8);
}

void cosmec::setServiciosExternos(){
	QString sql="SELECT id_servicios, nombre_srevicio, costo_hora FROM servicios_externos";
	llenartabla(ui.tableWidget_15,sql);
	llenartabla(ui.tableWidget_15,sql);
	ui.stackedWidget->setCurrentIndex(16);
}
void cosmec::setmaquina(){
	fmaquina->ui.lineEdit_7->setVisible(false);//labels y lineEdit de consumo de agua etc etc
	fmaquina->ui.lineEdit_8->setVisible(false);
	fmaquina->ui.lineEdit_9->setVisible(false);
	fmaquina->ui.lineEdit_4->setVisible(false);
	fmaquina->ui.lineEdit_6->setVisible(false);
	fmaquina->ui.label_12->setVisible(false);
	fmaquina->ui.label_13->setVisible(false);
	fmaquina->ui.label_14->setVisible(false);
	fmaquina->ui.label_15->setVisible(false);
	fmaquina->ui.label_16->setVisible(false);
	QImage imagen;
	fmaquina->ui.label_11->setPixmap(QPixmap::fromImage(imagen));
	QString sql="SELECT a.serie,a.cod_espe,a.modelo,a.costo,a.vida_util,a.horas_trabajo_anual,a.deprecicacion,a.costo_hora,a.presupuesto_anual FROM maquinas AS a";
	llenartabla(ui.tableWidget_3,sql);
	ui.stackedWidget->setCurrentIndex(1);
}
void cosmec::setherramienta(){
	fherr->ui.comboBox->setVisible(true);
	QString sql="SELECT a.id_herramienta,a.nombre_herramienta,a.cantidad_anual,a.costo_unitario,a.vida_util,a.depreciacion,a.costo_hora,b.modelo||' ('||b.cod_espe||')' FROM maquinas AS b,herramientas AS a WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
	llenartabla(ui.tableWidget_4,sql);
	ui.stackedWidget->setCurrentIndex(2);
}
void cosmec::setconsumible(){
	fcons->ui.comboBox->setVisible(true);
	QString sql="SELECT a.id_consumible,a.nombre_consumible,a.costo_unitario,b.modelo||' ('||b.cod_espe||')',a.aplicacion FROM maquinas AS b,consumible AS a WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
	llenartabla(ui.tableWidget_5,sql);
	ui.stackedWidget->setCurrentIndex(3);
}
void cosmec::setenergia(){
	fser->ui.comboBox->setVisible(true);
	QString sql="SELECT a.nombre_servi, a.tipo_consum, a.unidad, a.consumo_serv, a.consumo_hora, "
		"a.costo_consu, a.costo_hora, b.modelo||' ('||b.cod_espe||')' FROM serv_basico AS a, maquinas AS b WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
	cargaridenergia();
	llenartabla(ui.tableWidget_6,sql);
	llenartabla(ui.tableWidget_6,sql);
	ui.stackedWidget->setCurrentIndex(5);
}
void cosmec::setmantenimiento(){
	finsumo->ui.comboBox->setVisible(true);
	QString sql="SELECT a.nombre, a.costo_unitario, a.cantidad_anual, "
		"a.valor_total, a.costo_hora, b.modelo||' ('||b.cod_espe||')' FROM mantenimiento_preventivo AS a,maquinas AS b WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
	llenartabla(ui.tableWidget_7,sql);
	llenartabla(ui.tableWidget_7,sql);
	cargaridinsumo();
	
	sql="SELECT SUM(a.costo_hora) AS suma_prev, b.presupuesto_anual, round(cast(b.presupuesto_anual/b.horas_trabajo_anual AS numeric),2) AS costo_hora, "
		"round(cast((b.presupuesto_anual/b.horas_trabajo_anual)+(SUM(a.costo_hora)) as numeric),2) AS costo_total, b.modelo FROM mantenimiento_preventivo AS a, "
		"maquinas AS b WHERE a.serie_maquinas=b.serie GROUP BY b.serie ORDER BY b.modelo";
	llenartabla(ui.tableWidget_8,sql);
	llenartabla(ui.tableWidget_8,sql);
	ui.tableWidget_8->removeRow(ui.tableWidget_8->rowCount()-1);
	ui.stackedWidget->setCurrentIndex(6);
}
void cosmec::setmanoobra(){
	fActTrab->ui.comboBox->setVisible(true);
	cargaridactividades();
	QString sql;
	sql="SELECT a.id_cargo,a.nombre,a.salario FROM cargo AS a";
	llenartabla(ui.tableWidget,sql);
	llenartabla(ui.tableWidget,sql);

	//sql="SELECT b.nombre, a.nombre AS nombre_cargo, b.hora_mensual, b.costo_mes, b.costo_hora, d.modelo FROM cargo AS a,actividades_trabajo AS b,mano_obra AS c,maquinas AS d WHERE a.id_cargo=b.id_cargo_cargo AND b.id_actividad=c.id_actividad_actividades_trabajo AND c.serie_maquinas=d.serie";
	sql="SELECT b.nombre, a.nombre AS nombre_cargo, b.hora_mensual, b.costo_mes, b.costo_hora FROM cargo AS a,actividades_trabajo AS b WHERE a.id_cargo=b.id_cargo_cargo ORDER BY a.nombre";
	llenartabla(ui.tableWidget_2,sql);
	llenartabla(ui.tableWidget_2,sql);
	ui.stackedWidget->setCurrentIndex(4);

	if(ui.tableWidget_2->rowCount()!=0){
		comboCargo(ui.tableWidget_2,ui.tableWidget_2->rowCount()-1,1);
	}
}
void cosmec::setactividades(){
	fActEmp->ui.comboBox->setVisible(true);
	QString sql;
	sql="SELECT a.id_categoria_actividades, a.nombre FROM categoria_actividades AS a";
	llenartabla(ui.tableWidget_9,sql);
	llenartabla(ui.tableWidget_9,sql);
	sql="SELECT a.id_actividad, a.nombre, a.costo_hora, b.nombre AS cargo FROM actividades AS a, categoria_actividades AS b WHERE a.id_categoria_actividades_categoria_actividades=b.id_categoria_actividades";
	llenartabla(ui.tableWidget_10,sql);
	llenartabla(ui.tableWidget_10,sql);
	ui.stackedWidget->setCurrentIndex(7);
}
void cosmec::setrptcotizaciones(){
	ui.stackedWidget->setCurrentIndex(17);
}
void cosmec::guardarConfig()
{
	if(ui.pushButton_23->isChecked()){
		ui.pushButton_23->setText("Guardar");
		ui.pushButton_22->setEnabled(false);
		ui.pushButton_24->setEnabled(false);
	}
	else
	{
		ui.pushButton_23->setText("Actualizar");
		ui.pushButton_22->setEnabled(true);
		ui.pushButton_24->setEnabled(true);
	}
}
void cosmec::configurar()
{
	ui.editconfig->setText("Editar");

	if(ui.editconfig->isChecked()){
		ui.editconfig->setText("Guardar");
		ui.ip->setEnabled(true);
		ui.usuario->setEnabled(true);
		ui.passw->setEnabled(true);
		ui.port->setEnabled(true);
		ui.lineEdit_7->setEnabled(true);
	}
	else
	{
		QFile file("in.txt");
		if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
			QMessageBox msgBox;
			msgBox.setText("Error al guardar configuracion de conexion host");
			msgBox.exec();
		}else{
			QTextStream out(&file);
			out << ui.ip->text()<<"\n";
			out << ui.passw->text()<<"\n";
			out << ui.usuario->text()<<"\n";
			out << ui.port->text()<<"\n";
			out << ui.lineEdit_7->text()<<"\n";
			file.close();
			host=ui.ip->text();
			pass2=ui.passw->text();
			puerto=ui.port->text();
			usuario=ui.usuario->text();
			iva=(QString(ui.lineEdit_7->text()).toDouble())/100;
			qDebug()<<iva;
            ui.ip->setEnabled(false);
			ui.usuario->setEnabled(false);
			ui.passw->setEnabled(false);
			ui.port->setEnabled(false);
			ui.lineEdit_7->setEnabled(false);
		}
		
	}
}
void cosmec::conexion(){
	cosmecdb = QSqlDatabase::addDatabase("QPSQL","cosmec");
	if ( !cosmecdb.isValid() ) {
		QMessageBox::warning(0, "Error de Conexion", QObject::tr("No se cargo el controlador de la base de datos."));
	}
	cosmecdb.setHostName(host);
	cosmecdb.setDatabaseName( "cosmec" );
	cosmecdb.setUserName( usuario );
	cosmecdb.setPassword( pass2 );
	cosmecdb.setPort(puerto.toInt());
	if ( !cosmecdb.open() ) {
		QMessageBox::warning( 0,"Error de Conexion", QObject::tr("No se pudo conectar: ")+cosmecdb.lastError().databaseText());
	}

}
void cosmec::reportgenerador(){
	report = new NCReport();
	report->reset(true);
	QString a;
	if(ui.checkherrg->isChecked()){
		report->setReportFile("../reportes/herramienta_general.xml");
		reportesinter(report);
	}
	
	if(ui.checkherr->isChecked()){
		a=QString::number(idquery1[ui.comboherramientas->currentIndex()]);
		report->setReportFile("../reportes/herramienta_maquina.xml");
		report->addParameter("maquina",a);
		reportesinter(report);
	}
	if(ui.checkconsug->isChecked()){
		report->setReportFile("../reportes/consumibles_general.xml");
		reportesinter(report);
	}

	if(ui.checkconsu->isChecked()){
		a=QString::number(idquery1[ui.comboconsuibles->currentIndex()]);
		report->setReportFile("../reportes/consumibles_maquina.xml");
		report->addParameter("maquina",a);
		reportesinter(report);
	}
	if(ui.checkmantg->isChecked()){
		report->setReportFile("../reportes/isumos_general.xml");
		reportesinter(report);
	}

	if(ui.checkmant->isChecked()){
		a=QString::number(idquery1[ui.combomaqmantenimiento->currentIndex()]);
		report->setReportFile("../reportes/isumos_maquina.xml");
		report->addParameter("maquina",a);
		reportesinter(report);
	}
	if(ui.checkmanog->isChecked()){
		report->setReportFile("../reportes/manoobra_general.xml");
		reportesinter(report);
	}

	if(ui.checkmano->isChecked()){
		a=QString::number(idquery1[ui.combomanoobra->currentIndex()]);
		report->setReportFile("../reportes/manoobra_maquina.xml");
		report->addParameter("maquina",a);
		reportesinter(report);
	}
	if(ui.checkactivg->isChecked()){
		report->setReportFile("../reportes/actividades_general.xml");
		reportesinter(report);
	}

	if(ui.checkactiv->isChecked()){
		a=QString::number(idquery2[ui.comboactividades->currentIndex()]);
		report->setReportFile("../reportes/actividades_cargo.xml");
		report->addParameter("cargo",a);
		reportesinter(report);
	}
	if(ui.checkbasg->isChecked()){
		report->setReportFile("../reportes/serviciosgenerales_general.xml");
		reportesinter(report);
	}

	if(ui.checkbas->isChecked()){
		a=QString::number(idquery1[ui.combobasicos->currentIndex()]);
		report->setReportFile("../reportes/serviciosgenerales_maquina.xml");
		report->addParameter("maquina",a);
		reportesinter(report);
	}
	if(ui.checkmaqg->isChecked()){
		report->setReportFile("../reportes/reportmaquina.xml");
		reportesinter(report);
	}
}
void cosmec::reportesinter(NCReport *report){
	pv = new NCReportPreviewWindow();
	report->runReportToPreview();
	if(!report->hasError())
	{
		pv->setReport( report );
		pv->setOutput((NCReportPreviewOutput *)report->output());
		pv->setWindowModality(Qt::ApplicationModal);
		//pv->setAttribute(Qt::WA_DeleteOnClose);
		pv->show();
		report->reset(true);
	}
	else
	{
		QMessageBox::about(0,"Error in Report",	report->lastErrorMsg());
	}
}
void cosmec::llenartabla(QTableWidget *tableNum,QString sql){
	if(tableNum->rowCount()>0){
		borrartabla(tableNum);
		tableNum->insertRow(tableNum->rowCount());
	}

	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	if(!respuesta.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al agregar datos :"+respuesta.lastError().databaseText());
		msgBox.exec();
	}
		record = respuesta.record();
		int forint=record.count();
		tamquery1=respuesta.size();
		int fila=0;
	while(respuesta.next()){
		for(int columna=0;columna<forint;columna++){
			QTableWidgetItem *nuevo=new QTableWidgetItem();
			nuevo->setText(respuesta.value(columna).toString());
			tableNum->setItem(fila,columna,nuevo);
		}
		tableNum->insertRow(tableNum->rowCount());
		fila++;
	}
	cosmecdb.close();
}
void cosmec::insertarsql(QString sql){
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	if(!respuesta.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al agregar datos :"+respuesta.lastError().databaseText());
		msgBox.exec();
	}
	cosmecdb.close();
}
void cosmec::reporteexel(){
	db basedatos;
	PGconn *conn;
	basedatos.inicio(host.toStdString(),puerto.toStdString(),"cosmec",usuario.toStdString(),pass2.toStdString());
	conn=basedatos.conectar();
	if (PQstatus(conn) == CONNECTION_BAD){
		QMessageBox msgBox;
		msgBox.setText("Error al conectar base de datos :"+QString(PQerrorMessage(conn)));
		msgBox.exec();
		
	}else{
		XmlExcel archivo;
		TiXmlDocument doc;
		TiXmlDeclaration * decl;
		TiXmlElement * workbook; 
		TiXmlElement * estilo; 
		TiXmlElement* worksheet;
		TiXmlElement * table;
		TiXmlElement * row;
		TiXmlElement * row1;

		decl=archivo.cabecera();
		workbook=archivo.crear_documento_libro("COSMEC","2013-06-05T15:20:15Z"); //autor, fecha
		estilo=archivo.crear_estilos();
		workbook ->LinkEndChild(estilo);

		if(ui.radioButton_3->isChecked()){ //HERRAMIENTAS GRAL.
			//crea hoja de datos
			worksheet=archivo.crear_hoja("Herramientas"); //Nombre de la hoja
			table=archivo.crear_tabla("199","200"); //dimensiones maxima de la hoja x,y
			//Cabecera de hoja
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Escuela Politecnica del Ejercito","String","2","6","25");
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Departamento de ciencias de la energia y mecanica","String","2","6","15");
			table->LinkEndChild(row);
			row=archivo.salto_linea();
			table->LinkEndChild(row);

			int tam=ui.comboBox_4->count();
			int index;
			char indexChar[20];
			for(int k=0;k<tam;k++){
				index=idmaquinas[k];
				sprintf(indexChar,"%d",index);
				//qDebug()<<index;
				table=tabla_herramientasss(archivo,basedatos,conn,row,table,indexChar);
				row=archivo.salto_linea();
				table->LinkEndChild(row);
			}
			worksheet->LinkEndChild(table);
			workbook ->LinkEndChild(worksheet);	
			//Fin de la hoja de datos
		}
		if(ui.radioButton_4->isChecked()){//HERRAMIENTAS P/MAQ
			//crea hoja de datos
			worksheet=archivo.crear_hoja("Herramientas"); //Nombre de la hoja
			table=archivo.crear_tabla("199","200"); //dimensiones maxima de la hoja x,y
			//Cabecera de hoja
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Escuela Politecnica del Ejercito","String","2","6","25");
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Departamento de ciencias de la energia y mecanica","String","2","6","15");
			table->LinkEndChild(row);
			row=archivo.salto_linea();
			table->LinkEndChild(row);

			char indexChar[20];
			int index=idmaquinas[ui.comboBox_4->currentIndex()];
			sprintf(indexChar,"%d",index);
			table=tabla_herramientasss(archivo,basedatos,conn,row,table,indexChar);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			worksheet->LinkEndChild(table);
			workbook ->LinkEndChild(worksheet);	
			//Fin de la hoja de datos
		}
		if(ui.radioButton_12->isChecked()){//MANO OBRA GRAL
			//hoja2
			worksheet=archivo.crear_hoja("mano de obra"); //Nombre de la hoja
			table=archivo.crear_tabla("199","200"); //dimensiones maxima de la hoja x,y
			//Cabecera de hoja
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Escuela Politecnica del Ejercito","String","2","6","25");
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Departamento de ciencias de la energia y mecanica","String","2","6","15");
			table->LinkEndChild(row);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			//
			int tam=ui.comboBox_8->count();
			int index;
			char indexChar[20];
			for(int k=0;k<tam;k++){
				index=idmaquinas[k];
				sprintf(indexChar,"%d",index);
				table=tabla_herramientasss2(archivo,basedatos,conn,row,table,indexChar);
				row=archivo.salto_linea();
				table->LinkEndChild(row);
			}
			worksheet->LinkEndChild(table);
			workbook ->LinkEndChild(worksheet);	
			//Fin de la hoja de datos
		}
		if(ui.radioButton_6->isChecked()){//MANO OBRA P/MAQ
			//hoja2
			worksheet=archivo.crear_hoja("mano de obra"); //Nombre de la hoja
			table=archivo.crear_tabla("199","200"); //dimensiones maxima de la hoja x,y
			//Cabecera de hoja
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Escuela Politecnica del Ejercito","String","2","6","25");
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Departamento de ciencias de la energia y mecanica","String","2","6","15");
			table->LinkEndChild(row);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			//
			char indexChar[20];
			int index=idmaquinas[ui.comboBox_8->currentIndex()];
			sprintf(indexChar,"%d",index);
			table=tabla_herramientasss2(archivo,basedatos,conn,row,table,indexChar);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			worksheet->LinkEndChild(table);
			workbook ->LinkEndChild(worksheet);	
			//Fin de la hoja de datos
		}
		if(ui.radioButton_10->isChecked()){//CONSUMIBLES GRAL
			//hoja3
			worksheet=archivo.crear_hoja("Consumibles"); //Nombre de la hoja
			table=archivo.crear_tabla("199","200"); //dimensiones maxima de la hoja x,y
			//Cabecera de hoja
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Escuela Politecnica del Ejercito","String","2","6","25");
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Departamento de ciencias de la energia y mecanica","String","2","6","15");
			table->LinkEndChild(row);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			//
			int tam=ui.comboBox_7->count();
			int index;
			char indexChar[20];
			for(int k=0;k<tam;k++){
				index=idmaquinas[k];
				sprintf(indexChar,"%d",index);
				table=tabla_herramientasss3(archivo,basedatos,conn,row,table,indexChar);
				row=archivo.salto_linea();
				table->LinkEndChild(row);
			}
			worksheet->LinkEndChild(table);
			workbook ->LinkEndChild(worksheet);	
			//Fin de la hoja de datos
		}
		if(ui.radioButton_5->isChecked()){//CONSUMIBLES P/MAQ
			//hoja3
			worksheet=archivo.crear_hoja("Consumibles"); //Nombre de la hoja
			table=archivo.crear_tabla("199","200"); //dimensiones maxima de la hoja x,y
			//Cabecera de hoja
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Escuela Politecnica del Ejercito","String","2","6","25");
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Departamento de ciencias de la energia y mecanica","String","2","6","15");
			table->LinkEndChild(row);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			//
			char indexChar[20];
			int index=idmaquinas[ui.comboBox_7->currentIndex()];
			sprintf(indexChar,"%d",index);
			table=tabla_herramientasss3(archivo,basedatos,conn,row,table,indexChar);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			worksheet->LinkEndChild(table);
			workbook ->LinkEndChild(worksheet);	
			//Fin de la hoja de datos
		}
		if(ui.radioButton_13->isChecked()){//ACTIVIDADES GRAL
			//hoja4
			worksheet=archivo.crear_hoja("Actividades"); //Nombre de la hoja
			table=archivo.crear_tabla("199","200"); //dimensiones maxima de la hoja x,y
			//Cabecera de hoja
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Escuela Politecnica del Ejercito","String","2","6","25");
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Departamento de ciencias de la energia y mecanica","String","2","6","15");
			table->LinkEndChild(row);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			//
			int tam=ui.comboBox_9->count();
			int index;
			char indexChar[20];
			for(int k=0;k<tam;k++){
				index=idcargo[k];
				sprintf(indexChar,"%d",index);
				table=tabla_herramientasss4(archivo,basedatos,conn,row,table,indexChar);
				row=archivo.salto_linea();
				table->LinkEndChild(row);
			}
			worksheet->LinkEndChild(table);
			workbook ->LinkEndChild(worksheet);	
			//Fin de la hoja de datos
		}
		if(ui.radioButton_7->isChecked()){//ACTIVIDADES P/CARGO
			//hoja4
			worksheet=archivo.crear_hoja("Actividades"); //Nombre de la hoja
			table=archivo.crear_tabla("199","200"); //dimensiones maxima de la hoja x,y
			//Cabecera de hoja
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Escuela Politecnica del Ejercito","String","2","6","25");
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Departamento de ciencias de la energia y mecanica","String","2","6","15");
			table->LinkEndChild(row);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			//
			char indexChar[20];
			int index=idcargo[ui.comboBox_9->currentIndex()];
			sprintf(indexChar,"%d",index);
			table=tabla_herramientasss4(archivo,basedatos,conn,row,table,indexChar);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			worksheet->LinkEndChild(table);
			workbook ->LinkEndChild(worksheet);	
			//Fin de la hoja de datos
		}
		if(ui.radioButton_11->isChecked()){//MTTO GRAL
			//hoja5
			worksheet=archivo.crear_hoja("Mantenimiento"); //Nombre de la hoja
			table=archivo.crear_tabla("199","200"); //dimensiones maxima de la hoja x,y
			//Cabecera de hoja
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Escuela Politecnica del Ejercito","String","2","6","25");
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Departamento de ciencias de la energia y mecanica","String","2","6","15");
			table->LinkEndChild(row);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			//
			int tam=ui.comboBox_12->count();
			int index;
			char indexChar[20];
			for(int k=0;k<tam;k++){
				index=idmaquinas[k];
				sprintf(indexChar,"%d",index);
				table=tabla_herramientasss5(archivo,basedatos,conn,row,table,indexChar);
				row=archivo.salto_linea();
				table->LinkEndChild(row);
			}
			worksheet->LinkEndChild(table);
			workbook ->LinkEndChild(worksheet);	
			//Fin de la hoja de datos
		}
		if(ui.radioButton_9->isChecked()){//MTTO P/MAQ
			//hoja5
			worksheet=archivo.crear_hoja("Mantenimiento"); //Nombre de la hoja
			table=archivo.crear_tabla("199","200"); //dimensiones maxima de la hoja x,y
			//Cabecera de hoja
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Escuela Politecnica del Ejercito","String","2","6","25");
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Departamento de ciencias de la energia y mecanica","String","2","6","15");
			table->LinkEndChild(row);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			//
			char indexChar[20];
			int index=idmaquinas[ui.comboBox_12->currentIndex()];
			sprintf(indexChar,"%d",index);
			table=tabla_herramientasss5(archivo,basedatos,conn,row,table,indexChar);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			worksheet->LinkEndChild(table);
			workbook ->LinkEndChild(worksheet);	
			//Fin de la hoja de datos
		}
		if(ui.radioButton->isChecked()){//MAQ GRAL
			//hoja6
			worksheet=archivo.crear_hoja("General"); //Nombre de la hoja
			table=archivo.crear_tabla("199","200"); //dimensiones maxima de la hoja x,y
			//Cabecera de hoja
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Escuela Politecnica del Ejercito","String","2","6","25");
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Departamento de ciencias de la energia y mecanica","String","2","6","15");
			table->LinkEndChild(row);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			//
			table=tabla_herramientasss6(archivo,basedatos,conn,row,table,"nada");
			worksheet->LinkEndChild(table);
			workbook ->LinkEndChild(worksheet);	
			//Fin de la hoja de datos
		}
		if(ui.radioButton_14->isChecked()){//SERV BAS GRAL
			//hoja7
			worksheet=archivo.crear_hoja("Servicio Basicos"); //Nombre de la hoja
			table=archivo.crear_tabla("199","200"); //dimensiones maxima de la hoja x,y
			//Cabecera de hoja
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Escuela Politecnica del Ejercito","String","2","6","25");
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Departamento de ciencias de la energia y mecanica","String","2","6","15");
			table->LinkEndChild(row);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			//
			int tam=ui.comboBox_10->count();
			int index;
			char indexChar[20];
			for(int k=0;k<tam;k++){
				index=idmaquinas[k];
				sprintf(indexChar,"%d",index);
				table=tabla_herramientasss7(archivo,basedatos,conn,row,table,indexChar);
				row=archivo.salto_linea();
				table->LinkEndChild(row);
			}
			worksheet->LinkEndChild(table);
			workbook ->LinkEndChild(worksheet);	
			//Fin de la hoja de datos
		}
		if(ui.radioButton_8->isChecked()){//SERV BAS P/MAQ
			//hoja7
			worksheet=archivo.crear_hoja("Servicio Basicos"); //Nombre de la hoja
			table=archivo.crear_tabla("199","200"); //dimensiones maxima de la hoja x,y
			//Cabecera de hoja
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Escuela Politecnica del Ejercito","String","2","6","25");
			table->LinkEndChild(row);
			row=archivo.crear_general_titulo("Departamento de ciencias de la energia y mecanica","String","2","6","15");
			table->LinkEndChild(row);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			//
			char indexChar[20];
			int index=idmaquinas[ui.comboBox_10->currentIndex()];
			sprintf(indexChar,"%d",index);
			table=tabla_herramientasss7(archivo,basedatos,conn,row,table,indexChar);
			row=archivo.salto_linea();
			table->LinkEndChild(row);
			worksheet->LinkEndChild(table);
			workbook ->LinkEndChild(worksheet);	
			//Fin de la hoja de datos
		}

		//Armado del archivo
		doc.LinkEndChild( decl );
		doc.LinkEndChild( workbook );
		//Creacion del xml y visualizacion
		archivo.guardar_archivo(doc,"excel1a.xml");
		archivo.abrir_archivo("excel1a.xml");
	}
}
void cosmec::setactividadesMo(){
	QString sql="SELECT c.id_actividad,c.nombre,a.serie, a.modelo||' ('||a.cod_espe||')' FROM maquinas AS a,mano_obra AS b,actividades_trabajo AS c WHERE c.id_actividad=b.id_actividad_actividades_trabajo AND b.serie_maquinas=a.serie ORDER BY a.modelo";
	llenartabla(ui.tableWidget_13,sql);
	llenartabla(ui.tableWidget_13,sql);
	ui.stackedWidget->setCurrentIndex(15);
	if(ui.tableWidget_13->rowCount()!=0){
		comboActividades(ui.tableWidget_13,ui.tableWidget_13->rowCount()-1,1);
		comboMaq(ui.tableWidget_13,ui.tableWidget_13->rowCount()-1,3);
	}
}
void cosmec::setnuevaCotizacion(){
	modificar=false;
	QString sql;
	sql="SELECT setval('cotizacion_numero_seq',(SELECT nextval('cotizacion_numero_seq'))-1)";
	numerocoti=sql_general(sql,0).toInt()+1;
	ui.label_27->setText(QString::number(numerocoti));
	//llenar combo de máquinas combo
	ui.comboBox_5->clear();
	ui.comboBox_6->clear();
	ui.comboBox->clear();
	ui.comboBox_11->clear();
	ui.comboBox_13->clear();
	ui.tableWidget_12->clearContents();
	ui.tableWidget_24->clearContents();
	borrartabla(ui.tableWidget_12);
	borrartabla(ui.tableWidget_24);
	ui.doubleSpinBox->setValue(0);
	ui.doubleSpinBox_2->setValue(0);
	ui.doubleSpinBox_2->setValue(0);
	ui.doubleSpinBox_5->setValue(0);
	ui.doubleSpinBox_7->setValue(0);
	ui.lineEdit->clear();
	ui.lineEdit_2->clear();
	ui.lineEdit_3->clear();
	ui.lineEdit_4->clear();
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	respuesta.exec("SELECT a.serie, a.modelo, a.cod_espe FROM maquinas AS a ORDER BY a.modelo");
	tamquery1=respuesta.size();
	idmaquinas=new int[tamquery1];
	int b=0;
	while(respuesta.next()){
		idmaquinas[b]=respuesta.value(0).toInt();
		ui.comboBox_5->addItem(respuesta.value(1).toString()+"("+respuesta.value(2).toString()+")");
		b++;
	}
	cosmecdb.close();

	cosmecdb.open();
	respuesta.exec(QString("SELECT a.id_actividad, a.nombre FROM actividades AS a ORDER BY a.nombre"));
	tamquery1=respuesta.size();
	qDebug()<<tamquery1;
	idactividades=new int[tamquery1];
	b=0;
	while(respuesta.next()){
		idactividades[b]=respuesta.value(0).toInt();
		ui.comboBox_11->addItem(respuesta.value(1).toString());
		b++;
	}
	cosmecdb.close();
	
	cosmecdb.open();
	respuesta.exec(QString("SELECT a.id_material, a.nombre||' ('||a.geometria||'-'||a.dimencion||')' As nombre FROM materiales AS a ORDER BY a.nombre"));
	tamquery2=respuesta.size();
	idmaterial=new int[tamquery2];
	b=0;
	while(respuesta.next()){
		idmaterial[b]=respuesta.value(0).toInt();
		ui.comboBox->addItem(respuesta.value(1).toString());
		b++;
	}
	cosmecdb.close();

	cosmecdb.open();
	respuesta.exec(QString("SELECT id_servicios, nombre_srevicio FROM servicios_externos"));
	tamquery2=respuesta.size();
	idserv=new int[tamquery2];
	b=0;
	while(respuesta.next()){
		idserv[b]=respuesta.value(0).toInt();
		ui.comboBox_6->addItem(respuesta.value(1).toString());
		b++;
	}
	cosmecdb.close();
	ui.stackedWidget->setCurrentIndex(11);
}
void cosmec::setbuscarCotizacion(){
	borrartabla(ui.tableWidget_24);
	borrartabla(ui.tableWidget_11);
	ui.lineEdit_5->clear();
	ui.lineEdit_6->clear();
	ui.lineEdit_23->clear();
	ui.lineEdit_21->clear();

	ui.radioButton_c->setCheckable(false);
	ui.radioButton_c->update();
	ui.radioButton_c->setCheckable(true);

	ui.radioButton_2->setCheckable(false);
	ui.radioButton_2->update();
	ui.radioButton_2->setCheckable(true);

	ui.radioButton_15->setCheckable(false);
	ui.radioButton_15->update();
	ui.radioButton_15->setCheckable(true);

	ui.radioButton_16->setCheckable(false);
	ui.radioButton_16->update();
	ui.radioButton_16->setCheckable(true);

	ui.stackedWidget->setCurrentIndex(12);
}
void cosmec::setmateriales(){
	QString sql="SELECT id_material, nombre, geometria,unidades, dimencion, costo, aplicacion"
		" FROM materiales";
	llenartabla(ui.tableWidget_14,sql);
	llenartabla(ui.tableWidget_14,sql);
	ui.stackedWidget->setCurrentIndex(14);
}

//actividades - maquina
void cosmec::agregarfilaMaqActividades(){
	const int currentRow =ui.tableWidget_13->rowCount();  
	if(currentRow!=0){
			QString sql;
			//quitar combobox y poner texto
			QComboBox* anterio=(QComboBox*)ui.tableWidget_13->cellWidget(currentRow-1,1);
			int fila=anterio->currentIndex();
			qDebug()<<fila;
			int idnoce=idact[fila];
			qDebug()<<idact[2];
			QComboBox* anterio2=(QComboBox*)ui.tableWidget_13->cellWidget(currentRow-1,3);
			int id_maquina=idmaquinas[anterio2->currentIndex()];
			qDebug()<<id_maquina;
			sql=QString("INSERT INTO mano_obra(serie_maquinas, id_actividad_actividades_trabajo)"
				"VALUES (%1,%2)").arg(id_maquina).arg(idnoce);
			insertarsql(sql);
			sql="SELECT c.id_actividad,c.nombre,a.serie, a.modelo FROM maquinas AS a,mano_obra AS b,actividades_trabajo AS c WHERE c.id_actividad=b.id_actividad_actividades_trabajo AND b.serie_maquinas=a.serie ORDER BY a.modelo";
			llenartabla(ui.tableWidget_13,sql);
			if(ui.tableWidget_13->rowCount()!=0){
				comboActividades(ui.tableWidget_13,ui.tableWidget_13->rowCount()-1,1);
				comboMaq(ui.tableWidget_13,ui.tableWidget_13->rowCount()-1,3);
			}
	}else{
		ui.tableWidget_13->insertRow(currentRow);
		comboActividades(ui.tableWidget_13,ui.tableWidget_13->rowCount()-1,0);
		comboMaq(ui.tableWidget_13,ui.tableWidget_13->rowCount()-1,1);
	}
}
//void cosmec::actualizarMaqActividades(){
//	if(ui.pushButton_40->isChecked()){
//		ui.pushButton_40->setText("Guardar");
//		ui.pushButton_39->setEnabled(false);
//		ui.pushButton_38->setEnabled(false);
//		ui.menuBar->setEnabled(false);
//	}
//	else
//	{
//		if(comboH){
//			QComboBox* anterio=(QComboBox*)ui.tableWidget_13->cellWidget(filaEdit,1);
//			QString tAnterior=anterio->currentText();
//			ui.tableWidget_13->removeCellWidget(filaEdit,1);
//			QTableWidgetItem *itemA = new QTableWidgetItem;
//			itemA->setText(tAnterior);
//			ui.tableWidget_13->setItem(filaEdit,1,itemA);
//		}
//		if(comboG){
//			QComboBox* anterio=(QComboBox*)ui.tableWidget_13->cellWidget(filaEdit,3);
//			QString tAnterior=anterio->currentText();
//			ui.tableWidget_13->removeCellWidget(filaEdit,3);
//			QTableWidgetItem *itemA = new QTableWidgetItem;
//			itemA->setText(tAnterior);
//			ui.tableWidget_13->setItem(filaEdit,3,itemA);
//		}
//		filaEdit=-1;
//		comboH=false;
//		comboG=false;
//		ui.pushButton_40->setText("Actualizar");
//		ui.pushButton_39->setEnabled(true);
//		ui.pushButton_38->setEnabled(true);
//		ui.menuBar->setEnabled(true);
//	}
//}
void cosmec::eliminarFilaMaqActividades(){
	int currentRow=ui.tableWidget_13->currentRow();
	QString sql;
	QTableWidgetItem *itab1 = ui.tableWidget_13->item(currentRow,0);
	QTableWidgetItem *itab3 = ui.tableWidget_13->item(currentRow,2);
	if(currentRow==-1||(currentRow==ui.tableWidget_13->rowCount()-1)){
		QMessageBox msgBox;
		msgBox.setText("No hay fila seleccionada");
		msgBox.exec();
	}else{
		int id_actividad=QString(itab1->text()).toInt();
		int id_maquina=QString(itab3->text()).toInt();
		sql=QString("DELETE FROM mano_obra WHERE serie_maquinas=%1 AND id_actividad_actividades_trabajo=%2").arg(id_maquina).arg(id_actividad);
		insertarsql(sql);
		QString sql="SELECT c.id_actividad,c.nombre,a.serie, a.modelo FROM maquinas AS a,mano_obra AS b,actividades_trabajo AS c WHERE c.id_actividad=b.id_actividad_actividades_trabajo AND b.serie_maquinas=a.serie ORDER BY a.modelo";
		llenartabla(ui.tableWidget_13,sql);
		if(ui.tableWidget_13->rowCount()!=0){
			comboActividades(ui.tableWidget_13,ui.tableWidget_13->rowCount()-1,1);
			comboMaq(ui.tableWidget_13,ui.tableWidget_13->rowCount()-1,3);
		}
	}
	
}
//void cosmec::filaEditableMaqActividades(int row,int column){
//	bool actChecked=ui.pushButton_40->isChecked();
//	bool ultF= (row+1)==ui.tableWidget_13->rowCount();
//
//	if(actChecked&&filaEdit==-1){
//		filaEdit=row;
//	}
//
//	if((actChecked&&filaEdit==row)||(ultF&&!actChecked)){
//		if(actChecked&&column==1)
//		{
//			comboH=true;
//			comboActividades(ui.tableWidget_13,row,1);
//		}
//		if(actChecked&&column==3)
//		{
//			comboG=true;
//			comboMaq(ui.tableWidget_13,row,3);
//		}
//		ui.tableWidget_13->setEditTriggers(QAbstractItemView::DoubleClicked);
//	}
//	else{
//		if(actChecked&&filaEdit!=row){
//			QMessageBox msgBox;
//			msgBox.setText("Solo puede editar una fila a la vez");
//			msgBox.exec();
//		}
//		ui.tableWidget_13->setEditTriggers(QAbstractItemView::NoEditTriggers);
//	}
//}
//

//buscar cotización
void cosmec::habilitarBuscarRuc(){
	ui.lineEdit_5->setEnabled(false);
	ui.lineEdit_6->setEnabled(true);
	ui.lineEdit_21->setEnabled(false);
	ui.lineEdit_23->setEnabled(false);
	//qDebug()<<"habilita ruc";
}
void cosmec::habilitarBuscarCotizacion(){
	ui.lineEdit_5->setEnabled(true);
	ui.lineEdit_6->setEnabled(false);
	ui.lineEdit_21->setEnabled(false);
	ui.lineEdit_23->setEnabled(false);
	//qDebug()<<"habilita cotizacion";
}
void cosmec::habilitarBuscarProyecto(){
	ui.lineEdit_5->setEnabled(false);
	ui.lineEdit_6->setEnabled(false);
	ui.lineEdit_21->setEnabled(true);
	ui.lineEdit_23->setEnabled(false);
}
void cosmec::habilitarBuscarFecha(){
	ui.lineEdit_5->setEnabled(false);
	ui.lineEdit_6->setEnabled(false);
	ui.lineEdit_21->setEnabled(false);
	ui.lineEdit_23->setEnabled(true);
}
void cosmec::buscarCotizacion(){//llenar tabla de cotizaciones encontradas con ese valor de RUC o # cotizacion
	QString sql;
	//cosmecdb.open()
	//QSqlQuery aux(cosmecdb);
	if(ui.radioButton_c->isChecked() || ui.radioButton_2->isChecked() || ui.radioButton_15->isChecked()||ui.radioButton_16->isChecked()){
		if(ui.radioButton_c->isChecked()){
			sql=QString("SELECT a.numero,a.nombre,a.ruc,a.subtotal_cotizacion,b.nombre FROM cotizacion AS a, usuarios AS b WHERE b.id_usuario=a.id_usuario_usuarios AND a.nombre='%1'").arg(ui.lineEdit_5->text());
			llenartabla(ui.tableWidget_11,sql);
			llenartabla(ui.tableWidget_11,sql);
			ui.tableWidget_11->removeRow(ui.tableWidget_11->rowCount()-1);
		}
		if(ui.radioButton_2->isChecked()){
			sql=QString("SELECT a.numero,a.nombre,a.ruc,a.subtotal_cotizacion,b.nombre FROM cotizacion AS a, usuarios AS b WHERE b.id_usuario=a.id_usuario_usuarios AND a.ruc=%1").arg(ui.lineEdit_6->text());
			llenartabla(ui.tableWidget_11,sql);
			llenartabla(ui.tableWidget_11,sql);
			ui.tableWidget_11->removeRow(ui.tableWidget_11->rowCount()-1);
		}
		if(ui.radioButton_15->isChecked()){
			sql=QString("SELECT a.numero,a.nombre,a.ruc,a.subtotal_cotizacion,b.nombre FROM cotizacion AS a, usuarios AS b WHERE b.id_usuario=a.id_usuario_usuarios AND a.proyecto='%1'").arg(ui.lineEdit_21->text());
			llenartabla(ui.tableWidget_11,sql);
			llenartabla(ui.tableWidget_11,sql);
			ui.tableWidget_11->removeRow(ui.tableWidget_11->rowCount()-1);
		}
		if(ui.radioButton_16->isChecked()){
			sql=QString("SELECT a.numero,a.nombre,a.ruc,a.subtotal_cotizacion,b.nombre FROM cotizacion AS a, usuarios AS b WHERE b.id_usuario=a.id_usuario_usuarios AND a.fecha='%1'").arg(ui.lineEdit_23->text());
			llenartabla(ui.tableWidget_11,sql);
			llenartabla(ui.tableWidget_11,sql);
			ui.tableWidget_11->removeRow(ui.tableWidget_11->rowCount()-1);
		}
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("Escoja un parámetro de búsqueda");
		msgBox.exec();
	}
}
void cosmec::resultadoCotizacion(){
	QString sql;
	int currentRow=ui.tableWidget_11->currentRow();
	QTableWidgetItem *itab1 = ui.tableWidget_11->item(currentRow,0);
	if(currentRow==-1){
		QMessageBox msgBox;
		msgBox.setText("Debe elegir una cotización");
		msgBox.exec();
	}
	else{
		numerocoti=QString(itab1->text()).toInt();
		sql=QString("SELECT descuento, piezas FROM cotizacion WHERE numero=%1").arg(numerocoti);
		int piezas=sql_general(sql,1).toInt();
		double descuento=sql_general(sql,0).toDouble();
		double subtotal=calcularcotizacion(numerocoti);
		ui.lineEdit_18->setText(QString::number(piezas));
		ui.lineEdit_19->setText(QString::number(descuento));
		ui.lineEdit_27->setText(QString::number(subtotal));
		double aux=piezas*subtotal*(1-(descuento/100));
		ui.lineEdit_20->setText(QString::number(aux));
		ui.lineEdit_30->setText(QString::number(redondear(iva*aux)));
		ui.lineEdit_29->setText(QString::number(redondear((1+iva)*aux)));
		ui.pushButton_35->setVisible(true);
		ui.stackedWidget->setCurrentIndex(13);

	}
}
void cosmec::imprimirCotizacion()
{
	//preview de cotización
	report = new NCReport();
	report->reset(true);
	report->setReportFile("../reportes/cotizacion2.xml");
	report->addParameter("numerop",numerocoti);
	QString filename=QFileDialog::getSaveFileName(this,tr("Guardar Archivo PDF"),QString("Cotizacion_%1.pdf").arg(numerocoti),
		tr("Pdf file (*.pdf)"));
    report->runReportToPDF(filename);
	//report->runReportToPrinter(1,true,this);
	//reportesinter(report);
}
void cosmec::detalle(){
	dialogDetalle *pop=new dialogDetalle();
	//pop->ui.label->setText("nathy");
	int currentRow=ui.tableWidget_24->currentRow();
	double mano_total=0;
	QString dato1;
	QString dato2;
	QString dato3;
	QString dato4;
	QString dato5;
	QString sql;
	bool flag=false;
	if(currentRow==-1){
		QMessageBox msgBox;
		msgBox.setText("No hay fila seleccionada");
		msgBox.exec();
	}else{
		QTableWidgetItem *itab1 = ui.tableWidget_24->item(currentRow,0);
		QTableWidgetItem *itab2 = ui.tableWidget_24->item(currentRow,1);
		double aux=QString(itab1->text()).toDouble();
		int indice=(int)aux;
		double val=aux-indice;
		int fila=0;
		int ind=1;
		qDebug()<<val;
		if(val==0 && (itab2->text()!="Actividades" && itab2->text()!="Servicios Extras")){
			flag=true;
			int serie=idmaquinacot[indice-1];	
			sql=QString("SELECT SUM(costo_hora) FROM herramientas WHERE serie_maquinas=%1 GROUP BY serie_maquinas").arg(serie);
			double valor_herra=sql_general(sql,0).toDouble();
			
			dato1=QString::number(ind);
			dato2="Herramientas";
			dato3=QString::number(redondear(valor_herra));
			pop->tablaDetalle(fila,dato1,dato2,dato3);
			fila++;
			ind++;

			sql=QString("SELECT SUM(costo_hora) FROM consumible WHERE serie_maquinas=%1 GROUP BY serie_maquinas").arg(serie);
			double valor_consu=sql_general(sql,0).toDouble();
			
			dato1=QString::number(ind);
			dato2="Consumibles";
			dato3=QString::number(redondear(valor_consu));
			pop->tablaDetalle(fila,dato1,dato2,dato3);
			fila++;
			ind++;

			sql=QString("SELECT SUM(costo_hora) FROM serv_basico WHERE serie_maquinas=%1").arg(serie);
			double servicios=sql_general(sql,0).toDouble();
			
			dato1=QString::number(ind);
			dato2="Servicios Basicos";
			dato3=QString::number(redondear(servicios));
			pop->tablaDetalle(fila,dato1,dato2,dato3);
			fila++;
			ind++;

			sql=QString("SELECT (b.presupuesto_anual/b.horas_trabajo_anual)+(SUM(a.costo_hora)) AS costo_total "
				"FROM mantenimiento_preventivo AS a,maquinas AS b WHERE a.serie_maquinas=b.serie AND b.serie=%1 GROUP BY b.serie").arg(serie);
			double manteni=sql_general(sql,0).toDouble();
			
			dato1=QString::number(ind);
			dato2="Mantenimiento";
			dato3=QString::number(redondear(manteni));
			pop->tablaDetalle(fila,dato1,dato2,dato3);
			fila++;
			ind++;

			sql=QString("SELECT ((2*costo)/(vida_util*horas_trabajo_anual)) FROM maquinas WHERE serie=%1").arg(serie);
			double costomaqui=sql_general(sql,0).toDouble();
			
			double maquina=(valor_herra+valor_consu+servicios+manteni+costomaqui);
			
			dato1=QString::number(ind);
			dato2="Costo maquina y depreciacion ";
			dato3=QString::number(redondear(costomaqui));
			pop->tablaDetalle(fila,dato1,dato2,dato3);
			fila++;
			ind++;

			dato1="";
			dato2="Costo hora total";
			dato3=QString::number(redondear(maquina));
			pop->tablaDetalle(fila,dato1,dato2,dato3);
			fila++;
			ind++;

			dato1="";
			dato2="Precio total "+QString::number(vcomp*100)+"%";
			dato3=QString::number(redondear(maquina*(1+vcomp)));
			pop->tablaDetalle(fila,dato1,dato2,dato3);
			fila++;
			ind++;
		}
		if(QString::number(val)=="0.1" && itab2->text()=="Mano de obra"){
			flag=true;
			cosmecdb.open();
			QSqlQuery respuesta(cosmecdb);
			QString sql=QString("SELECT c.nombre, c.costo_mes FROM maquinas AS a, mano_obra AS b, actividades_trabajo AS c,cotizacion_manoobra AS d WHERE d.serie_maquina=a.serie AND d.numero_cotizacion=%1 AND a.serie=b.serie_maquinas AND b.id_actividad_actividades_trabajo=c.id_actividad AND a.serie=%2").arg(numerocoti).arg(idmaquinacot[indice-1]);
			if(!respuesta.exec(sql)){
				QMessageBox msgBox;
				msgBox.setText("Error al agregar datos :"+respuesta.lastError().databaseText());
				msgBox.exec();
			}
			while(respuesta.next()){
				dato1=QString::number(ind);
				dato2=respuesta.value(0).toString();
				dato3=respuesta.value(1).toString();
				pop->tablaDetalle(fila,dato1,dato2,dato3);
				double man=respuesta.value(1).toDouble();
				mano_total=mano_total+man;
				fila++;
				ind++;
			}

			dato1="";
			dato2="Costo total";
			dato3=QString::number(redondear(mano_total));
			pop->tablaDetalle(fila,dato1,dato2,dato3);
			fila++;
			ind++;
			
			dato1="";
			dato2="Costo hora";
			dato3=QString::number(redondear(mano_total/160));
			pop->tablaDetalle(fila,dato1,dato2,dato3);
			fila++;
			ind++;

			dato1="";
			dato2="Precio total "+QString::number(vcomp*100)+"%";
			dato3=QString::number(redondear((mano_total/160)*(1+vcomp)));
			pop->tablaDetalle(fila,dato1,dato2,dato3);
			fila++;
			ind++;
		}
		//pop->tablaDetalle();//funcion para llenar la tabla. modificar con los parámtros que necesites
		if(flag){
			pop->show();
		}else{
			QMessageBox msgBox;
			msgBox.setText("Sin opción de búsqueda");
			msgBox.exec();
		}
	}
}

//nueva cotización
void cosmec::sumarHerramienta(){
	/*QString herramienta=ui.comboBox_2->currentText();
	QString maq=ui.comboBox_3->currentText();
	int cantH=ui.spinBox->value();
	
	if(cantH!=0){
		ui.tableWidget_12->insertRow(ui.tableWidget_12->rowCount());
		
		QTableWidgetItem *itemMaquina = new QTableWidgetItem;
		QTableWidgetItem *itemDesc = new QTableWidgetItem;
		QTableWidgetItem *itemCate = new QTableWidgetItem;
		QTableWidgetItem *itemcant = new QTableWidgetItem;
		QTableWidgetItem *itemIdMaq = new QTableWidgetItem;
		QTableWidgetItem *itemIdDesc = new QTableWidgetItem;

		itemMaquina->setText(maq);
		itemDesc->setText(herramienta);
		itemCate->setText("Herramienta");
		itemcant->setText(QString::number(cantH));
		itemIdMaq->setText(QString::number(idmaquinas[ui.comboBox_3->currentIndex()]));
		itemIdDesc->setText(QString::number(idherramientas[ui.comboBox_2->currentIndex()]));

		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,0,itemMaquina);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,1,itemIdMaq);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,2,itemDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,3,itemIdDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,4,itemCate);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,5,itemcant);
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("La cantidad debe ser diferente de 0");
		msgBox.exec();
	}*/
}
void cosmec::sumarConsumible(){
	QString consumible=ui.comboBox_13->currentText();
	QString maq=ui.comboBox_5->currentText();
	double cantH=ui.doubleSpinBox_4->value();

	if(cantH!=0){
		ui.tableWidget_12->insertRow(ui.tableWidget_12->rowCount());

		QTableWidgetItem *itemMaquina = new QTableWidgetItem;
		QTableWidgetItem *itemDesc = new QTableWidgetItem;
		QTableWidgetItem *itemCate = new QTableWidgetItem;
		QTableWidgetItem *itemcant = new QTableWidgetItem;
		QTableWidgetItem *itemIdMaq = new QTableWidgetItem;
		QTableWidgetItem *itemIdDesc = new QTableWidgetItem;

		itemMaquina->setText(maq);
		itemDesc->setText(consumible);
		itemCate->setText("Consumible");
		itemcant->setText(QString::number(cantH));
		itemIdMaq->setText(QString::number(idmaquinas[ui.comboBox_5->currentIndex()]));
		itemIdDesc->setText(QString::number(idconsumibles[ui.comboBox_13->currentIndex()]));

		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,0,itemMaquina);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,1,itemIdMaq);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,2,itemDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,3,itemIdDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,4,itemCate);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,5,itemcant);
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("La cantidad debe ser diferente de 0");
		msgBox.exec();
	}
}
void cosmec::eliminarPrimeraCotizacion(){
	int currentRow=ui.tableWidget_12->currentRow();
	ui.tableWidget_12->removeRow(currentRow);
}
void cosmec::segundaParte(){
	if(ui.lineEdit_2->text()!="" && ui.lineEdit->text()!="" &&ui.lineEdit_22->text()!="" && ui.lineEdit_14->text()!="" &&
		ui.lineEdit_16->text()!="" && ui.lineEdit_13->text()!="" && ui.lineEdit_4->text()!="" && ui.lineEdit_15->text()!="" &&
		ui.lineEdit_17->text()!="" && ui.tableWidget_12->rowCount()!=0 && ui.spinBox->value()!=0){
		
		//ui.menuBar->setEnabled(false);

		QString sql;
		int numfilas=ui.tableWidget_12->rowCount();
		QString nobre=ui.lineEdit_2->text();
		QString dirigido=ui.lineEdit_11->text();
		QString proyecto=ui.lineEdit_12->text();
		QString forma_pago=ui.lineEdit_14->text();
		QString dura_coti=ui.lineEdit_16->text();
		QString ciudad=ui.lineEdit_13->text();
		QString fecha=ui.lineEdit_22->text();
		int ruc=QString(ui.lineEdit->text()).toInt();
		QString tiempo=ui.lineEdit_15->text();
		QString lugar=ui.lineEdit_17->text();
		QString direc=ui.lineEdit_3->text();
		QString telf=ui.lineEdit_4->text();
		int piezas=ui.spinBox->value();
		double descuento=ui.doubleSpinBox_6->value();

		if(modificar){
			sql=QString("UPDATE cotizacion "
				"SET nombre='%1', dirigido='%2', fecha='%3', ruc=%4, proyecto='%5', ciudad='%6', " 
				"telefono='%7', direccion='%8', forma_pago='%9', "
				"lugar_entrega='%10', tiempo_entrega='%11', duracion_cotizacion='%12', " 
				"descuento=%13, piezas=%14 "
				"WHERE numero='%15'").arg(nobre).arg(dirigido).arg(fecha).arg(ruc).arg(proyecto).arg(ciudad)
				.arg(telf).arg(direc).arg(forma_pago).arg(lugar).arg(tiempo).arg(dura_coti).arg(descuento).arg(piezas).arg(numerocoti);
		}else{
			sql=QString("INSERT INTO cotizacion(nombre, dirigido, fecha, ruc, proyecto, ciudad, telefono, "
				"direccion,forma_pago, lugar_entrega, "
				"tiempo_entrega, duracion_cotizacion, id_usuario_usuarios, descuento, "
				"piezas)VALUES ('%1','%2','%3',%4,'%5','%6','%7','%8', "
				"'%9','%10','%11','%12',%13,%14,%15)").arg(nobre).arg(dirigido).arg(fecha).arg(ruc).arg(proyecto).arg(ciudad).arg(telf)
				.arg(direc).arg(forma_pago).arg(lugar).arg(tiempo).arg(dura_coti).arg(idusuario).arg(descuento).arg(piezas);
		}
		insertarsql(sql);
		for(int a=0;a<numfilas;a++){
			QTableWidgetItem *itab1 = ui.tableWidget_12->item(a,4);
			QTableWidgetItem *itab2 = ui.tableWidget_12->item(a,1);
			QTableWidgetItem *itab4 = ui.tableWidget_12->item(a,3);
			QTableWidgetItem *itab5 = ui.tableWidget_12->item(a,5);
			int id_maquina=QString(itab2->text()).toInt();
			int id_item=QString(itab4->text()).toInt();
			double cantidad=QString(itab5->text()).toDouble();
			double valor;
			sql=QString("SELECT SUM(a.costo_mes), c.modelo FROM actividades_trabajo AS a,mano_obra AS b, maquinas AS c "
				"WHERE c.serie=b.serie_maquinas AND b.id_actividad_actividades_trabajo=a.id_actividad AND c.serie=%1 GROUP BY c.serie").arg(id_maquina);
			valor=sql_general(sql,0).toDouble()/160;

			if(itab1->text()=="Máquina"){
				sql=QString("INSERT INTO maquina_cotizacion(cantidad, numero_cotizacion, serie_maquinas) "
					"VALUES (%1,%2,%3)").arg(cantidad).arg(numerocoti).arg(id_maquina);
				insertarsql(sql);
				sql=QString("INSERT INTO cotizacion_manoobra(serie_maquina, numero_cotizacion,valor_mano,cantidad_mano) "
					"VALUES (%1,%2,0,0)").arg(id_maquina).arg(numerocoti);
				insertarsql(sql);
			}
			if(itab1->text()=="Actividad"){
				sql=QString("INSERT INTO actividades_cotizacion(id_actividad_actividades, numero_cotizacion, cantidad) "
					"VALUES (%1,%2,%3)").arg(id_item).arg(numerocoti).arg(cantidad);
				insertarsql(sql);
			}
			if(itab1->text()=="Mano de obra"){
				sql=QString("UPDATE cotizacion_manoobra SET valor_mano=%1, cantidad_mano=%2 "
					"WHERE serie_maquina=%3 AND numero_cotizacion=%4").arg(valor).arg(cantidad).arg(id_maquina).arg(numerocoti);
				insertarsql(sql);
			}
			if(itab1->text()=="Material"){
				sql=QString("INSERT INTO cotizacion_material(cantidad, serie_maquinas, numero_cotizacion, id_material_materiales) "
					"VALUES (%1,%2,%3,%4)").arg(cantidad).arg(id_maquina).arg(numerocoti).arg(id_item);
				insertarsql(sql);
			}
			if(itab1->text()=="Servicio Externo"){
				sql=QString("INSERT INTO servicios_cotizacion(numero_cotizacion, id_servicios_servicios_externos, " 
					"cantidad_servicios) VALUES (%1,%2,%3)").arg(numerocoti).arg(id_item).arg(cantidad);
				insertarsql(sql);
			}
			if(itab1->text()=="Consumible"){
				sql=QString("INSERT INTO consumibles_cotizacion(numero_cotizacion, id_consumible_consumible, " 
					"cantidad) VALUES (%1,%2,%3)").arg(numerocoti).arg(id_item).arg(cantidad);
				insertarsql(sql);
			}
		}
		ui.pushButton_35->setVisible(false);
		double subtotal=calcularcotizacion2(numerocoti);
		sql=QString("UPDATE cotizacion SET subtotal_cotizacion=%1 WHERE numero=%2").arg(subtotal).arg(numerocoti);
		insertarsql(sql);
		ui.lineEdit_18->setText(QString::number(piezas));
		ui.lineEdit_19->setText(QString::number(descuento));
		double aux=piezas*subtotal*(1-(descuento/100));
		ui.lineEdit_20->setText(QString::number(aux));
		ui.lineEdit_27->setText(QString::number(subtotal));
		ui.lineEdit_30->setText(QString::number(redondear(iva*aux)));
		ui.lineEdit_29->setText(QString::number(redondear((1+iva)*aux)));
		
		ui.stackedWidget->setCurrentIndex(13);
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("Ingrese:\n\n- Cliente\n- CI/RUC\n- Forma de pago\n- Ciudad\n- Fecha\n- Teléfono\n- Duración de la cotización\n- Tiempo de entrega\n- Lugar de entrega\n- Número de piezas diferente de cero\n- Elementos de la cotización");
		msgBox.exec();
	}

}
void cosmec::sumarMaq(){
	QString maquina=ui.comboBox_5->currentText();
	double cantH=ui.doubleSpinBox_2->value();

	if(cantH!=0){
		ui.tableWidget_12->insertRow(ui.tableWidget_12->rowCount());

		QTableWidgetItem *itemMaquina = new QTableWidgetItem;
		QTableWidgetItem *itemDesc = new QTableWidgetItem;
		QTableWidgetItem *itemCate = new QTableWidgetItem;
		QTableWidgetItem *itemcant = new QTableWidgetItem;
		QTableWidgetItem *itemIdMaq = new QTableWidgetItem;
		QTableWidgetItem *itemIdDesc = new QTableWidgetItem;

		itemMaquina->setText(maquina);
		itemDesc->setText(maquina);
		itemCate->setText("Máquina");
		itemcant->setText(QString::number(cantH));
		itemIdMaq->setText(QString::number(idmaquinas[ui.comboBox_5->currentIndex()])); //id maquina
		itemIdDesc->setText(QString::number(idmaquinas[ui.comboBox_5->currentIndex()])); //id maquina

		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,0,itemMaquina);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,1,itemIdMaq);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,2,itemDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,3,itemIdDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,4,itemCate);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,5,itemcant);
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("El tiempo debe ser diferente de 0");
		msgBox.exec();
	}
}

void cosmec::sumarActividad(){
	QString actividad=ui.comboBox_11->currentText();
	QString maq=ui.comboBox_5->currentText();
	double cantH=ui.doubleSpinBox->value();

	if(cantH!=0){
		ui.tableWidget_12->insertRow(ui.tableWidget_12->rowCount());

		QTableWidgetItem *itemMaquina = new QTableWidgetItem;
		QTableWidgetItem *itemDesc = new QTableWidgetItem;
		QTableWidgetItem *itemCate = new QTableWidgetItem;
		QTableWidgetItem *itemcant = new QTableWidgetItem;
		QTableWidgetItem *itemIdMaq = new QTableWidgetItem;
		QTableWidgetItem *itemIdDesc = new QTableWidgetItem;

		itemMaquina->setText("Cotizacion");
		itemDesc->setText(actividad);
		itemCate->setText("Actividad");
		itemcant->setText(QString::number(cantH));
		itemIdMaq->setText(QString::number(numerocoti)); //id maquina
		itemIdDesc->setText(QString::number(idactividades[ui.comboBox_11->currentIndex()])); //id actividad

		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,0,itemMaquina);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,1,itemIdMaq);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,2,itemDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,3,itemIdDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,4,itemCate);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,5,itemcant);
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("El tiempo debe ser diferente de 0");
		msgBox.exec();
	}
}
void cosmec::sumarMo(){
	QString maquina=ui.comboBox_5->currentText();
	double cantH=ui.doubleSpinBox_5->value();

	if(cantH!=0){
		ui.tableWidget_12->insertRow(ui.tableWidget_12->rowCount());

		QTableWidgetItem *itemMaquina = new QTableWidgetItem;
		QTableWidgetItem *itemDesc = new QTableWidgetItem;
		QTableWidgetItem *itemCate = new QTableWidgetItem;
		QTableWidgetItem *itemcant = new QTableWidgetItem;
		QTableWidgetItem *itemIdMaq = new QTableWidgetItem;
		QTableWidgetItem *itemIdDesc = new QTableWidgetItem;

		itemMaquina->setText(maquina);
		itemDesc->setText("Mano de obra");
		itemCate->setText("Mano de obra");
		itemcant->setText(QString::number(cantH));
		itemIdMaq->setText(QString::number(idmaquinas[ui.comboBox_5->currentIndex()])); //id maquina
		itemIdDesc->setText("Sin Id"); //id maquina

		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,0,itemMaquina);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,1,itemIdMaq);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,2,itemDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,3,itemIdDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,4,itemCate);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,5,itemcant);
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("El tiempo debe ser diferente de 0");
		msgBox.exec();
	}
}
void cosmec::eliminarSegundaCotizacion(){
	int currentRow=ui.tableWidget_15->currentRow();
	ui.tableWidget_15->removeRow(currentRow);
}
void cosmec::terminarCotizacion(){
	ui.menuBar->setEnabled(true);
    //------------------------------------
	QString sql;
	int numfilas=ui.tableWidget_15->rowCount();
	for(int a=0;a<numfilas;a++){
		QTableWidgetItem *itab1 = ui.tableWidget_15->item(a,4);
		QTableWidgetItem *itab2 = ui.tableWidget_15->item(a,1);
		QTableWidgetItem *itab4 = ui.tableWidget_15->item(a,3);
		QTableWidgetItem *itab5 = ui.tableWidget_15->item(a,5);
		int id_maquina=QString(itab2->text()).toInt();
		int id_item=QString(itab4->text()).toInt();
		double cantidad=QString(itab5->text()).toDouble();
		if(itab1->text()=="Máquina"){
			sql=QString("INSERT INTO maquina_cotizacion(cantidad, numero_cotizacion, serie_maquinas) "
				"VALUES (%1,%2,%3)").arg(cantidad).arg(numerocoti).arg(id_maquina);
			insertarsql(sql);
		}
		if(itab1->text()=="Actividad"){
			sql=QString("INSERT INTO actividades_cotizacion(serie_maquinas, id_actividad_actividades, numero_cotizacion, cantidad) "
			    "VALUES (%1,%2,%3,%4)").arg(id_maquina).arg(id_item).arg(numerocoti).arg(cantidad);
			insertarsql(sql);
		}
		if(itab1->text()=="Mano de obra"){
			sql=QString("SELECT SUM(a.costo_mes), c.modelo FROM actividades_trabajo AS a,mano_obra AS b, maquinas AS c "
				"WHERE c.serie=b.serie_maquinas AND b.id_actividad_actividades_trabajo=a.id_actividad AND c.serie=%1 GROUP BY c.serie").arg(id_maquina);
			double valor=sql_general(sql,0).toDouble()/160;
			
			sql=QString("INSERT INTO cotizacion_manoobra(serie_maquina, valor_mano, cantidad_mano, numero_cotizacion) "
				"VALUES (%1,%2,%3,%4)").arg(id_maquina).arg(valor).arg(cantidad).arg(numerocoti);
			insertarsql(sql);
		}
		if(itab1->text()=="Material"){
			sql=QString("INSERT INTO cotizacion_material(cantidad, serie_maquinas, numero_cotizacion, id_material_materiales) "
			"VALUES (%1,%2,%3,%4)").arg(cantidad).arg(id_maquina).arg(numerocoti).arg(id_item);
			insertarsql(sql);
		}
	}
	//------------------------------------
	double subtotal=calcularcotizacion2(numerocoti);
	sql=QString("UPDATE cotizacion SET subtotal_cotizacion=%1 WHERE numero=%2").arg(subtotal).arg(numerocoti);
	insertarsql(sql);
	ui.lineEdit_27->setText(QString::number(subtotal));
	ui.lineEdit_30->setText(QString::number(iva*subtotal));
	ui.lineEdit_29->setText(QString::number((1+iva)*subtotal));
	ui.pushButton_35->setVisible(false);
	ui.stackedWidget->setCurrentIndex(14);
}
void cosmec::cancelarCotizacion(){
	//eliminar cotizacion
	QString sql;
	sql=QString("DELETE FROM herramientas_cotizacion WHERE numero_cotizacion=%1").arg(numerocoti);
	insertarsql(sql);
	sql=QString("DELETE FROM cotizacion_consumible WHERE numero_cotizacion=%1").arg(numerocoti);
	insertarsql(sql);
	sql=QString("DELETE FROM cotizacion	WHERE numero=%1").arg(numerocoti);
	insertarsql(sql);
	sql=sql="SELECT setval('cotizacion_numero_seq',(SELECT nextval('cotizacion_numero_seq'))-1)";
	int sec=sql_general(sql,0).toInt()-1;
	sql=QString("SELECT setval('cotizacion_numero_seq',%1)").arg(sec);
	insertarsql(sql);
	ui.menuBar->setEnabled(true);
	ui.stackedWidget->setCurrentIndex(0);
}
void cosmec::sumarMaterial(){
	QString maquina=ui.comboBox_5->currentText();
	QString material=ui.comboBox->currentText();
	double cantH=ui.doubleSpinBox_7->value();

	if(cantH!=0){
		ui.tableWidget_12->insertRow(ui.tableWidget_12->rowCount());

		QTableWidgetItem *itemMaquina = new QTableWidgetItem;
		QTableWidgetItem *itemDesc = new QTableWidgetItem;
		QTableWidgetItem *itemCate = new QTableWidgetItem;
		QTableWidgetItem *itemcant = new QTableWidgetItem;
		QTableWidgetItem *itemIdMaq = new QTableWidgetItem;
		QTableWidgetItem *itemIdDesc = new QTableWidgetItem;

		itemMaquina->setText(maquina);
		itemDesc->setText(material);
		itemCate->setText("Material");
		itemcant->setText(QString::number(cantH));
		itemIdMaq->setText(QString::number(idmaquinas[ui.comboBox_5->currentIndex()])); //id maquina
		itemIdDesc->setText(QString::number(idmaterial[ui.comboBox->currentIndex()])); //id maquina

		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,0,itemMaquina);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,1,itemIdMaq);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,2,itemDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,3,itemIdDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,4,itemCate);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,5,itemcant);
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("La cantidad debe ser diferente de 0");
		msgBox.exec();
	}
}
void cosmec::sumarServExt(){
	QString servext=ui.comboBox_6->currentText();
	double cantH=ui.doubleSpinBox_3->value();

	if(cantH!=0){
		ui.tableWidget_12->insertRow(ui.tableWidget_12->rowCount());

		QTableWidgetItem *itemMaquina = new QTableWidgetItem;
		QTableWidgetItem *itemDesc = new QTableWidgetItem;
		QTableWidgetItem *itemCate = new QTableWidgetItem;
		QTableWidgetItem *itemcant = new QTableWidgetItem;
		QTableWidgetItem *itemIdMaq = new QTableWidgetItem;
		QTableWidgetItem *itemIdDesc = new QTableWidgetItem;

		itemMaquina->setText("Cotizacion");
		itemDesc->setText(servext);
		itemCate->setText("Servicio Externo");
		itemcant->setText(QString::number(cantH));
		itemIdMaq->setText(QString::number(numerocoti)); //id maquina
		itemIdDesc->setText(QString::number(idserv[ui.comboBox_6->currentIndex()])); //id actividad

		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,0,itemMaquina);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,1,itemIdMaq);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,2,itemDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,3,itemIdDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,4,itemCate);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,5,itemcant);
	}
	else{
		QMessageBox msgBox;
		msgBox.setText("El tiempo debe ser diferente de 0");
		msgBox.exec();
	}
}
QVariant cosmec::sql_maquina(int id,int para){
	cosmecdb.open();
	QVariant res;
	QString sql=QString("SELECT * FROM maquinas WHERE serie=%1").arg(id);
	QSqlQuery respuesta(cosmecdb);
	if(!respuesta.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al consultar datos :"+respuesta.lastError().databaseText());
		msgBox.exec();
		return -1;
	}else{
		while(respuesta.next()){
			res=respuesta.value(para);
		}
		cosmecdb.close();
		return res;
	}
}
QVariant cosmec::sql_herramienta(int id,int para){
	cosmecdb.open();
	QVariant res;
	QString sql=QString("SELECT * FROM herramientas WHERE id_herramienta=%1").arg(id);
	QSqlQuery respuesta(cosmecdb);
	if(!respuesta.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al consultar datos :"+respuesta.lastError().databaseText());
		msgBox.exec();
		return -1;
	}else{
		while(respuesta.next()){
			res=respuesta.value(para);
		}
		cosmecdb.close();
		return res;
	}
}
QVariant cosmec::sql_consumibles(int id,int para){
	cosmecdb.open();
	QVariant res;
	QString sql=QString("SELECT * FROM consumible WHERE id_consumible=%1").arg(id);
	QSqlQuery respuesta(cosmecdb);
	if(!respuesta.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
		msgBox.exec();
		return -1;
	}else{
		while(respuesta.next()){
			res=respuesta.value(para);
		}
		cosmecdb.close();
		return res;
	}
}
void cosmec::cargaridenergia(){
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	QString sql="SELECT id_serv_basico FROM serv_basico AS a, maquinas AS b WHERE a.serie_maquinas=b.serie ORDER BY b.modelo";
	if(!respuesta.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
		msgBox.exec();
	}else{
		int fila=0;
		idenergia=new int[respuesta.size()];
		while(respuesta.next()){
			idenergia[fila]=respuesta.value(0).toInt();
			fila++;
		}
		cosmecdb.close();
	}
}
void cosmec::cargaridagua(){
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	QString sql=QString("SELECT a.id_agua,b.serie FROM agua AS a, maquinas AS b WHERE b.serie=a.serie_maquinas ORDER BY b.modelo");
	if(!respuesta.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
		msgBox.exec();
	}else{
		int fila=0;
		idagua=new int[respuesta.size()];
		while(respuesta.next()){
			idagua[fila]=respuesta.value(0).toInt();
			fila++;
		}
		cosmecdb.close();
	}
}

void cosmec::cargaridactividades(){
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	QString sql=QString("SELECT b.id_actividad FROM cargo AS a,actividades_trabajo AS b WHERE a.id_cargo=b.id_cargo_cargo ORDER BY a.nombre");
	if(!respuesta.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
		msgBox.exec();
	}else{
		int fila=0;
		idactividades=new int[respuesta.size()];
		while(respuesta.next()){
			idactividades[fila]=respuesta.value(0).toInt();
			fila++;
		}
		cosmecdb.close();
	}
}
void cosmec::cargaridinsumo(){
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	QString sql=QString("SELECT a.id_insumo FROM mantenimiento_preventivo AS a,maquinas AS b WHERE a.serie_maquinas=b.serie ORDER BY b.modelo");
	if(!respuesta.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
		msgBox.exec();
	}else{
		int fila=0;
		idinsumo=new int[respuesta.size()];
		while(respuesta.next()){
			idinsumo[fila]=respuesta.value(0).toInt();
			fila++;
		}
		cosmecdb.close();
	}
}
void cosmec::cargaridusuario(){
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	QString sql=QString("SELECT id_usuario FROM usuarios ORDER BY usuario");
	if(!respuesta.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
		msgBox.exec();
	}else{
		int fila=0;
		vectusuario=new int[respuesta.size()];
		while(respuesta.next()){
			vectusuario[fila]=respuesta.value(0).toInt();
			fila++;
		}
		cosmecdb.close();
	}
}
QVariant cosmec::sql_general(QString sql,int para){
	cosmecdb.open();
	QVariant res;
	QSqlQuery respuesta(cosmecdb);
	if(!respuesta.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
		msgBox.exec();
		return 0;
	}else{
		while(respuesta.next()){
			res=respuesta.value(para);
		}
		return res;
	}
	cosmecdb.close();
}
QVariant cosmec::sql_record(QString sql,int para){
	cosmecdb.open();
	QVariant res;
	QSqlQuery respuesta(cosmecdb);
	if(!respuesta.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
		msgBox.exec();
		return 0;
	}else{
		while(respuesta.next()){
			res=respuesta.record().value(para);
		}
		return res;
	}
	cosmecdb.close();
}
void cosmec::combocotizacion(int index){
	//ui.comboBox_2->clear();
	//ui.comboBox_4->clear();
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	respuesta.exec(QString("SELECT a.id_herramienta, a.nombre_herramienta FROM herramientas AS a, maquinas AS b WHERE a.serie_maquinas=b.serie AND b.serie=%1 ORDER BY b.modelo").arg(idmaquinas[index]));
	tamquery1=respuesta.size();
	qDebug()<<tamquery1;
	idherramientas=new int[tamquery1];
	int b=0;
	while(respuesta.next()){
		idherramientas[b]=respuesta.value(0).toInt();
		//ui.comboBox_2->addItem(respuesta.value(1).toString());
		b++;
	}

	respuesta.exec(QString("SELECT a.id_consumible, a.nombre_consumible FROM consumible AS a, maquinas AS b WHERE a.serie_maquinas=b.serie AND b.serie=%1 ORDER BY b.modelo").arg(idmaquinas[index]));
	tamquery2=respuesta.size();
	idconsumibles=new int[tamquery2];
	b=0;
	while(respuesta.next()){
		idconsumibles[b]=respuesta.value(0).toInt();
		//ui.comboBox_4->addItem(respuesta.value(1).toString());
		b++;
	}
	cosmecdb.close();
}
void cosmec::combocotizacion2(int index){
	ui.comboBox_11->clear();
	ui.comboBox->clear();
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	respuesta.exec(QString("SELECT a.id_actividad, a.nombre FROM actividades AS a ORDER BY a.nombre"));
	tamquery1=respuesta.size();
	qDebug()<<tamquery1;
	idactividades=new int[tamquery1];
	int b=0;
	while(respuesta.next()){
		idactividades[b]=respuesta.value(0).toInt();
		ui.comboBox_11->addItem(respuesta.value(1).toString());
		b++;
	}

	respuesta.exec(QString("SELECT a.id_material, a.nombre FROM materiales AS a ORDER BY a.nombre").arg(idmaquinas[index]));
	tamquery2=respuesta.size();
	idmaterial=new int[tamquery2];
	b=0;
	while(respuesta.next()){
		idmaterial[b]=respuesta.value(0).toInt();
		ui.comboBox->addItem(respuesta.value(1).toString());
		b++;
	}

	cosmecdb.close();


}
void cosmec::borrartabla(QTableWidget *tableNum){
	int tam=tableNum->rowCount();
	while(tam!=0){
		tableNum->removeRow(tableNum->rowCount()-1);
		tam--;
	}
	tam=0;
}
void cosmec::borrartablaSlot(int index){
	QTableWidget *tableNum=ui.tableWidget_17;
	tableNum->setColumnHidden(2,true);
	int tam=tableNum->rowCount();
	while(tam!=0){
		tableNum->removeRow(tableNum->rowCount()-1);
		tam--;
	}
	tam=0;
}
void cosmec::borrartabla2(QTableWidget *tableNum2){
	int tam=tableNum2->rowCount();
	while(tam!=0){
		tableNum2->removeRow(tam);
		tam--;
	}
	tam=0;
}
double cosmec::calcularcotizacion(int numero){
	QString sql;
	QSqlQuery mac(cosmecdb);
	QSqlQuery aux(cosmecdb);
	QSqlQuery aux2(cosmecdb);
	QString nombre_maquina;
	QTableWidgetItem *nuevo;
	int b=0;
	int serie;
	double cant_cons=0;
	double costo_cons=0;
	double total_cons=0;
	double cantidad_maquina;
	double valor_herra;
	double total_mano_obra;
	double valor_consu;
	double servicios;
	double manteni;
	double costomaqui;
	double maquina;
	double total_maquina;
	double mano_obra;
	double cant_mano_obra;
	double costo_activi;
	double cant_activi;
	double total_activi=0;
	int fila=0;
	double indice=0;
	int indice2=0;
	double subtotal=0;
	double totalaux=0;
	double cant_mat=0;
	double costo_mat=0;
	double total_mat=0;
	double cant_serv=0;
	double costo_serv=0;
	double total_serv=0;
	bool flag=true;
	int index=0;
	cosmecdb.open();
	mac.exec(QString("SELECT a.serie_maquinas, cantidad, b.modelo FROM  maquina_cotizacion AS a,maquinas AS b WHERE a.serie_maquinas=b.serie AND a.numero_cotizacion=%1").arg(numero));
	idmaquinacot=new int[mac.size()];
	while(mac.next()){
		indice2++;
		serie=mac.value(0).toInt();
		idmaquinacot[index]=serie;
		cantidad_maquina=mac.value(1).toDouble();
		nombre_maquina=mac.value(2).toString();
		
		//valor maquina
		sql=QString("SELECT SUM(costo_hora) FROM herramientas WHERE serie_maquinas=%1 GROUP BY serie_maquinas").arg(serie);
		valor_herra=sql_general(sql,0).toDouble();
		/*sql=QString("SELECT SUM(costo_hora) FROM consumible WHERE serie_maquinas=%1 GROUP BY serie_maquinas").arg(serie);
		valor_consu=sql_general(sql,0).toDouble();*/
		
		sql=QString("SELECT SUM(costo_hora) FROM serv_basico WHERE serie_maquinas=%1").arg(serie);
		servicios=sql_general(sql,0).toDouble();
		sql=QString("SELECT (b.presupuesto_anual/b.horas_trabajo_anual)+(SUM(a.costo_hora)) AS costo_total "
			"FROM mantenimiento_preventivo AS a,maquinas AS b WHERE a.serie_maquinas=b.serie AND b.serie=%1 GROUP BY b.serie").arg(serie);
		manteni=sql_general(sql,0).toDouble();
		sql=QString("SELECT ((2*costo)/(vida_util*horas_trabajo_anual)) FROM maquinas WHERE serie=%1").arg(serie);
		costomaqui=sql_general(sql,0).toDouble();
		/*maquina=(valor_herra+valor_consu+servicios+manteni+costomaqui);*/
		maquina=(valor_herra+servicios+manteni+costomaqui);
		maquina=redondear(maquina);
		total_maquina=(maquina)*(1+vcomp)*cantidad_maquina;//<--
		total_maquina=redondear(total_maquina);
		
		//ingresa datos a tabla
		ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
		nuevo=new QTableWidgetItem();
		nuevo->setText(QString::number(indice2+indice));
		ui.tableWidget_24->setItem(fila,0,nuevo);
		nuevo=new QTableWidgetItem();
		nuevo->setText(nombre_maquina);
		ui.tableWidget_24->setItem(fila,1,nuevo);
		nuevo=new QTableWidgetItem();
		nuevo->setText(QString::number(maquina));
		ui.tableWidget_24->setItem(fila,2,nuevo);
		nuevo=new QTableWidgetItem();
		nuevo->setText(QString::number(cantidad_maquina));
		ui.tableWidget_24->setItem(fila,3,nuevo);
		nuevo=new QTableWidgetItem();
		nuevo->setText(QString::number(total_maquina));
		ui.tableWidget_24->setItem(fila,4,nuevo);
		
		fila++;
		indice=indice+0.1;

		//mano de obra
		sql=QString("SELECT valor_mano, cantidad_mano FROM cotizacion_manoobra WHERE serie_maquina=%1 AND numero_cotizacion=%2").arg(serie).arg(numero);
		mano_obra=sql_general(sql,0).toDouble();
		cant_mano_obra=sql_general(sql,1).toDouble();
		total_mano_obra=mano_obra*cant_mano_obra*(1+vcomp);//<---
		total_mano_obra=redondear(total_mano_obra);
		
		if(mano_obra>0){
			//ingresa datos a tabla
			ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(indice2+indice));
			ui.tableWidget_24->setItem(fila,0,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText("Mano de obra");
			ui.tableWidget_24->setItem(fila,1,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(mano_obra));
			ui.tableWidget_24->setItem(fila,2,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(cant_mano_obra));
			ui.tableWidget_24->setItem(fila,3,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(total_mano_obra));
			ui.tableWidget_24->setItem(fila,4,nuevo);
			fila++;
			indice=indice+0.1;
		}
		//Materiales
		cosmecdb.open();
		sql=QString("SELECT a.cantidad, b.costo, b.nombre FROM cotizacion_material AS a,materiales AS b WHERE a.id_material_materiales=b.id_material AND a.serie_maquinas=%1 AND a.numero_cotizacion=%2").arg(serie).arg(numero);
		if(!aux.exec(sql)){
			QMessageBox msgBox;
			msgBox.setText("Error al agregar datos :"+aux.lastError().databaseText());
			msgBox.exec();
		}else{
			while(aux.next()){
				//--------------------------------------
				cant_mat=aux.value(0).toDouble();
				costo_mat=aux.value(1).toDouble();
				total_mat=total_mat+(cant_mat*costo_mat);//<--
				//--------------------------------------
				if(cant_mat*costo_mat>0){
					ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
					nuevo=new QTableWidgetItem();
					nuevo->setText(QString::number(indice2+indice));
					ui.tableWidget_24->setItem(fila,0,nuevo);
					nuevo=new QTableWidgetItem();
					nuevo->setText(aux.value(2).toString());
					ui.tableWidget_24->setItem(fila,1,nuevo);
					nuevo=new QTableWidgetItem();
					nuevo->setText(QString::number(cant_mat));
					ui.tableWidget_24->setItem(fila,3,nuevo);
					nuevo=new QTableWidgetItem();
					nuevo->setText(QString::number(costo_mat));
					ui.tableWidget_24->setItem(fila,2,nuevo);
					nuevo=new QTableWidgetItem();
					nuevo->setText(QString::number(redondear(cant_mat*costo_mat)));
					ui.tableWidget_24->setItem(fila,4,nuevo);
					fila++;
					indice=indice+0.1;
				}
			}
		}
		total_mat=redondear(total_mat);
		cosmecdb.close();
		
		//Consumibles
		cosmecdb.open();
		sql=QString("SELECT a.cantidad, b.costo_unitario, b.nombre_consumible FROM consumibles_cotizacion AS a, consumible AS b WHERE a.id_consumible_consumible=b.id_consumible AND b.serie_maquinas=%1 AND a.numero_cotizacion=%2").arg(serie).arg(numero);
		if(!aux.exec(sql)){
			QMessageBox msgBox;
			msgBox.setText("Error al agregar datos :"+aux.lastError().databaseText());
			msgBox.exec();
		}else{
			while(aux.next()){
				//--------------------------------------
				cant_cons=aux.value(0).toDouble();
				costo_cons=aux.value(1).toDouble();
				total_cons=total_cons+(cant_cons*costo_cons);//<--
				qDebug()<<total_cons;
				//--------------------------------------
				ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(indice2+indice));
				ui.tableWidget_24->setItem(fila,0,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText(aux.value(2).toString());
				ui.tableWidget_24->setItem(fila,1,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(cant_cons));
				ui.tableWidget_24->setItem(fila,3,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(costo_cons));
				ui.tableWidget_24->setItem(fila,2,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(redondear(cant_cons*costo_cons)));
				ui.tableWidget_24->setItem(fila,4,nuevo);
				fila++;
				indice=indice+0.1;
			}
		}
		cosmecdb.close();
		
		index++;
		indice=0;
		totalaux=total_maquina+total_mano_obra+total_mat+total_cons;
		subtotal=subtotal+totalaux;
		subtotal=redondear(subtotal);

		//encere de variables
		valor_herra=0;
		valor_consu=0;
		servicios=0;
		manteni=0;
		costomaqui=0;
		maquina=0;
		total_maquina=0;
		mano_obra=0;
		cant_mano_obra=0;
		total_mano_obra=0;
		cant_activi=0;
		costo_activi=0;
		total_activi=0;
		cant_mat=0;
		costo_mat=0;;
		total_mat=0;
	}

	//Actividades
	cosmecdb.open();
	sql=QString("SELECT a.cantidad, b.costo_hora, b.nombre FROM actividades_cotizacion AS a,actividades AS b WHERE a.id_actividad_actividades=b.id_actividad AND a.numero_cotizacion=%2").arg(numero);
	if(!aux.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al agregar datos :"+aux.lastError().databaseText());
		msgBox.exec();
	}else{
		while(aux.next()){
			if(flag==true){
				//cabezera
				indice2++;
				ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(indice2+indice));
				ui.tableWidget_24->setItem(fila,0,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText("Actividades");
				ui.tableWidget_24->setItem(fila,1,nuevo);
				indice=indice+0.1;
				fila++;
				flag=false;
			}
			//--------------------------------------
			cant_activi=aux.value(0).toDouble();
			costo_activi=aux.value(1).toDouble();
			total_activi=total_activi+((cant_activi*costo_activi)*(1+vcomp));//<-
			//--------------------------------------
			ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(indice2+indice));
			ui.tableWidget_24->setItem(fila,0,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(aux.value(2).toString());
			ui.tableWidget_24->setItem(fila,1,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(costo_activi));
			ui.tableWidget_24->setItem(fila,2,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(cant_activi));
			ui.tableWidget_24->setItem(fila,3,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(redondear(cant_activi*costo_activi)));
			ui.tableWidget_24->setItem(fila,4,nuevo);
			fila++;
			indice=indice+0.1;
		}
		flag=true;
	}
	cosmecdb.close();
	subtotal=subtotal+redondear(total_activi);
	indice=0;

	//Servicios Externos
	cosmecdb.open();
	sql=QString("SELECT a.cantidad_servicios, b.costo_hora, b.nombre_srevicio FROM servicios_cotizacion a, servicios_externos AS b "
		"WHERE id_servicios_servicios_externos=id_servicios AND numero_cotizacion=%1").arg(numero);
	if(!aux2.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al agregar datos :"+aux2.lastError().databaseText());
		msgBox.exec();
	}else{
		while(aux2.next()){
			if (flag==true){
				//cabezera
				indice2++;
				ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(indice2+indice));
				ui.tableWidget_24->setItem(fila,0,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText("Servicios Extras");
				ui.tableWidget_24->setItem(fila,1,nuevo);
				indice=indice+0.1;
				fila++;
				flag=false;
			}
			//--------------------------------------
			cant_serv=aux2.value(0).toDouble();
			costo_serv=aux2.value(1).toDouble();
			total_serv=total_serv+(redondear(cant_serv*costo_serv));//<-
			//--------------------------------------
			ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(indice2+indice));
			ui.tableWidget_24->setItem(fila,0,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(aux2.value(2).toString());
			ui.tableWidget_24->setItem(fila,1,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(costo_serv));
			ui.tableWidget_24->setItem(fila,2,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(cant_serv));
			ui.tableWidget_24->setItem(fila,3,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(redondear(cant_serv*costo_serv)));
			ui.tableWidget_24->setItem(fila,4,nuevo);
			fila++;
			indice=indice+0.1;
		}
		flag=true;
	}
	cosmecdb.close();
	subtotal=subtotal+redondear(total_serv);
	qDebug()<<subtotal;
	return subtotal;
}
double cosmec::calcularcotizacion2(int numero){
	QString sql;
	QSqlQuery mac(cosmecdb);
	QSqlQuery aux(cosmecdb);
	QSqlQuery aux2(cosmecdb);
	QString nombre_maquina;
	QTableWidgetItem *nuevo;
	int b=0;
	int serie;
	double cant_cons=0;
	double costo_cons=0;
	double total_cons=0;
	double cantidad_maquina;
	double valor_herra;
	double total_mano_obra;
	double valor_consu;
	double servicios;
	double manteni;
	double costomaqui;
	double maquina;
	double total_maquina;
	double mano_obra;
	double cant_mano_obra;
	double costo_activi;
	double cant_activi;
	double total_activi=0;
	int fila=0;
	double indice=0;
	int indice2=0;
	double subtotal=0;
	double totalaux=0;
	double cant_mat=0;
	double costo_mat=0;
	double total_mat=0;
	double cant_serv=0;
	double costo_serv=0;
	double total_serv=0;
	int index=0;
	bool flag=true;
	cosmecdb.open();
	mac.exec(QString("SELECT a.serie_maquinas, cantidad, b.modelo FROM  maquina_cotizacion AS a,maquinas AS b WHERE a.serie_maquinas=b.serie AND a.numero_cotizacion=%1").arg(numero));
	idmaquinacot=new int[mac.size()];
	while(mac.next()){
		indice2++;
		serie=mac.value(0).toInt();
		idmaquinacot[index]=serie;
		cantidad_maquina=mac.value(1).toDouble();
		nombre_maquina=mac.value(2).toString();
		
		//valor maquina
		sql=QString("SELECT SUM(costo_hora) FROM herramientas WHERE serie_maquinas=%1 GROUP BY serie_maquinas").arg(serie);
		valor_herra=sql_general(sql,0).toDouble();
		/*sql=QString("SELECT SUM(costo_hora) FROM consumible WHERE serie_maquinas=%1 GROUP BY serie_maquinas").arg(serie);
		valor_consu=sql_general(sql,0).toDouble();*/
		
		sql=QString("SELECT SUM(costo_hora) FROM serv_basico WHERE serie_maquinas=%1").arg(serie);
		servicios=sql_general(sql,0).toDouble();
		sql=QString("SELECT (b.presupuesto_anual/b.horas_trabajo_anual)+(SUM(a.costo_hora)) AS costo_total "
			"FROM mantenimiento_preventivo AS a,maquinas AS b WHERE a.serie_maquinas=b.serie AND b.serie=%1 GROUP BY b.serie").arg(serie);
		manteni=sql_general(sql,0).toDouble();
		sql=QString("SELECT ((2*costo)/(vida_util*horas_trabajo_anual)) FROM maquinas WHERE serie=%1").arg(serie);
		costomaqui=sql_general(sql,0).toDouble();
		/*maquina=(valor_herra+valor_consu+servicios+manteni+costomaqui);*/
		maquina=(valor_herra+servicios+manteni+costomaqui);
		total_maquina=(maquina)*(1+vcomp)*cantidad_maquina;//<--
		//----------------
		sql=QString("UPDATE cotizacion_manoobra SET valor_maquinas=%1, cantidad_maquina=%2 "
			"WHERE serie_maquina=%3 AND numero_cotizacion=%4").arg(maquina).arg(cantidad_maquina).arg(serie).arg(numero);
		insertarsql(sql);
		//----------------
		//ingresa datos a tabla
		ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
		nuevo=new QTableWidgetItem();
		nuevo->setText(QString::number(indice2+indice));
		ui.tableWidget_24->setItem(fila,0,nuevo);
		nuevo=new QTableWidgetItem();
		nuevo->setText(nombre_maquina);
		ui.tableWidget_24->setItem(fila,1,nuevo);
		nuevo=new QTableWidgetItem();
		nuevo->setText(QString::number(redondear(maquina)));
		ui.tableWidget_24->setItem(fila,2,nuevo);
		nuevo=new QTableWidgetItem();
		nuevo->setText(QString::number(redondear(cantidad_maquina)));
		ui.tableWidget_24->setItem(fila,3,nuevo);
		nuevo=new QTableWidgetItem();
		nuevo->setText(QString::number(redondear(total_maquina)));
		ui.tableWidget_24->setItem(fila,4,nuevo);
		
		fila++;
		indice=indice+0.1;

		//mano de obra
		sql=QString("SELECT valor_mano, cantidad_mano FROM cotizacion_manoobra WHERE serie_maquina=%1 AND numero_cotizacion=%2").arg(serie).arg(numero);
		mano_obra=sql_general(sql,0).toDouble();
		cant_mano_obra=sql_general(sql,1).toDouble();
		total_mano_obra=mano_obra*cant_mano_obra*(1+vcomp);//<---
		
		if(mano_obra>0){
			//ingresa datos a tabla
			ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(indice2+indice));
			ui.tableWidget_24->setItem(fila,0,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText("Mano de obra");
			ui.tableWidget_24->setItem(fila,1,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(mano_obra));
			ui.tableWidget_24->setItem(fila,2,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(cant_mano_obra));
			ui.tableWidget_24->setItem(fila,3,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(redondear(total_mano_obra)));
			ui.tableWidget_24->setItem(fila,4,nuevo);
			fila++;
			indice=indice+0.1;
		}
		//Materiales
		cosmecdb.open();
		sql=QString("SELECT a.cantidad, b.costo, b.nombre FROM cotizacion_material AS a,materiales AS b WHERE a.id_material_materiales=b.id_material AND a.serie_maquinas=%1 AND a.numero_cotizacion=%2").arg(serie).arg(numero);
		if(!aux.exec(sql)){
			QMessageBox msgBox;
			msgBox.setText("Error al agregar datos :"+aux.lastError().databaseText());
			msgBox.exec();
		}else{
			while(aux.next()){
				//--------------------------------------
				cant_mat=aux.value(0).toDouble();
				costo_mat=aux.value(1).toDouble();
				total_mat=total_mat+(cant_mat*costo_mat);//<--
				//--------------------------------------
				ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(indice2+indice));
				ui.tableWidget_24->setItem(fila,0,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText(aux.value(2).toString());
				ui.tableWidget_24->setItem(fila,1,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(cant_mat));
				ui.tableWidget_24->setItem(fila,3,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(costo_mat));
				ui.tableWidget_24->setItem(fila,2,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(redondear(cant_mat*costo_mat)));
				ui.tableWidget_24->setItem(fila,4,nuevo);
				fila++;
				indice=indice+0.1;
			}
		}
		cosmecdb.close();
		
		//Consumibles
		cosmecdb.open();
		sql=QString("SELECT a.cantidad, b.costo_unitario, b.nombre_consumible FROM consumibles_cotizacion AS a, consumible AS b WHERE a.id_consumible_consumible=b.id_consumible AND b.serie_maquinas=%1 AND a.numero_cotizacion=%2").arg(serie).arg(numero);
		if(!aux.exec(sql)){
			QMessageBox msgBox;
			msgBox.setText("Error al agregar datos :"+aux.lastError().databaseText());
			msgBox.exec();
		}else{
			while(aux.next()){
				//--------------------------------------
				cant_cons=aux.value(0).toDouble();
				costo_cons=aux.value(1).toDouble();
				total_cons=total_cons+(cant_cons*costo_cons);//<--
				//--------------------------------------
				ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(indice2+indice));
				ui.tableWidget_24->setItem(fila,0,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText(aux.value(2).toString());
				ui.tableWidget_24->setItem(fila,1,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(cant_cons));
				ui.tableWidget_24->setItem(fila,3,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(costo_cons));
				ui.tableWidget_24->setItem(fila,2,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(redondear(cant_cons*costo_cons)));
				ui.tableWidget_24->setItem(fila,4,nuevo);
				fila++;
				indice=indice+0.1;
			}
		}
		cosmecdb.close();
		//--------------------------
		sql=QString("UPDATE cotizacion_manoobra SET valor_material=%1, valor_consumible=%4 "
			"WHERE serie_maquina=%2 AND numero_cotizacion=%3").arg(total_mat).arg(serie).arg(numero).arg(total_cons);
		insertarsql(sql);
		//--------------------------
		index++;
		indice=0;
		totalaux=total_maquina+total_mano_obra+total_mat+total_cons;
		subtotal=subtotal+totalaux;
		
		//encere de variables
		valor_herra=0;
		valor_consu=0;
		servicios=0;
		manteni=0;
		costomaqui=0;
		maquina=0;
		total_maquina=0;
		mano_obra=0;
		cant_mano_obra=0;
		total_mano_obra=0;
		cant_activi=0;
		costo_activi=0;
		total_activi=0;
		cant_mat=0;
		costo_mat=0;;
		total_mat=0;
	}

	//Actividades
	cosmecdb.open();
	sql=QString("SELECT a.cantidad, b.costo_hora, b.nombre FROM actividades_cotizacion AS a,actividades AS b WHERE a.id_actividad_actividades=b.id_actividad AND a.numero_cotizacion=%2").arg(numero);
	if(!aux.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al agregar datos :"+aux.lastError().databaseText());
		msgBox.exec();
	}else{
		while(aux.next()){
			if(flag==true){
				//cabezera
				indice2++;
				ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(indice2+indice));
				ui.tableWidget_24->setItem(fila,0,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText("Actividades");
				ui.tableWidget_24->setItem(fila,1,nuevo);
				indice=indice+0.1;
				fila++;
				flag=false;
			}
			//--------------------------------------
			cant_activi=aux.value(0).toDouble();
			costo_activi=aux.value(1).toDouble();
			total_activi=total_activi+((cant_activi*costo_activi)*(1+vcomp));//<-
			//--------------------------------------
			ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(indice2+indice));
			ui.tableWidget_24->setItem(fila,0,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(aux.value(2).toString());
			ui.tableWidget_24->setItem(fila,1,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(costo_activi));
			ui.tableWidget_24->setItem(fila,2,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(cant_activi));
			ui.tableWidget_24->setItem(fila,3,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(redondear(cant_activi*costo_activi)));
			ui.tableWidget_24->setItem(fila,4,nuevo);
			fila++;
			indice=indice+0.1;
		}
		flag=true;
	}
	cosmecdb.close();
	subtotal=subtotal+total_activi;
	indice=0;

	//Servicios Externos
	cosmecdb.open();
	sql=QString("SELECT a.cantidad_servicios, b.costo_hora, b.nombre_srevicio FROM servicios_cotizacion a, servicios_externos AS b "
		"WHERE id_servicios_servicios_externos=id_servicios AND numero_cotizacion=%1").arg(numero);
	if(!aux2.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al agregar datos :"+aux2.lastError().databaseText());
		msgBox.exec();
	}else{
		while(aux2.next()){
			if(flag==true){
				//cabecera
				indice2++;
				ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
				nuevo=new QTableWidgetItem();
				nuevo->setText(QString::number(indice2+indice));
				ui.tableWidget_24->setItem(fila,0,nuevo);
				nuevo=new QTableWidgetItem();
				nuevo->setText("Servicios Extras");
				ui.tableWidget_24->setItem(fila,1,nuevo);
				indice=indice+0.1;
				fila++;
				flag=false;
			}
			//--------------------------------------
			cant_serv=aux2.value(0).toDouble();
			costo_serv=aux2.value(1).toDouble();
			total_serv=total_serv+(cant_serv*costo_serv);//<-
			//--------------------------------------
			ui.tableWidget_24->insertRow(ui.tableWidget_24->rowCount());
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(indice2+indice));
			ui.tableWidget_24->setItem(fila,0,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(aux2.value(2).toString());
			ui.tableWidget_24->setItem(fila,1,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(costo_serv));
			ui.tableWidget_24->setItem(fila,2,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(cant_serv));
			ui.tableWidget_24->setItem(fila,3,nuevo);
			nuevo=new QTableWidgetItem();
			nuevo->setText(QString::number(redondear(cant_serv*costo_serv)));
			ui.tableWidget_24->setItem(fila,4,nuevo);
			fila++;
			indice=indice+0.1;
		}
		flag=true;
	}
	cosmecdb.close();
	subtotal=subtotal+total_serv;
	qDebug()<<subtotal;
	return subtotal;
}

//Formularios
void cosmec::setformulariomaq(){
	formularioMaq *nuevo=new formularioMaq();
	nuevo->show();
}
//Usuarios
void cosmec::verificarUsuario(){
	QSqlQuery aux2(cosmecdb);
	QString usu=ui.lineUser->text();
	QString passing=ui.linePass->text();
	QString passing2;
	QString sql;
	int nivel;
	cosmecdb.open();
	sql=QString("SELECT pass, nivel, usuario, id_usuario,nombre FROM usuarios WHERE usuario='%1'").arg(usu);
	if(!aux2.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("No existe el usuario ingresado");
		msgBox.exec();
	}else{
		while(aux2.next()){
			passing2=aux2.value(0).toString();
			usuariop=aux2.value(2).toString();
            nombrep=aux2.value(4).toString();
			nivel=aux2.value(1).toInt();
			idusuario=aux2.value(3).toInt();
		}
		if(usu==usuariop && passing==passing2){
			ui.menuCotizaciones->setEnabled(true);
			ui.menuReportes->setEnabled(true);
			ui.frame_4->setVisible(false);
			if(nivel==1){
				ui.menuNuevo->setEnabled(true);
				ui.actionUsuarios->setEnabled(true);
				ui.menuArchivos->setEnabled(true);
				QMessageBox msgBox;
				msgBox.setText("Bienvenido usuario "+nombrep+"!");
				msgBox.exec();
			}else{
				ui.menuNuevo->setEnabled(false);
				ui.actionUsuarios->setEnabled(false);
				ui.menuArchivos->setEnabled(true);
				QMessageBox msgBox;
				msgBox.setText("Bienvenido usuario "+nombrep+"!");
				msgBox.exec();
			}
			
		}else{
			QMessageBox msgBox;
			msgBox.setText("Usuario o contraseña incorrecta. Ingrese los datos nuevamente.");
			msgBox.exec();
		}
	}
}

void cosmec::agregarUser(){
	QString sql;
	QString nombre =ui.lineEdit_8->text();
	QString usuario=ui.lineEdit_9->text();
	QString password=ui.lineEdit_10->text();
	bool isAdmin=ui.checkBox_6->isChecked();

	if(isAdmin){
		sql=QString("INSERT INTO usuarios(nombre, usuario, pass, nivel)	VALUES ('%1','%2','%3',1)").arg(nombre).arg(usuario).arg(password);
	}else{
		sql=QString("INSERT INTO usuarios(nombre, usuario, pass, nivel)	VALUES ('%1','%2','%3',2)").arg(nombre).arg(usuario).arg(password);
	}
	insertarsql(sql);

	sql="SELECT usuario, nombre FROM usuarios ORDER BY usuario";
	llenartabla(ui.tableWidget_16,sql);
	cargaridusuario();
	ui.lineEdit_8->setText("");
	ui.lineEdit_9->setText("");
	ui.lineEdit_10->setText("");

}
void cosmec::modificarUser(){
	QString sql;
	if(ui.pushButton_40->isChecked()){
		int filActual=ui.tableWidget_16->currentRow();
		if(filActual!=-1){
			QTableWidgetItem *itemUser = ui.tableWidget_16->item(filActual,0);
			QTableWidgetItem *itemNom = ui.tableWidget_16->item(filActual,1);
			idusersel=vectusuario[filActual];
			sql=QString("SELECT nombre, usuario, pass, nivel FROM usuarios WHERE id_usuario=%1").arg(idusersel);
			ui.lineEdit_8->setText(sql_general(sql,0).toString());
			ui.lineEdit_9->setText(sql_general(sql,1).toString());
			ui.lineEdit_10->setText(sql_general(sql,2).toString());
			int nive=sql_general(sql,3).toInt();
		}else{
			QMessageBox msgBox;
			msgBox.setText("Seleccione un usuario");
			msgBox.exec();
		}
		ui.pushButton_40->setText("Guardar");
		ui.pushButton_12->setEnabled(false);
		ui.menuBar->setEnabled(false);
	}else{
		QString nombre =ui.lineEdit_8->text();
		QString usuario=ui.lineEdit_9->text();
		QString password=ui.lineEdit_10->text();
		bool isAdmin=ui.checkBox_6->isChecked();
		if(isAdmin){
			sql=QString("UPDATE usuarios SET nombre='%1', usuario='%2', pass='%3', nivel=1 "
				    "WHERE id_usuario=%4").arg(nombre).arg(usuario).arg(password).arg(idusersel);
		}else{
			sql=QString("UPDATE usuarios SET nombre='%1', usuario='%2', pass='%3', nivel=2 "
				"WHERE id_usuario=%4").arg(nombre).arg(usuario).arg(password).arg(idusersel);
		}
		qDebug()<<idusersel;
		insertarsql(sql);

		sql="SELECT usuario, nombre FROM usuarios ORDER BY usuario";
		llenartabla(ui.tableWidget_16,sql);
		cargaridusuario();
		ui.lineEdit_8->setText("");
		ui.lineEdit_9->setText("");
		ui.lineEdit_10->setText("");
		ui.checkBox_6->setChecked(false);
		
		ui.pushButton_40->setText("Modificar");
		ui.pushButton_12->setEnabled(true);
		ui.menuBar->setEnabled(true);
	}
}
void cosmec::setUsuarios(){
	QString sql="SELECT usuario, nombre FROM usuarios ORDER BY usuario";
	llenartabla(ui.tableWidget_16,sql);
	llenartabla(ui.tableWidget_16,sql);
	cargaridusuario();
	ui.stackedWidget->setCurrentIndex(17);
}

void cosmec::setInicio(){
	ui.stackedWidget->setCurrentIndex(0);
}
double cosmec::redondear(double num){
	double val;
	double scale = 0.01;  // i.e. round to nearest one-hundreth
	val = floor(num / scale + 0.5) * scale;
	return val;
}

void cosmec::setBusqueda(){
	ui.stackedWidget->setCurrentIndex(18);
	ui.tableWidget_17->setColumnHidden(2,true);
	ui.comboBox_3->setEnabled(false);
}
void cosmec::cambiarCombo(int opcion){
	QString sql;
	switch(opcion){
		case 0:
			ui.comboBox_3->setEnabled(false);
			break;
		case 1:
			//ui.comboBox_3->setEnabled(true);

			//cargar combo con máquinas
			//break;
		case 2:
			//ui.comboBox_3->setEnabled(true);
			////cargar combo con máquinas
			//break;
		case 3:
			//ui.comboBox_3->setEnabled(true);
			////cargar combo con máquinas
			//break;
		case 4:
			ui.comboBox_3->setEnabled(true);
			//cargar combo con máquinas
			sql="SELECT a.serie,a.modelo,a.cod_espe FROM maquinas AS a ORDER BY a.modelo";
			llenarcombomaq(sql,ui.comboBox_3);
			break;
		case 5:
			ui.comboBox_3->setEnabled(true);
			sql="SELECT a.id_categoria_actividades,a.nombre FROM categoria_actividades AS a ORDER BY a.nombre";
			llenarcombocat(sql,ui.comboBox_3);
			//cargar combo con CATEGORIAS
			break;
		case 6:
			ui.comboBox_3->setEnabled(false);
			break;
		case 7:
			ui.comboBox_3->setEnabled(true);
			sql="SELECT a.id_cargo,a.nombre FROM cargo AS a ORDER BY a.nombre";
			llenarcombocargo(sql,ui.comboBox_3);
			//cargar combo con CARGOS
			break;
		case 8:
			ui.comboBox_3->setEnabled(false);
			break;
		case 9:
			ui.comboBox_3->setEnabled(false);
			break;
		case 10:
			ui.comboBox_3->setEnabled(false);
			break;
	}
}
void cosmec::tablaBusqueda(){
	//poner función para llenar la tabla en función de los parámetros de búsqueda
	QString sql;
	int op=ui.comboBox_2->currentIndex();
	switch(op) {
		case 0:
			sql="SELECT a.serie,a.modelo,a.cod_espe FROM maquinas AS a ORDER BY a.modelo";
			ui.tableWidget_17->setColumnHidden(2,false);
			break;
		case 1:
			sql=QString("SELECT a.id_herramienta,a.nombre_herramienta FROM maquinas AS b,herramientas AS a "
				"WHERE a.serie_maquinas=b.serie AND b.serie=%1 ORDER BY b.modelo").arg(idmaquinas[ui.comboBox_3->currentIndex()]);
			ui.tableWidget_17->setColumnHidden(2,true);
			break;
		case 2:
			sql=QString("SELECT a.id_consumible,a.nombre_consumible,a.costo_unitario,a.costo_hora,b.modelo "
				"FROM maquinas AS b,consumible AS a WHERE a.serie_maquinas=b.serie AND b.serie=%1 ORDER BY b.modelo").arg(idmaquinas[ui.comboBox_3->currentIndex()]);
			ui.tableWidget_17->setColumnHidden(2,true);
			break;
		case 3:
			sql=QString("SELECT a.id_serv_basico, a.nombre_servi"
				" FROM serv_basico AS a, maquinas AS b WHERE "
				"a.serie_maquinas=b.serie AND b.serie=%1 ORDER BY b.modelo").arg(idmaquinas[ui.comboBox_3->currentIndex()]);
			ui.tableWidget_17->setColumnHidden(2,true);
			break;
		case 4:
			sql=QString("SELECT a.id_insumo, a.nombre FROM mantenimiento_preventivo AS a, "
				"maquinas AS b WHERE a.serie_maquinas=b.serie AND b.serie=%1 ORDER BY b.modelo").arg(idmaquinas[ui.comboBox_3->currentIndex()]);
			ui.tableWidget_17->setColumnHidden(2,true);
			break;
		case 5:
			sql=QString("SELECT a.id_actividad, a.nombre FROM actividades AS a, categoria_actividades AS b "
				"WHERE a.id_categoria_actividades_categoria_actividades=b.id_categoria_actividades AND b.id_categoria_actividades=%1").arg(idcategoria[ui.comboBox_3->currentIndex()]);
			ui.tableWidget_17->setColumnHidden(2,true);
			break;
		case 6:
			sql=sql="SELECT a.id_categoria_actividades, a.nombre FROM categoria_actividades AS a";
			ui.tableWidget_17->setColumnHidden(2,true);
			break;
		case 7:
			sql=QString("SELECT b.id_actividad, b.nombre FROM cargo AS a,actividades_trabajo AS b "
				"WHERE a.id_cargo=b.id_cargo_cargo AND a.id_cargo=%1 ORDER BY a.nombre").arg(idcargo[ui.comboBox_3->currentIndex()]);
			ui.tableWidget_17->setColumnHidden(2,true);
			break;
		case 8:
			sql="SELECT a.id_cargo,a.nombre FROM cargo AS a";
			ui.tableWidget_17->setColumnHidden(2,true);
			break;
		case 9:
			sql="SELECT id_material, nombre FROM materiales";
			ui.tableWidget_17->setColumnHidden(2,true);
			break;
		case 10:
			sql="SELECT id_servicios, nombre_srevicio FROM servicios_externos";
			ui.tableWidget_17->setColumnHidden(2,true);
			break;
	}
	llenartabla(ui.tableWidget_17,sql);
	llenartabla(ui.tableWidget_17,sql);
	ui.tableWidget_17->removeRow(ui.tableWidget_17->rowCount()-1);
}
void cosmec::mostrarFormlleno(){
	if(ui.tableWidget_17->currentRow()!=-1){
	int filh=ui.tableWidget_17->currentRow();
	QTableWidgetItem *itab1 = ui.tableWidget_17->item(filh,0);
	int idid=QString(itab1->text()).toInt();
	QString sql;
	QImage image;
	QPixmap* pixmap;
	QByteArray im;
	double valor_herra;
	double valor_consu;
	double servicios;
	double manteni;
	double costomaqui;
	double maquina2;
	QString serie;
	QString codespe;
	QString modelo;
	QString costo;
	QString vida;
	QString horas;
	QString presu;
	QString depre;
	QString costo_hora;
	
	QSqlQuery respuesta(cosmecdb);
	QString id_consumible="";
	QString nombre="";
	QString cantidad="";
	QString maquina="";	


	QString id_servicio="";
	QString tiempo_consumo="";
	QString consumo_total="";
	QString consumo_hora="";
	QString costo_unidad="";
	QString costo_hora_servicio="";
	QString unidades="";
	
	QString id_insumo="";
	QString costo_unitario="";
	QString valor_total="";
		
	QString id="";
	QString	actividad="";
	QString	categoria="";

	QString	cargo="";
	QString	horas_mes="";
	QString	costo_actividad="";
	
	QString salario="";

	QString material="";
	QString geometria="";
	QString dimensiones="";

	QString aplicacion;
	QString unidad;
	
		switch(ui.comboBox_2->currentIndex()){
			case 0:
				fmaquina=new formularioMaq();
				fmaquina->ui.pushButton_2->setVisible(false);
				fmaquina->ui.pushButton_3->setVisible(false);
				fmaquina->ui.pushButton->setVisible(false);
				fmaquina->ui.plainTextEdit->setVisible(false);
				fmaquina->ui.lineEdit_7->setVisible(true);//labels y lineEdit de consumo de agua etc etc
				fmaquina->ui.lineEdit_8->setVisible(true);
				fmaquina->ui.lineEdit_9->setVisible(true);
				fmaquina->ui.lineEdit_4->setVisible(true);
				fmaquina->ui.lineEdit_6->setVisible(true);
				fmaquina->ui.label_12->setVisible(true);
				fmaquina->ui.label_13->setVisible(true);
				fmaquina->ui.label_14->setVisible(true);
				fmaquina->ui.label_15->setVisible(true);
				fmaquina->ui.label_16->setVisible(true);
				//imagen
				sql=QString("SELECT encode(imagen,'base64') FROM maquinas WHERE serie=%1").arg(idid);
				im=sql_record(sql,0).toByteArray();
				qDebug()<<"imagen"<<im;
				image = QImage::fromData(QByteArray::fromBase64(im),"PNG");
				fmaquina->ui.label_11->setPixmap(QPixmap::fromImage(image));
				
				//datos extras
				sql=QString("SELECT SUM(costo_hora) FROM herramientas WHERE serie_maquinas=%1 GROUP BY serie_maquinas").arg(idid);
				valor_herra=sql_general(sql,0).toDouble();
				sql=QString("SELECT SUM(costo_hora) FROM consumible WHERE serie_maquinas=%1 GROUP BY serie_maquinas").arg(idid);
				valor_consu=sql_general(sql,0).toDouble();

				sql=QString("SELECT SUM(costo_hora) FROM serv_basico WHERE serie_maquinas=%1").arg(idid);
				servicios=sql_general(sql,0).toDouble();
				sql=QString("SELECT (b.presupuesto_anual/b.horas_trabajo_anual)+(SUM(a.costo_hora)) AS costo_total "
					"FROM mantenimiento_preventivo AS a,maquinas AS b WHERE a.serie_maquinas=b.serie AND b.serie=%1 GROUP BY b.serie").arg(idid);
				manteni=sql_general(sql,0).toDouble();
				sql=QString("SELECT ((2*costo)/(vida_util*horas_trabajo_anual)) FROM maquinas WHERE serie=%1").arg(idid);
				costomaqui=sql_general(sql,0).toDouble();
				manteni=redondear(manteni);
				maquina2=(valor_herra+valor_consu+servicios+manteni+costomaqui);
				maquina2=redondear(maquina2);

				fmaquina->ui.lineEdit_7->setText(QString::number(servicios));
				fmaquina->ui.lineEdit_8->setText(QString::number(valor_herra));
				fmaquina->ui.lineEdit_4->setText(QString::number(valor_consu));
				fmaquina->ui.lineEdit_6->setText(QString::number(manteni));
				fmaquina->ui.lineEdit_9->setText(QString::number(maquina2));
				//
				cosmecdb.open();
				sql=QString("SELECT a.serie,a.cod_espe,a.modelo,a.costo,a.vida_util,a.horas_trabajo_anual,a.deprecicacion, "
					"a.costo_hora,a.presupuesto_anual FROM maquinas AS a WHERE a.serie=%1").arg(idid);
				if(!respuesta.exec(sql)){
					QMessageBox msgBox;
					msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
					msgBox.exec();
				}else{
					while(respuesta.next()){
						serie=respuesta.value(0).toString();
						codespe=respuesta.value(1).toString();
						modelo=respuesta.value(2).toString();
						costo=respuesta.value(3).toString();
						vida=respuesta.value(4).toString();
						horas=respuesta.value(5).toString();
						depre=respuesta.value(6).toString();
						costo_hora=respuesta.value(7).toString();
						presu=respuesta.value(8).toString();
										
					}
					fmaquina->ui.lineEdit->setText(serie);
					fmaquina->ui.lineEdit_2->setText(codespe);
					fmaquina->ui.lineEdit_3->setText(modelo);
					fmaquina->ui.lineEdit_5->setText(depre);
					fmaquina->ui.lineEdit_10->setText(costo_hora);
					fmaquina->ui.doubleSpinBox_2->setValue(QString(costo).toDouble());
					fmaquina->ui.doubleSpinBox_3->setValue(QString(presu).toDouble());
					fmaquina->ui.spinBox->setValue(QString(vida).toInt());
					fmaquina->ui.spinBox_2->setValue(QString(horas).toInt());
				}
				cosmecdb.close();
				fmaquina->show();
				break;
			case 1:
				fherr=new formularioHerr();
				fherr->ui.pushButton_2->setVisible(false);
				fherr->ui.pushButton->setVisible(false);
				fherr->ui.comboBox->setVisible(false);
				cosmecdb.open();
				sql=QString("SELECT a.id_herramienta,a.nombre_herramienta,a.cantidad_anual,a.costo_unitario, "
					"a.vida_util,a.depreciacion,a.costo_hora,b.modelo||' ('||b.cod_espe||')' FROM maquinas AS b,herramientas AS a WHERE a.serie_maquinas=b.serie AND a.id_herramienta=%1 ORDER BY b.modelo").arg(idid);
				if(!respuesta.exec(sql)){
					QMessageBox msgBox;
					msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
					msgBox.exec();
					
				}else{
					while(respuesta.next()){
						fherr->ui.lineEdit_4->setText(respuesta.value(0).toString());
						fherr->ui.lineEdit_5->setText(respuesta.value(1).toString());
						fherr->ui.doubleSpinBox->setValue(respuesta.value(3).toDouble());
						fherr->ui.spinBox->setValue(respuesta.value(4).toInt());
						fherr->ui.lineEdit->setText(respuesta.value(5).toString());
						fherr->ui.lineEdit_2->setText(respuesta.value(6).toString());
						fherr->ui.spinBox_2->setValue(respuesta.value(2).toInt());
						fherr->ui.lineEdit_3->setText(QString::number(respuesta.value(6).toDouble()*respuesta.value(2).toInt()));
						fherr->ui.lineEdit_6->setText(respuesta.value(7).toString());
					}
				}
				cosmecdb.close();
				fherr->show();
				break;
			case 2:
				fcons=new formularioConsumibles();
				fcons->ui.pushButton_2->setVisible(false);
				fcons->ui.pushButton->setVisible(false);
				fcons->ui.comboBox->setVisible(false);
				cosmecdb.open();
				sql=QString("SELECT a.id_consumible,a.nombre_consumible,a.costo_unitario,a.costo_hora,b.modelo||' ('||b.cod_espe||')',a.aplicacion FROM maquinas AS b,consumible AS a WHERE a.serie_maquinas=b.serie AND a.id_consumible=%1 ORDER BY b.modelo").arg(idid);
				if(!respuesta.exec(sql)){
					QMessageBox msgBox;
					msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
					msgBox.exec();
					
				}else{
					while(respuesta.next()){
						id_consumible=respuesta.value(0).toString();
						nombre=respuesta.value(1).toString();
						costo=respuesta.value(2).toString();
						//cantidad=respuesta.value(2).toString();
						costo_hora=respuesta.value(3).toString();
						maquina=respuesta.value(4).toString();	
						aplicacion=respuesta.value(5).toString();
					}
					fcons->ui.lineEdit->setText(id_consumible);
					fcons->ui.lineEdit_2->setText(nombre);
					fcons->ui.doubleSpinBox->setValue(QString(costo).toDouble());
					//fcons->ui.spinBox->setValue(QString(cantidad).toInt());
					//fcons->ui.lineEdit_3->setText(costo_hora);
					fcons->ui.lineEdit_4->setText(maquina);	
					fcons->ui.plainTextEdit->setPlainText(aplicacion);
				}
				cosmecdb.close();
				fcons->show();
				break;
			case 3:
				fser=new formularioServicios();
				fser->ui.pushButton_2->setVisible(false);
				fser->ui.pushButton->setVisible(false);
				fser->ui.comboBox->setVisible(false);
				cosmecdb.open();
				sql=QString("SELECT a.id_serv_basico, a.nombre_servi, a.tipo_consum, a.unidad, a.consumo_serv, a.consumo_hora, "
					"a.costo_consu, a.costo_hora, b.modelo||' ('||b.cod_espe||')' FROM serv_basico AS a, maquinas AS b WHERE a.serie_maquinas=b.serie AND a.id_serv_basico=%1 ORDER BY b.modelo").arg(idid);
				if(!respuesta.exec(sql)){
					QMessageBox msgBox;
					msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
					msgBox.exec();
					
				}else{
					while(respuesta.next()){
						id_servicio=respuesta.value(0).toString();
						nombre=respuesta.value(1).toString();
						tiempo_consumo=respuesta.value(2).toString();
						consumo_total=respuesta.value(4).toString();
						consumo_hora=respuesta.value(5).toString();
						costo_unidad=respuesta.value(6).toString();
						costo_hora_servicio=respuesta.value(7).toString();
						unidades=respuesta.value(3).toString();
						maquina=respuesta.value(8).toString();	
					}
					fser->ui.lineEdit->setText(id_servicio);
					fser->ui.lineEdit_2->setText(nombre);
					fser->ui.spinBox->setValue(QString(tiempo_consumo).toInt());
					fser->ui.doubleSpinBox->setValue(QString(consumo_total).toDouble());
					fser->ui.lineEdit_3->setText(consumo_hora);
					fser->ui.doubleSpinBox_2->setValue(QString(costo_unidad).toDouble());
					fser->ui.lineEdit_4->setText(costo_hora_servicio);
					fser->ui.lineEdit_5->setText(unidades);
					fser->ui.lineEdit_6->setText(maquina);	
				}
				cosmecdb.close();
				fser->show();
				break;
			case 4:
				finsumo=new formularioInsumos();
				finsumo->ui.pushButton_2->setVisible(false);
				finsumo->ui.pushButton->setVisible(false);
				finsumo->ui.comboBox->setVisible(false);
				cosmecdb.open();
				sql=QString("SELECT a.id_insumo, a.nombre, a.costo_unitario, a.cantidad_anual, "
					"a.valor_total, a.costo_hora, b.modelo||' ('||b.cod_espe||')' FROM mantenimiento_preventivo AS a,maquinas AS b WHERE a.serie_maquinas=b.serie AND a.id_insumo=%1 ORDER BY b.modelo").arg(idid);
				if(!respuesta.exec(sql)){
					QMessageBox msgBox;
					msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
					msgBox.exec();
				
				}else{
					while(respuesta.next()){
						id_insumo=respuesta.value(0).toString();
						nombre=respuesta.value(1).toString();
						costo_unitario=respuesta.value(2).toString();
						cantidad=respuesta.value(3).toString();
						valor_total=respuesta.value(4).toString();
						costo_hora=respuesta.value(5).toString();
						maquina=respuesta.value(6).toString();
					}
					finsumo->ui.lineEdit->setText(id_insumo);
					finsumo->ui.lineEdit_2->setText(nombre);
					finsumo->ui.lineEdit_3->setText(valor_total);
					finsumo->ui.lineEdit_4->setText(costo_hora);
					finsumo->ui.lineEdit_5->setText(maquina);
					finsumo->ui.doubleSpinBox->setValue(QString(costo_unitario).toDouble());
					finsumo->ui.spinBox->setValue(QString(cantidad).toInt());
				}
				cosmecdb.close();
				finsumo->show();
				break;
			case 5:
				fActEmp=new formularioActEmpresa();
				fActEmp->ui.pushButton_2->setVisible(false);
				fActEmp->ui.pushButton->setVisible(false);
				fActEmp->ui.comboBox->setVisible(false);
				cosmecdb.open();
				sql=QString("SELECT a.id_actividad, a.nombre, a.costo_hora, b.nombre AS cargo FROM actividades AS a, categoria_actividades AS b WHERE a.id_categoria_actividades_categoria_actividades=b.id_categoria_actividades AND a.id_actividad=%1").arg(idid);
				if(!respuesta.exec(sql)){
					QMessageBox msgBox;
					msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
					msgBox.exec();
					
				}else{
					while(respuesta.next()){
						id=respuesta.value(0).toString();
						actividad=respuesta.value(1).toString();
						costo_hora=respuesta.value(2).toString();
						categoria=respuesta.value(3).toString();
					}
					fActEmp->ui.lineEdit->setText(id);
					fActEmp->ui.lineEdit_2->setText(actividad);
					fActEmp->ui.lineEdit_3->setText(categoria);
					fActEmp->ui.doubleSpinBox->setValue(QString(costo_hora).toDouble());	
				}
				cosmecdb.close();
				fActEmp->show();
				break;
			case 6:
				fcat=new formularioCategorias();
				fcat->ui.pushButton_2->setVisible(false);
				fcat->ui.pushButton->setVisible(false);
				cosmecdb.open();
				sql=QString("SELECT a.id_categoria_actividades, a.nombre FROM categoria_actividades AS a WHERE  a.id_categoria_actividades=%1").arg(idid);
				if(!respuesta.exec(sql)){
					QMessageBox msgBox;
					msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
					msgBox.exec();
				
				}else{
					while(respuesta.next()){
						id=respuesta.value(0).toString();
						categoria=respuesta.value(1).toString();
					}
					fcat->ui.lineEdit->setText(id);
					fcat->ui.lineEdit_2->setText(categoria);
				}
				cosmecdb.close();
				fcat->show();
				break;
			case 7:
				fActTrab=new formularioActTrabajo();
				fActTrab->ui.pushButton_2->setVisible(false);
				fActTrab->ui.pushButton->setVisible(false);
				fActTrab->ui.comboBox->setVisible(false);
				cosmecdb.open();
				sql=QString("SELECT b.id_actividad, b.nombre, a.nombre AS nombre_cargo, b.hora_mensual, b.costo_mes, b.costo_hora FROM cargo AS a,actividades_trabajo AS b WHERE a.id_cargo=b.id_cargo_cargo AND b.id_actividad=%1 ORDER BY a.nombre").arg(idid);
				if(!respuesta.exec(sql)){
					QMessageBox msgBox;
					msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
					msgBox.exec();
				
				}else{
					while(respuesta.next()){
						id=respuesta.value(0).toString();
						nombre=respuesta.value(1).toString();
						cargo=respuesta.value(2).toString();
						horas_mes=respuesta.value(3).toString();
						costo_actividad=respuesta.value(4).toString();
						costo_hora=respuesta.value(5).toString();
					}
					fActTrab->ui.lineEdit->setText(id);
					fActTrab->ui.lineEdit_2->setText(nombre);
					fActTrab->ui.lineEdit_3->setText(costo_hora);
					fActTrab->ui.lineEdit_5->setText(cargo);
					fActTrab->ui.spinBox->setValue(QString(horas_mes).toInt());
					fActTrab->ui.doubleSpinBox->setValue(QString(costo_actividad).toDouble());
				}
				cosmecdb.close();
				fActTrab->show();
				break;
			case 8:
				fcargo=new formularioCargos();
				fcargo->ui.pushButton_2->setVisible(false);
				fcargo->ui.pushButton->setVisible(false);
				cosmecdb.open();
				sql=QString("SELECT a.id_cargo,a.nombre,a.salario FROM cargo AS a WHERE a.id_cargo=%1").arg(idid);
				if(!respuesta.exec(sql)){
					QMessageBox msgBox;
					msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
					msgBox.exec();
					
				}else{
					while(respuesta.next()){
						id=respuesta.value(0).toString();
						nombre=respuesta.value(1).toString();
						salario=respuesta.value(2).toString();	
					}
					fcargo->ui.lineEdit->setText(id);
					fcargo->ui.lineEdit_2->setText(nombre);
					fcargo->ui.doubleSpinBox->setValue(QString(salario).toDouble());
				}
				cosmecdb.close();
				fcargo->show();
				break;
			case 9:
				fmateriales=new formularioMateriales();
				fmateriales->ui.pushButton_2->setVisible(false);
				fmateriales->ui.pushButton->setVisible(false);
				cosmecdb.open();
				sql=QString("SELECT id_material, nombre, geometria, dimencion, costo,unidades,aplicacion"
					" FROM materiales WHERE id_material=%1").arg(idid);
				if(!respuesta.exec(sql)){
					QMessageBox msgBox;
					msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
					msgBox.exec();
					
				}else{
					while(respuesta.next()){
						id=respuesta.value(0).toString();
						material=respuesta.value(1).toString();
						geometria=respuesta.value(2).toString();
						dimensiones=respuesta.value(3).toString();
						costo=respuesta.value(4).toString();
						unidad=respuesta.value(5).toString();
						aplicacion=respuesta.value(6).toString();
					}
					fmateriales->ui.lineEdit->setText(id);
					fmateriales->ui.lineEdit_2->setText(material);
					fmateriales->ui.lineEdit_3->setText(geometria);
					fmateriales->ui.lineEdit_4->setText(dimensiones);
					fmateriales->ui.lineEdit_5->setText(unidad);
					fmateriales->ui.doubleSpinBox->setValue(QString(costo).toDouble());
					fmateriales->ui.plainTextEdit->setPlainText(aplicacion);
				}
				cosmecdb.close();
				fmateriales->show();
				break;
			case 10:
				fexternos=new formularioSerExternos();
				fexternos->ui.pushButton_2->setVisible(false);
				fexternos->ui.pushButton->setVisible(false);
				cosmecdb.open();
				sql=QString("SELECT id_servicios, nombre_srevicio, costo_hora FROM servicios_externos WHERE id_servicios=%1").arg(idid);
				if(!respuesta.exec(sql)){
					QMessageBox msgBox;
					msgBox.setText("Error al consultar datos"+respuesta.lastError().databaseText());
					msgBox.exec();
					
				}else{
					while(respuesta.next()){
						id=respuesta.value(0).toString();
						nombre=respuesta.value(1).toString();
						costo=respuesta.value(2).toString();
					}
					fexternos->ui.lineEdit->setText(id);
					fexternos->ui.lineEdit_2->setText(nombre);
					fexternos->ui.doubleSpinBox->setValue(QString(costo).toDouble());
				}
				cosmecdb.close();
				fexternos->show();
				break;
		}
	}else{
		QMessageBox msgBox;
		msgBox.setText("Escoja un elemento de la tabla");
		msgBox.exec();
	}
}
void cosmec::limpiarFMaq(){
	fmaquina->ui.lineEdit->setText("");
	fmaquina->ui.lineEdit_2->setText("");
	fmaquina->ui.lineEdit_3->setText("");
	fmaquina->ui.lineEdit_4->setText("");
	fmaquina->ui.lineEdit_5->setText("");
	fmaquina->ui.lineEdit_6->setText("");
	fmaquina->ui.lineEdit_10->setText("");
	fmaquina->ui.lineEdit_7->setText("");
	fmaquina->ui.lineEdit_8->setText("");
	fmaquina->ui.lineEdit_9->setText("");
	fmaquina->ui.doubleSpinBox_2->setValue(0);
	fmaquina->ui.doubleSpinBox_3->setValue(0);
	fmaquina->ui.spinBox->setValue(0);
	fmaquina->ui.spinBox_2->setValue(0);
	fmaquina->ui.label_11->setText("");
	fmaquina->ui.plainTextEdit->setPlainText("");
}
void cosmec::llenarcombomaq(QString sql,QComboBox *combo){
	combo->clear();
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	respuesta.exec(sql);
	record = respuesta.record();
	tamquery1=respuesta.size();
	idmaquinas=new int[tamquery1];
	int fila=0;
	while(respuesta.next()){
		QString uno;
		idmaquinas[fila]=respuesta.value(0).toInt();
		uno=respuesta.value(1).toString()+"("+respuesta.value(2).toString()+")";
		combo->addItem(uno);
		fila++;
	}
}
void cosmec::llenarcombocat(QString sql,QComboBox *combo){
	combo->clear();
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	respuesta.exec(sql);
	record = respuesta.record();
	tamquery1=respuesta.size();
	idcategoria=new int[tamquery1];
	int fila=0;
	while(respuesta.next()){
		QString uno;
		idcategoria[fila]=respuesta.value(0).toInt();
		uno=respuesta.value(1).toString();
		combo->addItem(uno);
		fila++;
	}
}
void cosmec::limpiarFHerr(){
	fherr->ui.lineEdit_4->setText("");
	fherr->ui.lineEdit_5->setText("");
	fherr->ui.lineEdit->setText("");
	fherr->ui.lineEdit_2->setText("");
	fherr->ui.lineEdit_3->setText("");
	fherr->ui.lineEdit_6->setText("");
	fherr->ui.spinBox->setValue(0);
	fherr->ui.spinBox_2->setValue(0);
	fherr->ui.doubleSpinBox->setValue(0);
}
void cosmec::limpiarFCons(){
	fcons->ui.lineEdit->setText("");
	fcons->ui.lineEdit_2->setText("");
	//fcons->ui.lineEdit_3->setText("");
	fcons->ui.lineEdit_4->setText("");
	fcons->ui.doubleSpinBox->setValue(0);
	//fcons->ui.spinBox->setValue(0);
	fcons->ui.plainTextEdit->setPlainText("");
}
void cosmec::limpiarFser(){
	fser->ui.lineEdit->setText("");
	fser->ui.lineEdit_2->setText("");
	fser->ui.lineEdit_3->setText("");
	fser->ui.lineEdit_4->setText("");
	fser->ui.lineEdit_5->setText("");
	fser->ui.lineEdit_6->setText("");
	fser->ui.doubleSpinBox->setValue(0);
	fser->ui.doubleSpinBox_2->setValue(0);
	fser->ui.spinBox->setValue(0);
}
void cosmec::limpiarFInsumos(){
	finsumo->ui.lineEdit->setText("");
	finsumo->ui.lineEdit_2->setText("");
	finsumo->ui.lineEdit_3->setText("");
	finsumo->ui.lineEdit_4->setText("");
	finsumo->ui.lineEdit_5->setText("");
	finsumo->ui.doubleSpinBox->setValue(0);
	finsumo->ui.spinBox->setValue(0);
}
void cosmec::limpiarFActE(){
	fActEmp->ui.lineEdit->setText("");
	fActEmp->ui.lineEdit_2->setText("");
	fActEmp->ui.lineEdit_3->setText("");
	fActEmp->ui.doubleSpinBox->setValue(0);
}
void cosmec::limpiarFCat(){
	fcat->ui.lineEdit->setText("");
	fcat->ui.lineEdit_2->setText("");
}
void cosmec::limpiarFActTrab(){
	fActTrab->ui.lineEdit->setText("");
	fActTrab->ui.lineEdit_2->setText("");
	fActTrab->ui.lineEdit_3->setText("");
	fActTrab->ui.lineEdit_5->setText("");
	fActTrab->ui.doubleSpinBox->setValue(0);
	fActTrab->ui.spinBox->setValue(0);

}
void cosmec::limpiarFCargo(){
	fcargo->ui.lineEdit->setText("");
	fcargo->ui.lineEdit_2->setText("");
	fcargo->ui.doubleSpinBox->setValue(0);
}
void cosmec::limpiarFMateriales(){
	fmateriales->ui.lineEdit->setText("");
	fmateriales->ui.lineEdit_2->setText("");
	fmateriales->ui.lineEdit_3->setText("");
	fmateriales->ui.lineEdit_4->setText("");
	fmateriales->ui.doubleSpinBox->setValue(0);
	fmateriales->ui.lineEdit_5->setText("");
	fmateriales->ui.plainTextEdit->setPlainText("");
}
void cosmec::limpiarFSexternos(){
	fexternos->ui.lineEdit->setText("");
	fexternos->ui.lineEdit_2->setText("");
	fexternos->ui.doubleSpinBox->setValue(0);
}
int cosmec::buscarid(int *aux, int id,int tam){
	int index;
	for(int a=0;a<tam;a++){
		if(aux[a]==id){
			index=a;
		}
	}
	return index;
}
void cosmec::llenarcombocargo(QString sql,QComboBox *combo){
	combo->clear();
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	respuesta.exec(sql);
	record = respuesta.record();
	tamquery1=respuesta.size();
	idcargo=new int[tamquery1];
	int fila=0;
	while(respuesta.next()){
		QString uno;
		idcargo[fila]=respuesta.value(0).toInt();
		uno=respuesta.value(1).toString();
		combo->addItem(uno);
		fila++;
	}
}

void cosmec::centrarItem(QTableWidgetItem *elemento){
	elemento->setTextAlignment(Qt::AlignHCenter);
}

//CALCULOS EN TIEMPO REAL
void cosmec::costo_hora_consumibles(double valor){
	if(valor !=0){
		int horas_maq=sql_maquina(idmaquinas[fcons->ui.comboBox->currentIndex()],5).toInt();
		double resultado=redondear((valor*1)/(horas_maq));
		//fcons->ui.lineEdit_3->setText(QString::number(resultado));
	}
}
void cosmec::costo_hora_consumibles2(int cantidad){
	if(cantidad!=0 && fcons->ui.doubleSpinBox->value()!=0){
		int horas_maq=sql_maquina(idmaquinas[fcons->ui.comboBox->currentIndex()],5).toInt();
		double resultado=redondear((cantidad*fcons->ui.doubleSpinBox->value())/(horas_maq));
		//fcons->ui.lineEdit_3->setText(QString::number(resultado));
	}

}
void cosmec::costo_hora_consumibles3( int maq){
	if(fcons->ui.doubleSpinBox->value()!=0){
		int horas_maq=sql_maquina(idmaquinas[maq],5).toInt();
		double resultado=redondear((fcons->ui.doubleSpinBox->value()*1)/(horas_maq));
		//fcons->ui.lineEdit_3->setText(QString::number(resultado));
	}
}
void cosmec::depre_herramientas(double costo){
	int vida=fherr->ui.spinBox->value();
	int cantidad=fherr->ui.spinBox_2->value();
	if(vida!=0 && costo!=0 &&cantidad!=0){
		double resultado=redondear(costo*cantidad/vida);
		fherr->ui.lineEdit->setText(QString::number(resultado));
	}
}
void cosmec::depre_herramientas2(int vida){
	double costo=fherr->ui.doubleSpinBox->value();
	int cantidad=fherr->ui.spinBox_2->value();
	if(vida!=0 && costo!=0 &&cantidad!=0){
		double resultado=redondear(costo*cantidad/vida);
		fherr->ui.lineEdit->setText(QString::number(resultado));
	}
}
void cosmec::depre_herramientas3(int cantidad){
	int vida=fherr->ui.spinBox->value();
	double costo=fherr->ui.doubleSpinBox->value();
	if(vida!=0 && costo!=0 &&cantidad!=0){
		double resultado=redondear(costo*cantidad/vida);
		fherr->ui.lineEdit->setText(QString::number(resultado));
	}
}

void cosmec::costo_hora_herramientas(double costo){
	int horas_maq=sql_maquina(idmaquinas[fherr->ui.comboBox->currentIndex()],5).toInt();
	int cantidad=fherr->ui.spinBox_2->value();
	if(costo!=0 && cantidad!=0 && horas_maq!=0){
		double resultado=redondear(costo*cantidad/horas_maq);
		fherr->ui.lineEdit_2->setText(QString::number(resultado));
	}
}
void cosmec::costo_hora_herramientas2(int cantidad){
	int horas_maq=sql_maquina(idmaquinas[fherr->ui.comboBox->currentIndex()],5).toInt();
	double costo=fherr->ui.doubleSpinBox->value();
	if(costo!=0 && cantidad!=0 && horas_maq!=0){
		double resultado=redondear(costo*cantidad/horas_maq);
		fherr->ui.lineEdit_2->setText(QString::number(resultado));
	}
}
void cosmec::costo_hora_herramientas3(int maq){
	int horas_maq=sql_maquina(idmaquinas[maq],5).toInt();
	double costo=fherr->ui.doubleSpinBox->value();
	int cantidad=fherr->ui.spinBox_2->value();
	if(costo!=0 && cantidad!=0 && horas_maq!=0){
		double resultado=redondear(costo*cantidad/horas_maq);
		fherr->ui.lineEdit_2->setText(QString::number(resultado));
	}
}
void cosmec::costo_total_herramientas(double costo){
	int horas_maq=sql_maquina(idmaquinas[fherr->ui.comboBox->currentIndex()],5).toInt();
	int cantidad=fherr->ui.spinBox_2->value();
	int vida=fherr->ui.spinBox->value();
	if(costo!=0 && vida!=0 &&cantidad!=0){
		double resultado=redondear((costo*cantidad/horas_maq)+(costo*cantidad/(horas_maq*vida)));
		fherr->ui.lineEdit_3->setText(QString::number(resultado));
	}
}
void cosmec::costo_total_herramientas2(int cantidad){
	int horas_maq=sql_maquina(idmaquinas[fherr->ui.comboBox->currentIndex()],5).toInt();
	double costo=fherr->ui.doubleSpinBox->value();
	int vida=fherr->ui.spinBox->value();
	if(costo!=0 && vida!=0 &&cantidad!=0){
		double resultado=redondear((costo*cantidad/horas_maq)+(costo*cantidad/(horas_maq*vida)));
		fherr->ui.lineEdit_3->setText(QString::number(resultado));
	}
}
void cosmec::costo_total_herramientas3(int maq){
	int horas_maq=sql_maquina(idmaquinas[maq],5).toInt();
	double costo=fherr->ui.doubleSpinBox->value();
	int cantidad=fherr->ui.spinBox_2->value();
	int vida=fherr->ui.spinBox->value();
	if(costo!=0 && vida!=0 &&cantidad!=0){
		double resultado=redondear((costo*cantidad/horas_maq)+(costo*cantidad/(horas_maq*vida)));
		fherr->ui.lineEdit_3->setText(QString::number(resultado));
	}
}
void cosmec::costo_total_herramientas4(int vida){
	int horas_maq=sql_maquina(idmaquinas[fherr->ui.comboBox->currentIndex()],5).toInt();
	double costo=fherr->ui.doubleSpinBox->value();
	int cantidad=fherr->ui.spinBox_2->value();
	if(costo!=0 && vida!=0 &&cantidad!=0){
		double resultado=redondear((costo*cantidad/horas_maq)+(costo*cantidad/(horas_maq*vida)));
		fherr->ui.lineEdit_3->setText(QString::number(resultado));
	}
}
void cosmec::valor_total_insumo(double unitario){
	int cantidad=finsumo->ui.spinBox->value();
	if(unitario!=0 && cantidad!=0){
		double resultado=redondear(unitario*cantidad);
		finsumo->ui.lineEdit_3->setText(QString::number(resultado));
	}
}
void cosmec::valor_total_insumo2(int cantidad){
	double unitario=finsumo->ui.doubleSpinBox->value();
	if(unitario!=0 && cantidad!=0){
		double resultado=redondear(unitario*cantidad);
		finsumo->ui.lineEdit_3->setText(QString::number(resultado));
	}
}

void cosmec::costo_hora_insumo(double unitario){
	int cantidad=finsumo->ui.spinBox->value();
	int horas_maq=sql_maquina(idmaquinas[finsumo->ui.comboBox->currentIndex()],5).toInt();
	if(unitario!=0 && cantidad!=0){
		double resultado=redondear(unitario*cantidad/horas_maq);
		finsumo->ui.lineEdit_4->setText(QString::number(resultado));
	}

}
void cosmec::costo_hora_insumo2(int cantidad){
	double unitario=finsumo->ui.doubleSpinBox->value();
	int horas_maq=sql_maquina(idmaquinas[finsumo->ui.comboBox->currentIndex()],5).toInt();
	if(unitario!=0 && cantidad!=0){
		double resultado=redondear(unitario*cantidad/horas_maq);
		finsumo->ui.lineEdit_4->setText(QString::number(resultado));
	}
}
void cosmec::costo_hora_insumo3(int maq){
	double unitario=finsumo->ui.doubleSpinBox->value();
	int cantidad=finsumo->ui.spinBox->value();
	int horas_maq=sql_maquina(idmaquinas[maq],5).toInt();
	if(unitario!=0 && cantidad!=0){
		double resultado=redondear(unitario*cantidad/horas_maq);
		finsumo->ui.lineEdit_4->setText(QString::number(resultado));
	}
}
void cosmec::costo_hora_actrab(int horasact){
	int fila=fActTrab->ui.comboBox->currentIndex();
	int id_cargo=idcargo[fila];
	QString sql=QString("SELECT salario FROM cargo WHERE id_cargo=%1").arg(id_cargo);;
	double salario_cargo=sql_general(sql,0).toDouble();
	if(horasact!=0){
		double resultado=redondear((salario_cargo/160)*horasact);
		fActTrab->ui.lineEdit_3->setText(QString::number(redondear(salario_cargo/160)));
		fActTrab->ui.doubleSpinBox->setValue(resultado);
	}
}
void cosmec::costo_hora_actrab2(int car){
	int id_cargo=idcargo[car];
	QString sql=QString("SELECT salario FROM cargo WHERE id_cargo=%1").arg(id_cargo);;
	double salario_cargo=sql_general(sql,0).toDouble();
	int horasact=fActTrab->ui.spinBox->value();
	if(horasact!=0){
		double resultado=redondear((salario_cargo/160)*horasact);
		fActTrab->ui.lineEdit_3->setText(QString::number(redondear(salario_cargo/160)));
		fActTrab->ui.doubleSpinBox->setValue(resultado);
	}
}
void cosmec::limpiarRep(){
	ui.checkherrg->setCheckable(false);
	ui.checkherrg->update();
	ui.checkherrg->setCheckable(true);

	ui.checkherr->setCheckable(false);
	ui.checkherr->update();
	ui.checkherr->setCheckable(true);

	ui.checkconsug->setCheckable(false);
	ui.checkconsug->update();
	ui.checkconsug->setCheckable(true);

	ui.checkconsu->setCheckable(false);
	ui.checkconsu->update();
	ui.checkconsu->setCheckable(true);

	ui.checkmantg->setCheckable(false);
	ui.checkmantg->update();
	ui.checkmantg->setCheckable(true);

	ui.checkmant->setCheckable(false);
	ui.checkmant->update();
	ui.checkmant->setCheckable(true);

	ui.checkmaqg->setCheckable(false);
	ui.checkmaqg->update();
	ui.checkmaqg->setCheckable(true);

	ui.checkmanog->setCheckable(false);
	ui.checkmanog->update();
	ui.checkmanog->setCheckable(true);

	ui.checkmano->setCheckable(false);
	ui.checkmano->update();
	ui.checkmano->setCheckable(true);

	ui.checkactivg->setCheckable(false);
	ui.checkactivg->update();
	ui.checkactivg->setCheckable(true);

	ui.checkactiv->setCheckable(false);
	ui.checkactiv->update();
	ui.checkactiv->setCheckable(true);

	ui.checkbasg->setCheckable(false);
	ui.checkbasg->update();
	ui.checkbasg->setCheckable(true);

	ui.checkbas->setCheckable(false);
	ui.checkbas->update();
	ui.checkbas->setCheckable(true);
}
void cosmec::limpiarExcel(){
	ui.radioButton_3->setCheckable(false);
	ui.radioButton_3->update();
	ui.radioButton_3->setCheckable(true);

	ui.radioButton_4->setCheckable(false);
	ui.radioButton_4->update();
	ui.radioButton_4->setCheckable(true);

	ui.radioButton_12->setCheckable(false);
	ui.radioButton_12->update();
	ui.radioButton_12->setCheckable(true);

	ui.radioButton_6->setCheckable(false);
	ui.radioButton_6->update();
	ui.radioButton_6->setCheckable(true);

	ui.radioButton_10->setCheckable(false);
	ui.radioButton_10->update();
	ui.radioButton_10->setCheckable(true);

	ui.radioButton_5->setCheckable(false);
	ui.radioButton_5->update();
	ui.radioButton_5->setCheckable(true);

	ui.radioButton_13->setCheckable(false);
	ui.radioButton_13->update();
	ui.radioButton_13->setCheckable(true);

	ui.radioButton_7->setCheckable(false);
	ui.radioButton_7->update();
	ui.radioButton_7->setCheckable(true);

	ui.radioButton_11->setCheckable(false);
	ui.radioButton_11->update();
	ui.radioButton_11->setCheckable(true);

	ui.radioButton_9->setCheckable(false);
	ui.radioButton_9->update();
	ui.radioButton_9->setCheckable(true);

	ui.radioButton_14->setCheckable(false);
	ui.radioButton_14->update();
	ui.radioButton_14->setCheckable(true);

	ui.radioButton_8->setCheckable(false);
	ui.radioButton_8->update();
	ui.radioButton_8->setCheckable(true);

	ui.radioButton->setCheckable(false);
	ui.radioButton->update();
	ui.radioButton->setCheckable(true);
}
void cosmec::botonLimpiarRpt(){
	limpiarRep();
}
void cosmec::botonLimpiarExcel(){
	limpiarExcel();
}
void cosmec::modificarCotizacion(){
	borrartabla(ui.tableWidget_12);
	borrartabla(ui.tableWidget_24);
	QTableWidgetItem *itemMaquina;
	QTableWidgetItem *itemDesc;
	QTableWidgetItem *itemCate;
	QTableWidgetItem *itemcant;
	QTableWidgetItem *itemIdMaq;
	QTableWidgetItem *itemIdDesc;

	QString serie;
	QString cantidad_maquina;
	QString nombre_maquina;
	double mano_obra;
	double cant_mano_obra;
	QString nombre_mat;
	QString cant_mat;
	QString id_mat;

	QString cant_cons;
	QString id_cons;
	QString nombre_cons;//<--

	QString cant_activi;
	QString id_activi;
	QString nombre_activi;

	QString cant_serv;
	QString id_serv;
	QString nombre_serv;

	QString sql;
	int num;

	QSqlQuery cot(cosmecdb);
	QSqlQuery mac(cosmecdb);
	QSqlQuery aux(cosmecdb);
	QDate qdate;

	if(ui.checkBox_clonar->isChecked()){
		sql="SELECT setval('cotizacion_numero_seq',(SELECT nextval('cotizacion_numero_seq'))-1)";
		num=sql_general(sql,0).toInt()+1;
		ui.label_27->setText(QString::number(num));
		modificar=false;
	}else{
		ui.label_27->setText(QString::number(numerocoti));//<-aqui if chekbox
		modificar=true;
	}

	cosmecdb.open();
	sql=QString("SELECT nombre, dirigido, fecha, ruc, proyecto, ciudad, telefono, "
		"direccion, forma_pago, lugar_entrega, "
		"tiempo_entrega, duracion_cotizacion,descuento, " 
		"piezas FROM cotizacion WHERE numero=%1").arg(numerocoti);

	if(!cot.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al agregar datos :"+cot.lastError().databaseText());
		msgBox.exec();
	}else{
		while(cot.next()){
			ui.lineEdit_2->setText(cot.value(0).toString());
			ui.lineEdit_11->setText(cot.value(1).toString());
			ui.lineEdit_22->setText(cot.value(2).toString());
			ui.lineEdit->setText(cot.value(3).toString());
			ui.lineEdit_12->setText(cot.value(4).toString());
			ui.lineEdit_13->setText(cot.value(5).toString());
			ui.lineEdit_4->setText(cot.value(6).toString());
			ui.lineEdit_3->setText(cot.value(7).toString());
			ui.lineEdit_14->setText(cot.value(8).toString());
			ui.lineEdit_17->setText(cot.value(9).toString());
			ui.lineEdit_15->setText(cot.value(10).toString());
			ui.lineEdit_16->setText(cot.value(11).toString());
			ui.doubleSpinBox_6->setValue(cot.value(12).toDouble());
			ui.spinBox->setValue(cot.value(13).toInt());
		}
	}

	mac.exec(QString("SELECT a.serie_maquinas, cantidad, b.modelo FROM  maquina_cotizacion AS a,maquinas AS b WHERE a.serie_maquinas=b.serie AND a.numero_cotizacion=%1").arg(numerocoti));
	while(mac.next()){
		serie=mac.value(0).toString();
		cantidad_maquina=mac.value(1).toString();
		nombre_maquina=mac.value(2).toString();
		//Insertar maquina
		ui.tableWidget_12->insertRow(ui.tableWidget_12->rowCount());

		itemMaquina = new QTableWidgetItem;
		itemDesc = new QTableWidgetItem;
		itemCate = new QTableWidgetItem;
		itemcant = new QTableWidgetItem;
		itemIdMaq = new QTableWidgetItem;
		itemIdDesc = new QTableWidgetItem;

		itemMaquina->setText(nombre_maquina);
		itemDesc->setText(nombre_maquina);
		itemCate->setText("Máquina");
		itemcant->setText(cantidad_maquina);
		itemIdMaq->setText(serie); //id maquina
		itemIdDesc->setText(serie); //id maquina

		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,0,itemMaquina);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,1,itemIdMaq);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,2,itemDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,3,itemIdDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,4,itemCate);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,5,itemcant);

		//mano de obra
		sql=QString("SELECT valor_mano, cantidad_mano FROM cotizacion_manoobra WHERE serie_maquina=%1 AND numero_cotizacion=%2").arg(serie).arg(numerocoti);
		cant_mano_obra=sql_general(sql,1).toDouble();

		ui.tableWidget_12->insertRow(ui.tableWidget_12->rowCount());

		itemMaquina = new QTableWidgetItem;
		itemDesc = new QTableWidgetItem;
		itemCate = new QTableWidgetItem;
		itemcant = new QTableWidgetItem;
		itemIdMaq = new QTableWidgetItem;
		itemIdDesc = new QTableWidgetItem;

		itemMaquina->setText(nombre_maquina);
		itemDesc->setText("Mano de obra");
		itemCate->setText("Mano de obra");
		itemcant->setText(QString::number(cant_mano_obra));
		itemIdMaq->setText(serie); //id maquina
		itemIdDesc->setText("Sin Id"); //id maquina

		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,0,itemMaquina);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,1,itemIdMaq);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,2,itemDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,3,itemIdDesc);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,4,itemCate);
		ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,5,itemcant);

		//Materiales
		cosmecdb.open();
		sql=QString("SELECT a.cantidad, b.id_material, b.nombre FROM cotizacion_material AS a,materiales AS b WHERE a.id_material_materiales=b.id_material AND a.serie_maquinas=%1 AND a.numero_cotizacion=%2").arg(serie).arg(numerocoti);
		if(!aux.exec(sql)){
			QMessageBox msgBox;
			msgBox.setText("Error al agregar datos :"+aux.lastError().databaseText());
			msgBox.exec();
		}else{
			while(aux.next()){
				//--------------------------------------
				cant_mat=aux.value(0).toString();
				id_mat=aux.value(1).toString();
				nombre_mat=aux.value(2).toString();
				//--------------------------------------
				ui.tableWidget_12->insertRow(ui.tableWidget_12->rowCount());

				itemMaquina = new QTableWidgetItem;
				itemDesc = new QTableWidgetItem;
				itemCate = new QTableWidgetItem;
				itemcant = new QTableWidgetItem;
				itemIdMaq = new QTableWidgetItem;
				itemIdDesc = new QTableWidgetItem;

				itemMaquina->setText(nombre_maquina);
				itemDesc->setText(nombre_mat);
				itemCate->setText("Material");
				itemcant->setText(cant_mat);
				itemIdMaq->setText(serie); //id maquina
				itemIdDesc->setText(id_mat); //id maquina

				ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,0,itemMaquina);
				ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,1,itemIdMaq);
				ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,2,itemDesc);
				ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,3,itemIdDesc);
				ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,4,itemCate);
				ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,5,itemcant);
			}
		}
		cosmecdb.close();

		//Consumibles
		cosmecdb.open();
		sql=QString("SELECT a.cantidad, b.id_consumible, b.nombre_consumible FROM consumibles_cotizacion AS a, consumible AS b WHERE a.id_consumible_consumible=b.id_consumible AND b.serie_maquinas=%1 AND a.numero_cotizacion=%2").arg(serie).arg(numerocoti);
		if(!aux.exec(sql)){
			QMessageBox msgBox;
			msgBox.setText("Error al agregar datos :"+aux.lastError().databaseText());
			msgBox.exec();
		}else{
			while(aux.next()){
				//--------------------------------------
				cant_cons=aux.value(0).toString();
				id_cons=aux.value(1).toString();
				nombre_cons=aux.value(2).toString();//<--
				//--------------------------------------
				ui.tableWidget_12->insertRow(ui.tableWidget_12->rowCount());

				QTableWidgetItem *itemMaquina = new QTableWidgetItem;
				QTableWidgetItem *itemDesc = new QTableWidgetItem;
				QTableWidgetItem *itemCate = new QTableWidgetItem;
				QTableWidgetItem *itemcant = new QTableWidgetItem;
				QTableWidgetItem *itemIdMaq = new QTableWidgetItem;
				QTableWidgetItem *itemIdDesc = new QTableWidgetItem;

				itemMaquina->setText(nombre_maquina);
				itemDesc->setText(nombre_cons);
				itemCate->setText("Consumible");
				itemcant->setText(cant_cons);
				itemIdMaq->setText(serie);
				itemIdDesc->setText(id_cons);

				ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,0,itemMaquina);
				ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,1,itemIdMaq);
				ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,2,itemDesc);
				ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,3,itemIdDesc);
				ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,4,itemCate);
				ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,5,itemcant);
			}
		}
		cosmecdb.close();
	}

	//Actividades
	cosmecdb.open();
	sql=QString("SELECT a.cantidad, b.id_actividad, b.nombre FROM actividades_cotizacion AS a,actividades AS b WHERE a.id_actividad_actividades=b.id_actividad AND a.numero_cotizacion=%2").arg(numerocoti);
	if(!aux.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al agregar datos :"+aux.lastError().databaseText());
		msgBox.exec();
	}else{
		while(aux.next()){
			//--------------------------------------
			cant_activi=aux.value(0).toString();
			id_activi=aux.value(1).toString();
			nombre_activi=aux.value(2).toString();
			//--------------------------------------
			ui.tableWidget_12->insertRow(ui.tableWidget_12->rowCount());

			QTableWidgetItem *itemMaquina = new QTableWidgetItem;
			QTableWidgetItem *itemDesc = new QTableWidgetItem;
			QTableWidgetItem *itemCate = new QTableWidgetItem;
			QTableWidgetItem *itemcant = new QTableWidgetItem;
			QTableWidgetItem *itemIdMaq = new QTableWidgetItem;
			QTableWidgetItem *itemIdDesc = new QTableWidgetItem;

			itemMaquina->setText("Cotizacion");
			itemDesc->setText(nombre_activi);
			itemCate->setText("Actividad");
			itemcant->setText(cant_activi);
			itemIdMaq->setText(QString::number(numerocoti)); //id maquina
			itemIdDesc->setText(id_activi); //id actividad

			ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,0,itemMaquina);
			ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,1,itemIdMaq);
			ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,2,itemDesc);
			ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,3,itemIdDesc);
			ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,4,itemCate);
			ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,5,itemcant);
		}

	}
	cosmecdb.close();

	//Servicios Externos
	cosmecdb.open();
	sql=QString("SELECT a.cantidad_servicios, b.id_servicios, b.nombre_srevicio FROM servicios_cotizacion a, servicios_externos AS b "
		"WHERE id_servicios_servicios_externos=id_servicios AND numero_cotizacion=%1").arg(numerocoti);
	if(!aux.exec(sql)){
		QMessageBox msgBox;
		msgBox.setText("Error al agregar datos :"+aux.lastError().databaseText());
		msgBox.exec();
	}else{
		while(aux.next()){
			//--------------------------------------
			cant_serv=aux.value(0).toString();
			id_serv=aux.value(1).toString();
			nombre_serv=aux.value(2).toString();
			//--------------------------------------
			ui.tableWidget_12->insertRow(ui.tableWidget_12->rowCount());

			QTableWidgetItem *itemMaquina = new QTableWidgetItem;
			QTableWidgetItem *itemDesc = new QTableWidgetItem;
			QTableWidgetItem *itemCate = new QTableWidgetItem;
			QTableWidgetItem *itemcant = new QTableWidgetItem;
			QTableWidgetItem *itemIdMaq = new QTableWidgetItem;
			QTableWidgetItem *itemIdDesc = new QTableWidgetItem;

			itemMaquina->setText("Cotizacion");
			itemDesc->setText(nombre_serv);
			itemCate->setText("Servicio Externo");
			itemcant->setText(cant_serv);
			itemIdMaq->setText(QString::number(numerocoti)); //id maquina
			itemIdDesc->setText(id_serv); //id actividad

			ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,0,itemMaquina);
			ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,1,itemIdMaq);
			ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,2,itemDesc);
			ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,3,itemIdDesc);
			ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,4,itemCate);
			ui.tableWidget_12->setItem(ui.tableWidget_12->rowCount()-1,5,itemcant);
		}

	}
	cosmecdb.close();


	//Caragar combobox
	cosmecdb.open();
	QSqlQuery respuesta(cosmecdb);
	respuesta.exec("SELECT a.serie, a.modelo, a.cod_espe FROM maquinas AS a ORDER BY a.modelo");
	tamquery1=respuesta.size();
	idmaquinas=new int[tamquery1];
	int b=0;
	while(respuesta.next()){
		idmaquinas[b]=respuesta.value(0).toInt();
		ui.comboBox_5->addItem(respuesta.value(1).toString()+"("+respuesta.value(2).toString()+")");
		b++;
	}
	cosmecdb.close();

	cosmecdb.open();
	respuesta.exec(QString("SELECT a.id_actividad, a.nombre FROM actividades AS a ORDER BY a.nombre"));
	tamquery1=respuesta.size();
	qDebug()<<tamquery1;
	idactividades=new int[tamquery1];
	b=0;
	while(respuesta.next()){
		idactividades[b]=respuesta.value(0).toInt();
		ui.comboBox_11->addItem(respuesta.value(1).toString());
		b++;
	}
	cosmecdb.close();

	cosmecdb.open();
	respuesta.exec(QString("SELECT a.id_material, a.nombre||' ('||a.geometria||'-'||a.dimencion||')' FROM materiales AS a ORDER BY a.nombre"));
	tamquery2=respuesta.size();
	idmaterial=new int[tamquery2];
	b=0;
	while(respuesta.next()){
		idmaterial[b]=respuesta.value(0).toInt();
		ui.comboBox->addItem(respuesta.value(1).toString());
		b++;
	}
	cosmecdb.close();

	cosmecdb.open();
	respuesta.exec(QString("SELECT id_servicios, nombre_srevicio FROM servicios_externos"));
	tamquery2=respuesta.size();
	idserv=new int[tamquery2];
	b=0;
	while(respuesta.next()){
		idserv[b]=respuesta.value(0).toInt();
		ui.comboBox_6->addItem(respuesta.value(1).toString());
		b++;
	}
	cosmecdb.close();

	if(ui.checkBox_clonar->isChecked()){
		numerocoti=num;
	}else{
		sql=QString("DELETE FROM cotizacion_manoobra WHERE numero_cotizacion=%1").arg(numerocoti);
		insertarsql(sql);
		sql=QString("DELETE FROM maquina_cotizacion WHERE numero_cotizacion=%1").arg(numerocoti);
		insertarsql(sql);
		sql=QString("DELETE FROM servicios_cotizacion WHERE numero_cotizacion=%1").arg(numerocoti);
		insertarsql(sql);
		sql=QString("DELETE FROM cotizacion_material WHERE numero_cotizacion=%1").arg(numerocoti);
		insertarsql(sql);
		sql=QString("DELETE FROM actividades_cotizacion WHERE numero_cotizacion=%1").arg(numerocoti);
		insertarsql(sql);
		sql=QString("DELETE FROM cotizacion_manoobra WHERE numero_cotizacion=%1").arg(numerocoti);
		insertarsql(sql);
	}

	ui.stackedWidget->setCurrentIndex(11);
}
void cosmec::cambiarcomboconsumible(int index){
	int b=0;
	ui.comboBox_13->clear();
	QSqlQuery respuesta(cosmecdb);
	cosmecdb.open();
	respuesta.exec(QString("SELECT id_consumible, nombre_consumible	FROM consumible WHERE serie_maquinas=%1 ORDER BY nombre_consumible").arg(idmaquinas[index]));
	tamquery1=respuesta.size();
	qDebug()<<tamquery1;
	idconsumibles=new int[tamquery1];
	b=0;
	while(respuesta.next()){
		idconsumibles[b]=respuesta.value(0).toInt();
		ui.comboBox_13->addItem(respuesta.value(1).toString());
		b++;
	}
	cosmecdb.close();
}