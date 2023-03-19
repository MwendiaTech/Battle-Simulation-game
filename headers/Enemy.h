#pragma once
#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "GameObject.h"
#include <string>
#include <array>
using namespace std;

class Enemy : public GameObject
{
public:
    Enemy(const string& name) : SpeciesName(name), Health(100) {}
    void NormalAttack() override;
    virtual void TauntPlayer() = 0;
    int GetHealth() const { return Health; }
    string GetSpeciesName() const { return SpeciesName; }
    int SetHealth(const int health);

private:
    int Health;
    string SpeciesName;
};

class Orc : public Enemy
{
public:
    static const string SpeciesName;
	// Orc::Orc() : Enemy(SpeciesName), Taunt{"You're nothing compared to my strength and power"} {}
    // array<string, 1> Taunt{ "You're nothing compared to my strength and power" };
	// Orc constructor
	Orc() : Enemy(SpeciesName), Taunt{"You're nothing compared to my strength and power"} {}
    void TauntPlayer() override;
	// private:
    std::string Taunt;
};


class Undead : public Enemy
{
public:
    static const string SpeciesName;
    // array<string, 1> Taunt = { "Hahaha,You can't kill me !" };
	// Undead::Undead() : Enemy(SpeciesName), Taunt{"Hahaha,You can't kill me !"} {}
	// Undead constructor
	Undead() : Enemy(SpeciesName), Taunt{"Hahaha,You can't kill me !"} {}
    void TauntPlayer() override;

private:
    std::string Taunt;
};

#endif
