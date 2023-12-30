#pragma once

#include "STLIB.h"
#include "items.h"

struct Boss;

static void DisplayMsg(string text)
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
	cout << endl;
	system("pause");
}


struct Enemy {
	string name;
	string type;
	int strength;
	int health;
	int exp;
	int gold;
	string item;
	int tick;
	int max_health;

	Enemy(string name, string type, int strength, int health, int exp, int gold, string item)
		: name(name), type(type), strength(strength), health(health), max_health(health), exp(exp), gold(gold), item(item), tick(0) {}
};

struct Player {
public:
	int xPos, yPos;

	//inventory and related
	vector<Weapon> weaponsinven;
	vector<Armor> armorInventory;
	map<string, int> inventory;

	//vector quest, which shows quest, the completion condition etc.
	map<string, int> quests;

	vector<string> spells;




	//equipment
	Armor equippedArmor;
	Rags rags;

	Weapon equippedWeapon;
	QuarterStaff quarterstaff; // Pointer to the current weapon

	//stats
	string name = "Nameless";
	int level;
	int gold;
	int health;
	int max_health;
	int strength;
	int max_strength;
	int max_mana;
	int mana;
	int exp = 0;
	int healing_potion;
	int mana_potion;


	//location tags
	int gameLevel = 1;
	bool cityLevel = false;
	bool knightsTemenos = false;
	bool drakonHold = false;


	//spells
	bool heal;



	bool holy_light;
	bool Legend_Of_Altyrus;
	bool ascended1;

	void holy_light_spell(Player& player, Enemy& enemy)
	{
		//does damage, and heals for that amount

	}
	void heal_spell(Player& player, Enemy& enemy) {
		//heal the player for 50% health total
		player.mana -= 5;
		int heal_amount = player.max_health / 2;
		int new_health = player.health + heal_amount;
		if (new_health > player.max_health)
		{
			player.health = player.max_health;
		}
		else if (new_health <= player.max_health)
		{
			player.health = new_health;
		}
		else
		{
			cout << "\nYou dont have that spell\n";
			system("pause");
			int RNG = rand() % (0 + 12) + 1;
			int RNG_prot = rand() % (0 + 4) + 1;
			int point_prot = RNG_prot + this->equippedArmor.defense;
			int enemy_damge = max(0, enemy.strength + RNG - point_prot);
			this->health -= enemy_damge;

			cout << "\nYou took " << enemy_damge << " damage from " << enemy.name << ". Your health is " << this->health << endl;
			system("pause");
		}
	}

	bool divine_heal;
	int divine_heal_left;
	void divine_heal_spell(Player& player, Enemy& enemy)
	{
		if (player.player_class == "Holy Knight" && divine_heal_left > 0)
		{
			player.mana -= 15;
			//heals the player for 100% health total
			player.health = player.max_health;
			divine_heal_left--;

		}
		else if (player.player_class != "Holy Knight" && divine_heal_left > 0)
		{
			player.mana -= 30;
			//heals the player for 100% health total
			player.health = player.max_health;
			divine_heal_left--;
		}
		else if (divine_heal_left == 0)
		{
			cout << "\nYou have exhausted ur divine heal limit";

		}
		else

		{
			cout << "\nYou dont have that spell\n";
			system("pause");
			int RNG = rand() % (0 + 12) + 1;
			int RNG_prot = rand() % (0 + 4) + 1;
			int point_prot = RNG_prot + this->equippedArmor.defense;
			int enemy_damge = max(0, enemy.strength + RNG - point_prot);
			this->health -= enemy_damge;

			cout << "\nYou took " << enemy_damge << " damage from " << enemy.name << ". Your health is " << this->health << endl;
			system("pause");
		}

	}

