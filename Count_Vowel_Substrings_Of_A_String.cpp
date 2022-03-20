A substring is a contiguous (non-empty) sequence of characters within a string.
A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.
Given a string word, return the number of vowel substrings in word.


Example 1:
Input: word = "aeiouu"
Output: 2
  
Explanation: The vowel substrings of word are as follows (underlined):
- "aeiouu"
- "aeiouu"
  
Example 2:
Input: word = "unicornarihan"
Output: 0
Explanation: Not all 5 vowels are present, so there are no vowel substrings.
  
  SOLUTION :-
    class Solution {
public:
    int countVowelSubstrings(string word) 
    {
        int n = word.size();
        int res = 0;
        
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u'};
        
        for (int i = 0; i < n; i++)
        {
            unordered_set<char> letters;
            // string temp = "";
            for (int j = i; j < n; j++)
            {
                // temp += word[j];
                letters.insert(word[j]);
                if (letters == vowels)
                res++;
            }
        }
        
        return res;
    }
};
