#pragma once

//all the stories and what not

#include "Intro.h"
#include "STLIB.h"
#include "Player.h"
#include "locations.cpp"

static void endLevel(Player& player);
static void newGamePlus(Player& player);

static void displayMsg(string text)
{
	for (auto c : text) {
		cout << c << flush;

		if (c == '\n') {
			Sleep(1000);
		}
		else {
			Sleep(rand() % 25 + 25);
		}
	}

}


//prologue 1
static void prologue1(Player& hero)
{

	string msg = "In the land of Altyrus, a world shrouded in mystery and magic, our protagonist awakens with no memory but a name-" + hero.name + ".\n As he opens his eyes, " + hero.name + " finds himself in a lush forest, surrounded by ancient ruins and enchanted creatures. \nConfused and disoriented, He discovers a weathered parchment nearby, foretelling of a legendary hero destined to thwart the plans of the malevolent Emperor Drakon."
		"\nEmperor Drakon, a tyrant who seeks to plunge Altyrus into eternal darkness, is a formidable force fueled by dark magic.\nLegends spoke of a hero, chosen by the elements, who would rise to confront Drakon and restore balance to the realm. Drakon, learning of these legends, did everything he could to stop his destruction."
		"\nBut in trying to avoid his impending doom, he unknowingly brought forth The architect of his own death into this world"
		"\nAnd little do you know, you are that chosen hero."
		"\nGuided by the whispers of the wind and the ancient legends, You set forth on a perilous journey."
		"\nThe fate of Altyrus rests on your shoulders, and the adventure is just beginning.";
	DisplayMsg(msg);

}

static void prologue2(Player& hero)
{
	DisplayMsg("You have arrived at the outskirts of Knights Temenos, the Stronghold of the Knight Commander,\nand the gateway to Drakon's Hold.\nDefeat the knight commander, destroy any remaining forces.\n");

}

static void prologue3(Player& hero)
{
	hero.mainquest_3 = true;
	DisplayMsg("You have reached the final stretch of your journey. Drakon lies just ahead\nBut will you be able to defeat him...\n");
}


