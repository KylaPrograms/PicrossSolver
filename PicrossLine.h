#pragma once
#include <vector>
#include "PicrossSquare.h"

class PicrossLine
{
	// why doesn't PicrossGrid get thsi?
	public:
		/// <summary>
		/// 
		/// </summary>
		typedef std::vector<std::shared_ptr<PicrossSquare>> RowOfPicrossSquares;

	private:
		/// <summary>
		/// Vector to hold references to all the squares in the line
		/// </summary>
		RowOfPicrossSquares SquaresInLine;

		/// <summary>
		/// The numbers given as clues to which squares need to be filled
		/// </summary>
		std::vector<int> ClueNumbers;

		/// <summary>
		/// Whether or not the line has been filled/solved
		/// </summary>
		bool bDone = false;

		/// <summary>
		/// Counts and returns how many squares have not been filled
		/// </summary>
		/// <returns> The number of squares in the line that are not filled/solved </returns>
		int NumberSquaresUnsolved();

		/// <summary>
		/// Computes the total of all the values in a given Int Vector
		/// </summary>
		/// <param name="vec"> The vector to be totaled </param>
		/// <returns> The total of the values in the given Int Vector </returns>
		int IntVectorTotal(std::vector<int>& vec);

		/// <summary>
		/// Gets and returns the largest value from a given Int Vector
		/// </summary>
		/// <param name="vec"> The vector from which the greatest value is desired </param>
		/// <returns> The largest value in the provided vector </returns>
		int IntVectorGreatestValue(std::vector<int>& vec);

	public:
		friend std::ostream& operator <<(std::ostream& os, const PicrossLine& pl);

		PicrossLine(int lineLength);

		/// <summary>
		/// Sets the PicrossSquare* at given index to point to the PicrossSquare provided
		/// </summary>
		/// <param name="index"> The index in SquaresInLine that should be used </param>
		/// <param name="sq"> The square that the PicrossSquare* should point to </param>
		void AssignSquareInLine(int index, std::shared_ptr<PicrossSquare>& sq);

		/// <summary>
		/// Sets the values in ClueNumbers
		/// </summary>
		/// <param name="clueNums"> The numbers to be added </param>
		void SetClueNumbers(std::vector<int>& clueNums);

		/// <summary>
		/// Returns whether the line is filled/solved
		/// </summary>
		/// <returns> True if the line is filled/solved </returns>
		bool isFilled();

		/// <summary>
		/// Computes the minimum amount of consecutive squares needed to be filled based on ClueNumers
		/// </summary>
		/// <returns> The minimum length of consecutive squares needed based on ClueNumbers </returns>
		int MinLineLength();

		/// <summary>
		/// Fills in the line as much as possible
		/// </summary>
		void SolveLine();
};

