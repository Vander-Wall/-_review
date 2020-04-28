
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 2e6 + 5;
int tree[maxn][27];
int flag[maxn];
int sum[maxn];
int tot;
void _insert(char *str)
{
    int len =strlen(str);
    int rt=0;
    for(int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if(!tree[rt][id]) // 表示如果没有访问过
            tree[rt][id]=++tot;
        //printf("tree[rt][id]=%d\n", tree[rt][id]);
        sum[tree[rt][id]]++;
        //printf("sum[tree[rt][id]]=%d\n", sum[tree[rt][id]]);
        rt = tree[rt][id];
    }
    flag[rt]=1;
}
int _find(char *str)
{
    int len =strlen(str);
    int rt=0;
    for(int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if(!tree[rt][id]) // 如果没有出现过
            return 0;
        rt = tree[rt][id];
    }
    return sum[rt];
}
char ss[maxn];
int main()
{
    tot=0;
    memset(sum,0,sizeof(sum));
    while(gets(ss))
    {
        if(ss[0]=='\0')
            break;
        _insert(ss);
    }
    while(gets(ss))
    {
        printf("%d\n",_find(ss));
    }
    return 0;
}
