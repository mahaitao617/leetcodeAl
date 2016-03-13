/*
The numberic keypad on your mobile phone looks like below:
123
456
789
 0
 suppose you are holding your mobile phone with single hand. Your thumb points at digit 1. Each time you can 
 1)press the digit your thumb pointing at.2)moveyour thumb right,
 3)move your thumb down. Moving your thumb left or up is not allowed.
 By using the numeric keypad under above constrains, you can produce some numbers like 177 or 480 
 while producing other numbers like 590 or 52 is impossible.
 Given a number K, find out the maximum number less than or equal to K that can be produced.

输入描述:

the first line contains an integer T, the number of testcases.
Each testcase occupies a single line with an integer K.

For 50%of the data ,1<=K<=999.
For 100% of the data, 1<=K<=10^500,t<=20.



输出描述:

for each testcase output one line, the maximum number less than or equal to the corresponding K that can be produced.


输入例子:

3
25
83
131


输出例子:

25
80
129
*/
#include <vector>
#include <iostream>
#include <string.h>
 
using namespace std;
#define maxn 510
char a[maxn];
int t,n;
int pad[][10]=
{
{1,0,0,0,0,0,0,0,0,0},
{1,1,1,1,1,1,1,1,1,1},
{1,0,1,1,0,1,1,0,1,1},
{0,0,0,1,0,0,1,0,0,1},
{1,0,0,0,1,1,1,1,1,1},
{1,0,0,0,0,1,1,0,1,1},
{0,0,0,0,0,0,1,0,0,1},
{1,0,0,0,0,0,0,1,1,1},
{1,0,0,0,0,0,0,0,1,1},
{0,0,0,0,0,0,0,0,0,1},
};
 
bool dfs(int pos,vector<int> &res,int x,int fp)
{ 
    if(pos>=n) return true;
    int len=fp?a[pos]-'0':9;
    for(int i=len;i>=0;i--)
	{ //i
        if(pad[x][i])
		{
            res.push_back(i);
            //cout<<i<<endl;
            if(dfs(pos+1,res,i,fp&&((a[pos]-'0')==i))) return true;
            res.pop_back();
        }
    }
    return false;
}
 
int main(void)
{
    //freopen("debug.txt","r",stdin);
    cin>>t;         
    while(t--)
	{
        cin>>a;
        n=strlen(a);
        vector<int> res;
        dfs(0,res,1,1);
 
        int i=0;
        for(;i<res.size();i++){
            if(res[i]!=0) break;
        }
        for(;i<res.size();i++) cout<<res[i];
        cout<<endl;
    }
    return 0;
}
