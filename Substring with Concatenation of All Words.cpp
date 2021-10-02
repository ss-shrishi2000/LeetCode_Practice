PROBLEM STATEMENT :-
  You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word 
  in words exactly once, in any order, and without any intervening characters.You can return the answer in any order.
  
 Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
  
  Solution:-
    class Solution {
public:
    vector<int> findSubstring(string S, vector<string>& L)
    {
       int size_word = L[0].size(); 
  
    // Number of words present inside list L. 
    int word_count = L.size(); 
  
    // Total characters present in list L. 
    int size_L = size_word * word_count; 
  
    // Resultant vector which stores indices. 
    vector<int> res; 
  
    // If the total number of characters in list L 
    // is more than length of string S itself. 
    if (size_L > S.size()) 
        return res; 
  
    // Map stores the words present in list L 
    // against it's occurrences inside list L 
    unordered_map<string, int> hash_map; 
  
    for (int i = 0; i < word_count; i++)  
        hash_map[L[i]]++;     
  
    for (int i = 0; i <= S.size() - size_L; i++) { 
        unordered_map<string, int> temp_hash_map(hash_map); 
  
        int j = i,count=word_count; 
  
        // Traverse the substring 
        while (j < i + size_L) { 
  
            // Extract the word 
            string word = S.substr(j, size_word); 
  
  
            // If word not found or if frequency of current word is more than required simply break. 
            if (hash_map.find(word) == hash_map.end()||temp_hash_map[word]==0) 
                break; 
  
            // Else decrement the count of word from hash_map 
            else
               { temp_hash_map[word]--;count--;}  
  
  
            j += size_word; 
        } 
       
        // Store the starting index of that substring when all the words in the list are in substring 
        if (count == 0) 
            res.push_back(i); 
    } 
  
    return res;
    }
};

 
