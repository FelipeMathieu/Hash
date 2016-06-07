#include "Hash.h"

Hash::Hash(int tamanho)
{	
	this->elementos = vector<No*>(tamanho);
	this->tamanho = tamanho;

	for (int i = 0; i < tamanho; i++)
	{
		this->elementos[this->cHash(i)] = new No();
	}
}

Hash::~Hash()
{
}

void Hash::insert(long int e)
{
	No *novo = new No();
	No *aux = this->elementos[this->cHash(e)];
	No *ant = NULL;

	for (aux; aux != NULL; aux = aux->prox)
	{
		ant = aux;
	}

	novo->e = e;

	if (ant == NULL)
	{
		novo->prox = this->elementos[this->cHash(e)];
		this->elementos[this->cHash(e)] = novo;
	}
	else
	{
		novo->prox = ant->prox;
		ant->prox = novo;
	}
	//free(aux);
}

/*void Hash::printHash()
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
}*/

/*void Hash::quickSort(list<long int> *v, int left, int right, int aux) {
	int i = left, j = right;
	int tmp;
	int pivot = v->((left + right) / 2);

	//partition 
	while (i <= j) {
		while (v-> < pivot)
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

	// recursion 
	if (left < j)
		quickSort(v, left, j, aux);
	if (i < right)
		quickSort(v, i, right, aux);

	this->elementos[aux] = *v;
}*/