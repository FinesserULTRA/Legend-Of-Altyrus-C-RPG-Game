#pragma once
#include "STLIB.h"

struct Weapon {

	Weapon(std::string name, int damage, int value) : name(name), damage(damage), value(value) {}


	string toString() const {
		return name + " +" + to_string(damage) + " Damage ";
	}

	string name;
	int damage;
	int value;

};

//start game weapon
struct QuarterStaff : public Weapon {
	QuarterStaff(std::string name = "Quarter Staff", int damage = 5, int value = 20)
		: Weapon(name, damage, value) {}
};

struct OldSword : public Weapon
{
	OldSword(std::string name = "Old Sword", int damage = 7, int value = 25)
		: Weapon(name, damage, value) {}
};

struct ShortSword : public Weapon {
	ShortSword(std::string name = "Short Sword", int damage = 10, int value = 50)
		: Weapon(name, damage, value) {}
};

struct DemonBoneShiv : public Weapon {
	DemonBoneShiv(std::string name = "Demon Bone Shiv", int damage = 15, int value = 150)
		: Weapon(name, damage, value) {}
};

struct ErterenesGauntlets : public Weapon
{
	ErterenesGauntlets(string name = "Erterene's Gauntlets", int damage = 16, int value = 80)
		:Weapon(name, damage, value) {}
};

struct LongSword : public Weapon {
	LongSword(std::string name = "Long Sword", int damage = 20, int value = 100)
		: Weapon(name, damage, value) {}
};

struct ChiefSword : public Weapon
{
	ChiefSword(string name = "Chief's Sword", int dmg = 30, int value = 170)
		: Weapon(name, dmg, value) {}
};

struct ShadowBlade : public Weapon {
	ShadowBlade(std::string name = "Shadow Blade", int damage = 75, int value = 1000)
		: Weapon(name, damage, value) {}
};

struct SilverSword : public Weapon {
	SilverSword(std::string name = "Silver Sword", int damage = 85, int value = 1200)
		: Weapon(name, damage, value) {}
};

struct KnightKiller : public Weapon {
	KnightKiller(std::string name = "Knight Killer", int damage = 150, int value = 4500)
		: Weapon(name, damage, value) {}
};

struct KasakiFang : public Weapon {
	KasakiFang(std::string name = "Kasaki Fang", int damage = 120, int value = 3500)
		: Weapon(name, damage, value) {}
};


struct RazorEdge : public Weapon {
	RazorEdge(std::string name = "Razor Edge", int damage = 150, int value = 2000)
		: Weapon(name, damage, value) {}
};

struct GreatNagaTrident : public  Weapon {
	GreatNagaTrident(std::string name = "Great Naga Trident", int damage = 165, int value = 6500)
		: Weapon(name, damage, value) {}
};


//end game weapon

struct OrbOfAltryus : public Weapon {
	OrbOfAltryus(std::string name = "Orb Of Altryus", int damage = 100, int value = 7000)
		: Weapon(name, damage, value) {}
};

struct KnightBlade : public Weapon {
	KnightBlade(std::string name = "Knight Blade", int damage = 750, int value = 10000)
		: Weapon(name, damage, value) {}
};

struct BladeOfAltyrus : public Weapon {
	BladeOfAltyrus(std::string name = "Blade Of Altyrus", int damage = 2000, int value = 15000)
		: Weapon(name, damage, value) {}
};

//boss weapon
struct MightOfAltryus : public Weapon {
	MightOfAltryus(std::string name = "Might Of Altryus", int damage = 1000, int value = 25000)
		: Weapon(name, damage, value) {}
};




struct Armor {

	Armor(string name, int defense, int value) {
		this->name = name;
		this->defense = defense;
		this->value = value;

	}

	string toString() const {
		return name + " +" + to_string(defense) + " Prot ";
	}

	string name;
	int defense;
	int value;

};

//start game armor
struct Rags : public Armor {
	Rags(std::string name = "Rags", int defense = 1, int value = 20)
		: Armor(name, defense, value) {}
};

struct OldArmor : public Armor
{
	OldArmor(std::string name = "Old Armor", int defense = 3, int value = 25)
		: Armor(name, defense, value) {}
};

struct chiefArmor : public Armor
{
	chiefArmor(string name = "Chief's Armor", int defense = 10, int value = 35)
		:Armor(name, defense, value) {}
};

struct LeatherArmor : public Armor
{
	LeatherArmor(std::string name = "Leather Armor", int defense = 5, int value = 50)
		: Armor(name, defense, value) {}
};

struct ChainMail : public Armor
{
	ChainMail(std::string name = "Chain Mail", int defense = 15, int value = 100)
		: Armor(name, defense, value) {}
};

struct PlateMail : public Armor
{
	PlateMail(std::string name = "Plate Mail", int defense = 24, int value = 120)
		: Armor(name, defense, value) {}
};

struct ShadowArmor : public Armor
{
		ShadowArmor(std::string name = "Shadow Armor", int defense = 50, int value = 3200)
		: Armor(name, defense, value) {}
};

struct SilverArmor : public Armor
{
		SilverArmor(std::string name = "Silver Armor", int defense = 65, int value = 4000)
		: Armor(name, defense, value) {}
};

struct knightArmor : public Armor
{
		knightArmor(string name = "Knight's Armor", int defense = 500, int value = 5000)
		: Armor(name, defense, value) {}
};


//end armor

struct HeartOfAltryus : public Armor {
	HeartOfAltryus(std::string name = "Heart Of Altryus", int defense = 2000, int value = 15000)
		: Armor(name, defense, value) {}
};

struct SoulOfAltyrus : public Armor {
	SoulOfAltyrus(std::string name = "Soul Of Altyrus", int defense = 2000, int value = 25000)
		: Armor(name, defense, value) {}
};