/*

题目描述

求字典序在s1和s2之间的，长度在len1到len2的字符串的个数，结果mod 1000007。

输入描述:

每组数据包涵s1（长度小于100），s2（长度小于100），len1（小于100000），len2（大于len1，小于100000）



输出描述:

输出答案。


输入例子:

ab ce 1 2


输出例子:

56

*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MOD=1000007;
int main()
{
  int d[105]={0};
  string s1,s2;
  int len1,len2;
  while(cin>>s1>>s2>>len1>>len2)
  {
      int n1=s1.size();
      int n2=s2.size();
      int ans=0;
      for(int i=1;i<=max(len1,len2);i++)
      {
          d[i]=(n2<i?'a':s2[i-1])-(n1<i?'a':s1[i-1]);
          d[i]+=26*d[i-1];
          d[i]=d[i]%MOD;
          if(i<min(len1,len2))
              continue;
          ans += d[i] + 1 - (i < n2 ? 0 : 1) - (n1 < i ? 0 : 1);
          ans %= MOD;
      }
      cout<<ans<<endl;
  }
  return 0;    
}
