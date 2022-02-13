#include <vector>


class Table {
	std::vector<std::vector<char>> table;
	bool threeRow( char c );
	public:
		int makeMove( char c );
		void printTable();
		Table();
};