//level 1 main  quest, tuskar at his layer
static void main_quest_1_1(Player& hero, int& x, int& y)
{
	if (!hero.sideboss_1_alive && !hero.sideboss_1_1_alive && hero.mainquest_1_counter == 0)
	{
		hero.mainquest_1 = true;
		DisplayMsg("Welcome back adventurer.You have defeated most of the forces of Tusk.\nNow,We must defeat Tuskar, the left hand of Drakon\n");
		hero.mainquest_1_counter = 1;
	}
	else if (hero.mainquest_1 && hero.tuskar_alive && hero.mainquest_1_counter <= 2)
	{
		DisplayMsg("Tuskar is a strong fighter, and a stronger mage. he uses several magic attacks.\nHe has destroyed our forces single handedly, and killed all of the mercenaries we sent.\nKill him for us please"
			"\nNot only that, but he holds the key to the gateway that leads to Drakon's hold. So you will have to fight him no matter what.\nI wish you good luck"
			"\nHis lair has a secret entrance, meet my envoy, he will guide you.\n");
		hero.mainquest_1_counter = 2;
	}
	else if (hero.mainquest_1 && hero.tuskar_alive == false && hero.mainquest_1_counter == 3)
	{
		DisplayMsg("Thank you for defeating Tuskar. You have saved our city.\nHere are your rewards\n+4000 gold\n+70000 experience\n+30 Armor");
		hero.gold += 4000;
		hero.exp += 7000;
		hero.healing_potion += 20;
		hero.mana_potion += 5;
		PlateMail platemail;
		hero.addToInventory(platemail);
		hero.mainquest_1_counter = 4;
	}
	else if (hero.mainquest_1 && !hero.tuskar_alive && hero.mainquest_1_counter >= 4)
	{
		DisplayMsg("We will never forget you Adventurer.\nThank you and good luck\n");
	}

}
static void informer(Player& player)
{
	if (hero.trader_talk_count == 3)
	{
		DisplayMsg("\nWelcome adventurer, i assume the trader sent you to me, to get the location of secret entrance. It is right here next to me.\nGood luck.\n");
	}
}
static void trader1(Player& hero, int& x, int& y)
{
	if (hero.trader_talk_count == 0 && hero.gameLevel == 1) {
		//string msg = "You have arrived at the city of Altyrus, the capital of the realm. \nAs you enter the city, you are greeted by the sight of a bustling marketplace, filled with merchants and adventurers alike. \nYou see a tavern nearby, and decide to enter to rest and recuperate.";
		string msg = "\n(You have just passed through mountains. As you look ahead, you see the Capital. Devoid of its beauty, withering, empty) \nA person greets you. \"Hello Adventurer, I have been waiting for your arrival. Most peculiar\n(You wonder who he is)\n\"I am a trader, I wander the lands, in search of goods, weapons, armor and spells. Meet me at my shop in the city, and we will talk more. Go on, A long journey awaits you.\"\n";
		DisplayMsg(msg);
		playerMap[y][x] = " ";
		Map[y][x] = " ";
		Map[6][16] = "0";
		playerMap[6][16] = "t";
		hero.trader_talk_count = 1;
	}
	else if ((hero.trader_talk_count == 1 || hero.trader_talk_count == 2) && hero.gameLevel == 1)
	{
		DisplayMsg("Welcome adventurer. I see you managed to survive the wild and make it here.\n\"What happened here?\", you ask... \"Drakon.His forces have overrun this city.\""
			"\n\"Save us brave warrior\"...");
		if (hero.trader_talk_count == 1)
		{
			DisplayMsg("\nHere are some items to help you in your endeavour.\n+500 Gold\n+5 Healing potions\n+1 Mana Potion");
			hero.gold += 500;
			hero.healing_potion += 5;
			hero.mana_potion += 1;
			hero.trader_talk_count = 2;
		}
	}
	else if (hero.trader_talk_count == 3 && hero.gameLevel == 1 && !hero.sideboss_1_alive)
	{
		main_quest_1_1(hero, x, y);
	}
	else if (hero.trader_talk_count == 4 || hero.trader_talk_count == 3 && hero.tuskar_alive == false && hero.gameLevel == 1)
	{
		DisplayMsg("Thank you for defeating Tusk and his orchish forces.\nBut the world is not free yet. To stop this evil, at its root.\"Drakon\".\nKill the Commander, and gain path into Drakon's hold.\nGo warrior\"");
		DisplayMsg("\n(You have gained access to the Knights Temenos)\n");
		if (hero.trader_talk_count == 3)
		{
			DisplayMsg("\nAs thanks, here, have these items.\n +50 armor\n +10 healing potions\n +10 mana potions ");
			ShadowArmor shadowarmor;
			hero.addToInventory(shadowarmor);
			hero.healing_potion += 10;
			hero.mana_potion += 10;
			hero.trader_talk_count = 4;
		}
	}
	else if (hero.trader_talk_count == 4 && hero.gameLevel == 2)
	{
		DisplayMsg("\n\"Welcomee adventurer, to the knights temenos.The Knight Commander, second in command of Drakon, lives here. We must defeat him and his knight army."
			"\nGood luck and keep in touch. i will offer new items if you need them");


	}
	else if (hero.trader_talk_count == 6 && hero.commander_alive == false && hero.gameLevel == 2)
	{
		DisplayMsg("You have defeated the Commander. You have gained path into Drakon's hold.\nGo forth, and destroy his forces. Kill him, and reclaim the final pieces of the set of Altyrus.\n");
		hero.trader_talk_count = 6;
	}
	else if (hero.trader_talk_count == 7)
	{
		DisplayMsg("You have defeated Drakon and his forces. You have reclaimed the final pieces of the set of Altyrus.\n"
			"You have saved the realm of Altyrus. You are the hero of Altyrus.\n");

	}

}

