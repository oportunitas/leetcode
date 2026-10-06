// Created by oportunitas at 2026/10/06 10:20
// leetgo: 1.4.18
// https://leetcode.com/problems/apply-transform-over-each-element-in-array/

// @lc code=begin

function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    // return arr.map((el, i) => fn(el, i)); this is if we use .map()
    const result: number[] = [];
    arr.forEach((elem, idx) => {
        result[idx] = fn(elem, idx);
    }); 
    return result;
};

// @lc code=end
