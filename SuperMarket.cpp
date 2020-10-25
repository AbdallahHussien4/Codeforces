#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void Recursion(int* arrV, int* arrW, int* used, int n, int& max, int sum, int weight, int t, int i)
{
    bool b = false;
    if (sum >= max && weight <= t)
    {
        max = sum;
    }
    if (i == n || weight >= t)
    {
        b = true;
        sum = 0;
        weight = 0;
        return;
    }
    for (int i = 0;i < n;i++)
    {
        if (used[i] == 0)
        {
            if (b)
            {
                b = false;
                break;
            }
            used[i] = 1;
            Recursion(arrV, arrW, used, n, max, sum + arrV[i], weight + arrW[i], t, i + 1);
            used[i] = 0;
        }
    }

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, T, max = 0;
    cin >> T >> N;
    int* value = new int[N];
    int* weight = new int[N];
    int* isused = new int[N];
    for (int i = 0;i < N;i++)
    {
        cin >> weight[i];
        cin >> value[i];
        isused[i] = 0;
    }
    Recursion(value, weight, isused, N, max, 0, 0, T, 0);
    cout << max;
    return 0;
}
