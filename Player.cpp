#include "Player.h"
#include "Game.cpp"
#include "Maps.h"

void Player::playerHUD(Player& player)
{
	system("cls");

	cout << " ______________________________________________";
	cout << "\n| Name: " << setw(38) << left << player.name << "|";
	cout << "\n| Class: " << setw(37) << left << player.player_class << "|";
	cout << "\n| Health: " << setw(5) << right << player.health << "/" << setw(5) << left << player.max_health << setw(27) << right << "|\n";
	drawHealthBar(player.health, player.max_health, 41); cout << " |";
	cout << "\n| Mana: " << setw(5) << right << player.mana << "/" << setw(5) << left << player.max_mana << setw(29) << right << "|\n";
	drawHealthBar(player.mana, player.max_mana, 41); cout << " |";
	cout << "\n| Weapon: " << setw(36) << left << player.equippedWeapon.name << "|";
	cout << "\n| Damage: " << setw(36) << left << player.equippedWeapon.damage << "|";
	cout << "\n| Strength: " << setw(34) << left << player.strength << "|";
	cout << "\n| Armor: " << setw(37) << left << player.equippedArmor.defense << "|";
	cout << "\n| Health potions: " << setw(28) << left << player.healing_potion << "|";
	cout << "\n| Mana potions: " << setw(30) << left << player.mana_potion << "|";
	cout << "\n|_____________________________________________|";

}



void Player::battleHUD(Player& player, Enemy& enemy)
{
	system("CLS");
	cout << "\n________________________________________________________________";
	cout << "\n| Name: " << setw(30 - 8) << left << player.name << " |"
		<< " Name: " << setw(29 - 6) << left << enemy.name << " |";
	cout << "\n| Class: " << setw(30 - 8) << left << player.player_class << "|"
		<< " Type: " << setw(29 - 5) << left << enemy.type << "|";
	cout << "\n| Level: " << setw(30 - 8) << left << player.level << "|"
		<< " Health: " << setw(26 - 5) << left << enemy.health << " |";
	cout << "\n| Health: " << setw(5) << right << player.health << "/" << setw(5) << left << player.max_health << setw(19 - 6) << right;
	drawHealthBar(enemy.health, enemy.max_health, 27);
	cout << " |\n";

	drawHealthBar(player.health, player.max_health, 26);
	cout << " | Strength: " << setw(32 - 9 - 4) << left << enemy.strength << " |";


	cout << "\n| Mana: " << setw(5) << right << player.mana << "/" << setw(5) << left << player.max_mana << setw(19 - 6) << right << "|"
		<< setw(33) << right << " |\n";
	drawHealthBar(player.mana, player.max_mana, 26);
	cout << " |" << setw(32) << right << " |";

	cout << "\n| Strength: " << setw(33 - 7 - 8) << left << player.strength << " |"
		<< setw(32) << right << " |";

	cout << "\n| Weapon: " << setw(35 - 7 - 8) << left << player.equippedWeapon.name << " |"
		<< setw(32) << right << " |";
	cout << "\n| Damage: " << setw(35 - 7 - 8) << left << player.equippedWeapon.damage << " |"
		<< setw(32) << right << " |";
	cout << "\n| Armor: " << setw(37 - 7 - 8) << left << player.equippedArmor.defense << "|"
		<< setw(32) << right << " |";
	cout << "\n| Health potions: " << setw(28 - 7 - 8) << left << player.healing_potion << "|"
		<< setw(32) << right << "|";
	cout << "\n| Mana potions: " << setw(30 - 7 - 8) << left << player.mana_potion << "|"
		<< setw(32) << right << " |";
	cout << "\n|______________________________|_______________________________|";

}



void Player::drawHealthBar(int current, int max, int length) {
	int barLength = static_cast<int>(static_cast<float>(current) / max * length);
	//static int prevBarLength = 0;
	std::cout << "| [";

	for (int i = 0; i < length; ++i) {
		if (i < barLength) {
			std::cout << "#"; // Display the filled part of the health bar
		}
		else {
			std::cout << " "; // Display the empty part of the health bar
		}
	}


	std::cout << "]";
}






