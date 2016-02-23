/*   Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5]. 
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int>res;  
    if(matrix.empty())return res;
    int row=matrix.size();
    int col=matrix[0].size();
    const int nx[]={0,1,0,-1};
    const int ny[]={1,0,-1,0};
    int i=0;
    int x=0,y=-1;
    while(row>0 && col>0)
    {
        int k;
        if(i%2==0)
        {
            k=col;
            row--;
        }
        else
        {
            k=row;
            col--;
        }
        while(k--)
        {
            x+=nx[i];
            y+=ny[i];
            res.push_back(matrix[x][y]);
        }
        i=(i+1)%4;//direction
    }
    return res;
    }
};
/* spiral matrix II
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>>res(n,vector<int>(n));
    int k=1,i=0;
    while(k<=n*n)
    {
        int j=i;
        //four steps
        while(j<n-i)
        res[i][j++]=k++;
        j=i+1;
        while(j<n-i)
        res[j++][n-i-1]=k++;
        j=n-i-2;
        while(j>i)
        res[n-i-1][j--]=k++;
        j=n-i-1;
        while(j>i)
        res[j--][i]=k++;
        i++;
    }
    return res;
    }
};
