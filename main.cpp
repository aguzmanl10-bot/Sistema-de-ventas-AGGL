#include <iostream>

#include "productos.h"
#include "ventas.h"
#include "reportes.h"

using namespace std;

// ======================================================
// MENU PRINCIPAL
// ======================================================
void menu() {

    int opcion;

    do {

        cout << "\n================================";
        cout << "\n SISTEMA DE VENTAS E INVENTARIO";
        cout << "\n================================";

        cout << "\n1. Registrar producto";
        cout << "\n2. Listar productos";
        cout << "\n3. Buscar por codigo";
        cout << "\n4. Buscar por nombre";
        cout << "\n5. Actualizar stock";
        cout << "\n6. Modificar precio";
        cout << "\n7. Eliminar producto";
        cout << "\n8. Realizar venta";
        cout << "\n9. Reporte menor stock";
        cout << "\n10. Reporte mas vendidos";
        cout << "\n11. Ventas totales";
        cout << "\n12. Ordenar precio";
        cout << "\n13. Ordenar stock";
        cout << "\n14. Exportar reporte";
        cout << "\n15. Salir";

        cout << "\nSeleccione: ";
        cin >> opcion;

        switch(opcion) {

            case 1:
                registrarProducto();
                break;

            case 2:
                listarProductos();
                break;

            case 3:
                buscarProductoCodigo();
                break;

            case 4:
                buscarProductoNombre();
                break;

            case 5:
                actualizarStock();
                break;

            case 6:
                modificarPrecio();
                break;

            case 7:
                eliminarProducto();
                break;

            case 8:
                realizarVenta();
                break;

            case 9:
                reporteMenorStock();
                break;

            case 10:
                reporteMasVendidos();
                break;

            case 11:
                ventasTotalesDia();
                break;

            case 12:
                ordenarPrecioAscendente();
                break;

            case 13:
                ordenarStockAscendente();
                break;

            case 14:
                exportarReporteTXT();
                break;

            case 15:
                cout << "\nSaliendo...";
                break;

            default:
                cout << "\nOpcion invalida";
        }

    } while(opcion != 15);
}

int main() {

    menu();

    return 0;
}