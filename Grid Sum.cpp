#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    long long Mat[N][M];
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
            cin >> Mat[i][j];

    long long Values[N][M];
    
    Values[0][0]=Mat[0][0];
    for (int i = 1;i < M;i++)
        Values[0][i] = Values[0][i - 1]+Mat[0][i];
    for (int i = 1;i < N;i++)
        Values[i][0] = Values[i - 1][0]+Mat[i][0];

    for (int i = 1;i < N;i++)
        for (int j = 1;j < M;j++)
            Values[i][j] = max(Values[i - 1][j], max(Values[i - 1][j - 1], Values[i][j - 1])) + Mat[i][j];

    cout << Values[N-1 ][M-1 ];

}