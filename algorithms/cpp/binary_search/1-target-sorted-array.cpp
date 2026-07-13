#include <vector>
#include <iostream>
using namespace std;

class binarySearch
{
public:
    int find_target(const int target, const vector<int> &v)
    {
        int left = 0, right = v.size() - 1, mid{};
        while(left <= right)
        {
            // middle
            mid = left + (right - left) / 2;
            if(target == v[mid]) return mid;
            else if(target < v[mid])
            {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};

int main(void)
{
    // example
    const vector<int> nums = {2, 4, 7, 9, 11};

    // solution
    binarySearch bs;
    cout << bs.find_target(7, nums) << endl;


    return 0;
}