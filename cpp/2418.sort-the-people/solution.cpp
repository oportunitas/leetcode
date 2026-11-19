// Created by oportunitas at 2026/11/19 15:08
// leetgo: 1.4.18
// https://leetcode.com/problems/sort-the-people/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (8ms/83th% | 25.4MB/78th%)
        we can combine the fields to a vector of pair, then sort them,
        then extract the names
    */
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> combined; combined.reserve(names.size());
        for (const auto& [name, height] : views::zip(names, heights)) {
            combined.push_back({height, name});
        } ranges::sort(combined, greater{});

        vector<string> result; result.reserve(names.size());
        for (const auto& [height, name] : combined) {
            result.push_back(name);
        }
        return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<string> names = LeetCodeIO::deserialize<vector<string>>(cin);
		vector<int> heights = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.sortPeople(names, heights);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
