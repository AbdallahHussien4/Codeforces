#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
    long long N;
    cin >> N;
    if (N == 0)
    {
        cout << 0;
        return 0;
    }
    long long* FirstRow = new long long[N];
    long long* SecondRow = new long long[N];
    long long* memo1 = new long long[N];
    long long* memo2 = new long long[N];

    for (int i = 0;i < N;i++)
        cin >> FirstRow[i];
    for (int i = 0;i < N;i++)
        cin >> SecondRow[i];

    memo1[0] = FirstRow[0];
    memo2[0] = SecondRow[0];
    memo1[1] = SecondRow[0] + FirstRow[1];
    memo2[1] = FirstRow[0] + SecondRow[1];

    for (int i = 2;i < N;i++)
    {
        memo1[i] = FirstRow[i]+max(max(memo2[i - 1], memo1[i - 2]), memo2[i - 2]) ;
        memo2[i] = SecondRow[i]+max(max(memo1[i - 1], memo2[i - 2]), memo1[i - 2]) ;
    }

    cout <<max(memo1[N - 1],memo2[N - 1]);
    
}
