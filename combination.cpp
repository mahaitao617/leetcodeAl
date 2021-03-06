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
