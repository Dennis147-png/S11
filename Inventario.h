#define MAX 10

typedef struct {
    char titulo[100];
    char autor[50];
    int anio_publicacion;
    int ID;
    int disponible;

} Libro;

void menuInventario();
void ingresarLibro(Libro libros[], int *contador);
int idUnico(const Libro libros[], int contador, int id);
void mostrarLibros(const Libro libros[], int contador);
int buscarLibroPorID(const Libro libros[], int contador, int id);
int buscarLibroPorTitulo(const Libro libros[], int contador, const char TituloBuscar[]);
void prestarLibro(Libro libros[], int contador, int id);
void devolverLibro(Libro libros[], int contador, int id);
void eliminarLibro(Libro libros[], int *contador, int id);

