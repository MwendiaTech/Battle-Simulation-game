#include "Player.h"
#include<iostream>
using namespace std;


void Player::NormalAttack()
{
	cout << name << "performs a normal attack ." << endl;
}

string Player::GetName() const
{
	return name;
}
int Player::GetHealth() const
{
	return Health;
}

void Player::SetHealth(const int health)
{
	Health = health;
}

 void Wizard::SpecialAttack()
{
	cout<< "performs a special attack(Lightning ball)for 10 damage . " << endl;
}

void Knight::SpecialAttack()
{
	cout<< "performs a special attack(Sword strike)for 15 damage . " << endl;
}
