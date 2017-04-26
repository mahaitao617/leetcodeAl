#include<iostream>
#include <algorithm>
#include<string>
using namespace std;
//用来处理字符串长度不一样的情况
string process(string res,string str,int i,int &carry)
{
	while(i>=0)
	{
		if(carry==0)
		{
			for(;i>=0;i--)
			{
				res += str[i];
			}
			break;
		}
		int temp = (str[i]-'0'+carry)%10;
		carry = (str[i]-'0'+carry)/10;
		res +=(temp+'0');
		i--;
		
	}
	return res;
}
string bigDataAdd(string str1,string str2)
{
	string res = "";
	if(str1=="" || str2=="")return res;
	int len1 = str1.size();
	int len2 = str2.size();
	int carry = 0;
	int i = len1-1;
	int j = len2-1;
	for(;i>=0 && j>=0;i--,j--)
	{
		int temp = (str1[i]-'0'+str2[j]-'0'+carry)%10;
		carry = (str1[i]-'0'+str2[j]-'0'+carry)/10;
		res += (temp+'0');
	}
	if(i>=0)
	{
		res = process(res,str1,i,carry);
	}
	else if(j>=0)
	{
		res = process(res,str2,j,carry);
	}
	if(carry == 1)
	{
		res += "1";
	}
	reverse(res.begin(),res.end());
	return res;
}
int main()
{
    
	cout<<bigDataAdd("1999","1")<<endl;
	cin.get();
    return 0;
}
