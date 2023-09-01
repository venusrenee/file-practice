#include <iostream>
#include <fstream>
#include <string>
#ifdef __unix
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),(mode)))==NULL
#endif

using namespace std;

int main() {
	FILE* f;
	fopen_s(&f, "ncaa_champions.csv", "r");
	char line[150];
	string school;
	string school_input;
	cout << "Please enter school name: ";
	cin >> school_input;
	while (true) {
		school.clear();
		fgets(line, 150, f);
		if (feof(f)) {
			break;
		}
		int i = 0;
		while ((line[i] != ',') && (line[i] != '\n')) {
			school.push_back(line[i]);
			i = i + 1;
		}
		if (school == school_input) {
			cout << school_input << ' ';
			cout << line[i + 1] << line[i + 2] << line[i + 3] << line[i + 4] << "\n";
		}
	}
        return 0;
    }