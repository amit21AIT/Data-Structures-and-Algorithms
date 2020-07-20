#include <bits/stdc++.h>
using namespace std;

class TreeNode  {
public :
	int data;
	TreeNode *left , *right;
	TreeNode(int val)
	{
		data = val;
		left = right = NULL;	
	}	
		
};

class BST{
public:
	TreeNode *root;
	BST(){
		root = NULL;
	}
	
	void insert(int val){
		if(!root)
			root = new TreeNode(val);
		else 
		{
			TreeNode *iterator = root;
			while(iterator)
			{
				if(val <= iterator->data)
				{
					if(iterator->left)
						iterator = iterator->left;
					else 
					{
						iterator->left = new TreeNode(val);
						return;
					}
				}
				else 
				{
					
					if(iterator->right)
						iterator = iterator->right;
					else 
					{
						iterator->right = new TreeNode(val);
						return;
					}
				}
					
			}
		}
	}
	
	int min()
	{
		TreeNode *iterator = root;
		while(iterator->left)
			iterator = iterator->left;
		return iterator->data;
	}
	
	
	int max()
	{
		TreeNode *iterator = root;
		while(iterator->right)
			iterator = iterator->right;
		return iterator->data;
	}
	
	TreeNode * minValueNode(TreeNode *iterator)
	{
		while(iterator->left)
			iterator = iterator->left;
		return iterator;
	}
	
	TreeNode* deleteNodeUtil(TreeNode *iterator , int val)
	{
		if(!iterator)
			return NULL;
			
		if(val < iterator->data)
			iterator->left = deleteNodeUtil(iterator->left , val);
		else if(val > iterator->data)
			iterator->right = deleteNodeUtil(iterator->right , val);
		else
		{
			if(!iterator->left && !iterator->right)
			{
				delete iterator;
				return NULL;
			}
			else if(!iterator->left)
			{
				TreeNode *temp = iterator->right;
				delete iterator;
				return temp;
			}
			else if(!iterator->right)
			{
				TreeNode *temp = iterator->left;
				delete iterator;
				return temp;
			}
			TreeNode *temp = minValueNode(iterator->right);
			iterator->data = temp->data;
			root->right = deleteNodeUtil(iterator->right,temp->data);
		}
	
    }
	
	void deleteNode(int val)
	{
		TreeNode *iterator = root;
		root = deleteNodeUtil(iterator , val);
	}
	
};

void inorder(TreeNode *root)
{
	if(!root)
		return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	BST bst;
	bst.insert(20);
	bst.insert(12);
	bst.insert(39);
	bst.insert(11);
	bst.insert(49);
	inorder(bst.root);
	cout<<endl;
	bst.deleteNode(39);
	inorder(bst.root);
}
