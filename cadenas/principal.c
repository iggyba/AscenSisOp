#include <stdio.h>
#include <stdlib.h>
#include "punto.h"
#include "cadena.h"

int
main()
{
	punto_t p;
	punto_t *ptr;
	punto_t *cab;
	punto_t **pca;
	
	cab = NULL;
	
	
	ptr = &p;
	
	pca = &cab;
	//(*cab).sig = NULL;
	
	for(;;){
	
	//printf ("(%d , %d)\n", p.x ,p.y);	
	//printf ("cab apuntando a: %u\n", cab);
	
	menu_principal( ptr , pca);
	
	//printf ("cab apuntando a: %u\n", cab);	
	//printf (" dir p:        %u  \n" , &p);	
	//printf ("punto en main: (%d , %d)\n", p.x ,p.y);
	
	}
	
	exit (EXIT_SUCCESS);
}







