#ifndef _LIST_H_
#define _LIST_H_
using namespace std;

template<typename Type>
class Element //Класс - элемент списка
{
public:
	Element(Type data = Type(), Element* pNextElement = nullptr)
	{
		this->data = data;
		this->pNextElement = pNextElement;
	}
	Type data; Element* pNextElement;
};

template<typename Type>
class List
{
private:

	Element<Type>* pFirstElement;
	int size;

public:

	int GetSize(){return size;}
	List() //Конструктор
	{
		pFirstElement = nullptr;
		size = 0;
	}
	List(List<Type>& other) //Конструктор копирования
	{
		this->size = other.size;
		this->pFirstElement = new Element<Type>;
		Element<Type>* pTempElement = this->pFirstElement;
		Element<Type>* pTempElement2 = other.pFirstElement;
		while (pTempElement2->pNextElement != nullptr)
		{
			pTempElement->data = pTempElement2->data;
			pTempElement->pNextElement = new Element<Type>;
			pTempElement = pTempElement->pNextElement;
			pTempElement2 = pTempElement2->pNextElement;
		}
		pTempElement->data = pTempElement2->data;
	}
	~List() //Деструктор
	{
		clean();
	}


	Type& operator[](const int index);
	List<Type>& operator=(List<Type>&);
	bool empty();
	void push_back(Type value);
	void push_front(Type value);
	void insert(int pos, Type value);
	void erase(int pos);
	void pop_back();
	void pop_front();
	void resize(int new_size);
	void resize(int new_size, Type value);
	void clean();
	void unique();
	Type& front();
	Type& back();
	Element<Type>* begin();
	Element<Type>* end();
	void swap(List& other_List);
};

//////////////////////////////////////////////////////////////////////////////////
//Перегрузка оператора []
template<typename Type>
Type& List<Type>::operator[](const int index)
{
	Element<Type>* NowElement = pFirstElement;
	for (int i = 0; i < index; i++)
	{
		NowElement = NowElement->pNextElement;
	}
	return NowElement->data;
}


//Перегрузка оператора =
template<typename Type>
inline List<Type>& List<Type>::operator=(List<Type>& other_List)
{
	this->clean();
	this->size = other_List.size;
	this->pFirstElement = new Element<Type>;
	Element<Type>* pTempElement = this->pFirstElement;
	Element<Type>* pTempElement2 = other_List.pFirstElement;
	while (pTempElement2->pNextElement != nullptr)
	{
		pTempElement->data = pTempElement2->data;
		pTempElement->pNextElement = new Element<Type>;
		pTempElement = pTempElement->pNextElement;
		pTempElement2 = pTempElement2->pNextElement;
	}
	pTempElement->data = pTempElement2->data;
	return *this;
}


//Проверка списка на наличие элементов
template<typename Type>
inline bool List<Type>::empty()
{
	return(pFirstElement == nullptr);
};


//Добавление элемента в конец списка
template<typename Type>
inline void List<Type>::push_back(Type value)
{
	if (pFirstElement == nullptr)
	{
		pFirstElement = new Element<Type>(value);
	}
	else
	{
		Element<Type>* NowElement = pFirstElement;
		while (NowElement->pNextElement != nullptr)
		{
			NowElement = NowElement->pNextElement;
		}
		NowElement->pNextElement = new Element<Type>(value);
	}
	size++;
}


//Добавление элемента в начало списка
template<typename Type>
inline void List<Type>::push_front(Type value)
{
	if (pFirstElement == nullptr)
	{
		pFirstElement = new Element<Type>(value);
	}
	else
	{
		Element<Type>* pSecondElement = pFirstElement;
		pFirstElement = new Element<Type>(value);
		pFirstElement->pNextElement = pSecondElement;
		pSecondElement = nullptr;
	}
	size++;
}


//Добавление элемента на указанную позицию
template<typename Type>
inline void List<Type>::insert(int pos, Type value)
{
	try
	{
		if (pos == 0)
		{
			push_front(value);
		}
		else if (pos == List::GetSize())
		{
			push_back(value);
		}
		else
		{
			Element<Type>* NowElement = pFirstElement;
			for (int i = 0; i < pos - 1; i++)
			{
				NowElement = NowElement->pNextElement;
			}
			Element<Type>* pTempElement = NowElement->pNextElement;
			Element<Type>* pInsertElement = new Element<Type>(value);
			NowElement->pNextElement = pInsertElement;
			pInsertElement->pNextElement = pTempElement;
			pTempElement = pInsertElement = nullptr;
			size++;
		}
	}
	catch (const std::exception & ex)
	{
		cout << "Ошибка выполнения метода insert" << endl;
		cout << ex.what() << endl;
	}
};


