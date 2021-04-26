// Google online challenge 2020 for summer internships 2021
// https://www.geeksforgeeks.org/google-online-challenge-2020/
// First Question: Size of the smallest subset with maximum Bitwise OR
// dp

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int dp[5];
    int cnt = 1;
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(2);

    sort(arr.rbegin(), arr.rend()); // 내림차순 정렬

    dp[0] = arr[0];

    for(int i = 1 ; i < 5 ; i++) {
        if(dp[i-1] >= (dp[i-1] | arr[i])) {
            dp[i] = dp[i-1];
        }
        else {
            dp[i] = dp[i-1] | arr[i];
            cnt++;
        }
    }
    
    printf("%d\n", cnt);
    return 0;
}