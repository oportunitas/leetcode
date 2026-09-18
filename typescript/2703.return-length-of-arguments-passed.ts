// Created by oportunitas at 2026/09/19 05:51
// leetgo: 1.4.18
// https://leetcode.com/problems/return-length-of-arguments-passed/

// @lc code=begin

type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };

function argumentsLength(...args: JSONValue[]): number {
    return args.length;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */

// @lc code=end