void Player::levelUp(Player& player)
{
	/*if (player.exp >= player.expNext)
	{
		player.level++;
		player.exp = 0;
		player.expNext = player.expNext * 1.5;
		player.maxHP = player.maxHP + 10;
		player.HP = player.maxHP;
		player.damageMin = player.damageMin + 1;
		player.damageMax = player.damageMax + 1;
		player.defense = player.defense + 1;
		player.hpPot = player.hpPot + 1;
		cout << "You have leveled up!\n";
		system("pause");
	}*/

	while (true) {
		cout << "\nWhat would you like to Increase?\n"
			<< "1) Health\n"
			<< "2) Strength\n"
			<< "3) Mana\n";
		char choice;
		do
		{
			cout << "\n>";
			cin >> choice;
		} while (choice != '1' && choice != '2' && choice != '3');

		if (gameLevel == 1)
		{
			switch (choice)
			{
			case '1':
				player.max_health = player.max_health + 35;
				player.health = player.max_health;
				player.mana = player.max_mana;
				cout << "\nYour health is now " << player.max_health << "\n";
				break;
			case '2':
				player.max_strength = player.max_strength + 8;
				player.strength = player.max_strength;
				player.health = player.max_health;
				player.mana = player.max_mana;
				cout << "\nYour strength is now " << player.max_strength << "\n";
				break;
			case '3':
				player.max_mana = player.max_mana + 5;
				player.health = player.max_health;
				player.mana = player.max_mana;
				cout << "\nYour mana is now " << player.max_mana << "\n";
				break;
			default:
				cout << "Invalid choice\n";
				break;
			}
			break;
		}
		else if (gameLevel == 2)
		{
			switch (choice)
			{
			case '1':
				player.max_health = player.max_health + 100;
				player.health = player.max_health;
				player.mana = player.max_mana;
				cout << "\nYour health is now " << player.max_health << "\n";
				break;
			case '2':
				player.max_strength = player.max_strength + 25;
				player.strength = player.max_strength;
				player.health = player.max_health;
				player.mana = player.max_mana;
				cout << "\nYour strength is now " << player.max_strength << "\n";
				break;
			case '3':
				player.max_mana = player.max_mana + 20;
				player.health = player.max_health;
				player.mana = player.max_mana;
				cout << "\nYour mana is now " << player.max_mana << "\n";
				break;
			default:
				cout << "Invalid choice\n";
				break;
			}
			break;
		}
		else if (gameLevel == 3)
		{
			switch (choice)
			{
			case '1':
				player.max_health = player.max_health + 500;
				player.health = player.max_health;
				player.mana = player.max_mana;
				cout << "\nYour health is now " << player.max_health << "\n";
				break;
			case '2':
				player.max_strength = player.max_strength + 75;
				player.strength = player.max_strength;
				player.health = player.max_health;
				player.mana = player.max_mana;
				cout << "\nYour strength is now " << player.max_strength << "\n";
				break;
			case '3':
				player.max_mana = player.max_mana + 200;
				player.health = player.max_health;
				player.mana = player.max_mana;
				cout << "\nYour mana is now " << player.max_mana << "\n";
				break;
			default:
				cout << "Invalid choice\n";
				break;
			}
			break;
		}

	}
}

