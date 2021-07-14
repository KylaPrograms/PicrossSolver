#pragma once
#include <vector>
#include "PicrossSquare.h"

class PicrossLine
{
	private:
		/// <summary>
		/// Vector to hold references to all the squares in the line
		/// </summary>
		std::vector<PicrossSquare*> SquaresInLine;

		/// <summary>
		/// The numbers given as clues to which squares need to be filled
		/// </summary>
		std::vector<int> ClueNumbers;

		/// <summary>
		/// Whether or not the line has been filled/solved
		/// </summary>
		bool bDone = false;

		/// <summary>
		/// Computes the total of all the values in a given Int Vector
		/// </summary>
		/// <param name="vec"> The vector to be totaled </param>
		/// <returns> The total of the values in the given Int Vector </returns>
		int IntVectorTotal(std::vector<int> vec);

		/// <summary>
		/// Counts and returns how many squares have not been filled
		/// </summary>
		/// <returns> The number of squares in the line that are not filled/solved </returns>
		int NumberSquaresUnsolved();

	public:
		friend std::ostream& operator <<(std::ostream& os, const PicrossLine& pl);

		PicrossLine(int lineLength);

		/// <summary>
		/// Sets the PicrossSquare* at given index to point to the PicrossSquare provided
		/// </summary>
		/// <param name="index"> The index in SquaresInLine that should be used </param>
		/// <param name="sq"> The square that the PicrossSquare* should point to </param>
		void AssignSquareInLine(int index, PicrossSquare sq);

		/// <summary>
		/// Sets the values in ClueNumbers
		/// </summary>
		/// <param name="clueNums"> The numbers to be added </param>
		void SetClueNumbers(std::vector<int> clueNums);

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
};

