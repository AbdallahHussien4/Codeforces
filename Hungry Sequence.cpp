// hungry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int n, count = 0;
	bool flag = false;
	cin >> n;
	for (int i = 2; i <= 10000000; i++) {
		flag = false;
		for (int j = 2; j*j <= i; j++) {
			if (i%j == 0) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << i << " ";
			count++;
		}
		if (count == n) break;
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
