#include "reportes.h"
#include "productos.h"
#include "ventas.h"

#include <fstream>

//se ingresa el reporte 
void reporteMenorStock() {

    Producto p;

    ifstream archivo("productos.dat", ios::binary);

    while(archivo.read((char*)&p,sizeof(p))) {

        if(p.stock < 5 && p.activo) {

            cout << "\n" << p.nombre;
        }
    }

    archivo.close();
}
//se genera reporte 
void reporteMasVendidos() {

    Producto p;

    ifstream archivo("productos.dat", ios::binary);

    while(archivo.read((char*)&p,sizeof(p))) {

        cout << "\nProducto: " << p.nombre;
        cout << "\nVendidos: " << p.vendidos;
    }

    archivo.close();
}

// se verifican las ventas totales del dia
void ventasTotalesDia() {

    Venta v;

    float total = 0;

    ifstream archivo("ventas.dat", ios::binary);

    while(archivo.read((char*)&v,sizeof(v))) {

        total += v.total;
    }

    archivo.close();

    cout << "\nTOTAL VENTAS: Q" << total;
}


void exportarReporteTXT() {

    ofstream reporte("reporte.txt");

    reporte << "REPORTE GENERAL";

    reporte.close();

    cout << "\nReporte exportado";
}