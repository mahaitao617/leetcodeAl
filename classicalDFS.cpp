#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void dfs(string &s,vector<string>&res,int level,string &ans);
bool verify(string s);
int main()
{
    vector<string>res;
    string s="aabcd";
    int len=s.size();
	string ans;
	sort(s.begin(),s.end());
    dfs(s,res,0,ans);
    for(int i=0;i<res.size();i++)
	  cout<<res[i]<<endl;
    cin.get();
    return 0;    
}
void dfs(string &s ,vector<string>&res,int level,string &ans)
{
	for(int i=level;i<s.size();i++)
	{
		if(i!=level && s[i]==s[i-1])continue;
		ans.push_back(s[i]);
		if(verify(ans))
			res.push_back(ans);
		dfs(s,res,i+1,ans);
		ans.pop_back();
	}
}
bool verify(string s)
{ 
	if(s.size()<=0)return false;
	if(s.size()==1)return true;
	int len=s.size();
	sort(s.begin(),s.end());
	int count=1;
	for(int i=1;i<len;i++)
	{
		if(s[i-1]==s[i])continue;
		count++;
	}
	if(count==1||count==2|| count==3 || count==5 || count==8 || count==13 || count==21 || count==44 || count==65)
		return true;
    return false;
}
/*
 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3]
*/
class Solution {

public:

    void helper(vector<int>& candidates,int target,int level,int &sum,vector<int>&solution,vector<vector<int>>&res)

    {

        if(sum>target)return;

        if(sum==target)

        {

            res.push_back(solution);

            return;

        }

        for(int i=level;i<candidates.size();i++)

        {

           solution.push_back(candidates[i]);

           sum+=candidates[i];

           helper(candidates,target,i,sum,solution,res);

           solution.pop_back();

           sum=sum-candidates[i];

        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    vector<vector<int>>res;

    vector<int>solution;

    sort(candidates.begin(),candidates.end());

    int sum=0;

    helper(candidates,target,0,sum,solution,res);

    return res;

    }


};
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
class Solution {
public:
    void dfs(int pos,int n,int k,vector<int>&path,vector<vector<int>>&res)
    {
        if(k==0)
        {
            res.push_back(path);
            return ;
        }
        for(int i=pos;i<=n;i++)
        {
            path.push_back(i);
            dfs(i+1,n,k-1,path,res);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
    vector<vector<int>>res;
    vector<int>path;
    dfs(1,n,k,path,res);
    return res;
    }
};
/*
Total Accepted: 54253 Total Submissions: 188121 Difficulty: Medium
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
public:
    void dfs(int start,vector<int>&subset,vector<vector<int>> &subsets,const vector<int >&nums)
    {
	  subsets.push_back(subset);
	  for(int i=start;i<nums.size();i++)
	  {
	      if(i!=start && nums[i]==nums[i-1])continue;
	      subset.push_back(nums[i]);
	      dfs(i+1,subset,subsets,nums);
	      subset.pop_back();
	  }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>>subsets;
    vector<int>subset;
    dfs(0,subset,subsets,nums);
    return subsets;
    }
};
/*
Given a set of distinct integers, nums, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is: 
*/
class Solution {
public:   
    void  dfs(int start,vector<int>&path,vector<vector<int>>&res,vector<int>&nums)
    {
        if(!path.empty())
        res.push_back(path);
        for(int i=start;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            dfs(i+1,path,res,nums);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>path;
        vector<int>empty;
        sort(nums.begin(),nums.end());
        dfs(0,path,res,nums);
        res.push_back(empty);
        return res;
    }
};
