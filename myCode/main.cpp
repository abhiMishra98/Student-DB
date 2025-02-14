// Standard (system) header files
#include <iostream>
#include <cstdlib>

#include "StudentDB.h"
#include "SimpleUI.h"
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
// #include "CFraction.h"

// Main program
int main()
{
	std::cout.setf(std::ios::unitbuf);
	StudentDB db;
	SimpleUI screen(db);

	int terminate;
	do
	{
		terminate = screen.run();
	} while (terminate != 0);
	return 0;
}
