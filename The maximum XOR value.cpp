// Google SWE Online Coding Challenge Internship 2021
// https://www.geeksforgeeks.org/gocc15-google-swe-online-coding-challenge-internship-2021/?ref=rp
// The maximum XOR value

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void maxXOR(int, int);
vector <int> arr, ans;

int main(void)
{
    int t, n, q, tmp, x, m;
    cin >> t; // test cases
    while(t--) {
        cin >> n; // the number of elements in the array
        for(int i = 0 ; i < n ; i++) {
            cin >> tmp;
            arr.push_back(tmp); 
        }
        
        sort(arr.begin(), arr.end()); // 오름차순 정렬

        cin >> q; //  the number of queries
        for(int i = 0 ; i < q ; i++) {
            cin >> x >> m;
            maxXOR(x, m);
        }
    }

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
void maxXOR(int x, int m)
{
    int max = 0, idx = -1;

    // it = M보다 작거나 같은 값을 갖는 arr 원소 인덱스 
    int it = upper_bound(arr.begin(), arr.end(), m) - arr.begin() - 1;
    if(it < 0) { // 조건 만족하는 값 없는 경우
        ans.push_back(-1);
        return;
    }

    for(int j = 0 ; j < it ; j++) {
        if(max < (x ^ arr[j])) {
            max = (x ^ arr[j]);
            idx = j;
        }
    }
    ans.push_back(arr[idx]);
}