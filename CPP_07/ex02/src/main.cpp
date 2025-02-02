#include "../include/Array.hpp"

#define MAX_VAL 750

int main()
{
    // Probar la construcción por defecto
    Array<int> arrDefault;
    std::cout << "Tamaño de arrDefault: " << arrDefault.size() << std::endl;

    // Probar la construcción con tamaño específico
    int size = 5;
    Array<int> arr(size);
    std::cout << "Tamaño de arr: " << arr.size() << std::endl;

    // Llenar el array con valores
    for (int i = 0; i < size; i++)  // Cambiado 'int' a 'unsigned int'
        arr[i] = i * 10;

    // Mostrar los valores del array
    std::cout << "Valores en arr: ";
    for (int i = 0; i < size; i++)  // Cambiado 'int' a 'unsigned int'
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    // Probar el constructor de copia
    Array<int> arrCopy(arr);
    std::cout << "Valores en arrCopy (copiado de arr): ";
    for (int i = 0; i < arrCopy.size(); i++)  // Cambiado 'int' a 'unsigned int'
        std::cout << arrCopy[i] << " ";
    std::cout << std::endl;

    // Probar el operador de asignación
    Array<int> arrAssign;
    arrAssign = arr;
    std::cout << "Valores en arrAssign (asignado desde arr): ";
    for (int i = 0; i < arrAssign.size(); i++)  // Cambiado 'int' a 'unsigned int'
        std::cout << arrAssign[i] << " ";
    std::cout << std::endl;

    // Probar el manejo de excepción al acceder fuera de los límites
    try {
        std::cout << "Intentando acceder a un índice fuera de rango: " << std::endl;
        std::cout << arr[10] << std::endl;  // Esto debería lanzar una excepción
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
