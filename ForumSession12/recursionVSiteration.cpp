#include <iostream>
using namespace std;

int iteration(int n){
    int result = 1;
    for(int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}

int recursion(int n){
    if(n <= 1){
        return 1;
    }
    else{
        return n * recursion(n-1);
    }
}

int main(){
    int n;
    cout << "Enter a number to calculate its factorial: ";
    cin >> n;
    cout << "With iteration: " << iteration(n) << endl;
    cout << "With recursion: " << recursion(n) << endl;
}