#pragma once
#include <iostream>
using namespace std;


	struct Node
	{
		int value;
		Node* next;
	};
class SingleList
{
	Node* head;
	int size;

	void DeleteAll()
	{
		if (head != nullptr)
		{
			while (!IsEmpty())
			{
				DeleteHead();
			}
		}
	}
	SingleList()
	{
		head = nullptr;
		size = 0;
	};
	
	SingleList(const SingleList& other); // copy c-tor

	SingleList(SingleList&& other); // move c-tor
	
	~SingleList()
	{
		DeleteAll();
	}

	SingleList operator=(const SingleList& other);

	bool IsEmpty() const
	{
		return head == nullptr;
	}

	void AddToHead(int value);
	
	void AddToTail(int value);

	void AddPosition(int value, int pos);

	void DeleteHead();

	void DeleteTail();

	void DeletePosition(int pos);

	void Show()const;

	int Find(int pos);

public:
	
	bool Push(int value);
	int Pop();
	int Peek();



};


