#include "Enemy.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void Enemy::NormalAttack()
{
    cout << "Enemy performs a normal attack." << endl;
}

int Enemy::SetHealth(const int health)
{
    Health = health;
    return Health;
}

const string Orc::SpeciesName = "Orc";
const string Undead::SpeciesName = "Undead";

void Orc::TauntPlayer()
{
    cout << Taunt[0] << endl;
}

void Undead::TauntPlayer()
{
    cout << Taunt[0] << endl;
}
