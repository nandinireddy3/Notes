#include <bits/stdc++.h>

/*
CARDS:
    2,4,3,1
    SORTED  UNSORTED
    2,      4,3,1
    2,4,    3,1
    2,3,4   1
    1,2,3,4

BEST CASE TC: O(N) [SORTED ARRAY]
AVERAGE CASE TC: O(N^2)
WORST CASE TC: O(N^2) [ REVERSE SORTED ARRAY]
*/
using namespace std;

void Insertion(int n, vector<int>& A){

    for(int i = 1; i < n; i++){
        int temp = A[i];
        int hole = i;
        while(0 < hole && A[hole-1] > temp){
            A[hole] = A[hole-1];
            hole--;
        }
        A[hole] = temp;
    }
}

int main(){

    vector<int> A = {2,7,4,1,5,3};

    Insertion(6,A);

    for(int i = 0; i < 6; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}