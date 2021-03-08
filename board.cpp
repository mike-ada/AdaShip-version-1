#include "headers/adaship.h"


board::board() { //constructor function
};


void board::render() {
	//render the object's board
	std::string colour = C_CYAN;
	std::string colref;
	int idx = 0;

	//add column reference lables A, B, C..
	for(int row = 0; row < 2; row++) {
		std::cout << "\n";
		std::cout << colour << " " << std::setw(3) << " " << C_RESET;
		for(int col = 0; col < _boardwidth; col++) {
			if(row == 0) {
				colref = coordinates_indextocolref(col);
				std::cout << colour << "\t" << std::setw(2) << colref << C_RESET;
			} else {
				std::cout << colour << "\t" << "\u2501\u2501\u2501" << C_RESET;
			}
		}
	}

	//add row labels (0, 1, 2..) and board values
	for(int row = 0; row < _boardheight; row++) {
		std::cout << "\n";
		std::cout << colour << " " << std::setw(3) << (row+1) << "\u2503" << C_RESET;
		for(int col = 0; col < _boardwidth; col++) {
			idx = coordinates_getindex(col, row, _boardwidth);
			std::cout << "\t" << std::setw(2) << _tile[idx].state;
		}
	}
	std::cout << "\n";

}


void board::nexttile(std::string coordinate) {
	//at the moment, this is a bit of a hack to find max space availble on column and row
	//could be used to see if a boat could be positioned ??
	int idx = tileindex(coordinate); //convert the coordinate reference to an index
	int col = _tile[idx].col; //get the column value for the indexed tile
	int row = _tile[idx].row; //get the row value for the indexed tile
	int max_width = 0; //set a count
	int max_length = 0;

	for(int c = (col + 1); c < _boardwidth; c++) { //loop through each column to the end of the board
		int i = coordinates_getindex(c, row, _boardwidth); //find next tile on same column 
		if(_tile[i].state == states::Available) { //is the tile 'available'
			max_width++; //essentially a base 1 value indicating how many available tiles exists to the right of the tile
		} else {
			break;
		}
	}

	for(int r = (row + 1); r < _boardheight; r++) { //loop through each row to the end of the board
		int i = coordinates_getindex(col, r, _boardheight); //find next tile on same row 
		if(_tile[i].state == states::Available) { //is the tile 'available'
			max_length++; //essentially a base 1 value indicating how many available tiles exists below the tile 
		} else {
			break;
		}
	}

	std::cout << "\n" << coordinate << " available to the left: " << max_width;
	std::cout << "\n" << coordinate << " available to the below: " << max_length;

}


int board::tileindex(std::string coordinate, bool rowtobasezero) {
	//convert board coordinate to tile index; used to convert "A1.." to tile index
	udtboardreference boardreference;	
	boardreference = coordinates_extractcoordinate(coordinate); //break coordinate (A1 to 'A' and '1')

	int col = coordinates_colreftoindex(boardreference.colref); //convert colref (A..Z) to column index
	int row = rowtobasezero ? boardreference.rowref - 1: boardreference.rowref; //update rowref if base 0
	int idx = coordinates_getindex(col, row, _boardwidth); //convert column and row to index 

	//std::cout << "\ncoordinate: " << coordinate << " col: " << col << ", row: " << row << ", idx: " << idx;

	return idx;
}


udtile board::getboardtile(int idx) {
	//return the specified tile
	return _tile[idx];
}


udtile board::getboardtile(std::string coordinate) {
	//overloaded wrapper to return the specified tile based on board coordinate values
	int idx = tileindex(coordinate);
	return getboardtile(idx);
}


int board::setboardtile_state(int idx, states state) {
	//update board tile based on base 0 index value
	_tile[idx].state = state;
	return 0;
}


int board::setboardtile_state(std::string coordinate, states state) {
	//overloaded wrapper to update tile based on board coordinate values (A0)
	int idx = tileindex(coordinate);
	return setboardtile_state(idx, state);
}


void board::initboard(int w, int h) {
	//set and initialise a board based on the width and height
	
	_boardwidth = w; //set the width and height
	_boardheight = h;

	udtcoord coord;
	for (int idx = 0; idx < (_boardwidth * _boardheight); idx++) {
		coord = coordinates_getcolrow(idx, _boardwidth);
			_tile.push_back({
			coord.col,
			coord.row,
			idx,
			Available
		});
	}
};