PROBLEM STATEMENT :- Let the function f(s) be the frequency of the lexicographically smallest character in a non-empty string s. For example, if s = "dcce" 
  then f(s) = 2 because the lexicographically smallest character is 'c', which has a frequency of 2. You are given an array of strings words and another 
  array of query strings queries. For each query queries[i], count the number of words in words such that f(queries[i]) < f(W) for each W in words.
  Return an integer array answer, where each answer[i] is the answer to the ith query.

 

Example 1:
Input: queries = ["cbd"], words = ["zaaaz"]
Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
  
Example 2:
Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").
  
  SOLUTION :-
    class Solution {
public:
    static int getFreq(string &s)
    {
        int freq[26] = {0};
        
        for(int i = 0; s[i]; i++)
            freq[s[i] - 'a']++;
        
        // return freq of lexographically smallest char
        for(int i = 0; i < 26; i++) {
            if(freq[i])
                return freq[i];
        }
        return 0;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) 
    {
        vector<int> results;
        int count_freq[12] = {0};
        
        for(string &word : words) 
            count_freq[getFreq(word)]++;
        
        
        for(int i = 9; i >= 0; i--)
            count_freq[i] += count_freq[i + 1];
        // process the queries
        // if f(query) = 3 it will hold true for 4, 5, ....
        for(string &query : queries) 
            results.push_back(count_freq[getFreq(query) + 1]);
        
        return results;
    }
};
