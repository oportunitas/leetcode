// Created by oportunitas at 2026/09/25 13:26
// leetgo: 1.4.18
// https://leetcode.com/problems/allow-one-function-call/

// @lc code=begin

type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type OnceFn = (...args: JSONValue[]) => JSONValue | undefined

function once(fn: Function): OnceFn {
    let call_count = -1;
    return function (...args) {
        call_count ++;
        if (call_count <= 0) return fn(...args);
    };
}

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */

// @lc code=end
