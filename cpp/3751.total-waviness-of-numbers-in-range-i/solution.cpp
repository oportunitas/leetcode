// Created by oportunitas at 2026/09/23 07:13
// leetgo: 1.4.18
// https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
    /* idea #0 (0ms/100th% | 9.4MB/56th%)
        since this is a counting problem and its values can be precomputed once,
        we can calculate the values at the beginning instead (during class definition).
    */
private:
    static inline constexpr size_t max_testcase {100001};
    
    // it would be even nicer to use constexpr here also, but this process is way bigger than
    // what leetcode's compiler can store.
    // we declare as static inline to make this array a value pertaining to the class itself,
    // not each different instantiation of it. this way we only need to compute once,
    // even if we make multiple instances of Solution()
    // static: to make this data pertain to the class, not class instance
    // inline: to allow us to assign the data without doing it outside the class, hence "inline"
    //         because it's process is at the class definition not instantiation.
    static inline array<int, max_testcase> lookup {[] () {
        array<int, max_testcase> digitwise_wave_count_from_0 {0};
        array<int, max_testcase> numberwise_wave_count_from_0 {0};

        for (int i {100}; i < max_testcase; ++i) {
            // we read right to left
            int prefix = i % 10;
            int body = (i / 10) % 10;
            int suffix = (i / 100) % 10;


            /*
                suppose the number we have is formed as abcdef,
                we've extracted prefix = f, body = e, and suffix = c

                in the below code, we add the digitwise wave count of abcde with 1 if the current
                3-number pair is a wave. how do we know abcde's digitwise value beforehand then
                because the loop is increasing from 100 to max_testcase, we're guaranteed to have
                found the digitwise wave count of abcde by adding digitwise count of abcd with
                1 if wave. how do we get abcd? we're guaranteed to get abc already.

                so this approach effectively turns a top down (from complete number and slice down) 
                recursion problem to a bottom up (from no numbers and append up) iteration problem.
            */
            digitwise_wave_count_from_0[i] = (
                digitwise_wave_count_from_0[i / 10] + // the number of waves 1 digit up
                (bool) (
                    (body < min(prefix, suffix)) | //trench
                    (body > max(prefix, suffix))   //peak
                )
            );
            
            // the number of waves in the sequence of increasing numbers from 0
            // to this number is equal to the digitwise waves of this 
            // current number plus the previous number's total waves in increasing
            // numbers from 0
            numberwise_wave_count_from_0[i] = (
                digitwise_wave_count_from_0[i] +
                numberwise_wave_count_from_0[i - 1]
            );
        }

        return numberwise_wave_count_from_0;
    } ()};

public:
    int totalWaviness(int num1, int num2) {
        return (lookup[num2] - lookup[num1 - 1]);
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    try {
        int num1 = LeetCodeIO::deserialize<int>(cin);
        int num2 = LeetCodeIO::deserialize<int>(cin);

        Solution obj;
        auto res = obj.totalWaviness(num1, num2);

        stringstream out_stream;
        LeetCodeIO::print(out_stream, res);
        cout << "\noutput: " << out_stream.rdbuf() << '\n';
    } catch (const LeetCodeIO::Error &error) {
        cerr << "LC_IO: " << error.what() << '\n';
        return 2;
    }
    return 0;
}
