#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED
struct Articulo{
  char codigo[5];
  char descripcion[30];
  float precio;
  int stock;
};
void cargar_articulos(Articulo *vec, int t){
  int i;
  for(i=0; i<t; i++){
    cout << "Codigo: ";
    cin >> vec[i].codigo;
    cout << "Descripcion: ";
    cin.ignore();
    cin.getline(vec[i].descripcion, 30);
    cout << "Precio: ";
    cin >> vec[i].precio;
    cout << "Stock :";
    cin >> vec[i].stock;
  }
}
void mostrar_articulos(Articulo *vec, int t){
  int x;
  for(x=0; x<t; x++){
    cout << "Codigo: ";
    cout << vec[x].codigo << endl;
    cout << "Descripcion: ";
    cout << vec[x].descripcion << endl;
    cout << "Precio: ";
    cout << vec[x].precio << endl;
    cout << "Stock :";
    cout << vec[x].stock << endl;
    cout << "-----------------------" << endl;
  }
}

#endif // ARTICULO_H_INCLUDED
