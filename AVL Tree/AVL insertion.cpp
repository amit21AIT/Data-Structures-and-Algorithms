#include <bits/stdc++.h>
using namespaces std;
// function implementation only

class Node{
	public:
		int data , height;
		Node *next;
		Node()
		{
			next = NULL;
		}
		Node(int val)
		{
			data = val;
			height = 1;
			next = NULL;
		}
};

Node *rightRotate(Node *root)
{
	Node *newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;
	root->height = max(root->left->height , root->right->height) + 1;
	newRoot->height = max(newRoot->left->height , newRoot->right->height) + 1;
	return newRoot;
}

Node *leftRotate(Node *root)
{
	Node *newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;
	root->height = max(root->left->height , root->right->height) + 1;
	newRoot->height = max(newRoot->left->height , newRoot->right->height) + 1;
	return newRoot;
}

Node *avlInsert(Node *root , int value)
{
	if(root == NULL)
		return new Node(value);
	else if(value<=root->data)
		root->left = avlInsert(root->left , value);
	else 
		root->right = avlInsert(root->right , value);
		
	int balance = root->left->height - root->right->height;
	
	if(balance>1)
	{
		if(root->left->left->height >= root->right->right->height)
			return rightRotate(root);
		else
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}	
	}	
	else if( balance<-1)
	{
		if(root->right->right->height >= root->right->left->height)
			return leftRotate(root);
		else
		{
			root->right = rightRotate(root->left);
			return leftRotate(root);
		}
	}
	
	root->height = 1 + max(root->left->height , root->right->height);
	return root;
}