//first quest, given by a soldier at te goblin camp
static void story_1_1(Player& hero, int x, int y)
{
	string msg;
	if (Map[y][x] == "1" && hero.ring == false && hero.sideboss_1_alive == true && (hero.sidequest_1 == false || hero.sidequest_1))
	{
		hero.sidequest_1 = true;
		msg = "\nI want revenge on him for what he did to my wife...\n"
			"if anyone can get her ring, i will reward him...\n";
		displayMsg(msg);
		Sleep(500);
		if (playerMap[51][6] != "G")
		{
			msg = "I have revealed the location of the goblin warrior. "
				"\nPlease avenge my wife...";
			DisplayMsg(msg);
			Sleep(500);

			msg = "\nLocation revealed at: (51,6) as G\n";
			DisplayMsg(msg);
			playerMap[51][6] = "G";

		}
		else if (playerMap[51][6] == "G")
		{
			msg = "\nHe is at inside the camp, i've marked him as G\n";
			DisplayMsg(msg);

		}
		goto end;
	}
	if (Map[y][x] == "1" && hero.sidequest_1 == true && hero.sideboss_1_alive == false && hero.findItemInInventory("Dead Wife's Ring")) {
		system("cls");
		msg = "\nHello adventurer.I see you managed to defeat the goblins.\n"
			"Their ring leader, a goblin warrior killed my wife. And you have killed him.\n";
		DisplayMsg(msg);

		msg = "\n(You give him the Dead Wife's ring)\n";
		DisplayMsg(msg);

		hero.removeItemFromInventory("Dead Wife's Ring");

		msg = "\nThank you for avenging my wife. and granting me some closure.\n";
		DisplayMsg(msg);
		DisplayMsg("Here's your reward.\n+80 gold. +45 exp");
		hero.gold += 80;
		hero.exp += 45;

		msg = "\nAgh we dont have much time. The wild is a dangerous place to be.\n"
			"Meet me in the city north of here\n";
		DisplayMsg(msg);


		Map[y][x] = " ";
		playerMap[y][x] = " ";
		Map[25][12] = "1";
		playerMap[25][12] = "N";

		hero.sidequest_1_counter = 1;


		msg = "\n(An enemy attacks you...)"
			"\nKill the beast, and meet me in the city, then we'll talk...\n";
		DisplayMsg(msg);

		hero.enemy("Wild Wolf", "Normal", 3, 60, 35, 5, "Wolf Pelt");
		goto end;
	}

	//save person from prison if gate is opened, and get a reward
	if (Map[y][x] == "3" && hero.sidequest_1 == true && hero.sideboss_1_alive == false && Map[53][7] == " ")
	{

		system("cls");
		cout << "Thank you for saving me. We are in your debt.\nI wish to reward you. I have a sword, some potions, and armor. What would you like?\n1) Old Sword +7\n2)Old Armor +3\n3) +2 HP potions\n";
		//displayMsg(msg);
		char userChoice;
		do
		{
			cout << "\n>";
			cin >> userChoice;
		} while (userChoice != '1' && userChoice != '2' && userChoice != '3');

		if (userChoice == '1')
		{
			OldSword oldsword;
			hero.addToInventory(oldsword);
		}
		else if (userChoice == '2')
		{
			OldArmor oldarmor;
			hero.addToInventory(oldarmor);
		}
		else if (userChoice == '3')
		{
			hero.healing_potion++;
			hero.healing_potion++;
		}


		msg = "You can now enter the city.\n";
		hero.cityAllow = true;
		displayMsg(msg);

		hero.sidequest_1_counter = 2;
		hero.sideboss_1_alive = false;
		hero.ring = true;
		Map[y][x] = " ";
		goto end;
	}


	//
	if (Map[y][x] == "1" && hero.sidequest_1 == true && hero.sideboss_1_alive == false && hero.sidequest_1_counter < 3)
	{
		system("cls");
		msg = "\nI see you managed to survive the wild. Congratulations.\n"
			"It wasn't always like this. Ever since the orcs attacked, it has been a deathwish to stay here.\n"
			"Could you defeat the enemies? for us?\nQuest aquired \"Kill 10 or more enemies in the area\"";
		hero.addItemToInventory("\"Kill 10 or more enemies in the area\"",10);
		hero.quest1_kill_count = 0;
		displayMsg(msg);

		system("pause");
		hero.sidequest_1_counter = 3;
		hero.sidequest_1 = true;
		goto end;

	}
	if (Map[y][x] == "1" && hero.quest1_kill_count < 10 && hero.sidequest_1_counter <= 4 && hero.sideboss_1_1_alive == true && hero.sidequest_1 == true)
	{
		DisplayMsg("Kill 10 or more enemies to weaken the enemy forces\n");
		cout << "\nCurrent Kills: " << hero.quest1_kill_count;
		Sleep(1000);
		goto end;

	}
	if (Map[y][x] == "1" && hero.quest1_kill_count >= 10 && hero.sidequest_1_counter <= 4 && hero.sideboss_1_1_alive == true && hero.sidequest_1 == true)
	{
		system("cls");

		msg = "Thanks brave warrior, You have weakened the enemies.\n";
		displayMsg(msg);
		system("pause");

		msg = "Kill their sectional boss.\n";
		displayMsg(msg);

		system("pause");

		msg = "Their leader is `Erterene` , He has been terrorizing us.\n"
			"kill him for us, and you will be rewarded.\n"
			"His lair is to the southeast of the city, in a jungle. Be careful though, he is quite strong\n";
		displayMsg(msg);

		system("pause");

		hero.sidequest_1_counter = 4;
		goto end;

	}
	if (hero.sideboss_1_1_alive == false && hero.sideboss_1_alive == false && hero.sidequest_1 == true && hero.sidequest_1_counter == 6)
	{
		Map[42][23] = " ";
		playerMap[42][23] = " ";
		system("cls");
		DisplayMsg("\nThank you traveler. You have saved our city\n");
		system("pause");
		DisplayMsg("\nHere, take my Short Sword to help you on your journey\n");
		system("pause");

		hero.sidequest_1_counter = 7;
		//hero.changeWeapon(shortsword);
		LongSword longsword;
		hero.addToInventory(longsword);
		hero.sidequest_1 = false;
		hero.sideboss_1_alive = false;
		goto end;

	}
	if (Map[y][x] == "1" && hero.sideboss_1_1_alive == false && hero.sideboss_1_alive == false && hero.sidequest_1 == true && hero.sidequest_1_counter >= 7)
	{
		system("cls");
		msg = "Thank you for your help brave adventurer. Your Help will never be forgotten by us..."
			"\nDo inquire if you need any help...\n";
		system("pause");

		goto end;

	}
end:
	{
	}
}


