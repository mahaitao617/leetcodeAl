/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:

    pattern = "abba", str = "dog cat cat dog" should return true.
    pattern = "abba", str = "dog cat cat fish" should return false.
    pattern = "aaaa", str = "dog cat cat dog" should return false.
    pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space. 
*/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
    map<char ,int>p;
    map<string,int>w;
    istringstream input(str);
    int i=0,n=pattern.size();
    for(string word;input>>word;i++)
    {
        if(i==n || p[pattern[i]]!=w[word])
        return false;
        p[pattern[i]]=w[word]=i+1;
        
    }
    return i==n;
    }
};
