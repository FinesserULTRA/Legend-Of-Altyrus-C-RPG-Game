#pragma once

#include "STLIB.h"
#include "Maps.h"


static void settlement()
{
	system("cls");
	wcout << LR"(
                                                                                    0000            
                                                                                  00    00          
                                                                                00        00        
                                                                                00        00          ÂÂÂÂÂÂÂÂÂÂ    
                                                                                  00    00          //+++++++++\\
ÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂÂ              ÂÂÂÂÂÂÂÂÂÂÂ                                       0000            ||sssssssss||
++++++++++++++++++++\\          //++++++++++\\                                                      ||         ||
                    ||          ||ssssssssss||                                                      || //////  ||
  ////  ////  ////  ||          ||          ||                                                      || |~~~~|  ||
  |__|  |__|  |__|  ||          ||          ||                                                      || |____|  ||
  oooo  oooo  oooo  ||          ||          ||                                                      ||         ||
                    ||          || //////// ||                                                      ||_________||
                    ||          || |______| ||                                                      || \ \ \ \ ||
  ++++  ++++  ++++  ||          ||++++++++++||                                                      ||\ \ \ \ \||
  |__|  |__|  |__|  ||          ||          ||                                                      || \ \ \ \ ||
  ssss  ssss  ssss  ||          ||__________||                                                      ||\ \ \ \ \||
                    ||          ||__________||++++++++++++++++                                      ||_________||
              ////////////////  ||          yyyyyyyyyyyyyyyyyy//      ////////////          ////////|| \ \ \ \ ||
            //yyyyyyyyyyyyyyyy//||    //////        //////    ||    //yyyyyyyyyyyy//      //yyyyyyyy||\ \ \ \ \||
            ||  ////    ////  ||||    |    |        |    |    ||  //||////////////||//  //||////////|| \ \ \ \ ||
            ||  |__|    |__|  ||||    |____|        |____|    ||  yy||yyyyyyyyyyyy||yy  yy||yyyyyyyy||\ \ \ \ \||
            ||  hhhh    hhhh  ||||    hhhhhh        hhhhhh    ||    ||            ||      ||        || \ \ \ \ ||
::::        ||                ||||                            ||    ||            ||      ||        ||\ \ \ \ \||
MMMM::      ||    ::::::      ||||          ::::::::          ||    ||   :::::    ||      ||::::::::|| \ \ \ \ ||
/// MM      ||    //////      ||||          ////////          ||    ||   /////    ||      || ////// ||\ \ \ \ \||
  | MM      ||    | || |      ||||          M  ||  M          ||    ||   |   |    ||      ||  |  |  || \ \ \ \ ||
  | MM------||----| || |------||||----------M  ||  M----------||----||---|   |----||------||--|  |--||\ \ \ \ \||
ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
)";

}


