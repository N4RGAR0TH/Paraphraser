#include <iostream>
#include "mheader.h"
using namespace std;
int main() {
	int option;
	cout << "1-upload text by input" << "\n" << "2-upload text by file" << "\n" << "3-exit" << "\n";
	cin >> option;
	switch (option)
	{
	case 1:
		inputUpload();
		break;
	case 2:
		fileUpload();
		break;
	case 3:
		break;
	default:
		cout << "not an option" << endl;
		main();
	}
	return 0;
}