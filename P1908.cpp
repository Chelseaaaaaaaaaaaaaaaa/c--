#include "bits/stdc++.h"

using namespace std;
int arr[500001];
int aux[500001];
long long cnt = 0;

void quick_sort(int left, int right){
    if(left >= right){
        return;
    }
    int pivot = arr[(left+right)/2];
    int i = left;
    int j = right; 
    while(i <= j){
       while(arr[i] < pivot){
        i++;
       }
       while(arr[j] > pivot){
        j--;
       }

       if(i<=j){
        swap(arr[i],arr[j]);
        i++;
        j--;
       }
    }

    quick_sort(left,j);
    quick_sort(i,right);
}

void mSort(int left, int right) {
    if (left == right) return;
    int mid = (left+right)/2;
    mSort(left,mid);
    mSort(mid+1,right);

    int i = left;
    int j = mid+1;
    int k = left; //record aux index
    
    while(i<=mid && j<= right){
        if(arr[i] <= arr[j]){
            aux[k] = arr[i];
            i++;
        }else{
            cnt += (mid-i)+1;
            aux[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i<=mid){
        aux[k] = arr[i];
        i++;
        k++;
    }

    while(j<=right){
        aux[k] = arr[j];
        j++;
        k++;
    }

    for(int i=left;i<=right;i++){
        arr[i] = aux[i];
    }

}
int main(){
    // freopen("paint.in", "r", stdin);
    // freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    //quick_sort(0,N-1);
    mSort(0,N-1);
   cout << cnt;
    return 0;
}


