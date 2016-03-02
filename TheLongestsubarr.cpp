/*


对于一个数字序列，请设计一个复杂度为O(nlogn)的算法，返回该序列的最长上升子序列的长度，
这里的子序列定义为这样一个序列U1，U2...，其中Ui < Ui+1，且A[Ui] < A[Ui+1]。

给定一个数字序列A及序列的长度n，请返回最长上升子序列的长度。
测试样例：

[2,1,4,3,1,5,6],7

返回：4
*/
class AscentSequence {
public:
    int findLongest(vector<int> A, int n) {
        // write code here
        int *dp=new int[n];
        int *ends=new int[n];
        dp[0]=1;
        ends[0]=A[0];
        int l=0;
        int r=0;
        int m=0;
        int right=0;
        int res=dp[0];
        for(int i=1;i<n;i++)
        {
              l=0;
              r=right;
            while(l<=r)
            {
              m=(l+r)/2;
                if(A[i]>ends[m])
                    { l=m+1;  }
                else{ r=m-1;}
            }
            right=max(right,l);
            ends[l]=A[i];
            dp[i]=l+1;
            res=max(dp[i],res);
        }
        return res;
    }
};

