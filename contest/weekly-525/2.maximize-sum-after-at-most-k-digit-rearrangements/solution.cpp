// Created by oportunitas at 2026/10/25 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/maximize-sum-after-at-most-k-digit-rearrangements/
// https://leetcode.com/contest/weekly-contest-525/problems/maximize-sum-after-at-most-k-digit-rearrangements/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        multimap<int64_t, pair<int64_t, int64_t>> to_sort;
        for (auto& num : nums) {
            int64_t decrease_count {0};
            int64_t digit_count {0};
            int64_t last_digit {0};
            int64_t _num {num};

            while (num > 0) {
                int64_t cur_digit {num % 10};
                if (cur_digit < last_digit) {
                    decrease_count += 1;
                }

                last_digit = cur_digit;
                num /= 10; digit_count += 1;
            }

            if (decrease_count == 0) {
                to_sort.insert({0, {_num, _num}});
            } else {
                string num_s {format("{}", _num)}; ranges::sort(num_s, greater{});
                int64_t sorted_num {0};
                auto [ptr, ec] = from_chars(num_s.data(), num_s.data() + num_s.size(), sorted_num);
                to_sort.insert({abs(sorted_num - _num), {sorted_num, _num}});
            }
        }

        int64_t total {0};
        for (const auto& [key, val] : to_sort | views::reverse) {
            if (k > 0) {
                total += val.first; // pick sorted
                k -= 1;
            } else {
                total += val.second;
            }
        }

        // println("{}", to_sort);
        // println("{}", total);
        return total;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.maximizeSum(nums, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
