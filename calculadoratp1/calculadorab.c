 void bienvenida()
 {
    printf("\n---------------------------------------------------");
    printf("\n|><><><><><|BIENVENIDO A LA CALCULADORA|><><><><><|");
    printf("\n---------------------------------------------------\n\n");

    system("pause");
    system("cls");
 }
void menuCalculadora()
{
    int numeroUno;
    int numeroDos;
    int opcion;
    char respuesta ;

    int banderaX=0;
    int banderaY=0;

    respuesta='s';

    printf("\n ======MENU======\n");

    while(respuesta=='s')
    {
        //OPCION1
        if (banderaX)
        {
            printf("\n 1-- Ingresar 1er operando A = %d \n",numeroUno);
        }else{
            printf("\n 1-- Ingresar 1er operando (A = x)");
        }

        //OPCION2
        if(/*opcion==2 ||*/ banderaY )
        {
            printf("\n 2-- Ingresar 2do operando B = %d \n",numeroDos);
        }else{
            printf("\n 2-- Ingresar 2er operando (B = y)");
        }

        //OPCION3
         printf("\n 3-- Calcular Operaciones");

         printf("\n 4-- Resultados ");

         printf("\n 5-- Salir \n");


        printf("\n º Elija una opcion º:\n ");
        scanf("%d",& opcion);



    switch(opcion)
    {
        case 1:
            printf("Numero A es : ");
            scanf("%d",& numeroUno);
            banderaX=1;
            break;

        case 2:
            printf("Numero B es: ");
            scanf("%d",& numeroDos);
            banderaY=1;
            break;

        case 3:
            calcularOperaciones(numeroUno, numeroDos, banderaX, banderaY);
            break;

             //infomarResultados
        case 4:
            mostrarTodasLasOperaciones( numeroUno, numeroDos);
            break;

        case 5:
            respuesta = 'n';
            break;
        default:

            printf("\n\n [ ERROR ],Ingrese una opcion valida\n\n");
            break;
        }

        system("\n\n pause");
        system("cls");
    }
}

 int sumar(int num1, int num2)
 {
     int resultado=  num1+ num2;
     return resultado;
 }

 int restar(int num1, int num2)
 {
     int resultado=  num1- num2;
     return resultado;
 }
 int multiplicar(int num1, int num2)
 {
     int resultado;
     resultado= num1* num2;
     return resultado;
 }

  float dividir(int num1, int num2)
 {
    float resultado;
    resultado= (float) num1/num2;
    return resultado;
 }

 long long int factorial(int numero )
{
    long long int fact;

    if(numero >= 0 )
    {
        if (numero == 1 || numero==0)
        {
            fact=1;
        }
        else
        {
            fact= numero*factorial(numero-1);
        }
    }

    return fact;
}
int calcularOperaciones(numeroUno, numeroDos, flagX, flagY)
{
        if( flagX && flagY)
        {
            printf("(a) -Calcular la suma (%d + %d)\n",numeroUno,numeroDos);
            printf("(b) -Calcular la resta (%d - %d)\n",numeroUno,numeroDos);
            printf("(c) -Calcular la division (%d / %d)\n",numeroUno,numeroDos);
            printf("(d) -Calcular la multiplicacion (%d * %d)\n",numeroUno,numeroDos);
            printf("(e) -Calcular el factorial (%d y %d)\n\n",numeroUno,numeroDos);

            printf("\n Las operaciones fueron calculadas correctamente \n\n");
        }

        else
        {
            printf("Ingrese los operandos faltantes\n");
            printf("a) -Calcular la suma (A + B)\n");
            printf("b) -Calcular la resta (A - B)\n");
            printf("c) -Calcular la division (A / B)\n");
            printf("d) -Calcular la multiplicacion (A * B)\n");
            printf("e) -Calcular el factorial (A y B)\n\n");
        }

    return 0;
}
void mostrarTodasLasOperaciones(int numeroUno, int numeroDos)
{
    printf(" \n El resultado de  A+B es: %d",sumar(numeroUno,numeroDos));
    printf(" \n El resultado de  A-B es: %d",restar(numeroUno,numeroDos));

    if(numeroDos==0)
    {
        printf("\n No es posible dividir por cero ,ingrese otro numero\n");
    }else{
        printf("\n El resultado de  A/B es: %.2f",dividir(numeroUno,numeroDos));
    }
    printf("\n El resultado de  A*B es: %d ", multiplicar(numeroUno, numeroDos));

    printf("\n El factorial de  A es: %lld y El factorial de B es: %lld\n ",factorial(numeroUno),factorial(numeroDos));

}
