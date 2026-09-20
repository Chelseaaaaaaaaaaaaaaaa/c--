#include "bits/stdc++.h"
using namespace std;

int n;
int pos[101];

int getExplosionIndex(int startIndex, int direction) {
    int radius = 1;
    while (true){
        if(direction == -1 && startIndex == 0 || direction == 1 && startIndex == n-1){
            break;
        }

        int currentIndex = startIndex;
        while (true){
            if(currentIndex + direction >= 0 && currentIndex + direction < n && abs(pos[currentIndex + direction]-pos[startIndex]) <= radius){
                currentIndex += direction;
            }else{
                break;
            }
        }

        if(currentIndex == startIndex){
            break;
        }

        startIndex = currentIndex;
        radius++;
    }
    return startIndex;
}

int main()
{
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>pos[i];
    }
    sort(pos, pos+n);

    int answer = 1;
    for(int i=0; i<n; i++) {
        int left = getExplosionIndex(i, -1);
        int right = getExplosionIndex(i, 1);
        int count = right - left + 1;
        answer = max(answer, count);
    }
    cout<<answer<<endl;
    return 0;
}
