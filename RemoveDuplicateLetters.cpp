/*
 Given a string which contains only lowercase letters, remove duplicate letters so
 that every letter appear once and only once. You must make sure your result is the 
 smallest in lexicographical order among all possible results.

Example:

Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
    if(s.size()<=1)return s;
    string res="0";
    int a[256]={0};
    vector<bool>visited(256,false);
    for(int i=0;i<s.size();i++)
    {
        a[s[i]]++;
    }
    for(int i=0;i<s.size();i++)
    {
        a[s[i]]--;
        if(visited[s[i]])continue;
        while(s[i]<res.back() && a[res.back()])
        {
            visited[res.back()]=false;
            res.pop_back();
        }
        res=res+s[i];
        visited[s[i]]=true;
    }
    return res.substr(1);;
    }
};
