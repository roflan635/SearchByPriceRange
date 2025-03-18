#pragma once

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows

struct ListItem
{
    int id;
    char name[30];
    float price;
    float count;
    ListItem* next;
};

ListItem* SearchByPriceRange(ListItem*, float, float);