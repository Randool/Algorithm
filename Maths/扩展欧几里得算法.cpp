#include <cstdio>
using namespace std;

int gcd(int a, int b, int& d, int& x, int& y) {
	if(!b) {
		d = a;
		x = 1;
		y = 0;
	}
	else {
		gcd(b, a%b, d, y, x);
		y -= x * (a / b);
	}
}

int main() {
	
	return 0;
}
