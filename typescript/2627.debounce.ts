// Created by oportunitas at 2026/09/19 06:17
// leetgo: 1.4.18
// https://leetcode.com/problems/debounce/

// @lc code=begin

type F = (...args: number[]) => void

function debounce(fn: F, t: number): F {
    // this is the function definition of the last call. 
    let last_call : ReturnType<typeof setTimeout> | undefined = undefined;
    
    return function(...args) {
        // we clear any definition of the last call function, preparing to overwrite it
        clearTimeout(last_call);

        // overwrite
        last_call = setTimeout(() => fn(...args), t);
    }
};

/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */

// @lc code=end
