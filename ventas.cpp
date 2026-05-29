#include "ventas.h"
#include "productos.h"

#include <fstream>
#include <cmath>

// ======================================================
// REALIZAR VENTA
// ======================================================
void realizarVenta() {
    float ventasPorMes[12][31];

    Venta v;

    v.subtotal = 0;

    int cantidadTotal = 0;

    int opcion;

    do {

        int codigo;
        int cantidad;

        cout << "\nCodigo producto: ";
        cin >> codigo;

        cout << "Cantidad: ";
        cin >> cantidad;

        Producto p;

        fstream archivo("productos.dat", ios::binary | ios::in | ios::out);

        while(archivo.read((char*)&p,sizeof(p))) {

            if(p.codigo == codigo && p.activo) {

                if(p.stock >= cantidad) {

                    float subtotalProducto;

                    subtotalProducto = cantidad * p.precio;

                    v.subtotal += subtotalProducto;

                    cantidadTotal += cantidad;

                    p.stock -= cantidad;

                    p.vendidos += cantidad;

                    archivo.seekp(archivo.tellg() - (long)sizeof(p));

                    archivo.write((char*)&p,sizeof(p));

                    cout << "\nProducto agregado";
                }

                else {

                    cout << "\nStock insuficiente";
                }
            }
        }

        archivo.close();

        cout << "\n1. Agregar otro";
        cout << "\n0. Finalizar";
        cin >> opcion;

    } while(opcion == 1);

    // IVA
    v.iva = v.subtotal * 0.12;

    // Descuento
    v.descuento = 0;

    if(v.subtotal > 500) {

        v.descuento += v.subtotal * 0.05;
    }

    // Uso de %
    if(cantidadTotal % 5 == 0) {

        v.descuento += 25;
    }

    // Total
    v.total = v.subtotal + v.iva - v.descuento;

    // Redondeo
    v.total = round(v.total * 100) / 100;

    // Guardar venta
  ofstream archivoVentas("ventas.dat", ios::binary | ios::app);

archivoVentas.write((char*)&v, sizeof(v));

archivoVentas.close();

    cout << "\nTOTAL: Q" << v.total;
}