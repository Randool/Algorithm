#include <cstdio>
#include <cstring>
char str[101][101];
int n;
int find_str(int len,int index) {
	char s[101],pos[101],inv[101];
	bool flag;
	int i,j,l;
	//将字符串拷贝出来
	strcpy(s,str[index]);
	l=len;
	// 舍弃后面的
	while(l>0) {
		flag = 0;
		for(i = 0; i <= len-l; ++i) {
			flag=1;//flag初始化为1
			//正向字符串，将str中第i个位置，取l长度（舍弃前面的）
			strncpy(pos,s+i,l);
			//inv 为pos的逆序
			for(j=0; j<l; j++)
				inv[j]=pos[l-j-1];
			// 字符数组，最后\0，防止某些不必要的冲突
			pos[l]=inv[l] ='\0';
			for(j=0; j<n; j++) {
				if(strstr(str[j],pos)==NULL&&strstr(str[j],inv)==NULL) {
					flag=0;
					break;
				}
			}
			if(flag)    break;
		}
		if(flag)    break;
		--l;
	}
	return l;
}

int main() {
	int i,t,min_len,index;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		min_len = 101;
		for(i = 0; i < n; i++) {
			scanf("%s",str[i]);
			//找到最短的字符串
			if(strlen(str[i])<min_len) {
				min_len = strlen(str[i]);//记录最短字串的长度
				index = i;//记录最短字串的位置
			}
		}
		printf("%d\n",find_str(min_len,index));
	}
	return 0;
}
