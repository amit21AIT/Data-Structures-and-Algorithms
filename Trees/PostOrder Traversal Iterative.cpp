#incude <bits/stdc++.h>
using namespace std;
//Only function implementation
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

vector <int> postorder(TreeNode* root)
{
	vector <int> list;
	if(!root)
		return list;
	TreeNode *iterator = root;
	TreeNode *previous = NULL;
	stack <TreeNode *> s;
	do{
		while(iterator)
		{
			s.push(iterator);
			iterator = iterator->left;
		}
		
		while(iterator == NULL && !s.empty())
		{
			iterator = s.top();
			if(iterator->right == NULL || iterator->right == previous)
			{
				list.push_back(iterator->data);
				s.pop();
				previous = iterator;
				iterator = NULL;
			}
			else
				iterator = iterator->right;
		}
	}while(!s.empty());
	
	return list;
}
