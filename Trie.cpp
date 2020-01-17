#include <bits/stdc++.h>
using namespace std;
class TrieNode{
  public:
    char data;
    TrieNode *child[26];
    bool isWord;
    TrieNode()
    {
        isWord = false;
        for(int i = 0  ; i < 26;  i++)
            child[i] = NULL;
    }
};

void insert(TrieNode *root, string word)
{
    TrieNode *tempNode = root;
    for(int i = 0  ; i < word.size()  ; i++)
    {
        int ind = word[i] - 'a';
        if(!tempNode->child[ind])
            tempNode->child[ind] = new TrieNode();
        tempNode = tempNode->child[ind];
        
    }
    tempNode->isWord = true;
}

bool search(TrieNode *root , string key)
{
    TrieNode *tempNode = root;
    for(int i = 0 ; i < key.size() ;  i++)
    {
        int ind = key[i] - 'a';
        if(!tempNode->child[ind])
            return false;
        tempNode = tempNode->child[ind];
    }
    
    return tempNode!=NULL && tempNode->isWord;
}
int main()
{
    int i,j,n,m,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string input;
        TrieNode * root = new  TrieNode();
        for(int i = 0  ; i < n  ; i++)
        {
            cin>>input;
            insert(root , input);
        }
        string key;
        cin>>key;
        if(search(root , key))  
            cout<<1;
        else
            cout<<0;
        cout<<endl;
    }
}