	bool fire_bolt;
	//finish thiss
	void fire_bolt_spell(Player& player, Enemy& enemy)
	{
		//deals 50% of the players strength as damage
		if (this->fire_bolt == true || this->player_class == "Mage")
		{
			if (this->mana >= 10)
			{
				int power = rand() % (15 + 50) + 15;

				int damage = (player.strength / 2) + power;
				enemy.health -= damage;
				this->mana -= 10;

				cout << "\nYou used Fire Bolt, dealing " << damage << " damage\n";
				system("pause");
			}
			else
			{
				cout << "\nYou dont have enough mana\n";
				system("pause");
				int RNG = rand() % (0 + 12) + 1;
				int RNG_prot = rand() % (0 + 4) + 1;
				int point_prot = RNG_prot + this->equippedArmor.defense;
				int enemy_damge = max(0, enemy.strength + RNG - point_prot);
				this->health -= enemy_damge;

				cout << "\nYou took " << enemy_damge << " damage from " << enemy.name << ". Your health is " << this->health << endl;
				system("pause");
			}
		}
		else
		{
			cout << "\nYou dont have that spell\n";
			system("pause");
			int RNG = rand() % (0 + 12) + 1;
			int RNG_prot = rand() % (0 + 4) + 1;
			int point_prot = RNG_prot + this->equippedArmor.defense;
			int enemy_damge = max(0, enemy.strength + RNG - point_prot);
			this->health -= enemy_damge;

			cout << "\nYou took " << enemy_damge << " damage from " << enemy.name << ". Your health is " << this->health << endl;
			system("pause");
		}
	}

	bool hym_of_fireGiant;
	void hym_of_fireGiant_spell(Player& player, Enemy& enemy)
	{
		if (this->hym_of_fireGiant == true || this->player_class == "Mage")
		{
			if (this->mana >= 25)
			{
				int power = rand() % (50 + 100) + 50;

				enemy.health -= power;
				this->mana -= 25;

				cout << "\nYou used Hym of the Fire Giant, dealing " << power << " damage\n";
				cout << "\nEnemy is set ablaze. Enemy takes extra damage.";

				srand(static_cast<unsigned int>(time(0)));

				int RNG = rand() % (0 + 12) + 1;
				int RNG_prot = rand() % (0 + 4) + 1;
				int point_prot = 0;
				int player_damage = max(0, this->strength + RNG + this->equippedWeapon.damage);
				enemy.health -= player_damage;

				Sleep(500);
				cout << "\nExtra fire damage dealt " << player_damage << "\n";
				Sleep(500);
			}
			else
			{
				cout << "\nYou dont have enough mana\n";
				system("pause");
				int RNG = rand() % (0 + 12) + 1;
				int RNG_prot = rand() % (0 + 4) + 1;
				int point_prot = RNG_prot + this->equippedArmor.defense;
				int enemy_damge = max(0, enemy.strength + RNG - point_prot);
				this->health -= enemy_damge;

				cout << "\nYou took " << enemy_damge << " damage from " << enemy.name << ". Your health is " << this->health << endl;
				system("pause");
			}
		}
		else
		{
			cout << "\nYou dont have that spell\n";
			system("pause");
			int RNG = rand() % (0 + 12) + 1;
			int RNG_prot = rand() % (0 + 4) + 1;
			int point_prot = RNG_prot + this->equippedArmor.defense;
			int enemy_damge = max(0, enemy.strength + RNG - point_prot);
			this->health -= enemy_damge;

			cout << "\nYou took " << enemy_damge << " damage from " << enemy.name << ". Your health is " << this->health << endl;
			system("pause");
		}
	}

