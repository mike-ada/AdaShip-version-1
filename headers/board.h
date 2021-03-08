#pragma once


enum states { Available, Occupied };

struct udtile {
	int col;
	int row;
	int idx;
	states state;
};


class board {
	public:
		board(); //constructor

		void initboard(int w, int h);
		void render();

		int setboardtile_state(std::string coordinate, states state);
		udtile getboardtile(std::string coordinate);

		void nexttile(std::string coordinate);

	protected:

	private:	
		int tileindex(std::string coordinate, bool rowtobasezero = true);
		int setboardtile_state(int idx, states state);
		udtile getboardtile(int idx);

		std::vector<udtile> _tile;
		int _boardwidth;
		int _boardheight;

};