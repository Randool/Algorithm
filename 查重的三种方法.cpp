/*查重复的三种方法*/
//以0-8的全排列对应 362879个数为例： 
//State 为八数码的状态 
//st[]储存了每一步的状态 

/*方法一*/ 
/**/ 
int vis[362880], fact[9];

/*方法二*/
/*哈希技术*/ 
const int hashsize = 1000003;
int head[hashsize], next[hashsize];
void init_lookup_table() { memset(head,0,sizeof(head)); }
int hash(State& s) {
	int v = 0;
	for(int i=0; i<9; i++) v = v*10 + s[i];
	return v % hashsize;
}
int try_to_insert(int s) {
	int h = hash(st[s]);
	int u = head[h];
	while(u) {
		if(memcmp(st[u], st[s], sizeof(st[s])) == 0) return 0;
		u = next[u];
	}
	next[s] = head[h];
	head[h] = s;
	return 1;
}

/*方法三*/
/*STL*/ 