	bool criticalStrike;
	void critical_strike_spell(Player& player, Enemy& enemy)
	{
		if (player.criticalStrike == true && player.mana >= 5 || this->player_class == "Mage")
		{
			player.mana -= 5;
			int power = rand() % (50 + 100) + 50;
			power += this->equippedWeapon.damage + this->strength;
			enemy.health -= power;

			cout << "\nYou used Critical Strike, dealing " << power << " damage\n";
			system("pause");
		}
		else
		{
			cout << "\nYou dont have that spell or not enough mana\n";
			system("pause");
			int RNG = rand() % (0 + 12) + 1;
			int RNG_prot = rand() % (0 + 4) + 1;
			int point_prot = RNG_prot + player.equippedArmor.defense;
			int enemy_damge = max(0, enemy.strength + RNG - point_prot);
			player.health -= enemy_damge;

			cout << "\nYou took " << enemy_damge << " damage from " << enemy.name << ". Your health is " << player.health << endl;
			system("pause");
		}
	}

	bool mutilate;
	void mutilate_spell(Player& player, Enemy& enemy)
	{
		if (this->mutilate && this->mana >= 10 || this->player_class == "Mage")
		{
			this->mana -= 20;
			int dice = this->mutilate_count * (rand() % (100 + 150) + 100);
			int player_damage = dice + this->strength + this->equippedWeapon.damage;
			enemy.health -= player_damage;

			cout << "\nMutilate activated.Dealt " << player_damage << " extra damage\n";
			system("pause");
			this->mutilate_count++;

		}
		else
		{
			cout << "\nYou dont have that spell or enough mana\n";
			system("pause");
			int RNG = rand() % (0 + 12) + 1;
			int RNG_prot = rand() % (0 + 4) + 1;
			int point_prot = RNG_prot + this->equippedArmor.defense;
			int enemy_damge = max(0, enemy.strength + RNG - point_prot);
			this->health -= enemy_damge;

			cout << "\nYou took " << enemy_damge << " damage from " << enemy.name << ". Your health is " << this->health << endl;
			system("pause");
		}
	}
	int mutilate_count;


	bool commanders_authority;
	bool drakons_fury;
	void drakon_fury_spell(Player& player, Enemy& enemy)
	{
		if (this->drakons_fury == true || this->player_class == "Mage")
		{
			if (this->mana >= 150)
			{
				int power = rand() % (2500 + 6500) + 2500;

				enemy.health -= power;
				this->mana -= 150;

				cout << "\nYou used Drakon's Fury, dealing " << power << " damage\n";
				system("pause");
			}
		}
		else
		{
			cout << "\nYou dont have that spell\n";
			system("pause");
			int RNG = rand() % (0 + 12) + 1;
			int RNG_prot = rand() % (0 + 4) + 1;
			int point_prot = RNG_prot + this->equippedArmor.defense;
			int enemy_damge = max(0, enemy.strength + RNG - point_prot);
			this->health -= enemy_damge;

			cout << "\nYou took " << enemy_damge << " damage from " << enemy.name << ". Your health is " << this->health << endl;
			system("pause");
		}
	}

	bool shadow_flee;
	void shadow_flee_spell(Player& player, Enemy& enemy)
	{
		if (this->shadow_flee == true && this->mana >= 5)
		{
			this->mana -= 5;
			this->flee = true;
		}
		else if (player.mana < 2)
		{
			cout << "\nYou dont have Mana\n";
			system("pause");
			int RNG = rand() % (0 + 12) + 1;
			int RNG_prot = rand() % (0 + 4) + 1;
			int point_prot = RNG_prot + player.equippedArmor.defense;
			int enemy_damge = max(0, enemy.strength + RNG - point_prot);
			this->health -= enemy_damge;

			cout << "\nYou took " << enemy_damge << " damage from " << enemy.name << ". Your health is " << this->health << endl;
			system("pause");
		}
	}

