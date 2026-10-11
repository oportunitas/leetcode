// Created by oportunitas at 2026/10/11 12:48
// leetgo: 1.4.18
// https://leetcode.com/problems/maximum-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #1 (0ms/100th% | 40.6MB/97th%)
        an alternative to idea #0 that doesnt use recursion is by using a stack as an 
        intermediary abstraction of us going down/up the tree.

        this implementation does not need a nested for loop to find the max num in a 
        subarray.
    */
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;

        vector<TreeNode*> node_stack;
        for (const auto& num : nums) {
            TreeNode* cur_node {new TreeNode(num)};
            // as long as current node's value is bigger than what came before it,
            // we need to traverse up the tree (popping the vector) until we find
            // one that has the value bigger than current node.
            // 
            // the current node should have been the right child of this found node (instead).
            // and the incumbent right child (if there's any) should be the left child
            // of our current node instead.
            while (!node_stack.empty() && node_stack.back()->val < num) {
                cur_node->left = node_stack.back();
                node_stack.pop_back();
            }   
            
            // there's still nodes above our current node. we must set that node's right
            // child as the current node. if there's none, the current node is the root
            if (!node_stack.empty()) {
                node_stack.back()->right = cur_node;
            } node_stack.push_back(cur_node);
        } return node_stack[0];
    }

    // /* idea #0 (10ms/66th% | 43.7MB/72nd%)
    //     the code should be self explanatory, we traverse down
    // */
    // TreeNode* traverse(vector<int>& nums, int left, int right) {
    //     if (left > right) return nullptr;

    //     int max_num {-1}; int max_i {-1};
    //     for (int i {left}; i <= right; ++i) {
    //         if (nums[i] > max_num) {
    //             max_num = nums[i];
    //             max_i = i;
    //         }
    //     } 
        
    //     TreeNode* cur_node = new TreeNode(max_num);
    //     cur_node->left = traverse(nums, left, max_i - 1);
    //     cur_node->right = traverse(nums, max_i + 1, right);

    //     return cur_node;
    // }


    // TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    //     if (nums.empty()) return nullptr;
    //     return traverse(nums, 0, nums.size() - 1);
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.constructMaximumBinaryTree(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
