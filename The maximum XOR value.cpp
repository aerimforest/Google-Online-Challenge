// Google SWE Online Coding Challenge Internship 2021
// https://www.geeksforgeeks.org/gocc15-google-swe-online-coding-challenge-internship-2021/?ref=rp
// The maximum XOR value

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#define MAX 1000
using namespace std;

void maxXOR(int);
int queries[MAX][MAX] = {0};
vector <int> arr, ans;

int main(void)
{
    int t, n, q, tmp, i = 0, x, m;
    cin >> t; // test cases
    while(t--) {
        cin >> n; // the number of elements in the array
        for(int i = 0 ; i < n ; i++) {
            cin >> tmp;
            arr.push_back(tmp); 
        }
        cin >> q; //  the number of queries
        for(int i = 0 ; i < q ; i++) {
            cin >> queries[i][0] >> queries[i][1];
        }
        
        sort(arr.begin(), arr.end()); // 오름차순 정렬
        maxXOR(q);
    }

    cout << "ans" << '\n';
    // 정답 출력
    for(int i = 0 ; i < q ; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}

/*
    determine the array value that provides the maximum bitwise XOR value with x 
    where the array value is not more than m
*/
void maxXOR(int q)
{
    for(int i = 0 ; i < q ; i++) {
        int max = 0, idx = -1;

        // it = M보다 작거나 같은 값을 갖는 arr 원소 인덱스 
        int it = upper_bound(arr.begin(), arr.end(), queries[i][1]) - arr.begin() - 1;
        if(it < 0) { // 조건 만족하는 값 없는 경우
            ans.push_back(-1);
            continue;
        }

        for(int j = 0 ; j < it ; j++) {
            if(max < (queries[i][0] ^ arr[j])) {
                max = (queries[i][0] ^ arr[j]);
                idx = j;
            }
        }
        ans.push_back(arr[idx]);
    }
}