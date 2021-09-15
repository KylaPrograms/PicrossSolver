#include <iostream>

#include "PicrossGrid.h"

int main()
{
	std::vector<int> clueNums(2);
	clueNums[0] = 1;
	clueNums[1] = 3;

	PicrossGrid Test1(5, 7);
	//Test1.SetClueNumbersForRow(3, clueNums);


	//Test1.SetClueNumbersForRow(3, { 1, 3 });
	//Test1.Solve();

	std::cout << Test1 << std::endl;
}