#include "Tree.h"
#include "Hash.h"
#include "Search.h"

void main(void)
{
	Hash *hash;
	Tree *tree = new Tree();
	int tamanho;
	long int elemento;
	clock_t j = NULL, k = NULL, result = NULL;
	clock_t j1 = NULL, k1 = NULL, result1 = NULL;
	float r, r1;
	float a1, c1, a, c;
	Node *aux = new Node();
	Search s;
	vector<long int> v;
	int i = 0;
	//ofstream arvore, vetor;

	cout << "Informe o tamanho: ";
	cin >> tamanho;

	srand(time(NULL));
	hash = new Hash(tamanho);

	//Inserção;
	//------------------------------------------

	while(i < tamanho)
	{
		elemento = (rand()*rand());

		if (elemento > 0)
		{
			k += clock();
			hash->insert(elemento);
			j += clock();

			k1 += clock();
			tree->insert(elemento);
			j1 += clock();

			i++;
		}
	}

	elemento = 0;
	i = 0;

	while (i < tamanho)
	{
		elemento = (rand()*rand());
		if (elemento > 0)
		{
			v.push_back(elemento);
			i++;
		}
	}

	result = j - k;
	r = ((float)result) / CLOCKS_PER_SEC;
	a = r;

	result1 = j1 - k1;
	r1 = ((float)result1) / CLOCKS_PER_SEC;
	a1 = r1;

	cout << "Tempo de insercao na hash: " << r << endl;
	cout << "Tempo de insercao na arvore: " << r1 << endl << endl;

	//Ordenação e balanceamente;
	//--------------------------------------------------------

	/*k = NULL;
	k1 = NULL;
	j = NULL;
	j1 = NULL;
	result = NULL;
	result1 = NULL;
	r = 0.0f;
	r1 = 0.0f;

	/*k = clock();
	for (int i = 0; i < tamanho; i++)
	{
		if (hash->Get_IndexHash(i).size() > 1)
		{
			hash->Get_IndexHash(i).sort(begin(), end());
		}
	}
	j = clock();

	result = j - k;
	r = ((float)result) / CLOCKS_PER_SEC;
	b = r;

	k1 = clock();
	aux = tree->balance(tree->Root());
	j1 = clock();

	result1 = j1 - k1;
	r1 = ((float)result1) / CLOCKS_PER_SEC;
	b1 = r1;

	//cout << "Tempo de ordenacao da hash: " << r << endl;
	cout << "Tempo de ordenacao da arvore: " << r1 << endl << endl;*/

	//cout << "Salvando...." << endl << endl;
	
	//hash->printHash();

	/*arvore.open("TreeInOrder.txt");
	tree->saveTreeInOrder(aux, arvore);
	arvore.close();*/

	/*vetor.open("VetorComp.txt");
	if (vetor.is_open())
	{
		for (int i = 0; i < v.size(); i++)
		{
			vetor << v.at(i) << " |";
		}
	}
	else
	{
		cout << "Erro ao salvar vetor auxiliar." << endl;
	}
	vetor.close();*/

	//Busca
	//-------------------------------------------------------

	k = NULL;
	k1 = NULL;
	j = NULL;
	j1 = NULL;
	result = NULL;
	result1 = NULL;
	r = 0.0f;
	r1 = 0.0f;

	k = clock();
	s.searchHash(*hash, tamanho, v);
	j = clock();

	result = j - k;
	r = ((float)result) / CLOCKS_PER_SEC;
	c = r + a;

	cout << "Tempo de busca na hash: " << r << endl;

	k1 = clock();
	s.searchTree(tree->Root(), tamanho, v);
	j1 = clock();

	result1 = j1 - k1;
	r1 = ((float)result1) / CLOCKS_PER_SEC;
	c1 = r1 + a1;

	cout << "Tempo de busca na arvore: " << r1 << endl << endl;

	cout << "Tempo total das operacoes na Hash: " << c << endl;
	cout << "Tempo total das operacoes na Arvore: " << c1 << endl << endl;
}