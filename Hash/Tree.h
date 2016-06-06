#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

typedef struct Node
{
	long int element;
	Node *right, *left;
};

class Tree
{

private:

	Node *root;
	void insertNode(long int e, Node *leaf);
	Node *removeElement(Node *t, long int e);

public:
	Tree();
	~Tree();

	void insert(long int e);
	int search(long int e, Node *aux);
	void printPreOrder(Node *t);
	void printInOrder(Node *t);
	void printPostOrder(Node *t);
	Node *Root()
	{
		return root;
	}
	int height(Node *t);
	int difHeight(Node *t);
	Node *balance(Node *t);
	void display(Node *t, long int lvl);
	Node *rightRotate(Node *t);
	Node *leftRotate(Node *t);
	Node *leftRightRotate(Node *t);
	Node *rightLeftRotate(Node *t);
	void remove(Node *t, long int e);
	void saveTreeInOrder(Node *t, ostream &out);
	void saveTreePreOrder(Node *t, ostream &out);
	void saveTreePostOrder(Node *t, ostream &out);
};
