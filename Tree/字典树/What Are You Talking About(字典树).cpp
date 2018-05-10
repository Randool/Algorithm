/*HDU 1075*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char w1[15], w2[15];
char words[3005], ans[3005];

struct Trie {
	bool flag;
	char earth[15];
	struct Trie* next[26];
	Trie() {
		flag = 0;
		memset(next,0,sizeof(next));
		memset(earth,0,sizeof(earth));
	}
};

Trie *root = new Trie;

void make_tree(char* word, char* earth) {
	int len = strlen(word);
	Trie *p = root;
	for(int i=0; i<len; i++) {
		if (p->next[word[i]-'a'] == NULL)
			p->next[word[i]-'a'] = new Trie;
		p = p->next[word[i]-'a'];
	}
	p->flag = 1;
	strcpy(p->earth, earth);
}

void find_tree(char* s) {
	Trie* p = root;
	int len = strlen(s);
	if(len == 0) return;
	for(int i=0; i<len; i++) {
		char c = s[i] - 'a';
		if(p->next[c] == NULL) {
			printf("%s",s);
			return;
		}
		p = p->next[c];
	}
	if(p->flag)
		printf("%s",p->earth);
	else
		printf("%s", s);
}

bool is_alph(char c) {
	if(c<='z' && c>='a') return 1;
	return 0;
}

int main() {
	scanf("%s", &w1);
	while(scanf("%s", &w1)) {
		if(strcmp(w1,"END")==0)
			break;
		scanf("%s", &w2);
		make_tree(w2, w1);
	}

	scanf("%s", &w1);
	getchar();

	while(gets(words)) {
		if(strcmp(words,"END") == 0)
			break;
		int k = 0;
		
		for(int i=0; words[i]!='\0'; i++) {
			
			if( is_alph(words[i])) {
				w1[k++] = words[i];
			}

			else if( !is_alph(words[i]) ) {
				w1[k] = '\0';
				find_tree(w1);
				k=0;
				printf("%c",words[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
/*
START
from fiwo
hello difh
mars riwosf
earth fnnvk
like fiiwj
END
START
difh, i'm fiwo riwosf.
i fiiwj fnnvk!
END
*/
