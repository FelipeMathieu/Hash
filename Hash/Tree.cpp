#include "Tree.h"

Tree::Tree()
{
	this->root = NULL;
}

Tree::~Tree()
{
}

void Tree::insert(long int e)
{
	if (this->root != NULL)
	{
		insertNode(e, root);
	}
	else
	{
		root = new Node();
		root->element = e;
	}
}

void Tree::insertNode(long int e, Node *leaf)
{
	Node *aux = NULL;

	while (leaf != NULL)
	{
		aux = leaf;
		if (e < leaf->element)
		{
			leaf = leaf->left;
		}
		else if (e >= leaf->element)
		{
			leaf = leaf->right;
		}
	}

	if (e >= aux->element)
	{
		aux->right = new Node();
		leaf = aux->right;
		leaf->element = e;
	}
	else if (e < aux->element)
	{
		aux->left = new Node();
		leaf = aux->left;
		leaf->element = e;
	}

	//root = balance(root);
}

int Tree::search(long int e, Node *aux)
{
	if (aux != NULL)
	{
		if (e == aux->element)
		{
			cout << "Elemento " << e << " existe!" << endl;
			return 1;
		}
		else if (e < aux->element)
		{
			search(e, aux->left);
		}
		else
		{
			search(e, aux->right);
		}
	}
	else
	{
		cout << "Elemento nao existe!" << endl;
		return 0;
	}
}

void Tree::printPreOrder(Node *t)
{
	if (t != NULL)
	{
		cout << t->element << " |";
		printPreOrder(t->left);
		printPreOrder(t->right);
	}
}

void Tree::printInOrder(Node *t)
{
	if (t != NULL)
	{
		printInOrder(t->left);
		cout << t->element << " |";
		printInOrder(t->right);
	}
}

void Tree::printPostOrder(Node *t)
{
	if (t != NULL)
	{
		printPostOrder(t->left);
		printPostOrder(t->right);
		cout << t->element << " |";
	}
}

int Tree::height(Node *t)
{
	int h = 0, leftHeight, rightHeight, maxHeight;

	if (t != NULL)
	{
		leftHeight = height(t->left);
		rightHeight = height(t->right);
		maxHeight = max(leftHeight, rightHeight);
		h = maxHeight + 1;
	}

	return h;
}

int Tree::difHeight(Node *t)
{
	int x, y, z;

	x = height(t->left);
	y = height(t->right);

	z = x - y;

	return z;
}

Node *Tree::balance(Node *t)
{
	int bFactor;
	Node *aux;

	if (t == NULL)
	{
		return t;
	}

	if (t != NULL)
	{
		t->left = balance(t->left);
		t->right = balance(t->right);
		bFactor = difHeight(t);

		if (bFactor > 1)
		{
			if (t->left != NULL)
			{
				aux = t->left;
			}
			else
			{
				aux = NULL;
			}
			if (difHeight(aux) < 0)
			{
				t = leftRightRotate(t);
			}
			else
			{
				t = rightRotate(t);
			}
		}
		else if (bFactor < -1)
		{
			if (t->right != NULL)
			{
				aux = t->right;
			}
			else
			{
				aux = NULL;
			}
			if (difHeight(aux) > 0)
			{
				t = rightLeftRotate(t);
			}
			else
			{
				t = leftRotate(t);
			}
		}
	}

	return t;
}

void Tree::display(Node *t, long int lvl)
{
	int i;

	if (t != NULL)
	{
		display(t->right, lvl + 1);
		cout << endl;
		if (t == root)
		{
			cout << "Root -> ";
		}
		for (i = 0; i < lvl && t != root; i++)
		{
			cout << "        ";
		}
		cout << t->element;
		display(t->left, lvl + 1);
	}
}

Node *Tree::rightRotate(Node *t)
{
	Node *q;
	Node *aux;

	q = t->left;
	aux = q->right;
	q->right = t;
	t->left = aux;

	//cout << "Simple Right Rotate." << endl;

	return q;
}

Node *Tree::leftRotate(Node *t)
{
	Node *q;
	Node *aux;

	q = t->right;
	aux = q->left;
	q->left = t;
	t->right = aux;

	//cout << "Simple Left Rotate." << endl;

	return q;
}

Node *Tree::leftRightRotate(Node *t)
{
	t->left = leftRotate(t->left);
	return rightRotate(t);
}

Node *Tree::rightLeftRotate(Node *t)
{
	t->right = rightRotate(t->right);
	return leftRotate(t);
}

void Tree::remove(Node *t, long int e)
{
	int aux;

	if (t == NULL)
	{
		cout << "A arvore esta vazia!" << endl;
	}
	else
	{
		aux = search(e, t);
		if (aux == 1)
		{
			t = removeElement(t, e);
			if (t != NULL)
			{
				cout << "Elemento " << e << " removido!" << endl;
				root = balance(root);
			}
			else
			{
				cout << "Arvore vazia!" << endl;
				root = NULL;
			}
		}
		else
		{
			return;
		}
	}
}

Node *Tree::removeElement(Node *t, long int e)
{
	if (t == NULL)
	{
		return t;
	}
	if (e < t->element)
	{
		t->left = removeElement(t->left, e);
	}
	else if (e > t->element)
	{
		t->right = removeElement(t->right, e);
	}

	else
	{
		if (t->left == NULL || t->right == NULL)
		{
			Node *aux = t->left ? t->left : t->right;

			if (aux == NULL)
			{
				aux = t;
				t = NULL;
			}
			else
			{
				*t = *aux;
			}
			free(aux);
		}
		else
		{
			Node *aux = t->right;

			while (aux->left != NULL)
			{
				aux = aux->left;
			}

			t->element = aux->element;
			t->right = removeElement(t->right, t->element);
		}
	}
	return t;
}

void Tree::saveTreeInOrder(Node *t, ostream &out)
{
	int i;

	if (t != NULL)
	{
		saveTreeInOrder(t->left, out);
		out << t->element << " |";
		saveTreeInOrder(t->right, out);
	}
}

void Tree::saveTreePostOrder(Node *t, ostream &out)
{
	int i;

	if (t != NULL)
	{
		saveTreeInOrder(t->left, out);
		saveTreeInOrder(t->right, out);
		out << t->element << " |";
	}
}

void Tree::saveTreePreOrder(Node *t, ostream &out)
{
	int i;

	if (t != NULL)
	{
		out << t->element << " |";
		saveTreeInOrder(t->left, out);
		saveTreeInOrder(t->right, out);
	}
}