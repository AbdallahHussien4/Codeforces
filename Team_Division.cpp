#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, T, Teams = 1;
    int currentStudent = 0;
    cin >> N >> T;
    int* Student = new int[N];
    int* Friend1 = new int[T];
    int* Friend2 = new int[T];
    for (int i = 0; i < N; i++)
    {
        Student[i] = 1;
    }
    for (int i = 0;i < T;i++)
    {
        cin >> Friend1[i] >> Friend2[i];

    }
    while ( currentStudent < N)
    {
        Teams=Student[currentStudent];
        for (int i = 0; i < T; i++)
        {
            if (Friend1[i] == currentStudent && Student[Friend2[i]] == Teams)
            {
                Student[Friend2[i]] = Teams + 1;
            }
            else if (Friend2[i] == currentStudent && Student[Friend1[i]] == Teams)
            {
                Student[Friend1[i]] = Teams + 1;
            }
        }
        currentStudent++;

    }
    int max = 0;
    for (int i = 0; i < N;i++)
    {
        if (max < Student[i])
            max = Student[i];
    }

    cout << max;
    return 0;
}