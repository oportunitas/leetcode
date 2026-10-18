// Created by oportunitas at 2026/10/18 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/find-root-of-a-colored-tree/
// https://leetcode.com/contest/weekly-contest-524/problems/find-root-of-a-colored-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /*
        pick any node, and traverse up by using the reverse of the pattern
        (R->W->B->R)

        when we've reached a node that cant be traversed further, we traverse down
        and if we can satisfy the "each level has same color" rule, that node is root,
        else none is root.
    */
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        unordered_map<int, unordered_map<int, int>> edge;
        for (const auto& node : edges) {
            int node1 = node[0]; int node2 = node[1];
            edge[node1][node2] += 1;
            edge[node2][node1] += 1;
        }

        // we pick any node essentially.
        auto cur_node = edge.begin()->first;

        while (true) {
            // println("at {}", cur_node);

            char cur_color = colors[cur_node];
            char next_color = cur_color == 'B' ? 'R' : cur_color == 'R' ? 'W' : 'B';

            auto next_node = cur_node;
            for (const auto& candidate : edge[cur_node]) {
                // println("checking {}", candidate.first);
                if (colors[candidate.first] == next_color) {
                    next_node = candidate.first;
                }
            }

            // println("next node: {}", next_node);

            // cannot traverse further
            if (next_node == cur_node) {
                break;
            } cur_node = next_node;
        } 
        // println("end traverse up, might be at root");
        // return -1;

        // we should be in the root node by now if there's any. now we can traverse down 
        // and check the children colors.
        unordered_set<int> visited;
        vector<int> level_members {{cur_node}};
        while (level_members.size() > 0) {
            // println("level members: {}", level_members);

            vector<int> next_level_members;
            char cur_color = colors[level_members[0]];
            char next_color = cur_color == 'B' ? 'W' : cur_color == 'W' ? 'R' : 'B';

            for (const auto& member : level_members) {
                int count {0};
                for (const auto& neighbor : edge[member]) {
                    // if this node hasnt been visited yet (below the current node)
                    if (!visited.count(neighbor.first)) {
                        count += 1;
                        // disobeys rule, immediately return
                        if (colors[neighbor.first] != next_color) {
                            // println("found violation in order, no root is the final answer");
                            return -1;
                        } else {
                            next_level_members.push_back(neighbor.first);
                        }
                    }
                }
                if (count > 2) {
                    // println("found violation in binary property, no root is the final answer");
                    return -1;
                }
                visited.insert(member);
            }

            level_members = next_level_members;
        }

        // println("traversed all levels successfully, the root node is correct");
        // return -2;
        return cur_node;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> edges = LeetCodeIO::deserialize<vector<vector<int>>>(cin);
		string colors = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.findColoredRoot(edges, colors);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
