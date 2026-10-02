// Created by oportunitas at 2026/10/02 06:38
// leetgo: 1.4.18
// https://leetcode.com/problems/balance-a-binary-search-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
/* idea #0 (0ms/100th% | 47.4MB/99th%)
    lets represent the example 1 array with serialized seg tree:
        1, -, 2, -, -, -, 3, -, -, -, -, -, -, -, 4
    turns into:
        2, 1, 3, -, -, -, 4
    or:
        3, 1, 4, -, 2, -, -
    or:
        3, 2, 4, 1, -, -, -
    
    a general rule is that given n nodes, the max level should be ceil(log(2)(n + 1))

    the solution tree should have the median value as root. then the left and right childs
    are the median of each part (left or right to the ordering).

    perhaps we can first traverse the tree inorder, which can help us find a sorted
    representation of the tree nodes. then, we can move the nodes by
*/
private:
    void get_sorted_nodes(vector<TreeNode*>& nodes, TreeNode* cur_node, int64_t& node_count) {
        if (cur_node->left != nullptr) {
            get_sorted_nodes(nodes, cur_node->left, node_count);
        } 
        nodes.push_back(cur_node);
        node_count += 1;
        if (cur_node->right != nullptr) {
            get_sorted_nodes(nodes, cur_node->right, node_count);
        } 
        return;
    }

    void rearrange(
        vector<TreeNode*>& nodes, TreeNode* cur_node,
        int64_t begin, int64_t middle, int64_t end, 
        bitset<10001>& is_placed, int64_t level
    ) {
        // println("[{}][{}, {}, {}], placed {}", level, begin, middle, end, cur_node->val);

        int64_t left = ((middle - begin) / 2) + begin;
        if (!is_placed[left] && left >= 0 && left <= middle) {
            cur_node->left = nodes[left];
            is_placed.set(left);

            rearrange(
                nodes, cur_node->left, 
                begin, left, middle - 1,
                is_placed, level + 1
            );
        } else {
            cur_node->left = NULL;
        }
        
        int64_t right = ((end - middle) / 2) + (middle + 1);
        if (!is_placed[right] && right >= middle && right <= end) {
            cur_node->right = nodes[right];
            is_placed.set(right);

            rearrange(
                nodes, cur_node->right, 
                middle + 1, right, end,
                is_placed, level + 1
            );
        } else {
            cur_node->right = NULL;
        }
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        auto nodes {[] () {vector<TreeNode*> _; _.reserve(10001); return _;} ()};
        int64_t node_count {0};
        get_sorted_nodes(nodes, root, node_count);
        // println("nodes: {}", (nodes | views::transform([](TreeNode* n){return n->val;})));
        // println("node count: {}", node_count);
        bitset<10001> is_placed {0};
        is_placed.set(node_count / 2);
        TreeNode* res_root = nodes[node_count / 2];
        rearrange(
            nodes, res_root,
            0, (node_count / 2), node_count - 1,
            is_placed, 0
        );
        // for (int i {0}; i < node_count; ++i) {
        //     println("val: {}", nodes[i]->val);
        //     if (nodes[i]->right != nullptr) {
        //         println("   right: {}", nodes[i]->right->val);
        //     } else {
        //         println("   right: null");
        //     }

        //     if (nodes[i]->left != nullptr) {
        //         println("   left: {}", nodes[i]->left->val);
        //     } else {
        //         println("   left: null");
        //     }
        // }
        return res_root;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		TreeNode* root = LeetCodeIO::deserialize<TreeNode*>(cin);

		Solution obj;
		auto res = obj.balanceBST(root);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
