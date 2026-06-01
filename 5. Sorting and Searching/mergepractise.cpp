#include<bits/stdc++.h>
using namespace std;
void merge(int A[], int l , int r){
    int mid =(l + r)/2;
    int i =l;
    int j = mid + 1;
}
void mergeSort(int A[], int l, int r){
    if(l == r)return;
    int mid = (l + r)/2;
    mergeSort(A, l, mid);
    mergeSort(A, mid +1 , r);
    merge(A, l, r);
}
int main(){
    int n = 8;
    int A[8] = {10, 6, 3, 5, 8,2, 6, 9};
    mergeSort(A, 0, n-1);
    for(int i = 0; i< n; i++){
        cout << A[i] << " ";
    }

}