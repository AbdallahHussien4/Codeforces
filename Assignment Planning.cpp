#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    //int* Penalties=new int[N];
    int* isused = new int[N];
    vector<vector<int>>DP(N, vector<int>(3));
    for (int i = 0;i < N;i++)
    {
        cin >> DP[i][1];
        DP[i][2] = 0;
        isused[i] = 0;
    }
    for (int i = 0;i < N;i++)
    {
        cin >> DP[i][0];
    }
    sort(DP.begin(), DP.end(), greater<vector<int>>());

    for (int i = 0;i < N;i++)
    {
        for (int j = DP[i][1]-1;j >= 0;j--)
        {
            if (!isused[j])
            {
                DP[i][2] = 1;
                isused[j] = 1;
                break;
            }
        }
    }
    long long Penalty = 0;
    for (int i = 0;i < N;i++)
        if (!DP[i][2])
            Penalty += DP[i][0];
    cout << Penalty;

    return 0;
}
