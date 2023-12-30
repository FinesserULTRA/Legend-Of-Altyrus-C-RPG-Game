//game.cpp

#pragma once

#include "STLIB.h"
#include "stories.cpp"

//function proto

static void handleSpecialCharacter(Player& player, string& newPosition, string& oldPosition, int& newPlayerX, int& newPlayerY);
static void clearScreen(Player& hero);
static bool isPositionValid(int x, int y);
static string MovePlayer(Player& player, char direction);
static string oldPosition, newPosition;

static int gridSize = 3240; //size of the map
static int viewWidth = 15, viewHeight = 20; //size of the map




//static vector<vector<string>> mapChoice = CityMap;

inline void order(map<string, int> bag) {

	std::cout << "\n";
	for (const auto& pair : bag) {
		std::cout << "- " << pair.first << " - " << pair.second << "\n";
	}
	std::cout << "\n";
}

inline void order(vector<string> bag)
{
	cout << "\n";
	for (int i = 0; i < bag.size(); i++) {
		cout << "- " << bag[i] << "\n";
	}
	cout << "\n";

}

inline void order(vector<Weapon> weapons)
{

	for (int i = 1; i < weapons.size(); i++) {
		cout << i << ") " << weapons[i].toString() << " ";
	}
	cout << endl;

}
inline void order(vector<Armor> armour)
{
	for (int i = 0; i < armour.size(); i++) {
		cout << i << ") " << armour[i].toString() << " ";
	}
	cout << endl;
}

inline void displayFullMap(vector<vector<string>> map)
{
	//system("cls"); // Clear the console (Windows specific)
	cout << "\n\n";
	for (int i = 0; i < map.size(); ++i) {
		cout << "[";
		for (int j = 0; j < map[i].size(); ++j) {
			cout << " ";
			if (i == hero.yPos && j == hero.xPos) {
				cout << "P";
			}
			else {
				cout << map[i][j];
			}
			cout << " ";
		}
		cout << "]\n";
	}
}

static void displayMapAround(std::vector<std::vector<std::string>>& map, int newPlayerX, int newPlayerY)
{
	int playerX = hero.xPos;
	int playerY = hero.yPos;

	int startX = max(0, playerX - viewWidth / 2);
	int startY = max(0, playerY - viewHeight / 2);
	int endX = min(static_cast<int>(map[0].size()), startX + viewWidth);
	int endY = min(static_cast<int>(map.size()), startY + viewHeight);

	if (endX - startX < viewWidth) {
		startX = max(0, endX - viewWidth);
	}
	if (endY - startY < viewHeight) {
		startY = max(0, endY - viewHeight);
	}

	cout << "\n\n";
	for (int y = startY; y < endY; ++y) {
		cout << "[";
		for (int x = startX; x < endX; ++x) {
			cout << " ";

			// Highlight the player position
			if (x == playerX && y == playerY) {
				cout << "P";
			}
			else {
				cout << map[y][x];
			}

			// Add space to separate characters
			cout << " ";
		}
		cout << "]\n";
	}
}


inline bool isPositionValid(int x, int y) {
	return x >= 0 && x < gridSize && y >= 0 && y < gridSize && (Map[y][x] != "_" && Map[y][x] != "|" && Map[y][x] != "B" && Map[y][x] != "+" && Map[y][x] != "|" && Map[y][x] != "*"
		&& Map[y][x] != "0" && Map[y][x] != "O" && Map[y][x] != "\\" && Map[y][x] != "/");
}





