/*
    this library contains all the private functions for leetcode solutions that
    i've deemed to be necessary/near-stl level for leetcode. the functions should close
    the gaps in stl that c++23 currently does not apply directly. 

    although, the general rule for this is to never copy paste the functions directly,
    but retype them, to aid comprehension and to also hopefully one day have the concept
    solid enough to completely type them directly without looking at this file
*/

#include <bits/stdc++.h>
using i64 = std::int64_t;
class Library {
private:
    i64 _ipow(i64 b, i64 e, i64 m = 1e9+7) {
        i64 n {1}; for (b % m; e > 0; e >>= 1, b = b * b % m) {
            if (e & 1) n = n * b % m;
        } return n;
    }
}