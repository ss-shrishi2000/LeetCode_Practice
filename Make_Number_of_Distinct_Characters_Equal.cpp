PROBLEM STATEMENT :- You are given two 0-indexed strings word1 and word2. A move consists of choosing two indices i and j such that 
0 <= i < word1.length and 0 <= j < word2.length and swapping word1[i] with word2[j]. Return true if it is possible to get the number 
of distinct characters in word1 and word2 to be equal with exactly one move. Return false otherwise.


Example 1:

Input: word1 = "ac", word2 = "b"
Output: false
Explanation: Any pair of swaps would yield two distinct characters in the first string, and one in the second string.
Example 2:

Input: word1 = "abcc", word2 = "aab"
Output: true
Explanation: We swap index 2 of the first string with index 0 of the second string. The resulting strings are word1 = "abac" and word2 = "cab", 
which both have 3 distinct characters.
  
  SOLUTION :-
    class Solution {
public:
    bool isItPossible(string word1, string word2) 
    {
        map<char, int> mp1, mp2;
        bool f = true;
        for(int i = 0; i < word1.size(); i++)
        mp1[word1[i]]++;

        for(int i  = 0; i < word2.size(); i++)
        mp2[word2[i]]++;


        //cout<<mp1.size()<<" "<<mp2.size()<<endl;

        for(char c = 'a'; c <='z'; c++)
        {
                for(char d = 'a'; d <='z'; d++)
                {
                    if(mp2[d] > 0 && mp1[c] > 0)
                    {
                        mp2[d]--;
                        mp2[c]++;
                        mp1[d]++;
                        mp1[c]--;

                        int d1 = 0, d2 = 0;
                        for(char c3 = 'a'; c3 <= 'z'; c3++)
                        {
                            if(mp1[c3] > 0)d1++;
                            if(mp2[c3] > 0)d2++;
                        }

                        if(d1 == d2)
                        return 1;

                        mp2[d]++;
                        mp2[c]--;
                        mp1[d]--;
                        mp1[c]++;

                    }
                }
        }

        return false;
    }
};