void Player::enemy(string eName, string etype, int eStrength, int eHP, int eXP, int eGold, string eItem) {
	//cout << "\nEnemy name: " << eName << "\nEnemy strength: " << eStrength << "\nEnemy health: " << eHP << "\nEnemy exp: " << eXP << "\nEnemy gold: " << eGold << "\nEnemy item: " << eItem << "\n";
	//string etype = "NULL";
	Enemy enemy(eName, etype, eStrength, eHP, eXP, eGold, eItem);
	this->mutilate_count = 0;
	this->shadow_flee = false;
	this->divine_heal_left = 3;
	this->flee = false;
	while (true) {
		this->battleHUD(*this, enemy);
		srand(static_cast<unsigned int>(time(0)));

		int RNG = 0, RNG_prot = 0, point_prot = 0, player_damage = 0;

		cout << "\n1) Attack\n"
			<< "2) Use health potion\n"
			<< "3) Use mana potion\n"
			<< "4) Spells\n"
			<< "5) Inventory\n"
			<< "6) Escape\n";
		char choice;
		do
		{
			cout << "\n>";
			cin >> choice;

		} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6');

		if (enemy.health > 0 && this->health > 0) {
			if (choice == '1') {
				srand(static_cast<unsigned int>(time(0)));

				RNG = rand() % (0 + 12) + 1;
				RNG_prot = rand() % (0 + 4) + 1;
				point_prot = 0;
				player_damage = max(0, this->strength + RNG + this->equippedWeapon.damage);
				enemy.health -= player_damage;

				Sleep(500);
				cout << "\nYou attacked " << enemy.name << " and dealt " << player_damage << endl;
				system("pause");

				if (this->shadow_hunter == true) {
					RNG = rand() % 100 + 1;
					if (RNG < 50)
					{
						int dice = rand() % 20 + 1;
						enemy.health -= dice;
					}
					else if (RNG < 75)
					{
						int dice = rand() % (10 + 20) + 1;
						player_damage = dice + this->strength + this->equippedWeapon.damage;
						enemy.health -= player_damage;

						cout << "\nYou dealt crit attack, doing " << player_damage << " extra damage\n";
					}
				}
				else if (this->dragon_knight)
				{
					RNG = rand() % 10 + 1;
					if (RNG < 50)
					{
						int dice = rand() % 5 + 1;
						point_prot += dice;
					}
				}


			}
			else if (choice == '6')
			{
				srand(static_cast<unsigned int>(time(0)));
				int flee_chance = rand() % (0 + 100) + 1;

				if (flee_chance > 50)
				{
					cout << "\nYou ran, and live to fight another day\n";
					this->flee = true;
					break;
				}
				else
				{
					cout << "\nYou failed to escape\n";
					system("pause");
				}

			}
			else if (choice == '5')
			{
				cout << "\nWeapon Inventory(W). Item Inventory(i). Spells(S). Armour(A).\n\n";
				char userInput = _getch();
				if (userInput == 'i') {
					order(this->inventory);
					_getch();
				}
				else if (userInput == 'w')
				{

					cout << endl << endl;
					order(this->weaponsinven);
					cout << "Index to change weapon, (E) to exit.\n";
					cin >> userInput;
					if (userInput == 'e')
					{
						continue;
					}
					else
					{
						this->switchWeapon(userInput - '0');
						system("pause");

					}

				}
				else if (userInput == 'a')
				{
					cout << "\n\n";
					order(this->armorInventory);
					cout << "\nIndex to change Armour, (E) to exit.\n";
					cin >> userInput;
					if (userInput == 'e')
					{
						continue;
					}
					else
					{
						this->switchArmor(userInput - '0');
						system("pause");

					}
				}
				else if (userInput == 's')
				{

					cout << "\n\n";
					order(this->spells);
					cout << endl;
					system("pause");

				}

			}
			else if (choice == '2') {
				//heal
				int heal_amount;
				heal_amount = this->max_health / 4;
				if (this->healing_potion > 0 && this->health < this->max_health) {
					this->healing_potion -= 1;
					this->health += heal_amount;
					system("pause");
				}
				else if (this->healing_potion <= 0)
				{
					cout << "\nYou have no health potions\n";
					system("pause");
				}
				else if (this->health >= this->max_health)
				{
					cout << "\nYou are already at full health\n";
					system("pause");
				}

			}
			else if (choice == '3') {
				//mana
				int heal_amount;
				heal_amount = this->max_mana / 2;
				if (this->mana_potion > 0 && this->mana < this->max_mana) {
					this->mana_potion -= 1;
					this->mana += heal_amount;
					system("pause");
				}
				else if (this->mana_potion <= 0)
				{
					cout << "\nYou have no mana potions\n";
					system("pause");
				}
				else if (this->mana >= this->max_mana)
				{
					cout << "\nYou are already at full mana\n";
					system("pause");
				}

			}
			else if (choice == '4')
			{

				string spell;

				order(this->spells);

				cout << "Spell: ";
				cin >> spell;

				if (spell == "G" || spell == "g")
				{
					hym_of_fireGiant_spell(*this, enemy);
				}
				else if (spell == "F" || spell == "f")
				{
					fire_bolt_spell(*this, enemy);
				}
				else if (spell == "S" || spell == "s" && this->mana >= 5)
				{
					//shadow_flee_spell(*this, enemy);
					if (this->flee == true)
					{
						break;
					}
				}
				else if (spell == "I" || spell == "i")
				{
					ice_blast_spell(*this, enemy);
				}
				else if (spell == "V" || spell == "v")
				{
					chaos_vortex_spell(*this, enemy);
				}
				else if (spell == "c" || spell == "C")
				{
					critical_strike_spell(*this, enemy);
				}
				else if (spell == "M" || spell == "m")
				{
					mutilate_spell(*this, enemy);
				}
				else if (spell == "D" || spell == "d")
				{
					divine_heal_spell(*this, enemy);
				}
				else if (spell == "H" || spell == "h")
				{
					heal_spell(*this, enemy);
				}


			}

			else {
				cout << "\nInvalid choice\n";


				continue;

			}
			if (this->flee == true) {
				cout << "\nYou ran, and live to fight another day\n";
				this->flee = false;
				break;
			}


			else if (enemy.health > 0)
			{
				int RNG = rand() % (0 + 12) + 1;
				int RNG_prot = rand() % (0 + 4) + 1;
				int point_prot = RNG_prot + this->equippedArmor.defense;
				int enemy_damge = max(0, enemy.strength + RNG - point_prot);
				this->health -= enemy_damge;


				cout << "\nYou took " << enemy_damge << " damage from " << enemy.name << ". Your health is " << this->health << endl;
				system("pause");
				if (this->health <= 0) {
					cout << "\nYou died\n";
					char null = _getch();
					exit(0);
				}
			}

			else if (enemy.health <= 0) {
				cout << "\nYou killed the " << enemy.name << "\n";
				if (this->sidequest_1_counter == 3)
				{
					this->quest1_kill_count++;
					cout << "You have " << this->quest1_kill_count << " kills for quest 1.";
					Sleep(1000);
				}
				this->killCount++;
				cout << "\nYou gained " << enemy.exp << " experience\nYou gained " << enemy.gold << " gold\n";
				this->gold += enemy.gold;
				this->exp += enemy.exp;

				if (enemy.item == "Dead Wife's Ring")
				{
					DisplayMsg("You found a ring.\n");
					this->sideboss_1_alive = false;
					this->ring = true;
					this->addItemToInventory("Dead Wife's Ring");

					DisplayMsg("You also find a key. Find out what it unlocks...\n");
					this->addItemToInventory("Prison Key", 1);


				}
				else if (enemy.item == "Erterene's Gauntlets")
				{
					DisplayMsg("You found Erterene's Gauntlets\n");
					this->sideboss_1_1_alive = false;
					ErterenesGauntlets ert;
					this->addToInventory(ert);

					this->sidequest_1_counter = 6;
					this->trader_talk_count = 3;
				}
				else if (enemy.item == "Naga Scales")
				{
					DisplayMsg("You killed the naga queen, and got naga scales");
					this->nagaQueenAlive = false;
					this->blacksmith_allow = true;

					this->addItemToInventory("Naga Scales", 1);


				}
				else if (enemy.item == "Mutilate")
				{
					DisplayMsg("You found Mutilate spell\n");
					this->mutilate = true;
					this->spells.emplace_back("(M)utilate 10 Mana");
				}

				else if (enemy.item == "Throne Room Key")
				{
					DisplayMsg("You found the Throne Room Key\nReturn to unknown helper, and continue forward.\n");
					this->addItemToInventory("Throne Room Key", 1);
					this->throneroom_key = true;
				}

				else if (enemy.item == "Orb Of Altyrus") {
					orb_of_altyrus = true;
					DisplayMsg("\nYou found the Orb of Altyrus\n"
						"The first of the Set of Legendary Altyrus Artifacts.\n"
						"return to the trader to find out more\n");
					this->mainquest_1_counter = 3;
					this->trader_talk_count = 3;
					this->tuskar_alive = false;
					OrbOfAltryus orb;
					this->addToInventory(orb);

				}
				else if (enemy.item == "Blade Of Altyrus")
				{
					BladeOfAltyrus blade;
					blade_of_altyrus = true;
					DisplayMsg("You have found the Legendary \"Blade Of Altyrus\"\n");
					this->addToInventory(blade);
					this->commander_alive = false;
					this->trader_talk_count = 5;
				}
				else if (enemy.item == "Knight Blade")
				{
					KnightBlade knight;
					this->lancelotAlive = false;
					this->addToInventory(knight);
				}
				else if (enemy.item == "Knight Armor")
				{
					knightArmor knight;
					this->addToInventory(knight);
					this->mordredAlive = false;
				}
				else if (enemy.item == "Soul Of Altyrus")
				{
					soul_of_altyrus = true;
					SoulOfAltyrus soul;
					addToInventory(soul);
					this->sideboss_5_alive = false;
					Ascension(*this);
					Ascension(hero);
				}
				else if (enemy.item == "Heart Of Altyrus")
				{
					heart_of_altyrus = true;
					HeartOfAltryus heart;
					addToInventory(heart);
					Ascension(*this);
					Ascension(hero);
					this->sideboss_6_alive = false;
				}
				else
				{
					this->addItemToInventory(enemy.item, 1);
					int RNG = rand() % (10) + 1;

					if (RNG < 7)
					{
						this->healing_potion += 2;
					}
					else if (RNG < 9)
					{
						this->mana_potion += 1;
					}
					else
					{
						this->healing_potion += 2;
						this->mana_potion += 1;
					}
				}


				if (this->exp >= 100 && this->level2_claimed == false) {
					levelUp(*this);
					this->level2_claimed = true;
					this->level = 2;
				}
				if (this->exp >= 250 && this->level3_claimed == false) {
					levelUp(*this);
					this->level3_claimed = true;
					this->level = 3;
				}
				if ((this->exp >= 500) && this->level4_claimed == false) {
					levelUp(*this);
					this->level4_claimed = true;
					this->level = 4;
				}
				if (this->exp >= 1000 && this->level5_claimed == false) {
					levelUp(*this);
					this->level5_claimed = true;
					this->level = 5;
				}
				if (this->exp >= 1800 && this->level6_claimed == false) {
					levelUp(*this);
					this->level6_claimed = true;
					this->level = 6;
				}
				if (this->exp >= 3000 && this->level7_claimed == false) {
					levelUp(*this);
					this->level7_claimed = true;
					this->level = 7;
				}
				if (this->exp >= 5000 && this->level8_claimed == false) {
					levelUp(*this);
					this->level8_claimed = true;
					this->level = 8;
				}
				if (this->exp >= 6000 && this->level9_claimed == false) {
					levelUp(*this);
					this->level9_claimed = true;
					this->level = 9;
				}
				if (this->exp >= 8000 && this->level10_claimed == false) {
					levelUp(*this);
					this->level10_claimed = true;
					this->level = 10;
				}
				if (this->exp >= 11000 && this->level11_claimed == false) {
					levelUp(*this);
					this->level11_claimed = true;
					this->level = 11;
				}
				if (this->exp >= 14000 && this->level12_claimed == false) {
					levelUp(*this);
					this->level12_claimed = true;
					this->level = 12;
				}
				if (this->exp >= 17100 && this->level13_claimed == false) {
					levelUp(*this);
					this->level13_claimed = true;
					this->level = 13;
				}
				if (this->exp >= 20000 && this->level14_claimed == false) {
					levelUp(*this);
					this->level14_claimed = true;
					this->level = 14;

				}
				if (this->exp >= 22000 && this->level15_claimed == false) {
					levelUp(*this);
					this->level15_claimed = true;
					this->level = 15;
				}
				if (this->exp >= 24000 && this->level16_claimed == false) {
					levelUp(*this);
					this->level16_claimed = true;
					this->level = 16;
				}
				if (this->exp >= 27000 && this->level17_claimed == false) {
					levelUp(*this);
					this->level17_claimed = true;
					this->level = 17;
				}
				if (this->exp >= 30000 && this->level18_claimed == false) {
					levelUp(*this);
					this->level18_claimed = true;
					this->level = 18;
				}
				if (this->exp >= 32500 && this->level19_claimed == false) {
					levelUp(*this);
					this->level19_claimed = true;
					this->level = 19;
				}
				if (this->exp >= 35000 && this->level20_claimed == false) {
					levelUp(*this);
					this->level20_claimed = true;
					this->level = 20;
				}

				Ascension(hero);


				cout << "\n\nPress Enter to Continue your adventure";
				char null = _getch();
				break;
			}
		}
		else if (this->health <= 0)
		{
			DisplayMsg("\nYou died\n");
			exit(0);
		}
	}

}
struct Boss : public Enemy
{
	Boss(string bossName, string bossType, int bossStrength, int bossHP, int bossXP, int bossGold, string bossItem) : Enemy(bossName, bossType, bossStrength, bossHP, bossXP, bossGold, bossItem) {}
	int maxHealth;
};

