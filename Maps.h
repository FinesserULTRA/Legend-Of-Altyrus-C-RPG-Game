#pragma once    

#include "STLIB.h"
#include "Global.h"

static vector<vector<string>> cityMap;
static vector<vector<string>> knightsTemenos;
static vector<vector<string>> playerKnight;
static vector<vector<string>> DrakonHold;
static vector<vector<string>> Drakon_playerMap;
static vector<vector<string>> playerMap;
static vector<vector<string>> Map;

// Function to read the ASCII map from a text file and store it in a 2D vector of strings
inline vector<vector<string>> readMapFromFile(const string filename) {
	vector<vector<string>> map;

	// Open the file
	ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << "Error: Unable to open file " << filename << std::endl;
		return map;  // Return an empty map
	}

	// Read the file line by line and store characters in the vector of strings
	std::string line;
	while (std::getline(file, line)) {
		std::vector<std::string> row;

		size_t startPos = line.find_first_not_of(" \t\r\n\v\f\??");

		for (char ch : line) {
			if (ch == ',') {
				ch = ' ';
			}
			else if (ch == '\'') {
				ch = ' ';
			}
			else if (ch == '.') {
				ch = ' ';
			}
			else if (ch == '*') {
				ch = 'M';
			}

			else if (ch == '+') {
				ch = 'M';
			}
			
			row.push_back(std::string(1, ch));
		}

		map.push_back(row);
	}

	// Close the file
	file.close();

	return map;
}



static void displayMap(const vector<vector<string>> map) {


	cout << "\n\n";
	for (int i = 0; i < map.size(); ++i) {
		cout << "[";
		for (int j = 0; j < map[i].size(); ++j) {
			if (i == hero.yPos && j == hero.xPos) {
				cout << "P";
			}
			else {
				cout << map[i][j];
			}
		}
		cout << "]\n";
	}
}

static void getMaps()
{

	string Drakon_Hold = "Drakon Hold.txt";



	// Read the ASCII map from the file
	cityMap = readMapFromFile("City.txt");
	playerMap = readMapFromFile("Player City.txt");
	knightsTemenos = readMapFromFile("Knights Temenos.txt");
	playerKnight = readMapFromFile("Player Knights Temenos.txt");
	DrakonHold = readMapFromFile("Drakon Hold.txt");
	Drakon_playerMap = readMapFromFile("PlayerDrakon.txt");
	
	Map = cityMap;

	system("cls");
	displayMap(playerMap);
	system("pause");
	system("cls");
	displayMap(playerKnight);
	system("pause");
	system("cls");
	displayMap(Drakon_playerMap);
	system("pause");
	system("cls");

	//displayMap(Map);*/

	hero.xPos = 34;
	hero.yPos = 4;
}
