#include "GameMap.h"
#include <iostream>
#include <fstream>
#include <string>


GameMap::GameMap()
  : gameOver{false} , level{1} , PlayerCell{nullptr}
{
	load_map_from_file();
	PlayerCell = &Cells[1][1];
	PlayerCell->id = 'H';
}


void GameMap::draw_map()
{
	for(int i{} ; i < 15 ; i++)
	{
		for(int j{} ; j < 15 ; j++)
			std::cout << Cells[i][j].id;
		
		std::cout << std::endl;
	}
}


bool GameMap::is_new_level(int xVal , int yVal)
{
	if(Cells[yVal][xVal].id == '$')
	{
		if(level < 3)
		{
			system("clear");
			level++;
			load_map_from_file();
			PlayerCell = &Cells[1][1];
			PlayerCell->id = 'H';
		} 

		else
		{
			system("clear");
			draw_victory();
			gameOver = true;
		}

		return true;      
		}

	else
		return false;
}


bool GameMap::set_player_cell(int xValue , int yValue)
{
  	if(Cells[yValue][xValue].is_blocked() == false)
  	{
    		if(PlayerCell != nullptr)
      			PlayerCell->id = ' ';
    
      		PlayerCell = &Cells[yValue][xValue];
      		PlayerCell->id = 'H';

    		return false;
  	}
  
  	else
      		return true;   
}


void GameMap::draw_intro()
{
  	std::string line;
  	std::ifstream myFile("intro.txt");
  
  	if(myFile.is_open())
  	{
      		while(std::getline(myFile , line))
          		std::cout << line << std::endl;
      
      		std::cin >> line;
      		system("clear");
  	}

	else
	{
		std::cout << "FATAL ERROR: INTRO COULD NOT BE LOADED!!" << std::endl;
		gameOver = true;
	}
}


void GameMap::draw_victory()
{
  	std::string line;
  	std::ifstream myFile("victory.txt");
  
  	if(myFile.is_open())
  	{
      		while(std::getline(myFile , line))
          		std::cout << line << std::endl;

      		std::cin >> line;
      		system("clear");
  	}

	else
	std::cout << "FATAL ERROR: VICTORY COULD NOT BE LOADED!!" << std::endl;
}


void GameMap::load_map_from_file()
{
	std::ifstream myFile;

	switch(level)
	{
		case 1:
			myFile.open("level1.txt");
			break;
		case 2:
			myFile.open("level2.txt");
			break;
		case 3:
			myFile.open("level3.txt"); 
			break;
		default:
			break;
	}

	std::string line;
	int row{};
  
	if(myFile.is_open())
	{
		while(std::getline(myFile , line))
		{
			for(size_t c{} ; c < line.length() ; c++)
				Cells[row][c].id = line[c];

			row++;
		}
	}

  	else
	{
      		std::cout << "FATAL ERROR: MAP FILE COULD NOT BE LOADED!!" << std::endl;
      		gameOver = true;
  	}
}


bool GameMap::is_game_over()
{
  	return gameOver;
}
