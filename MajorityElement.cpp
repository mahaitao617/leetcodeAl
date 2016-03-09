/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. 
The algorithm should run in linear time and in O(1) space.
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    int cn1=0,cn2=0,a=0,b=1;
    for(auto n:nums)
    {
        if(a==n)
        {
            cn1++;
        }
        else if(b==n)
        {
            cn2++;
        }
        else if(cn1==0)
        {
            a=n;
            cn1=1;
        }
        else if(cn2==0)
        {
            b=n;
            cn2=1;
        }
        else
        {
            cn1--;
            cn2--;
        }
    }
    cn1=0;
    cn2=0;
    for(auto n:nums)
    {
        if(n==a)cn1++;
        else if(n==b)cn2++;
    }
    vector<int>res;
    if(cn1>nums.size()/3)res.push_back(a);
    if(cn2>nums.size()/3)res.push_back(b);
    return res;
    }
};
