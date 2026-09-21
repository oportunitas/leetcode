// Created by oportunitas at 2026/09/21 12:39
// leetgo: 1.4.18
// https://leetcode.com/problems/find-x-value-of-array-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #4 (4ms/99th% | 106.2MB/96th%)
        lets agressively cut down any slight inefficencies now.

        old_from_prev and new_from_prev are always at most of size 5, so we can declare them 
        as std::array instead
    */
    static vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> result(k, 0);
        if (k == 1) return {((long long)(n)) * (n + 1) / 2};

        array<int, 5> old_from_prev {{0}};
        array<int, 5> new_from_prev;

        for (const int num : nums) {
            new_from_prev.fill(0);

            const int _num = num % k;
            new_from_prev[_num] += 1;
            result[_num] += 1;

            for (int i {0}; i < k; ++i) {
                int new_i = (i * _num) % k;
                new_from_prev[new_i] += old_from_prev[i];
                result[new_i] += old_from_prev[i];
            } 

            old_from_prev = new_from_prev;
        }
        return result;
    }

    // /* idea #3 (11ms/99th% | 106.2MB/96th%)
    //     idea #2 is very fast, about 12-20 ms, but lets make the implementation even faster.

    //     til: modulo arithmetic is one of the more expensive operations, inclusing multiple
    //     cpu cycles, i thought this takes only 1 cycle vro. 

    //     lets cache modulo arithmetic results to variables.

    //     and just as a side trick, if k is 1, then every number we encounter adds
    //     to new_from_prev by 1. since we're adding new_from_prev, every time, this problem becomes:
    //         1 + 2 + 3 + 4 + 5 + 6 + 7 + ... + n - 1 + n
    //     the solution of which is the formula for the arithmetic progression
    //         (n * (n + 1)) / 2
    // */
    // vector<long long> resultArray(vector<int>& nums, int k) {
    //     // println("---");
    //     int n = nums.size();

    //     vector<long long> result(k, 0);
    //     if (k == 1) {
    //         result[0] = (long long)(int64_t{1} * n * (n + 1) / 2);
    //         return result;
    //     }

    //     vector<int> old_from_prev (5, 0);
    //     vector<int> new_from_prev (5, 0);

    //     for (auto&& num : nums) {
    //         fill(new_from_prev.begin(), new_from_prev.end(), 0);

    //         const int _num = num % k;
    //         new_from_prev[_num] += 1;
    //         result[_num] += 1;

    //         for (int i {0}; i < k; ++i) {
    //             int new_i = (i * _num) % k;
    //             new_from_prev[new_i] += old_from_prev[i];
    //             result[new_i] += old_from_prev[i];
    //         } 

    //         swap(old_from_prev, new_from_prev);
    //     }
    //     return result;
    // }

    // /* idea #2 (12ms/98th% | 106.1MB/96th%)
    //     idea #1 works within the time limit! however, its not efficient enough, most probably
    //     due to excessive heap allocations (declaring new_from_prev inside the loop, for example)

    //     lets lean down memory, cut data type sizes wherever possible and preallocate everything
    //     before the loop.

    //     for the new_from_prev vector, instead of redeclaring every time, we can use std::fill
    //     instead (memcpy also works, but lets use cpp when if use cpp)

    //     also, the from_prev vectors dont need to be in long long, int is enough since nums.length
    //     is 100000.

    //     instead of using old_from_prev = new_from_prev;, we can just swap, which removes data
    //     copying. this made new_from_prev the value of old_from_prev, but we're clearing it up
    //     anyway in next iteration.
    // */
    // vector<long long> resultArray(vector<int>& nums, int k) {
    //     // println("---");
    //     vector<long long> result(k, 0);
    //     vector<int> old_from_prev (k, 0);
    //     vector<int> new_from_prev (k, 0);

    //     for (auto&& num : nums) {
    //         fill(new_from_prev.begin(), new_from_prev.end(), 0);

    //         new_from_prev[num % k] += 1;
    //         result[num % k] += 1;

    //         for (int i {0}; i < k; ++i) {
    //             int new_i = (i * (num % k)) % k;
    //             new_from_prev[new_i] += old_from_prev[i];
    //             result[new_i] += old_from_prev[i];
    //         } 

    //         swap(old_from_prev, new_from_prev);
    //     }
    //     return result;
    // }

    // /* idea #1 (152ms/72%th | 151.1MB/55th%)
    //     we've hit time limit with idea #0, the most probable culprit is the inner j loop.
    //     if we were reading the vector in retrograde, perhaps we can do some dp?:
    //         _<-
    //         __<-
    //         ___<-
    //         ____<-
    //         (this way of reading the array lets use memorize or reuse stuff)
        
    //     in this context, the result array stores the number of %k counts so far.
        
    //     lets observe for the case [1, 2, 3, 4, 5], 3
        
    //     begin:
    //         result so far: [0, 0, 0]
    //         new          : [0, 0, 0]
    //         from_prev    : [0, 0, 0]
    //         new result   : [0, 0, 0]
    //     receive 1 % 3 = 1 (0->0, 1->1, 2->2):
    //         result so far: [0, 0, 0]
    //         new          : [0, 1, 0]
    //         from_prev    : [0, 1, 0]
    //         new result   : [0, 1, 0]
    //     receive 2 % 3 = 2 (0->0, 1->2, 2->1):
    //         result so far: [0, 1, 0]
    //         new          : [0, 0, 1]
    //         from_prev    : [0, 0, 2]
    //         new result   : [0, 1, 2]
    //     receive 3 % 3 = 0 (0->0, 1->0, 2->0):
    //         result so far: [0, 1, 2]
    //         new          : [1, 0, 0]
    //         from_prev    : [3, 0, 0]
    //         new result   : [3, 1, 2]
    //     receive 4 % 3 = 1 (0->0, 1->1, 2->2):
    //         result so far: [3, 1, 2]
    //         new          : [0, 1, 0]
    //         from_prev    : [3, 1, 0]
    //         new result   : [6, 2, 2]
    //     receive 5 % 3 = 2 (0->0, 1->2, 2->1):
    //         result so far: [6, 2, 2]
    //         new          : [0, 0, 1]
    //         from_prev    : [3, 0, 2]
    //         new result   : [9, 2, 4]

    //     we have found a pattern here: the from_prev on an iteration is the same as
    //     the from_prev from the previous iteration, undergone the modulo transform, and added
    //     with the new number.
    // */
    // vector<long long> resultArray(vector<int>& nums, int k) {
    //     // println("---");
    //     vector<long long> result(k, 0);

    //     vector<long long> old_from_prev (k, 0);
    //     for (auto&& num : nums) {
    //         vector<long long> new_from_prev (k, 0);
    //         new_from_prev[num % k] += 1;

    //         // for (int i {0}; i < k; ++i) {
    //         // 	print("[{}]", old_from_prev[i]);
    //         // } print("\n");

    //         for (int i {0}; i < k; ++i) {
    //             new_from_prev[(i * (num % k)) % k] += old_from_prev[i];
    //         } 
    //         // print("\n--\n");

    //         for (int i {0}; i < k; ++i) {
    //             // print("[{}]", new_from_prev[i]);
    //             result[i] += new_from_prev[i];
    //         } 
    //         // print("\n");

    //         old_from_prev = new_from_prev;
    //     }
    //     return result;
    // }

    // /* idea #0 (time limit exceeded)
    // 	k's value is only between 1 and 5. lets break down by x value:
    // 		0: if at any point in the array, there's a factor of k
    // */
    // vector<long long> resultArray(vector<int>& nums, int k) {
    // 	vector<long long> result(k, 0);
    //     for (int64_t i {0}; i < nums.size(); ++i) {
    // 		int64_t prod_so_far {1};
    // 		for (int64_t j {i}; j < nums.size(); ++j) {
    // 			/* 
    // 				to prevent integer overflow, we use the following trick:
    // 				we only ever care about the modulo result, so we always do mod k
    // 				on prod_so_far.
    // 			*/
    // 			prod_so_far = (prod_so_far * nums[j]) % k;

    // 			/*
    // 				aditionally, we know that, if we're halfway through this subarray
    // 				(j has not reached the end yet) but we've 
    // 			*/
    // 			result[prod_so_far] += 1;
    // 		}
    // 	}
    // 	return result;
    // }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    try {
        vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
        int k = LeetCodeIO::deserialize<int>(cin);

        Solution obj;
        auto res = obj.resultArray(nums, k);

        stringstream out_stream;
        LeetCodeIO::print(out_stream, res);
        cout << "\noutput: " << out_stream.rdbuf() << '\n';
    } catch (const LeetCodeIO::Error &error) {
        cerr << "LC_IO: " << error.what() << '\n';
        return 2;
    }
    return 0;
}
