#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int key;
    node *next;};

int main(int argc, char* argv[]){
    
    if(argc > 3) {
        int numPlayers = atoi(argv[1]);
        int m = atoi(argv[2]);
        int p = atoi(argv[3]);
        int i = 1;
        int turn = 1;
        
        node *head, *temp;
        head = new node;
        head->key = 1;
        temp = head;
        
        for(i = 2; i <= numPlayers; i++) {
            temp->next = new node;
            temp = temp->next;
            temp->key = i;
        }
        
        temp->next = head;
        
        while(temp != temp->next) {
            
            if(turn % 2 == 1) {
                cout << "odd" << endl;
                for(i = 1; i < m; i++) {
                    temp = temp->next;
                }
                
            } else {
                cout << "even" << endl;
                for(i = 1; i < p; i++) {
                    temp = temp->next;
                }
            }
            
            turn++;
            cout << temp->next->key<<" has dropped out "<< endl;
            head = temp->next;
            temp->next = head->next;
            delete head;
        }
        cout << "winner is " << temp->key << endl;
    }
    return 0;
}
