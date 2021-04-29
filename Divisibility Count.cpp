// Google SWE Online Coding Challenge Internship 2021
// https://www.geeksforgeeks.org/gocc15-google-swe-online-coding-challenge-internship-2021/?ref=rp
// Divisibility Count

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector <int> ans;

// 최대공약수
int gcd(int a, int b)  
{ 
    return (a % b)!=0 ? gcd(b, a%b) : b; // 유클리드 호제법 
}

// Find the number of N digit integers divisible by both X and Y
void count(int n, int x, int y)
{
    int cnt = 0, num;
    num = x*y / gcd(x, y); // 최소공배수

    for(int i = num ; i < pow(10, n) ; i+=num) {
        if(i > pow(10, n-1)) {
            cnt++;
        }
    } 
    ans.push_back(cnt % ((int)pow(10, 9) + 7));
}

int main(void)
{
    int t, n, x, y;
    cin >> t; // test case
    
    while(t--) {
        cin >> n >> x >> y;
        count(n, x, y);
    }

    for(int i = 0 ; i < ans.size() ; i++) {
        cout << ans[i] << '\n';
    }
}