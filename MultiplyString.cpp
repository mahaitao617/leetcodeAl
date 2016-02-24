/*
Given two numbers represented as strings, return multiplication of the numbers as a string.
*/
class Solution {
public:
    string multiply(string num1, string num2) {
    int len1=num1.size();
    int len2=num2.size();
    vector<int>res(len1+len2,0);
    string ans;
    int i,j;
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
        res[i+j]+=(num1[i]-'0')*(num2[j]-'0');
        res[i+j+1]+=res[i+j]/10;
        res[i+j]=res[i+j]%10;
        }
    }
    for(i=len1+len2-1;i>0 && res[i]==0;i--)
    ;
    for(;i>=0;i--)
    {
        ans+=to_string(res[i]);
    }
    return ans;
    }
};
