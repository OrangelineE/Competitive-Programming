#include<iostream>
using namespace std;
int getCheap(int n, int m, int a, int b){
	int total_price = 0;
	int unit_price = b/m;
	if (a <= unit_price) {
		total_price += n * a;
	}else {
		if (n%m == 0) {
		total_price = n/m * b;	
		}else {
		int price1 = n%m * a + n/m *b;
		int price2 = (n/m + 1)*b;
		total_price = price1 < price2 ? price1 : price2; 
		}
	}
	return total_price;
}

int main()
{
int n, m, a, b;
cin >> n >> m >> a >> b;
cout << getCheap(n, m, a, b) << endl;
return 0;

}
