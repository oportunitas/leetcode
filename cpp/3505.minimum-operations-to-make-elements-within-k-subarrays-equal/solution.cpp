// Created by oportunitas at 2026/11/04 11:58
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/* idea #1 (631ms/95th% | 352.9MB/84th%)
    its taking way too long for me to implement the idea i've had, since i believed that 
    i'm lacking some syntactic knowledge. turns out, after looking at solutions, the general
    idea for the solution is already correct (from idea #0)! i've used one of the public solutions
    as a reference to tune idea #0's approach to acceptance. turns out oop really helps to clear
    the air for hard problems.
*/
using i64 = std::int64_t;
class window_t {
public:
    window_t(
        vector<int>::const_iterator first, vector<int>::const_iterator last
    ) : _set (first, last), _is_odd (_set.size() & 1) {
        _median = next(_set.begin(), _set.size() / 2);
        _low    = accumulate(_set.begin(), _median, 0ll);
        _total  = accumulate(_set.begin(), _set.end(), 0ll);
    }

    i64 _get_difsum() const {
        return _total - (2 * _low) - (_is_odd * *_median);
    }

    i64 _slide(i64 outbound, i64 inbound) {
        _set.insert(inbound);
        if (inbound < *_median) {
            _low += (inbound - *--_median);
        }

        if (outbound < *_median) {
            _low += *_median++ - outbound;
            _set.erase(_set.find(outbound));
        } else if (outbound == *_median) {
            _median = _set.erase(_median);
        } else {
            _set.erase(_set.find(outbound));
        }

        _total += (inbound - outbound);
        return _get_difsum();
    }

private:
    multiset<int> _set;
    multiset<int>::iterator _median;
    i64 _low; i64 _total;
    bool _is_odd;
};

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        size_t n {nums.size()};

        // act 1: create difsums array
        window_t window (nums.begin(), nums.begin() + x);
        vector<i64> difsums {window._get_difsum()};
        for (size_t i = x; i < n; ++i) {
            difsums.push_back(window._slide(nums[i-x], nums[i]));
        }

        // act 2: dp
        vector<i64> dp (n + 1, 0);
        for (size_t h {0}; h < k; ++h) {
            vector<i64> layer (n + 1, INT64_MAX / 2);
            for (size_t i = x; i <= n; ++i) {
                layer[i] = min(layer[i-1], dp[i-x] + difsums[i-x]);
            } swap(dp, layer);
        } return dp[n];
    }
};

/* idea #0 (abandoned)
    we can use the median + sliding window, and we can calculate difsum (the total of
    the differences from median to each element in a window). after we've got the 
    difsums, we can do dp to find out the least value of k selections
*/
// class Solution {
// public:
//     long long minOperations(vector<int>& nums, int x, int k) { println("--");
//         // act 1: create array of difsums. this array will contain how many moves we need
//         // for each index to make x previous elements (including it) be equal.
//         vector<int> window (nums.begin(), nums.begin() + x);
//         window.reserve(x + 1); ranges::sort(window);
//         vector<int> medians (nums.size(), 0);
//         vector<int> difsums (nums.size(), 0);
//         for (size_t i {x - 1}; i < nums.size(); ++i) {
//             println("{}", window);

//             int outbound_val {nums[i-x]};
//             auto outbound_it {ranges::lower_bound(window, outbound_val)};
//             window.erase(outbound_it);

//             int inbound_val {nums[i]}; 
//             auto inbound_it {ranges::lower_bound(window, inbound_val)};
//             window.insert(inbound_it, inbound_val);

//             int median {x % 2 == 0 ? midpoint(window[x/2-1], window[x/2]) : window[x/2]};
//             medians[i] = median;

//             int difsum {0};
//             for (size_t j {i - (x - 1)}; j <= i; ++j) {
//                 difsum += abs(median - nums[j]);
//             } difsums[i] = difsum;
//         }
//         println("{}", nums);
//         println("{}", medians);
//         println("{}", difsums);

//         // act 2: dp to find minimum difsums.
//         //      we can iterate through the difsums array,
//         //      at each point, we have 2 options: take or skip.
//         //      if we take:
//         //          we add difsums[i] to the total
//         //          we must jump x indeces forward
//         //      if we skip:
//         //          we keep the total so far
//         //          we jump 1 index forward.
//         vector<i64> prev (nums.size() + 1, 0);
//         vector<i64> curr (nums.size() + 1, 0);
//         for (int h {0}; h < k; ++h) {
//             ranges::fill(curr, INT32_MAX);
//             for (int i {x}; i <= nums.size(); ++i) {
//                 curr[i] = min(curr[i-1], prev[i-x] + difsums[i-x]);
//             } swap(prev, curr);
//         }

//         println("{}", prev);
//         return -1;
//     }
// };

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int x = LeetCodeIO::deserialize<int>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.minOperations(nums, x, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
