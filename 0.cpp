#include<iostream>
#include"cstdlib"
#include"stack.cpp"
using namespace std;

int main(int argc, char *argv[]) {
    
    stack<int> save(argc);
    
    for(int i = 1; i < argc; i++) {
        
        string param = string(argv[i]);
        
        if (param == "+") {
            
            save.push(save.pop() + save.pop());
            
        } else if (param == "-") {
            
            save.push((-1) * (save.pop() - save.pop()));
            
        } else if (param == "/") {
            
            int l = save.pop();
            save.push(save.pop() / l);
            
        } else if (param == "*") {
            
            save.push(save.pop() * save.pop());
            
        } else {
            
            int my_integer = atoi(argv[i]);
            save.push(my_integer);
            
        }
        
    }
    
    cout << save.pop() << endl;
    return 0;
    
    /*
    char *a = argv[1];
    int i, div, N = strlen(a);
    stack<int> save(N);
    
    for(i = 0; i<N; i++) {
        if(a[i] == '+')
            save.push(save.pop() + save.pop());
        if(a[i] == '*')
            save.push(save.pop() * save.pop());
        if(a[i] == '-')
            save.push((-1) * (save.pop() - save.pop()));
        if(a[i] == '/') {
            int l = save.pop();
            save.push(save.pop() / l);
        }
        
        if(a[i] >= '0' && a[i] <= '9')
            save.push(a[i] -'0');
    
            
        
    }
    cout << save.pop() <<endl;
     */
}
