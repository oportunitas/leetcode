// Created by oportunitas at 2026/10/09 11:45
// leetgo: 1.4.18
// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/* idea #0 (0ms/100th% | 41.9/86th%)
    we can bring the values of parent and grandparents down while we traverse
*/
class Solution {
public:
    void traverse(TreeNode* cur_node, int parent_val, int grandparent_val, int& sum) {
        if (cur_node == nullptr) return;

        if (grandparent_val % 2 == 0 && grandparent_val >= 0) sum += cur_node->val;
        traverse(cur_node->right, cur_node->val, parent_val, sum);
        traverse(cur_node->left, cur_node->val, parent_val, sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum {0};
        traverse(root, -1, -1, sum);
        return sum;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		TreeNode* root = LeetCodeIO::deserialize<TreeNode*>(cin);

		Solution obj;
		auto res = obj.sumEvenGrandparent(root);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
