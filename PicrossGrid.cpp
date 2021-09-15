#include "PicrossGrid.h"

PicrossGrid::PicrossGrid(int columnAmount, int rowAmount) :
	GridOfSquares(rowAmount, RowOfPicrossSquares(columnAmount)),
	Rows(rowAmount),
	Columns(columnAmount)
{
	int row = 0, col = 0;
	for (; row < GridOfSquares.size(); ++row)
	{
		Rows[row] = std::make_shared<PicrossLine>(columnAmount);
		for (; col < GridOfSquares[row].size(); ++col)
		{
			Columns[col] = std::make_shared<PicrossLine>(rowAmount);
			GridOfSquares[row][col] = std::make_shared<PicrossSquare>();

			//Rows[row]->AssignSquareInLine(col, GridOfSquares[row][col]);
		}
		col = 0;
	}
}

void PicrossGrid::SetClueNumbersForRow(int rowNumber, std::vector<int>& clueNums)
{
	if (rowNumber > 0 && rowNumber < Rows.size())
	{
		Rows[rowNumber]->SetClueNumbers(clueNums);
	}
}

void PicrossGrid::SetClueNumbersForColumn(int colNumber, std::vector<int>& clueNums)
{
	if (colNumber > 0 && colNumber < Rows.size())
	{
		Columns[colNumber]->SetClueNumbers(clueNums);
	}
}

void PicrossGrid::Solve()
{
	for (std::shared_ptr<PicrossLine> pl : Rows)
	{
		pl->SolveLine();
	}
}

std::ostream& operator<<(std::ostream& os, const PicrossGrid& pg)
{
	for (int row = 0; row < pg.GridOfSquares.size(); ++row)
	{
		for (int col = 0; col < pg.GridOfSquares[row].size(); ++col)
		{
			os << *pg.GridOfSquares[row][col];
		}
		os << "\n";
	}

	return os;
}
