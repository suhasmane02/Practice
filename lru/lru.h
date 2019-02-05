#ifndef __LRU_H__
#define __LRU_H__

#include <map>

using namespace std;

class Node
{
	public:
		Node(int key, int value);

		int key;
		int value;
		Node *next;
		Node *prev;
};

class LRU
{
	public:
		LRU(int capacity);
		void deleteNode(Node *node);
		void addtoHead(Node *node);
		Node *getNode(int);
		void setNode(int key, int value);
		void printLRU();

	private:
		map<int, Node*> lru_map;
		Node *head, *tail;
		int capacity;
		int count;
};

#endif
