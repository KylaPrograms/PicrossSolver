#pragma once
#include <iostream>

enum class ESQUARESTATE
{
	
	Unknown,
	Blocked,
	Filled
};

class PicrossSquare
{
	private:
		/// <summary>
		/// 
		/// </summary>
		ESQUARESTATE CurrentState = ESQUARESTATE::Unknown;

	public:
		friend std::ostream& operator <<(std::ostream& os, const PicrossSquare& ps);

		PicrossSquare() {};

		/// <summary>
		/// 
		/// </summary>
		void Fill() { CurrentState = ESQUARESTATE::Filled; }

		/// <summary>
		/// 
		/// </summary>
		void Block() { CurrentState = ESQUARESTATE::Blocked; }

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		bool isFilled() { return CurrentState == ESQUARESTATE::Filled || CurrentState == ESQUARESTATE::Blocked; }
};

