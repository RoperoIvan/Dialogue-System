#include "DialogTree.h"

using namespace std;

int main()
{
	Dialogue d;
	int id = 2;

	d.init();
	int rv;
	rv = d.performdialogue(id);

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