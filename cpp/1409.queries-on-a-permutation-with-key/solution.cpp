// Created by oportunitas at 2026/10/23 17:13
// leetgo: 1.4.18
// https://leetcode.com/problems/queries-on-a-permutation-with-key/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/* idea #0 (0ms/100th% | 12.5MB/24th%)
    this is my first foray into fenwick/binary index trees, and i've intentionally made the
    code very OOP to accomodate learning. im sure this can be tigthened in later attempts.

    the main idea behind this solution is that we dont necessarily need to rearrange the array
    itself. we can instead create an array twice the size of the original, and set the
    original values to the right half (other half empty). every query, we copy the requested number 
    to the left of the non-empty part. this hack is possible because we do not necessarily
    need to recreate the whole array every time, but we just need to keep track of the indices
    of each number before theyre moved to the left.

    in the 1st example [1,2,3,4,5], we can create:
        [-,-,-,-,-,1,2,3,4,5] number
        [-,-,-,-,-,0,1,2,3,4] index
    then after queries:
        [-,-,-,-,3,1,2,3,4,5]
        [-,-,-,-,0,1,2,x,3,4]

        [-,-,-,1,3,1,2,3,4,5]
        [-,-,-,0,1,x,2,x,3,4]

        [-,-,2,1,3,1,2,3,4,5]
        [-,-,0,1,2,x,x,x,3,4]

        [-,1,2,1,3,1,2,3,4,5]
        [-,0,1,x,2,x,x,x,3,4]
    
    creating and editing the number list is trivial, but the index list, we can optimize
    by using a fenwick tree (so we reduce from n to log(n) whenever we iterate the indexes)
    in practice, the x locations in the index list is just the same value as the next number 
    (non-decreasing nature). 
*/
class Solution {
private:
    class bidx_tree {
        friend struct formatter<bidx_tree>;
    private:
        size_t _size;
        vector<int64_t> _values;

        int64_t _get_sum(size_t i) const {
            int64_t sum {0}; while (i > 0) {
                sum += _values[i];
                i -= i & -i; // remove least significant bit
            } return sum;
        }

        void _add(size_t i, int64_t val) {
            while (i < _size) {
                _values[i] += val;
                i += i & -i; // add one bit after most significant bit
            } return;
        }
    public:
        bidx_tree(size_t size) {
            size_t actual_size {1};
            while (actual_size <= size) {
                actual_size *= 2; //double the tree (add one bit for index)
            }
            _size   = actual_size;
            _values = vector<int64_t>(_size, 0);
        }

        int64_t operator[](size_t i) const {
            return _get_sum(i);
        }

        class _proxy {
        private:
            bidx_tree& _tree;
            size_t _i;
        public:
            _proxy(bidx_tree& tree, size_t i) : _tree(tree), _i(i) {}
            _proxy& operator+=(int64_t val) {
                _tree._add(_i,val); return *this;
            } 
            _proxy& operator-=(int64_t val) {
                _tree._add(_i,-val); return *this;
            }
            operator int64_t() const {
                return _tree._get_sum(_i);
            }
        }; 
        
        _proxy operator[](size_t i) {
            return _proxy(*this, i);
        }

        // friend void println(const auto& tree) {
        //     print("["); for (size_t i {0}; i < tree._size; ++i) {
        //         if (i > 0) print(", "); print("{}", tree[i]);
        //     } println("]");
        // }
    };
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        bidx_tree sum_to {static_cast<size_t>(m) * 2};
        unordered_map<int64_t, int64_t> num_i {};
        // println("-");

        for (size_t i {1}; i <= m; ++i) {
            sum_to[i+m] += 1;
            num_i[i] = i+m;
        } 
        // println(sum_to);
        
        int offset {m};
        vector<int> result {};

        for (const auto& q: queries) {
            result.push_back(sum_to[num_i[q]] - 1);

            sum_to[num_i[q]] -= (sum_to[num_i[q]] - sum_to[num_i[q]-1]);
            sum_to[offset] += 1;
            num_i[q] = offset;
            offset -= 1;

            // println(sum_to);
            // println("{}", result);
        } 

        return result;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    try {
        vector<int> queries = LeetCodeIO::deserialize<vector<int>>(cin);
        int m = LeetCodeIO::deserialize<int>(cin);

        Solution obj;
        auto res = obj.processQueries(queries, m);

        stringstream out_stream;
        LeetCodeIO::print(out_stream, res);
        cout << "\noutput: " << out_stream.rdbuf() << '\n';
    } catch (const LeetCodeIO::Error &error) {
        cerr << "LC_IO: " << error.what() << '\n';
        return 2;
    }
    return 0;
}
