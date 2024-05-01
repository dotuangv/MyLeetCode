class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        while(i < word.size() && word[i] != ch) i++;
        if(i < word.size())
        {
            int j = 0;
            while(j <= i)
            {
                swap(word[i], word[j]);
                i--;
                j++;
            }
        }
        return word;
    }
};