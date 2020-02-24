#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

// helper functions

int gcd(int a, int b) {
    
    if(b == 0) return a;
    
    return gcd(b, a%b);
    
}

int main(int argc, char *argv[]) {
    
    int size = atoi(argv[1]);
    int **a = new int*[size];
    
    // initialize matrix
    for(int i = 0; i < size; i++) {
        
        a[i] = new int[size];
        
        
        for(int j = 0; j < size; j++) {
            a[i][j] = 0;
        }
    }
    
    
    // init 1s position to 1
    for(int i = 1; i < size; i++) {
        a[i][1] = 1;
        a[1][i] = 1;
    }
    
    // solve gcd from 2 - size
    for(int i = 2; i < size; i++) {
        for(int j = 2; j < size; j++) {
            
            int b = gcd(i,j);
            
            if(b == 1) {
                a[i][j] = 1;
            }
            
            
        }
    }
    
    
    // print out matrix
    cout << size << endl;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
