class Solution {
public:
    bool isValid(string word) {
        bool ok1 = false, ok2 = false;
        if(word.size() < 3) return false;
        for(int i = 0; i < word.size(); i++)
        {
            if(word[i] == 'a' || word[i] == 'e' || word[i] == 'o' || word[i] == 'i' || word[i] == 'u' || word[i] == 'A' || word[i] == 'E' || word[i] == 'O' || word[i] == 'I' || word[i] == 'U') ok1 = true;
            else if(word[i] == '@' || word[i]== '#' || word[i] == '$') return false;
            else if(word[i] < '0' || word[i] > '9') ok2 = true;
        }
        return ok1 && ok2;
    }
};