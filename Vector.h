#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdexcept>
#include <random>

class Vector {
private:
    int* data;        // Указатель на динамический массив
    int size;         // Текущий размер массива
    int capacity;     // Вместимость массива

    void resize(int newCapacity);

public:
    // Конструктор
    Vector();
    Vector(int initialCapacity);

    // Конструктор копирования
    Vector(const Vector& other);

    // Деструктор
    ~Vector();

    // Перегрузка оператора присваивания
    Vector& operator=(const Vector& other);

    // Перегрузка оператора []
    int& operator[](int index);

    // Методы
    void Insert(int index, int value);
    void RemoveAt(int index);
    void RemoveByValue(int value);
    void PopFront();
    void PopBack();
    void TrimToSize();
    int IndexOf(int value) const;
    int LastIndexOf(int value) const;
    void Reverse();
    void SortAsc();
    void SortDesc();
    void Shuffle();
    void RandomFill(int minValue, int maxValue);
    bool Equals(const Vector& other) const;
    int GetElementAt(int index) const;
    Vector Clone() const;

    // Перегрузка оператора ==
    bool operator==(const Vector& other) const;

    // Перегрузка оператора <<
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);

    // Перегрузка оператора >>
    friend std::istream& operator>>(std::istream& is, Vector& v);

    // Получение размера вектора
    int getSize() const;

    // Проверка, пустой ли вектор
    bool isEmpty() const;
};


