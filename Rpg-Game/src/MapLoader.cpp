#include "MapLoader.h"

#include<fstream>
#include<string>
using namespace std;

void MapLoader::Load(string filename)
{
	string line;
	ifstream file(filename);

	bool isMapValid = false;

	if (file.is_open()) {
		while (getline(file, line)) {

			if (!isMapValid) {
				if (line == "[Map]") {
					isMapValid = true;
					continue;
				}
				else {
					cout << "Map not valid!";
					break;
				}
			}
			if (isMapValid) {
				int count = line.find('=');
				string var = line.substr(0, count);
				string value = line.substr(count + 1, line.length() - count);
				cout << var << endl;
				cout << value << endl;
				break;
			} 
		}
		file.close();
	}
	else {
		cout << "Unable to open file" << endl;
	}
	
	file.close();
}
