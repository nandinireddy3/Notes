#include <bits/stdc++.h>

using namespace std;
/*
    1- InPlace SC= O(1)
    2- O(nlogn) - Average case TC
    3- O(n^2) - Worst case TC

    1- Pick the Pivot
    2- Arrange in such a way that all left < Pivot
        and all right > Pivot
*/
int Partition(int l,int h,vector<int>& A){

    int pivot = A[h];
    int pIndex = l;

    for(int i = l; i < h; i++){
        if(A[i] <= pivot){
            swap(A[i],A[pIndex]);
            pIndex++;
        }
    }

    swap(A[pIndex],A[h]);
    return pIndex;
}
void QuickSort(int l,int h, vector<int>& A){

    if(l >= h) return;

    int iPivot = Partition(l,h,A);
    QuickSort(l,iPivot-1,A);
    QuickSort(iPivot+1,h,A);
}

int main(){

    vector<int> A = {2,7,4,1,5,3};

    QuickSort(0,5,A);

    for(int i = 0; i < 6; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}