// Created by oportunitas at 2026/09/21 11:04
// leetgo: 1.4.18
// https://leetcode.com/problems/range-sum-of-bst/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
	/* idea #0 (0ms/100th% | 65.1MB/31th%)
		we can just bring the sum along and add them whenever we find nodes with values
		between low and high. for added performance, we can ignore the left child of nodes
		with values smaller or equal to low, vice versa for high
	*/
public:
	void add_and_recurse(TreeNode* cur_node, int& sum, int& low, int& high) {
		if (cur_node == nullptr) return;

		if (cur_node->val >= low && cur_node->val <= high) {
			sum += cur_node->val;
		} 
		
		if (cur_node->val > low) {
			add_and_recurse(cur_node->left, sum, low, high);
		}

		if (cur_node->val < high) {
			add_and_recurse(cur_node->right, sum, low, high);
		}
	}

    int rangeSumBST(TreeNode* root, int low, int high) {
		int result {0};
		add_and_recurse(root, result, low, high);
		return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		TreeNode* root = LeetCodeIO::deserialize<TreeNode*>(cin);
		int low = LeetCodeIO::deserialize<int>(cin);
		int high = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.rangeSumBST(root, low, high);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
