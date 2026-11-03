// Created by oportunitas at 2026/11/03 13:33
// leetgo: 1.4.18
// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const int fast_io = [] { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
using i64 = std::int64_t;
using uz = std::size_t;

class Solution {
public:
    /* idea #1 (2ms/99th% | 68.7MB/6th%)
        to optimize time, we can instead count the number of each number.
    */
    int maxCoins(vector<int>& piles) {
        const i64 vmax {10001}; 
        vector<i64> count (vmax, 0); uz max_pile {0};

        for (const auto& pile : piles) {
            count[pile] += 1;
            max_pile = max(max_pile, (uz)pile);
        }
        
        i64 ans {0}; i64 visited {0};
        i64 max_visits {(i64)(piles.size() * 2 / 3)}; 
        for (uz i {max_pile}; visited < max_visits; --i) {
            i64 to_visit {min(count[i], max_visits - visited)}; 
            i64 to_add {to_visit / 2};

            if (visited % 2 && to_visit % 2) to_add += 1; 

            ans += to_add * (i);
            visited += to_visit;
        } return ans;
    }

    // /* idea #0 (27ms/72th% | 57.1MB/93th%)
    //     we sort the array first. then, we take every other element on the second thirds
    //     of the array.
    // */
    // int maxCoins(vector<int>& piles) {
    //     ranges::sort(piles); uz a3rd = piles.size() / 3; i64 ans {0};
    //     for (uz i {a3rd}; i < piles.size(); i += 2) {
    //         ans += piles[i];
    //     } return ans;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> piles = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.maxCoins(piles);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