	bool ice_blast;
	void ice_blast_spell(Player& player, Enemy& enemy)
	{

		if (this->ice_blast == true || this->player_class == "Mage" )
		{
			if (this->mana >= 25)
			{
				int power = rand() % (50 + 100) + 50;

				enemy.health -= power;
				this->mana -= 25;

				cout << "\nYou used Ice blast, dealing " << power << " damage\n";
				cout << "\nEnemy has been frozen, granting 1 extra hit";
				system("pause");

				srand(static_cast<unsigned int>(time(0)));

				int RNG = rand() % (0 + 12) + 1;
				int RNG_prot = rand() % (0 + 4) + 1;
				int point_prot = 0;
				int player_damage = max(0, this->strength + RNG + this->equippedWeapon.damage);
				enemy.health -= player_damage;

				Sleep(500);
				cout << "\nYou attacked " << enemy.name << " and dealt " << player_damage << endl;

			}
			else
			{
				cout << "\nYou dont have enough mana\n";
				system("pause");
				int RNG = rand() % (0 + 12) + 1;
				int RNG_prot = rand() % (0 + 4) + 1;
				int point_prot = RNG_prot + this->equippedArmor.defense;
				int enemy_damge = max(0, enemy.strength + RNG - point_prot);
				this->health -= enemy_damge;

				cout << "\nYou took " << enemy_damge << " damage from " << enemy.name << ". Your health is " << this->health << endl;
				system("pause");
			}
		}
		else
		{
			cout << "\nYou dont have that spell\n";
			system("pause");
			int RNG = rand() % (0 + 12) + 1;
			int RNG_prot = rand() % (0 + 4) + 1;
			int point_prot = RNG_prot + this->equippedArmor.defense;
			int enemy_damge = max(0, enemy.strength + RNG - point_prot);
			this->health -= enemy_damge;

			cout << "\nYou took " << enemy_damge << " damage from " << enemy.name << ". Your health is " << this->health << endl;
			system("pause");
		}
	}

	bool chaos_vortex;
	void chaos_vortex_spell(Player& player, Enemy& enemy)
	{

		if (this->chaos_vortex == true || this->player_class == "Mage")
		{
			if (this->mana >= 25)
			{
				int power = rand() % (50 + 100) + 50;

				enemy.health -= power;
				this->mana -= 25;

				cout << "\nYou used Chaos Vortex, dealing " << power << " damage\n";
				cout << "\nEnemy has gone insane, granting 3 hits";
				system("pause");

				srand(static_cast<unsigned int>(time(0)));

				int RNG = rand() % (0 + 12) + 1;
				int RNG_prot = rand() % (0 + 4) + 1;
				int point_prot = 0;
				int player_damage = max(0, this->strength + RNG + this->equippedWeapon.damage);
				enemy.health -= player_damage;

				Sleep(500);
				cout << "\nYou attacked " << enemy.name << " and dealt " << player_damage << endl;


				RNG = rand() % (0 + 12) + 1;
				RNG_prot = rand() % (0 + 4) + 1;
				point_prot = 0;
				player_damage = max(0, this->strength + RNG + this->equippedWeapon.damage);
				enemy.health -= player_damage;

				Sleep(500);
				cout << "\nYou attacked " << enemy.name << " and dealt " << player_damage << endl;

				RNG = rand() % (0 + 12) + 1;
				RNG_prot = rand() % (0 + 4) + 1;
				point_prot = 0;
				player_damage = max(0, this->strength + RNG + this->equippedWeapon.damage);
				enemy.health -= player_damage;

				Sleep(500);
				cout << "\nYou attacked " << enemy.name << " and dealt " << player_damage << endl;

			}
			else
			{
				cout << "\nYou dont have enough mana\n";
				system("pause");
				int RNG = rand() % (0 + 12) + 1;
				int RNG_prot = rand() % (0 + 4) + 1;
				int point_prot = RNG_prot + this->equippedArmor.defense;
				int enemy_damge = max(0, enemy.strength + RNG - point_prot);
				this->health -= enemy_damge;

				cout << "\nYou took " << enemy_damge << " damage from " << enemy.name << ". Your health is " << this->health << endl;
				system("pause");
			}
		}
		else
		{
			cout << "\nYou dont have that spell\n";
			system("pause");
			int RNG = rand() % (0 + 12) + 1;
			int RNG_prot = rand() % (0 + 4) + 1;
			int point_prot = RNG_prot + this->equippedArmor.defense;
			int enemy_damge = max(0, enemy.strength + RNG - point_prot);
			this->health -= enemy_damge;

			cout << "\nYou took " << enemy_damge << " damage from " << enemy.name << ". Your health is " << this->health << endl;
			system("pause");
		}
	}

