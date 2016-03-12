/*
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。
处理:
1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
3.输入的文件可能带路径，记录文件名称不能带路径

输入描述:

一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

    文件路径为windows格式

    如：E:\V1R2\product\fpgadrive.c 1325



输出描述:

将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1 

    结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。

    如果超过8条记录，则只输出前8条记录.

    如果文件名的长度超过16个字符，则只输出后16个字符


输入例子:

E:\V1R2\product\fpgadrive.c 1325


输出例子:

fpgadrive.c 1325 1
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
struct ErrorLog
{
  string name;
  int line;
  int count;
};
void creatErrorLog(ErrorLog &log,string name,int line)
{
   int index=-1;
   for(int i=name.size()-1;i>=0;i--)
   {
      if(name[i]=='\\')
      {
        index=i;
        break;
      }
   }
   log.name=name.substr(index+1);
   log.line=line;
   log.count=1;
   return ;
}
void RecordErrorLog(vector<ErrorLog>&res,ErrorLog &log)
{
   bool isRepeated=false;
   for(int i=0;i<res.size();i++)
   {
      if(res[i].name==log.name && res[i].line==log.line)
      {
          isRepeated=true;
          res[i].count++;
          break;
      }
   }
   if(!isRepeated)
   {
      res.push_back(log);
   }
   return ;
}
static bool Compare(const ErrorLog& a, const ErrorLog& b)
{
   return a.count>b.count;
}
int main()
{
  string name;
  int line;
  vector<ErrorLog>res;
 /* ofstream fout;
  fout.open("log.txt");*/
  while(cin>>name>>line)
  {
      ErrorLog log;
      creatErrorLog(log,name,line);
      RecordErrorLog(res,log);
  }
  sort(res.begin(),res.end(),Compare);
  int length=res.size()>8?8:res.size();
  for(int i=0;i<length;i++)
  {
     int len=res[i].name.size();
     if(len>16)
         res[i].name=res[i].name.substr(len-16);
	  //fout<<res[i].name<<" "<<res[i].line<<" "<<res[i].count<<endl;
      cout<<res[i].name<<" "<<res[i].line<<" "<<res[i].count<<endl;
         
  }
  //cin.get();
  return 0;    
}
