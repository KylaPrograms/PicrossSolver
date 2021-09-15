#include "PicrossLine.h"

std::ostream& operator<<(std::ostream& os, const PicrossLine& pl)
{
	if (&pl.SquaresInLine)
	{
		for (std::shared_ptr<PicrossSquare> sq : pl.SquaresInLine)
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

int PicrossLine::NumberSquaresUnsolved()
{
	int total = 0;

	if (!bDone)
	{
		for (std::shared_ptr<PicrossSquare> ps : SquaresInLine)
		{
			if (!ps->isFilled())
			{
				total += 1;
			}
		}
	}

	return total;
}

int PicrossLine::IntVectorTotal(std::vector<int>& vec)
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

int PicrossLine::IntVectorGreatestValue(std::vector<int>& vec)
{
	if (vec.size() > 0)
	{
		int greatestVal = 0;
		for (int num : vec)
		{
			if (num > greatestVal)
			{
				greatestVal = num;
			}
		}
	}

	std::cout << "ERROR: PicrossLine::IntVectorGreatestValue : vector has size of 0\n";
	return 0;
}

PicrossLine::PicrossLine(int lineLength) :
	SquaresInLine(lineLength)
{
}

void PicrossLine::AssignSquareInLine(int index, std::shared_ptr<PicrossSquare>& sq)
{
	if (index >= 0 && index < SquaresInLine.size())
	{
		if (!SquaresInLine[index])
		{
			SquaresInLine[index] = sq;
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

void PicrossLine::SetClueNumbers(std::vector<int>& clueNums)
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
		for (std::shared_ptr<PicrossSquare> ps : SquaresInLine)
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

void PicrossLine::SolveLine()
{
	if (MinLineLength() > SquaresInLine.size())
	{
		std::cout << "ERROR: PicrossLine::SolveLine : clue numbers don't add up\n";

		return;
	}
	else
	{
		// fill in the entire line if the minimum line length needed by the ClueNumbers is equal to the amound of squares in the line
		if (MinLineLength() == SquaresInLine.size())
		{
			int ClueNumIndex = 0;
			int SquaresToFill = ClueNumbers[ClueNumIndex];
			for (std::shared_ptr<PicrossSquare> sq : SquaresInLine)
			{
				if (SquaresToFill > 0)
				{
					sq->Fill();
					SquaresToFill -= 1;
				}
				else
				{
					sq->Block();
					ClueNumIndex += 1;
					SquaresToFill = ClueNumbers[ClueNumIndex];
				}
			}

			bDone = true;
		}
		// if there is any possible overlap when trying to solve the line from one end or the other, fill in as many squares as possible
		else if ((SquaresInLine.size() - MinLineLength()) < IntVectorGreatestValue(ClueNumbers))
		{

		}
	}
}
