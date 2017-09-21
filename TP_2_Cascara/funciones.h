#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int dni;
    int estado;
    int posicion;

}ePersona;
void fLimpiar();
/** \brief Inicializa todos los datos dentro de la estructura en 0.
 *
 * \param El vector del individuo.
 * \param La cantidad de individuos.
 *
 */

void fInicializar(ePersona individuo[], int cantidad);
/** \brief Obtiene el primer indice libre del vector (array).
 *
 * \param Individuo (Array que se pasa como parametro).
 * \return Devuelve el indice.
 * \return  Devuelve -1 si no hay mas espacio.
 *
 */

int fEspacioLibre(ePersona individuo[], int cantidad);
/** \brief Carga Nombre, Edad, DNI y estado.
 *
 * \param Individuo (Array que se pasa como parametro).
 * \param Indice en el cual cargar datos.
 *
 */

void fAgregarPersona(ePersona individuo[], int indice);
/** \brief Muestra los datos de las personas cargadas.
 *
 * \param Individuo (Array que se pasa como parametro).
 * \param Cantidad de personas totales.
 *
 */

void fMostrarPersona(ePersona individuo[], int cantidad);
/** \brief Verifica que se haya ingresado el nombre correctamente.
 *
 * \param Nombre (Array que se pasa como parametro).
 * \param Tamaño del array.
 * \return Devuelve 0 si es incorrecto el ingreso.
 * \return  Devuelve 1 si es correcto el ingreso.
 *
 */

int fVerificarNombre(char auxNombre[], int tam);
/** \brief Verifica que se haya ingresado el nombre correctamente.
 *
 * \param Edad (Array que se pasa como parametro).
 * \return Devuelve 0 si es incorrecto el ingreso.
 * \return Devuelve 1 si es correcto el ingreso.
 *
 */

int fVerificarEdad(char auxEdad[]);
/** \brief Verifica que se haya ingresado el DNI correctamente.
 *
 * \param Individuo (Array que se pasa como parametro).
 * \param DNI (Array que se pasa como parametro).
 * \param Cantidad de personas totales.
 * \return Devuelve 0 si es incorrecto el ingreso.
 * \return Devuelve 1 si es correcto el ingreso.
 * \return  Devuelve 2 si se encuentra un dni que ya se ingreso.
 *
 */

int fVerificarDNI(ePersona individuo[],char auxDNI[], int tam);
/** \brief Muestra un grafico con las edades.
 *
 * \param Individuo (Array que se pasa como parametro).
 * \param Cantidad de personas totales.
 *
 */

void graficoEdades(ePersona individuo[], int tam);
/** \brief Busca un DNI en el array de individuos y elimina a la persona.
 *
 * \param Individuo (Array que se pasa como parametro).
 * \param Cantidad de personas totales.
 *
 */

void fBuscarPorDNI(ePersona individuo[], int cantidad);

#endif // FUNCIONES_H_INCLUDED
