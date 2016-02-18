 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    vector<bool> row(m, false); //标记该行是否存在0
    vector<bool> col(n, false);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==0)
            row[i]=col[j]=true;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(row[i])
        {
            for(int j=0;j<n;j++)
            matrix[i][j]=0;
        }
    }
    for(int j=0;j<n;j++)
    {
        if(col[j])
        {
            for(int i=0;i<m;i++)
            matrix[i][j]=0;
        }
    }
    return ;
    }
};
