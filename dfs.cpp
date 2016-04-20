#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;
/*
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
For example,
If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution 
{
public:
    void dfs(vector<int>&nums,vector<vector<int>>&res,vector<int>&path,int pos,int sum,int n)
    {
		if(sum<0)return ;
        if(sum==0)
		{
			res.push_back(path);
			return ;
		}
		for(int i=pos;i<n;i++)
		{
			path.push_back(nums[i]);
			sum=sum-nums[i];
			dfs(nums,res,path,i+1,sum,n);
			path.pop_back();
			sum=sum+nums[i];
		}
    }
    vector<vector<int>> combine(vector<int>nums, int sum,int n) 
	{
      vector<vector<int>>res;
	  vector<int>path;
	  //int sum=0;
	  if(nums.size()==0)return res;
	  dfs(nums,res,path,0,sum,n);
	  return res;
    }
private:

};
int main()
{
  vector<int>nums(6,0);
  for(int i=0;i<6;i++)
  {
	  nums[i]=i+1;
  }
  Solution a;
  vector<vector<int>>res=a.combine(nums,15,6);
  for(int i=0;i<res.size();i++)
  {
	  for(int j=0;j<res[i].size();j++)
		  cout<<res[i][j]<<" ";
	  cout<<endl;
  }
  cin.get();
  return 0;    
}
