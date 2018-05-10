#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int l, flag;

struct Word {
	char begin, end;
} c[100];

int vis[100];

void dfs(char ch) {
	int i;
	if(ch == 'm')
		flag = 1;
	if(flag)
		return;
	for(i=0; i<l; i++) {
		if(vis[i])
			continue;
		if(c[i].begin == ch) {
			vis[i] = 1;
			dfs(c[i].end);
			vis[i] = 0;
		}
	}
}

int main() {
	char s[100];
	int i;
	//将每一段看成三部分：第一个单词、剩下的单词、0 
	while(~scanf("%s",s)) {
		if(strcmp(s,"0")==0)
			continue;
		l = 0;
		c[l].begin=s[0];
		c[l].end=s[strlen(s)-1];
		l++;
		while(scanf("%s",s),strcmp(s,"0")) {
			c[l].begin=s[0];
			c[l].end=s[strlen(s)-1];
			l++;
		}
		flag = 0;
		for(int i=0; i<l; i++) {
			if(c[i].begin=='b') {
				memset(vis,0,sizeof(vis));
				vis[i]=1;
				dfs(c[i].begin);
			}
			if(flag) break;
		}
		if(flag) printf("Yes.\n");
		else printf("No.\n");
	}
	return 0;
}
