#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define RUTA_ARCHIV "archivo_binario.dat"
#define RUTA_HTML "index.html"

void fLimpiar()
{
    system("cls");
}
int getInt(char mensajeamostrar[],char erroramostrar[],int minimo,int maximo,int largoentero)
{

    int bandera;
    int validacion;
    int numero;
    char numeroAUX[largoentero];

    do
    {
        bandera=0;

        printf(mensajeamostrar);
        fflush(stdin);
        scanf("%s",numeroAUX);

        validacion=validaNumero(numeroAUX,largoentero);

        if(validacion!=0)
        {
            numero=atoi(numeroAUX);
            if(numero>=minimo && numero<=maximo)
            {
                return numero;
            }
            else
            {
                printf(erroramostrar);
                bandera++;
            }
        }
        else
        {
            printf(erroramostrar);
            bandera++;
        }
    }
    while(bandera!=0);
}
int validaNumero(char datoAValidar[],int largoDato)
{
    int i;
    int largoNumero;
    int bandera=0;

    largoNumero=strlen(datoAValidar);

    if((largoNumero>largoDato) && (largoDato!=0))
    {
        return 0;
    }

    for(i=0; i<largoNumero; i++)
    {
        if(!(isdigit(datoAValidar[i])))
        {
            bandera=1;
            break;
        }
    }

    if(bandera==1)
    {
        return 0;
    }

    return 1;
}
void getChar(char ingreso[],char mensajeamostrar[],char erroramostrar[],int largoChar)
{
    int bandera;
    int validacion;

    do
    {
        bandera=0;

        printf(mensajeamostrar);
        fflush(stdin);
        gets(ingreso);

        validacion=validaLetra(ingreso,largoChar);

        if(validacion==0)
        {
            printf(erroramostrar);
            bandera++;
        }
    }
    while(bandera!=0);
}
int validaLetra(char datoAValidar[],int largoChar)
{
    int i;
    int largoC;
    int bandera=0;

    largoC=strlen(datoAValidar);

    if((largoC>largoChar) && (largoChar!=0))
    {
        return 0;
    }

    for(i=0; i<largoC; i++)
    {
        if((isdigit(datoAValidar[i])) || ((datoAValidar[i]<'A' && datoAValidar[i]!=' ') || (datoAValidar[i]>'Z' && datoAValidar[i]<'a') || (datoAValidar[i]>'z')) )
        {
            bandera=1;
            break;
        }
    }

    if(bandera==1)
    {
        return 0;
    }

    return 1;
}
void agregarPelicula(ePelicula pelicula)
{
    FILE *archivoBinario;

    if((archivoBinario = fopen(RUTA_ARCHIV,"rb+")) == NULL)
    {
    if((archivoBinario = fopen(RUTA_ARCHIV,"wb+")) == NULL)
    {
         printf("No se pudo abrir el archivo\n");
         return 0;
    }
    }

    getChar(pelicula.titulo,"Ingrese el titulo de la pelicula: ", "Titulo invalido...\n", 100);
    getChar(pelicula.genero,"Ingrese el genero de la pelicula: ", "Genero invalido...\n", 100);
    pelicula.duracion = getInt("Ingrese la duracion de la pelicula (hora/s): ", "Error, duracion invalida...\n",1,3,1);
    printf("Ingrese la descripcion de la pelicula: ");
    scanf("%s",pelicula.descripcion);
    pelicula.puntaje = getInt("Ingrese el puntaje de la pelicula: ", "Error, puntaje de pelicula invalido...\n",1,10,2);
    printf("Ingrese link de la imagen de la pelicula: ");
    scanf("%s",pelicula.linkDeImagen);
    pelicula.estado=1;
    printf("Pelicula agregada correctamente\n");

    /*strcpy(pelicula.titulo,"Volver al futuro");
    strcpy(pelicula.genero,"Ciencia ficcion");
    pelicula.duracion=2;
    strcpy(pelicula.descripcion,"Una pelicula muy interesante");
    pelicula.puntaje=10;
    strcpy(pelicula.linkDeImagen,"https://cdni.rt.com/actualidad/public_images/2016.11/article/581c4fb0c4618803268b4570.jpg");
    pelicula.estado=1;*/

    fseek(archivoBinario, 0L, SEEK_END);
    fwrite(&pelicula, sizeof(ePelicula), 1, archivoBinario);
    fclose(archivoBinario);
}
void modificarPelicula(ePelicula pelicula)
{
    int cant;
    char auxTitulo[100];

    FILE *archivoBinario;

    archivoBinario = fopen(RUTA_ARCHIV,"rb+");

    if(archivoBinario == NULL)
    {
         printf("No se pudo abrir el archivo\n");
         return 0;
    }

    getChar(auxTitulo,"Ingrese el titulo de la pelicula a modificar: ", "Titulo invalido...\n", 100);

    int notfound=0;
    while(!feof(archivoBinario))
    {
        cant = fread(&pelicula, sizeof(ePelicula), 1, archivoBinario);

        if(cant!=0)
        {
            if((strcmp(auxTitulo, pelicula.titulo)==0) && pelicula.estado==1)
            {
                getChar(pelicula.titulo,"Ingrese el nuevo titulo de la pelicula: ", "Titulo invalido...\n", 100);
                getChar(pelicula.genero,"Ingrese el nuevo genero de la pelicula: ", "Genero invalido...\n", 100);
                pelicula.duracion = getInt("Ingrese la nueva duracion de la pelicula (hora/s): ", "Error, duracion invalida...\n",1,3,1);
                printf("Ingrese la descripcion de la pelicula: ");
                scanf("%s",pelicula.descripcion);
                pelicula.puntaje = getInt("Ingrese el nuevo puntaje de la pelicula: ", "Error, puntaje de pelicula invalido...\n",1,10,2);
                printf("Ingrese el nuevo link de la imagen de la pelicula: ");
                scanf("%s",pelicula.linkDeImagen);
                pelicula.estado=1;
                printf("Pelicula modificada correctamente\n");
                break;
            }
            else
            {
                notfound=1;
            }
        }
    }

    if(notfound==1)
    {
        printf("Error, no se ha encontrado el titulo\n");
    }

    fseek(archivoBinario,(long)(-1)*sizeof(ePelicula), SEEK_CUR);
    fwrite(&pelicula, sizeof(ePelicula), 1, archivoBinario);
    fclose(archivoBinario);
}
void borrarPelicula(ePelicula pelicula)
{
    int cant;
    char auxTitulo[50];

    FILE *archivoBinario;

    archivoBinario = fopen(RUTA_ARCHIV,"rb+");

    if(archivoBinario == NULL)
    {
         printf("No se pudo abrir el archivo\n");
         return 0;
    }

    getChar(auxTitulo,"Ingrese el titulo de la pelicula a borrar: ", "Titulo invalido...\n", 100);

    int notfound=0;
    while(!feof(archivoBinario))
    {
        cant = fread(&pelicula, sizeof(ePelicula), 1, archivoBinario);
        if(cant!=0)
        {
            if((strcmp(auxTitulo, pelicula.titulo)==0)&& pelicula.estado==1)
            {
                pelicula.estado=0;
                printf("Pelicula eliminada correctamente\n");
                break;
            }
            else
            {
                notfound=1;
            }
        }
    }

    if(notfound==1)
    {
        printf("Error, no se ha encontrado el titulo\n");
    }

    fseek(archivoBinario,(long)(-1)*sizeof(ePelicula), SEEK_CUR);
    fwrite(&pelicula, sizeof(ePelicula), 1, archivoBinario);
    fclose(archivoBinario);
}
void html(ePelicula pelicula)
{
    ePelicula* dir;

    int contador=0;
    FILE *archivoBinario;

    archivoBinario = fopen(RUTA_ARCHIV,"rb+");

    if(archivoBinario == NULL)
    {
         printf("No se pudo abrir el archivo\n");
         return 0;
    }

    while(!feof(archivoBinario))
    {
        int cant = fread(&pelicula, sizeof(ePelicula), 1, archivoBinario);
        if(cant!=0)
        {
            if(pelicula.estado!=0)
            {
                contador++;
            }
        }
    }

    rewind(archivoBinario);

    ePelicula carga[contador];

    int i;

    dir=&carga;

    for(i=0;i<contador;i++)
    {
        if(pelicula.estado==1)
        {
            fread((dir+i),sizeof(ePelicula),1,archivoBinario);
        }
    }

    FILE *archivoHTML;

    if((archivoHTML = fopen(RUTA_HTML,"w+")) == NULL)
    {
         printf("No se pudo abrir el archivo\n");
         return 0;
    }

    fseek(archivoHTML, 0L, SEEK_SET);
    fprintf(archivoHTML,"<!DOCTYPE html>\n");
    fseek(archivoHTML, 0L, SEEK_END);
    fprintf(archivoHTML,"<head>\n");
    fseek(archivoHTML, 0L, SEEK_END);
    fprintf(archivoHTML,"<meta charset='utf-8'>\n");
    fseek(archivoHTML, 0L, SEEK_END);
    fprintf(archivoHTML,"<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
    fseek(archivoHTML, 0L, SEEK_END);
    fprintf(archivoHTML,"<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
    fseek(archivoHTML, 0L, SEEK_END);
    fprintf(archivoHTML,"<title>Lista de peliculas</title>\n");
    fseek(archivoHTML, 0L, SEEK_END);
    fprintf(archivoHTML,"<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
    fseek(archivoHTML, 0L, SEEK_END);
    fprintf(archivoHTML,"<link href='css/custom.css' rel='stylesheet'>\n");
    fseek(archivoHTML, 0L, SEEK_END);
    fprintf(archivoHTML,"</head>\n");
    fseek(archivoHTML, 0L, SEEK_END);
    fprintf(archivoHTML,"<body>\n");
    fseek(archivoHTML, 0L, SEEK_END);
    fprintf(archivoHTML,"<div class='container'>\n");
    fseek(archivoHTML, 0L, SEEK_END);
    fprintf(archivoHTML,"<div class='row'>\n");
    fseek(archivoHTML, 0L, SEEK_END);

    int p;
    for(p=0;p<contador;p++)
    {
        if((dir+p)->estado==1)
        {
        fprintf(archivoHTML,"<article class='col-md-4 article-intro'>\n");
        fseek(archivoHTML, 0L, SEEK_END);
        fprintf(archivoHTML,"<a href='#'>\n");
        fseek(archivoHTML, 0L, SEEK_END);
        fprintf(archivoHTML,"<img class='img-responsive img-rounded' src='%s' alt=''>\n",(dir+p)->linkDeImagen);
        fseek(archivoHTML, 0L, SEEK_END);
        fprintf(archivoHTML,"</a>\n");
        fseek(archivoHTML, 0L, SEEK_END);
        fprintf(archivoHTML,"<h3>\n");
        fseek(archivoHTML, 0L, SEEK_END);
        fprintf(archivoHTML,"<a href='#'>%s</a>\n",(dir+p)->titulo);
        fseek(archivoHTML, 0L, SEEK_END);
        fprintf(archivoHTML,"</h3>\n");
        fseek(archivoHTML, 0L, SEEK_END);
        fprintf(archivoHTML,"<ul>\n");
        fseek(archivoHTML, 0L, SEEK_END);
        fprintf(archivoHTML,"<li>Genero: %s</li>\n",(dir+p)->genero);
        fseek(archivoHTML, 0L, SEEK_END);
        fprintf(archivoHTML,"<li>Puntaje: %d</li>\n",(dir+p)->puntaje);
        fseek(archivoHTML, 0L, SEEK_END);
        fprintf(archivoHTML,"<li>Duracion: %d hora/s</li>\n",(dir+p)->duracion);
        fseek(archivoHTML, 0L, SEEK_END);
        fprintf(archivoHTML,"</ul>\n");
        fseek(archivoHTML, 0L, SEEK_END);
        fprintf(archivoHTML,"<p>Descripcion: %s</p>\n",(dir+p)->descripcion);
        fseek(archivoHTML, 0L, SEEK_END);
        fprintf(archivoHTML,"</article>\n");
        fseek(archivoHTML, 0L, SEEK_END);
        }
    }

    fprintf(archivoHTML,"</div>\n</div>\n<script src='js/jquery-1.11.3.min.js'></script>\n<script src='js/bootstrap.min.js'></script>\n<script src='js/ie10-viewport-bug-workaround.js'></script>\n<script src='js/holder.min.js'></script>\n</body>\n</html>\n");

    fclose(archivoBinario);
    fclose(archivoHTML);
    printf("Archivo HTML creado correctamente\n");
}
