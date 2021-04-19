#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "MapCell.h"

class GameMap
{
public:
	GameMap();
	MapCell Cells[15][15];
	MapCell *PlayerCell; 
	bool is_game_over();
	
	void draw_map();
	void draw_intro();
	void draw_victory();
	bool set_player_cell(int xValue , int yValue);
	bool is_new_level(int xVal , int yVal);
    
private:
	void load_map_from_file();
	int level;
	bool gameOver;
};

#endif // GAMEMAP_H
