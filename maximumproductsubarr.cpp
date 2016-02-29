/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6. 
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int ans=nums[0];
    int front=1;
    int back=1;
    for(int i=0;i<nums.size();i++)
    {
        front*=nums[i];
        back*=nums[nums.size()-1-i];
        ans=max(ans,max(front,back));
        front=front==0?1:front;
        back=back==0?1:back;
    }
    return ans;
    }
};
