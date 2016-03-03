/*
Given an array nums, there is a sliding window of size k which is moving from the very left
of the array to the very right. You can only see the k numbers in the window. Each time the 
sliding window moves right by one position.
For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Therefore, return the max sliding window as [3,3,5,5,6,7].
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int>res;
    if(nums.size()<=0)return res;
    deque<int>qmax;
    for(int i=0;i<nums.size();i++)
    {
        if(qmax.empty())
        qmax.push_back(i);
        while(!qmax.empty() && nums[qmax.back()]<=nums[i])
        {
            qmax.pop_back();
        }
        qmax.push_back(i);
        if(qmax.front()==i-k)
        {
            qmax.pop_front();
        }
        if(i>=k-1)
        {
            res.push_back(nums[qmax.front()]);
        }
    }
    return res;
    }
};
