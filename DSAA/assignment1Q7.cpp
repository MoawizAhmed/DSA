/*You are required to implement a Turn-Based Battle Simulator game using Doubly Linked
Lists where each node contains a Combatant object with properties like name, health points
(1-70), both inclusive and attack power (1 to 5), both inclusive. This game simulates a classic
RPG-style battle between a player’s party of heroes and a team of enemies. The core challenge
involves managing two teams - one for the hero’s team and another for the enemy team.
The hero’s team should be initialized with five heroes. The enemy team should contain five
enemies in this sequence. The battle follows a structured turn based sequence where the player
hero always attacks first in each round, followed by the enemy counterattack.
Any member of a team can attack any opponent. During each turn, the program will first ask the
player to choose an attacker (by name or position) and then select a target from the opponent’s
team (also by name or position). The attacker and target must exist in their respective teams. Once
attacker is chosen, the attacker will strike on opponent and the opponent’s health will be reduced
by:
Damage = Attack Power × Random Value (where the random value is between 1 and 3,
inclusive).
If any combatant’s health reaches zero or below, they are immediately removed from their team.
After every turn, only the names of the remaining team members from both sides will be displayed.
(do not display health points and attack power of combatant while playing the game).
The winning conditions are based on both survival and strength. If one team is completely
eliminated, the other team wins instantly. However, if the combat lasts until a fixed number of
rounds (10 Minimum), the winner is decided by comparing the total health points of the remaining
members. If both teams have the same total health, the match ends in a draw. At the end of the
game, display the names, health points, and attack power of the surviving members of the winning

team, or in the case of a draw, display the remaining members of both teams, with remaining health
points and attack power.*/#include <iostream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Combatant
{
public:
    string name;
    int health;
    int attackPower;

    Combatant()
    {
        name = "";
        health = 0;
        attackPower = 0;
    }

    Combatant(string n, int h, int a)
    {
        name = n;
        health = h;
        attackPower = a;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Attack Power: " << attackPower << endl;
    }
};

class Node
{
public:
    Combatant data;
    Node* next;
    Node* prev;

    Node(Combatant c)
    {
        data = c;
        next = NULL;
        prev = NULL;
    }
};

class Team
{
private:
    Node* head;
    Node* tail;

public:
    Team()
    {
        head = NULL;
        tail = NULL;
    }

    ~Team()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    void addCombatant(Combatant c)
    {
        Node* newNode = new Node(c);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void displayNames()
    {
        Node* temp = head;

        if (temp == NULL)
        {
            cout << "None";
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data.name;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }
    }

    void displayFull()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            temp->data.display();
            cout << endl;
            temp = temp->next;
        }
    }

    Node* getByPosition(int position)
    {
        Node* temp = head;
        int count = 1;

        while (temp != NULL)
        {
            if (count == position)
                return temp;

            count++;
            temp = temp->next;
        }

        return NULL;
    }

    Node* getByName(string name)
    {
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->data.name == name)
                return temp;

            temp = temp->next;
        }

        return NULL;
    }

    void remove(Node* node)
    {
        if (node == NULL)
            return;

        if (node == head)
            head = node->next;

        if (node == tail)
            tail = node->prev;

        if (node->prev != NULL)
            node->prev->next = node->next;

        if (node->next != NULL)
            node->next->prev = node->prev;

        delete node;
    }

    int totalHealth()
    {
        Node* temp = head;
        int total = 0;

        while (temp != NULL)
        {
            total += temp->data.health;
            temp = temp->next;
        }

        return total;
    }
};

void showTeams(Team& heroes, Team& enemies)
{
    cout << "\nRemaining Heroes: ";
    heroes.displayNames();

    cout << "\nRemaining Enemies: ";
    enemies.displayNames();

    cout << endl;
}

