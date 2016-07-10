第一题：人民币分为（1,5,10,20,50,100）的金额，若交易金额为19，收银（50），找零（20+10+1）交易所需人民币张数为4.或者收银（10+5+1+1+1+1）交易所需人民币张数为6.输入交易金额n,输出交易所需最少人民币数量

//dfs

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int res=0x7f;
bool flag=false;
void dfs(vector<int>&nums,int target,int sum,int cnt,int size)
{
   if(sum>target || flag)return ;
   if(sum==target)
   {
	   flag=true;
	   res=min(res,cnt);
	   return ;
   }
   for(int i=0;i<size;i++)
   {
	   sum+=nums[i];
	   cnt++;
	   dfs(nums,target,sum,cnt,size);
	   cnt--;
	   sum=sum-nums[i];
   }
}
int main()
{
  
	vector<int>nums(4,0);
	nums[0]=10;
	nums[1]=5;
	nums[2]=2;
	nums[3]=1;
	dfs(nums,19,0,0,4);
	cout<<res<<endl;
    return 0;
}

//dp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int res=0x7f;
bool flag=false;
void dfs(vector<int>&nums,int target,int sum,int cnt,int size)
{
   if(sum>target || flag)return ;
   if(sum==target)
   {
	   flag=true;
	   res=min(res,cnt);
	   return ;
   }
   for(int i=0;i<size;i++)
   {
	   sum+=nums[i];
	   cnt++;
	   dfs(nums,target,sum,cnt,size);
	   cnt--;
	   sum=sum-nums[i];
   }
}
int main()
{
  
	vector<int>nums(4,0);
	nums[0]=1;
	nums[1]=2;
	nums[2]=5;
	nums[3]=10;
	vector<vector<int>>dp(4,vector<int>(101,0x7f));
	for(int i=0;i<4;i++)
	{
		dp[i][0]=0;
	}
	for(int i=1;i<=100;i++)
	{
		if(i%nums[0]==0)
			dp[0][i]=i/nums[0];
	}
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=100;j++)
		{
			if(j>=nums[i])
			{
				dp[i][j] = min(dp[i][j-nums[i]]+1,dp[i][j]);
			}
			dp[i][j] = min(dp[i-1][j],dp[i][j]);
		}
	}
	cout<<dp[3][100]<<endl;
	cin.get();
    return 0;
}
