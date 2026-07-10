#include <vector>
#include <cmath>
using std::vector;

// definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int readNumber(ListNode *l1)
    {
        // init vector
        vector<int> nums{};

        // read the linked list
        ListNode *ptr = l1;
        while(ptr != nullptr)
        {
            nums.push_back(ptr->val);
            ptr = ptr->next;
        }

        // write the number {1, 2, 3} -> 321
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans += (nums[i] * pow(10, i));
        }
        return ans;
    }

    ListNode* writeLinkedList(int n)
    {
        // 321 -> {1, 2, 3}
        ListNode node{};
        while(n > 0)
        {
            // register digit and update n
            int digit = n % 10;
            n = n % 10;

            // store val and update node
            node.val = digit;
            if(n >= 0) node.next = new ListNode{};
            else node.next = nullptr;
        }

    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        // add the two numbers
        int n = readNumber(l1) + readNumber(l2);

        // return the associated linked list
        return writeLinkedList(n);

    }
};