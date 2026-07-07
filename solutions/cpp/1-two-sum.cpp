#include <vector>
#include <utility>
#include <iostream>
using std::vector;
using std::pair;

/*
To solve the Two Sum problem, we can use a hash map.
Since the goal of solving the Two Sum problem is to build an
understanding of this type of data structure, I will implement
my own hash map class to use in the solution.
*/

class HashMap
{
private:
    // private member variables
    static const int CAPACITY = 10000;
    vector<vector<pair<int, int>>> table;

    // private helper: hash function
    int hash(int key)
    {
        int h = key % CAPACITY;

        // handling negative keys
        if(h < 0) h += CAPACITY;

        return h;
    }

public:
    // constructor
    HashMap()
    {
        table.resize(CAPACITY);
    }

    // insert()
    void insert(int key, int value)
    {
        int idx = hash(key);

        // table[idx] is one bucket, i.e. a vector<pair<int, int>>.
        // auto& p means p is a reference to each pair inside that bucket.
        // This avoids copying the pair and allows us to modify it directly.
        for (auto &p : table[idx])
        {
            if (p.first == key)
            {
                p.second = value;
                return;
            }
        }

        // if we did not find a match <key, value>
        // we use the push_back() function to append table
        table[idx].push_back({key, value});
    }

    // contains: check if a given key is in the hash map
    bool contains(int key)
    {
        int idx = hash(key);
        for (auto &p : table[idx])
        {
            if (p.first == key)
            {
                return true;
            }
        }

        return false;
    }

    // get
    int get(int key)
    {
        int idx = hash(key);
        for (auto &p : table[idx])
        {
            if (p.first == key)
            {
                return p.second;
            }
        }

        // missing key
        return -999;
    }
    
};

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        // instantiate HashMap
        HashMap map{};

        // scan array
        for (int i = 0; i < nums.size(); ++i)
        {
            int n = nums[i];
            int diff = target - n;
            if (map.contains(diff)) return {i, map.get(diff)};
            map.insert(n, i);
        }

        return {-999, -999};
    }
};