	//playerLocations
	bool dungeon;

	//flee quest
	bool flee;

	//quest variables
	bool ring;

	//talk with trader and stuff
	int trader_talk_count;

	//level 1 main quest tuskar and end level
	bool mainquest_1;
	int mainquest_1_counter;
	bool tuskar_alive;
	bool orb_of_altyrus;
	bool symbolOfPower;

	//level 1 sq1 kill goblin warrior and erterene
	bool sidequest_1;
	int  sidequest_1_counter;
	bool sideboss_1_alive;
	bool cityAllow;
	bool sideboss_1_1_alive;
	int quest1_kill_count;

	//level 1 sq2 clear the dungeon, and kill its boss the shadow assassin
	bool sidequest_2;
	int  sidequest_2_counter;
	bool sideboss_2_alive;
	bool dungeon_clear;


	//level 2 main quest kill the commander
	bool mainquest_2;
	int mainquest_2_counter;
	bool commander_alive;
	bool blade_of_altyrus;

	bool lancelotAlive;
	bool mordredAlive;

	//level 2 sq1 jsut a warning from entering the knight temenos
	bool sidequest_2_1;

	bool sidequest_3;
	int  sidequest_3_counter;
	bool sideboss_3_alive;

	//level 2 sq2
	bool sidequest_4;
	int  sidequest_4_counter;
	bool sideboss_4_alive;

	//level 2 sq 7, given by the bansihed knight
	bool hiddenKey;
	bool sidequest_2_7;

	//level 3 main quest
	bool mainquest_3;
	int mainquest_3_counter;
	bool drakon_alive;
	bool might_of_Altyrus;

	//level 3 sq1
	bool sidequest_5;
	int  sidequest_5_counter;
	bool sideboss_5_alive;
	bool soul_of_altyrus;

	//level 3 sq2
	bool sidequest_6;
	int  sidequest_6_counter;
	bool sideboss_6_alive;
	bool heart_of_altyrus;

	bool sideboss_7_alive;



	//other counters and markers
	int killCount;
	int turn_counter;
	bool marks;
	bool map;
	bool ship;
	bool amulet;


	//classes
	string player_class = "Outlander";
	bool outLander = true;
	bool shadow_hunter;
	bool mage;
	bool dragon_knight;

	bool diamond_1;
	bool diamond_2;
	bool diamond_3;
	bool diamond_4;
	bool diamond_5;
	bool abandoned_outpost;

	//player lecels
	bool level2_claimed;
	bool level3_claimed;
	bool level4_claimed;
	bool level5_claimed;
	bool level6_claimed;
	bool level7_claimed;
	bool level8_claimed;
	bool level9_claimed;
	bool level10_claimed;
	bool level11_claimed;
	bool level12_claimed;
	bool level13_claimed;
	bool level14_claimed;
	bool level15_claimed;
	bool level16_claimed;
	bool level17_claimed;
	bool level18_claimed;
	bool level19_claimed;
	bool level20_claimed;


	int currentWeaponIndex;
	int currentArmorIndex;

	bool sidequest_2_objective;
	bool nagaQueenAlive;
	bool nagaQuest;
	bool sideboss_8_alive;
	bool blacksmith_allow;
	bool monarch;
	bool sidequest_2_4;
	bool sideboss_2_4;
	bool throneroom_key;
	bool sidequest_2_2;


