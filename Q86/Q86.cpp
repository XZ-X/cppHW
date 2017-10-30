#include<iostream>

#define MIN(x,y) ((x)>(y)?(x):(y))

using namespace std;
int m, n;
int visit(int* a, int r, int c){
	return *(a + c + r*n);
}
int main(){
	cin >> m >> n;
	auto data = new int[m*n];
	for (int i = 0; i < m*n; i++){
		cin >> data[i];
	}
	int dest;
	cin >> dest;
	dest++;
	int k = 0,sum=0; 
	for (k = 0; k < MIN(m, n); k++){
		sum += (m + n) * 2 - 4 - 4 * k;
		if (dest > sum) break;
	}
	dest -= sum - ((m + n) * 2 - 4 - 4 * k);
	k--;
	if (dest <= m - 2 * k){
		cout << visit(data,k,dest+k-1);
	}
	else if (dest <= (m - 2 * k) + (n - 2 * k) - 1){
		cout << visit(data, dest - (m - 2 * k) + k - 1, m - k - 1);
	}
	else if (dest <= (m - 2 * k) * 2 + (n - 2 * k) - 1){
		cout << visit(data, m - k - 1, n - k - 1 - (dest - ((m - 2 * k) * 2 + (n - 2 * k) - 1)));
	}
	else{
		cout << visit(data, m - 1 - k - ((dest - ((m - 2 * k) * 2 + (n - 2 * k) - 1) + (m - 2 * k - 1))), k);
	}

	return 0;
}