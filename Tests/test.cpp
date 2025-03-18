#include "pch.h"
#include "Task.h"
#include <iostream>
using namespace std;

void DeleteList(ListItem*& firstItem)
{
	auto temp = firstItem;
						   
	while (firstItem != nullptr)
	{
		firstItem = firstItem->next;
		delete temp;
		temp = firstItem;
	}
}

bool InRange(ListItem* firstItem, float l, float u)
{
	auto temp = firstItem;					   
	while (temp != nullptr)
	{
		if (temp->price < l || temp->price > u)
			return false;
		temp = temp->next;
	}
	return true;
}

int A(ListItem* z)
{
	int x = 0; auto t = z; while (t != nullptr) { x++; t = t->next; }return x;
}

void AddFirst1(ListItem*& firstItem, int productId, const char* productName, float productPrice, float productCount)
{
	ListItem* temp = new ListItem; // ������� � ������ ����� ������� ������
	temp->id = productId;   // ����������� ����� �������� ������ ��������
	strcpy_s(temp->name, productName); // ��� �������� - ��� ����� C-Style, ������� �������� �� � ������� ����������� ������� ����������� �����
	temp->price = productPrice; // ����������� ����� �������� ������ ��������
	temp->count = productCount; // ����������� ����� �������� ������ ��������
	temp->next = firstItem; // ��� ����� �������� ������� � ������ ������, �������
						// ��������� next ����������� ����� �������, ����� �� �������� �� �������
						// ������� ����� ��� ������ (�� ���� ��������� first)
	firstItem = temp;       // � ������ ������, ����� first �������� �� ��� ��������� �������
}

TEST(TestTask, EmptyList) {
	ListItem* first = nullptr;
	ListItem* list;
	EXPECT_NO_THROW(list = SearchByPriceRange(first, 0, 100));
	EXPECT_EQ(list, nullptr);
}

TEST(TestTask, ListWithOneElementTrue) {

	ListItem* first = nullptr;
	ListItem* list = nullptr;
	AddFirst1(first, 1, "", 10, 1);
	EXPECT_NO_THROW(list = SearchByPriceRange(first, 0, 100));
	EXPECT_FALSE(list == nullptr);
	EXPECT_EQ(A(list), 1);
	EXPECT_TRUE(InRange(list, 0, 100));
	DeleteList(first);
	DeleteList(list);
}

TEST(TestTask, ListWithOneElementFalse) {

	ListItem* first = nullptr;
	ListItem* list;
	AddFirst1(first, 1, "", 100, 1);
	EXPECT_NO_THROW(list = SearchByPriceRange(first, 0, 10));
	EXPECT_TRUE(list == nullptr);
	DeleteList(first);
}

TEST(TestTask, ListWithElementsTrue) {

	ListItem* first = nullptr;
	ListItem* list = nullptr;
	AddFirst1(first, 1, "", 10, 1);
	AddFirst1(first, 1, "", 20, 1);
	AddFirst1(first, 1, "", 30, 1);
	AddFirst1(first, 1, "", 40, 1);
	AddFirst1(first, 1, "", 50, 1);
	AddFirst1(first, 1, "", 60, 1);
	AddFirst1(first, 1, "", 70, 1);

	EXPECT_NO_THROW(list = SearchByPriceRange(first, 20, 30));
	EXPECT_FALSE(list == nullptr);
	EXPECT_EQ(A(list), 2);
	EXPECT_TRUE(InRange(list, 20, 30));
	DeleteList(first);
	DeleteList(list);
}

TEST(TestTask, ListWithElementsFalse) {

	ListItem* first = nullptr;
	ListItem* list;
	AddFirst1(first, 1, "", 10, 1);
	AddFirst1(first, 1, "", 20, 1);
	AddFirst1(first, 1, "", 30, 1);
	AddFirst1(first, 1, "", 40, 1);
	AddFirst1(first, 1, "", 50, 1);
	AddFirst1(first, 1, "", 60, 1);
	AddFirst1(first, 1, "", 70, 1);

	EXPECT_NO_THROW(list = SearchByPriceRange(first, 200, 300));
	EXPECT_TRUE(list == nullptr);
	DeleteList(first);
}
