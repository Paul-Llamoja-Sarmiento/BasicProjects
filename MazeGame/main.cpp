#include <iostream>
#include "Player.h"
#include "GameMap.h"
#include "MapCell.h"

int main()
{
	Player Hero;
	GameMap Map;
  
	Map.draw_intro();

	while(Map.is_game_over() == false)
	{
		system("clear");
		Map.draw_map();
		Hero.call_input();

		if(Map.is_new_level(Hero.get_x() , Hero.get_y()))
		Hero.reset_position();
		
		else if(Map.set_player_cell(Hero.get_x() , Hero.get_y()))
		Hero.last_position();
	}
  
  return 0;
}
