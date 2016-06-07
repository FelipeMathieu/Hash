#pragma once

#include<iostream>
#include<time.h>
#include<vector>
#include<list>
#include<fstream>

using namespace std;

typedef struct no
{
	long int e;
	no *prox;
}No;

class Hash
{
private:
	vector<No*> elementos;
	int tamanho;
	//void quickSort(vector<long int> *v, int left, int right);

public:
	Hash(int tamanho);
	~Hash();
	
	int cHash(int e)
	{
		return (e % this->tamanho);
	}
	void insert(long int e);
//	void printHash();
//	void quickSort(list<long int> *v, int left, int right, int aux);
	No *Get_IndexHash(int i) 
	{ 
		return this->elementos[i]; 
	}
	int size(No *n)
	{
		int count = 1;

		for (n; n->prox != NULL; n = n->prox)
		{
			count += 1;
		}
		return count;
	}
};

