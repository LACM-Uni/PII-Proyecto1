
class Matriz
{
    public:

    Matriz(int, int);

    void llenar_matriz();
    void mostrar_matriz();

    void producto_matriz(const Matriz , Matriz );
    void sumar_matriz(const Matriz );
    void escalar_por_matriz(float );
    void gauss_jordan(const int );

     ~Matriz();


    private:
        int filas, columnas;
        float **matriz;
};
