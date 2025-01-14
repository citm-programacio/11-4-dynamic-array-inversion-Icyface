#include <iostream>
using namespace std;

class DynamicArray {
private:
    int *array;
    int size;
    int capacity;

public:
    // Constructor
    DynamicArray(int initial_capacity = 10) : size(0), capacity(initial_capacity) {
        array = new int[capacity];
    }

    // Destructor
    ~DynamicArray() {
        delete[] array;
    }

    // Función para agregar un elemento al final
    void push_back(int value) {
        if (size == capacity) {
            resize();
        }
        array[size++] = value;
    }

    // Función para redimensionar el array
    void resize() {
        capacity *= 2;
        int *new_array = new int[capacity];
        for (int i = 0; i < size; ++i) {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
    }

    // Función para imprimir el array
    void print() const {
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    // Función para invertir el orden de los elementos
    void invert() {
        for (int i = 0; i < size / 2; ++i) {
            swap(array[i], array[size - i - 1]);
        }
    }
};

int main() {
    // Crear una instancia de DynamicArray
    DynamicArray arr;

    // Agregar elementos al array
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);

    // Imprimir el array antes de invertir
    cout << "Array antes de invertir:" << endl;
    arr.print();

    // Invertir el array
    arr.invert();

    // Imprimir el array después de invertir
    cout << "Array después de invertir:" << endl;
    arr.print();

    return 0;
}