#include <iostream>
#include <string>
#include "md5.h"
using namespace std;

int main(int argc, char* argv[]) {

	string secret_key = "bgvyzdsv";
	int i = 0;
	string control;
	
	while (1) {
		control = md5(secret_key + to_string(i));
		if ((control.substr(0, 5)!="00000")) {
			i++;
		}
		else {
			cout << secret_key + to_string(i)<<endl;
			break;
		}
	}
	//part 2 
	while (1) {
		control = md5(secret_key + to_string(i));
		if ((control.substr(0, 6) != "000000")) {
			i++;
		}
		else {
			cout << secret_key + to_string(i) << endl;
			break;
		}
	}
	cout <<"ae";
	system("pause");
	return 0;
}