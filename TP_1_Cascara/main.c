#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    fColor(); //Cambiar color pantalla
    float numeroUno,numeroDos,resultadoFinal;
    long long int resultadoFactorial;
    int verificacionFinal;
    int flagA = 0,flagB = 0;
    char seguir='s';
    int opcion=0;
    fflush(stdin);

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n",numeroUno);
        printf("2- Ingresar 2do operando (B=%.2f)\n",numeroDos);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            fLimpiar();
            numeroUno = fpedirNumero("Ingrese numero (A): ");
            flagA = 1;
            break;
        case 2:
            fLimpiar();
            numeroDos = fpedirNumero("Ingrese numero (B): ");
            flagB = 1;
            break;
        case 3:
            fLimpiar();
            verificacionFinal = fVerificacionAB(flagA,flagB);
            if(verificacionFinal == 1)
            {
                resultadoFinal = fSuma(numeroUno,numeroDos);
                printf("Resultado de la suma: %.2f\n\n",resultadoFinal);
            }
            else
            {
                printf("Error, fallo operacion. Ingresar ambos numeros (A) y (B) antes de sumar.\n\n");
            }
            break;
        case 4:
            fLimpiar();
            verificacionFinal = fVerificacionAB(flagA,flagB);
            if(verificacionFinal == 1)
            {
                resultadoFinal = fResta(numeroUno,numeroDos);
                printf("Resultado de la resta: %.2f\n\n",resultadoFinal);
            }
            else
            {
                printf("Error, fallo operacion. Ingresar ambos numeros (A) y (B) antes de restar.\n\n");
            }
            break;
        case 5:
            fLimpiar();
            verificacionFinal = fVerificacionDivision(numeroDos,flagA,flagB);
            if(verificacionFinal == 1)
            {
                resultadoFinal = fDivision(numeroUno,numeroDos);
                printf("Resultado de la division: %.2f\n\n",resultadoFinal);
            }
            else if(verificacionFinal == 0)
            {
                printf("Error gravisimo!, la calculadora no puede dividir por 0!.\n\n");
            }
            else
            {
                printf("Error, fallo operacion. Ingresar ambos numeros (A) y (B) antes de dividir.\n\n");
            }
            break;
        case 6:
            fLimpiar();
            verificacionFinal = fVerificacionAB(flagA,flagB);
            if(verificacionFinal == 1)
            {
                resultadoFinal = fMultiplicacion(numeroUno,numeroDos);
                printf("Resultado de la multiplicacion: %.2f\n\n",resultadoFinal);
            }
            else
            {
                printf("Error, fallo operacion. Ingresar ambos numeros (A) y (B) antes de multiplicar.\n\n");
            }
            break;
        case 7:
            fLimpiar();
            verificacionFinal = fVerificacionFactorial(numeroUno,flagA);
            if(verificacionFinal == 1)
            {
                resultadoFactorial = fFactorial(numeroUno);
                printf("Resultado de la factorial: %lli\n\n",resultadoFactorial);
            }
            else if(verificacionFinal == 0)
            {
                printf("Error, fallo la operacion. Ingrese el numero (A) antes de realizar la factorial.\n\n");
            }
            else if(verificacionFinal == 2)
            {
                printf("Error, no se permiten numeros decimales en la factorial.\n\n");
            }
            else if(verificacionFinal == 3)
            {
                printf("Error, el limite para calcular factorial es 20. Por favor ingrese un numero menor a 20.\n\n");
            }
            else
            {
                printf("Error, ingrese un numero positivo para realizar la factorial.\n\n");
            }
            break;
        case 8:
            fLimpiar();
            verificacionFinal = fVerificacionAB(flagA,flagB);
            if(verificacionFinal == 1)
            {
                resultadoFinal = fSuma(numeroUno,numeroDos);
                printf("Resultado de la suma: %.2f\n\n",resultadoFinal);
            }
            else
            {
                printf("Error, fallo operacion. Ingresar ambos numeros (A) y (B) antes de sumar.\n\n");
            }
            verificacionFinal = fVerificacionAB(flagA,flagB);
            if(verificacionFinal == 1)
            {
                resultadoFinal = fResta(numeroUno,numeroDos);
                printf("Resultado de la resta: %.2f\n\n",resultadoFinal);
            }
            else
            {
                printf("Error, fallo operacion. Ingresar ambos numeros (A) y (B) antes de restar.\n\n");
            }
            verificacionFinal = fVerificacionDivision(numeroDos,flagA,flagB);
            if(verificacionFinal == 1)
            {
                resultadoFinal = fDivision(numeroUno,numeroDos);
                printf("Resultado de la division: %.2f\n\n",resultadoFinal);
            }
            else if(verificacionFinal == 0)
            {
                printf("Error gravisimo!, la calculadora no puede dividir por 0!.\n\n");
            }
            else
            {
                printf("Error, fallo operacion. Ingresar ambos numeros (A) y (B) antes de dividir.\n\n");
            }
            verificacionFinal = fVerificacionAB(flagA,flagB);
            if(verificacionFinal == 1)
            {
                resultadoFinal = fMultiplicacion(numeroUno,numeroDos);
                printf("Resultado de la multiplicacion: %.2f\n\n",resultadoFinal);
            }
            else
            {
                printf("Error, fallo operacion. Ingresar ambos numeros (A) y (B) antes de multiplicar.\n\n");
            }
            verificacionFinal = fVerificacionFactorial(numeroUno,flagA);
            if(verificacionFinal == 1)
            {
                resultadoFactorial = fFactorial(numeroUno);
                printf("Resultado de la factorial: %lli\n\n",resultadoFactorial);
            }
            else if(verificacionFinal == 0)
            {
                printf("Error, fallo la operacion. Ingrese el numero (A) antes de realizar la factorial.\n\n");
            }
            else if(verificacionFinal == 2)
            {
                printf("Error, no se permiten numeros decimales en la factorial.\n\n");
            }
            else if(verificacionFinal == 3)
            {
                printf("Error, el limite para calcular factorial es 20. Por favor ingrese un numero menor a 20.\n\n");
            }
            else
            {
                printf("Error, ingrese un numero positivo para realizar la factorial.\n\n");
            }
            break;
        case 9:
            seguir = 'n';
            break;
        }

    }

    system("pause");
    return 0;

}