void Player::boss(string bossName, string bossType, int bossStrength, int bossHP, int bossXP, int bossGold, string bossItem) {

	// Initialize boss
	Boss boss(bossName, bossType, bossStrength, bossHP, bossXP, bossGold, bossItem);

	// Boss phases
	int bossPhase = 1;
	this->mutilate_count = 0;
	this->shadow_flee = false;
	this->divine_heal_left = 3;
	this->flee = false;
	while (!flee) {
		this->battleHUD(*this, boss);
		srand(static_cast<unsigned int>(time(0)));

		int RNG = 0, RNG_prot = 0, point_prot = 0, player_damage = 0, boss_damage = 0;

		cout << "\n1) Attack\n"
			<< "2) Use health potion\n"
			<< "3) Use mana potion\n"
			<< "4) Spells\n"
			<< "5) Inventory\n"
			<< "6) Escape\n";
		char choice;

		do {
			cout << "\n>";
			cin >> choice;
		} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6');

		if (boss.health > 0 && this->health > 0) {
			if (choice == '1') {
				// Player attacks boss

				srand(static_cast<unsigned int>(time(0)));

				RNG = rand() % (0 + 12) + 1;
				RNG_prot = rand() % (0 + 4) + 1;
				point_prot = 0;
				player_damage = max(0, this->strength + RNG + this->equippedWeapon.damage);
				boss.health -= player_damage;

				Sleep(500);
				cout << "\nYou attacked " << boss.name << " and dealt " << player_damage << endl;
				system("pause");

				if (this->shadow_hunter == true) {
					RNG = rand() % 100 + 1;
					if (RNG < 50)
					{
						int dice = rand() % 20 + 1;
						boss.health -= dice;
					}
					else if (RNG < 75)
					{
						int dice = rand() % (10 + 20) + 1;
						player_damage = dice + this->strength + this->equippedWeapon.damage;
						boss.health -= player_damage;

						cout << "\nYou dealt crit attack, doing " << player_damage << " extra damage\n";
					}
				}
				else if (this->dragon_knight)
				{
					RNG = rand() % 10 + 1;
					if (RNG < 50)
					{
						int dice = rand() % 5 + 1;
						point_prot += dice;
					}
				}
				else if(this->mage)
				{
					int spellRNG = rand() % 10 + 1;


					if (spellRNG == 1)
					{
						hym_of_fireGiant_spell(*this, boss);
					}
					else if (spellRNG == 2)
					{
						fire_bolt_spell(*this, boss);
					}
					else if (spellRNG == 3)
					{
						ice_blast_spell(*this, boss);
					}
					else if (spellRNG == 5)
					{
						chaos_vortex_spell(*this, boss);
					}
					else if (spellRNG == 4)
					{
						critical_strike_spell(*this, boss);
					}
					else if (spellRNG == 6)
					{
						mutilate_spell(*this, boss);
					}
					else if (spellRNG == 7)
					{
						divine_heal_spell(*this, boss);
					}
					else if (spellRNG == 8)
					{
						heal_spell(*this, boss);
					}
				}

			}
			else if (choice == '6') {
				//cant escape this fight
				DisplayMsg("\nTrying to run away, coward!!\n");

			}
			else if (choice == '5') {
				// Player checks inventory

				cout << "\nWeapon Inventory(W). Item Inventory(i). Spells(S). Armour(A).\n\n";
				char userInput = _getch();
				if (userInput == 'i') {
					order(this->inventory);
					_getch();
				}
				else if (userInput == 'w')
				{

					cout << endl << endl;
					order(this->weaponsinven);
					cout << "Index to change weapon, (E) to exit.\n";
					cin >> userInput;
					if (userInput == 'e')
					{
						continue;
					}
					else
					{
						this->switchWeapon(userInput - '0');
						system("pause");

					}

				}
				else if (userInput == 'a')
				{
					cout << "\n\n";
					order(this->armorInventory);
					cout << "\nIndex to change Armour, (E) to exit.\n";
					cin >> userInput;
					if (userInput == 'e')
					{
						continue;
					}
					else
					{
						this->switchArmor(userInput - '0');
						system("pause");

					}
				}
				else if (userInput == 's')
				{

					cout << "\n\n";
					order(this->spells);
					cout << endl;
					system("pause");

				}
			}
			else if (choice == '2') {
				// Player uses health potion
				//heal
				int heal_amount;
				heal_amount = this->max_health / 4;
				if (this->healing_potion > 0 && this->health < this->max_health) {
					this->healing_potion -= 1;
					this->health += heal_amount;
					system("pause");
				}
				else if (this->healing_potion <= 0)
				{
					cout << "\nYou have no health potions\n";
					system("pause");
				}
				else if (this->health >= this->max_health)
				{
					cout << "\nYou are already at full health\n";
					system("pause");
				}
			}
			else if (choice == '3') {
				int heal_amount;
				heal_amount = this->max_mana / 2;
				if (this->mana_potion > 0 && this->mana < this->max_mana) {
					this->mana_potion -= 1;
					this->mana += heal_amount;
					system("pause");
				}
				else if (this->mana_potion <= 0)
				{
					cout << "\nYou have no mana potions\n";
					system("pause");
				}
				else if (this->mana >= this->max_mana)
				{
					cout << "\nYou are already at full mana\n";
					system("pause");
				}
			}
			else if (choice == '4') {
				string spell;

				order(this->spells);

				cout << "Spell: ";
				cin >> spell;

				if (spell == "G" || spell == "g")
				{
					hym_of_fireGiant_spell(*this, boss);
				}
				else if (spell == "F" || spell == "f")
				{
					fire_bolt_spell(*this, boss);
				}
				else if (spell == "S" || spell == "s" && this->mana >= 5)
				{
					//shadow_flee_spell(*this, boss);
					if (this->flee == true)
					{
						break;
					}
				}
				else if (spell == "I" || spell == "i")
				{
					ice_blast_spell(*this, boss);
				}
				else if (spell == "V" || spell == "v")
				{
					chaos_vortex_spell(*this, boss);
				}
				else if (spell == "c" || spell == "C")
				{
					critical_strike_spell(*this, boss);
				}
				else if (spell == "M" || spell == "m")
				{
					mutilate_spell(*this, boss);
				}
				else if (spell == "D" || spell == "d")
				{
					divine_heal_spell(*this, boss);
				}
				else if (spell == "H" || spell == "h")
				{
					heal_spell(*this, boss);
				}

			}
			else {
				cout << "\nInvalid choice\n";
				continue;
			}

			// Boss attacks player
			if (boss.health > 0) {
				bossAttack(*this, boss);

			}

			// Check player's health
			if (this->health <= 0) {
				DisplayMsg("\n\"This is the Legend? HAHAHAHAHAHA, i am dissapointed. To think that i was worried about you. Rest in pain.\nThis world shall truly feel my wrath Muahaha\n!!!!\"");

				cout << "\nYou Died";
				char null = _getch();
				exit(0);
			}


			// Check if boss is defeated
			if (boss.health <= 0) {


				// Switch to phase 2
				if (bossPhase == 1) {
					DisplayMsg("\nAGghhhh, you have defeatted meeeee, noooooo......\n\nHhahaha, is that what you thought muahhaaa\nYou cant defeat mee. Die fool\n");
					bossPhase = 2;
					boss.max_health += 20000;
					boss.strength += 1000;
					// Boss regenerates health for phase 2
					boss.health = boss.max_health;
				}
				else {
					DisplayMsg("\nAgh,nooooo, What have you doneeee.\nI cant believe it, I... have lost... p-rrpptartr\n");
					if (boss.item == "Might Of Altyrus") {
						this->drakon_alive = false;
						MightOfAltryus Might;
						this->addToInventory(Might);

					}
					Ascension(*this);
					break;

				}
			}
		}
	}

}


