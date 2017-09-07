void fColor()
{
    system ("color 0B"); //Cambio color de pantalla
}
void fLimpiar()
{

    system("cls"); //Limpio pantalla

}
float fpedirNumero(char mensaje[])
{

    float numero;
    printf("%s",mensaje);
    scanf("%f",&numero);
    system("cls");
    return numero;

}
int fVerificacionAB(int flagA, int flagB)
{

    if(flagA == 0 || flagB == 0) //Si no se ingreso el numero (A) o (B), devuelve 0.
    {
        return 0;
    }
    else // Si se ingresaron devuelvo 1.
    {
        return 1;
    }
}
float fSuma(float a, float b)
{

    float resultado;
    resultado = a + b;
    return resultado;

}
float fResta(float a, float b)
{
    float resultado;
    resultado = a - b;
    return resultado;
}
int fVerificacionDivision(float b,int flagA, int flagB)
{

    if(flagA == 0 || flagB == 0) // Si no se ingreso uno de los 2 numeros devuelve el numero 2.
    {
        return 2;
    }
    else if(b == 0) // Si el numero (B) es 0, devuelve el numero 0.
    {
        return 0;
    }
    else // Si todo es correcto devuelvo el numero 1.
    {
        return 1;
    }

}
float fDivision(float a, float b)
{

    float resultado;
    resultado = a / b;
    return resultado;


}
float fMultiplicacion(float a, float b)
{

    float resultado;
    resultado = a * b;
    return resultado;


}
int fVerificacionFactorial(float a, int flagA)
{

    float prueba = 0;
    /*Divido el numero sin parsear sobre el numero parseado, si da distinto de 1 es porque es decimal o 0*/
    prueba = a / (int)a;

    if(flagA == 0)//Si el numero (A) no se ingreso devuelvo 0.
    {
        return 0;
    }
    /*Si prueba es distinto de 1, es decimal o 0 pero excluyo el 0 porque a este si
     se le puede realizar la factorial, tambien verifico que la bandera este en 1
                (para verificar que el numero se ingreso) */

    else if(prueba!=1 && flagA == 1 & a!=0)//Si el numero es decimal devuelvo 2.
    {
        return 2;
    }
    else if(a>20) // Si el numero es mayor a 20 devuelvo 3.
    {
        return 3;
    }
    else if(a<0) // Si el numero no es positivo devuelvo 4
    {
        return 4;
    }
    else // Si todo es correcto devuelvo 1.
    {
        return 1;
    }
}
long long int fFactorial(long long int a)
{

    long long int acum = 1;

    if(a==1 || a==0)// Si el numero (A) es 1 o 0, su factorial es 1.
    {
        acum = 1;
    }
    for(; a>0; a--)
    {
        acum = acum*a;
    }

    return acum;

}
