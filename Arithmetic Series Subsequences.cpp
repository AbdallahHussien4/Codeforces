#include <vector>
#include <iostream>
#include<unordered_map>
using namespace std;

int main()
{
    int N, D, M, Next, Current, Count = 1,f=0,c=0;
    cin >> N >> D >> M;
    int* Numbers = new int[N];
    for (int i = 0;i < N;i++)
        cin >> Numbers[i];
    unordered_map<int, int> Hash;
    unordered_map<int, int> isused;
    for (int i = 0;i < N;i++)
    {
        Hash[Numbers[i]]++;
    }
    if (M == 3)
    {
        for (int i = 0;i < N;i++)
            for (int j = i+1;j < N;j++)
                for (int k = j+1;k < N;k++)
                    if ((Numbers[j] - Numbers[i] == D) && (Numbers[k] - Numbers[j] == D))
                        f++;
    }
    else
    {
        for (int i = 0;i < N;i++)
            if (Hash.find(Numbers[i]) != Hash.end())
            {
                if (c == M)
                    f += Count;
                c = 1;
                Count = 1;
                Current = Numbers[i];
                Hash[Current]--;
                Next = Current + D;
                while (c < M)
                {
                    if (Hash.find(Next) != Hash.end())
                    {
                        Count *= Hash[Next];
                        Current = Next;
                        Next = Current + D;
                        c++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
    }
    cout << f<<endl;
   
}