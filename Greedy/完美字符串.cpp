#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int cnt[26];

int main() {
	string s;
	int sum;
	while(cin>>s) {
		sum = 0;
		memset(cnt,0,sizeof(cnt));
		int len = s.length();
		for(int i=0;i<len;i++)
			s[i] = toupper(s[i]);
		for(int i=0;i<len;i++)
			cnt[s[i]-65]++;
		sort(cnt,cnt+26,greater<int>());
		for(int i=0; i<=25; i++)
			sum += cnt[i]*(26-i);
		cout << sum << endl;
	}
	
	return 0;
}
