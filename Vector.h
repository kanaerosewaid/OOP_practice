#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector {
private:
    T* array;      // Динамічний масив для збереження елементів
    int size;      // Поточна кількість елементів
    int capacity;  // Поточна ємність масиву

public:
    // Конструктор за замовчуванням
    Vector() : size(0), capacity(10) {
        array = new T[capacity];
    }

    // Деструктор
    ~Vector() {
        delete[] array;
    }

    // Метод отримання кількості елементів
    int getSize() const {
        return size;
    }

    // Метод отримання ємності контейнера
    int getCapacity() const {
        return capacity;
    }

    // Метод додавання елемента в кінець
    void push_back(T element) {
        if (size == capacity) {
            capacity *= 2;
            T* newArray = new T[capacity];
            for (int i = 0; i < size; ++i) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
        array[size++] = element;
    }

    // Метод видалення останнього елемента
    void pop_back() {
        if (size > 0) {
            --size;
        } else {
            throw std::out_of_range("Vector is empty");
        }
    }

    // Метод отримання елемента за індексом
    T at(int index) const {
        if (index >= 0 && index < size) {
            return array[index];
        }
        throw std::out_of_range("Index out of range");
    }

    // Перевантаження оператора []
    T& operator[](int index) {
        if (index >= 0 && index < size) {
            return array[index];
        }
        throw std::out_of_range("Index out of range");
    }
};

#endif // VECTOR_H
