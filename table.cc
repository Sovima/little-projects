#include "table.h"
#include <iostream>
using namespace std;


void Table::printTable() {
	cout << "   1 2 3 " << endl;
	for ( int i = 1; i < 4; ++i ) {
		cout << i << " |";
		for ( int j = 0; j < 3; ++j ) { 
			cout << table[i - 1][j] << "|" ;
		}
		cout << endl;
		if ( i < 3 ) {
			cout << "  " << string(7, '-') << endl;
		}
	}
}

// Assume legal for now, might check later
int Table::makeMove( char c ) {
	cout << "Enter the next move (<row> <col>)" << endl;
	int row;
	int col;
	cin >> row;
	if ( cin.fail() ) { return 2; }
	cin >> col;
	if ( cin.fail() ) { return 2; }
	table[ row - 1 ][ col - 1 ] = c;
	return threeRow( c );
}

bool Table::threeRow( char c ) {
	bool ld = true;
	bool rd = true;
	for ( int i = 0; i < 3; ++i ) {
		bool r = true;
		bool l = true;
		ld = ld && table[i][i] == c;
		rd = rd && table[i][2 - i] == c;
		for ( int j = 0; j < 3; ++j ) { 
			r = r && table[i][j] == c;
			l = l && table[j][i] == c;
		}
		if ( r || l ) { return true; }
	}
	if ( ld || rd ) { return true; }
	return false;

}

Table::Table() {
	for ( int i = 0; i < 3; ++i) {
		vector<char> row = {' ', ' ', ' '};
		table.emplace_back( row );
	}
}
