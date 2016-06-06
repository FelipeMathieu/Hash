#include "Hash.h"

Hash::Hash(int tamanho)
{	
	this->elementos = vector<vector<long int>>(tamanho, vector<long int>(0));
	this->tamanho = tamanho;
}

Hash::~Hash()
{
}

void Hash::insert(long int e)
{
	this->elementos[this->cHash(e)].push_back(e);
	//quickSort(&this->elementos[this->cHash(e)], 0, this->elementos[this->cHash(e)].size() - 1);
}

void Hash::printHash()
{
	ofstream hash("Hash.txt");

	if (hash.is_open())
	{
		for (int i = 0; i < this->tamanho; i++)
		{
			if (this->elementos[i].size() > 0)
			{
				for (int j = 0; j < this->elementos[i].size(); j++)
				{
					hash << this->elementos[i].at(j) << " ";
				}
				hash << " |";
			}
			else
			{
				hash << " |";
			}
		}
	}
	else
	{
		cout << "Erro ao salvar Hash." << endl;
	}
	hash.close();
}

void Hash::quickSort(vector<long int> *v, int left, int right, int aux) {
	int i = left, j = right;
	int tmp;
	int pivot = v->at((left + right) / 2);

	/* partition */
	while (i <= j) {
		while (v->at(i) < pivot)
			i++;
		while (v->at(j) > pivot)
			j--;
		if (i <= j) {
			tmp = v->at(i);
			v->at(i) = v->at(j);
			v->at(j) = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(v, left, j, aux);
	if (i < right)
		quickSort(v, i, right, aux);

	this->elementos[aux] = *v;
}