//Удаление элемента с указанной позиции
template<typename Type>
inline void List<Type>::erase(int pos)
{
	try
	{
		if (pos == 0)
		{
			pop_front();
		}
		else if (pos == List::GetSize() - 1)
		{
			pop_back();
		}
		else
		{
			Element<Type>* NowElement = pFirstElement;
			for (int i = 0; i < pos - 1; i++)
			{
				NowElement = NowElement->pNextElement;
			}
			Element<Type>* pTempElement = NowElement->pNextElement->pNextElement;
			delete NowElement->pNextElement;
			NowElement->pNextElement = pTempElement;
			NowElement = nullptr;
			pTempElement = nullptr;
			size--;
		}
	}
	catch(const std::exception & ex)
	{
		cout << "Ошибка выполнения метода erase" << endl;
		cout << ex.what() << endl;
	}
};


//Удаление элемента из конца списка
template<typename Type>
inline void List<Type>::pop_back()
{	
	if (List::GetSize() == 1)
	{
		delete pFirstElement;
		pFirstElement = nullptr;
		size--;
	}
	else
	{
		Element<Type>* NowElement = pFirstElement;
		for (int i = 0; i < List::GetSize() - 2; i++)
		{
			NowElement = NowElement->pNextElement;
		}
		delete NowElement->pNextElement;
		NowElement->pNextElement = nullptr;
		NowElement = nullptr;
		size--;
	}
}


//Удаление элемента из начала списка
template<typename Type>
inline void List<Type>::pop_front()
{
	Element<Type>* pTempElement = pFirstElement;
	pFirstElement = pFirstElement->pNextElement;
	delete pTempElement;
	pTempElement = nullptr;
	size--;
}


//Изменение размера списка
template<typename Type>
inline void List<Type>::resize(int new_size)
{
	if (new_size < List::GetSize())
	{
		while (List::GetSize() != new_size)
		{
			pop_back();
		}
	}
	else
	{
		while (List::GetSize() != new_size)
		{
			push_back(Type());
		}
	}
}


//Изменение размера списка с присваиваемым новым элементам заданного значения
template<typename Type>
inline void List<Type>::resize(int new_size, Type value)
{
	if (new_size < List::GetSize())
	{
		while (List::GetSize() != new_size)
		{
			pop_back();
		}
	}
	else
	{
		while (List::GetSize() != new_size)
		{
			push_back(value);
			
		}
	}
}


//Очистка списка
template<typename Type>
inline void List<Type>::clean()
{
	while (size != 0)
	{
		pop_back();
	}
}


//Удаление повторяющихся данных списка
template<typename Type>
inline void List<Type>::unique()
{	
	Element<Type>* pTempElement = pFirstElement;
	Element<Type>* pTempElement2 = nullptr;
	int k = 0, n = 0;
	while (pTempElement != nullptr)
	{
		pTempElement2 = pTempElement->pNextElement;
		while (pTempElement2 != nullptr)
		{
			k += 1;
			if (pTempElement->data == pTempElement2->data)
			{
				pTempElement2 = pTempElement2->pNextElement;
				erase(k+n);
				k--;
			}
			else
			{
				pTempElement2 = pTempElement2->pNextElement;
			}
		}
		pTempElement = pTempElement->pNextElement;
		k = 0;
		n++;
	}
}


//Возвращение первого элемента
template<typename Type>
inline Type& List<Type>::front()
{
	try 
	{
		return pFirstElement->data;
	}
	catch (const std::exception& ex)
	{
		cout << "Ошибка выполнения метода front" << endl;
		cout << ex.what() << endl;
	}
}


//Возвращение последнего элемента
template<typename Type>
inline Type& List<Type>::back()
{
	try
	{
		Element<Type>* pTempElement = pFirstElement;
		while (pTempElement->pNextElement != nullptr)
		{
			pTempElement = pTempElement->pNextElement;
		}
		return pTempElement->data;
	}
	catch (const std::exception& ex)
	{
		cout << "Ошибка выполнения метода back" << endl;
		cout << ex.what() << endl;
	}
}


//Возвращение ссылки на первый элемент
template<typename Type>
inline Element<Type>* List<Type>::begin()
{
	return pFirstElement;
}


//Возвращение ссылки на последной элемент
template<typename Type>
inline Element<Type>* List<Type>::end()
{
	Element<Type>* pTempElement = pFirstElement;
	while (pTempElement->pNextElement != nullptr)
	{
		pTempElement = pTempElement->pNextElement;
	}
	return pTempElement;
}


//Смена списков местами
template<typename Type>
inline void List<Type>::swap(List& other_List)
{
	List<Type> c(other_List);
	other_List = *this;
	*this = c;
}

#endif