int main()
{
    srand(time(0));

    Team heroes;
    Team enemies;

    heroes.addCombatant(Combatant("Arthur", 60, 5));
    heroes.addCombatant(Combatant("Lancelot", 55, 4));
    heroes.addCombatant(Combatant("Merlin", 45, 5));
    heroes.addCombatant(Combatant("Robin", 50, 3));
    heroes.addCombatant(Combatant("Gawain", 65, 4));

    enemies.addCombatant(Combatant("Goblin", 40, 3));
    enemies.addCombatant(Combatant("Orc", 60, 4));
    enemies.addCombatant(Combatant("Troll", 70, 3));
    enemies.addCombatant(Combatant("Dragon", 65, 5));
    enemies.addCombatant(Combatant("Demon", 55, 4));

    int round = 1;

    cout << "Turn Based Battle Game\n";

    while (!heroes.isEmpty() && !enemies.isEmpty() && round <= 10)
    {
        cout << "\nRound " << round << endl;

        cout << "\nHero Turn\n";

        cout << "Choose a hero:\n";
        cout << "1. Arthur\n";
        cout << "2. Lancelot\n";
        cout << "3. Merlin\n";
        cout << "4. Robin\n";
        cout << "5. Gawain\n";

        int heroPosition;
        cout << "Enter position: ";
        cin >> heroPosition;

        Node* hero = heroes.getByPosition(heroPosition);

        while (hero == NULL)
        {
            cout << "Invalid position. Try again: ";
            cin >> heroPosition;
            hero = heroes.getByPosition(heroPosition);
        }

        cout << "\nChoose an enemy:\n";
        enemies.displayNames();

        int enemyPosition;
        cout << "\nEnter position: ";
        cin >> enemyPosition;

        Node* enemy = enemies.getByPosition(enemyPosition);

        while (enemy == NULL)
        {
            cout << "Invalid position. Try again: ";
            cin >> enemyPosition;
            enemy = enemies.getByPosition(enemyPosition);
        }

        int randomValue = (rand() % 3) + 1;
        int damage = hero->data.attackPower * randomValue;

        cout << "\n" << hero->data.name << " attacks "
             << enemy->data.name << endl;

        enemy->data.health -= damage;

        cout << "Damage: " << damage << endl;

        if (enemy->data.health <= 0)
        {
            cout << enemy->data.name << " has been defeated.\n";
            enemies.remove(enemy);
        }

        showTeams(heroes, enemies);

        if (enemies.isEmpty())
        {
            cout << "\nHeroes win!\n";
            break;
        }

        cout << "\nEnemy Turn\n";

        cout << "Choose an enemy:\n";
        enemies.displayNames();

        int enemyAttackerPosition;
        cout << "\nEnter position: ";
        cin >> enemyAttackerPosition;

        Node* enemyAttacker =
            enemies.getByPosition(enemyAttackerPosition);

        while (enemyAttacker == NULL)
        {
            cout << "Invalid position. Try again: ";
            cin >> enemyAttackerPosition;

            enemyAttacker =
                enemies.getByPosition(enemyAttackerPosition);
        }

        cout << "\nChoose a hero:\n";
        heroes.displayNames();

        int heroTargetPosition;
        cout << "\nEnter position: ";
        cin >> heroTargetPosition;

        Node* heroTarget =
            heroes.getByPosition(heroTargetPosition);

        while (heroTarget == NULL)
        {
            cout << "Invalid position. Try again: ";
            cin >> heroTargetPosition;

            heroTarget =
                heroes.getByPosition(heroTargetPosition);
        }

        randomValue = (rand() % 3) + 1;
        damage = enemyAttacker->data.attackPower * randomValue;

        cout << "\n" << enemyAttacker->data.name
             << " attacks " << heroTarget->data.name << endl;

        heroTarget->data.health -= damage;

        cout << "Damage: " << damage << endl;

        if (heroTarget->data.health <= 0)
        {
            cout << heroTarget->data.name << " has been defeated.\n";
            heroes.remove(heroTarget);
        }

        showTeams(heroes, enemies);

        if (heroes.isEmpty())
        {
            cout << "\nEnemies win!\n";
            break;
        }

        round++;
    }

    if (!heroes.isEmpty() && !enemies.isEmpty() && round > 10)
    {
        int heroHealth = heroes.totalHealth();
        int enemyHealth = enemies.totalHealth();

        cout << "\n10 rounds completed.\n";

        if (heroHealth > enemyHealth)
        {
            cout << "\nHeroes win!\n";
            cout << "\nSurviving Heroes:\n";
            heroes.displayFull();
        }
        else if (enemyHealth > heroHealth)
        {
            cout << "\nEnemies win!\n";
            cout << "\nSurviving Enemies:\n";
            enemies.displayFull();
        }
        else
        {
            cout << "\nThe match is a draw.\n";

            cout << "\nRemaining Heroes:\n";
            heroes.displayFull();

            cout << "\nRemaining Enemies:\n";
            enemies.displayFull();
        }
    }
    else
    {
        cout << "\nFinal Results\n";

        if (heroes.isEmpty())
        {
            cout << "\nWinning Team: Enemies\n";
            cout << "\nSurviving Enemies:\n";
            enemies.displayFull();
        }
        else if (enemies.isEmpty())
        {
            cout << "\nWinning Team: Heroes\n";
            cout << "\nSurviving Heroes:\n";
            heroes.displayFull();
        }
    }

    return 0;
}