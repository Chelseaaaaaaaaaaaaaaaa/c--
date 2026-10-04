#include "bits/stdc++.h"
using namespace std;
int dat[101];

//时间复杂度log_2(N)

/**
���ֲ���
����1
input:
10
1 3 4 5 7 8 9 10 20 21
11
output:
not found

����2
input:
10
1 3 4 5 7 8 9 10 20 21
9
output:
7
 */
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>dat[i];
    }
    sort(dat, dat + n);
    int target;
    cin>>target;
    int left=0;
    int right=n-1;
    while(right>=left){
        int mid = left  + (right-left)/2; 
        if(dat[mid]==target){
            cout << mid;
            return 0;
        }
        if(dat[mid]>target){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    cout << "not found";
    // TODO
    return 0;
}
