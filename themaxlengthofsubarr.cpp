/*
求一个数组的不含重复数字的连续子数组的最大长度
*/
#include<iostream>
#include<algorithm>
using namespace std;
int thelength(int nums[],int n);
int main()
{
	int a[]={1,2,3,4,3,2,1,4,5,8,7,8,9,7,4,1,2,4};
	int len=sizeof(a)/sizeof(int);
	cout<<thelength(a,len)<<endl;
	cin.get();
    return 0;
}
int thelength(int nums[],int n)
{
	if(n<0 || nums==NULL)return -1;
	int len=0;
	int map[256];
	for(int i=0;i<256;i++)
	{
		map[i]=-1;
	}
	int pre=-1;
	for(int i=0;i<n;i++)
	{
		pre=max(pre,map[nums[i]]);
		len=max(len,i-pre);
		map[nums[i]]=i;
	}
	return len;
}
