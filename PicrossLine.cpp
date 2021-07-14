#include "PicrossLine.h"

std::ostream& operator<<(std::ostream& os, const PicrossLine& pl)
{
	if (&pl.SquaresInLine)
	{
		for (PicrossSquare* sq : pl.SquaresInLine)
		{
			os << *sq;
		}
	}
	else
	{
		os << "ERROR: PicrossLine : nullpointer\n";
	}
	
	return os;
}

int PicrossLine::IntVectorTotal(std::vector<int> vec)
{
	int total = 0;
	if (vec.size() > 0)
	{
		for (int num : vec)
		{
			total += num;
		}
	}

	return total;
}

int PicrossLine::NumberSquaresUnsolved()
{
	int total = 0;

	if (!bDone)
	{
		for (PicrossSquare* ps : SquaresInLine)
		{
			if (!ps->isFilled())
			{
				total += 1;
			}
		}
	}

	return total;
}

PicrossLine::PicrossLine(int lineLength) :
	SquaresInLine{ lineLength }
{
}

void PicrossLine::AssignSquareInLine(int index, PicrossSquare sq)
{
	if (index >= 0 && index < SquaresInLine.size())
	{
		if (!SquaresInLine[index])
		{
			SquaresInLine[index] = &sq;
		}
		else
		{
			std::cout << "ERROR: PicrossLine::AssignSquareInLine : square already exists\n";
		}
	}
	else
	{
		std::cout << "ERROR: PicrossLine::AssignSquareInLine : invalid index\n";
	}
}

void PicrossLine::SetClueNumbers(std::vector<int> clueNums)
{
	if (IntVectorTotal(clueNums) + clueNums.size() - 1 <= SquaresInLine.size())
	{
		ClueNumbers = clueNums;
	}
	else
	{
		std::cout << "ERROR: PicrossLine::SetClueNumbers : clue numbers don't add up\n";
	}
}

bool PicrossLine::isFilled()
{
	if (!bDone)
	{
		for (PicrossSquare* ps : SquaresInLine)
		{
			if (!ps->isFilled())
			{
				return false;
			}
		}

		bDone = true;
	}

	return true;
}

int PicrossLine::MinLineLength()
{
	return IntVectorTotal(ClueNumbers) + ClueNumbers.size() - 1;
}
