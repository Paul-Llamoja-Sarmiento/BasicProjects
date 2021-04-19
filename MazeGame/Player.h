#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
    
	Player();
	void call_input();
	int get_x();
	int get_y();
	void last_position();
	void reset_position();
    
private:
	int x , y;
	int lastX , lastY;

};

#endif // PLAYER_H
