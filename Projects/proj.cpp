

#include <fstream>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


struct Node
{
    int data;
    Node *left;
    Node *right;
};


Node *newNode(int data);



Node *buildUtil(int in[], int post[], int inStrt, int inEnd, int *pIndex, unordered_map<int, int> &mp)
{
    
    if (inStrt > inEnd){
        return NULL;
    }
    
    int curr = post[*pIndex];
    Node *node = newNode(curr);
    (*pIndex)--;

    
    if (inStrt == inEnd){
        return node;
    }
    
    int iIndex = mp[curr];

   
    node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex, mp);
    node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex, mp);

    return node;
}


struct Node *buildTree(int in[], int post[], int len)
{
    
    unordered_map<int, int> mp;
    for (int i = 0; i < len; i++){
        mp[in[i]] = i;
    }
    int index = len - 1; 
    return buildUtil(in, post, 0, len - 1, &index, mp);
}

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}



void parse(string code, Node *t, vector<int> &datavalues)
{
    Node *p = t;

    for(int pos = 0; pos < code.length(); pos++){
        p = code[pos]=='0' ? p->left : p->right;
        
        if (p->left == NULL) {
            datavalues.push_back(p->data);
            p = t;
        }
    }
}




int main(int argc, char const *argv[])
{

    vector<int> inOrder;
    vector<int> postOrder;

    ifstream inOrderFile;
    inOrderFile.open(argv[1]);
    int q;

    while (inOrderFile >> q)
    {
        inOrder.push_back(q);
    }

    ifstream postOrderFile;
    postOrderFile.open(argv[2]);

    while (postOrderFile >> q)
    {
        postOrder.push_back(q);
    }

    
    ifstream codeFile;
    codeFile.open(argv[3]);

    string w;
    string code;
    
    while(codeFile >> w){
        code = w;
    }
    

    int x = postOrder.size();

    int in[x];
    int post[x];

    
    for(int i = 0; i < x; i++)
    {
        in[i] = inOrder.at(i);
    }
    
    
    for(int i = 0; i < x; i++)
    {
        post[i] = postOrder.at(i);
    }
    

    int n = sizeof(in) / sizeof(in[0]);

    Node *root = buildTree(in, post, n);

 

    vector<int> datavalues;

    parse(code, root, datavalues);

    // Test to make sure data values were stored correctly.
    // for(int i = 0; i < datavalues.size(); i++){
    //     cout << datavalues.at(i) <<  " ";
    // }
    
    
    for(int i = 0; i < datavalues.size(); i++){

        cout  << char(datavalues.at(i));
    }
    

    cout << endl;
    return 0;
}
