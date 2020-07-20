#include <bits/stdc++.h>
using namepsace std;
//Only function Implementation
class TreeNode{
public:
	int data ;
	TreeNode *left , *right;
	TreeNode(int val)
	{
		data = val;
		left = right = NULL;
	}
};

vector <int> inorder(TreeNode * root)
{
	vector <int> list;
	if(!root)
		return list;
	TreeNode *iterator = root;
	stack <TreeNode*> s;
	while(true)
	{
		while(iterator)
		{
			s.push(iterator);
			iterator = iterator->left;
		}
		if(s.empty())
			break;
		iterator = s.top();
		s.pop();
		list.push_back(iterator->data);
		iterator = iterator->right;
	}
	
	return list;
}
