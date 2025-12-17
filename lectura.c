#include <stdio.h>
#include "lectura.h"

int ingresaEntero(char *mensaje){
    int valor;
    printf("%s: ", mensaje);
    while (scanf("%d", &valor) != 1 || valor <= 0)
    {
        while(getchar() != '\n');
        printf("El dato debe ser un numero entero positivo (mayor que 0)\n");
        printf("%s: ", mensaje);
    }
    while(getchar() != '\n'); 
    return valor;
}

int ingresarMayorIgual(char *mensaje, int min){
    int valor;
    printf("%s: ", mensaje);
    while (scanf("%d", &valor) != 1 || valor < min)
    {
        while(getchar() != '\n');
        printf("El dato debe ser un numero entero mayor o igual que %d\n", min);
        printf("%s: ", mensaje);
    }
    while(getchar() != '\n'); 
    return valor;
}

int ingresarMenorIgual(char *mensaje, int max){
    int valor;
    printf("%s: ", mensaje);
    while (scanf("%d", &valor) != 1 || valor > max)
    {
        while(getchar() != '\n');
        printf("El dato debe ser un numero entero menor o igual que %d\n", max);
        printf("%s: ", mensaje);
    }
    while(getchar() != '\n'); 
    return valor;
}

int ingresoEntre(char *mensaje, int min, int max){
    int valor;
    printf("%s: ", mensaje);
    while (scanf("%d", &valor) != 1 || valor < min || valor > max)
    {
        while(getchar() != '\n');
        printf("El dato debe ser un numero entero entre %d y %d\n", min, max);
        printf("%s: ", mensaje);
    }
    while(getchar() != '\n'); 
    return valor;
}


float ingresaFloat(char *mensaje){
    float valor;
    printf("%s: ", mensaje);
    while (scanf("%f", &valor) != 1 || valor <= 0.0)
    {
        while(getchar() != '\n');
        printf("El dato debe ser un numero decimal positivo (mayor que 0)\n");
        printf("%s: ", mensaje);
    }
    while(getchar() != '\n');
    return valor;
}

float ingresarMayorIgualFloat(char *mensaje, float min){
    float valor;
    printf("%s: ", mensaje);
    while (scanf("%f", &valor) != 1 || valor < min)
    {
        while(getchar() != '\n');
        printf("El dato debe ser un numero decimal mayor o igual que %.2f\n", min);
        printf("%s: ", mensaje);
    }
    while(getchar() != '\n'); 
    return valor;
}

float ingresarMenorIgualFloat(char *mensaje, float max){
    float valor;
    printf("%s: ", mensaje);
    while (scanf("%f", &valor) != 1 || valor > max)
    {
        while(getchar() != '\n');
        printf("El dato debe ser un numero decimal menor o igual que %.2f\n", max);
        printf("%s: ", mensaje);
    }
    while(getchar() != '\n'); 
    return valor;
}

float ingresoEntreFloat(char *mensaje, float min, float max){
    float valor;
    printf("%s: ", mensaje);
    while (scanf("%f", &valor) != 1 || valor < min || valor > max)
    {
        while(getchar() != '\n');
        printf("El dato debe ser un numero decimal entre %.2f y %.2f\n", min, max);
        printf("%s: ", mensaje);
    }
    while(getchar() != '\n'); 
    return valor;
}