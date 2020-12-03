#include <iostream>
#include <set>
#include<vector>
#include<algorithm>
#include <climits>
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

int GetHeight(Node* n)
{
    if (n == NULL)
        return 0;
    int LH = GetHeight(n->Left);
    int RH = GetHeight(n->Right);
    if (LH > RH)
        return LH + 1;
    return RH + 1;
}

void GetMinFromLevel(Node* n,int L,int& K,int c)
{
    if (n == NULL)
        return;
    if (c == L)
    {
        if (n->Key < K)
            K = n->Key;
    }
    GetMinFromLevel(n->Left, L, K, c + 1);
    GetMinFromLevel(n->Right, L, K, c + 1);
}


void GetLevelsSum(Node* n, int level, int sum[])
{
    if (n == NULL)
        return;
    sum[level] += n->Key;
    GetLevelsSum(n->Left, level + 1, sum);
    GetLevelsSum(n->Right, level + 1, sum);
}

int main()
{
    int N, T;
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
    int H = GetHeight(&Nodes[0]);
    int L = Nodes[0].Key % H;
    int K = INT_MAX;
    GetMinFromLevel(&Nodes[0], L,K,0);
    K%=H;
    if (K == 0)
        K = 1;
    int* sum = new int[H];
    for (int i = 0;i < H;i++)
        sum[i] = 0;
    GetLevelsSum(&Nodes[0], 0, sum);
    for (int i = 0;i < H;i+=K)
        cout << sum[i] ;

}