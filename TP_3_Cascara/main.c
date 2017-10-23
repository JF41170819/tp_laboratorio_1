#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int respuesta;

    ePelicula pelicula;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Modificar pelicula\n");
        printf("3- Borrar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                fLimpiar();
                agregarPelicula(pelicula);
                break;
            case 2:
                fLimpiar();
                modificarPelicula(pelicula);
                break;
            case 3:
                fLimpiar();
                borrarPelicula(pelicula);
                break;
            case 4:
                fLimpiar();
                html(pelicula);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                fLimpiar();
                printf("Error, ingrese una opcion valida... \n");
                break;
        }
    }

    return 0;
}
