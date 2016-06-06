#include "Search.h"

Search::Search()
{
}

Search::~Search()
{
}

void Search::searchTree(Node *root, int size, vector<long int> v)
{
	int count = 0;
	Node *t1 = root;

	for (int i = 0; i < size; i++)
	{
		while (root != NULL)
		{
			if (v.at(i) == root->element)
			{
				count += 1;
				break;
			}
			else if (v.at(i) < root->element)
			{
				root = root->left;
			}
			else if (v.at(i) > root->element)
			{
				root = root->right;
			}
		}
		root = t1;
	}

	free(t1);

	cout << "Existem " << count << " chaves do vetor2 na arvore." << endl;
}

void Search::searchHash(Hash h, int size, vector<long int> v)
{
	int count = 0;
	int aux;
	int meio, ultimo, primeiro;
	vector<long int> *hAux = new vector<long int>;

	for (int i = 0; i < size; i++)
	{
		aux = h.cHash(v.at(i));
		*hAux = h.Get_IndexHash(aux);
		ultimo = hAux->size() - 1;
		meio = hAux->size() / 2;
		primeiro = 0;
		if (hAux->size() > 0)
		{
			while (primeiro <= ultimo)
			{
				if (hAux->at(meio) < v.at(i))
				{
					primeiro = meio + 1;
				}
				else if (hAux->at(meio) == v.at(i))
				{
					count += 1;
					break;
				}
				else
				{
					ultimo = meio - 1;
				}
				meio = (primeiro + ultimo) / 2;
			}
		}
	}

	cout << "Existem " << count << " chaves do vetor na Hash." << endl;
}