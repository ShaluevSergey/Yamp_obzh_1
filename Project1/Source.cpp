//1 общая лабораторная ямп
#include <iostream>
using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();

	//удаление первого элемента в списке
	void pop_front();

	//добавление элемента в конец списка
	void push_back(T data);

	// очистить список
	void clear();

	// получить количество елементов в списке
	int GetSize() { return Size; }

	// перегруженный оператор [] 
	T& operator[](const int index);

	//добавление элемента в начало списка
	void push_front(T data);

	//добавление элемента в список по указанному индексу после номера
	void insert_back(T data, int index);

	//добавление элемента в список по указанному индексу перед номером
	void insert_front(T data, int index);

	//удаление элемента в списке по указанному индексу
	void removeAt(int index);

	//удаление последнего элемента в списке
	void pop_back();

private:


	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;//поле информации
			this->pNext = pNext;//указатель на следующий элемент
		}
	};
	int Size;//размер списка
	Node<T>* head;// первый элемент списка
};


template<typename T>//конструктор
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()//деструктор
{
	clear();
}


template<typename T>
void List<T>::pop_front()//удаление первого элемента в списке
{
	Node<T>* temp = head;//создаём временную переменную равную "голове" списка

	head = head->pNext;//Присваеваем "голове" значение второго элемента

	delete temp;//удаляем бывшую "голову"

	Size--;//Мы удалили элемент, значит уменьшаем список

}

template<typename T>
void List<T>::push_back(T data)//Добавление элемента в конец списка
{
	if (head == nullptr)//Если список пустой
	{
		head = new Node<T>(data);//Создаём новый элемент
	}
	else
	{
		Node<T>* current = this->head;//Создаём новую переменную

		while (current->pNext != nullptr)//Ищем последний элемент
		{
			current = current->pNext;//
		}
		current->pNext = new Node<T>(data);//Создаём последний элемент в конце

	}

	Size++;//увеличиваем размер
}

template<typename T>
void List<T>::clear()//Очистка списка
{
	while (Size)
	{
		pop_front();
	}
}


template<typename T>
T& List<T>::operator[](const int index)//перегрузка оператора для обращения к элементам списка через []
{
	int counter = 0;//счётчик

	Node<T>* current = this->head;//переменная для проверки адреса

	while (current != nullptr)//пока не конец
	{
		if (counter == index)//нашли нужный аргумент
		{
			return current->data;//"забираем" данные из поля data
		}
		current = current->pNext;//спрашиваем адрес следующего элемента
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)//добавление в начало списка
{
	head = new Node<T>(data, head);//
	Size++;
}
//добавление элемента в список по указанному индексу после номера
template<typename T>
void List<T>::insert_back(T data, int index)//Передаём в функцию данные и индекс элемента
{

	if (index == 0)//если вставляем после первого элемента
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;//Создаём новую переменную

		for (int i = 0; i < index - 1; i++)//Поиск нужного элемента
		{
			previous = previous->pNext;//Присваем переменной указатель на следующий элемент
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);//ПВ поле pNext передаётся адрес поля предыдущего элемента 

		previous->pNext = newNode;//Присваиваем адрес нового элемента предыдущему

		Size++;
	}

}
//добавление элемента в список по указанному индексу перед номером
template<typename T>
void List<T>::insert_front(T data, int index)//Передаём в функцию данные и индекс элемента
{

	if (index == 1)//если один элемент, то удаляем его как голову списка
	{
		push_front(data);//функция удаления головы списка
	}
	else
	{
		Node<T>* next = this->head;//Переменная для поиска нужного индекса

		for (int i = 0; i < index - 2; i++)//перебираем до нужного нам элемента (-2 потому что мы всталяем перед указаннным)
		{
			next = next->pNext;//Берём следующий элемент
		}

		Node<T>* newNode = new Node<T>(data, next->pNext);//Создаём новый элемент передавая ему адрес следующего и значение самого элемента

		next->pNext = newNode;//Присваиваем указатель на следующий элемент

		Size++;//Добавили элемент и увеличиваем размер списка
	}
}
//удаление элемента в списке по указанному ключу
template<typename T>
void List<T>::removeAt(int data)//передаём в функцию ключ(значение) удаляемого элемента
{
	{
		Node<T>* counter = head;//текущий
		Node<T>* previous = nullptr;//предыдущий 
		while ((counter->data != a) && (counter->pNext != nullptr))///пока не найдем элемент
		{
			previous = counter;//в конец списка пока не дошли до хвоста или не нашли нужный элемент
			counter = counter->pNext;
		}
		if (counter->data == a)//если нашли элемент
		{
			if (counter != head)//если не голова списка
			{
				previous->pNext = counter->pNext;//указатель предыдущего перемещаем на указатель текущего
				counter->pNext = nullptr;//следующий за удаляемым
				delete counter;//удаляем элемент
				Size--;//удалили элемент уменьшим счётчик
			}
			if (counter == head)//если голова
			{
				pop_front();//удаление головы
			}
		}
	}
}
//удаление последнего элемента в списке
template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);//Удалям хвост с помощью функции удаления выбранного элемента
}

int main()
{

	setlocale(LC_ALL, "ru");
	List<int> lst;
	int temp;
	int n;
	int t;
	cout << "Введите количество чисел (не больше 10 чисел)" << endl;
	cin >> n;
	cout << "Введите числа" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		lst.push_back(temp);
	}

	cout << "Введённые числа" << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;

	}

	cout << "-------------" << endl << "Вставка после указанного номера" << endl;
	cout << "Введите число для вставки";
	cin >> temp;
	cout << "введите номер элемента за которым вставлять число";
	cin >> t;
	lst.insert_back(temp, t);//t-индекс

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "-------------" << endl << "Вставка перед указанным номером" << endl;
	cout << "Введите число для вставки";
	cin >> temp;
	cout << "введите номер элемента перед которым вставлять число";
	cin >> t;
	lst.insert_front(temp, t);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "-------------" << endl << "Вставка во главу" << endl << "Введите число";
	cin >> temp;
	lst.push_front(temp);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "-------------" << endl << "Вставка в хвост" << endl << "Введите число";
	cin >> temp;
	lst.push_back(temp);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "-------------" << endl << "Удаление указанного элемента" << endl << "Введите ключ элемента";
	cin >> t;
	lst.removeAt(t);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "-------------" << endl << "Удаление элемента с головы и с хвоста" << endl;
	lst.pop_front();
	lst.pop_back();
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	return 0;
}