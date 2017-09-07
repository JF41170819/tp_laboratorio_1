#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Cambia el color de la pantalla.
 */
void fColor();
/** \brief Limpia pantalla.
 */
void fLimpiar();
/** \brief Pide un numero y lo guarda.
 *
 * \param Mensaje a mostrar.
 *
 * \return Devuelvo el numero ingresado.
 *
 */
float fpedirNumero(char mensaje[]);
/** \brief Devuelve 0 si no se ingresaron ambos numeros (A) y (B), y devuelve 1 si se ingresaron ambos numeros.
 *
 * \param Bandera del numero (A).
 * \param Bandera del numero (B).
 * \return Devuelve 0 si no se ingresaron ambos numeros.
 * \return Devuelve 1 si se ingresaron ambos numeros.
 *
 */
int fVerificacionAB(int flagA, int flagB);
/** \brief Suma 2 numeros, (A) y (B)
 *
 * \param Numero (A).
 * \param Numero (B).
 * \return El resultado de la suma.
 *
 */
float fSuma(float a, float b);
/** \brief Resta 2 numeros, (A) y (B)
 *
 * \param Numero (A).
 * \param Numero (B).
 * \return El resultado de la resta.
 *
 */
float fResta(float a, float b);
/** \brief Devuelve el numero 1 si esta todo correcto, devuelve 2 si no se ingresaron ambos numeros (A) y (B) y 0 si (B) = 0.
 *
 * \param Bandera del numero (A).
 * \param Bandera del numero (B).
 * \return Devuelve el numero 2, si no se ingreso uno de los dos numeros o ambos (A) y (B).
 * \return Devuelve el numero 0, si (B) es 0 por lo tanto no se puede realizar la division.
 * \return Devuelve el numero 1 si no hay ningun fallo en la verificacion.
 *
 */
int fVerificacionDivision(float b,int flagA, int flagB);
/** \brief Divide dos numeros, (A) y (B).
 *
 * \param Numero (A).
 * \param Numero (B).
 * \return El resultado de la division.
 *
 */
float fDivision(float a, float b);
/** \brief Multiplica dos numeros, (A) y (B).
 *
 * \param Numero (A).
 * \param Numero (B).
 * \return El resultado de la multiplicacion.
 *
 */
float fMultiplicacion(float a, float b);
/** \brief Devuelve 0 si no se ingreso el numero (A), devuelve 2 si es un numero decimal, devuelve 3 si es mayor a 20 y devuelve 4 si no es positivo.
 *
 * \param Numero (A).
 * \param Bandera (A).
 * \return Devuelve 0, si no se ingreso el numero (A) previamente.
 * \return Devuelve 2, si es un numero decimal.
 * \return Devuelve 3, si el numero es mayor a 20.
 * \return Devuelve 4, si el numero no es positivo.
 *
 */
int fVerificacionFactorial(float a, int flagA);
/** \brief Realiza la factorial del numero (A).
 *
 * \param Numero (A).
 * \return Devuelve el resultado de la factorial.
 *
 */
long long int fFactorial(long long int a);

#endif // FUNCIONES_H_INCLUDED
