// Created by oportunitas at 2026/09/22 14:41
// leetgo: 1.4.18
// https://leetcode.com/problems/function-composition/

// @lc code=begin

type F = (x: number) => number;

function compose(functions: F[]): F {
    if (functions.length === 0) return ((x: any) => x);

    // til: reduceRight, which implements moving along an array from right to left.
    return functions.reduceRight((prev_fn, cur_fn) => {
        return (x: any) => {
            return cur_fn(prev_fn(x));
        }
    })
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */

// @lc code=end
