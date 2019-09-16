
typedef struct punto punto_t;


struct punto
{
	int x;
	int y;
	punto_t *sig;
};

void menu_principal(punto_t *p, punto_t **cab);

void leer_punto (punto_t *);

void mostrar_punto (punto_t *p);

void crear_punto (punto_t *p);

