#pragma once
#include <vector>
#include "PicrossSquare.h"
#include "PicrossLine.h"

class PicrossGrid
{
	private:
		/// <summary>
		/// 
		/// </summary>
		typedef std::vector<std::shared_ptr<PicrossSquare>> RowOfPicrossSquares;

		/// <summary>
		/// 
		/// </summary>
		typedef std::vector<RowOfPicrossSquares> GridOfPicrossSquares;

		/// <summary>
		/// 
		/// </summary>
		GridOfPicrossSquares GridOfSquares;

		/// <summary>
		/// 
		/// </summary>
		std::vector<std::shared_ptr<PicrossLine>> Rows, Columns;

	public:
		friend std::ostream& operator <<(std::ostream& os, const PicrossGrid& pg);

		PicrossGrid(int rowAmount, int columnAmount);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rowNumber"></param>
		/// <param name="clueNums"></param>
		void SetClueNumbersForRow(int rowNumber, std::vector<int>& clueNums);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="colNumber"></param>
		/// <param name="clueNums"></param>
		void SetClueNumbersForColumn(int colNumber, std::vector<int>& clueNums);

		void Solve();
};

