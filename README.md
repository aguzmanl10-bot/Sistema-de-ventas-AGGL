PROYECTO FINAL
ANA GUZMAN 
Sistema de gestión de ventas diseñado para administrar productos, clientes y transacciones de forma eficiente.
en el main.cpp se unen todos los archivos tanto xomo ventas, reportes, tipos pero son todos con .h. (así)
#include "productos.h"  →  productos.cpp
#include "ventas.h"     →  ventas.cpp
#include "reportes.h"   →  reportes.cpp

como mencione los tres .h incluyen "tipos.h"
(structs, constantes y utilidades compartidas)
adicional de eso ya podremos hacer los archicos .cpp que en ellos podemos declarar todas nuebtras variables, condiciones, estructuras y ya en el main solo lo ña declaramos.
