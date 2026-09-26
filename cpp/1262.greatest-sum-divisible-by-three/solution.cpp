// Created by oportunitas at 2026/09/26 17:39
// leetgo: 1.4.18
// https://leetcode.com/problems/greatest-sum-divisible-by-three/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #1 (0ms/100th% | 28.8MB/ 100th%)
            post-submission remark: this solution's time jitters heavily between submissions,
            and i believe that idea #0 is ultimately better, but this is an interesting
            intelectual exercise regardless.

        idea #0 is great! now, i want to explore a more dynamic programming approach,
        idea #0 is more analytical/statistical, lets look at the problem more as tackling
        an "iterating through an array" problem.

        to remember: a dynamic programming solution usually means that even if we stop someway through the array, the solution would be valid for just the array we're reading up to.

        say if we're in the ultimate position, and we're reading the last number. this number
        will either make the sum % 3 be 0 (could be any case, 0 + 0, 1 + 2, 2 + 1). however,
        the sum we're going to be having at this point should already be something that
        if added with this number will have % 3 equal to 0.

        if we're looking back from after the operation ends, its as if we've keep trace of
        any occurences of remainder 1, remainder 2, and remainder 3, and have perfectly sealed
        the holes that occured by having remainder 1 or 2 sums along the way

        at any point in the array, we can add a number and keep track of its % 3 result via
        an array. 

        now, lets see this from the beginning position and onwards:
        
        we start with sum of 0, and whatever our first number will be will either have
        the modulo 3 of either 0, 1, or 2. we can store this in an array, based on the result of
        (sum + num) % 3. if the program ends at the first number, we just report the value of
        sum[0], which contains the sum of all the things that add up to have remainder 3 of 0.
        if the first number is a multiplication of 3, sum[0] will be bigger than 0. elsewise
        its gonna be 0 since the number will populate sum[1] or sum[2] instead.

        then, we are in the second number. we've just gone through the first number, whatever it is,
        and the sum is stored in the sum[] array. this number will do either one of 3 things to the
        sum: if number % 3 == 0, it'll just add every sum element by itself. if number % 3 == 1,
        then it will round shift the sums by 1 (since the sum that's previously mod 3 == 0 now has
        mod 3 == 1 because of this number, and so on). if numberr % 3 == 2, it'll round shift the
        numbers by 2. notice that this operation is essentially the exact same as what we did
        in step 0, just with different initial values of the sum[] array. and by this point,
        sum[0] still is going to be storing the sum of numbers that have remainder 3 of 0.

        we can do this same exact step all the way through.

        [0, 0, 0]

        get 3, [3, 0, 0]
        [3, 0, 0]

        get 6, [9, 0, 0]
        [9, 0, 0]

        get 5, 
        [ 9, 0, 0]
        [14, 0, 0]

        [9, 0, 14]

        get 1, [10, 1, 15]
        [15, 10, 14]

        get 8, [23, 18, 22]
        [18, 22, 23]
    */
    int maxSumDivThree(vector<int>& nums) {
        array<int, 3> totals {0};
        array<int, 3> temp_totals {0};
        for (const auto& num : nums) {
            temp_totals = totals;
            for (const auto& temp_total : temp_totals) {
                int tobe_total {temp_total + num};
                int tobe_index {tobe_total % 3};
                totals[tobe_index] = max(totals[tobe_index], tobe_total);
            }
        } return totals[0];
    }

    // /* idea #0 (0ms/100th% | 28.9MB/88th%)
    //     divisible by three means the sum of the array % 2 is 0.
    //     if we have the array as-is, there's 3 possiblities:
    //         - the sum % 3 already 0, in this case we dont do anything to the array.
    //         - the sum % 3 is either 1 or 2.
    //             in this case, we need to subtract some number/s from the array.
    //             lets consider possibilities:
    //             - sum % 3 == 1, there's the below possibilities for this happening:
    //                 - sum is the addition of a[] and b, where sum(a) % 3 == 0,
    //                 but b % 3 == 1.
    //                 - sum is the addition of a[], b, and c, where sum(a) % 3 == 0,
    //                 but b % 3 and c % 3 == 2
    //                 - sum can also be the addition of a[], b, c, and d, where 
    //                 (b + c + d) % 3 == 1. however, notice that for this case to be
    //                 satisfied, and since each modulo of b, c, d is equal to either 2
    //                 or 1, the sum of all modulos should be 4. the only combination
    //                 that will allow this is a version of [1, 1, 2] (according to
    //                 arrangement). notice that the addition of the 2 numbers in that
    //                 combination (the 2 leftover one and the 1 leftover one) would
    //                 just result in 3. this case is the same as the first condition.
    //             - sum % 3 == 2, the possibilities are almost the same with the 1
    //             remainder case, but in this case its either b % 3 == 2, or b % 3 == 1
    //             & c % 3 == 1

    //             a crucial observation that we can infer is, that, to get an array
    //             with sum that is divisible by 3, we can just find 2 numbers with
    //             modulo 3 of 1, and 2 numbers with modulo 3 of 2. and then, according
    //             to which case we encounter (sum % 3 == ?), we can use 3 of the 4
    //             numbers we get.

    //             naturally, instead of finding any number, since we're to find the
    //             biggest possible sum, we find the smallest numbers (2 smallest 
    //             numbers with % 3 of 1, and then 2 smallest numbers with % 3 of 2). we
    //             then can find the smallest value of either option combo.
    // */
    // int maxSumDivThree(vector<int>& nums) {
    //     array<int, 2> min_remain_1 {10001, 10001};
    //     array<int, 2> min_remain_2 {10001, 10001};

    //     int64_t total {0};
    //     for (const auto& num : nums) {
    //         // println("num: {}, total: {}", num, total);
    //         total += num;
    //         if ((num % 3 == 1) && (num <= ranges::max(min_remain_1))) {
    //             if (num <= min_remain_1[0]) {
    //                 min_remain_1[1] = min_remain_1[0];
    //                 min_remain_1[0] = num;
    //             } else min_remain_1[1] = num;
    //         } else if ((num % 3 == 2) && (num <= ranges::max(min_remain_2))) {
    //             if (num <= min_remain_2[0]) {
    //                 min_remain_2[1] = min_remain_2[0];
    //                 min_remain_2[0] = num;
    //             } else min_remain_2[1] = num;
    //         }
    //     }

    //     // println("min_remain_1: {}", min_remain_1);
    //     // println("min_remain_2: {}", min_remain_2);
    //     // println("final sum: {}", total);

    //     if (total % 3 == 1) {
    //         total -= min((min_remain_1[0]), (min_remain_2[0] + min_remain_2[1]));
    //     } else if (total % 3 == 2) {
    //         // print("min: {}", min((min_remain_2[0]), (min_remain_1[0] + min_remain_1[1])));
    //         total -= min((min_remain_2[0]), (min_remain_1[0] + min_remain_1[1]));
    //     } return total;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.maxSumDivThree(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
