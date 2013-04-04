#include <iostream>
#include "Player.h"
using namespace std;
void game() {
    cout << "My role: X or O:" << endl;
    char c;
    int role;
    int tmp;
    cin >> c;
    if (c == 'x' || c == 'X') {
        role = MAX;
        cout << "I am X now!" << endl;
    }
    else{
        role = MIN;
        cout << "I am O now!" << endl;
    }
    Player p(role);
    p.play();       
}

int main() {		
		game();
		return 0;
}
