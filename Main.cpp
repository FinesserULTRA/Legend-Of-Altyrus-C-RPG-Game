// Legend OF altyurus.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Intro.h"
#include "STLIB.h"


int main()
{

	//set console to utf-8
	setlocale(LC_ALL, "en_US.utf8");


	//start game
	Intro intro;
	intro.start();



	return 0;
}

