#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED

struct Articulo{
  char codigo[5];
  char descripcion[30];
  float precio;
  int stock;
};

bool cargar_articulo(Articulo *b){
  cout << "CÓDIGO: ";
  cin >> b->codigo;
  cout << "DESCRIPCION: ";
  cin.ignore();
  cin.getline(b->descripcion, 30);
  cout << "PRECIO: $";
  cin >> b->precio;
  if (b->precio <= 0){
    return false;
  }
  cout << "STOCK: ";
  cin >> b->stock;
  if (b->stock < 0){
    return false;
  }
  return true;
}
void mostrar_articulo(Articulo a){
  cout << "CÓDIGO: ";
  cout << a.codigo << endl;
  cout << "DESCRIPCION: ";
  cout << a.descripcion << endl;
  cout << "PRECIO: $";
  cout << a.precio << endl;
  cout << "STOCK: ";
  cout << a.stock << endl;
}
bool guardar_articulo(Articulo a){
  FILE *p;
  p = fopen("articulos.dat", "ab");
  if (p == NULL){
    return false;
  }
  bool i=fwrite(&a, sizeof(Articulo), 1, p);
  fclose(p);
  return i;
}
void listar_articulos(){
  Articulo a;
  FILE *p;
  p = fopen("articulos.dat", "rb");
  if (p == NULL){
    cout << "Error al abrir el archivo.";
    return;
  }
  while(fread(&a, sizeof(Articulo), 1, p) == 1){
    mostrar_articulo(a);
    cout << endl;
  }
  fclose(p);
}


#endif // ARTICULO_H_INCLUDED
