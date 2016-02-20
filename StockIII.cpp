/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Show Tags
Show Similar Problems

分析：这道题非常的巧妙，题目中说最多分两段进行，那么肯定在一个节点前，买入之后再卖出，然后在这个节点之后，先买入后卖出。
那么就可以维护两个数组，第一个数组是指，从前向后遍历，在某个节点之前能获取的最大收益。第二个数组指：从后向前遍历，在某
个节点之后获取的最大收益。使用DP算法来获取者两个数组，然后在两个数组中找到某个节点，使两个数组的对应项相加和最大。
即找到了最大收益值。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if (length <= 0)
            return 0;
        int *front = new int[length];
        int *end = new int[length];

        int low = prices[0];
        int height = prices[0];
        front[0] = 0;
        for (int i = 1; i < length; i++) {
            int tmpVal = prices[i] - low;
            front[i] = front[i - 1] > tmpVal ? front[i - 1] : tmpVal;
            if (prices[i] < low)
                low = prices[i];
        }
        height = prices[length - 1];
        low = prices[length - 1];
        end[length - 1] = 0;
        for (int i = length - 2; i >= 0; i--)
        {
            int tmpVal = height - prices[i];
            end[i] = end[i + 1]>tmpVal ? end[i + 1] : tmpVal;
            if (prices[i] > height)
                height = prices[i];
        }
        int max = front[0] + end[0];
        for (int i = 1; i < length; i++) {
            if (front[i] + end[i]>max)
                max = front[i] + end[i];
        }
        return max;
    }
};
