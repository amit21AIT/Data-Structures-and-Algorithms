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
vector <int> Preorder(TreeNode *root)
{
	int i,j;
	vector <int> list;
	if(!root)
		return list;
	stack <TreeNode *> st;
	TreeNode *iterator = root;
	while(true)
	{
		while(iterator)
		{
			s.push(iterator);
			list.push_back(iterator->data);
			iterator = iterator->left;
		}
		if(s.empty())
			break;
		
		iterator = s.top();
		s.pop();
		iterator = iterator->right;
		
	}
	
	return list;
}
