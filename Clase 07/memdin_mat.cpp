#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>
int contarMedicos(){
  /// Función que cuenta la cantidad de registros
  /// de médico en el archivo
  return 100;
}
int contarPacientes(){
  /// Función que cuenta la cantidad de registros
  /// de paciente en el archivo
  return 10;
}
int contarControlesxMedicoPaciente(int **m){
  FILE *p;
  p = fopen("controles.dat", "rb");
  if (p == NULL){
    cout << "Me hiciste pedir memoria y no podés abrirte";
    return -1;
  }
  Control reg;
  int i, j;
  while(fread(&reg, sizeof(Control), 1, p)){
    i = buscarPaciente(reg.DNI);
    j = buscarMedico(reg.NroMatricula);
    if (i >= 0 && j >= 0)
      m[i][j]++;
  }
  fclose(p);
  return 0;
}

int ponerCero(int **m, int f, int c){
  int i, j;
  for(i=0; i<f; i++){
    for(j=0; j<c; j++){
        m[i][j] = 0;
    }
  }
}
void mostrarMatriz(int **m, int f, int c){
  int i, j;
  Medico me;
  Paciente p;
  for(i=0; i<f; i++){
    me= leerMedico(i);
    cout << me.apellido << endl;
    for(j=0; j<c; j++){
        p = leerPaciente(j);
        cout << p.apellido << endl;
        cout << m[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  int **m;
  int i, j;
  int medicos, pacientes;
  medicos = contarMedicos();
  pacientes = contarPacientes();
  m = (int **) malloc (medicos * sizeof(int*));
  for(i=0; i<medicos; i++){
    m[i] = (int *) malloc (pacientes * sizeof(int));
  }
  ponerCero(m, medicos, pacientes);
  contarControlesxMedicoPaciente(m);
  mostrarMatriz(m, medicos, pacientes);
  for(i=0; i<medicos; i++){
    free(*(m+i));
  }
  free(m);
  return 0;
}
