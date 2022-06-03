#include<iostream>
#include"../include/test.h"
#include"../include/list.h"
#include"../include/print.h"
using namespace std;

void test_list()
{
	List<int> list;
	cout << "Создан объект класса List" << endl << endl << endl;

	cout << "Проверка на отсутствие элементов: " << list.empty() << endl << endl << endl;

	cout << "Добавление элементов в список с помощью метода push_back" << endl;
	for (int i = 0; i < 5; i++)
	{
		list.push_back(i);
	}
	cout << "Результат работы:" << endl;
	print(list);

	cout << endl << endl << "Проверка на отсутствие элементов: " << list.empty() << endl << endl << endl;

	cout << "Добавление элемента в список с помощью метода push_front" << endl;
	list.push_front(5);
	cout << "Результат работы:" << endl;
	print(list);

	cout << endl << endl << "Добавление элемента в список помощью метода insert. В данном примере позиция 2" << endl;
	list.insert(2, 7);
	cout << "Результат работы:" << endl;
	print(list);

	cout << endl << endl << "Удаление элемента из списка с помощью метода erase. В данном примере позиция 3" << endl;
	list.erase(3);
	cout << "Результат работы:" << endl;
	print(list);

	cout << endl << endl << "Изменеие размера списка с помощью метода resize. В данном примере новый размер - 4" << endl;
	list.resize(4);
	cout << "Результат работы:" << endl;
	print(list);
	cout << "При увеличении числа символов относительно начального и заданном значении value" << endl;
	list.resize(10, 8);
	cout << "Результат работы:" << endl;
	print(list);

	cout << endl << endl << "Добавим в список несколько значений-дубликатов" << endl;
	for (int i = 0; i < 4; i++)
	{
		list.insert(2, 10); list.insert(8, 3);
	}
	list.insert(5, 17); list.insert(7, 17); list.insert(0, 17);
	print(list);
	cout << "Удалим дубликаты с помощью метода unique" << endl;
	list.unique();
	cout << "Результат работы:" << endl;
	print(list);

	cout << endl << endl << "Получение размера списка с помощью метода GetSize: " << list.GetSize() << endl << endl;

	cout << endl << "Удаление последнего элемента с помощью метода pop_back" << endl;
	list.pop_back();
	cout << "Результат работы:" << endl;
	print(list);

	cout << endl << endl << "Удаление первого элемента с помощью метода pop_front" << endl;
	list.pop_front();
	cout << "Результат работы:" << endl;
	print(list);

	cout << endl << endl << "Возвращение значений и указателей первого и последнего элемента с помощью методов" << '\n' << "front, back, begin, end" << endl;
	cout << "Значение первого элемента:" << '\t' << list.front() << '\t';
	cout << "Указатель на первый элемент:" << '\t' << list.begin() << endl;
	cout << "Значение последнего элемента:" << '\t' << list.back() << '\t';
	cout << "Указатель на последний элемент:" << '\t' << list.end() << endl;

	cout << endl << endl << "Создание второго объекта класса List: 0 1 2 3 4" << endl;
	List<int> list2;
	for (int i = 0; i < 5; i++)
	{
		list2.push_back(i);
	}
	cout << "Cмена текущего списка местами с вторым списком методом swap" << endl;
	list.swap(list2);
	cout << "Результат работы:" << endl;
	cout << "Первый список:" << '\t'; print(list);
	cout << "Второй список:" << '\t'; print(list2);

	cout << endl << endl << "Очистка списка с помощью метода clean" << endl;
	list.clean();
	cout << "Размер списка после выполнения метода: " << list.GetSize() << endl;
	cout << "Указатель на первый элемент списка после выполнения метода: " << list.begin() << endl;
	cout << "Проверка на отсутствие элементов: " << list.empty() << endl << endl;
}