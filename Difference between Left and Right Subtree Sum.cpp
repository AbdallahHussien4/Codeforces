#include <iostream>
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

long long Sum(Node* n)
{
    if (n == NULL)
        return 0;
    return(n->Key+Sum(n->Right) + Sum(n->Left));
}

long long Diff(Node* n,int c=0)
{
    if (n == NULL)
        return 0;
    return(abs(Sum(n->Right) - Sum(n->Left)));
}
int main()
{
    int N, R, T,Count=0;
    cin >> N >> R;

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

    for (int i = 0;i < N;i++)
        if (Diff(&Nodes[i]) <= R)
            Count++;
    cout << Count;

}