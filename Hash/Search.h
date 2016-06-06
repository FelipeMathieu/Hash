#pragma once

#include "Hash.h"
#include "Tree.h"

class Search
{
public:
	Search();
	~Search();

	void searchTree(Node *root, int size, vector<long int> v);
	void searchHash(Hash h, int size, vector<long int> v);
};