	// Constructor
	Player(string name, int health, int gold, int strength, int mana, int exp, int healing_potion, int mana_potion)
		: inventory({ {"Spell book",1} }), weaponsinven({ quarterstaff }), name(name), equippedArmor(rags), currentArmorIndex(0), currentWeaponIndex(0), equippedWeapon(quarterstaff),
		level(1), gold(gold), health(health), max_health(health), armorInventory({ rags }),
		strength(strength), max_strength(strength), max_mana(mana), mana(mana), exp(exp), healing_potion(healing_potion),
		mana_potion(mana_potion), fire_bolt(false), heal(false), shadow_flee(false), ice_blast(false),
		chaos_vortex(false), flee(false), dungeon(false), ring(false), sidequest_1(false), sideboss_1_alive(true),
		sidequest_2(false), sideboss_2_alive(true), sidequest_3(false), sideboss_3_alive(true), sideboss_1_1_alive(true),
		sideboss_4_alive(true), sidequest_5(false), sideboss_5_alive(true), tuskar_alive(true),
		mainquest_1(false), mainquest_1_counter(0), mainquest_2(false), mainquest_2_counter(0), mainquest_3(false), mainquest_3_counter(0),
		sidequest_1_counter(0), sidequest_2_counter(0), sidequest_3_counter(0), sidequest_4(false), sidequest_4_counter(0), sidequest_5_counter(0),
		sidequest_6(false), sidequest_6_counter(0), sideboss_6_alive(true), spells({}), commander_alive(false), quests({}),
		blade_of_altyrus(false), orb_of_altyrus(false), might_of_Altyrus(false), heart_of_altyrus(false),
		soul_of_altyrus(false), drakon_alive(true), turn_counter(0), marks(false), ship(true), map(false),
		amulet(false), player_class("Outlander"), outLander(true), shadow_hunter(false),
		dragon_knight(false), mage(false), diamond_1(false), diamond_2(false), diamond_3(false), diamond_4(false),
		killCount(0), diamond_5(false), abandoned_outpost(false), level2_claimed(false), level3_claimed(false),
		level4_claimed(false), level5_claimed(false), level6_claimed(false), level7_claimed(false),
		level8_claimed(false), level9_claimed(false), level10_claimed(false), level11_claimed(false),
		level12_claimed(false), level13_claimed(false), level14_claimed(false), level15_claimed(false),
		level16_claimed(false), level17_claimed(false), level18_claimed(false), level19_claimed(false),
		level20_claimed(false), xPos(44), yPos(4), cityLevel(true), knightsTemenos(false), drakonHold(false), gameLevel(1),
		quest1_kill_count(), cityAllow(false), sidequest_2_objective(false), nagaQueenAlive(true), nagaQuest(false),
		mutilate(false), criticalStrike(false), commanders_authority(false), drakons_fury(false),
		mutilate_count(0), hym_of_fireGiant(false), sideboss_7_alive(true), sideboss_8_alive(true), blacksmith_allow(false), trader_talk_count(0),
		symbolOfPower(false), divine_heal(false), monarch(false), throneroom_key(false), sidequest_2_1(false), sidequest_2_4(false), sideboss_2_4(false),
		sidequest_2_2(false), hiddenKey(false), sidequest_2_7(false), divine_heal_left(3), holy_light(false), dungeon_clear(false), Legend_Of_Altyrus(false),
		ascended1(false)

	{
		this->equippedArmor = rags;
		this->equippedWeapon = quarterstaff;
		this->weaponsinven.push_back(quarterstaff);
		this->armorInventory.emplace_back(rags);
		this->xPos = 46;
		this->yPos = 4;
	}