static string MovePlayer(Player& player, char direction) {
	int newPlayerX = player.xPos;
	int newPlayerY = player.yPos;

	switch (direction) {
	case 'w':
		newPlayerY--;
		newPosition = Map[newPlayerY][newPlayerX];

		break;
	case 's':
		newPlayerY++;
		newPosition = Map[newPlayerY][newPlayerX];

		break;
	case 'a':
		newPlayerX--;
		newPosition = Map[newPlayerY][newPlayerX];

		break;
	case 'd':
		newPlayerX++;
		newPosition = Map[newPlayerY][newPlayerX];


		break;
	default:
	{
		newPosition = Map[player.yPos][player.xPos];
		cout << "invalid input";
		break;
	}
	}

	oldPosition = Map[player.yPos][player.xPos];

	handleSpecialCharacter(player, newPosition, oldPosition, newPlayerX, newPlayerY);

	return newPosition;
}

void handleSpecialCharacter(Player& player, string& newPosition, string& oldPosition, int& newPlayerX, int& newPlayerY)
{

	//default movement
	if (newPosition == " ") {

		if (oldPosition == " ")
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[player.yPos][player.xPos] = " ";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "P";
		}
		else if (oldPosition == "~" && hero.ship)
		{
			Map[player.yPos][player.xPos] = "~";
			playerMap[player.yPos][player.xPos] = "~";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "P";
		}
		else if (oldPosition == "T" && hero.gameLevel == 1)
		{
			Map[player.yPos][player.xPos] = "T";
			playerMap[player.yPos][player.xPos] = "T";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "P";
		}
		else
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[player.yPos][player.xPos] = " ";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "P";
		}
	}
	else if (newPosition == "~" && hero.ship) {
		if (oldPosition == "~")
		{
			Map[player.yPos][player.xPos] = "~";
			playerMap[player.yPos][player.xPos] = "~";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "~";
		}
		else if (oldPosition == " ")
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[player.yPos][player.xPos] = " ";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "~";
		}
	}
	

	//check for gamelevel
	if (hero.gameLevel == 1) {
		//gamelevel 1 stuff, all the missions and quests are checked like dis
		if (newPosition == "T" && hero.sidequest_1_counter >= 4) {
			if (oldPosition == "T")
			{
				Map[player.yPos][player.xPos] = "T";
				playerMap[player.yPos][player.xPos] = "T";
				player.xPos = newPlayerX;
				player.yPos = newPlayerY;
				playerMap[player.yPos][player.xPos] = "T";
			}
			else if (oldPosition == " ")
			{
				Map[player.yPos][player.xPos] = " ";
				playerMap[player.yPos][player.xPos] = " ";
				player.xPos = newPlayerX;
				player.yPos = newPlayerY;
				playerMap[player.yPos][player.xPos] = "T";
			}
		}
		else if (newPosition == "x")
		{
			if (hero.cityAllow)
			{
				Map[player.yPos][player.xPos] = "x";
				playerMap[player.yPos][player.xPos] = " ";
				player.xPos = newPlayerX;
				player.yPos = newPlayerY;
				playerMap[player.yPos][player.xPos] = "P";
			}
			else
			{
				DisplayMsg("You dont have access to the city yet.\n");
				Map[newPlayerY][newPlayerX] = "x";
				playerMap[newPlayerY][newPlayerX] = "x";
				playerMap[player.yPos][player.xPos] = "P";
			}
		}
		else if (newPosition == "d") {
			if (oldPosition == "d")
			{
				Map[player.yPos][player.xPos] = "d";
				playerMap[player.yPos][player.xPos] = "d";
				player.xPos = newPlayerX;
				player.yPos = newPlayerY;
				playerMap[player.yPos][player.xPos] = "d";
			}
			else if (oldPosition == " ")
			{
				Map[player.yPos][player.xPos] = " ";
				playerMap[player.yPos][player.xPos] = " ";
				player.xPos = newPlayerX;
				player.yPos = newPlayerY;
				playerMap[player.yPos][player.xPos] = "d";
			}
		}
		else if (newPosition == "z" && hero.tuskar_alive == false) {

			Map[player.yPos][player.xPos] = " ";
			playerMap[player.yPos][player.xPos] = " ";
			Map[newPlayerY][newPlayerX] = " ";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "P";


		}
		if (newPosition == "0")
		{
			Map[player.yPos][player.xPos] = " ";

			playerMap[player.yPos][player.xPos] = "P";
			trader1(hero, newPlayerX, newPlayerY);

		}
		else if (newPosition == "1") {
			Map[newPlayerY][newPlayerX] = "1";
			newPosition = Map[newPlayerY][newPlayerX];
			playerMap[newPlayerY][newPlayerX] = "N";
			playerMap[player.yPos][player.xPos] = "P";
			story_1_1(player, newPlayerX, newPlayerY);
		}
		else if (newPosition == "C")
		{
			//newPosition = Map[newPlayerY][newPlayerX];
			Map[newPlayerY][newPlayerX] = "C";
			playerMap[newPlayerY][newPlayerX] = "C";
			playerMap[player.yPos][player.xPos] = "P";
			story_1_2(hero);
		}
		else if (newPosition == "2")
		{
			if (hero.sidequest_1 == true && hero.sideboss_1_alive) {
				Map[player.yPos][player.xPos] = " ";
				playerMap[player.yPos][player.xPos] = "P";
				playerMap[newPlayerY][newPlayerX] = "G";
				Boss_Battles_1(player, newPlayerX, newPlayerY);
				//player.xPos = newPlayerX;
				//player.yPos = newPlayerY;
			}
			else if (hero.sideboss_1_alive == false)
			{
				Map[player.yPos][player.xPos] = " ";
				playerMap[player.yPos][player.xPos] = "P";
				playerMap[newPlayerY][newPlayerX] = " ";
			}
		}
		else if (newPosition == ")")
		{
			if (hero.findItemInInventory("Prison Key"))
			{
				Map[player.yPos][player.xPos] = " ";
				playerMap[player.yPos][player.xPos] = "P";
				playerMap[newPlayerY][newPlayerX] = " ";
				
				displayMsg("Opening the gate...\n");
				hero.removeItemFromInventory("Prison Key");
				Map[newPlayerY][newPlayerX] = " ";
				hero.sidequest_1_counter++;
			}
			else
			{
				DisplayMsg("You need the prison key to open the prison door.\nThe key is probably with the goblin warrior\n");
			}
		}
		else if (newPosition == "3")
		{
			story_1_1(hero, newPlayerX, newPlayerY);
		}
		else if (newPosition == "D")
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[player.yPos][player.xPos] = "P";
			playerMap[newPlayerY][newPlayerX] = "D";
			DisplayMsg("You have found the dungeon.\n");
			dungeon(hero);

		}
		else if (newPosition == "4")
		{
			if (hero.sidequest_1 == true) {
				Map[player.yPos][player.xPos] = " ";
				playerMap[player.yPos][player.xPos] = "P";
				playerMap[newPlayerY][newPlayerX] = "B";
				Boss_Battles_1(player, newPlayerX, newPlayerY);

				
			}
			else if (hero.sideboss_1_1_alive == false)
			{
				DisplayMsg("You have already killed the boss.\n");


				Map[newPlayerY][newPlayerX] = " ";
				playerMap[newPlayerY][newPlayerX] = " ";
				playerMap[hero.yPos][hero.xPos] = " ";
				Map[hero.yPos][hero.xPos] = " ";

			}

		}
		else if (newPosition == "6")
		{
			if (hero.tuskar_alive == true) {
				playerMap[player.yPos][player.xPos] = "P";
				playerMap[newPlayerY][newPlayerX] = "T";
				Boss_Battles_1(player, newPlayerX, newPlayerY);
			}
		}
		else if (newPosition == "8")
		{
			if (hero.nagaQuest == false && hero.nagaQueenAlive)
			{
				hero.nagaQuest = true;
				Map[newPlayerY][newPlayerX] = " ";
				playerMap[newPlayerY][newPlayerX] = " ";
				playerMap[player.yPos][player.xPos] = "P";
				playerMap[31][24] = " ";
				Map[31][24] = " ";
				playerMap[39][10] = "N";
				Map[39][10] = "8";
				DisplayMsg("Hello adventurer, I am the blacksmith of this city.\nI have a task for you.\nThere is a Naga Queen that lives in the lake south of here.\nKill her, bring her scales, and i will reward you.\n");
			}
			else if (hero.nagaQueenAlive && hero.nagaQuest) {
				playerMap[player.yPos][player.xPos] = "P";
				DisplayMsg("You have found the Naga Queen.\nKill her, bring the scales to the blacksmith, and claim your reward\n");
				hero.enemy("Naga Queen", "Mini Boss", 45, 800, 2000, 2000, "Naga Scales");

			}
			else if (hero.nagaQueenAlive == false && hero.nagaQuest)
			{
				DisplayMsg("You have killed the Naga Queen.\nThank you, have this, +1000 gold, +1000 xp");
				hero.exp += 1000;
				hero.gold += 1000;

				playerMap[newPlayerY][newPlayerX] = " ";
				Map[newPlayerY][newPlayerX] = " ";

				hero.nagaQuest = true;
			}

		}
		else if (newPosition == "s")
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[newPlayerY][newPlayerX] = "s";
			playerMap[player.yPos][player.xPos] = "P";
			spellShop(player);
		}
		else if (newPosition == "b")
		{

			if (hero.nagaQuest == false && hero.nagaQueenAlive == false)
			{
				Map[player.yPos][player.xPos] = " ";
				playerMap[newPlayerY][newPlayerX] = "s";
				playerMap[player.yPos][player.xPos] = "P";
				blacksmithShop(player);
			}
			else if (hero.nagaQuest == false && hero.nagaQueenAlive)
			{
				hero.nagaQuest = true;
				Map[player.yPos][player.xPos] = " ";
				playerMap[newPlayerY][newPlayerX] = "b";
				playerMap[player.yPos][player.xPos] = "P";

				playerMap[31][24] = " ";
				Map[31][24] = " ";
				playerMap[39][10] = "N";
				Map[39][10] = "8";

				DisplayMsg("Hello adventurer, I am the blacksmith of this city.\nI have a task for you.\nThere is a Naga Queen that lives in the lake south of here.\nKill her, bring her scales, and i will reward you.\n");

			}
			else if (hero.nagaQuest == true && hero.nagaQueenAlive)
			{
				DisplayMsg("You have not killed the Naga Queen yet.\nKill the Naga queen, then we'll talk.\n");
				//hero.nagaQuest = false;
			}
			else if (hero.nagaQuest == true && hero.nagaQueenAlive == false)
			{
				DisplayMsg("Welcommeee, You have defeated the naga queen. Thank you, now, onto business.\nI sell high quality weapons, Armors and craftables, if you have the materials required.\nHave a look");
				hero.nagaQuest = false;
				blacksmithShop(hero);
			}
			else
			{
				blacksmithShop(hero);
			}

		}
		else if (newPosition == "S" && hero.mainquest_1_counter >= 1)
		{
			Map[newPlayerY][newPlayerX] = "S";
			playerMap[player.yPos][player.xPos] = " ";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "P";
		}
		else if (newPosition == "Q")
		{
			playerMap[newPlayerY][newPlayerX] = "Q";
			playerMap[player.yPos][player.xPos] = "P";
			informer(hero);
		}
		else if (newPosition == "o")
		{
			playerMap[newPlayerY][newPlayerX] = "O";
			playerMap[player.yPos][player.xPos] = "P";
			abandonedOutpost(hero);
		}
		else if (newPosition == "E") {
			Map[player.yPos][player.xPos] = " ";
			playerMap[player.yPos][player.xPos] = " ";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "P";

			battle_1_1(player, newPlayerX, newPlayerY);
		}
		else if (newPosition == "e") {
			Map[player.yPos][player.xPos] = " ";
			playerMap[player.yPos][player.xPos] = " ";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "P";

			battle_1_2(player, newPlayerX, newPlayerY);
		}
		else if (newPosition == "(")
		{
			if (hero.tuskar_alive == false)
			{
				symbol_of_power(hero);
				Map[player.yPos][player.xPos] = " ";
				playerMap[player.yPos][player.xPos] = " ";
				player.xPos = newPlayerX;
				player.yPos = newPlayerY;
				playerMap[player.yPos][player.xPos] = "P";
				endLevel(player);
				//epilogueLevel1(hero);
			}
		}
		else if (newPosition == "█")
		{

			Map[player.yPos][player.xPos] = "█";
			playerMap[player.yPos][player.xPos] = " ";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "P";

		}
	}
	//them for level 2 and its quests and interactions
	else if (hero.gameLevel == 2)
	{
		if (newPosition == "p")
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[newPlayerY][newPlayerX] = " ";
			Map[newPlayerY][newPlayerX] = " ";
			playerMap[player.yPos][player.xPos] = "P";
			prologue2(hero);
		}
		else if (newPosition == "0")
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[newPlayerY][newPlayerX] = " ";
			Map[newPlayerY][newPlayerX] = " ";
			playerMap[player.yPos][player.xPos] = "P";
			trader1(hero, newPlayerX, newPlayerY);
		}
		else if (newPosition == "1")
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[player.yPos][player.xPos] = " ";
			Map[newPlayerY][newPlayerX] = " ";
			hero.xPos = newPlayerX;
			hero.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "P";
			story_2_1(hero, newPlayerX, newPlayerY);

		}
		else if (newPosition == "2")
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[newPlayerY][newPlayerX] = "s";
			Map[newPlayerY][newPlayerX] = "2";
			playerMap[player.yPos][player.xPos] = "P";
			story_2_2(hero, newPlayerX, newPlayerY);
		}
		else if (newPosition == "4")
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[newPlayerY][newPlayerX] = "w";
			Map[newPlayerY][newPlayerX] = "4";
			playerMap[player.yPos][player.xPos] = "P";
			story_2_4(hero);
		}
		else if (newPosition == "W")
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[player.yPos][player.xPos] = " ";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "P";
			battle_2_1(hero);
		}
		else if (newPosition == "E") {
			Map[player.yPos][player.xPos] = " ";
			playerMap[player.yPos][player.xPos] = " ";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "P";

			battle_2_2(player);
		}
		else if (newPosition == "k")
		{
			battle_2_2(hero);
		}
		else if (newPosition == "K")
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[player.yPos][player.xPos] = "P";
			Map[newPlayerY][newPlayerX] = "K";

			player.enemy("Valeron", "Mini Boss", 400, 4500, 6000, 5000, "Throne Room Key");
		}
		else if (newPosition == "7")
		{
			Map[player.yPos][player.xPos] = "N";
			playerMap[player.yPos][player.xPos] = "P";
			story_2_7(hero);
		}
		else if (newPosition == ":")
		{
			if (hero.throneroom_key && hero.findItemInInventory("Throne Room Key"))
			{

				Map[newPlayerY][newPlayerX] = " ";
				playerMap[newPlayerY][newPlayerX] = " ";
				player.xPos = newPlayerX;
				player.yPos = newPlayerY;
				playerMap[player.yPos][player.xPos] = "P";

			}
			else
			{
				DisplayMsg("You need the throne room key to enter the throne room.\n");
			}
		}
		else if (newPosition == "H" && hero.hiddenKey)
		{
			Map[newPlayerY][newPlayerX] = " ";
			playerMap[player.yPos][player.xPos] = " ";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "P";
		}
		else if (newPosition == "t")
		{
			Map[newPlayerY][newPlayerX] = " ";
			playerMap[newPlayerY][newPlayerX] = " ";
			playerMap[player.yPos][player.xPos] = "P";
			DisplayMsg("You found a treasure chest...items gained\n2000 Gold\n6000 exp\n10 Healing Potion\n5 Mana Potions\n ");
			hero.gold += 2000;
			hero.exp += 6000;
			hero.mana_potion += 5;
			hero.healing_potion += 10;
		}
		else if (newPosition == "8" && hero.lancelotAlive)
		{
			//fight with commander's guards
			player.enemy("Lancelot", "Guard Knight", 500, 5000, 7000, 5000, "Knight Blade");
		}
		else if (newPosition == "8" && hero.mordredAlive)
		{
			//fight with commander's guards
			player.enemy("Mordred", "Guard Knight", 500, 5000, 7000, 5000, "Knight Armor");
		}
		else if (newPosition == "I" && hero.commander_alive)
		{
			//fight the commander
			DisplayMsg("\n\"Welcome warrior, I will be your Judge,and your executioner, come let us begin..\"\n");
			player.enemy("Commander", "Boss", 800, 10000, 10000, 10000, "Blade Of Altyrus");
		}
		else if (newPosition == "█")
		{

			Map[player.yPos][player.xPos] = "█";
			playerMap[player.yPos][player.xPos] = " ";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "P";
			endLevel(player);
		}

	}	//level 3 interafctions and stuff
	else if (hero.gameLevel == 3)
	{
		if (newPosition == "0")
		{
			Map[newPlayerY][newPlayerX] = " ";
			playerMap[player.yPos][player.xPos] = " ";
			player.xPos = newPlayerX;
			player.yPos = newPlayerY;
			playerMap[player.yPos][player.xPos] = "P";
			prologue3(hero);
		}
		else if(newPosition == "1")
		{
			Map[newPlayerY][newPlayerX] = "1";
			playerMap[player.yPos][player.xPos] = "P";

			if (hero.drakon_alive)
				enterThroneTalk();
			else
				talk_with_Altyrus(hero);
		}
		else if (newPosition == "E")
		{
			Map[newPlayerY][newPlayerX] = " ";
			playerMap[player.yPos][player.xPos] = "P";
			Map[newPlayerY][newPlayerX] = " ";
			battle_3_2(hero);
		}
		else if (newPosition == "W")
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[player.yPos][player.xPos] = "P";
			Map[newPlayerY][newPlayerX] = " ";
			battle_3_1(hero);
		}
		
		else if (newPosition == "8"&&hero.drakon_alive)
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[player.yPos][player.xPos] = "P";
			Map[newPlayerY][newPlayerX] = "D";
			displayMsg("You have reached the end, Drakon himself stands infront you, towering over you.\nYou prepare yourself, as a wave of uneasiness passes over you."
				"\nDrakon speaks,\"Welcome fleshling, even though you have defeated my army, and my commanders, but you will never defeat meeeeee\",\n\"I am Death, I am the END, I AM DRAKKOONNNNN!!!\"");
			hero.boss("Emperor Drakon", "Emperor", 5000, 35000, 50000, 50000, "Might Of Altyrus");
			Boss_Battles_1(hero, newPlayerX, newPlayerY);
		}
		else if (newPosition == "4" && hero.sideboss_6_alive)
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[player.yPos][player.xPos] = "P";
			Map[newPlayerY][newPlayerX] = "4";
			//drakons left hand man, fight him, named Bellion
			DisplayMsg("\n\"This is your end, even if you defeat me, my lord will never lose\"\n");
			player.enemy("Arkhel", "Mini Boss", 1000, 10000, 7000, 5000, "Heart Of Altyrus");
		}
		else if (newPosition == "6" && hero.sideboss_5_alive)
		{
			Map[player.yPos][player.xPos] = " ";
			playerMap[player.yPos][player.xPos] = "P";
			Map[newPlayerY][newPlayerX] = "6";
			//drakons left hand man, fight him, named Bellion
			DisplayMsg("\n\"You will go no further, i will protect my lord with my life.\"...\n");
			player.enemy("Bellion", "Mini Boss", 1000, 10000, 7000, 5000, "Soul Of Altyrus");
		}
		
	}

}
