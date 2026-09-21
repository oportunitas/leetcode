// Created by oportunitas at 2026/09/21 11:17
// leetgo: 1.4.18
// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #1 (0ms/100th% | 17.5MB/37th%)
		lets lean down the program, see if it can make it faster. lets use maps now
		i suspect that the time inefficiency stems from the 2d vector and appending that vector
		along the way. lets now only append to result vector after the group is complete.
	*/
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		auto result {[] () { vector<vector<int>> _; _.reserve(2048); return _;} ()};
		unordered_map<int, vector<int>> group;
		for (auto&& [i, group_size]: groupSizes | views::enumerate) {
			group[group_size].push_back(i);
			if (group[group_size].size() == group_size) {
				result.push_back(group[group_size]);
				group[group_size].clear();
			}
		} return result;
    }

	// /* idea #0 (3ms/70th% | 17.8MB/28th%)
	// 	we can create the array for the groups, then assign people accordingly
	// */
    // vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
	// 	// map for assigning, map<groupsize, result_index>
	// 	vector<int> size_to_i (512, -1);
    //     auto cur_count {[] () { vector<int> _; _.reserve(512); return _;} ()};
	// 	auto max_count {[] () { vector<int> _; _.reserve(512); return _;} ()};
	// 	auto result {[] () { vector<vector<int>> _; _.reserve(512); return _;} ()};

	// 	for (auto&& [i, group_size]: groupSizes | views::enumerate) {
	// 		// if no group exists yet for this group size, make a new one and put the current
	// 		// number there
	// 		if (size_to_i[group_size] == -1 || max_count[size_to_i[group_size]] == 1) {
	// 			result.push_back({(int)i});
	// 			size_to_i[group_size] = result.size() - 1;
	// 			cur_count[size_to_i[group_size]] = 1;
	// 			max_count[size_to_i[group_size]] = group_size;
	// 		} else { // else just put them in the existing one to be filled
	// 			result[size_to_i[group_size]].push_back((int)i);
	// 			cur_count[size_to_i[group_size]] += 1;

	// 			// if the current group is full, tell that there's no group for this group size
	// 			if (cur_count[size_to_i[group_size]] == max_count[size_to_i[group_size]]) {
	// 				size_to_i[group_size] = -1;
	// 			}
	// 		}
	// 	} return result;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> groupSizes = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.groupThePeople(groupSizes);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