	//functions
	void playerHUD(Player& player);
	void battleHUD(Player& player, Enemy& enemy);
	void drawHealthBar(int current, int max, int length);
	void enemy(string eName, string etype, int eStrength, int eHP, int eXP, int eGold, string eItem);
	void boss(string eName, string etype, int eStrength, int eHP, int eXP, int eGold, string eItem);
	void bossAttack(Player& player, Boss& boss);
	void bossAttackPhase1(Player& player, Boss& boss);
	void bossAttackPhase2(Player& player, Boss& boss);
	void bossSpecialMovePhase1(Player& player, Boss& boss);
	void bossSpecialMovePhase2(Player& player, Boss& boss);

	void levelUp(Player& player);


	//modifier
	void changeWeapon(Weapon& newWeapon) {
		DisplayMsg("Changing weapon to " + newWeapon.toString() + "\n");
		equippedWeapon = newWeapon;
	}


	void switchWeapon(int newIndex) {
		if (!weaponsinven.empty()) { // Check if the vector is not empty
			if (newIndex >= 0 && newIndex < weaponsinven.size()) {
				currentWeaponIndex = newIndex;
				equippedWeapon = weaponsinven[currentWeaponIndex];
				DisplayMsg("Switched to " + equippedWeapon.toString() + "\n");
			}
			else {
				DisplayMsg("Invalid weapon index.\n");
			}
		}
		else {
			DisplayMsg("No weapons in inventory.\n");
		}
	}

	void switchArmor(int newIndex)
	{
		if (!armorInventory.empty()) { // Check if the vector is not empty
			if (newIndex >= 0 && newIndex < armorInventory.size())
			{
				currentArmorIndex = newIndex;
				equippedArmor = armorInventory[newIndex];
				DisplayMsg("Switched to " + equippedArmor.toString() + "\n");
			}
			else
			{
				DisplayMsg("Invalid armor index.\n");
			}
		}
		else
		{
			DisplayMsg("No armor in inventory.\n");
		}
	}


	// Add a method to add weapons to the inventory
	void addToInventory(Weapon& weapon) {
		DisplayMsg("Added " + weapon.toString() + " to inventory\n");
		weaponsinven.push_back(weapon);
	}
	void addItemToInventory(const std::string& item, int quantity = 1) {
		// Check if the item is already in the inventory
		auto it = inventory.find(item);
		if (it != inventory.end()) {
			// Item already exists, increment the quantity
			it->second += quantity;
		}
		else {
			// Item doesn't exist, add it to the inventory
			inventory[item] = quantity;
		}

		std::cout << "Added " << item << " to the inventory. Quantity: " << quantity << "\n";
	}
	void addQuest(const std::string& item, int quantity = 1) {
		// Check if the item is already in the inventory
		auto it = quests.find(item);
		if (it != quests.end()) {
			// Item already exists, increment the quantity
			it->second += quantity;
		}
		else {
			// Item doesn't exist, add it to the inventory
			inventory[item] = quantity;
		}

		std::cout << "Added " << item << " to the inventory. Quantity: " << quantity << "\n";
	}

	void addToInventory(Armor& armor)
	{
		DisplayMsg("Added " + armor.toString() + " to inventory\n");
		armorInventory.push_back(armor);
	}




	//find specific item in inventory
	bool findItemInInventory(const std::string& itemName) {
		auto it = this->inventory.find(itemName);

		if (it != this->inventory.end()) {
			DisplayMsg(itemName + " found in inventory. Quantity: " + std::to_string(it->second) + "\n");
			return true;
		}
		else {
			DisplayMsg(itemName + " not found in inventory.\n");
			return false;
		}
	}

	void removeItemFromInventory(const std::string& itemName) {
		auto it = this->inventory.find(itemName);

		if (it != this->inventory.end()) {
			// If the item quantity is greater than 1, decrement the quantity
			if (it->second > 1) {
				it->second--;
			}
			else {
				// If the quantity is 1, remove the item from the map
				this->inventory.erase(it);
			}
			DisplayMsg("Removed " + itemName + " from inventory.\n");
		}
		else {
			DisplayMsg("Item " + itemName + " not found in inventory.\n");
		}
	}
};


