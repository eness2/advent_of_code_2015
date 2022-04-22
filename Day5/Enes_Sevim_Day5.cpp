#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	string inputs;
	string control;
	// part1
	// bool twice, vowels ,ae;
	bool twice ,repeat;
	int nice = 0;
	fstream newfile;
	newfile.open("input.txt", ios::in);
	if (newfile.is_open()) {
		while (getline(newfile, inputs)) {
			/* part1 
			
			int count = 0;
			vowels = false;
			twice = false;
			ae = true;
			for (int i = 0; i < 16; i++) {
				control = inputs[i];
				control.push_back(inputs[i + 1]);
				if (control == "ab" || control == "cd" || control == "pq" || control == "xy") 
					ae = false;
				if (control[0] == control[1])
					twice = true;
				if (inputs[i] == 'a' || inputs[i] == 'e' || inputs[i] == 'i' || inputs[i] == 'o' || inputs[i] == 'u') {
					count++;
					if (count == 3) 
						vowels = true;
				}
			}
			if (twice && vowels && ae) 
				nice++;

			*/

			// part2
			twice = false;
			repeat = false;
			for (int i = 0; i < 15; i++) {
				control = inputs[i];
				control.push_back(inputs[i + 1]);
				if (inputs[i] == inputs[i + 2]) {
					repeat = true;
				}
				for (int j = i + 2; j < 15; j++) {
					if (control[0] == inputs[j] && control[1] == inputs[j + 1])
						twice = true;
				}
			}
			if (twice && repeat)
				nice++;
		}
	}
	cout << "nicu stringu : " << nice << endl;
	system("pause");
	return 0;
}