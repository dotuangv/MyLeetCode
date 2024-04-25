class Solution {
public:

    bool isMatch(string s, string p) {

	int n = s.length();
	int m = p.length();
	int i = 0, j = 0, startIndex = -1, match = 0;

	while (i < n)
	{
		if (j < m && (p[j] == '?' || p[j] == s[i]))
		{
			// Characters match or '?' in pattern matches any character.
			i++;
			j++;
		}
		else if (j < m && p[j] == '*')
		{
			// Wildcard character '*', mark the current position in the pattern and the text as a proper match.
			startIndex = j;
			match = i;
			j++;
		}
		else if (startIndex != -1)
		{
			// No match, but a previous wildcard was found. Backtrack to the last '*' character position and try for a different match.
			j = startIndex + 1;
			match++;
			i = match;
		}
		else
		{
			// If none of the above cases comply, the pattern does not match.
			return false;
		}
	}

	// Consume any remaining '*' characters in the given pattern.
	while (j < m && p[j] == '*')
	{
		j++;
	}

	// If we have reached the end of both the pattern and the text, the pattern matches the text.
	return j == m;
}


   
    
};