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

vector <vector<int>> levelOrder(TreeNode *root)
{
	vector <vector<int>> list;
	if(!root)
		return list;
	queue <TreeNode *> s;
	s.push(root);
	while(!root)
	{
		vector <int> level;
		int size = s.size();
		for(int i = 0 ; i < size ; i++)
		{
			TreeNode *temp = s.top();
			s.pop();
			level.push_back(temp->data);
			if(temp->left)
				s.push(temp->left);
			if(temp->right)
				s.push(temp->right);
		}
		
		list.push_back(level);
	}
	
	return list;
	
}
