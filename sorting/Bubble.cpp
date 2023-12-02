#include <bits/stdc++.h>

using namespace std;

/*
2,7,4,1,5,3 - >   2,4,1,5,3,7
TC: O(N^2)
SC: O(1)
FURTHER OPTIMISATION: IF NO SWAPS HAPPENING THEN SORTED ALREADY
BEST CASE TC: O(N)
AVERAGE CASE TC: O(N^2)
WORST CASE TC: O(N^2) 
*/
void Bubble(int n, vector<int>& A){

    for(int i = 0; i < n; i++){
        bool flag = false;
        for(int j = 0; j < n-i-1; j++){
            if(A[j] > A[j+1]){
                swap(A[j],A[j+1]);
                flag = true;
            }
        }
        if(flag == false) break;
    }
}

int main(){

    vector<int> A = {2,7,4,1,5,3};

    Bubble(6,A);

    for(int i = 0; i < 6; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}