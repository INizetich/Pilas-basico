#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
///IGNACIO NIZETICH| UTN MAR DEL PLATA
void cargarPila (Pila *dada);

int main()
{
    Pila dada,aux1,aux2, a;
    inicpila(&dada);
    inicpila(&a);
    inicpila(&aux1);
    inicpila(&aux2);
 int suma = 0, opc, contador = 0;

 printf("--------ELIJA UNA OPCION---------\n");
 fflush(stdin);
 scanf("%i", &opc);


 switch (opc) {

 case 1:
    cargarPila(&dada);
     mostrar(&dada);


     while (!pilavacia(&dada)) {

            suma = suma + tope(&dada);

            apilar(&aux1, desapilar(&dada));
     }

     printf("La suma es: %i", suma);

     break;

 case 2:
     cargarPila(&dada);


     while (!pilavacia(&dada)) {
        apilar(&aux1, desapilar(&dada));

        contador = contador + 1;

     }

     printf("la cantidad de numeros que tenia la pila dada es de: %i \n", contador);

    break;

 case 3:

     cargarPila(&dada);

     while (!pilavacia(&dada)) {

       suma = suma + tope(&dada);
        contador = contador + 1;
        apilar(&aux1, desapilar(&dada));


     }

     printf("El promedio de la pila es de: %i", suma/contador);


    break;

 case 4:

     cargarPila(&dada);


     apilar(&aux1, desapilar(&dada));


     while(!pilavacia(&dada)) {
        if (tope(&dada)>tope(&aux1)) {
                apilar(&aux2, desapilar(&dada));

        } else {
        apilar(&aux2, desapilar(&aux1));
        apilar(&aux1, desapilar(&dada));

        }
     }
while (!pilavacia(&aux2)) {
    apilar(&dada, desapilar(&aux2));
}


    printf("el menor elementos es: ");
    mostrar(&aux1);
    printf("PILA ORIGINAL SIN EL MENOR: ");
    mostrar(&dada);

    break;

 case 5:
     cargarPila(&dada);
     printf("\n\nQue valor insertamos?\n");
        leer(&a);

        while(!pilavacia(&dada))
        {
            if(tope(&dada)<tope(&a))
            {
                apilar(&aux1, desapilar(&dada));
            }
            if(tope(&a) < tope(&dada))
            {
                apilar(&aux1, desapilar(&a));
            }

        }

        while(!pilavacia(&aux1))
        {
            apilar(&dada, desapilar(&aux1));
        }

        mostrar(&dada);

    break;



 default:
     printf("OPCION NO VALIDA. ");
     break;

 }
    return 0;
}



void cargarPila (Pila *dada)
{
    char eleccion;

    do
    {
        leer(dada);
        printf("escriba s para continuar: ");
        fflush(stdin);
        scanf("%c",  &eleccion);


    }
    while (eleccion == 's');
}


