#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* priceA = new int[n];
	int* priceG = new int[n];
	int i = 0;
	while (i < n) {
		cin >> priceA[i]; 
		cin >> priceG[i];
		i++;
	}
	int A = 0;
	int	G = 0;
	char* out = new char[n];
	int k = 0;
	for (int j = 0; j < n; j++) {
		if (abs((A + priceA[j]) - G) < abs(A - (G + priceG[j]))) {
			A += priceA[j];
			out[k] = 'A';
			k++;
		}
		else {
			G += priceG[j];
			out[k] = 'G';
			k++;
		}
	}
	if (abs(A - G) > 500) {
		cout << -1;
	}
	else {
		for (int j = 0; j < n; j++) {
			cout << out[j];
		}
	}
	return 0;
}