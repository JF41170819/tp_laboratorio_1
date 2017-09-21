#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 20

int main()
{
    char seguir='s';
    int opcion=0,indice=0;

    ePersona individuo[CANT];

    fInicializar(individuo,CANT);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                fLimpiar();
                indice = fEspacioLibre(individuo,CANT);
                if(indice == -1)
                {
                    printf("No hay mas espacio disponible en memoria!\n");
                }
                else
                {
                    fAgregarPersona(individuo,indice);
                    printf("Persona agregada correctamente!.\n");
                }
                system("pause");
                fLimpiar();
                break;
            case 2:
                fLimpiar();
                fBuscarPorDNI(individuo,CANT);
                system("pause");
                fLimpiar();
                break;
            case 3:
                fLimpiar();
                fMostrarPersona(individuo,CANT);
                system("pause");
                fLimpiar();
                break;
            case 4:
                fLimpiar();
                graficoEdades(individuo,CANT);
                system("pause");
                fLimpiar();
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
