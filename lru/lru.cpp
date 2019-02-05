#include <iostream>
#include <map>
#include "lru.h"

using namespace std;

Node::Node(int key, int value)
{
	this->key = key;
	this->value = value;

	prev = (Node*)0;
	next = (Node*)0;
}

LRU::LRU(int capacity)
{
	this->count = 0;
	this->capacity = capacity;
	head = (Node*)0;
	tail = (Node*)0;
}

void LRU::setNode(int key, int value)
{
	if(lru_map.find(key) != lru_map.end())
	{
		Node *node = lru_map[key];
		node->value = value;
		addtoHead(node);
	}
	else
	{
		Node *node = new Node(key, value);
		lru_map[key] = node;
		addtoHead(node);
		count++;
		if(count > capacity)
		{
			Node *temp = tail->prev;
			delete tail;
			temp->next = (Node*)0;
			tail = temp;
		}
	}
}

Node* LRU::getNode(int key)
{
	Node *node = (Node*)0;
	if(lru_map.find(key) != lru_map.end())
	{
		node = lru_map[key];
		int value = node->value;
		addtoHead(node);
		cout << "getNode value : " << value << endl;
	}

	return node;
}

void LRU::addtoHead(Node *node)
{
	if(head == (Node *)0)
	{
		head = node;
		tail = node;
		return;
	}
	node->next = head;
	head->prev = node;
	head = node;

	return;
}

void LRU::printLRU()
{
	cout << "Printing map " << endl;
	for(map<int, Node*>::iterator it = lru_map.begin(); it != lru_map.end(); it++)
	{
		Node *node = it->second;
		cout << "key is : " << node->key << " Value is : " << node->value << endl;
	}

	cout << "Printing Linked List" << endl;
	Node *temp = head;
	while(temp)
	{
		cout << temp->key << "->";
		temp = temp->next;
	}
	cout << endl;

	return;
}
