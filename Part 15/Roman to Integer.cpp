
// PROBLEM LINK
// https://www.codingninjas.com/codestudio/problems/1112581

/*
    Solution : 
    Time complexity : O(N)
    Space Complexity : O(7) ~ O(1)
*/


class Solution {
public:
    int romanToInt(string s) {
	unordered_map<char, int> m = {{ 'I' , 1 },
		{ 'V' , 5 },
		{ 'X' , 10 },
		{ 'L' , 50 },
		{ 'C' , 100 },
		{ 'D' , 500 },
		{ 'M' , 1000 }
	};

	int sum = m[s.back()];
	for (int i = 0; i < s.size() - 1; i++) {
		if (m[s[i]] < m[s[i + 1]])
			sum -= m[s[i]];  // IV   5-1 =4
		else
			sum += m[s[i]];
	}
	return sum;
}
};