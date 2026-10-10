// Created by oportunitas at 2026/10/10 07:31
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-sum-of-squared-difference/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
private:
    void _print_diff_count(array<int, 100002>& diff_count) {
        print("[");
        for (int64_t i {100001}; i >= 0; --i) {
            if (diff_count[i] > 0) print("[{}: {}]", i, diff_count[i]);
        } print("]\n");
    }
public:
    /* idea #1 (0ms/100th% | 119.1MB/94th%)
        i believe idea #0's general direction is already correct, but we only need to optimize.
        i believe that the time cost is mostly spent on reducing the values (cut-trim processes)

        (post-whiteboard analysis)
        something that flew way past my head when doing idea #0 was the fact that we can store
        the number of instances with difference of x. this way the cut and trim process reduces
        from o(n) to o(1), which makes the overall process turn from o(n * m) to o(m)

        lets try

        the logic should be something like this:
            while there's still k and the count array is not all 0:
                tall = largest index
                next = second largest index
                max_cut = tall - next
                cut = min(max_cut, k / number of talls)
                trim = (k - number of talls) < number of talls ? (k - number of talls) : 0

                below is the cases where the towers are both cut and trimmed
                diff_count[max(tall - cut - 1, 0)] += trim

                below is the cases wehre the towers are just cut
                diff_count[max(tall - cut, 0)] += (number of talls - trim)
    */
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        array<int, 100002> diff_count; ranges::fill(diff_count, 0); diff_count[0] += 1;
        for (const auto& [num1, num2] : views::zip(nums1, nums2)) {
            diff_count[abs(num1 - num2)] += 1;
        } 
        // _print_diff_count(diff_count);

        int64_t k {k1 + k2};

        int64_t highest {100001};
        int64_t next_highest {100001};
        while (k > 0) {
            for (int64_t i {highest}; i >= 0; --i) {
                if (diff_count[i] > 0) {
                    highest = i;
                    if (i == 0) break;
                    for (int64_t j {i - 1}; j >= 0; --j) {
                        if (diff_count[j] > 0) {
                            next_highest = j;
                            break;
                        }
                    } break;
                }
            } if (highest <= 0) break;

            // println("highest: {}, second highest: {}", highest, next_highest);
            int64_t nof_highest {diff_count[highest]};
            int64_t max_cut {highest - next_highest};
            int64_t cut {min(max_cut, k / nof_highest)};
            int64_t trim {(k - (cut * nof_highest)) < nof_highest ? (k - (cut * nof_highest)) : 0};
            // println("k: {}, nof_highest: {}, cut: {}, trim: {}", k, nof_highest, cut, trim);

            diff_count[highest] = 0;
            diff_count[max(int64_t{0}, (highest - cut - 1))] += trim;
            diff_count[max(int64_t{0}, (highest - cut))] += (nof_highest - trim);

            // _print_diff_count(diff_count);
            k -= ((cut * nof_highest) + (trim));
        }

        long long sum {0};
        for (int64_t i {highest}; i >= 0; --i) {
            if (diff_count[i] > 0) {
                sum += diff_count[i] * (i * i);
            }
        }

        return sum;

        // long long sum {transform_reduce(
        //     diff_arr.begin(), diff_arr.end(), 0LL, plus<>{},
        //     [] (int64_t x) { return static_cast<long long>(x * x); }
        // )}; return sum;
    }

    // /* idea #0 (time limit exceeded)
    //     lets note the how the values blow up in each (nums1[i] - nums2[i]):
    //         0 : 0
    //         1 : 1 (+1)
    //         2 : 4 (+3)
    //         3 : 9 (+5)
    //         4 : 16 (+7)
    //         5 : 25 (+9)
    //     we observe that the change of values is always increasing (analytical proof:
    //         since the first derivative of x^2 is 2x^1, we know that the increase
    //         of rate is always increasing
    //     )
    //     as such, to reduce the squared difference sum, we need to always reduce from
    //     the biggest numbers first.

    //     we dont need to really care about separating k1 and k2, i think. we can just combine
    //     them to a single k number, that we can use as a quota to reduce from the differences
    //     value of each index in the difference array.

    //     now, im kind of stumped in how one would optimize reducing the values themselves.
    //     if we already have the difference array, lets say looking like this (sorted):
    //         --------
    //         ----
    //         ----
    //         --
    //         -
    //         -
    //         -
    //         -
    //     if k is <= 4, this is trivial, we just reduce the "height" of the first element.
    //     but if k is bigger than 4, my idea as of right now is to do this:

    //         left = index of first element
    //         while still has k remaining:
    //             right = index of last element with same height as first element
    //             next_height = height of the element after right 

    //             max_cut = height of elements left<->right - next_height
    //             cut = remaining k / (right - left)
    //             trim = remaining k - (cut) if cut <= max_cut else 0
                
    //             for element from left to right:
    //                 height -= cut
    //                 if trim > 0 height -= 1
    //     but this loop might be very expensive in time. lets try it anyway for now.
    // */
    // long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
    //     auto diff_arr {[&nums1] () {vector<int64_t> _; _.reserve(nums1.size() + 1); return _;} ()};
    //     for (const auto& [num1, num2] : views::zip(nums1, nums2)) {
    //         diff_arr.push_back(abs(num1 - num2));
    //     } ranges::sort(diff_arr, ranges::greater()); diff_arr.push_back(0);
    //     // println("{}", diff_arr);

    //     int64_t k {k1 + k2};
    //     while (k > 0) {
    //         // find right, in this case, right is the first element that's below height[0]
    //         int64_t right {0};
    //         while (right < diff_arr.size() && diff_arr[right] == diff_arr[0]) {
    //             right += 1;
    //         } if (right == diff_arr.size()) break;

    //         int64_t max_cut {diff_arr[0] - diff_arr[right]};
    //         int64_t cut {min((k / right), max_cut)};
    //         int64_t trim {(k - (cut * right)) < right ? (k - (cut * right)) : 0};
    //         // println("k: {}, right: {}, cut: {}, trim: {}", k, right, cut, trim);

    //         k -= ((cut * right) + (trim));

    //         for (int64_t i {0}; i < right; ++i) {
    //             diff_arr[i] -= cut;
    //             if (trim > 0 && diff_arr[i] > 0) {
    //                 diff_arr[i] -= 1;
    //                 trim--;
    //             }
    //         }
    //         // println("{}", diff_arr);
    //     }

    //     long long sum {transform_reduce(
    //         diff_arr.begin(), diff_arr.end(), 0LL, plus<>{},
    //         [] (int64_t x) { return static_cast<long long>(x * x); }
    //     )};

    //     return sum;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums1 = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> nums2 = LeetCodeIO::deserialize<vector<int>>(cin);
		int k1 = LeetCodeIO::deserialize<int>(cin);
		int k2 = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.minSumSquareDiff(nums1, nums2, k1, k2);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
