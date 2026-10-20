# Created by oportunitas at 2026/10/20 17:51
# leetgo: 1.4.18
# https://leetcode.com/problems/invalid-tweets/

# @lc code=begin

import pandas as pd

def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    return tweets[['tweet_id']][tweets['content'].str.len() > 15]

# @lc code=end
