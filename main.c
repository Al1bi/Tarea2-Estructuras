#include "list.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
  char nombreItem[50];
}Item;

typedef struct{
  char nombre[30];
  int PA;
  int CantidadItems;
  List *listaItems;
}Jugador;


void mostrarMenu() {
  printf("\n---  Juego  ---\n");
  printf("[1] Registrar Jugador.\n");
  printf("[2] Mostrar perfil de Jugador.\n");
  printf("[3] Agregar item a Jugador.\n");
  printf("[4] Eliminar item a Jugador.\n");
  printf("[5] Agregar puntos de habilidad a Jugador.\n");
  printf("[6] Mostrar jugadores con un item especifico.\n");
  printf("[7] Deshacer ultima accion del jugador.\n");
  printf("[8] Exportar Jugadores.\n");
  printf("[9] Cargar datos de Jugadores.\n");
  printf("[10] Salir.\n");
  printf("Seleccione una opción: ");
}


Jugador* obtenerDatosJugador(){

  Jugador* nuevoJ =(Jugador *) calloc(1, sizeof(Jugador));
  printf("Nombre : ");
  scanf("%s", nuevoJ->nombre);
  nuevoJ->PA = 0;
  nuevoJ->CantidadItems = 0;
  nuevoJ->listaItems = createList();
  return nuevoJ;
  
}

Jugador* buscarJugador(List* listaJugadores, char nombre[30]){
  Jugador* it = firstList(listaJugadores);
  
  while(it != NULL){
    if(strcmp(it->nombre, nombre) == 0){
      return it;
    }
    it = nextList(listaJugadores);
  }
  
  return it;
}

void imprimirDatosJugador(Jugador* jugador){
  printf("%s : [%d] , [%d] ,", jugador->nombre, jugador->PA , jugador->CantidadItems);
  if(jugador->CantidadItems == 0)
    printf("No hay items asignados.\n");
  else{
      Item * it = firstList(jugador->listaItems);
      while(it != NULL){
        printf("%s ,", it->nombreItem);
        it = nextList(jugador->listaItems);
      }
  }
}

//Opcion 1 - Registrar Jugador
void registrarJugador(List*  listaJugadores){
  pushBack(listaJugadores, obtenerDatosJugador());
  printf("Jugador registrado correctamente!!\n");
}

//Opcion 2 - Mostrar Perfil Jugador

void mostrarPerfilJugador(List* listaJugadores){

  char nombreB[30];
  printf("Ingrese el nombre del jugador: ");
  scanf("%s", nombreB);

  Jugador* jugadorB = buscarJugador(listaJugadores, nombreB);

  if(jugadorB == NULL){
    printf("--- NO se encontro al jugador --- \n");
  }else{
    imprimirDatosJugador(jugadorB);
  }
  
}

//Opcion 3 - Agregar item a jugador

void agregarItemJugador(List* listaJugadores){

  char nombreB[30], blank[50];
  printf("Ingrese el nombre del jugador: ");
  scanf("%s", nombreB);

  Jugador* jugadorB = buscarJugador(listaJugadores, nombreB);

  if(jugadorB == NULL){
    printf("--- NO se encontro al jugador --- \n");
    return;
  }
  char opcion;
  
  do{
    printf("Desea agregar un item al jugador ' %s ' Y/N? : ", jugadorB->nombre);
    scanf("%s", &opcion);
    if (opcion == 'Y') {
      Item* nuevoItem = (Item*) calloc(1, sizeof(Item));
      printf("Nombre del item: ");
      fgets(blank, 50, stdin);
      fgets(nuevoItem->nombreItem, 50, stdin);
      nuevoItem->nombreItem[strcspn(nuevoItem->nombreItem, "\n")] ='\0';
      pushBack(listaJugadores, nuevoItem);
      jugadorB->CantidadItems++;
      printf("--- Se agrego correctamente el item!!! --- \n");
      
    } else if (opcion == 'N')
      break;
    else
      printf("Opcion Invalida\n");
  }while(true);

}

//Opcion 4 - Eliminar item a jugador

void eliminarItemJugador(List* listaJugadores){

  char nombreB[30], blank[50];
  printf("Ingrese el nombre del jugador: ");
  scanf("%s", nombreB);

  Jugador* jugadorB = buscarJugador(listaJugadores, nombreB);

  if(jugadorB == NULL){
    printf("--- NO se encontro al jugador --- \n");
    return;
  }

  
  
}

int main() {

  int opcion = 10, aux;

  List *listaJugadores = createList();

  while (true) {

    mostrarMenu();
    
    scanf("%d", &opcion);
    printf("\n");
    
    switch (opcion) {
    case 1:
      registrarJugador(listaJugadores);
      break;
    case 2:
      mostrarPerfilJugador(listaJugadores);
      break;
    case 3:
      agregarItemJugador(listaJugadores);
      break;
    case 4:
      
      break;
    case 5:
      
      break;
    case 6:
      
      break;
    case 7:
      
      break;
    case 8:
      
      break;
    case 9:
      
      break;
    case 10:

      break;
    default:
      printf("Opcion Invalida, ingrese nueva opcion\n");
    }
    if (opcion == 10)
      break;
  }

  return 0;
}