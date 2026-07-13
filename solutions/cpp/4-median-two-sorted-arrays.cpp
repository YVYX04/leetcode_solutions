#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {

        // lengths
        int m = nums1.size(), n = nums2.size();

        // odd/even
        bool isOdd = (m + n) % 2 == 1;

        // empty array case
        if(m == 0)
        {
            if(isOdd) return nums2[n / 2];
            else return (nums2[n / 2] + nums2[n / 2 - 1]) / 2.0;
        } else if(n == 0)
        {
            if(isOdd) return nums1[m / 2];
            else return (nums1[m / 2] + nums1[m / 2 - 1]) / 2.0;
        }
        
        // A: smallest array, B: largest array
        vector<int>& A = (m < n) ? nums1 : nums2;
        vector<int>& B = (m < n) ? nums2 : nums1;

        // bounds
        // l = -1 to account for the case where the partition is at the start of A
        int l = -1, r = A.size() - 1, mid{};

        // limits
        int pos_infty = INT_MAX;
        int neg_infty = INT_MIN;

        // partition length
        int partitionLen = (m + n) / 2;

        // track
        int Al{}, Ar{}, Bl{}, Br{}, pB{};

        while(l <= r)
        {
            // midpoint in A
            mid = l + (r - l) / 2;

            // partition idx in B
            pB = partitionLen - (mid + 2);

            // avoid out of bound issue
            Al = (mid >= 0) ? A[mid] : neg_infty;
            Ar = (mid + 1 < A.size()) ? A[mid + 1] : pos_infty;
            Bl = (pB >= 0) ? B[pB] : neg_infty;
            Br = (pB + 1 >= 0 && pB + 1 < B.size()) ? B[pB + 1] : pos_infty;

            // compare and update bounds
            if(Al <= Br && Bl <= Ar) // partition rule respected
            {
                if(isOdd) return min(Ar, Br);
                else return (min(Ar, Br) + max(Al, Bl)) / 2.0;
            } else if(Al > Br) // move left
            {
                r = mid - 1;
            } else // move right
            {
                l = mid + 1;
            }
        }
        return 0.0; // should never reach here
    }
};

int main(void)
{
    // test 1
    vector<int> a = {1};
    vector<int> b = {100};
    Solution s;
    std::cout << s.findMedianSortedArrays(a, b) << std::endl;

    return 0;
}