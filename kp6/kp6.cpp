#include "kp6.h"


int main() {

	HashTable<int, int> table(100);

	// inserting elements:

	table.Insert(12, 13);
	table.Insert(232322, 13);
	table.Insert(1232, 13223);
	table.Insert(113, 32928);
	cout << "created table: \n";
	table.Output();
	cout << '\n';

	// finding value table[key]:

	int b = table[232322];
	cout << "\nelement table[232322] (232322 is a key):\n" << b << '\n';

	// searching elements:

	int a = table.Search(1232);
	cout << "\nelement with key_value = 1232: \n" << a << '\n';


	// deleting elements:

	table.Delete(13);
	cout << "\ntable with deleted elements = 13: \n";
	table.Output();
	cout << '\n';


	return 0;
}