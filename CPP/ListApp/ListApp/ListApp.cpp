// ListApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <typeinfo.h>
#include "List.h"
#include "SortedList.h"
#include "SortedDLList.h"
#include "DLList.h"

using namespace std;

void TestList(vector<int> v);
void TestSortedList(vector<int> v);
void Test2WayList(vector<int> v);
void TestDeleteNode(vector<int> v, int data);
void runVectorFunc(vector<int> v, std::function<void(int)> func);

auto printFunc = [](int y)
{
	cout << y << "  ";
};


int main()
{
	std::vector<int> v1 = { 80, 50, 30, 60, 40, 90, 70 };
	TestList(v1);
	std::vector<int> v2 = { 90, 50 };
	TestList(v2);
	std::vector<int> v3 = { 40, 70 };
	TestList(v3);
	std::vector<int> v4 = { 60 };
	TestList(v4);
	std::vector<int> v5 = {  };
	TestList(v5);

	TestSortedList(v1);

	Test2WayList(v1);

	TestDeleteNode(v1, 30);
	TestDeleteNode(v1, 40);
	TestDeleteNode(v1, 60);
	TestDeleteNode(v1, 80);
	TestDeleteNode(v1, 90);
	TestDeleteNode(v1, -99);

	return 0;
}


void TestList(vector<int> v)
{
	
	List* list = new List();
	for (auto& i : v)
	{
		list->addNode(i);
	}
	cout << endl;
	cout << "List: " << typeid(*list).name() << endl;
	vector<int> v1 = list->traverse();
	for (auto i = v1.begin(); i != v1.end(); ++i)
	{
		std::cout << *i << "  ";
	}
	cout << endl;
	cout << "sort " << endl;
	list->sort();
	vector<int> v2 = list->traverse();
	runVectorFunc(v2, printFunc);
    cout << endl;
	cout << "reverse " << endl;
	list->reverse();
	list->traverse();
	vector<int> v3 = list->traverse();
	//for (auto i = v3.begin(); i != v3.end(); ++i)
	std::for_each(v3.begin(), v3.end(), [=] (int i)
	{
		printFunc(i);
	});
	cout << endl;
}

void TestSortedList(vector<int> v)
{

	List* list = new SortedDLList();
	for (auto& i : v)
	{
		list->addNode(i);
	}
	cout << endl;
	cout << "Sorted List: " << typeid(*list).name() << endl;
	vector<int> v1 = list->traverse();
	for (auto i = v1.begin(); i != v1.end(); ++i)
	{
		std::cout << *i << "  ";
	}
	cout << endl;
	cout << "sort " << endl;
	list->sort();
	vector<int> v2 = list->traverse();
	runVectorFunc(v2, printFunc);
	cout << endl;
	cout << "reverse " << endl;
	list->reverse();
	list->traverse();
	vector<int> v3 = list->traverse();
	//for (auto i = v3.begin(); i != v3.end(); ++i)
	std::for_each(v3.begin(), v3.end(), [=](int i)
	{
		printFunc(i);
	});
	cout << endl;
}

void Test2WayList(vector<int> v)
{

	List* list = new DLList();
	for (auto& i : v)
	{
		list->addNode(i);
	}
	cout << endl;
	cout << "2 Way List: " << typeid(*list).name() << endl;
	vector<int> v1 = list->traverse();
	for (auto i = v1.begin(); i != v1.end(); ++i)
	{
		std::cout << *i << "  ";
	}
	cout << endl;
	cout << "sort " << endl;
	list->sort();
	vector<int> v2 = list->traverse();
	runVectorFunc(v2, printFunc);
	cout << endl;
	cout << "reverse " << endl;
	list->reverse();
	list->traverse();
	vector<int> v3 = list->traverse();
	//for (auto i = v3.begin(); i != v3.end(); ++i)
	std::for_each(v3.begin(), v3.end(), [=](int i)
	{
		printFunc(i);
	});
	cout << endl;
}

void TestDeleteNode(vector<int> v, int data)
{

	List* list = new SortedDLList();
	for (auto& i : v)
	{
		list->addNode(i);
	}
	cout << endl;
	cout << "List: Delete Node from " << typeid(*list).name() << endl;
	vector<int> v1 = list->traverse();
	runVectorFunc(v1, printFunc);
	cout << endl;
	cout << "Delete node:" << data << endl;
	list->deleteNode(data);
	list->traverse();
	vector<int> v2 = list->traverse();
	runVectorFunc(v2, printFunc);
	cout << endl;
}


void runVectorFunc(vector<int> v, std::function<void(int)> func)
{
	for_each(v.begin(), v.end(), func);
}
