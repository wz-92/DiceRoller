/*
 * DiceRoller.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: Zack White
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int roll(int diceSize) {
	return (rand() % diceSize) + 1;
}

void printOutcome(int totalRoll, int targetNumber) {
	if (totalRoll >= targetNumber)
		cout << "\nSuccess! Nice roll!\n";
	else cout << "\nToo low! Better luck next time...\n";
}

void rollAndTotal() {
	cout << "** ROLL AND TOTAL **" << endl;

	int diceSize, diceCount, targetNumber, thisRoll, totalRoll = 0;

	cout << "What size die do you wanna roll?: " << endl;
	cin >> diceSize;
	cout << "How many dice?: " << endl;
	cin >> diceCount;
	cout << "What's the target number?:" << endl;
	cin >> targetNumber;

	cout << "*Rolling " << diceCount << "d" << diceSize << " aiming for " << targetNumber << "*\n\n";

	for (int i = 0; i < diceCount; i++) {
		thisRoll = roll(diceSize);
		totalRoll += thisRoll;
		cout << thisRoll << " ";
	}

	cout << "Total: " << totalRoll;

	printOutcome(totalRoll, targetNumber);
}

void rollAndKeepX() {
	cout << "** ROLL AND KEEP X **" << endl;

	int diceSize, diceCount, diceToKeep, targetNumber, totalRoll = 0;
	vector<int> rollList;

	cout << "What size die do you wanna roll?: " << endl;
	cin >> diceSize;
	cout << "How many dice?: " << endl;
	cin >> diceCount;
	cout << "How many dice to keep?:" << endl;
	cin >> diceToKeep;
	cout << "What's the target number?:" << endl;
	cin >> targetNumber;

	cout << "\n\nRolls: ";

	for (int i = 0; i < diceCount; i++) {
		rollList.push_back(roll(diceSize));
		cout << rollList[i] << " ";
	}

	sort(rollList.begin(), rollList.end());

	for (int i = diceCount - diceToKeep; i < diceCount; i++)
		totalRoll += rollList[i];

	cout << "\nTotal: " << totalRoll;

	printOutcome(totalRoll, targetNumber);
}

void rollAndKeepHigh() {
	cout << "** ROLL AND KEEP HIGH **" << endl;
	
	int thisRoll, diceSize, diceCount, targetNumber;
	
	cout << "What size die do you wanna roll?: " << endl;
	cin >> diceSize;
	cout << "How many dice?: " << endl;
	cin >> diceCount;
	cout << "What's the target roll?: " << endl;
	cin >> targetNumber;

	cout << "\n\n*Rolling " << diceCount << "d" << diceSize << ", keeping high roll, "
		<< "aiming for " << targetNumber << "*\n\n";

	int highRoll = 0;
	for (int i = 0; i < diceCount; i++) {	
		thisRoll = roll(diceSize);
		if (thisRoll > highRoll)
			highRoll = thisRoll;
		cout << thisRoll << " ";
	}

	cout << "\nHigh roll: " << highRoll << "\ntarget number: " << targetNumber << endl;

	if (highRoll >= targetNumber)
		cout << "\nSuccess! Nice roll!\n";
	else cout << "\nToo low! Better luck next time...\n";
}

int main() {
	srand(time(NULL));

	bool repeat;
	int selection, rollAgain;
	
	cout << "\t\tWelcome to DiceRoller!" << endl;
	
	do {
		cout << "\t\tPlease make a selection 1-3:" << endl;
		cout << "\t\t\t(1) Roll and Keep High" << endl;
		cout << "\t\t\t(2) Roll and Total" << endl;
		cout << "\t\t\t(3) Roll and Keep X" << endl;
		cin >> selection;
		
		switch(selection) {
			case 1: rollAndKeepHigh();
					break;
			case 2: rollAndTotal();
					break;
			case 3: rollAndKeepX();
					break;
			default: cout << "Error, make a selection 1-3." << endl;
		}
		
		cout << "Roll again? " << "\n(1) yes \n(2) no" << endl;
		cin >> rollAgain;
		
		if (rollAgain == 1)
			repeat = true;
		else repeat = false;
	} while (repeat);
	
	cout << "Goodbye!" << endl;
	return 0;
}
