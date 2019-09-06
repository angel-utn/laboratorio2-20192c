#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED

struct Articulo{
  char codigo[5];
  char descripcion[30];
  float precio;
  int stock;
};


bool cargar_articulo(Articulo *);
void mostrar_articulo(Articulo);
void modificar_articulo();
void listar_articulo_x_codigo();

///ACCESO A DISCO
Articulo leer_articulo(int);
bool guardar_articulo(Articulo);
void listar_articulos();
int buscar_articulo(char *);
int cantidad_articulos();
bool sobreescribir_articulo(Articulo, int);

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
  int cant = cantidad_articulos(), i;
  Articulo reg;
  for(i=0; i<cant; i++){
    reg = leer_articulo(i);
    mostrar_articulo(reg);
    cout << "----------------------" << endl;
  }
}
int buscar_articulo(char *codigo){
  FILE *p;
  p = fopen("articulos.dat", "rb");
  if (p == NULL){
    return -2;
  }
  Articulo a;
  int i=0;
  while(fread(&a, sizeof(Articulo), 1, p)){
    if (strcmp(codigo, a.codigo) == 0){
      fclose(p);
      return i;
    }
    i++;
  }
  fclose(p);
  return -1;
}
void listar_articulo_x_codigo(){
  char codigo[5];
  int pos;
  cout << "CODIGO A BUSCAR: ";
  cin >> codigo;
  pos = buscar_articulo(codigo);
  if (pos >= 0){
    Articulo reg;
    reg = leer_articulo(pos);
    mostrar_articulo(reg);
  }
  else{
    cout << "No existe el registro.";
  }
}
Articulo leer_articulo(int pos){
  Articulo reg;
  FILE *p;
  p = fopen("articulos.dat", "rb");
  if (p==NULL){
    reg.precio = -1;
    return reg;
  }
  fseek(p, sizeof(Articulo)*pos, SEEK_SET);
  bool leyo=fread(&reg, sizeof(Articulo), 1, p);
  if (leyo == false){
    reg.precio = -1;
  }
  fclose(p);
  return reg;
}
int cantidad_articulos(){
  FILE *p;
  p = fopen("articulos.dat", "rb");
  if (p == NULL){
    return 0;
  }
  int tamanio;
  fseek(p, 0, SEEK_END);
  tamanio = ftell(p);
  fclose(p);
  return tamanio/sizeof(Articulo);
}
void modificar_articulo(){
   char codigo[5];
  int pos;
  cout << "CODIGO A BUSCAR: ";
  cin >> codigo;
  pos = buscar_articulo(codigo);
  if (pos >= 0){
    Articulo reg;
    reg = leer_articulo(pos);
    mostrar_articulo(reg);
    cout << endl << "NUEVO PRECIO: $";
    cin >> reg.precio;
    if (sobreescribir_articulo(reg, pos) == true){
      cout << endl << "PRECIO MODIFICADO.";
    }
  }
  else{
    cout << "No existe el registro.";
  }
}
bool sobreescribir_articulo(Articulo reg, int pos){
  FILE *p;
  p = fopen("articulos.dat", "rb+");
  if (p == NULL){
    return false;
  }
  fseek(p, sizeof(Articulo)*pos, 0);
  bool i=fwrite(&reg, sizeof(Articulo), 1, p);
  fclose(p);
  return i;
}

#endif // ARTICULO_H_INCLUDED
