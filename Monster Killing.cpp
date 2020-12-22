#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

vector<int> MinShots(int Health, int* guns, int M, vector<int>& shots, vector<int>& health)
{
    vector<int> Result(2);
    if (Health == 0 || (Health < guns[0] || !guns[0]))
    {
        Result[0] = Health;
        Result[1] = 0;
        return Result;
    }

        
    if (health[Health] != -1)
    {
        Result[0] = health[Health];
        Result[1] = shots[Health];
        return Result;
    }

    vector<int> Temp(2,INT_MAX);
    vector<int> Current(2);

    for (int i = 0;i < M;i++)
    {
        if (guns[i] == 0 || (Health - guns[i] < 0))
            continue;
        Current=MinShots(Health - guns[i], guns, M, shots, health);

        if (Temp[0] > Current[0] || (Temp[0] == Current[0] && Temp[1] > Current[1] +1))
        {
            Temp[0] = Current[0];
            Temp[1] = Current[1]+1;
        }
    }
    health[Health] = Temp[0];
    shots[Health] = Temp[1];
    return Temp;
}

int main() {
        
    int N, M, maxHealth = 0;
    cin >> N;
    int* Monsters = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> Monsters[i];
        maxHealth = max(maxHealth, Monsters[i]);
    }
    cin >> M;
    int* Weapons = new int[M];
    int c=0;
    for (int i = 0; i < M; i++)
    {
        int kaka;
        cin >> kaka;
        if(kaka)
        {
            Weapons[c++]=kaka;
        }
    }
    sort(Weapons, Weapons + c);
    vector<int> Shots(maxHealth+1, -1);
    vector<int> Health(maxHealth+1, -1);
    vector<int> Result(2);

    for (int i = 0;i < N;i++)
    {
        Result=MinShots(Monsters[i], Weapons, c, Shots, Health);
        cout << Result[0] << ' ' << Result[1] << endl;
    }
    return 0;
}