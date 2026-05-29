#ifndef PRODUCTOS_H
#define PRODUCTOS_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

// =====================================================
// Guarda la información de cada producto
// ======================================================
struct Producto {

    int codigo;
    char nombre[40];
    char categoria[30];
    int stock;
    float precio;
    int vendidos;
    bool activo;
};

// ======================================================
// Se utiliza para ordenamientos y reportes
// ======================================================
extern Producto productosVector[100];

extern int totalProductos;

// ======================================================
// pongo todo a minusculas
// ======================================================
void convertirMinusculas(char texto[]);

// ======================================================
// CRUD PRODUCTOS
// ======================================================
void registrarProducto();
void listarProductos();
void buscarProductoCodigo();
void buscarProductoNombre();
void actualizarStock();
void modificarPrecio();
void eliminarProducto();

void ordenarPrecioAscendente();
void ordenarPrecioDescendente();
void ordenarStockAscendente();


void cargarProductosVector();

#endif