//shop settlement
static void spellShop(Player& player)
{
	/*while (true)*/
	{
		settlement();
		//system("cls");
		cout << "Welcome to the spell shop!\n";
		cout << "Here you can buy spells to use in battle!\n";
		cout << "You have " << player.gold << " gold.\n";
		cout << "1) Fire Bolt - 1000 gold\n";
		cout << "2) Ice Blast - 1000 gold\n";
		cout << "3) Heal - 1250 gold\n";
		cout << "4) Divine - 4000 gold\n";
		cout << "5) Shadow Flee - 750 gold\n";
		cout << "6) Health potion - 100 Gold\n";
		cout << "7) Mana potion - 250 Gold\n";
		cout << "0) Exit\n";
		cout << "What would you like to buy?\n";

		int choice;
		cin >> choice;

		if (choice == 1 && hero.fire_bolt == false)
		{
			if (player.gold >= 1000)
			{
				player.gold -= 1000;
				player.spells.emplace_back("(F)ire Bolt 10 mana");
				player.fire_bolt = true;
				cout << "You bought Fire bolt!\n";
				cout << "You have " << player.gold << " gold left.\n";
				cout << "Would you like to buy anything else?\n";
				cout << "1) Yes\n";
				cout << "2) No\n";
				int choice2;
				cin >> choice2;
				if (choice2 == 1)
				{
					spellShop(player);
				}
				else if (choice2 == 2)
				{
					cout << "Thank you for shopping!\n";
					Sleep(1000);
					//system("cls");
				}
			}
			else
			{
				cout << "You don't have enough gold!\n";
				Sleep(1000);
				//system("cls");
			}
		}
		else if (choice == 2 && hero.ice_blast == false)
		{
			if (player.gold >= 1000)
			{
				player.gold -= 1000;
				player.spells.emplace_back("(I)ce Blast 10 mana");
				player.ice_blast = true;
				cout << "You bought Ice Blast!\n";
				cout << "You have " << player.gold << " gold left.\n";
				cout << "Would you like to buy anything else?\n";
				cout << "1) Yes\n";
				cout << "2) No\n";
				int choice2;
				cin >> choice2;
				if (choice2 == 1)
				{
					spellShop(player);
				}
			}
			else
			{
				cout << "You don't have enough gold!\n";
				Sleep(1000);
				//system("cls");
			}
		}
		else if (choice == 3 && hero.heal == false)
		{
			if (player.gold >= 1250) 
			{
				player.gold -= 1250;
				player.spells.push_back("(H)eal 5 mana");
				player.heal= true;
				cout << "You bought heal!\n";
				cout << "You have " << player.gold << " gold left.\n";
				cout << "Would you like to buy anything else?\n";
				cout << "1) Yes\n";
				cout << "2) No\n";
				int choice2;
				cin >> choice2;
				if (choice2 == 1)
				{
					spellShop(player);
				}
			}
			else
			{
				cout << "You don't have enough gold!\n";
				Sleep(1000);
				//system("cls");
			}
		}
		else if (choice == 4 && hero.divine_heal == false)
		{
			if (player.gold >= 2500)
			{
				player.gold -= 2500;
				player.divine_heal = true;
				player.spells.emplace_back("(D)ivine Heal (30/15) mana");
				cout << "You bought Divine!\n";
				cout << "You have " << player.gold << " gold left.\n";
				cout << "Would you like to buy anything else?\n";
				cout << "1) Yes\n";
				cout << "2) No\n";
				int choice2;
				cin >> choice2;
				if (choice2 == 1)
				{
					spellShop(player);
				}
			}
			else
			{
				cout << "You don't have enough gold!\n";
				Sleep(1000);
				//system("cls");
			}
		}
		else if (choice == 5 && hero.shadow_flee == false)
		{
			if (player.gold >= 750)
			{
				player.gold -= 750;
				player.shadow_flee = true;
				player.spells.emplace_back("(S)hadow Flee 5 mana");
				cout << "You bought Shadow Flee!\n";
				cout << "You have " << player.gold << " gold left.\n";
				cout << "Would you like to buy anything else?\n";
				cout << "1) Yes\n";
				cout << "2) No\n";
				int choice2;
				cin >> choice2;
				if (choice2 == 1)
				{
					spellShop(player);
				}
			}
			else
			{
				cout << "You don't have enough gold!\n";
				Sleep(1000);
				//system("cls");
			}
		}
		else if(choice == 7)
		{
			//mana potions
			if(hero.gold >= 250)
			{
				hero.gold -= 250;
				hero.mana_potion += 1;
				cout << "You bought a mana potion!\n";
				cout << "You have " << hero.gold << " gold left.\n";
				cout << "Would you like to buy anything else?\n";
				cout << "1) Yes\n";
				cout << "2) No\n";
				int choice2;
				cin >> choice2;
				if (choice2 == 1)
				{
					spellShop(hero);
				}
				else if (choice2 == 2)
				{
					cout << "Thank you for shopping!\n";
					Sleep(1000);
					//system("cls");
				}
			}
			else
			{
				cout << "You don't have enough gold!\n";
				Sleep(1000);
				//system("cls");
			}
		}
		else if(choice == 6)
		{
			//heal potions
			if(hero.gold>=100)
			{
				hero.gold -= 100;
				hero.healing_potion += 1;
				cout << "You bought a healing potion!\n";
				cout << "You have " << hero.gold << " gold left.\n";
				cout << "Would you like to buy anything else?\n";
				cout << "1) Yes\n";
				cout << "2) No\n";
				int choice2;
				cin >> choice2;
				if (choice2 == 1)
				{
					spellShop(hero);
				}
				else if (choice2 == 2)
				{
					cout << "Thank you for shopping!\n";
					Sleep(1000);
					//system("cls");
				}
			}
			else
			{
				cout << "You don't have enough gold!\n";
				Sleep(1000);
				//system("cls");
			}
		}
		else if (choice == 0)
		{
			cout << "Thank you for shopping!\n";
			Sleep(1000);
			//system("cls");
		}
	}
}


static void abandonedOutpost(Player& player)
{
	
		char choice;
		if (player.abandoned_outpost == false)
		{
			cout << "\nYou have discovered an abandoned outpost!\n";
			cout << "What to do?\n1) Search\n2) Leave\n";
			cin >> choice;

			if (choice == '1')
			{
				player.healing_potion += 8;
				player.mana_potion += 4;
				PlateMail plate;
				player.addToInventory(plate);
				player.abandoned_outpost = true;

				DisplayMsg("You found some potions, and armor.\n+8 Healing potions. +4 mana potions.\nGained PlateMail armor");

			}
			else if (choice == 'n' || choice == 'N')
			{
				cout << "You leave the outpost.\n";
				system("pause");
			}
			else
				cout << "Invalid input.\n";
		}
		else if (player.abandoned_outpost == true)
		{
			cout << "You have already searched this outpost.\n";
			system("pause");
		}
	

}