//kill dungeon and stuff from chief
static void story_1_2(Player& player)
{
	if (hero.sidequest_2 == false)
	{
		displayMsg("Hello," + hero.name + ", i have been waiting for you.\nIve heard of your brave acts,\n..And your history.\nI have a task for you");
		hero.sidequest_2 = true;
		goto end;
	}
	if (hero.sidequest_2)
	{
		displayMsg("As you know, we are under the malevolant rule of Drakon and his minions.He has reduced our once great city to rubble.\n"
			"Traders and visitors barely come here. We have no resources left.The source of our surrounding `issues` is a dungeon, in the north mountain.\n"
			"It spews new monsters on the daily and has been a thorn in our hind. Take care of it, and i will reward you greatly.\n");
		hero.sidequest_2_counter = 1;
	}
	if (hero.sidequest_2 && hero.sidequest_2_counter <= 2 && !hero.sideboss_2_alive && hero.dungeon_clear)
	{
		displayMsg("Thank you for clearing the dungeon.\nYou have saved my city,even though it is my job as the chief.But you have accomplished it.\nTake my sword and armor, for you have more need of it than I\n");

		ChiefSword sword;
		chiefArmor armor;
		hero.addToInventory(sword);
		hero.addToInventory(armor);
		hero.sidequest_2_counter = 3;
	}
	else if (hero.sidequest_2 && !hero.sideboss_2_alive && hero.dungeon_clear)
	{
		displayMsg("Thank you for clearing the dungeon.\nYou have saved my city,even though it is my job as the chief.But you have accomplished it.\nYou will never be forgotten");


	}
end:
	{
	}
}




//level 2 first quest given when you pass through the mountains
static void story_2_1(Player& player, int x, int y)
{
	DisplayMsg("\nA warning is displayed near the path\n");
	DisplayMsg("\n\"Welcome, to your death, the Knight's Temenos. Death awaits to all those who dare.\nCommand thee to escape, Attack if thee disvalue thou life.\"\n");

}

