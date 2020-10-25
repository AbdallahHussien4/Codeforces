#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void Recursion(int* arr,int* used, int n,int sum ,int t,int i , bool &f)
{
    bool b = false;
    if (f)
        return;
    if (sum == t)
    {
        f = true;
        return;
    }
    if (i == n || sum > t)
    {
        b = true;
        sum = 0;
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
            Recursion(arr, used, n, sum + arr[i], t, i + 1,f);
            used[i] = 0;
        }
    }

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, T;
    cin >> T >> N;
    int* A = new int[N];
    int* isused = new int[N];
    bool found = false;
    for (int i = 0;i < N;i++)
    {
        cin >> A[i];
        isused[i] = 0;
    }
    Recursion(A, isused, N, 0, T, 0, found);
    if (found)
        cout << 1;
    else
        cout << 0 ;
    return 0;
}

