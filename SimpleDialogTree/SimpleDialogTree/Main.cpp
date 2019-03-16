#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include "DialogTree.h"

using namespace std;

int main()
{
	DialogTree d;

	d.init();
	int rv;
	rv = d.performdialogue();

	if (rv == 1)
	{
		cout << "You accepted the quest";
	}

	d.destroytree();

	cout << "Enter any key to continue...\n";
	int tmp;
	cin >> tmp;
	
	return 0;
}