void Player::bossAttack(Player& player, Boss& boss) {
	srand(static_cast<unsigned int>(time(0)));

	int RNG = rand() % (0 + 12) + 1;
	int RNG_prot = rand() % (0 + 8) + 1;
	int point_prot = RNG_prot + player.equippedArmor.defense;
	int bossDamage = max(0, boss.strength + RNG - point_prot);

	// Boss critical attack chance
	int critRNG = rand() % 100 + 1;
	if (critRNG < 10) {  // Adjust the critical chance as needed
		bossDamage *= 1.2;  // 1.2x for critical hit
		cout << "\nBoss landed a critical hit!\n";
	}

	player.health -= bossDamage;

	cout << "\nBoss attacked you and dealt " << bossDamage << " damage\n";
	system("pause");
}


void Player::bossSpecialMovePhase1(Player& player, Boss& boss) {
	srand(static_cast<unsigned int>(time(0)));
	int totaldamage = 0;
	int bossDamage = 0;
	for (int i = 0; i < 3; ++i) {
		int RNG = rand() % (0 + 12) + 1;
		int RNG_prot = rand() % (0 + 4) + 1;
		int point_prot = RNG_prot + player.equippedArmor.defense;
		bossDamage = max(0, boss.strength + RNG - point_prot);

		// Boss critical attack chance for each hit
		int critRNG = rand() % 100 + 1;
		if (critRNG < 5) {  // Adjust the critical chance, todo
			bossDamage *= 1.2;  // 1.2x damage for critical hit
			cout << "\nBoss landed a critical hit!\n";
		}
		totaldamage = bossDamage;
		player.health -= bossDamage;
	}

	cout << "\nBoss performed a fast strike and dealt " << totaldamage << " damage\n";

	system("pause");
}

void Player::bossSpecialMovePhase2(Player& player, Boss& boss) {
	// Boss uses heal spells in phase 2
	int healAmount = boss.maxHealth / 6;
	boss.health = min(boss.maxHealth, boss.health + healAmount);
	cout << "\nBoss used a healing spell and restored " << healAmount << " health\n";
	system("pause");
}

void Player::bossAttackPhase1(Player& player, Boss& boss) {
	int specialRNG = rand() % 10;  // Adjust as needed for the number of spells
	if (specialRNG == 0) {
		//Boss uses Drakon Fury
		bossSpecialMovePhase1(player, boss);
	}
	else {
		// Boss uses a regular attack
		bossAttack(player, boss);
	}
}

void Player::bossAttackPhase2(Player& player, Boss& boss) {
	// Boss uses spells and special moves in phase 2
	int spellRNG = rand() % 10;

	if (spellRNG == 0) {
		// Boss uses a heal spell
		bossSpecialMovePhase2(player, boss);
	}
	else {
		// Boss uses a regular attack
		bossAttack(player, boss);
	}
}