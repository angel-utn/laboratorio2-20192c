#include <iostream>
using namespace std;
#include <cstdlib>
#include "articulo.h"
int main(){
  Articulo v[3];
  cargar_articulos(v, 3);
  system("cls");
  mostrar_articulos(v, 3);
  return 0;
}
