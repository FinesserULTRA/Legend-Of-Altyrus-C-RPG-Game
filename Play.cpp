//play.cpp

#pragma once
#include "STLIB.h"
#include "Player.h"
#include "Game.cpp" 

static void display() {
	hero.playerHUD(hero); // Assuming this function exists
	//hero.displayHud(hero);
	displayMapAround(playerMap, hero.xPos, hero.yPos);
	//displayFullMap(playerMap);
}



static bool gameloop = true;

//static void fight() {
//	battle_1(hero);
//}



//debugging code/stats, use for level 1 and 2
/*hero.level = 13;
	hero.max_health = 380;
	hero.health = hero.max_health;
	hero.max_mana = 25;
	hero.mana = hero.max_mana;
	hero.strength = 32;
	hero.healing_potion = 69;
	hero.mana_potion = 19;
	hero.mainquest_1_counter = 2;
	hero.trader_talk_count = 2;
	//
	hero.mainquest_1 = true;


	///*
	//hero.xPos = 33;
	//hero.yPos = 7;


KnightKiller kk;
ShadowArmor shadow;
hero.addToInventory(kk);
hero.addToInventory(shadow);

//hero.xPos = 10;
//hero.yPos = 39;

/*OrbOfAltryus orb;
hero.addToInventory(orb);
int previousX = hero.xPos;
int previousY = hero.yPos;
playerMap[hero.yPos][hero.xPos] = "P";
/*hero.gameLevel = 1;
hero.gold = 2500;
hero.max_health = 5000;
hero.health = hero.max_health;
*/

static void play() {

	
	//call getmaps, to get input for all the maps from txt
	getMaps();

	//starting position for level 1
	hero.xPos = 47;
	hero.yPos = 3;

	//input variable and position
	char userInput;
	static string position;

	//seed for RNG
	srand(static_cast<unsigned int>(time(0)));


	//debugging stats for level 3, use incase of skip to level 3
	/*hero.xPos = 5;
	hero.yPos = 11;
	hero.gameLevel = 3;
	Map = DrakonHold;
	playerMap = Drakon_playerMap;
	hero.orb_of_altyrus = true;
	hero.blade_of_altyrus = true;
	hero.max_health = 3000;
	hero.max_mana = 350;
	hero.max_strength = 200;
	hero.health = hero.max_health;
	hero.mana = hero.max_mana;
	hero.strength = hero.max_strength;
	hero.healing_potion += 80;
	hero.mana_potion += 30;
	hero.mutilate = true;
	BladeOfAltyrus blade;
	hero.addToInventory(blade);
	hero.spells.emplace_back("(M)utilate 10 mana");
	hero.chaos_vortex = true;
	hero.spells.emplace_back("(C)haos vortex 50 mana");*/


	//game loop
	while (gameloop) {

		//clear screen 
		system("cls");

		//display map, player stats, and player position

		//User input is mostly validated here
		do
		{
			system("cls");
			display();
			std::cout << "\n\nUse WASD to move.`I` for inventory.'y' to show quests. Press 'q' to quit.\n";
			userInput = _getch();
		} while (userInput != 'w' && userInput != 'a' && userInput != 's' && userInput != 'd' && userInput != 'i' && userInput != 'y' && userInput != 't' && userInput != 'q');


		//movement, inventory, and quest display, and quitting
		if (userInput == 'w' || userInput == 'a' || userInput == 's' || userInput == 'd') {
			position = MovePlayer(hero, userInput);
		}
		else if (userInput == 'I' || userInput == 'i')
		{
			//inventory options
			cout << "\n\nWeapon Inventory(W). Item Inventory(i). Spells(S). Armour(A). Potions (P)\n\n";
			userInput = _getch();

			//Weapons, armor, acquried spells, and potions to be used.
			//user inventory, items etc are here
			if (userInput == 'i') {
				order(hero.inventory);
				_getch();
			}
			//use potions
			else if (userInput == 'p')
			{
				cout << "\n\n1) Health Potions: " << hero.healing_potion;
				cout << "\n2) Mana Potions: " << hero.mana_potion;
				cout << "\n>";
				cin >> userInput;

				if (userInput == '1')
				{
					int heal_amount;
					heal_amount = hero.max_health / 4;
					if (hero.healing_potion > 0 && hero.health < hero.max_health) {
						hero.healing_potion -= 1;
						hero.health += heal_amount;
						system("pause");
					}
					else if (hero.healing_potion <= 0)
					{
						cout << "\nYou have no health potions\n";
						system("pause");
					}
					else if (hero.health >= hero.max_health)
					{
						cout << "\nYou are already at full health\n";
						system("pause");
					}
				}
				else if (userInput == '2')
				{
					int heal_amount;
					heal_amount = hero.max_mana / 2;
					if (hero.mana_potion > 0 && hero.mana < hero.max_mana) {
						hero.mana_potion -= 1;
						hero.mana += heal_amount;
						system("pause");
					}
					else if (hero.mana_potion <= 0)
					{
						cout << "\nYou have no mana potions\n";
						system("pause");
					}
					else if (hero.mana >= hero.max_mana)
					{
						cout << "\nYou are already at full mana\n";
						system("pause");
					}
				}

			}
			//All the weapons are dispalyed, and options to change weapons are here
			else if (userInput == 'w')
			{
				cout << endl << endl;
				order(hero.weaponsinven);
				cout << "Index to change weapon, (E) to exit.\n";
				cin >> userInput;
				if (userInput == 'e')
				{
					continue;
				}
				else
				{
					hero.switchWeapon(userInput - '0');
					system("pause");

				}

			}
			//all the armor are displayed, and options to change armor are here
			else if (userInput == 'a')
			{
				cout << "\n\n";
				order(hero.armorInventory);
				cout << "\nIndex to change Armour, (E) to exit.\n";
				cin >> userInput;
				if (userInput == 'e')
				{
					continue;
				}
				else
				{
					hero.switchArmor(userInput - '0');
					system("pause");

				}
			}
			//all acquired spells are displayed
			else if (userInput == 's')
			{

				cout << "\n\n";
				order(hero.spells);
				cout << endl;
				system("pause");

			}
		}
		//quest display
		else if (userInput == 'y')
		{
			order(hero.quests);
			_getch();
		}

		//quit
		else if (userInput == 'q') {
			gameloop = false;
			exit(0);
		}
	}
}