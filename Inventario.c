#include <stdio.h>
#include <string.h>
#include "lectura.h"
#include "Inventario.h"

void menuInventario() {
    
    printf("\n--- Biblioteca ---\n");
    printf("1. Ingresar Libro\n");
    printf("2. Mostrar Libros\n"); 
    printf("3. Buscar Libro por ID\n");
    printf("4. Buscar Libro por Titulo\n");  
    printf("5. Prestar Libro\n");
    printf("6. Devolver Libro\n");
    printf("7. Eliminar Libro\n");  
    printf("8. Salir\n");
}
int idUnico(const Libro libros[], int contador, int id) {
    for (int i = 0; i < contador; i++) {
        if (libros[i].ID == id) {
            return 0; 
        }
    }
    return 1; 
}
void ingresarLibro(Libro libros[], int *contador) {
    if (*contador >= MAX) {
        printf("Capacidad maxima de libros alcanzada.\n");
        return;
    }
    printf("\n--- Ingresar Nuevo Libro ---\n");
    printf("Titulo: ");
    fgets(libros[*contador].titulo, 100, stdin);
    libros[*contador].titulo[strcspn(libros[*contador].titulo, "\n")] = '\0';
    printf("Autor: ");
    fgets(libros[*contador].autor, 50, stdin);
    libros[*contador].autor[strcspn(libros[*contador].autor, "\n")] = '\0';
    libros[*contador].anio_publicacion = ingresaEntero("Anio de Publicacion: ");
    do {
        libros[*contador].ID = ingresaEntero("ID del Libro: ");
        if (!idUnico(libros, *contador, libros[*contador].ID)) {
            printf("ID ya existe. Ingrese un ID unico: ");
        }
    } while(!idUnico(libros, *contador, libros[*contador].ID));
    libros[*contador].disponible = 1; // Disponible por defecto
    (*contador)++; 
    printf("Libro ingresado exitosamente.\n");
}
void mostrarLibros(const Libro libros[], int contador) {
    if (contador == 0) {
        printf("No hay libros en la biblioteca.\n");
        return;
    }
    printf("\n--- Lista de Libros ---\n");
    for (int i = 0; i < contador; i++) {
        printf("  Libro  | Titulo: %s | Autor: %s | Anio: %d | ID: %d | Estado: %s\n", 
               libros[i].titulo, 
               libros[i].autor, 
               libros[i].anio_publicacion, 
               libros[i].ID, 
               libros[i].disponible ? "Disponible" : "Prestado");
        
    }

}
int buscarLibroPorID(const Libro libros[], int contador, int id){    
    for (int i = 0; i < contador; i++) {
        if (libros[i].ID == id) {
            return i; 
        }
    }
    return -1;
}
int buscarLibroPorTitulo(const Libro libros[], int contador, const char TituloBuscar[]){
    for (int i = 0; i < contador; i++) {
        if (strcmp(libros[i].titulo, TituloBuscar) == 0) {
            return i; 
        }
    }
    return -1;
}

void prestarLibro(Libro libros[], int contador, int id) {
    int indice = buscarLibroPorID(libros, contador, id);
    if (indice == -1) {
        printf("Libro con ID %d no encontrado.\n", id);
        return;
    }
    if (!libros[indice].disponible) {
        printf("El libro '%s' ya esta prestado.\n", libros[indice].titulo);
        return;
    }
    libros[indice].disponible = 0; 
    printf("Has prestado el libro %s\n", libros[indice].titulo);
}
void devolverLibro(Libro libros[], int contador, int id) {
    int indice = buscarLibroPorID(libros, contador, id);
    if (indice == -1) {
        printf("Libro con ID %d no encontrado.\n", id);
        return;
    }
    if (libros[indice].disponible) {
        printf("El libro '%s' no esta prestado.\n", libros[indice].titulo);
        return;
    }
    libros[indice].disponible = 1; 
    printf("Has devuelto el libro %s\n", libros[indice].titulo);
}
void eliminarLibro(Libro libros[], int *contador, int id) {
    int indice = buscarLibroPorID(libros, *contador, id);
    if (indice == -1) {
        printf("Libro con ID %d no encontrado.\n", id);
        return;
    }
    for (int i = indice; i < *contador - 1; i++) {
        libros[i] = libros[i + 1];
    }
    (*contador)--; 
    printf("Libro con ID %d eliminado exitosamente.\n", id);
}