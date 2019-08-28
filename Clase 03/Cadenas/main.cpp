#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
#include <cstring>

int main(){
  int legajo;
  char apellidos[31];
  char nombres[100];

  cout << "Legajo: ";
  cin >> legajo;
  cout << "Apellido: ";
  cin.ignore(); /// Necesario porque previo al cin.getline hay un cin
  cin.getline(apellidos, 31);
  cout << "Nombres : ";
  /// No se usa cin.ignore porque previo al cin.getline hay otro cin.getline
  cin.getline(nombres, 100);

  cout << endl;
  cout << apellidos << ", " << nombres;
  cout << endl << legajo;
  /**
    /// Comparar
    int strcmp(a, b);

    /// <  0  --> a es menor b
    /// == 0  --> son iguales
    /// >  0  --> a es mayor b

    ///Copiar
    strcpy(a, b);
  */
  return 0;
}
