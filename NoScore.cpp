/*
 用一维数组存储学号和成绩，然后，按成绩排序输出。 
输入描述:

输入第一行包括一个整数N(1<=N<=100)，代表学生的个数。
接下来的N行每行包括两个整数p和q，分别代表每个学生的学号和成绩。


输出描述:

按照学生的成绩从小到大进行排序，并将排序后的学生信息打印出来。
如果学生的成绩相同，则按照学号的大小进行从小到大排序。

输入例子:

3
1 90
2 87
3 92

输出例子:

2 87
1 90
3 92
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct Student {
    int No;
    int Score;
    Student(int no, int score): No(no), Score(score) {}
    Student() {}
    bool operator <(const Student& s2)const
    {
        if(Score != s2.Score)
            return Score < s2.Score;
        else
            return No < s2.No;
    }

} res[105];
int main()
{
    int n, i;
    while(scanf("%d", &n) == 1) {
        for(i = 0; i < n; i++)
            scanf("%d%d", &res[i].No, &res[i].Score);
        sort(res, res + n);
        for(i = 0; i < n; i++)
            printf("%d %d\n", res[i].No, res[i].Score);
    }
    return 0;
}
