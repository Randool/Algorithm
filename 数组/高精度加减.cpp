#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int a[10001], b[10001], ans[10001];
int main() {
	string ta, tb;
	int lena, lenb, i, l;
	cin >> ta >> tb;
	if(ta[0] != '-' && tb[0] != '-')
	{
		int la = lena = ta.length(), lb = lenb = tb.length();
		l=max(la,lb);
		for(i = 10000; i > 10000 - lena; i--)
			a[i] = (int)ta[--la]-48;
		for(i = 10000; i > 10000 - lenb; i--)
			b[i] = (int)tb[--lb]-48;
		for(i=10000; i > 10000 - l; i--) {
			int sum = a[i]+b[i];
			ans[i] += sum % 10;
			ans[i-1] += sum / 10;
		}
		for(i=10000-l; i<=10000; i++) {
			if(ans[i]==0) continue;
			cout<<ans[i];
		}
	}
	else if(ta[0]=='-' && tb[0]=='-')
	{
		int la = lena = ta.length()-1, lb = lenb = tb.length()-1;
		l=max(la,lb);
		for(i = 10000; i > 10000 - lena; i--)
			a[i] = (int)ta[--la]-48;
		for(i = 10000; i > 10000 - lenb; i--)
			b[i] = (int)tb[--lb]-48;
		for(i=10000; i > 10000 - l; i--) {
			int sum = a[i]+b[i];
			ans[i] += sum % 10;
			ans[i-1] += sum / 10;
		}
		cout<<"-";
		for(i=10000-l; i<=10000; i++) {
			if(ans[i]==0) continue;
			cout<<ans[i];
		}
	}
	/*int la = lena = ta.length(), lb = lenb = tb.length();
	l=max(la,lb);
	for(i = 10000; i > 10000 - lena; i--)
		a[i] = (int)ta[--la]-48;
	for(i = 10000; i > 10000 - lenb; i--)
		b[i] = (int)tb[--lb]-48;
	for(i=10000; i > 10000 - l; i--) {
		int sum = a[i]+b[i];
		ans[i] += sum % 10;
		ans[i-1] += sum / 10;
	}
	for(i=10000-l; i<=10000; i++) {
		if(ans[i]==0) continue;
		cout<<ans[i];
	}*/
	return 0;
}