static void blacksmithShop(Player& hero)
{
	while (true)
	{
		system("cls");
		cout << "Welcome to the blacksmith shop!\n";
		cout << "Here you can buy weapons and armor!\n";
		cout << "You have " << hero.gold << " gold.\n";
		cout << "1) Short Sword - 450 gold\n";
		cout << "2) Long Sword - 800 gold\n";
		cout << "3) Knight Killer - 4000 gold\n";
		cout << "\nCraftables:\n";
		cout << "\n5) Demon Bone Shiv - 15 Dmg - 1x Demon Bone, 150 Gold";
		cout << "\n6) Demon Chestplate - 2x Ratling Fur, 500 gold";

		if (!hero.nagaQueenAlive) {
			cout << "\n9) Great Naga Trident - Naga Scales, 1000 gold, +150 damage.";
		}
		

		cout << "0) Exit\n";
		cout << "\nWhat would you like to buy?\n";

		int choice;
		cin >> choice;

		 if (choice == 1)
		{
			if (hero.gold >= 450)
			{
				hero.gold -= 450;
				ShortSword shortSword;
				hero.weaponsinven.emplace_back(shortSword);
				cout << "You bought a Short Sword!\n";
				cout << "You have " << hero.gold << " gold left.\n";
				cout << "Would you like to buy anything else?\n";
				cout << "1) Yes\n";
				cout << "2) No\n";
				int choice2;
				cin >> choice2;
				if (choice2 == 1)
				{
					blacksmithShop(hero);
				}
				else if (choice2 == 2)
				{
					cout << "Thank you for shopping!\n";
					Sleep(1000);
					break;
					//system("cls");
				}
			}
		}
		else if (choice == 2)
		{
			if (hero.gold >= 800)
			{
				hero.gold -= 800;
				LongSword longS;
				hero.weaponsinven.emplace_back(longS);
				cout << "You bought a Short Sword!\n";
				cout << "You have " << hero.gold << " gold left.\n";
				cout << "Would you like to buy anything else?\n";
				cout << "1) Yes\n";
				cout << "2) No\n";
				int choice2;
				cin >> choice2;
				if (choice2 == 1)
				{
					blacksmithShop(hero);
				}
				else if (choice2 == 2)
				{
					cout << "Thank you for shopping!\n";
					Sleep(1000);
					break;
					//system("cls");
				}
			}
		}
		else if (choice == 3)
		{
			if (hero.gold >= 4000)
			{
				hero.gold -= 4000;
				KnightKiller knightKiller;
				hero.weaponsinven.emplace_back(knightKiller);
				cout << "You bought a Knight Killer!\n";
				cout << "You have " << hero.gold << " gold left.\n";
				cout << "Would you like to buy anything else?\n";
				cout << "1) Yes\n";
				cout << "2) No\n";
				int choice2;
				cin >> choice2;
				if (choice2 == 1)
				{
					blacksmithShop(hero);
				}
				else if (choice2 == 2)
				{
					cout << "Thank you for shopping!\n";
					Sleep(1000);
					break;
					//system("cls");
				}
			}
		}
		else if(choice == 5 )
		{
			if(hero.gold >= 150 && hero.findItemInInventory("Demon Bone"))
			{
				hero.gold -= 150;
				hero.removeItemFromInventory("Demon Bone");
				DemonBoneShiv demonBoneShiv;
				hero.weaponsinven.emplace_back(demonBoneShiv);
				cout << "You bought a Demon Bone Shiv!\n";
				cout << "You have " << hero.gold << " gold left.\n";
				cout << "Would you like to buy anything else?\n";
				cout << "1) Yes\n";
				cout << "2) No\n";

				int choice2;
				cin >> choice2;
				if (choice2 == 1)
				{
					blacksmithShop(hero);
				}
				else if (choice2 == 2)
				{
					cout << "Thank you for shopping!\n";
					Sleep(1000);
					break;
					//system("cls");
				}
			}
			else
			{
				cout << "You don't have enough gold or materials!\n";
				Sleep(1000);
				break;
			}
		}
		else if (choice == 9 && hero.nagaQueenAlive == false)
		{
			if (hero.gold >= 1000 && hero.findItemInInventory("Naga Scales"))
			{
				hero.gold -= 1000;
				hero.removeItemFromInventory("Naga Scales");
				GreatNagaTrident greatNagaTrident;
				hero.weaponsinven.emplace_back(greatNagaTrident);
				cout << "You bought a Great Naga Trident!\n";
				cout << "You have " << hero.gold << " gold left.\n";
				cout << "Would you like to buy anything else?\n";
				cout << "1) Yes\n";
				cout << "2) No\n";

				int choice2;
				cin >> choice2;
				if (choice2 == 1)
				{
					blacksmithShop(hero);
				}
				else if (choice2 == 2)
				{
					cout << "Thank you for shopping!\n";
					Sleep(1000);
					break;
					//system("cls");
				}
			}
		}
		else if (choice == 0)
		{
			cout << "Thank you for shopping!\n";
			Sleep(1000);
			break;
			//system("cls");
		}
	}

}

