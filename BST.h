#include <string>

#pragma once
class BSTNode
{
public:
	int key;
	int val;
	BSTNode* left;
	BSTNode* right;
	BSTNode* parent;

public:
	BSTNode(int k, int v, BSTNode* parent);
	BSTNode();
};

static BSTNode* Nil;

class BST
{
public:
	BSTNode* root;

public:
	void Insert(int key, int val = 0);
	int Get(int key);
	std::string ToString();
	BST();

private:
	BSTNode* FindNode(int key);
};

