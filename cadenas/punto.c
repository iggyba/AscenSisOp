#include <stdio.h>
#include <stdlib.h>
#include "punto.h"
#include "cadena.h"

int res = 0;
int sel;


void
menu_principal(punto_t *p, punto_t **cab)
{

printf ("Elegir opcion:\n");
printf ("1. crear punto.\n");
printf ("2. mostrar punto a insertar.\n");
printf ("3. insert punto INICIO.\n");
printf ("4. insert punto FINAL.\n");
printf ("5. elim. punto INICIO.\n");
printf ("6. elim. punto FINAL.\n");
printf ("7. elim. punto MEDIO.\n");
printf ("8. mostrar puntos.\n");
printf ("9. salir.\n");
printf ("\n");
scanf("%d",&sel);

    switch (sel){
        case 1:
          printf ("creando..\n");
          //printf(" ptr de fun %u \n" , p);
          crear_punto (p);
          break;
        case 2:
          printf ("mostrando..\n");
          mostrar_punto (p);
          break;
        case 3:
          printf ("insertando..\n");
          insertar_inicio (p, cab);
          break;
        case 4:
          printf ("insertando..\n");
          insertar_final (p, cab);
          break;
        case 5:
          printf ("eliminando..\n");
          extraer_inicio ( cab);
          break;
        case 6:
          printf ("eliminando..\n");
          extraer_final ( cab);
          break;
        case 7:
          printf ("eliminando..\n");
          extraer_med ( cab);
          break;
        case 8:
          printf ("puntos son:\n");
          recorrer(cab);
          break;
        case 9:
          printf ("saliendo..\n");
          exit (EXIT_SUCCESS);
          break;  
       
        default:
          printf ("opcion no existe\n");
    }


}

void 
crear_punto (punto_t *p)
{
    int a;
    int b;
	 
	
	printf ("x:");
	scanf("%d", &a );
	p->x = a;
	
	printf ("y:");
	scanf("%d", &b );
	p->y = b;
	
	res = 1;
	
}

void
mostrar_punto (punto_t *p )
{
	if(res != 1){
	printf("DEBE CERAR UN PUNTO PRIMERO\n");
	}else{
	printf ("(%d , %d)\n", p->x ,p->y);
	}
}
