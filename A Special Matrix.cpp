// Google Internship 2020 – Google Online Challenge(1st Coding Round)
// https://www.geeksforgeeks.org/google-internship-2020-google-online-challenge1st-coding-round/?ref=rp
// A Special Matrix

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int matrix[501][501];

// 특정 숫자가 Special Number가 되기 위해 필요한 연산 횟수 계산
int countMove(int num)
{
    for(int i = num/2 ;; i++) {
        if((i-1)*i/2 <= num && num < i*(i+1)/2) { // 계차수열
            return min(num - (i-1)*i/2, i*(i+1)/2 - num);
        }
    }
}

// Special Matrix가 되기 위한 최소 연산 횟수 계산
int makeSpecial(int n)
{
    vector <int> moveSum;
    int row, column;

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            matrix[i][j] = countMove(matrix[i][j]);
        }
    }

    for(int i = 0 ; i < n ; i++) {
        row = 0, column = 0;
        for(int j = 0 ; j < n ; j++) {
            row += matrix[i][j];
            column += matrix[j][i];
        }
        moveSum.push_back(row);
        moveSum.push_back(column);
    }

    sort(moveSum.begin(), moveSum.end());

    return moveSum[0];
}

int main(void)
{
    int t, n;  
    cin >> t; // test case

    while(t--) {
        cin >> n;

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                cin >> matrix[i][j];
            }
        }
        cout << makeSpecial(n) << '\n';
    }

    return 0;
}