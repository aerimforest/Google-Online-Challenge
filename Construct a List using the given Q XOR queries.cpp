// Google online challenge 2020 for summer internships 2021
// https://www.geeksforgeeks.org/google-online-challenge-2020/
// Construct a List using the given Q XOR queries

#include <cstdio>
#include <vector>
#include <algorithm> 
#define MAX 1000

using namespace std;

int main(void)
{
    int queryNum;
    int queries[MAX][MAX];
    vector<int> list;
    scanf("%d", &queryNum);
    
    list.push_back(0); // initial list

    for(int i = 0 ; i < queryNum ; i++) {
        scanf("%d %d", &queries[i][0], &queries[i][1]);
        if(queries[i][0] == 0) { // add element to list
            list.push_back(queries[i][1]);
        }
        else { // replace each element “A” of the list by A^X(XOR)
            for(int j = 0 ; j < list.size() ; j++) {
                list[j] = (list[j] ^ queries[i][1]); 
            }
        }
    }

    sort(list.begin(), list.end()); // 오름차순 정렬
    for(int i = 0 ; i < list.size() ; i++) {
        printf("%d ", list[i]);
    }

    return 0;
}