//level 2 second quest given by the knight at the entrance of the knights temenos
static void story_2_2(Player& player, int x, int y)
{
	if (hero.sidequest_2_2 == false && Map[y][x] == "2")
	{
		DisplayMsg("Welcome to the knight's Temenos.The fortress of The commander.\nIt is highly fortified, and has 100s of knights inside.\nBe careful and may Alterion be with you.\n");
		Map[y][x] = " ";
		playerMap[y][x] = " ";
		Map[29][32] = "2";
		playerMap[29][32] = "!";
		hero.sidequest_2_2 = true;

	}
	else if (hero.sidequest_2_2 == true)
	{
		DisplayMsg("Im ..sor-ry adve..entureer.... I couldnt defeat them, \naghhh, they were too strong for me....\n(coughs Blood)\nAgh, this is it for me. You must defeat them. \nGood luck"
			"\nHere take my sword, armor and some potions.\n");


		SilverSword  silver;
		SilverArmor  siver;
		hero.addToInventory(silver);
		hero.addToInventory(siver);

		hero.mana_potion += 2;
		hero.healing_potion += 5;

		Map[y][x] = " ";
		playerMap[y][x] = " ";
	}
}

//level 2 third quest given by the a unknown helper at the locked door to the throne room
static void story_2_4(Player& player)
{
	if (hero.sidequest_2_4 == false && hero.sideboss_2_4 == true)
	{
		DisplayMsg("Hello " + player.name + ". Are you looking to go after the Knight Commander?\nWell unfortunately, the path ahead is blocked, and it needs a key."
			"\nthe key is with a High ranking knight, Valeron.\nKill him and bring the key here.");
		hero.sidequest_2_4 = true;

	}
	else if (hero.sidequest_2_4 == true && hero.sideboss_2_4 == false)
	{
		DisplayMsg("Thank you for killing Valeron. \nLet us move into the throne room.\n");
		hero.gold += 5000;
		hero.exp += 5000;
		hero.healing_potion += 20;
		hero.mana_potion += 5;
		hero.sidequest_2_4 = false;

	}
	else if (hero.sidequest_2_4 == false && hero.sideboss_2_4 == false)
	{
		DisplayMsg("What are you waiting for? Lets move in already.\n");

	}
}



static void story_2_7(Player& player)
{
	if (hero.sidequest_2_7 == false && hero.hiddenKey == false)
	{
		hero.sidequest_2_7 = true;
		DisplayMsg("\n(You find an man, cladded in armor, sitting peacefully) He seems like a knight.\n\"Who are you?\", you ask.\"I am a knight. or atleast i was one, until i was banished.\"\n"
			"\"I spoke against the evils they were commiting and they banished me.What do you want?\".\n\"I want to defeat Drakon and his forces\", you reply.\n\"Hahahahahhaaa, Defeat Drakon???"
			"You must be out of your mind hahaha......Unlessss. Fight me brave warrior\"");
		player.enemy("Banished Knight", "Knight", 200, 4000, 5000, 4000, "Hidden Path Key");
	}
	else if (hero.sidequest_2_7 == true && hero.hiddenKey == true)
	{

		DisplayMsg("\"Hahahaha, I see potential in you warrior.\nHere have this key,it leads straight into the throne room,the door is located the cellar room\nGood luck, we shall meet again"
			" You have gained the key to the hidden path.\n");
		hero.sidequest_2_7 = false;
	}
	else if (hero.sidequest_2_7 == false && hero.hiddenKey == true)
	{
		DisplayMsg("You have the key to the hidden path. Go to the cellar room and open the door.\n");
	}
}


static void symbol_of_power(Player& hero)
{
	if (hero.tuskar_alive == false && hero.sideboss_1_alive == false && hero.sideboss_1_1_alive == false && hero.nagaQueenAlive == false && hero.sideboss_2_alive == false && hero.orb_of_altyrus && hero.symbolOfPower == false && hero.monarch == true)
	{
		DisplayMsg("You have the necessary requirements for the Secret Quest, Symbol of Power...\nYou have exceeded the limits...\nCalculating...\nCalculating...\nCalculating...\nGained extra power..."
			"\n+500 Health, 100+ mana, 40+ strength\n");
		hero.max_health += 500;
		hero.max_mana += 100;
		hero.max_strength += 40;
		hero.symbolOfPower = true;
	}
	else if(hero.tuskar_alive == false)
	{
		DisplayMsg("\nYou have defeated tuskar and unlocked the gateway to the Knights temenos, good luck");

	}
}


