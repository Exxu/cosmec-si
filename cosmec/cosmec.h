
#ifndef COSMEC_H
#define COSMEC_H

#include <QtGui/QMainWindow>
#include <QtGui/QMessageBox>
#include <QtGui/QImage>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMenuBar>
#include <QtGui/QMenu>
#include <QtGui/QComboBox>
#include <QtGui/QRadioButton>
#include <QtGui/QCheckBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QBuffer>
#include <QThread>
#include <QtCore>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QtGui/QFileDialog>
#include <QtDebug>
#include "ncreport.h"
#include "ncreportpreviewwindow.h"
#include "ncreportpreviewoutput.h"
#include "libpq-fe.h"
#include "ui_cosmec.h"
#include "dialogdetalle.h"
#include "db.h"
#include "XmlExcel.h"
#include "formulariomaq.h"
#include <math.h>
#include "formularioactempresa.h"
#include "formularioacttrabajo.h"
#include "formulariocargos.h"
#include "formulariocategorias.h"
#include "formularioconsumibles.h"
#include "formularioherr.h"
#include "formularioinsumos.h"
#include "formulariomaq.h"
#include "formulariomateriales.h"
#include "formularioserexternos.h"
#include "formularioservicios.h"
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <iostream>
#include <list>


class cosmec : public QMainWindow
{
	Q_OBJECT

public:
	cosmec(QWidget *parent = 0, Qt::WFlags flags = 0);
	~cosmec();

private:
	Ui::cosmecClass ui;
	QComboBox *comboMaquina, *comboCategoria, *comboCarg, *comboAct, *comboInsumo;
	
	formularioHerr *fherr;
	formularioMaq *fmaquina;
	formularioConsumibles *fcons;
	formularioServicios *fser;
	formularioInsumos *finsumo;
	formularioActEmpresa *fActEmp;
	formularioCategorias *fcat;
	formularioActTrabajo *fActTrab;
	formularioCargos *fcargo;
	formularioMateriales *fmateriales;
	formularioSerExternos *fexternos;

	QString host;
	QString pass2;
	QString puerto;
	QString usuario;
	QString usuariop;
	QString nombrep;
	double iva;
	QSqlDatabase cosmecdb;
	QSqlRecord record;
	bool modificar;
	int idusuario;
	int *idcategoria;
	int *idquery1;
	int *idmaquinacot;
	int *idact;
	int *idmaquinas;
	int *idserv;
	int *idherramientas;
	int *idconsumibles;
	int *idactividades;
	int *idcargo;
	int *idquery2;
	int *idenergia;
	int *idagua;
	int *idinsumo;
	int *vectusuario;
	int *idinsumocombo;
	int *idmaterial;
	int tamquery1;
	int tamquery2;
	int numerocoti;
	int idusersel;
	double vcomp;
	NCReport *report;
	NCReportPreviewWindow *pv;
	void comboMaq(QTableWidget *tableNum,int fil, int col);
	void comboCat(QTableWidget *tableNum,int fil, int col);
	void comboCargo(QTableWidget *tableNum,int fil, int col);
	void comboActividades(QTableWidget *tableNum,int fil, int col);
	void comboinsumos(QTableWidget *tableNum,int fil, int col);
	void reportesinter(NCReport *report);
	void llenartabla(QTableWidget *tableNum,QString sql);
	void insertarsql(QSqlQuery respuesta);
	void insertarsql(QString sql);
	QVariant sql_maquina(int id,int para);
	QVariant sql_herramienta(int id,int para);
	QVariant sql_consumibles(int id,int para);
	QVariant sql_general(QString sql,int para);
	void cargaridenergia();
	void cargaridagua();
	void cargaridactividades();
	void cargaridcategoria();
	void cargaridinsumo();
	void cargaridusuario();
	void borrartabla(QTableWidget *tableNum);
	double calcularcotizacion(int numero);
	double calcularcotizacion2(int numero);
	void borrartabla2(QTableWidget *tableNum2);
	double redondear(double num);

	void limpiarFMaq();
	void limpiarFHerr();
	void limpiarFCons();
	void limpiarFser();
	void limpiarFInsumos();
	void limpiarFActE();
	void limpiarFCat();
	void limpiarFCargo();
	void limpiarFActTrab();
	void limpiarFMateriales();
	void limpiarFSexternos();
	void llenarcombomaq(QString sql,QComboBox *combo);
	void llenarcombocat(QString sql,QComboBox *combo);
	void llenarcombocargo(QString sql,QComboBox *combo);
	int buscarid(int *aux,int id,int tam);
	QVariant sql_record(QString sql,int para);
	void limpiarRep();
	void limpiarExcel();

private slots:
	//inicio
	void setInicio();

