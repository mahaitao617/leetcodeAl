/*Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

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
