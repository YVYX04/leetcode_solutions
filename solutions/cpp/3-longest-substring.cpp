#include <string>
#include <array>
using std::string;
using std::array;



class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        array<int, 256> lastSeen;
        lastSeen.fill(-1);

        int left = 0;
        int best = 0;

        for (int right = 0; right < s.size(); ++right)
        {
            unsigned char c = s[right];

            if (lastSeen[c] >= left)
            {
                left = lastSeen[c] + 1;
            }

            lastSeen[c] = right;
            best = std::max(best, right - left + 1);
        }

        return best;
    }
};