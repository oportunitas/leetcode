// Created by oportunitas at 2026/09/30 08:50
// leetgo: 1.4.18
// https://leetcode.com/problems/encode-and-decode-tinyurl/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {

/* idea #1 (0ms/100th% | 9.8MB/98th%)
    lets now optimize for speed. lets not use base62 conversion, and use base 36 instead
    so we can use std::from_chars.
*/
private:
    unordered_map<int64_t, string> table;
    int64_t counter;

public:
    Solution() {
        counter = 0;
    }

    // Encodes a URL to a shortened URL.
    string encode(string_view long_url) {
        table.insert({counter, long_url.data()});
        string short_url;
        auto [ptr, ec] = to_chars(
            short_url.data(), short_url.data() + short_url.size(), counter, 36
        );
        counter += 1;
        return short_url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string_view short_url) {
        int64_t key {0};
        auto [ptr, ec] = from_chars(
            short_url.data(), short_url.data() + short_url.size(), key, 36
        );
        return table[key];
    }

// /* idea #0 (8ms/19th% | 10.2MB/82th%)
//     there's generally 2 schools of thought in solving this problem:
//         1. we can create a table that can map every short url to a long one,
//            this allows us to create very short urls but we're reliant on the table

//            worst case is we need many locations to store the table to prevent
//            it being missing (which results in the infamous cloud data centers)

//         2. we can create a compression algorithm for the urls themselves
//            (using shannon's entropy). this algorithm will not rely on any table
//            but the algorithm itself may get very heavy and or the urls might
//            not be that short

//            worst case is that in finding a way to store information about urls,
//            we end up creating an algo that can predict information about general 
//            language, which can be very heavy, and we would need a location that can 
//            do the massive calculation that the algorithm needs (which results
//            in the infamous AI data centers)

//     lets approach this problem with the first approach.
//     we shall create an unordered map that has the short url as the key
//     and the long url as the value. 

//     a very safe approach is to create something akin to UUIDs to represent the 
//     tiny urls. however, for the sake of finding out how encoding and decoding
//     works in the first place first, lets use a counter instead.

//     to make the urls even shorter, instead of using decimal numbers, we can use
//     base 62 instead. even though the map stores numbers using int 64, the urls
//     we give to users are in base 62 so it looks shorter.
// */
// private:
//     unordered_map<int64_t, string> table;
//     int64_t counter;
//     string mapping;

//     string base10_to_base62(int64_t base10) {
//         auto base62 {[] () {string _; _.reserve(1 << 6); return _;} ()};

//         while (base10 > 0) {
//             base62.push_back(mapping[base10 % 62]);
//             base10 /= 62;
//         }

//         ranges::reverse(base62);
//         return base62;
//     }

//     int64_t base62_to_base10(string base62) {
//         int64_t result {0};
//         for (const auto& c : base62) {
//             int64_t c_num;
//             if (c >= '0' && c <= '9') {
//                 c_num = (c - '0') + 52;
//             } else if (c >= 'A' && c <= 'Z') {
//                 c_num = (c - 'A') + 26;
//             } else {
//                 c_num = c - 'a';
//             }
//             result *= 62;
//             result += c_num;
//         }
//         return result;
//     }

// public:
//     Solution() {
//         mapping = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
//         counter = 0;
//     }

//     // Encodes a URL to a shortened URL.
//     string encode(string longUrl) {
//         table.insert({counter, longUrl});
//         string short_url {base10_to_base62(counter)};
//         counter += 1;
//         return short_url;
//     }

//     // Decodes a shortened URL to its original URL.
//     string decode(string shortUrl) {
//         return table[base62_to_base10(shortUrl)];
//     }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
	ios_base::sync_with_stdio(false);
	try {
		string url = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.CodecDriver(url);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
