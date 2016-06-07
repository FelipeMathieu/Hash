#pragma once

#include<iostream>
#include<time.h>
#include<vector>
#include<fstream>

using namespace std;

class Hash
{
private:
	vector<vector<long int>> elementos;
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
	void printHash();
	void quickSort(vector<long int> *v, int left, int right, int aux);
	vector<long int> Get_IndexHash(int i) 
	{ 
		return this->elementos[i]; 
	}
};

