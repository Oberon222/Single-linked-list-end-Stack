#include "SingleList.h"
#include <iostream>
using namespace std;

SingleList::SingleList(const SingleList& other) : head(nullptr) //copy c-tor
{
	Node* current = other.head;
	while(current !=nullptr)
	{
		AddToTail(current->value);
		current = current->next;

	}
}

SingleList::SingleList(SingleList&& other) //move c-tor
{
	this->size = other.size;
	this->head = other.head;
	other.head = nullptr;
	other.size = 0;
}

SingleList SingleList::operator=(const SingleList& other)
{
	
	if (this == &other) return *this;

	this->~SingleList();

	Node* current = other.head;
		while (current !=nullptr)
		{
			AddToTail(current->value);
			current = current->next;
		}
}

void SingleList::AddToHead(int value)
{
	Node* newElem = new Node;
	newElem->value = value;
	newElem->next = head;
	head = newElem;

	++size;
}

void SingleList::AddToTail(int value)
{
	Node* newElem = new Node;
	newElem->value = value;
	newElem->next = nullptr;

	if (head == nullptr)
	{
		head = newElem;
	}
	else
	{
		Node* current = head;
		while (current->next != nullptr)
		{
			// move to next
			current = current->next;
		}

		current->next = newElem;
	}
	++size;
}

void SingleList::AddPosition(int value, int pos)
{
	if (pos <= 0 || pos > size + 1) return;
	if (pos == 1)
	{
		AddToHead(value);
	}
	if (pos == size + 1)
	{
		AddToTail(value);
		return;
	}

	Node* newElem = new Node;
	newElem->value = value;

		Node* current = head;
		for (int i = 0; i < pos - 2; ++i)
		{
			current = current->next;
		}

		newElem->next = current->next;
		current->next = newElem;
		++size;
}

void SingleList::DeleteHead()
{
	if (head == nullptr) return;

	Node* temp = head->next;
	delete head;

	if (temp == nullptr)
		head = nullptr;
	else
		head = temp;

	--size;
}

void SingleList::DeleteTail()
{
	if (head == nullptr) return;

	if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		Node* current = head;
		while (current->next->next != nullptr)
		{
			// move to next
			current = current->next;
		}

		// видаляємо останній елемент
		delete current->next;
		current->next = nullptr;
	}
	--size;
}

void SingleList::DeletePosition(int pos)
{
	if (pos <= 0 || pos > size) return;

	if (pos == 1)
	{
		DeleteHead();
		return;
	}

	if (pos == size)
	{
		DeleteTail();
		return;
	}

	Node* current = head;
	for (int i = 0; i < pos - 2; ++i)
	{
		current = current->next;
	}
	current->next = current->next->next;
	delete current->next;
	--size;
}

void SingleList::Show() const
{
	Node* current = head;
	while (current !=nullptr)
	{
		cout << current->value << ", ";
		current = current->next;

	}
}

int SingleList::Find(int pos)
{
	Node* current = head;
	int counter=0;
	while (current != nullptr)
	{
		if (counter == pos - 1) {
			return current->value;
		}
		current = current->next;
		++counter;
	}

}

bool SingleList::Push(int value)
{
		AddToHead(value);
		return true;
}

int SingleList::Pop()
{
	DeleteHead();
	return 0;
}

int SingleList::Peek()
{

	return head->value;
}
