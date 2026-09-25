// Created by oportunitas at 2026/09/25 13:29
// leetgo: 1.4.18
// https://leetcode.com/problems/deepest-leaves-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
/* idea #0 (0ms/100th% | 60.4MB/92th%)
    we can use recursion here, and add the sum of leaves in every level, while keeping count
    of the deepest level explored so far
*/
private:
    void add_to_sum(
        TreeNode* cur_node, int64_t cur_level, int64_t& max_level, int64_t& sum
    ) {
        if (cur_node == nullptr) return;
        if (cur_node->left == nullptr && cur_node->right == nullptr) {
            if (cur_level > max_level) {
                sum = 0;
                max_level = cur_level;
            } if (cur_level == max_level) {
                sum += cur_node->val;
            }
        }

        add_to_sum(cur_node->right, cur_level + 1, max_level, sum);
        add_to_sum(cur_node->left, cur_level + 1, max_level, sum);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int64_t max_level {0};
        int64_t sum {0};
        add_to_sum(root, 0, max_level, sum);
        return sum;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		TreeNode* root = LeetCodeIO::deserialize<TreeNode*>(cin);

		Solution obj;
		auto res = obj.deepestLeavesSum(root);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
