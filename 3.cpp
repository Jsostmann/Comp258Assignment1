#include <iostream>
#include <fstream>
#include"cstdlib"
#include <string>
using namespace std;


bool hasCycle(int u, char** matrix, bool* visited, int parent, int size) {
    
    visited[u] = true;
    
    for(int v = 0; v < size; v++) {
        
        if(matrix[u][v] == '1') {
            
            if(visited[v] == false) {
                
                if(hasCycle(v,matrix,visited,u,size)) {
                    
                    return true;
                }
                
            } else if(v != parent) {
                
                return true;
            }
        }
    }
    return false;
}
bool isTree(char**a, bool* visited, int size) {
    if(hasCycle(0, a, visited, -1, size))
        return false;
    
    for(int i = 0; i < size; i++) {
        if(!visited[i])
            return false;
    }
    return true;
}

int main () {
    string line;
    ifstream myfile ("graph.txt");
    int size;
    char** matrix;
    
    if (myfile.is_open()) {
        
        if(getline(myfile,line)) {
            
            size = line[0] - '0';
            cout << size;
            matrix = new char *[size];
            
            for (int i = 0; i < size; i++) {
                matrix[i] = new char[size];
            }
            
            for(int i = 0; i < size; i++) {
                
                getline(myfile,line);
                for(int j = 0; j < size; j++) {
                    
                    matrix[i][j] = line[j];
                    cout << line[j];
                }
                
                cout << endl;
            }
            
            bool* visited = new bool[size];
            for(int i = 0; i<size; i++) {
                visited[i] = false;
            }
            
           bool val = isTree(matrix,visited,size);
            
            if(val) {
                cout << "Tree" << endl;
            } else {
                cout << "Not Tree" << endl;
            }
            
        }
        
        
        myfile.close();
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Unable to open file";
        
    }
    
    
    return 0;
}
