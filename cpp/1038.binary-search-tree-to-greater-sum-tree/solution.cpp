// Created by oportunitas at 2026/09/20 12:38
// leetgo: 1.4.18
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
private:
	/* idea #0 (0ms/100th% | 11.32MB/49.04th%)
		if we create an array from the tree (lets use example 1):
			 0,  1,  2,  3,  4,  5,  6,  7,  8
		then we can just traverse backwards and add:
			36, 36, 35, 33, 30, 26, 21, 15,  8
	*/
	int cache = 0;
	void recurse(TreeNode* cur_node) {
		if (cur_node == nullptr) {
			return;
		} else {
			recurse(cur_node->right);
			cache += cur_node->val;
			cur_node->val = cache;
			recurse(cur_node->left);
		}
	}

public:
    TreeNode* bstToGst(TreeNode* root) {
		recurse(root);
		return root;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		TreeNode* root = LeetCodeIO::deserialize<TreeNode*>(cin);

		Solution obj;
		auto res = obj.bstToGst(root);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
