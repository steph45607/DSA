#include <iostream>
using namespace std;

int binarySearch(int[] A, int low, int high, int x){
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (x == A[mid]) {
        return mid;
    }
    else if (x < A[mid]) {
        return binarySearch(A, low,  mid - 1, x);
    }
    else {
        return binarySearch(A, mid + 1,  high, x);
    }
}

int main(){
    binarySearch({1,2,3,4},1,4,3);
}
