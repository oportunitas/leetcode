// Created by oportunitas at 2026/10/19 14:08
// leetgo: 1.4.18
// https://leetcode.com/problems/count-items-matching-a-rule/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 36.4MB/20th%)
        lets use ranges::count_if()
    */
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string, int> val_i;
        val_i["type"] = 0; val_i["color"] = 1; val_i["name"] = 2;
        return ranges::count_if(items, [&ruleKey, &ruleValue, &val_i] (const auto& item) {
            return item[val_i[ruleKey]] == ruleValue;
        });
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<string>> items = LeetCodeIO::deserialize<vector<vector<string>>>(cin);
		string ruleKey = LeetCodeIO::deserialize<string>(cin);
		string ruleValue = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.countMatches(items, ruleKey, ruleValue);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
