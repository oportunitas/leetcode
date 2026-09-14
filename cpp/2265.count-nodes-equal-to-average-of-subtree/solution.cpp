// Created by oportunitas at 2026/09/14 09:11
// leetgo: 1.4.18
// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 15.9MB/29th%)
		lets try using the most straightforward solution, which is with recursion
	*/

	// returns <total_node_count, total_node_value>
	pair<int64_t, int64_t> subtree_total(int& result, TreeNode* cur_node) {
		if (cur_node == nullptr) {
			return {0, 0};
		} 
		// println("{}", cur_node->val);
		auto cur_node_val = cur_node->val;
		auto r_subtree_total = subtree_total(result, cur_node->right);
		auto l_subtree_total = subtree_total(result, cur_node->left);

		int64_t total_node_count = 1 + r_subtree_total.first + l_subtree_total.first;
		int64_t total_node_value = cur_node_val + r_subtree_total.second + l_subtree_total.second;

		if ((total_node_value / total_node_count) == cur_node_val) {
			result += 1;
		}

		return {total_node_count, total_node_value};
	}

    int averageOfSubtree(TreeNode* root) {
		int result = 0;
		subtree_total(result, root);
        return result;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
	ios_base::sync_with_stdio(false);
	try {
		TreeNode* root = LeetCodeIO::deserialize<TreeNode*>(cin);

		Solution obj;
		auto res = obj.averageOfSubtree(root);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
