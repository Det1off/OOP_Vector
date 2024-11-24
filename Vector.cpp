#include "Vector.h"

// Конструктор по умолчанию
Vector::Vector() : size(0), capacity(10) {
    data = new int[capacity];
}

// Конструктор с заданной вместимостью
Vector::Vector(int initialCapacity) : size(0), capacity(initialCapacity) {
    data = new int[capacity];
}

// Конструктор копирования
Vector::Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
    data = new int[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// Деструктор
Vector::~Vector() {
    delete[] data;
}

// Перегрузка оператора присваивания
Vector& Vector::operator=(const Vector& other) {
    if (this == &other) return *this;

    delete[] data;

    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }

    return *this;
}

// Перегрузка оператора []
int& Vector::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

// Вставка элемента по индексу
void Vector::Insert(int index, int value) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of bounds");
    }
    if (size == capacity) resize(capacity * 2);
    for (int i = size; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    ++size;
}

// Удаление элемента по индексу
void Vector::RemoveAt(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

// Удаление элемента по значению
void Vector::RemoveByValue(int value) {
    for (int i = 0; i < size; ++i) {
        if (data[i] == value) {
            RemoveAt(i);
            --i; // Чтобы снова проверить текущий индекс после сдвига
        }
    }
}

// Удаление первого элемента
void Vector::PopFront() {
    if (size == 0) throw std::out_of_range("Vector is empty");
    RemoveAt(0);
}

// Удаление последнего элемента
void Vector::PopBack() {
    if (size == 0) throw std::out_of_range("Vector is empty");
    --size;
}

// Подгонка вместимости под размер
void Vector::TrimToSize() {
    resize(size);
}

// Поиск первого вхождения
int Vector::IndexOf(int value) const {
    for (int i = 0; i < size; ++i) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

// Поиск последнего вхождения
int Vector::LastIndexOf(int value) const {
    for (int i = size - 1; i >= 0; --i) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

// Изменение порядка следования элементов
void Vector::Reverse() {
    std::reverse(data, data + size);
}

// Сортировка по возрастанию
void Vector::SortAsc() {
    std::sort(data, data + size);
}

// Сортировка по убыванию
void Vector::SortDesc() {
    std::sort(data, data + size, std::greater<int>());
}

// Случайное перемешивание элементов
void Vector::Shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(data, data + size, g);
}

// Заполнение случайными значениями
void Vector::RandomFill(int minValue, int maxValue) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minValue, maxValue);
    for (int i = 0; i < size; ++i) {
        data[i] = dis(gen);
    }
}

// Сравнение двух векторов
bool Vector::Equals(const Vector& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

// Получение элемента по индексу
int Vector::GetElementAt(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

// Создание копии вектора
Vector Vector::Clone() const {
    return *this;
}

// Перегрузка оператора ==
bool Vector::operator==(const Vector& other) const {
    return Equals(other);
}

// Перегрузка оператора <<
std::ostream& operator<<(std::ostream& os, const Vector& v) {
    for (int i = 0; i < v.size; ++i) {
        os << v.data[i] << " ";
    }
    return os;
}

// Перегрузка оператора >>
std::istream& operator>>(std::istream& is, Vector& v) {
    int value;
    while (is >> value) {
        v.Insert(v.size, value);
    }
    return is;
}

// Получение размера вектора
int Vector::getSize() const {
    return size;
}

// Проверка, пустой ли вектор
bool Vector::isEmpty() const {
    return size == 0;
}

// Вспомогательный метод для изменения размера массива
void Vector::resize(int newCapacity) {
    if (newCapacity <= capacity) return; // Если новая вместимость не больше текущей, ничего не делаем
    int* newData = new int[newCapacity];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}
