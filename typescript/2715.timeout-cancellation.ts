// Created by oportunitas at 2026/09/19 06:43
// leetgo: 1.4.18
// https://leetcode.com/problems/timeout-cancellation/

// @lc code=begin

type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Fn = (...args: JSONValue[]) => void

function cancellable(fn: Fn, args: JSONValue[], t: number): Function {
    // we create the function itself, that has a timeout/delay of t
    const fn_call = setTimeout(() => { fn(...args) }, t);

    // and then we return the function that can cancel it, given fn_call is not finished yet
    return function () { clearTimeout(fn_call) };
};

/**
 *  const result = [];
 *
 *  const fn = (x) => x * 5;
 *  const args = [2], t = 20, cancelTimeMs = 50;
 *
 *  const start = performance.now();
 *
 *  const log = (...argsArr) => {
 *      const diff = Math.floor(performance.now() - start);
 *      result.push({"time": diff, "returned": fn(...argsArr)});
 *  }
 *       
 *  const cancel = cancellable(log, args, t);
 *
 *  const maxT = Math.max(t, cancelTimeMs);
 *           
 *  setTimeout(cancel, cancelTimeMs);
 *
 *  setTimeout(() => {
 *      console.log(result); // [{"time":20,"returned":10}]
 *  }, maxT + 15)
 */

// @lc code=end