	//cotizaciones
	void combocotizacion(int index);
	void combocotizacion2(int index);
	//Configuracion
	void guardarConfig();
	void configurar();
	void conexion();
	//reportes
	void reportgenerador();
	void reporteexel();
	//Cambios de stack
	void setmaquina();
	void setherramienta();
	void setconsumible();
	void setenergia();
	void setmantenimiento();
	void setmanoobra();
	void setactividades();
	void setconfig();
	void setactividadesMo();
	void setnuevaCotizacion();
	void setbuscarCotizacion();
	void setmateriales();
	void setrptcotizaciones();
	void setServiciosExternos();
	//reportes
	void setgenerador();
	void setreporteexel();
	//mano de obra - cargos
	void agregarfila();
	void actualizar();
	void eliminarFila();
	void filaEditable(int row, int column);
	void nuevoCargo();
	void editarCargo();
	void updateCargo();
	//maquinaria
	void agregarfilaMaq();
	void actualizarMaq();
	void eliminarFilaMaq();
	void filaEditableMaq(int row, int column);
	void nuevaMaq();
	void editarMaq();
	void updateMaq();
	//servicios externos
	void agregarfilaSExternos();
	void actualizarSExternos();
	void eliminarFilaSExternos();
	void filaEditableSExternos(int row, int column);
	void nuevoSExterno();
	void editarSExterno();
	void updateSExterno();
	//herramientas
	void agregarfilaHe();
	void actualizarHe();
	void eliminarFilaHe();
	void filaEditableHe(int row, int column);
	void nuevaHerr();
	void editarHerr();
	void updateHerr();
	//consumibles
	void agregarfilaCons();
	void actualizarCons();
	void eliminarFilaCons();
	void filaEditableCons(int row, int column);
	void nuevoCons();
	void editarCons();
	void updateCons();
	//servicios básicos
	void agregarfilaSer();
	void actualizarSer();
	void eliminarFilaSer();
	void filaEditableSer(int row, int column);
	void nuevoSbasico();
	void editarSbasico();
	void updateSbasico();
	//mtto -insumos
	void agregarfilaMtto();
	void actualizarMtto();
	void eliminarFilaMtto();
	void filaEditableMtto(int row, int column);
	void nuevoInsumo();
	void editarInsumo();
	void updateInsumo();
	//mtto - preventivo
	//void agregarfilaPrev();
	//void actualizarPrev();
	//void eliminarFilaPrev();
	//void filaEditablePrev(int row, int column);
	//actividades -categorias
	void agregarfilaActC();
	void actualizarActC();
	void eliminarFilaActC();
	void filaEditableActC(int row, int column);
	void nuevaCat();
	void editarCat();
	void updateCat();
	//actividades -actividades
	void agregarfilaActAct();
	void actualizarActAct();
	void eliminarFilaActAct();
	void filaEditableActAct(int row, int column);
	void nuevaActE();
	void editarActE();
	void updateActE();
	//mano de obra - actividades
	void agregarfilaMo();
	void actualizarMo();
	void eliminarFilaMo();
	void filaEditableMo(int row, int column);
	void nuevaActTrab();
	void editarActTrab();
	void updateActTrab();
	//actividades - maquina
	void agregarfilaMaqActividades();
	//void actualizarMaqActividades();
	void eliminarFilaMaqActividades();
	//void filaEditableMaqActividades(int row,int column);
	//materiales
	void agregarfilaMat();
	void actualizarMat();
	void eliminarFilaMat();
	void filaEditableMat(int row, int column);
	void nuevoMat();
	void editarMat();
	void updateMat();
	//buscar cotización
	void habilitarBuscarRuc();
	void habilitarBuscarCotizacion();
	void habilitarBuscarProyecto();
	void habilitarBuscarFecha();
	void buscarCotizacion();
	void resultadoCotizacion();
	void imprimirCotizacion();
	void modificarCotizacion();
	void detalle();
	//nueva cotización
	void sumarHerramienta();
	void sumarConsumible();
	void eliminarPrimeraCotizacion();
	void segundaParte();
	void sumarMaq();
	void sumarActividad();
	void sumarMo();
	void sumarMaterial();
	void sumarServExt();
	void eliminarSegundaCotizacion();
	void terminarCotizacion();
	void cancelarCotizacion();

	//FORMULARIOS
	void setformulariomaq();

	//USUARIOS
	void verificarUsuario();
	void agregarUser();
	void modificarUser();
	void setUsuarios();

	//BUSQUEDA FORMULARIOS
	void setBusqueda();
	void cambiarCombo(int opcion);
	void mostrarFormlleno();
	void tablaBusqueda();

	//CENTRAR DATOS DE LAS TABLAS
	void centrarItem(QTableWidgetItem *elemento);

	//CALCULOS EN TIEMPO REAL
	void costo_hora_actrab(int horasact);
	void costo_hora_actrab2(int car);

	void costo_hora_consumibles(double valor);
	void costo_hora_consumibles2(int cantidad);
	void costo_hora_consumibles3( int maq);
	
	void depre_herramientas(double costo);
	void depre_herramientas2(int vida);
	void depre_herramientas3(int cantidad);

	void costo_hora_herramientas(double costo);
	void costo_hora_herramientas2(int cantidad);
	void costo_hora_herramientas3(int maq);

	void costo_total_herramientas(double costo);
	void costo_total_herramientas2(int cantidad);
	void costo_total_herramientas3(int maq);
	void costo_total_herramientas4(int vida);

	void valor_total_insumo(double unitario);
	void valor_total_insumo2(int cantidad);

	void costo_hora_insumo(double unitario);
	void costo_hora_insumo2(int cantidad);
	void costo_hora_insumo3(int maq);

	void borrartablaSlot(int index);
	void botonLimpiarRpt();
	void botonLimpiarExcel();

	void cambiarcomboconsumible(int index);
};

#endif // COSMEC_H
