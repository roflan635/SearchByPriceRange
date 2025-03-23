// Task.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "Task.h"
#include <iostream>

void AddFirst(ListItem*& firstItem, int productId, const char* productName, float productPrice, float productCount)
{
    ListItem* temp = new ListItem; // создаем в памяти новый элемент списка
    temp->id = productId;   // присваиваем полям элемента нужные значения
    strcpy_s(temp->name, productName); // имя продукта - это стока C-Style, поэтому копируем ее с помощью специальной функции копирования строк
    temp->price = productPrice; // присваиваем полям элемента нужные значения
    temp->count = productCount; // присваиваем полям элемента нужные значения
    temp->next = firstItem; // нам нужно встроить элемент в начало списка, поэтому
    // указатель next настраиваем таким образом, чтобы он указывал на элемент
    // который ранее был первым (на него указывает first)
    firstItem = temp;       // а теперь делаем, чтобы first указывал на наш созданный элемент
}

ListItem* GetLast(ListItem* firstItem)
{
	if (firstItem == nullptr) return nullptr; // если список пуст, то вернем пустой указатель
	auto temp = firstItem; // временной переменной присваиваем указатель на первый элемент
    while (temp->next != nullptr)
    {
        temp = temp->next;  // перемещаемся к следующему элементу списка
    }
	return temp; // возвращаем указатель на последний элемент
}// Функция получения указателя на последний элемент

ListItem* AddLast(ListItem*& firstItem, int productId, const char* productName, float productPrice, float productCount)
{
    if (firstItem == nullptr) // если список пуст, вызовем функцию добавления в начало списка
    {
        AddFirst(firstItem, productId, productName, productPrice, productCount);
        return firstItem;
    }
    ListItem* temp = new ListItem; // создаем в памяти новый элемент списка
    temp->id = productId;   // присваиваем полям элемента нужные значения
    strcpy_s(temp->name, productName); // имя продукта - это стока C-Style, поэтому копируем ее с помощью специальной функции копирования строк
    temp->price = productPrice; // присваиваем полям элемента нужные значения
    temp->count = productCount; // присваиваем полям элемента нужные значения
    temp->next = nullptr; // нам нужно встроить элемент в конец списка, поэтому
    // указатель next настраиваем таким образом, чтобы он был пустым
    // который ранее был первым (на него указывает first)
    GetLast(firstItem)->next = temp;    // а теперь делаем, чтобы элемент, который до этого был последним
    // (а его мы получаем с помощью уже созданной GetLast)
    // ссылался на наш новый элемент
    return temp; // возвращаем указатель на последний элемент
}

ListItem* SearchByPriceRange(ListItem* firstItem, float bottom, float top)
{
    if (firstItem == nullptr) return nullptr;   //если список пуст, то возвращаем нулевой указатель
    ListItem* newList = new ListItem;   
    newList = nullptr;
    while (firstItem != nullptr)    //пока список не кончится проверяем товары и добавляем их в новый список
    {
        if (firstItem->price <= top && firstItem->price >= bottom)
            AddLast(newList, firstItem->id, firstItem->name, firstItem->price, firstItem->count);
        firstItem = firstItem->next;	// двигаемся дальше по списку
    }
    return newList;
}

/*
Создайте функцию, которая ищет в связном списке товаров товары с ценой, которая лежит в указанном диапазоне.
Функция возвращает в качечтве результата новый список, в который включены только те товары, цена которых
лежит в указанном диапазоне цен.

Структура элемента списка:

struct ListItem
{
    int id;
    char name[30];
    float price;
    float count;
    ListItem* next;
};

1. Функция должна иметь имя SearchByPriceRange
2. Функция в качестве параметров должна принимать следующее:
- первый параметр - указатель на первый элемент списка
- второй параметр - нижняя граница поиска цены (float)
- третий параметр - верхняя граница поиска цены (float)

3. Функция должна возвращать указатель на вновь созданный список товаров, удовлетворяющих условию. Если таких товаров нет,
   то функция должна вернуть nullptr.

Тип возвращаемого результата - ListItem*.

    !!!!! ВАЖНО !!!!!
    В данном файле разрешается разместить кроме кода требуемой функции - код любых других вспомогательных
    функций. Никакой функции main() в этом файле быть не должно.
    Если вы хотите испытать и отладить вашу функцию - пишите код в файле Example.cpp проекта Example данного решения
    Для этого задайте в качестве запускаемого проекта проект Example.

    ДЛЯ АВТОМАТИЧЕСКОГО ТЕСТИРОВАНИЯ  проверки правильности работы вашего задания - сделайте запукаемым проект
    Tests и запустите его. Если функция написана правильно - все тесты должны успешно выполниться
    (зеленый цвет в консоли). Если ваша функция работает некорректно - в консоли будут сообщения красным цветом
*/