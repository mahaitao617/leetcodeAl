/*
汉诺塔三个步骤：
1,2....N-1,N个圆盘
第一步把1，2......N-2,N-1从left移动到mid,中间状态是right
第二步把第N个圆盘从left移动到right;中间状态是mid
第三步把1......N-1个圆盘从mid移动到right上,中间状态是left
时间复杂度推理
f(i)=f(i-1)+1+f(i-1)--->f(i)=2^i-1
*/
void hanofun(int n ,string from,string mid,string to)
{
	if(n==1)
		cout<<"move from: "<<from<<"-->"<<to<<endl;
	else
	{
		hanofun(n-1,from,to,mid);
		hanofun(1,from,mid,to);
		hanofun(n-1,mid,from,to);
	}
}
/*补充


有一个int数组arr其中只含有1、2和3，分别代表所有圆盘目前的状态，1代表左柱，2代表中柱，3代表右柱，arr[i]的值代表第i+1个圆盘的位置。比如，arr=[3,3,2,1]，代表第1个圆盘在右柱上、第2个圆盘在右柱上、第3个圆盘在中柱上、第4个圆盘在左柱上。如果arr代表的状态是最优移动轨迹过程中出现的状态，返回arr这种状态是最优移动轨迹中的第几个状态。如果arr代表的状态不是最优移动轨迹过程中出现的状态，则返回-1。

给定一个int数组arr及数组的大小n，含义如题所述，请返回一个int，代表所求的结果。
测试样例：

[3,3]

返回：3
*/
// Method1
class Hanoi {
public:
    int chkStep(vector<int> arr, int n) {
        // write code here
       if(arr.size()==0 || n==0)return -1;
       return process(arr,arr.size()-1,1,2,3);
    }
    int process(vector<int>arr,int i,int from,int mid,int to)
        {
        if(i==-1)return 0;
        if(arr[i]!=from && arr[i]!=to)
            return -1;
        if(arr[i]==from)
            return process(arr,i-1,from,to,mid);
        else
            {
            int rest=process(arr,i-1,mid,from,to);
            if(rest==-1)return -1;
            return (1<<i)+rest;
        }
    }
};
// Method2
class Hanoi {
public:
    int chkStep(vector<int> arr, int n) {
        // write code here
         
        if (n == 0)
        {
          return -1;
        }
        int from = 1;
        int mid = 2;
        int to = 3;
        int i = n - 1;
        int res = 0;
        int tmp = 0;
        while (i >= 0)
        {
            if (arr[i] == mid )
            {
                return -1;
            }
            if (arr[i] == to)
            {
                res += 1 << i;  //2^(n-1)
                tmp = from;
                from = mid;
            }
            else
            {
                tmp = to;
                to = mid;
            }
            mid = tmp;
            i--;
        }
        return res;
    }
};
