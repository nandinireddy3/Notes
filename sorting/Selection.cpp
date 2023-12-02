#include <bits/stdc++.h>

/*
    1- Take min in unsorted and fill it in sorted arrays.
    2- Not Inplace sorting Algorithm if an unsorted
    and sorted are maintained

    Left: 2,7,4,1,5,3 ,             Right: _,_,_,_,_,_
    Left: 2,7,4,MAX,5,3 ,           Right: 1,_,_,_,_,_
    Left: MAX,7,4,MAX,5,3 ,         Right: 1,2,_,_,_,_
    Left: MAX,7,4,MAX,5,MAX ,       Right: 1,2,3,_,_,_
    Left: MAX,7,MAX,MAX,5,MAX ,     Right: 1,2,3,4,_,_
    Left: MAX,7,MAX,MAX,MAX,MAX ,   Right: 1,2,3,4,5,_
    Left: MAX,MAX,MAX,MAX,MAX,MAX , Right: 1,2,3,4,5,7

    3- we simply swap to make it inplace

    TC: O(N^2)
    SC: O(1)


*/
using namespace std;

void Selection(int n, vector<int>& A){

    for(int i = 0; i < n; i++){
        int m = A[i];
        int iMin = i;
        for(int j = i; j < n; j++){
            if(A[j] < m){
                m = A[j];
                iMin = j;
            }
        }
        swap(A[i],A[iMin]);
    }
}

int main(){

    vector<int> A = {2,7,4,1,5,3};

    Selection(6,A);

    for(int i = 0; i < 6; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}