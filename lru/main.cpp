#include <iostream>
#include "lru.h"

using namespace std;

int main()
{
	LRU *lru = new LRU(10);

	for(int i = 1; i <= 10; i++)
		lru->setNode(i, i);

	lru->printLRU();

	for(int i = 5; i <= 15; i++)
		lru->setNode(i, i);

	lru->printLRU();

	return 0;
}
