#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define CANT 20
void fLimpiar()
{
    system("cls");
}
void fInicializar(ePersona individuo[], int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        strcpy(individuo[i].nombre,"\0");
        individuo[i].edad=0;
        individuo[i].dni=0;
        individuo[i].estado=0;
        individuo[i].posicion=i+1;
    }
}
int fEspacioLibre(ePersona individuo[], int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(individuo[i].estado==0)
        {
            return i;
        }

    }

    return -1;
}
void fAgregarPersona(ePersona individuo[], int indice)
{
    int i = indice;
    char auxNombre[50];
    char auxEdad[50];
    char auxDNI[50];
    int verificador, edad, dni;

    while(individuo[i].estado!=1)
    {
        //Nombre
        printf("Ingrese nombre: ");
        scanf("%s",auxNombre);
        verificador=fVerificarNombre(auxNombre,50);

        while(verificador==0)
        {
            printf("Error, re-ingrese nombre: ");
            scanf("%s",auxNombre);
            verificador=fVerificarNombre(auxNombre,50);
        }

        strcpy(individuo[i].nombre,auxNombre);

        //Edad
        printf("Ingrese edad: ");
        scanf("%s",auxEdad);
        verificador=fVerificarEdad(auxEdad);
        while(verificador==0)
        {
            printf("Error, re-ingrese edad: ");
            scanf("%s",auxEdad);
            verificador=fVerificarEdad(auxEdad);
        }

        edad = atoi(auxEdad);
        individuo[i].edad = edad;

        //DNI
        printf("Ingrese DNI: ");
        scanf("%s",auxDNI);
        verificador=fVerificarDNI(individuo,auxDNI,CANT);

        while(verificador==0 || verificador==2)
        {
            printf("Error, re-ingrese DNI: ");
            scanf("%s",auxDNI);
            verificador=fVerificarDNI(individuo,auxDNI,CANT);
        }

        dni = atoi(auxDNI);
        individuo[i].dni = dni;

        //Cambio estado
        individuo[i].estado=1;
    }

}
int fVerificarNombre(char auxNombre[], int tam)
{
    int i;
    for(i=0; i<strlen(auxNombre); i++)
    {
        if((isdigit(auxNombre[i])))
        {
            return 0;
        }
    }

    if(strlen(auxNombre)>tam)
    {
        return 0;
    }

    return 1;

}
int fVerificarEdad(char auxEdad[])
{
    int i;
    int edad;
    for(i=0; i<strlen(auxEdad); i++)
    {
        if(!(isdigit(auxEdad[i])))
        {
            return 0;
        }
    }

    edad = atoi(auxEdad);

    if(edad>99 || edad<=0)
    {
        return 0;
    }

    return 1;

}
int fVerificarDNI(ePersona individuo[],char auxDNI[], int tam)
{
    int i;
    int dni;
    for(i=0; i<strlen(auxDNI); i++)
    {
        if(!(isdigit(auxDNI[i])))
        {
            return 0;
        }
    }

    dni = atoi(auxDNI);

    if(dni<10000000 || dni>99999999)
    {
        return 0;
    }

    for(i=0; i<tam; i++)
    {
        if(individuo[i].dni==dni)
        {
            return 2; //Si encuentra un dni identico ya cargado devuelve 2
        }
    }

    return 1;
}
void fMostrarPersona(ePersona individuo[], int cantidad)
{
    int i;
    printf("\n|DNI|\t\t\t|NOMBRE|\t|EDAD|");
    printf("\n----------------------------------------------\n");
    for(i=0; i<cantidad; i++)
    {
        if(individuo[i].estado!=0)
        {
            printf("\n%d\t\t%s\t\t%d\n",individuo[i].dni,individuo[i].nombre,individuo[i].edad);
        }
    }
    printf("\n----------------------------------------------\n");
}
void fBuscarPorDNI(ePersona individuo[], int cantidad)
{
    char auxDNI[50];
    int dni;
    int verificador;
    int i;
    char opcion;

    printf("Ingrese DNI: ");
    scanf("%s",auxDNI);
    verificador=fVerificarDNI(individuo,auxDNI,CANT);

    while(verificador==0)
    {
        printf("Error, re-ingrese DNI: ");
        scanf("%s",auxDNI);
        verificador=fVerificarDNI(individuo,auxDNI,CANT);
    }

        dni = atoi(auxDNI);

    if(verificador==2)
    {

        for(i=0; i<cantidad; i++)
        {
            if(individuo[i].dni==dni)
            {
                printf("Desea borrar a la persona con DNI %d del registro? s/n: ",dni);
                fflush(stdin);
                scanf("%c",&opcion);

                opcion = tolower(opcion);

                while(!(opcion=='s' || opcion=='n'))
                {
                    printf("Error, ingrese s o n: ");
                    fflush(stdin);
                    scanf("%c",&opcion);
                }
                if(opcion=='s')
                {
                    strcpy(individuo[i].nombre,"\0");
                    individuo[i].edad=0;
                    individuo[i].dni=0;
                    individuo[i].estado=0;

                    printf("Persona eliminada del registro correctamente. \n");
                    break;
                }
                else
                {
                    printf("Se lo devolvera al menu.\n");
                    break;
                }
            }
        }
    }
    else if(verificador==1)
    {
        printf("No se encontro el DNI en el registro.\n");
    }


}

void graficoEdades(ePersona individuo[], int tam)
{
    int i,j;
    int bandera=0;
    int vmenora18=0,vde19a35=0,vmayora35=0;
    for(i=0; i<tam; i++)
    {
        if(individuo[i].estado==1)
        {
            if(individuo[i].edad>35)
            {
                vmayora35++;
            }
            else if(individuo[i].edad<18)
            {
                vmenora18++;
            }
            else
            {
                vde19a35++;
            }

        }

    }


    if(vmenora18 > vde19a35 && vmenora18 > vmayora35)
    {
        j = vmenora18;
    }
    else if(vmayora35 > vmenora18 && vmayora35 > vde19a35)
    {
        j = vmayora35;
    }
    else
    {
        j = vde19a35;
    }

    for(i=j; i>0; i--)
    {
        printf("  |");

        if(i<= vmenora18)
        {
            printf(" * ");
        }
        if(i<= vde19a35)
        {
            printf("\t  *");
            bandera=1;
        }
        if(i<= vmayora35)
        {
            if(bandera==1)
            {
                printf("\t *");
            }
            else if(bandera==0)
            {
                printf("\t\t  *");
            }

        }
        printf("\n");
    }

    printf("  |-----------------|");
    printf("\n  |<18|\t|19-35|\t|>35|\n");
    printf("  |-----------------|\n");
}
