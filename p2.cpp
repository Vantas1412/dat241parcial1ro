#include <iostream>

int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

int multiplicacion(int a, int b) {
    int resultado = 0;
    int *p_resultado = &resultado; // Puntero a resultado
    for (int i = 0; i < b; i++) {
        *p_resultado += a; // Incrementar el valor apuntado por el puntero
    }
    return resultado;
}

int division(int a, int b) {
    int resultado = 0;
    int *p_resultado = &resultado; // Puntero a resultado
    while (a >= b) {
        a -= b;
        (*p_resultado)++; // Incrementar el valor apuntado por el puntero
    }
    return resultado;
}

int main() {
    int x = 5;
    int y = 2;
    std::cout << "suma: " << suma(x, y) << std::endl;
    std::cout << "resta: " << resta(x, y) << std::endl;
    std::cout << "multiplicacion: " << multiplicacion(x, y) << std::endl;
    std::cout << "division: " << division(x, y) << std::endl;

    return 0;
}