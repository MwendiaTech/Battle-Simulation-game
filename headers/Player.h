#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "GameObject.h"
#include <string>
using namespace std;


class Player : public GameObject
{
public:
	
	Player(string &name) :name(name),Health(100){}
	

	void NormalAttack() override;
	virtual void SpecialAttack() = 0;

	string GetName()const;
	int GetHealth()const;

	void SetHealth(const int health);



private:
	string name;
	int Health;

};


class Wizard :public Player
{
public:

	static const string SpecialAttackName;
	virtual void SpecialAttack();
    Wizard(string name) : Player(name) {}
    // void SpecialAttack() override;
	

};

class Knight:public Player
{
public:
	static const string SpecialAttackName;
	virtual void SpecialAttack() ;
	// static const string SpecialAttackName;
    Knight(string name) : Player(name) {}
    // void SpecialAttack() override;

};

#endif