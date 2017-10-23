#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkDeImagen[300];
    int estado;
}ePelicula;

/** \brief Limpia pantalla.
 */
void fLimpiar();
/** \brief Pide el ingreso y verifica que sea un entero.
 *
 * \param Mensaje a mostrar.
 * \param Mensaje a mostrar si hay un error.
 * \param Numero minimo que se puede ingresar.
 * \param Numero maximo que se puede ingresar.
 * \param Largo maximo que puede llegar a tener el entero ingresado previamente.
 * \return Numero ingresado.
 *
 */
int getInt(char mensajeamostrar[],char erroramostrar[],int minimo,int maximo,int largoentero);
/** \brief Verifica que lo que se ingrese sea un numero.
 *
 * \param Dato a validar.
 * \param Largo del dato a validar.
 * \return Devuelve 1 si el dato es un numero, y 0 si no lo es.
 *
 */
int validaNumero(char datoAValidar[],int largoDato);
/** \brief Pide el ingreso y verfica sea de tipo char (sin numeros).
 *
 * \param Ingreso (dato a validar).
 * \param Mensaje a mostrar.
 * \param Mensaje a mostrar si hay un error.
 * \param Largo maximo que puede llegar a tener el char (sin numeros) ingresado previamente.
 *
 */
void getChar(char ingreso[],char mensajeamostrar[],char erroramostrar[],int largoChar);
/** \brief Verifica que lo que se ingrese sea una letra.
 *
 * \param Dato a validar
 * \param Largo del dato a validar.
 * \return Devuelve 1 si el dato es una letra, y 0 si no lo es.
 *
 */
int validaLetra(char datoAValidar[],int largoDato);
/** \brief Agrega una pelicula en el archivo binario.
 *
 * \param Pelicula, la estructura a ser agregada en el archivo.
 *
 */
void agregarPelicula(ePelicula pelicula);
/** \brief Modifica una pelicula en el archivo binario.
 *
 * \param Pelicula, la estructura a ser modificada en el archivo.
 *
 */
void modificarPelicula(ePelicula pelicula);
/** \brief Elimina una pelicula del archivo binario.
 *
 * \param Pelicula, la estructura a ser eliminada en el archivo.
 *
 */
void borrarPelicula(ePelicula pelicula);
/** \brief Genera el archivo html a partir del archivo binario.
 */
void html();

#endif // FUNCIONES_H_INCLUDED
