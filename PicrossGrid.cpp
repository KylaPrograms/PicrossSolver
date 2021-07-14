#include "PicrossGrid.h"

PicrossGrid::PicrossGrid(int rowAmount, int columnAmount) :
	GridOfSquares{ rowAmount, std::vector<PicrossSquare>(columnAmount, PicrossSquare()) },
	Rows{ rowAmount, new PicrossLine(columnAmount) },
	Columns{ columnAmount, new PicrossLine(rowAmount)}
{
	for (int row = 0, col = 0; row < GridOfSquares.size() && col < GridOfSquares[row].size(); ++row, ++col)
	{
		Rows[row]->AssignSquareInLine(col, GridOfSquares[row][col]);
		Columns[col]->AssignSquareInLine(row, GridOfSquares[row][col]);
		
	}

	GridOfSquares[0][2].Fill();
}

void PicrossGrid::SetClueNumbersForRow(int rowNumber, std::vector<int> clueNums)
{
	Rows[rowNumber]->SetClueNumbers(clueNums);
}

void PicrossGrid::SetClueNumbersForColumn(int colNumber, std::vector<int> clueNums)
{
	Columns[colNumber]->SetClueNumbers(clueNums);
}

std::ostream& operator<<(std::ostream& os, const PicrossGrid& pg)
{
	if (&pg.GridOfSquares)
	{
		for (int row = 0; row < pg.GridOfSquares.size(); ++row)
		{
			for (int col = 0; col < pg.GridOfSquares[row].size(); ++col)
			{
				os << pg.GridOfSquares[row][col];
			}
			os << "\n";
		}
	}
	else
	{
		os << "ERROR: PicrossGrid : grid nullpointer\n";
	}

	return os;
}
