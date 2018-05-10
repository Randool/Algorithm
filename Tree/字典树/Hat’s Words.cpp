/*http://acm.hdu.edu.cn/showproblem.php pid=1247*/
#include <cstdio>
#include <cstring>
using namespace std;

char words[50005][50];

struct Trie{
	bool flag;
	Trie* next[26];
	Trie() {
		flag = 0;
		memset(next,0,sizeof(next));
	}
};

Trie* root = new Trie;

void insert(char* c) {
	Trie* p = root;
	int len = strlen(c);
	for(int i=0; i<len; i++)
	{
		int t = c[i] - 'a';
		if(p->next[t] == NULL)
		{
			p->next[t] = new Trie;
			if(i == len-1)
				p->flag = 1;
			p = p->next[t];
		}
	}
	//p->flag = 1;
}

bool find(char* c) {
	Trie* p = root;
	int len = strlen(c);
	for(int i=0; i<len; i++)
	{
		int t = c[i]-'a';
		if(p->next[t] == NULL)
			return 0;
		p = p->next[t];
	}
	return p->flag;
}

char t1[50], t2[50];

int main()
{
	char word[50];
	int cnt = 0;
	while(scanf("%s", &words[cnt]) != EOF)
	{
		if(strcmp(words[cnt],"END")==0) break;
		insert(words[cnt++]);
	}
	for(int i=0; i<cnt; i++)
		printf("%s\n", words[i]);
	for(int i=0; i<cnt; i++)
	{
		int len = strlen(words[i]);
		//printf("%d\n" ,len);
		for(int j=1; j<len; j++)
		{
			memset(t1,0,sizeof(t1));
			memset(t2,0,sizeof(t2));
			for(int t = 0; t<j; t++)
				t1[t] = words[i][t];
			for(int t = j; t<len; t++)
				t2[t] = words[i][t];
			if(find(t1) && find(t2))
			{
				printf("%s. %s. ", t1,t2);
				printf("%s\n", words[i]);
				break;
			}
		}
	}
	return 0;
}
/*
a
ahat
hat
hatword
hziee
word
END
*/