static void battle_1_1(Player& player, int x, int y) {

	srand(static_cast<unsigned int>(time(0)));

	int RNG = 1 + rand() % (100);


	if (RNG < 40) {
		std::cout << "From the shadows, a Bog Imp attacks you\n";
		Sleep(1500);
		player.enemy("Bog Imp", "Normal", 2, 80, 60, 30, "Imp Tooth");
	}
	else if (RNG < 70) {
		std::cout << "A Rattling sneaks up behind you\n";
		player.enemy("Rattling", "Normal", 4, 100, 80, 45, "Rattling Fur");
	}
	else if (RNG < 100) {
		std::cout << "You see a Lesser Demon ready to feed\n";
		player.enemy("Lesser Demon", "Demon", 7, 120, 100, 50, "Demon Bone");
	}

}

static void battle_1_2(Player& player, int x, int y)
{

	srand(static_cast<unsigned int>(time(0)));

	int RNG = 1 + rand() % (100);

	if (RNG < 30) {
		std::cout << "A Shadow Beast appears\n";
		Sleep(1500);
		player.enemy("Shadow Beast", "Beast", 15, 180, 350, 150, "Beast skin");
	}
	else if (RNG < 70) {
		std::cout << "A Chaos denizen attacks you. \"All paths lead to your death\".\n";
		Sleep(1500);
		player.enemy("Chaos Denizen", "Demonic", 22, 250, 400, 180, "Chaos gem");
	}
	else if (RNG < 95) {
		std::cout << "A Diamond Dragon. \"Prepare to die Mortal\" it says.\n";
		Sleep(1500);
		player.enemy("Diamond Dragon", "Dragon", 25, 300, 500, 200, "Diamond");
	}
	else
	{
		cout << "A crowned Lich attacks you.\n";
		Sleep(1500);
		player.enemy("Crowned Lich", "Undead", 45, 550, 800, 500, "Lich Blade");
	}
}

static void battle_1_3(Player& hero, int x, int y)
{
	srand(static_cast<unsigned int>(time(0)));

	int RNG = 1 + rand() % 10;

	if (RNG < 5)
	{
		std::cout << "A Naga appears\n";
		Sleep(1500);
		hero.enemy("Naga", "Water", 25, 380, 550, 250, "Naga Scales ");
	}
	else if (RNG < 8)
	{
		std::cout << "A Steel Jaw attacks you.\n";
		Sleep(1500);
		hero.enemy("Steel Jaw", "Beast", 36, 450, 600, 220, "Steel Fang");
	}
	else if (RNG < 9)
	{
		std::cout << "A dumb Ogre attacks you.\n";
		Sleep(1500);
		hero.enemy("Ogre", "Dumb", 45, 600, 630, 280, "Ogre Club");
	}
	else
	{
		cout << "An Arch Lich King ambushes you.\n";
		Sleep(1500);
		hero.enemy("Arch Lich King", "Undead King", 50, 750, 800, 800, "Frostmourne Shard");
	}

}
static void battle_2_1(Player& player)
{
	srand(static_cast<unsigned int>(time(0)));
	int RNG = 1 + rand() % 10;

	if (RNG < 4)
	{
		cout << "\nSquire attacks you";
		player.enemy("Squire", "Normal", 50, 600, 1000, 500, "Silver Piece");

	}
	else if (RNG < 7)
	{
		cout << "\nYou encounter a wild Death Larpus";
		Sleep(1500);
		player.enemy("Death Larpus", "Undead", 80, 1000, 1500, 1500, "Blight Stone");
	}
	else if (RNG <= 10)
	{
		cout << "A Knight spots you.";
		Sleep(1500);
		player.enemy("Knight", "Apprentice", 100, 2000, 1500, 1500, "Knight Armor piece");
	}
	else
	{
		cout << "A Knight spots you.";
		Sleep(1500);
		player.enemy("Knight", "Warrior", 150, 2500, 5000, 2500, "Knight Blade Shard");
	}
}

