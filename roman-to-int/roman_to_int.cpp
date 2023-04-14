#include <iostream>
#include <string>
#include <unordered_map>

class Solution {

public:
	static std::unordered_map<char, int> S2V;

	static const char Seqs[][3];

	static int romanToInt(std::string s) {
		int result = 0;

		for (std::size_t i = 0; i < s.length(); ++i) {
			const char ch = s[i];
			const char* ch_next = i < s.length() ? &s[i + 1] : nullptr;

			bool was_processed = false;
			for (std::size_t x = 0; !was_processed && x < 3; ++x) {
				if (Seqs[x][0] == ch && (ch_next && (*ch_next == Seqs[x][1] || *ch_next == Seqs[x][2]))) {
					result += (S2V[*ch_next] - S2V[ch]);
					++i;
					was_processed = true;
				}
			}

			if(!was_processed)
				result += S2V[ch];			
		}
		return result;
	}
};
 std::unordered_map<char, int>
Solution::S2V = {
	{'I', 1},
	{'V', 5},
	{'X', 10},
	{'L', 50},
	{'C', 100},
	{'D', 500},
	{'M', 1000}
};

 const char Solution::Seqs[][3] = {
	 {'I', 'V', 'X'},
	 {'X', 'L', 'C'},
	 {'C', 'D', 'M'}
 };

int main()
{
	std::string s1 = "III";
	std::cout << s1 << " equal to " << Solution::romanToInt(s1) << std::endl;

	std::string s2 = "LVIII";
	std::cout << s2 << " equal to " << Solution::romanToInt(s2) << std::endl;

	std::string s3 = "MCMXCIV";
	std::cout << s3 << " equal to " << Solution::romanToInt(s3) << std::endl;

	return 0;
}