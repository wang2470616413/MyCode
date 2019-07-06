#include<stdio.h>
#include<string.h>
#include<algorithm>
#define ll long long 
#define mmset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 1e6;
int trie[N][30], num[N] = {0};
int root = 0, index = 1;
void insert(char* data)
{
    int len = strlen(data);
    int rt = root;
    for(int i = 0; i < len; i++)
    {
        int y = data[i] - 'a';
        if(trie[rt][y] == 0)
        {
            trie[rt][y] = index++;
        }
        rt = trie[rt][y];
        num[rt]++;
    }
}
int query(char* str)
{
    int len = strlen(str);
    int rt = root;
    for(int i = 0; i < len; i++)
    {
        int y = str[i] - 'a';
        rt = trie[rt][y];
        if(rt == 0)
        {
            return 0;
        }
    }
    return num[rt];
}

int main()
{
    char word[11];
     while(gets(word))
     {
       if(word[0]==NULL)    //空行。gets读入的回车符会自动转换为NULL。
             break;
         insert(word);
     }
     while(gets(word))
         printf("%d\n",query(word));
    return 0;
}