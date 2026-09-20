// Created by oportunitas at 2026/09/20 08:24
// leetgo: 1.4.18
// https://leetcode.com/problems/array-wrapper/

// @lc code=begin

class ArrayWrapper {
    private nums: number[];

    constructor(nums: number[]) {
        this.nums = nums;
    }
    
    valueOf(): number {
        return this.nums.reduce((acc, cur_val) => acc + cur_val, 0);
    }
    
    toString(): string {
        return `[${this.nums}]`;
    }
};

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */

// @lc code=end
