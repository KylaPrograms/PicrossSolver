#include <iostream>

#include "PicrossGrid.h"

int main()
{
	PicrossGrid Test1(5, 7);
	Test1.SetClueNumbersForRow(1, { 1, 3, 1 });

	std::cout << Test1 << std::endl;
}