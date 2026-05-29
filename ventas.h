#ifndef ventas.h
#define ventas.h

#include <iostream>

using namespace std;

// ======================================================
// se detalla la venta 
// ======================================================
struct DetalleVenta {

    int codigoProducto;
    int cantidad;
    float precioUnitario;
    float subtotal;
};

// ======================================================
// como es la venta en general
// ======================================================
struct Venta {

    int numeroVenta;

    float subtotal;
    float iva;
    float descuento;
    float total;
};

// ======================================================
// ventasPorMes[12][31]
// ======================================================
extern float ventasPorMes[12][31];

void realizarVenta();

#endif