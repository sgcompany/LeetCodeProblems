/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

https://leetcode.com/problems/two-sum/solution/

Approach 3: One-pass Hash Table
It turns out we can do it in one-pass. While we iterate and inserting elements into the table, we also look back to check if current element's complement already exists in the table. If it exists, we have found a solution and return immediately.

Complexity Analysis:
Time complexity : O(n). We traverse the list containing n elements only once. Each look up in the table costs only O(1) time.
Space complexity : O(n). The extra space required depends on the number of items stored in the hash table, which stores at most n elements.
*/

#pragma once

#include <unordered_map>
#include <vector>

namespace arrays
{
   class TwoSum
   {
   public:
      std::vector<int> Run(const std::vector<int>& i_nums, int i_target)
      {
         std::unordered_map<int, int> hash_nums;
         std::vector<int> res;
         for (auto i = 0u; i < i_nums.size(); ++i)
         {
            auto j = hash_nums.find(i_target - i_nums[i]);
            if (j == hash_nums.end())
            {
               hash_nums.emplace(i_nums[i], i);
            }
            else if (i_nums[i] + j->first == i_target)
            {
               res.push_back(j->second);
               res.push_back(i);
               return res;
            }
         }
         return res;
      }
   };
}
