#include <iostream>
using namespace std;
#include <clocale>
#include <cstdlib>
#include <cstdio>
#include "articulo.h"

int main(){
  setlocale(LC_ALL, "Spanish");
  Articulo a;
  int i, opc;

  while(true){
    system("cls");
    cout << "MEN�" << endl;
    cout << "1 - CARGAR ART�CULO" << endl;
    cout << "2 - MOSTRAR ART�CULOS" << endl;
    cout << "0 - SALIR" << endl;
    cin >> opc;
    switch(opc){
      case 1:
        if (cargar_articulo(&a) == true){
          if (guardar_articulo(a) == true){
          cout << "Datos guardados correctamente." << endl;
          }
          else{
            cout << "Error al guardar" << endl;
          }
        }
        else{
          cout << "Error de carga";
        }
      break;
      case 2:
        system("cls");
        listar_articulos();
      break;
      case 0:
        return 0;
      break;
    }
    cout << endl;
    system("pause");
  }

  return 0;
}
