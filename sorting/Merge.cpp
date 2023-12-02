#include <bits/stdc++.h>

using namespace std;

/*
    1- Divide and Conquer
    2- Recursive
    3- Stable
    4- Not Inplace SC- O(N)
    5- Worst case TC- O(nlogn)
*/
void Merge(int l,int mid,int h, vector<int>& A){

    int nL = mid-l+1;
    int nR = h-mid;

    int Left[nL];
    int Right[nR];

    for(int x = 0; x < nL; x++){
        Left[x] = A[x+l];
    }

    for(int x = 0; x < nR; x++){
        Right[x] = A[x+mid+1];
    }

    int i = 0, j = 0, k =l;
    while((i < nL) && (j < nR)){
        if(Left[i] <= Right[j]){
            A[k] = Left[i];
            i++;
        }
        else{
            A[k] = Right[j];
            j++;
        }
        k++;
    }
    while(i < nL){
        A[k] = Left[i];
        i++;
        k++;
    }
    while(j < nR){
        A[k] = Right[j];
        j++;
        k++;
    }

}

void MergeSort(int l,int h, vector<int>& A){

    if(l >= h) return;
    
    int mid = l + (h-l)/2;
    MergeSort(l,mid,A);
    MergeSort(mid+1,h,A);
    Merge(l,mid,h,A);
}

int main(){

    vector<int> A = {2,7,4,1,5,3};

    MergeSort(0,5,A);

    for(int i = 0; i < 6; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}