/*


Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.

Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]


Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/
class Solution {
public:
    void dfs(vector<vector<int>>&res,vector<int>&path,int k,int n,int pos,int sum)
    {
       if(k==0 && sum==n)
       {
           res.push_back(path);
           return ;
       }
       for(int i=pos;i<=9;i++)
       {
           if(sum+i>n)break;
           path.push_back(i);
           sum+=i;
           dfs(res,path,k-1,n,i+1,sum);
           path.pop_back();
           sum-=i;
       }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>>res;
    vector<int>path;
    int sum=0;
    dfs(res,path,k,n,1,sum);
    return res;
    }
};
