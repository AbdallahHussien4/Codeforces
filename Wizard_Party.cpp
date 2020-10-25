#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int house=0;
bool checkPortal(int r, int n, int* Friend1, int* Friend2,int t)
{
    for (int j = 0; j < t; j++)
    {
        if ((Friend1[j] == r  && Friend2[j] == n) || (Friend2[j] == r  && Friend1[j] == n)||n==r)
        {
            return true;
        }
    }
    return false;
}
void Recursion(int* Friend1, int* Friend2, int* used, int j, int N, int& Max, int t, int l,int sum)
{
    if (Max == 1)
        return;
    if (house == N )
    {
        if (checkPortal(0,l,Friend1,Friend2,t))
        {
            Max = 1;
        }
        house--;
        return;
        
    }
    
    for (int i = 0; i < N;i++)
    {
        if (!used[i] && checkPortal(l, i, Friend1, Friend2, t))
        {
            house++;
            used[i] = 1;
            Recursion(Friend1, Friend2, used, i + 1, N, Max, t, i, sum);
            used[i] = 0;
        }
    }
    house--;
}


int main() {

    int N, T, max = 0;
    cin >> N >> T;
    int* isused = new int[N];
    int* Friend1 = new int[T];
    int* Friend2 = new int[T];
    for (int i = 0; i < N; i++)
    {
        isused[i] = 0;
    }
    for (int i = 0;i < T;i++)
    {
        cin >> Friend1[i] >> Friend2[i];

    }
    if (N == 1)
    {
        cout << 1;
        return 0;
    }
    Recursion(Friend1, Friend2, isused, 0, N, max, T,0,0);
    cout << max;
    return 0;
}
