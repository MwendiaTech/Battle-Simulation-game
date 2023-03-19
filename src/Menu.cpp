#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "GameObject.h"

using namespace std;

int main()
{
    srand(time(0));

    cout << "Welcome to the battle simulator!\n\n";

    // Prompt the player for information
    cout << "What type of player do you want to play as? Wizard or Knight?" << endl;
    string player_type;
    cin >> player_type;

    cout << "What is your character's name?" << endl;
    string player_name;
    cin >> player_name;

    // Create the player
    Player* player;
    if (player_type == "Wizard"){
        player = new Wizard(player_name);
    }
    else if (player_type == "Knight"){
        player = new Knight(player_name);
    }
    else {
        cout << "Invalid player type. Exiting..." << endl;
        return 1;
    }

    // Display player summary
    cout << "Player Type: " << player_type << endl;
    cout << "Player Name: " << player_name << endl;
    cout << "Default Health: " << player->GetHealth() << endl;

    // Ask if the player is ready for the battle
    cout << "Are you ready to witness a battle? (y/n)" << endl;
    char answer;
    cin >> answer;
    if (answer != 'y') {
        cout << "Exiting..." << endl;
        return 0;
    }

    // Create a random enemy
    Enemy* enemy;
    int enemy_type = rand() % 2;
    if (enemy_type == 0){
        enemy = new Orc();
    }
    else {
        enemy = new Undead();
    }

    // Display enemy summary
    cout << "An enemy " << enemy->GetSpeciesName() << " has appeared!" << endl;
    cout << "Enemy Health: " << enemy->GetHealth() << endl;

    // Battle sequence	
    while (true) {
        // Enemy taunts the player
        enemy->TauntPlayer();

        // Player performs normal attack
        player->NormalAttack();
        int damage = rand() % 10 + 1;
        enemy->SetHealth(enemy->GetHealth() - damage);
        cout << "Player deals " << damage << " damage to the enemy." << endl;

        // Enemy taunts the player
        enemy->TauntPlayer();

        // Player performs special attack
        player->SpecialAttack();
        damage = rand() % 15 + 1;
        enemy->SetHealth(enemy->GetHealth() - damage);
        cout << "Player deals " << damage << " damage to the enemy." << endl;

        // Enemy performs normal attacks
        for (int i = 0; i < 2; i++) {
            enemy->NormalAttack();
            damage = rand() % 10 + 1;
            player->SetHealth(player->GetHealth() - damage);
            cout << "Enemy deals " << damage << " damage to the player." << endl;
        }

        // Player performs special attack
        player->SpecialAttack();
        damage = rand() % 15 + 1;
        enemy->SetHealth(enemy->GetHealth() - damage);
        cout << "Player deals " << damage << " damage to the enemy." << endl;

        // Enemy taunts the player
        enemy->TauntPlayer();

        // Player performs special attack
        player->SpecialAttack();
        damage = rand() % 15 + 1;
        enemy->SetHealth(enemy->GetHealth() - damage);
        cout << "Player deals " << damage << " damage to the enemy." << endl;
		   // Check if enemy is dead
		if (enemy->GetHealth() <= 0) {
			cout << "The enemy has been defeated! Congratulations, you win!" << endl;
			break;
		}

		// Check if player is dead
		if (player->GetHealth() <= 0) {
			cout << "You have been defeated! Better luck next time." << endl;
			break;
		}
	}

	// Clean up memory
	delete player;
	delete enemy;

	return 0;
	}