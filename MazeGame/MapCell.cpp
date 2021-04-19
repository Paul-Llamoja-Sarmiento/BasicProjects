#include "MapCell.h"

MapCell::MapCell()
        : id {' '}
{
}

bool MapCell::is_blocked()
{
	if(id == '*')
		return true;

	else
		return false;
}
