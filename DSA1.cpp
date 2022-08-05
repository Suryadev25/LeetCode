// 217
//  #include <set>
//  using namespace std;

// class Solution
// {
// public:
//     bool containsDuplicate(vector<int> &nums)
//     {
//         return nums.size() > set<int>(nums.begin(), nums.end()).size();
//     }
// };

// 53
// #include <bits/stdc++.h>
// #define ll long long
// #define int int64_t
// using namespace std;

// class Solution
// {
// public:
//     void maxSubArray(vector<int> &nums)
//     {
//         vector<int> v;
//         v.push_back(nums[0]);
//         for (int i = 1; i < nums.size(); i++)
//         {
//             v.push_back(v[i - 1] + nums[i]);
//         }
//         sort(v.rbegin(), v.rend());
//         int ans = v[0];
//         cout << ans;
//     }
// };

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     vector<int> neew;
//     neew = {1, 2, 4, 5, 5};
//     Solution s;
//     s.maxSubArray(neew);

//     return 0;
// }

// 350
// #include <bits/stdc++.h>
// using namespace std;
// class Solution
// {
// public:
//     vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
//     {
//         unordered_map<int, int> mp;
//         vector<int> vec;
//         for (auto it : nums1)
//             mp[it]++;
//         for (auto it : nums2)
//         {
//             if (mp[it] != 0)
//             {
//                 vec.push_back(it);
//                 mp[it]--;
//             }
//         }
//         return vec;
//     }
// };

// 121
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int sum = 0;
//         int maxii = INT_MAX;
//         for (int i = 0; i < prices.size(); i++)
//         {
//             if (prices[i] < maxii)
//             {
//                 maxii = prices[i];
//             }
//             else if (maxii - prices[i] < 0)
//             {
//                 sum = max(sum, prices[i] - maxii);
//             }
//         }

//         return sum;
//     }
// };

// 566
// class Solution
// {
// public:
//     vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
//     {
//         int sum = 0;
//         int m = mat.size();
//         int n = mat[0].size();
//         sum = m * n;
//         if (sum != r * c)
//             return mat;

//         vector<vector<int>> ans(r, vector<int>(c));
//         for (int i = 0; i < sum; i++)
//             ans[i / c][i % c] = mat[i / n][i % n];

//         return ans;
//     }
// };

// 118
//  This is taking more time and giving error after n=22
//  class Solution {
//  public:
//      long long int factorial(int n){
//          long long int factorial = 1;
//          for(int i =2 ; i<=n ; i++){
//              factorial = factorial*i;
//          }
//          return factorial;
//      }
//      long long int nCr(int n, int r){
//          return factorial(n)/(factorial(r)* factorial(n-r));
//      }
//      vector<vector<int>>my_vec;
//      vector<vector<int>> generate(int numRows) {
//          vector<int >vec;
//          for(int i =0 ; i<numRows ; i++){
//              for(int j=0;j<i;j++){
//                  vec.push_back(nCr(i,j));
//              }
//              vec.push_back(1);
//              my_vec.push_back(vec);
//              vec.clear();
//          }
//           return my_vec;
//      }

// };
// Second solution
// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>>ans(numRows);
//         for(int i =0 ; i<numRows;i++){
//             ans[i].resize(i+1);
//             ans[i][0] = ans[i][i] = 1;

//             for(int j=1 ; j<i ; j++){
//                 ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
//             }
//         }
//         return ans;

//     }
// };

// 36
// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         vector<set<int>>row(9);
//         vector<set<int>>col(9);
//         vector<set<int>>box(9);

//         for(int i =0 ; i<9 ; i++){
//             for(int j=0 ; j<9 ; j++){
//                 if(board[i][j] == '.')
//                     continue;

// refrencing variable which will take the value at index[i][j]

//                 int ref = board[i][j];

// if count is 1 or (value is present already) return false

//                 if(row[i].count(ref))
//                     return false;
//                 if(col[j].count(ref))
//                     return false;

// index for box

//                 int box_index = (i/3)*3 + (j/3);
//                 if(box[box_index].count(ref))
//                     return false;

// if no value is already present then insert the ref in row ,col,box

//                 row[i].insert(ref);
//                 col[j].insert(ref);
//                 box[box_index].insert(ref);
//             }
//         }

// if everything goes fine i.e no repeating value is there , return True

//         return true;
//     }
// };

// 74
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int row = matrix.size();
//        int col = matrix[0].size()-1;
//         int row1=0,col1=col;
//         while(row1<row && col1>-1){
//             if(matrix[row1][col1]==target)
//                 return true;
//             if(matrix[row1][col1]>target){
//                 col1--;
//             }
//             else
//                 row1++;
//         }
//         return false;
//     }
// };

// Basic Binary Search
//  class Solution {
//  public:
//      bool searchMatrix(vector<vector<int>>& matrix, int target) {
//       int row = matrix.size();
//       int col = matrix[0].size();
//       int low = 0;
//       int high = row*col-1;

//      while(low<=high){
//         int mid = (low +high)/2;
//         int mid_val = matrix[mid/col][mid%col];
//          if(mid_val == target)
//              return true;
//          if(mid_val < target){
//              low = mid+1;
//          }
//          else{
//              high = mid-1;
//          }
//      }
//         return false;
//     }
// };

// 387
// class Solution {
// public:
//     int firstUniqChar(string s) {
//          unordered_map<char, int> mp;
//     for (int i = 0; i < s.length(); i++)
//     {
//         mp[s[i]]++;
//     }
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (mp[s.at(i)] == 1)
//         {
//             return i;
//         }
//     }

//     return -1;
//     }
// };
// 383
#include <bits/stdc++.h>
#define ll long long
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    map<char, int> mp1;
    map<char, int> mp2;
    for (int i = 0; i < s2.length(); i++)
    {
        mp2[s2[i]]++;
    }
    for (int i = 0; i < s1.length(); i++)
    {
        mp1[s1[i]]++;
    }
 
    for (int i = 0; i < s2.length(); i++)
    {
        if (mp1.count(s2[i]) == 0)
        {
            // cout << s1[i]
            mp2.erase(s2[i]);
        }
        // cout << s2[i];
    }
    vector<int> v1;
    vector<int> v2;
    for (auto it : mp1)
    {
        v1.push_back(it.second);
    }
    for (auto it : mp2)
    {
        v2.push_back(it.second);
    }
    int valid = 0;
    for (int i = 0; i < v2.size(); i++)
    {
        if (v2[i] < v1[i])
            valid = 1;
    }

    return 0;
}