/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode *sortedArrayTree(vector<int> &arr, int start, int end)
  {
    if (start > end) return NULL;
  
    TreeNode *root = new TreeNode(arr[(start + end)/2]);
  
    root -> left = sortedArrayTree(arr, start, (start + end)/2 - 1);
    root -> right = sortedArrayTree(arr, (start + end)/2 + 1, end);
    return root;
  }
  
  // 给定有序链表，构造高度平衡二叉树
  TreeNode *sortedListToBST(ListNode *head)
  {
    if (!head) return NULL;
  
    vector<int> tmp;
    while(head)
    {
      tmp.push_back(head -> val);
      head = head -> next;
    }
    return sortedArrayTree(tmp, 0, tmp.size() - 1);
  }

};
