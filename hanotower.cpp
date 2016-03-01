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
