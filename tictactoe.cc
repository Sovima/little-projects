#include <vector>
#include <iostream>
#include "table.h"
using namespace std;


int main () {
	cout << "table";
	Table table;
	int won{ 0 };
	vector<char> moves{ 'O', 'X' };
	while ( won == 0 ) {
		for ( auto move : moves ) {
			cout << "The table" << endl;
			table.printTable();
			won = table.makeMove( move );
			if ( won == 2) { 
				return 1; 
			} else if ( won == 1 && move == 'O') { 
				cout << "Player1 won!" << endl;
			} else if ( won == 1 ) {
				cout << "Player2 won!" << endl;
			}
		}
	}

}
