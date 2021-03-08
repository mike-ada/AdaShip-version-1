#include "headers/adaship.h" //include adaship headers

//https://www.rapidtables.com/code/text/unicode-characters.html


const int width = 5;
const int height = 5;

board board;

int main() {

	std::string coordinate;
	int i, col, row;
	udtile tile;

	board.initboard(width, height);
	
	coordinate = "A1";
	board.setboardtile_state(coordinate, Occupied);
	board.render();

	tile = board.getboardtile(coordinate);
	std::cout << "\ntile " << coordinate << ", col: " << tile.col << ", row: " << tile.row << ", idx: " << tile.idx << ", state: " << tile.state;

	board.nexttile(coordinate);

	common_randomselect(0, 10, true);

}