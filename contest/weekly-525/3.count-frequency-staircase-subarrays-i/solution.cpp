// Created by oportunitas at 2026/10/25 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/count-frequency-staircase-subarrays-i/
// https://leetcode.com/contest/weekly-contest-525/problems/count-frequency-staircase-subarrays-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
private:
    struct option {
        unordered_set<int> appeared;
        int last_num;
        int last_count;
        int cur_count;
    }; unordered_map<int, option> options;
    void _print(unordered_map<int, option>& options) {
        println("----");
        for (const auto& [key, opt] : options) {
            auto& [appeared, last_num, last_count, cur_count] = opt;
            println("[{}, {}, {}, {}]", appeared, last_num, last_count, cur_count);
        }
        
        return;
    }

public:
    int countStaircase(vector<int>& nums) {
        // unordered_multiset<unordered_set<int>, pair<int, int>> nodes;
        unordered_map<int, option> options;
        nums.push_back(-1);

        int count {0};
        for (const auto& [i, num] : nums | views::enumerate) {
            vector<int> to_delete {};
            _print(options);
            for (auto& [key, opt] : options) {
                auto& [appeared, last_num, last_count, cur_count] = opt;
                if (last_count + 1 == cur_count) {
                    println("add");
                    count += 1;
                }

                if (!appeared.contains(num)) {
                    if (last_count == cur_count - 1) {
                        appeared.insert(num);
                        last_count = cur_count;
                        last_num = num;
                        cur_count = 1;
                    } else {
                        to_delete.push_back(key); //invalid
                    }
                } else {
                    if (last_num != num) {
                        to_delete.push_back(key);
                    } else {
                        if (cur_count > last_count) {
                            to_delete.push_back(key);
                        } else {
                            cur_count += 1;
                        }
                    }
                }
            }

            for (const auto& key : to_delete) {
                options.erase(key);
            } options[i] = {{num}, num, 0, 1};
        } _print(options);

        println("count: {}", count);

        return -1;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.countStaircase(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