static void armorShop(Player& player)
{
	
}
static void dungeonBattle(Player& player)
{

	std::cout << "Deeper into the temple you go" << std::endl;
	player.dungeon = true;

	double r = static_cast<double>(rand()) / RAND_MAX;

	if (r < 0.45) {
		std::cout << "You hear the muttering of the insane. A Clockwork Horror appears" << std::endl;
		player.enemy("Valhemic Horror", "Haunted", 25, 550, 800, 750, "Iron Shard");
	}
	else if (r < 0.72) {
		std::cout << "You see a Clockwork Pain Taker in the distance. Prepare for combat" << std::endl;
		player.enemy("Daggar D", "Deranged ", 30, 600, 600, 750, "Iron Shard");
	}
	else if (r < 0.87) {
		std::cout << "A Clockwork Engineer rushes towards you. Defend with violence" << std::endl;
		player.enemy("Necrophos", "Undead", 40, 400, 800, 1000, "Iron Shard");
	}
	else if (r < 0.90) {
		while (true)
		{
			cout << "\nYou stumbled upon a treasure chest.\nDo you wish to open it?";
			char choice = _getch();

			if (choice == 'y' || choice == 'Y')
			{
				r = static_cast<double>(rand()) / RAND_MAX;

				if (r < .60)
				{
					cout << "\nYou found gold";
					hero.gold += 5000;
					break;
				}
				else
				{
					cout << "\nYou find an enemy";
					player.enemy("Chest Demon", "Demonic", 60, 120, 600, 750, "Iron Shard");
				}
			}
			else
			{
				cout << "\nYou decide to leave the chest alone.\n";
				break;
			}

		}
	}
}


static void dungeon(Player& hero)
{
	while (true)
	{
		
		dungeonBattle(hero);
		system("cls");
		dungeonBattle(hero);
		system("cls");
		cout << "You find a way out of the temple" << endl;
		string choice;
		cout << "Escape(E) or Remain(R): ";
		cin >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

		if (choice == "E") {
			cout << "Press any key to leave the dungeon";
			hero.dungeon = false;
			system("cls");
			break;
		}
		else if (choice == "R") {
			system("cls");
			cout << "You decide to push ahead against the undying darkness" << endl;
		}
		else {
			system("cls");
			cout << "Invalid choice, but it is too late to make a decision" << endl;
			cout << "A horde of monsters has blocked the exit" << endl;
		}

		cout << "Press enter to continue";
		system("pause");

		system("cls");
		dungeonBattle(hero);
		system("cls");
		dungeonBattle(hero);
		system("cls");
		cout << "You find a way out of the temple" << endl;
		cout << "Escape(E) or Remain(R): ";
		cin >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

		if (choice == "E") {
			cout << "Press any key to leave the dungeon";
			hero.dungeon = false;
			system("cls");
			break;
		}
		else if (choice == "R") {
			system("cls");
			cout << "You decide to push ahead against the undying darkness" << endl;
		}
		else {
			system("cls");
			cout << "Invalid choice, but it is too late to make a decision" << endl;
			cout << "A horde of monsters has blocked the exit" << endl;
		}

		cout << "Press enter to continue";
		system("pause");
		system("cls");
		dungeonBattle(hero);
		system("cls");
		dungeonBattle(hero);
		system("cls");
		dungeonBattle(hero);
		system("cls");
		dungeonBattle(hero);
		system("cls");

		cout << "You have cleared the temple for now " << endl;
		cout << "In the corner of your eyes, you spot something.. " << endl;

		double r = static_cast<double>(rand()) / RAND_MAX;
		if (r < 0.80) {
			cout << "You find a large stash of Iron Shards!!" << endl;
			cout << "You gain 5 Iron Shards" << endl;
			hero.addItemToInventory("Iron Shards", 5);
		}
		else if (r < 0.90) {
			cout << "You find a large stash of gold" << endl;
			cout << "You gain 1000 gold" << endl;
			hero.gold += 1000;
		}
		else {
			cout << "You find a small stash of Demon Bones" << endl;
			cout << "You gain 2 Demon Bones " << endl;
			hero.addItemToInventory("Demon Bone", 2);
		}

		hero.dungeon = false;
		hero.dungeon_clear = true;
		cout << "Press any key to leave the dungeon.\nBut before you manage to leave, an assassin attacks you...";
		hero.enemy("Shadow Assassin", "Assassin", 45, 900, 2500, 3000, "Mutilate");

		system("pause");
		system("cls");
		break;
	
	}
}



static void waterTown(Player& hero)
{
	
}

