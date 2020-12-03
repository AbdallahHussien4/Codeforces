#include <iostream>
#include <set>
#include<vector>
#include<algorithm>
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

void Median(Node* n, int &c,int level , vector<long long> p)
{
    if (n == NULL)
        return;
    p.push_back(n->Key);
    if (level % 2 == 1)
    {
        sort(p.begin(), p.end());
        int index=p.size() / 2;
        if (p[index] == n->Key)
            c++;
    }
    Median(n->Left,c,level+1,p);
    Median(n->Right,c,level+1,p);

}

int main()
{
    int N, R, T,Count=0;
    cin >> N ;

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
    vector<long long> Path;
    Median(&Nodes[0], Count,1,Path);
    cout << Count;

}