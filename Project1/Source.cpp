//1 ����� ������������ ���
#include <iostream>
using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();

	//�������� ������� �������� � ������
	void pop_front();

	//���������� �������� � ����� ������
	void push_back(T data);

	// �������� ������
	void clear();

	// �������� ���������� ��������� � ������
	int GetSize() { return Size; }

	// ������������� �������� [] 
	T& operator[](const int index);

	//���������� �������� � ������ ������
	void push_front(T data);

	//���������� �������� � ������ �� ���������� ������� ����� ������
	void insert_back(T data, int index);

	//���������� �������� � ������ �� ���������� ������� ����� �������
	void insert_front(T data, int index);

	//�������� �������� � ������ �� ���������� �������
	void removeAt(int index);

	//�������� ���������� �������� � ������
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
			this->data = data;//���� ����������
			this->pNext = pNext;//��������� �� ��������� �������
		}
	};
	int Size;//������ ������
	Node<T>* head;// ������ ������� ������
};


template<typename T>//�����������
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()//����������
{
	clear();
}


template<typename T>
void List<T>::pop_front()//�������� ������� �������� � ������
{
	Node<T>* temp = head;//������ ��������� ���������� ������ "������" ������

	head = head->pNext;//����������� "������" �������� ������� ��������

	delete temp;//������� ������ "������"

	Size--;//�� ������� �������, ������ ��������� ������

}

template<typename T>
void List<T>::push_back(T data)//���������� �������� � ����� ������
{
	if (head == nullptr)//���� ������ ������
	{
		head = new Node<T>(data);//������ ����� �������
	}
	else
	{
		Node<T>* current = this->head;//������ ����� ����������

		while (current->pNext != nullptr)//���� ��������� �������
		{
			current = current->pNext;//
		}
		current->pNext = new Node<T>(data);//������ ��������� ������� � �����

	}

	Size++;//����������� ������
}

template<typename T>
void List<T>::clear()//������� ������
{
	while (Size)
	{
		pop_front();
	}
}


template<typename T>
T& List<T>::operator[](const int index)//���������� ��������� ��� ��������� � ��������� ������ ����� []
{
	int counter = 0;//�������

	Node<T>* current = this->head;//���������� ��� �������� ������

	while (current != nullptr)//���� �� �����
	{
		if (counter == index)//����� ������ ��������
		{
			return current->data;//"��������" ������ �� ���� data
		}
		current = current->pNext;//���������� ����� ���������� ��������
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)//���������� � ������ ������
{
	head = new Node<T>(data, head);//
	Size++;
}
//���������� �������� � ������ �� ���������� ������� ����� ������
template<typename T>
void List<T>::insert_back(T data, int index)//������� � ������� ������ � ������ ��������
{

	if (index == 0)//���� ��������� ����� ������� ��������
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;//������ ����� ����������

		for (int i = 0; i < index - 1; i++)//����� ������� ��������
		{
			previous = previous->pNext;//�������� ���������� ��������� �� ��������� �������
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);//�� ���� pNext ��������� ����� ���� ����������� �������� 

		previous->pNext = newNode;//����������� ����� ������ �������� �����������

		Size++;
	}

}
//���������� �������� � ������ �� ���������� ������� ����� �������
template<typename T>
void List<T>::insert_front(T data, int index)//������� � ������� ������ � ������ ��������
{

	if (index == 1)//���� ���� �������, �� ������� ��� ��� ������ ������
	{
		push_front(data);//������� �������� ������ ������
	}
	else
	{
		Node<T>* next = this->head;//���������� ��� ������ ������� �������

		for (int i = 0; i < index - 2; i++)//���������� �� ������� ��� �������� (-2 ������ ��� �� �������� ����� ����������)
		{
			next = next->pNext;//���� ��������� �������
		}

		Node<T>* newNode = new Node<T>(data, next->pNext);//������ ����� ������� ��������� ��� ����� ���������� � �������� ������ ��������

		next->pNext = newNode;//����������� ��������� �� ��������� �������

		Size++;//�������� ������� � ����������� ������ ������
	}
}
//�������� �������� � ������ �� ���������� �����
template<typename T>
void List<T>::removeAt(int data)//������� � ������� ����(��������) ���������� ��������
{
	{
		Node<T>* counter = head;//�������
		Node<T>* previous = nullptr;//���������� 
		while ((counter->data != a) && (counter->pNext != nullptr))///���� �� ������ �������
		{
			previous = counter;//� ����� ������ ���� �� ����� �� ������ ��� �� ����� ������ �������
			counter = counter->pNext;
		}
		if (counter->data == a)//���� ����� �������
		{
			if (counter != head)//���� �� ������ ������
			{
				previous->pNext = counter->pNext;//��������� ����������� ���������� �� ��������� ��������
				counter->pNext = nullptr;//��������� �� ���������
				delete counter;//������� �������
				Size--;//������� ������� �������� �������
			}
			if (counter == head)//���� ������
			{
				pop_front();//�������� ������
			}
		}
	}
}
//�������� ���������� �������� � ������
template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);//������ ����� � ������� ������� �������� ���������� ��������
}

int main()
{

	setlocale(LC_ALL, "ru");
	List<int> lst;
	int temp;
	int n;
	int t;
	cout << "������� ���������� ����� (�� ������ 10 �����)" << endl;
	cin >> n;
	cout << "������� �����" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		lst.push_back(temp);
	}

	cout << "�������� �����" << endl;
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;

	}

	cout << "-------------" << endl << "������� ����� ���������� ������" << endl;
	cout << "������� ����� ��� �������";
	cin >> temp;
	cout << "������� ����� �������� �� ������� ��������� �����";
	cin >> t;
	lst.insert_back(temp, t);//t-������

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "-------------" << endl << "������� ����� ��������� �������" << endl;
	cout << "������� ����� ��� �������";
	cin >> temp;
	cout << "������� ����� �������� ����� ������� ��������� �����";
	cin >> t;
	lst.insert_front(temp, t);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "-------------" << endl << "������� �� �����" << endl << "������� �����";
	cin >> temp;
	lst.push_front(temp);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "-------------" << endl << "������� � �����" << endl << "������� �����";
	cin >> temp;
	lst.push_back(temp);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "-------------" << endl << "�������� ���������� ��������" << endl << "������� ���� ��������";
	cin >> t;
	lst.removeAt(t);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << "-------------" << endl << "�������� �������� � ������ � � ������" << endl;
	lst.pop_front();
	lst.pop_back();
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	return 0;
}