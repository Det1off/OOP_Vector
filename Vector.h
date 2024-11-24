#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdexcept>
#include <random>

class Vector {
private:
    int* data;        // ��������� �� ������������ ������
    int size;         // ������� ������ �������
    int capacity;     // ����������� �������

    void resize(int newCapacity);

public:
    // �����������
    Vector();
    Vector(int initialCapacity);

    // ����������� �����������
    Vector(const Vector& other);

    // ����������
    ~Vector();

    // ���������� ��������� ������������
    Vector& operator=(const Vector& other);

    // ���������� ��������� []
    int& operator[](int index);

    // ������
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

    // ���������� ��������� ==
    bool operator==(const Vector& other) const;

    // ���������� ��������� <<
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);

    // ���������� ��������� >>
    friend std::istream& operator>>(std::istream& is, Vector& v);

    // ��������� ������� �������
    int getSize() const;

    // ��������, ������ �� ������
    bool isEmpty() const;
};