static void  throne()
{
	cout << R"(
@#@#@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%++%:,,......,,:%++%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@
@@@#%@S@@@@@@SSSS@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@S;::S:,,,,,,,,,,:S::;S@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@SSSS@@@@@@S@@#%@@
;:%;:%S*#@S@@@@@@#@@###@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#S?*;+;;:*%:;;+;*?S#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@###@@#@@@@@@S@#*S%;%+:S
,,?,,*:,*;:%*?####SS#####@#SS#@##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@*:.......;?.......:*@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##@#SS#@#####SS####?*%:;*,:*,+:.*
SS#SS#?%%++*,:+::%++*#S##@@S#%%@#@@@@@@@@@@@@@@@@@@@@@@@@@S?S@@S@%*+%+%%%%S#?%%%+%+*%@S@@S?S@@@@@@@@@@@@@@@@@@@@@@@@@#@%%#S@@##S#*++%::+:,*++%%?#S##S#
@@@@@@@S#@@@@#S*++,:*;;?%%S@@@@S?#%%@@@@@@@@@@@@@@@@#S#?+%?%@@@%+:,,%.%@@@@@@@@%.%,,:+%@@@%?%+?#S#@@@@@@@@@@@@@@@@%%#?S@@@@S%%?;;*:,++*S#@@@@#S@@@@@@@
@@@@S@@S##@@@@@@@@#%*::+:;??*S#@?*?###%##@@@@@@@@#%S**%S#@@@@@@SS*++S;*@@@@@@@@*;S++*SS@@@@@@#S%**S%#@@@@@@@@##%###?*?@#S*??;:+::*%#@@@@@@@@##S@@S@@@@
@@@@*%@@@@@@@@@@@@@@@@#%+++:+?**#@@%*??**S##@@#%%??#@@@@@@@@@@#?@%+::,;@@@@@@@@:,::+%@?#@@@@@@@@@@#??%%#@@##S**??*%@@#**?+:+++%#@@@@@@@@@@@@@@@@%*@@@@
@@@@+*%#@@@#@@@@@@@@@@@@@@S++,;***%@SSS##?%#@@??#@@@@@@@@@@@@@#?@?:,,,:@@@@@@@@;,,,:?@?#@@@@@@@@@@@@@#??@@#%?##SSS@%***;,++S@@@@@@@@@@@@@@#@@@#%*+@@@@
@@@S?%@?S@@@@@@@@@@@@@@@@@@@@%?;+*++%#S?SSSS%S#@@@@@@@@@@@@@@@@#S?*+S;;S##@@@@%;;S+*?S#@@@@@@@@@@@@@@@@#S%SSSS?S#%++*+;?%@@@@@@@@@@@@@@@@@@@@S?@%?S@@@
@@@%,:#:*#@@@@@@@@@@@@@@@@@@@@@#?+;++*S@#*+++#S%S@@@@@@@@@@@@@@?+:.,%..?#S@@@@*..%,.:+?@@@@@@@@@@@@@@S%S#+++*#@S*++;+?#@@@@@@@@@@@@@@@@@@@@@#*:#:,?@@@
@@@#%%#S@@@@@@@@@@@@@@@@@@@@@@@@@#S++;;*SS%%S??*++?@@@@@@@@@@@@#@%?*%++%@@@@@@%++%*?%@#@@@@@@@@@@@@?++*??S%%SS*;;++S#@@@@@@@@@@@@@@@@@@@@@@@@@S#%%#@@@
@@@?,,:+#@@S@@@@@@@@@@#@@@@@@@@@@S#@%;?+;*#%S?**??%%?S@@@@@@@@#+@?:....*#@#@@@*....:?@+#@@@@@@@@S?%%??**?S%#*;+?;%@#S@@@@@@@@@@#@@@@@@@@@@S@@#+:,.?@@@
@@@S*?%S#@@@@@@@@@@#@@##@##@#@@@#@@?%@?,;*+*@#%#?SS%%#@%@@@@@@#%@%+;+;;%SS%S%@%;;+;+%@%#@@@@@@%@#%%SS?#%#@*+*;,?@%?@@#@@@#@##@##@@#@@@@@@@@@@#S%??#@@@
@@@%;*@+?#@@@@@@@@@@@@@@###@@@@@#%S#@@@%*,**?#@#%S??%?%#@@@@@@@S?+;;%::?S?S%?%?,:%;;+?S@@@@@@@#%?%??S%#@#?**,*%@@@#S%#@@@@@###@@@@@@@@@@@@@@#?+@*;%@@@
#S@S++@+?@@@@@@@@@@@@%#%#@@@@@@%SS@@@@@@@**:+?#%?S%+++#S?*%#@@@%?;::S:,?%+%*???,:S::;?%@@@#%*?S#+++%S?%#?+:**@@@@@@@SS%@@@@@@#%#%@@@@@@@@@@@@?+@+;%@S@
S@##??%S@@@#@@@S##@@#@@@##@@@#S+#@@@@@@@@@%:+;+%?;?@##**?+;*#@#%@S?++;;%%?????%;;++?S@%#@#*;+?**##@?;?%+;+:%@@@@@@@@@#+S#@@@##@@@#@@##S@@@#@@@S%??S@#S
@%#?,,:+#@@#@@#S##SS@@##S#@@#?%@@@@@@@@@@@@#+;*+%S?*+S#??%S%?@#*@*:....??;+S*?*....:*@*#@?%S%??#S+*?S%+*;+#@@@@@@@@@@@@%?#@@#S##@@SS##S#@@#@@#+:,.?@S%
S?##%%#S#@@@@@@@##@#@@@#@#@#+?@@@@@@@@@@@@@@@+,;*##SS#@%@?*##@#S#%*+%++S*;+?;%%++%+*%#S#@##*?@%@#SS##*;,+@@@@@@@@@@@@@@@?+#@#@#@@@#@##@@@@@@@#S#%%##?%
?*#%,;#:*#@@@@##@@@@##@@#S%+S@@@@@@@@@@@@@@@@@*:,:%%?+?@##@%+@@%+:,,%..*+:;:;**..%,,:+%@@+%@##@?+?%%:,:*@@@@@@@@@@@@@@@@@S+%S#@@##@@@@##@@@@#*:#;,?S+*
**##?%@%S@@@@@S@@@@@@SS@##S*@@@@@@@@@@@@@@@@@@@+++*#*?S??+?%%@@SS*++S;;%+:%;:+?;;S++*SS@@%%?+??S?*#*+++@@@@@@@@@@@@@@@@@@@*S##@SS@@@@@@S@@@@@S%@%?S#*S
?*S?;;+*#@@S@@@SS###S@@@S**@@@@@@@@@@@@@@@@@@@@@;:,*@@*+*++*#@#?@%+::,:*?;%+;**,,::+%@?#@#*++*+*@@*,:;@@@@@@@@@@@@@@@@@@@@@**S@@@S###SS@@@S@@#*+;;?#?#
;;S%;;+?#@@@@@S#@###@@@#%*#@@@@@@@@@@@@@@@@@@@@@#;++S#@%S%SS?@#?@?;,,,,?+,,,,+?,,,,;?@?#@?SS%S%@#S++;#@@@@@@@@@@@@@@@@@@@@@#*%#@@@###@#S@@@@@#?+;;SS;;
?%SS?%@?S@@@@@@#S#@#@@S#*%@@@@@@@@@@@@@@@@@@@@@@@?:;+#SS@??SS@@#S?*+S;;??**?*??;;S+*?S#@@SS??@SS#+;:?@@@@@@@@@@@@@@@@@@@@@@@%*#S@@#@#S#@@@@@@S?@%?SS??
?*#%,:#:*#@@@@S#@@@@@@#%+@@@@@@@@@@@@@@@@@@@@@@@@@+;;S##%%#S+@@?+:.,%..*;,:?,;*..%,.:+?@@+S#%%##S;;+@@@@@@@@@@@@@@@@@@@@@@@@@*%@@@@@@@#S@@@@@*:#;,?@?;
S?S#%%#S@@@@@@##@@@@@@@*%@@@@@@@@@@@@@@@@@@@@@@@@@%;+%@??++*S@@#@%?*%++%*++?+*%++%*?%@#@@S*++??@%+;%@@@@@@@@@@@@#%%%%%%%%%%%%**%%%%%?%%%%%%%%??%????++
;:??,,:+#@@S@@@SSSS@@S%+@@@@@@@@@@@@@@@@@@@@@@@@@@@;,,%S*???%@#+@?:....*;....:*....:?@+#@%???*S%,,;@@@@@@@@@@@@@#%S*;;+SSSSS%;;;?%%?%S+;;*%SS%**;;;?;;
++%S??%S#@@@@@####@@##*%@@@@@@@@@@@@@@@@@@@@@@@@@@@?;+?@@?%#%@#%@%+;+;;%*;;;;*%;;+;+%@%#@%#%?@@?+;?@@@@@@@@@@@@@@@@@*:S@@@@@@%:?##@@##S+;#@@@@S#*:%%++
++S%;*@;?#@@@@@###@SS%+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@::;%@SS%?@@S?+::%::?*:?;,*?,:%::+?S@@?%SS@%;::@@@@@@@@@@@@@@@@@@+:S@@@@@@?:*#SS@###::@@@#?;@+,SS+%
,:?S++@+?@@@@@S@@@@S#?#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@S;++S?%S*@@%?;::S:,?;,?:,;?,:S::;?%@@*S%?S++;S@@@@@@@@@@@@@@@@@@*;#@@@@@@S;?%@S@@@@++@@@@%+@?;S?:%
??%#??%S@@@#@@@S##@#S+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:;;S?;*#@#%@S?++;;%*;++;*%;;++?S@%#@#*;?S;;:@@@@@@@@@@@@@@@@+;;::;;;++++;;;;;;;;+;;;;++;+++;;;;;;
::??,,:+#@@#@@#S#S#S*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%;;+SS%?@#*@*:....?;....:*....:*@*#@?%SS+;;%@@@@@@@@@@@@@@@@S?+,,,,,,,,,+?+,,,,,,;??:,,,,,,*?+,,,
,,*#S%#S#@@@@@@@##S%*@@@@@@@@@@@#*S##@@@@@@@@@@@#S%%@@;;+S%##@#S#%*+%++*,....:+++%+*%#S#@##%S+;;@@%%S#@@@@@@@@@@@##S?,+;;;;:+#+S+::;::S??%::;::*S*#;::
;*?%+;#:*#@@@@##@S#+S@@@@@@@@@@@#+?????%%%%%%%????*?@@%::*@%+@@%+:,,%.;*+:,,:+*;.%,,:+%@@+%@*::%@@?*????%%%%%%%???%%::*,,;?::***:::%::+**;::*+:;***:::
+S##?%@%S@@@@@S@@#%?@@@@@@@@@@@@@*%%%%%%%%%%%%%%%%+@@@@*;;SS%@@SS*++S;;*%+,,+%*;;S++*SS@@%SS;;*@@@@+%%%%%%%%%%%%%S*,..,;+?*........?........+;........
;S@?;;+*#@@S@@@S##SS@@@@@@@@@@@@@%*%%%%%%%%%%%%%%?*@@@@%*+%%#@#?@%+::,::S:..:S:,,::+%@?#@#%%+*%@@@@*?%%%%%%%%%%%%S%*,,;;:;*,,:::,,,?,.:::,.,+;.,:::,,.
:S@*;;+?#@@@@@S#SS%%@@@@@@@@@@@@@@+%%%%%%%%%%%%%%?%@@@@S+;+S*@#?@?;,,,::S:..;S:,:,,;?@?#@*S+;+S@@@@%?%%%%%%%%%%%%%%?*:*,,+*;+S?S*;;?;;%%%%;;*+;*S?S+;;
:S@#?%@?S@@@@@##%?+++@@@@@@@@@@@@@??%%%%%%%%%%%%%*@@@S:::+*??@@#S?*+S;+*#:..:S*;;S+*?S#@@??*+:::S@@@*%%%%%%%%%%%%S%*;.,;:,..:%*%:.....???*.....;%?%,..
:#@%,:#:*#@@@@@#S%?S#@@@@@@@@@@@@@??%%%%%%%%%%%%%+@@@@%+;+?%#@@?+:,,%..,%:..;S:..%,,:+?@@#%?+;+%@@@@+%%%%%%%%%%%#;:,,,,,,,,,,,;:,,,,,,,;;,,,,,,,:;,,,,
:#@#%%#S@@@@@@#%S##@@@@@@@@@@@@@@@??%%%%?+;??%%%%+@@@@@##S*+%@@S@%?*%++*#;..;#+++%*?%@S@@%+*S##@@@@@+%%%%??;+?%%SS+;;;;+?%?S########%+;;;;+%??#S%%S#S*
;S@+,,:+#@@S@@?*@@@@@@@@@@@@@@@@@@???%%**%%?+%%?%+@@@@@@@@@+,@#+@?:....,S:..:S.....:?@+#@,+@@@@@@@@@+%?%%+?%%**%%%,....,++*?@@@@@@@@*,....,?;??;,,?@S:
,%#%*?%S#@@@@@@@@@@@@@@@@@@@@@@@@@%**;?+*%%?+?*;?+@@@@@@@@@@#@#%@%+;+;;+%:..:%;;;+;+%@%#@#@@@@@@@@@@+?;*?+?%%*+?+?......+;**@@@@@@@@+......*,??%??##%,
:+?#+*@;?#@@@@@@@@@@@@@@@@@@@@@@@@@S?*+%*?%*%*+?S#@@@@@@@@@@@@@S?+::%::?;,,,,;?::%::+?S@@@@@@@@@@@@@#S?+*%*%?*%+?%......+;**@@@@@@@@+......?:?%@++#?+:
%#@#++@+?@@@@@@@@@@@@@@@@@@@@@@@@@@@@@S**%%?+%@@@@@@@@@@@@@@@@@%?;::S::+#%;;%#*::S::;?%@@@@@@@@@@@@@@@@@%+?%%**S@%......+;**@@@@@@@@+......?:?%@+?#@#%
%S*???%S@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@S++?@@@@@@@@@@@@@@@@@@#%@S?++;;;;?**?;;;;++?S@%#@@@@@@@@@@@@@@@@@@?++S@@@%......+;**@@@@@@@@+......?:??%???*S?
#;,,,,:+#@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@S%@@@@@@@@@@@@@@@@@@@#*@*:......:?%:......:*@*#@@@@@@@@@@@@@@@@@@@%S@@@@%......+;**@@@@@@@@+......?:??;,,:,;%
??%%%%#S#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#S#%*+%+;:+****+:;+%+*%#S#@@@@@@@@@@@@@@@@@@@@@@@@@%......+;**@@@@@@@@+......*,?%#%?+%??
..,::;#:*#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+:,,%.,;:*?S*:;,.%,,:+%@@@@@@@@@@@@@@@@@@@@@@@@@@%,....,++*?@@@@@@@@*,....,?;*%#:;?*%S
;+*???#*%######################################################%%+;;S;;??*??*?*;;S;;+%%#########################@S;,,.,:?**S@@@@@@@@?:,..,;%*?#@%?@S##
?+*+++*+****+;;+******;;;******+;;+*****+;;+******;;;******+;;+*?*++*+++*+**+*+++*++*?*+;;+******;;;******+;;+**S#S?:,+?**S@@@@@@@@@#S*,:*?*?S*+;:;;+@
#;%?:+S%#@@@S;:%@@@@@@*:*@@@@@@?;;S@@@@@S+:?@@@@@@*:+@@@@@@%;:%%@?;;?+:**:%S:**;;?;;?@%%;:%@@@@@@*:*@@@@@@?;;S@@@@@@?+@SS@@@@@@@@@@@@@@**@SS@#?+;;*;:S
++?S:+@?S@@@@;:#@@@@@@?,%@@@@@@#:;@@@@@@@+:#@@@@@@%,*@@#@SS#;:#SS?++#*:%;:;;:;%:+#++?SS#;:#SS@#@@?,%@@@@@@#:;@@@@@@@+;S#%@@@@@@@@@@@@@#;;#S%@S?@%??+++
..,?;*@:*@@@@+;@@@@@@@%:%@@@@@@#;+@@@@@@@*:#@@@@@@S:?S@@@@@@+;@?*:,,#*:*,....,?;+#,,:*?@+;@@@@@@S%:%@@@@@@#;+@@@@@%?;:*%?*?@@@@@@@@@#%*::???*%%#;:,,..
++?*;+%*?%%%?;;?%%%%%%+;*%%%%%%?;;?%%%%%%;;?%%%%%%*;+?%%%?%?;;???+++%+;*+;;;;+*;+%+++???;;?%?%%%?+;*%%%%%%?;;?%%%?++++++**+*%??%%%%%*++++++?*+?%****++
,,,:*;,,,,,,,++,,,,,,,:*:,,,,,,,*;,,,,,,,;*,,,,,,,:*:,,,,,,,++,,,,,,,;*:,,,,,,:*;,,,,,,,++,,,,,,,:*:,,,,,,,*;,,,,,,,;+,,,,,,,:*:,,,,,,,++,,,,,,,;*:,,,
,,:S*%*,,,,,%?*%,,,,,+S+S;,,,,,S*%?,,,,,?%*S,,,,,;S+S+,,,,,%*?%,,,,,*%*S:,,,,:S*%*,,,,,%?*%,,,,,+S+S;,,,,,S*%?,,,,,?%*S,,,,,;S+S+,,,,,%*?%,,,,,*%*S:,,
%;;%?%+;;%+;*%%?;;**;+%?%;;;%;;??%*;;?+;*%??;;+?;;%?%+;;%;;?%%*;;**;+%?%;;;%;;%?%+;;%+;*%%?;;**;+%?%;;;%;;??%*;;?+;*%??;;+?;;%?%+;;%;;?%%*;;**;+%?%;;;
%,,,:,,,,?:,,,,,,,+*,,,:,,,,%,,,,,,,,?;,,,:,,,;?,,,,,,,,%,,,,,,,,*+,,,,,,,:?,,,:,,,,?:,,,,,,,+*,,,:,,,,%,,,,,,,,?;,,,:,,,;?,,,,,,,,%,,,,,,,,*+,,,,,,,,
*+;;;;;?+;;;;+++++S++;;;;;%;;;;;++++*%++;;;;;%:;;;+++++??++;;;;+?;;;;+++++%*+;;;;;?+;;;;+++++S++;;;;;%;;;;;++++*%++;;;;;%:;;;+++++??++;;;;+?;;;;+++++%
:;+*;;;++?+;;:::::::;*+;;;++?;;:::::::;;?;;;;+**;;:::::::;;?;;;;+?+;;:::::::;+*;;;++?+;;:::::::;*+;;;++?;;:::::::;;?;;;;+**;;:::::::;;?;;;;+?+;;::::::
;:?,...,:;+*;;*;;;;:;?....,;;++;+*;;;;:+*....,;+*+;*+;;;;:*;...,:;+*;;*;;;;;:?,...,:;+*;;*;;;;:;?....,;;++;+*;;;;:+*....,;+*+;*+;;;;:*;...,:;+*;;*;;;;
:;?*:;;;::;::;?;;:;:;%+:;;;::;::+*;::;:+%;:;;::::::*+;:::;*?;;;;::;:::?;;:::;?*:;;;::;::;?;;:;:;%+:;;;::;::+*;::;:+%;:;;::::::*+;:::;*?;;;;::;:::?;;::
,,..,;;;++;:,,..,;*,..,:+;;*;::,,..:++,..,:+;;*;::,..,:*;,..,;;;;*;::,..,;?:,..,;;;++;:,,..,;*,..,:+;;*;::,,..:++,..,:+;;*;::,..,:*;,..,;;;;*;::,..,;?
::::;;;;+*;:::::;?,::::;;;;?+;:::::++,:::;;;;;?;;:::::*:::::;;;;;?;::::::?,::::;;;;+*;:::::;?,::::;;;;?+;:::::++,:::;;;;;?;;:::::*:::::;;;;;?;::::::?,
S+++;;;;;;;+S*+++*#?+++;;;;;;;+S++++*#*++;;;;;;;;?%++++%#+++;;;;;;;;%?+++*SS+++;;;;;;;+S*+++*#?+++;;;;;;;+S++++*#*++;;;;;;;;?%++++%#+++;;;;;;;;%?+++*%
)";
}