#include "BST.h"
#include <string>
#include <stack>
using namespace std;

void BST::Insert(int key, int val)
{
	if (root == nullptr)
	{
		root = new BSTNode(key, val, nullptr);
	}
	else
	{
		BSTNode* find = root;
		while (find != Nil)
		{
			if (key < find->key)
			{
				if (find->left == Nil)
				{
					find->left = new BSTNode(key, val, find);
					break;
				}
				else
				{
					find = find->left;
				}
			}
			else
			{
				if (find->right == Nil)
				{
					find->right = new BSTNode(key, val, find);
					break;
				}
				else
				{
					find = find->right;
				}
			}
		}
	}
}

int BST::Get(int key)
{
	BSTNode* find = FindNode(key);
	if (find == nullptr)
	{
		throw("no this key");
	}
	else
	{
		return find->val;
	}
}

string BST::ToString()
{
	string res = "";
	if (root == nullptr) return res;

	BSTNode* now = root;
	stack< BSTNode*> nodes = stack< BSTNode*>();

	while (now != Nil || !nodes.empty())
	{
		// 根节点和左节点入栈
		while (now != Nil)
		{
			nodes.push(now);
			now = now->left;
		}

		// 出栈 
		if (!nodes.empty())
		{
			now = nodes.top();
			nodes.pop();
			res = res + " " + to_string(now->key);
			now = now->right;	// 下个循环会将 右子树的左节点入栈
		}
	}


	return res;
}

BST::BST()
{
	if (Nil == nullptr)
	{
		Nil = new BSTNode();
	}
}

BSTNode* BST::FindNode(int key)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	else
	{
		BSTNode* find = root;
		while (find != Nil)
		{
			if (key < find->key)
			{
				find = find->left;
			}
			else if (key > find->key)
			{
				find = find->right;
			}
			else 
			{
				break;	// 找到指定节点
			}
		}
		return find;
	}
}



BSTNode::BSTNode(int k, int v, BSTNode* parent)
{
	key = k;
	val = v;
	left = Nil;
	right = Nil;
	this->parent = parent;
}

BSTNode::BSTNode()
{
}
