#include "PicrossSquare.h"

std::ostream& operator<<(std::ostream& os, const PicrossSquare& ps)
{
	if (&ps)
	{
		switch (ps.CurrentState)
		{
		case ESQUARESTATE::Unknown:
			os << "?";
			break;
		case ESQUARESTATE::Blocked:
			os << "X";
			break;
		case ESQUARESTATE::Filled:
			os << "O";
			break;
		default:
			os << "ERROR: PicrossSquare : bad state\n";
		}
	}
	else
	{
		os << "ERROR: PicrossSquare : nullpointer\n";
	}
	

	return os;
}
