#include "Vector.h"

// ����������� �� ���������
Vector::Vector() : size(0), capacity(10) {
    data = new int[capacity];
}

// ����������� � �������� ������������
Vector::Vector(int initialCapacity) : size(0), capacity(initialCapacity) {
    data = new int[capacity];
}

// ����������� �����������
Vector::Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
    data = new int[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// ����������
Vector::~Vector() {
    delete[] data;
}

// ���������� ��������� ������������
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

// ���������� ��������� []
int& Vector::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

// ������� �������� �� �������
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

// �������� �������� �� �������
void Vector::RemoveAt(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

// �������� �������� �� ��������
void Vector::RemoveByValue(int value) {
    for (int i = 0; i < size; ++i) {
        if (data[i] == value) {
            RemoveAt(i);
            --i; // ����� ����� ��������� ������� ������ ����� ������
        }
    }
}

// �������� ������� ��������
void Vector::PopFront() {
    if (size == 0) throw std::out_of_range("Vector is empty");
    RemoveAt(0);
}

// �������� ���������� ��������
void Vector::PopBack() {
    if (size == 0) throw std::out_of_range("Vector is empty");
    --size;
}

// �������� ����������� ��� ������
void Vector::TrimToSize() {
    resize(size);
}

// ����� ������� ���������
int Vector::IndexOf(int value) const {
    for (int i = 0; i < size; ++i) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

// ����� ���������� ���������
int Vector::LastIndexOf(int value) const {
    for (int i = size - 1; i >= 0; --i) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

// ��������� ������� ���������� ���������
void Vector::Reverse() {
    std::reverse(data, data + size);
}

// ���������� �� �����������
void Vector::SortAsc() {
    std::sort(data, data + size);
}

// ���������� �� ��������
void Vector::SortDesc() {
    std::sort(data, data + size, std::greater<int>());
}

// ��������� ������������� ���������
void Vector::Shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(data, data + size, g);
}

// ���������� ���������� ����������
void Vector::RandomFill(int minValue, int maxValue) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minValue, maxValue);
    for (int i = 0; i < size; ++i) {
        data[i] = dis(gen);
    }
}

// ��������� ���� ��������
bool Vector::Equals(const Vector& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

// ��������� �������� �� �������
int Vector::GetElementAt(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

// �������� ����� �������
Vector Vector::Clone() const {
    return *this;
}

// ���������� ��������� ==
bool Vector::operator==(const Vector& other) const {
    return Equals(other);
}

// ���������� ��������� <<
std::ostream& operator<<(std::ostream& os, const Vector& v) {
    for (int i = 0; i < v.size; ++i) {
        os << v.data[i] << " ";
    }
    return os;
}

// ���������� ��������� >>
std::istream& operator>>(std::istream& is, Vector& v) {
    int value;
    while (is >> value) {
        v.Insert(v.size, value);
    }
    return is;
}

// ��������� ������� �������
int Vector::getSize() const {
    return size;
}

// ��������, ������ �� ������
bool Vector::isEmpty() const {
    return size == 0;
}

// ��������������� ����� ��� ��������� ������� �������
void Vector::resize(int newCapacity) {
    if (newCapacity <= capacity) return; // ���� ����� ����������� �� ������ �������, ������ �� ������
    int* newData = new int[newCapacity];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}
