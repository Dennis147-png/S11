#include <stdio.h>
#include <string.h>
#include "lectura.h"
#include "Inventario.h"

int main(int argc, char const *argv[])
{
    Libro libros[MAX];
    char TituloBuscar[50];
    int opcion;
    int contador = 0;   
    do {
        menuInventario();
        opcion = ingresoEntre("Seleccione una opcion: ", 1, 8);
        switch (opcion) {
            case 1:
                ingresarLibro(libros, &contador);
                break;
            case 2:
                mostrarLibros(libros, contador);
                break;
            case 3: {
                int id = ingresaEntero("Ingrese el ID del libro que desea buscar: ");
                int indice = buscarLibroPorID(libros, contador, id);
                if (indice != -1) {
                    printf("Libro encontrado: %s por %s | Estado: %s\n", 
               libros[indice].titulo, 
               libros[indice].autor,
               libros[indice].disponible ? "Disponible" : "Prestado");
                } else {
                    printf("Libro con ID %d no encontrado.\n", id);
                }
                break;
            }
            case 4: {
                if (contador == 0)
                {
                    printf("No hay libros en la biblioteca.\n");
                    break;
                }
                printf("Ingrese el titulo EXACTO del libro que desea buscar: ");
                fgets(TituloBuscar, 50, stdin);
                TituloBuscar[strcspn(TituloBuscar, "\n")] = '\0';
                int indice = buscarLibroPorTitulo(libros, contador, TituloBuscar);
                if (indice != -1) { 
                     printf("Libro encontrado: %s por %s | Estado: %s\n", 
               libros[indice].titulo, 
               libros[indice].autor,
               libros[indice].disponible ? "Disponible" : "Prestado");
                } else {
                    printf("Libro con titulo '%s' no encontrado.\n", TituloBuscar);
                }
                break;
            }
            case 5: {
                int id = ingresaEntero("Ingrese el ID del libro a prestar: ");
                prestarLibro(libros, contador, id);
                break;
            }
            case 6: {
                int id = ingresaEntero("Ingrese el ID del libro a devolver: ");
                devolverLibro(libros, contador, id);
                break;
            }
            case 7: {
                int id = ingresaEntero("Ingrese el ID del libro a eliminar: ");
                eliminarLibro(libros, &contador, id);
                break;
            }
            case 8:
                printf("Saliendo del sistema de biblioteca.\n");
                break;
            default:
                printf("Opcion invalida. Por favor intente de nuevo.\n");
        }
    } while(opcion != 8);
    
    return 0;
}
