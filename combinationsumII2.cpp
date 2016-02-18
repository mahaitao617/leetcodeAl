/*
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/
class Solution {
public:
    void dfs(vector<vector<int>>&res,vector<int>&solution,vector<int>candidates,int sum,int level,int target)
    {
        if(sum>target)return ;
        if(sum==target)
        {
            res.push_back(solution);
        }
        for(int i=level;i<candidates.size();i++)
        {
            solution.push_back(candidates[i]);
            dfs(res,solution,candidates,sum+candidates[i],i+1,target);
            solution.pop_back();
            while(candidates[i]==candidates[i+1])i++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>>res;
    vector<int>solution;
    sort(candidates.begin(),candidates.end());
    int sum=0;
    dfs(res,solution,candidates,sum,0,target);
    return res;
    }
};