static void battle_2_2(Player& player)
{
	srand(static_cast<unsigned int>(time(0)));
	int RNG = 1 + rand() % 10;

	if (RNG < 6)
	{
		cout << "\nKnight attacks you";
		Sleep(1500);
		player.enemy("Knight", "Warrior", 320, 3000, 5500, 2500, "Gold Piece");

	}
	else
	{
		cout << "A Knight spots you.";
		Sleep(1500);
		player.enemy("Knight", "Striker", 300, 3500, 5000, 2000, "Platinum piece");
	}
}

static void battle_3_1(Player& player)
{
	
		cout << "Fighting the Watch Knight ";
		Sleep(1500);
		player.enemy("Knight", "Watcher", 450, 3500, 8000, 2000, "Platinum piece");
	
}
static void battle_3_2(Player& player)
{
	srand(static_cast<unsigned int>(time(0)));
	int RNG = 1 + rand() % 10;

	if (RNG < 6)
	{
		cout << "\nKnight attacks you";
		Sleep(1500);
		player.enemy("Knight", "Warrior", 500, 3000, 8000, 2500, "Gold Piece");

	}
	else
	{
		cout << "A Knight spots you.";
		Sleep(1500);
		player.enemy("Knight", "Striker", 600, 3500, 8000, 2000, "Platinum piece");
	}
}



static void Boss_Battles_1(Player& hero, int x, int y)
{

	if (hero.sideboss_1_alive == true && hero.sidequest_1 == true && Map[y][x] == "2")
	{
		displayMsg("You find the goblin warrior. Kill him and reclaim the ring.\n");
		displayMsg("\"You have come to your doooommmm\"... \nGet ready to fight...");
		system("pause");
		hero.enemy("Top G", "Goblin Warrior", 25, 400, 550, 450, "Dead Wife's Ring");
	}
	if (hero.sideboss_1_1_alive == true && hero.sidequest_1 == true && Map[y][x] == "4")
	{
		displayMsg("Boss encountered. Prepare to fight");
		hero.enemy("Erteres", "Brawler", 45, 800, 1000, 800, "Erterene's Gauntlets");

	}
	if (hero.mainquest_1 == true && hero.tuskar_alive == true && hero.mainquest_1_counter >= 1 && Map[y][x] == "6")
	{
		displayMsg("\nBUAWWHAHAAHAA. You've come this far, only to meet your doooommm. HAHAHHAAAAAA\"\nPrepare to Fight...");
		system("pause");

		hero.enemy("Tusk", "High Shaman",45, 1500, 2500, 2550, "Orb Of Altyrus");
	}
	if (hero.sidequest_4) {
		if (hero.mainquest_2 && hero.commander_alive && Map[y][x] == "9")
		{
			displayMsg("The Commander himself descends to kill you.\nConsider this an honor. And prepare for your death.\n");
			hero.enemy("Knight Commander Igneel", "Commander", 350, 5000, 8000, 7500, "Blade Of Altyrus");
		}
	}

	if (hero.mainquest_3 && hero.drakon_alive && Map[y][x] == "D")
	{
		displayMsg("You have reached the end, Drakon himself stands infront you, towering over you.\nYou prepare yourself, as a wave of uneasiness passes over you."
			"\nDrakon speaks,\"Welcome fleshling, even though you have defeated my army, and my commanders, but you will never defeat meeeeee\",\n\"I am Death, I am the END, I AM DRAKKOONNNNN!!!\"");
		hero.boss("Emperor Drakon", "Emperor", 5000, 35000, 50000, 50000, "Might Of Altyrus");
	}
}

static void enterThroneTalk()
{
	DisplayMsg("\nYou have made it this far, now only DRAKON remains. Kill him.");
}

static void talk_with_Altyrus(Player& player)
{
	system("cls");
	DisplayMsg("\n\"Welcome " + player.name + ". Congratulations on making it this far, you have truly proved yourself worthy of my power.\", the trader says.\"Your power??\", you ask.\"Yes. I am not a trader, but rather,\n\nI AM ALTYRUS Incarnate\n"
		"\nI have been waiting for a warrior, who would save me from this blight that is DRAKON.\nFor a thousand years, he has ravaged my land, my people, and my world.\nI am an avatar of the world itself.\nAnd i have brought you, into this world, to save us\n"
		"You have my eternal thanks. Thank you for heeding my call, and saving us all.\n\nThis is goodbye, you will be sent back to your world, Good luck and goodbye\n");
	endLevel(hero);
}

