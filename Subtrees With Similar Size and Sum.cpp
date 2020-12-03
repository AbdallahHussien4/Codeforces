#include <iostream>
#include <set>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int Key;
    Node* Left;
    Node* Right;
    Node* Parent;
    Node()
    {
        Left = NULL;
        Right = NULL;
        Parent = NULL;
    }
};

unordered_map <int,int> Sum;

int GetSize(Node* n)
{
    if (n == NULL)
        return 0;
    return (1 + GetSize(n->Left) + GetSize(n->Right));
}

int FindSubTrees(Node* n,int m,int sum)
{
    if (n == NULL)
        return 0;
    int LS = FindSubTrees(n->Left,m,sum);
    if (LS == -1)
        return -1;
    int RS = FindSubTrees(n->Right,m,sum);
    if (RS == -1)
        return -1;
    sum += n->Key + LS + RS;
    int s=GetSize(n);
    if (Sum.find(sum) != Sum.end() && Sum[sum] == s && s>m)
        return -1;
    Sum[sum]=s;

    return sum;
}


int main()
{
    int N, M, T;
    cin >> N>>M ;

    Node* Nodes = new Node[N];
    for (int i = 0;i < N;i++)
    cin >> Nodes[i].Key;
    cin >> T;
    char* Dir = new char[T];
    int* Parents = new int[T];
    int* Childs = new int[T];
    for (int i = 0;i < T;i++)
    {
        cin >> Dir[i] >> Parents[i] >> Childs[i];
        if (Dir[i] == 'L')
        {
            Nodes[Parents[i]].Left = &Nodes[Childs[i]];
        }
        else if(Dir[i] == 'R')
        {
            Nodes[Parents[i]].Right = &Nodes[Childs[i]];

        }
    }

    int r= FindSubTrees(&Nodes[0],M,0);
    if (r == -1)
        cout << 1;
    else
        cout << 0;

}