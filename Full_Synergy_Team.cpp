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


int main() {

    int N, T, max = 0;
    cin >> N >> T;
    int* Friend1 = new int[T];
    int* Friend2 = new int[T];

    for (int i = 0;i < T;i++)
    {
        cin >> Friend1[i] >> Friend2[i];

    }
    for (int k = 0;k < N;k++)
    {
        vector<int> isused(1);
        int c = 1;
        bool good = true;
        isused[0] = k;
        for (int i = k+1; i < N;i++)
        {
            for (int j = 0;j < c;j++)
                if (!checkPortal(isused[j], i, Friend1, Friend2, T))
                {
                    good = false;
                }
            if (good)
            {
                isused.push_back(i);
                c++;
            }
            else
                good = true;
        }
        if (c > max)
            max = c;
    }
    cout << max;
    return 0;
}