static void Ascension(Player& player)
{

	if (player.orb_of_altyrus && player.blade_of_altyrus && player.heart_of_altyrus && player.soul_of_altyrus && player.might_of_Altyrus && player.Legend_Of_Altyrus == false )
	{
		system("cls");
		DisplayMsg("You have all the requirements for \"Legend Of Altyrus\"\nAscending...Ascending...Ascending\nLegend awaken...Legend incarnate...Legend embodied...\nAwaken Legend Of Altyrus");
		player.Legend_Of_Altyrus = true;
		player.level = 999999;
		player.max_health += 50000;
		player.max_mana += 10000;
		player.max_strength += 5000;
		player.strength += 5000;
		player.health = player.max_health;
		player.mana = player.max_mana;
		
		player.mainquest_3 = true;
		//play();
	}
	if(player.orb_of_altyrus && player.blade_of_altyrus && player.heart_of_altyrus && player.soul_of_altyrus && player.ascended1 == false )
	{
		system("cls");

		DisplayMsg("\nOrb Of Altyrus found, increased Spell damage by 100%\nBlade Of Altyrus found, Increased Damage by 2000\nSoul of Altyrus found, increased Mana by 5000\n Heart Of Altyrus found, Increased Health by 15000\n"
			"You have the necessary requirements for Ascension, Ascension acquired, Level oo.\n");
		player.level = 9999;
		player.max_health+=15000;
		player.max_mana += 5000;
		player.max_strength += 2000;
		player.strength += 2000;
		player.ascended1 = true;
		player.health = player.max_health;
		player.mana = player.max_mana;

	}
	
}

static void endLevel(Player& hero)
{
	//end if all enemies bosses are dead
	if (!hero.sideboss_1_alive && !hero.sideboss_1_1_alive && hero.tuskar_alive == false && hero.gameLevel == 1)
	{
		hero.gameLevel = 2;
		cout << "\nYou have defeated the Orcs and the Goblins. The city is safe for now.\n"
			"However, the Orcs and Goblins are not the only ones who want to destroy the city.\n"
			"Go to the next city and find out who is behind all this.\n";
		system("pause");
		cout << "\nYou Decide to Go to Knights Temenos.\n";
		system("pause");
		hero.cityLevel = false;
		hero.knightsTemenos = true;
		playerMap = playerKnight;
		Map = knightsTemenos;

		hero.xPos = 5; hero.yPos = 4;
	}
	if (!hero.lancelotAlive && !hero.mordredAlive && !hero.commander_alive && hero.gameLevel == 2)
	{
		hero.gameLevel = 3;
		Map = DrakonHold;
		playerMap = Drakon_playerMap;
		hero.xPos = 6;
		hero.yPos = 12;

		DisplayMsg("Knight Commander Igneel and his forces have been defeated.\nYou have obtained the Orb and Blade of Altyrus. (2/5) set of Altyrus."
			"\nGo forth to Drakon's Hold, destroy his forces, Kill him and reclaim the final pieces of the set of Altyrus.\n");
	}
	else if (!hero.sideboss_5_alive && !hero.sideboss_6_alive && hero.mainquest_3 && !hero.drakon_alive && hero.gameLevel == 3)
	{
		DisplayMsg("You have defeated Drakon and his forces. You have reclaimed the final pieces of the set of Altyrus.\n"
			"You have saved the realm of Altyrus. You are the hero of Altyrus.\n");
		
		//Intro intro;
		//intro.mainMenu();
	}
}



static void endGame(Player& hero)
{
	if (hero.Legend_Of_Altyrus)
	{
		DisplayMsg("You have defeated Drakon and his forces. You have reclaimed the final pieces of the set of Altyrus.\n"
			"You have saved the realm of Altyrus. You are the hero of Altyrus.\n");
		//Intro intro;
		//intro.mainMenu();
	}
}

static void newGamePlus(Player& player)
{
	//newGme plus.
	string choice;
	getline(cin, choice);

	if(choice == "Yes" || choice == "yes" || choice == "y" || choice == "Y")
	{
		displayMsg("\nYou decided to start all over again, good luck adventured.\n");
		Intro intro;
		intro.start(player);
	}
}