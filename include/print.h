#ifndef _PRINT_H_
#define _PRINT_H_

template<typename Type>
void print(List<Type>& list)
{
	for (int i = 0; i < list.GetSize(); i++)
	{
		cout << list[i] << '\t';
	}
	cout << endl;
};
#endif