#include<iostream>
#include"../include/test.h"
#include"../include/list.h"
#include"../include/print.h"
using namespace std;

void test_list()
{
	List<int> list;
	cout << "������ ������ ������ List" << endl << endl << endl;

	cout << "�������� �� ���������� ���������: " << list.empty() << endl << endl << endl;

	cout << "���������� ��������� � ������ � ������� ������ push_back" << endl;
	for (int i = 0; i < 5; i++)
	{
		list.push_back(i);
	}
	cout << "��������� ������:" << endl;
	print(list);

	cout << endl << endl << "�������� �� ���������� ���������: " << list.empty() << endl << endl << endl;

	cout << "���������� �������� � ������ � ������� ������ push_front" << endl;
	list.push_front(5);
	cout << "��������� ������:" << endl;
	print(list);

	cout << endl << endl << "���������� �������� � ������ ������� ������ insert. � ������ ������� ������� 2" << endl;
	list.insert(2, 7);
	cout << "��������� ������:" << endl;
	print(list);

	cout << endl << endl << "�������� �������� �� ������ � ������� ������ erase. � ������ ������� ������� 3" << endl;
	list.erase(3);
	cout << "��������� ������:" << endl;
	print(list);

	cout << endl << endl << "�������� ������� ������ � ������� ������ resize. � ������ ������� ����� ������ - 4" << endl;
	list.resize(4);
	cout << "��������� ������:" << endl;
	print(list);
	cout << "��� ���������� ����� �������� ������������ ���������� � �������� �������� value" << endl;
	list.resize(10, 8);
	cout << "��������� ������:" << endl;
	print(list);

	cout << endl << endl << "������� � ������ ��������� ��������-����������" << endl;
	for (int i = 0; i < 4; i++)
	{
		list.insert(2, 10); list.insert(8, 3);
	}
	list.insert(5, 17); list.insert(7, 17); list.insert(0, 17);
	print(list);
	cout << "������ ��������� � ������� ������ unique" << endl;
	list.unique();
	cout << "��������� ������:" << endl;
	print(list);

	cout << endl << endl << "��������� ������� ������ � ������� ������ GetSize: " << list.GetSize() << endl << endl;

	cout << endl << "�������� ���������� �������� � ������� ������ pop_back" << endl;
	list.pop_back();
	cout << "��������� ������:" << endl;
	print(list);

	cout << endl << endl << "�������� ������� �������� � ������� ������ pop_front" << endl;
	list.pop_front();
	cout << "��������� ������:" << endl;
	print(list);

	cout << endl << endl << "����������� �������� � ���������� ������� � ���������� �������� � ������� �������" << '\n' << "front, back, begin, end" << endl;
	cout << "�������� ������� ��������:" << '\t' << list.front() << '\t';
	cout << "��������� �� ������ �������:" << '\t' << list.begin() << endl;
	cout << "�������� ���������� ��������:" << '\t' << list.back() << '\t';
	cout << "��������� �� ��������� �������:" << '\t' << list.end() << endl;

	cout << endl << endl << "�������� ������� ������� ������ List: 0 1 2 3 4" << endl;
	List<int> list2;
	for (int i = 0; i < 5; i++)
	{
		list2.push_back(i);
	}
	cout << "C���� �������� ������ ������� � ������ ������� ������� swap" << endl;
	list.swap(list2);
	cout << "��������� ������:" << endl;
	cout << "������ ������:" << '\t'; print(list);
	cout << "������ ������:" << '\t'; print(list2);

	cout << endl << endl << "������� ������ � ������� ������ clean" << endl;
	list.clean();
	cout << "������ ������ ����� ���������� ������: " << list.GetSize() << endl;
	cout << "��������� �� ������ ������� ������ ����� ���������� ������: " << list.begin() << endl;
	cout << "�������� �� ���������� ���������: " << list.empty() << endl << endl;
}