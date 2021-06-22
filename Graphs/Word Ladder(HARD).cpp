// A transformation sequence from word beginWord to word endWord 
// using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, 
// return the number of words in the shortest transformation sequence from beginWord to endWord, 
// or 0 if no such sequence exists.

// https://leetcode.com/problems/word-ladder/

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
  
Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
  
  
  
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        q.push(beginWord);
        int wordSize = beginWord.size();
        unordered_set<string>word;
        for(int i = 0 ; i < wordList.size() ; i++){
            word.insert(wordList[i]);
        }
        
        if(word.find(endWord) == word.end()){
            return 0;
        }
        int len = 0;
        while(!q.empty()){
            len++;
            int qlen = q.size();
            for(int i = 0 ; i < qlen ; i++){
                string s = q.front();
                q.pop();
                for(int j = 0 ; j < wordSize ; j++){
                    char org = s[j];
                    for(char ch = 'a' ; ch <= 'z' ; ch++){
                        s[j] = ch;
                        if(s == endWord)return len+1;
                        if(word.find(s) == word.end())continue;
                        word.erase(s);
                        q.push(s);
                    }
                    s[j] = org;
                }
            }
        }
        return 0;
    }
};
