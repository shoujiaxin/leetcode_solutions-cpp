/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (29.64%)
 * Likes:    8077
 * Dislikes: 493
 * Total Accepted:    1.4M
 * Total Submissions: 4.6M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 *
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> charSet;
    decltype(charSet.size()) maxLen = 0;

    for (auto it = s.cbegin(); it != s.cend();) {
      if (charSet.find(*it) == charSet.end()) {
        charSet.insert(*it);
        ++it;
      } else {
        maxLen = max(maxLen, charSet.size());

        it -= charSet.size() - 1;
        charSet.clear();
      }
    }
    maxLen = max(maxLen, charSet.size());

    return maxLen;
  }
};
// @lc code=end
