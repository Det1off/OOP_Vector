#include "Vector.h"

int main() {
    Vector vec;

    // Вставка элементов
    vec.Insert(0, 5);
    vec.Insert(1, 10);
    vec.Insert(1, 7);

    std::cout << "Vector: " << vec << std::endl;

    // Удаление элемента по индексу
    vec.RemoveAt(1);
    std::cout << "After RemoveAt(1): " << vec << std::endl;

    // Поиск элемента
    int index = vec.IndexOf(10);
    std::cout << "Index of 10: " << index << std::endl;

    // Сортировка
    vec.SortAsc();
    std::cout << "Sorted Ascending: " << vec << std::endl;

    // Клонирование
    Vector clonedVec = vec.Clone();
    std::cout << "Cloned Vector: " << clonedVec << std::endl;

}
