#include "productos.h"

Producto productosVector[100];

int totalProductos = 0;

// Convierte cualquier texto ingresado a minúsculas
void convertirMinusculas(char texto[]) {

    for(int i = 0; texto[i] != '\0'; i++) {

        texto[i] = tolower(texto[i]);
    }
}
// REGISTRAR PRODUCTO
// se crea el crud
void registrarProducto() {

    Producto p;

    try {

        ofstream archivo("productos.dat", ios::binary | ios::app);

        if(!archivo) {

            throw 1;
        }

        cout << "\n========== REGISTRO PRODUCTO ==========";

        cout << "\nCodigo: ";
        cin >> p.codigo;

        cin.ignore();

        cout << "Nombre: ";
        cin.getline(p.nombre,40);

        convertirMinusculas(p.nombre);

        cout << "Categoria: ";
        cin.getline(p.categoria,30);

        convertirMinusculas(p.categoria);

        cout << "Stock: ";
        cin >> p.stock;

        cout << "Precio: ";
        cin >> p.precio;

        p.vendidos = 0;
        p.activo = true;

        archivo.write((char*)&p,sizeof(p));

        archivo.close();

        cout << "\nProducto registrado correctamente";
    }

    catch(int error) {

        cout << "\nError al abrir archivo";
    }
}

// se lee el crud para mostrar los productos registrados

void listarProductos() {

    Producto p;

    ifstream archivo("productos.dat", ios::binary);

    if(!archivo) {

        cout << "\nNo existen productos";
        return;
    }

    while(archivo.read((char*)&p,sizeof(p))) {

        if(p.activo) {

            cout << "\n========================";
            cout << "\nCodigo    : " << p.codigo;
            cout << "\nNombre    : " << p.nombre;
            cout << "\nCategoria : " << p.categoria;
            cout << "\nStock     : " << p.stock;
            cout << "\nPrecio    : Q" << p.precio;
        }
    }

    archivo.close();
}

// ======================================================
// se busca el producto por codigo, se lee el crud y se compara el codigo ingresado con los codigos del archivo
// ======================================================
void buscarProductoCodigo() {

    Producto p;

    int codigo;
    bool encontrado = false;

    cout << "\nIngrese codigo: ";
    cin >> codigo;

    ifstream archivo("productos.dat", ios::binary);

    while(archivo.read((char*)&p,sizeof(p))) {

        if(p.codigo == codigo && p.activo) {

            encontrado = true;

            cout << "\nProducto encontrado";
            cout << "\nNombre: " << p.nombre;
        }
    }

    archivo.close();

    if(!encontrado) {

        cout << "\nProducto no encontrado";
    }
}

// ======================================================
// se busca el producto por nombre
// ======================================================
void buscarProductoNombre() {

    Producto p;

    char nombreBuscar[40];

    cin.ignore();

    cout << "\nIngrese nombre: ";
    cin.getline(nombreBuscar,40);

    convertirMinusculas(nombreBuscar);

    bool encontrado = false;

    ifstream archivo("productos.dat", ios::binary);

    while(archivo.read((char*)&p,sizeof(p))) {

        if(strcmp(nombreBuscar,p.nombre) == 0 && p.activo) {

            encontrado = true;

            cout << "\nProducto encontrado";
            cout << "\nCodigo: " << p.codigo;
            cout << "\nPrecio: Q" << p.precio;
        }
    }

    archivo.close();

    if(!encontrado) {

        cout << "\nNo encontrado";
    }
}

// ======================================================
// se actualiza el stock del producto, se busca por codigo y se modifica el stock en el archivo
// ======================================================
void actualizarStock() {

    Producto p;

    int codigo;

    cout << "\nCodigo producto: ";
    cin >> codigo;

    fstream archivo("productos.dat", ios::binary | ios::in | ios::out);

    while(archivo.read((char*)&p,sizeof(p))) {

        if(p.codigo == codigo) {

            cout << "\nNuevo stock: ";
            cin >> p.stock;

            archivo.seekp(archivo.tellg() - (long)sizeof(p));

            archivo.write((char*)&p,sizeof(p));

            cout << "\nStock actualizado";

            break;
        }
    }

    archivo.close();
}

// ======================================================
//se modifica el precio
// ======================================================
void modificarPrecio() {

    Producto p;

    int codigo;

    cout << "\nCodigo producto: ";
    cin >> codigo;

    fstream archivo("productos.dat", ios::binary | ios::in | ios::out);

    while(archivo.read((char*)&p,sizeof(p))) {

        if(p.codigo == codigo) {

            cout << "\nNuevo precio: ";
            cin >> p.precio;

            archivo.seekp(archivo.tellg() - (long)sizeof(p));

            archivo.write((char*)&p,sizeof(p));

            cout << "\nPrecio actualizado";

            break;
        }
    }

    archivo.close();
}

//eliminamos el producto
void eliminarProducto() {

    Producto p;

    int codigo;

    cout << "\nCodigo producto: ";
    cin >> codigo;

    fstream archivo("productos.dat", ios::binary | ios::in | ios::out);

    while(archivo.read((char*)&p,sizeof(p))) {

        if(p.codigo == codigo) {

            p.activo = false;

            archivo.seekp(archivo.tellg() - (long)sizeof(p));

            archivo.write((char*)&p,sizeof(p));

            cout << "\nProducto eliminado";

            break;
        }
    }

    archivo.close();
}

void cargarProductosVector() {

    Producto p;

    totalProductos = 0;

    ifstream archivo("productos.dat", ios::binary);

    while(archivo.read((char*)&p,sizeof(p))) {

        productosVector[totalProductos] = p;

        totalProductos++;
    }

    archivo.close();
}


void ordenarPrecioAscendente() {

    cargarProductosVector();

    for(int i=0; i<totalProductos-1; i++) {

        for(int j=0; j<totalProductos-1; j++) {

            if(productosVector[j].precio >
               productosVector[j+1].precio) {

                Producto aux = productosVector[j];

                productosVector[j] = productosVector[j+1];

                productosVector[j+1] = aux;
            }
        }
    }

    cout << "\nPRODUCTOS ORDENADOS";
}

void ordenarStockAscendente() {

    cargarProductosVector();

    for(int i=0; i<totalProductos-1; i++) {

        int menor = i;

        for(int j=i+1; j<totalProductos; j++) {

            if(productosVector[j].stock <
               productosVector[menor].stock) {

                menor = j;
            }
        }

        Producto aux = productosVector[i];

        productosVector[i] = productosVector[menor];

        productosVector[menor] = aux;
    }

    cout << "\nStock ordenado";
}