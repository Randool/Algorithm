#include <cstdio>
#include <stack>
#include <cstring>
#include <iostream>
#define pro_w fs.top().weight
#define pro_d fs.top().dir
using namespace std;

struct Fish
{
    int weight;
    int dir;
    Fish(int w, int d)
    {
        weight = w;
        dir = d;
    }
};

stack<Fish> fs;

int main()
{
    int n, w, d, cnt = 0;
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
    {
        scanf("%d%d", &w, &d);
        if (fs.empty())
            fs.push(Fish(w, d));
        else
        {
            if (!pro_d && d || pro_d == d) fs.push(Fish(w,d));
            else // pro_d = 1 && d == 0
            {
                while (pro_d && pro_w < w)   // 向下吃
                {
                    fs.pop();
                    if (fs.empty()) break; // 防止越界 
				} 
				if (fs.empty()) // 防止越界 
				{
					fs.push(Fish(w, d));
					continue;
				}
                if (pro_d && pro_w > w)
                    continue;
                else
                    fs.push(Fish(w, d));
            }
        }
    }
    printf("%d\n", fs.size());

    return 0;
}
