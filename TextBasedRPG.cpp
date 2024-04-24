/*This is a basic text based rpg game using OOP concepts,operator overloading,friend functions etc. Dont hesitate to fork this
project and improve it.Hope you enjoy!*/
#include <iostream>
#include <string>
using namespace std;

class Member {
public:
    virtual ~Member() {}

    virtual void takeDamage(int damage) 
    {
        health -= damage;
        if (health < 0) health = 0;
    }

    virtual void setHealth(int newHealth) 
    {
        health = newHealth;
    }

    int getHealth() const 
    {
        return health;
    }

    virtual void decrementStamina(int cost) 
    {
        stamina -= cost;
        if (stamina < 0) stamina = 0;
    }
    virtual void setStamina(int newStamina) 
    {
        stamina=newStamina;
    }
    int getStamina() const 
    {
        return stamina;
    }

    friend void setStats(Member& m, int newHealth, int newStamina);

    friend ostream& operator<<(ostream& os, const Member& m) 
    {
        os<<"Health :"<<m.health<<" Stamina :"<<m.stamina<<endl;
        return os;
    }

protected:

    int health = 100;
    int stamina = 100;
};

void setStats(Member& m, int newHealth, int newStamina) 
{
    m.health = newHealth; 
    m.stamina = newStamina;
    cout<< m << endl;
}


class Enemy : public Member 
{
public:

    void poisonAttack(Member& target) 
    {
        target.takeDamage(24);
    }
    void ShadowAttack(Member& target) 
    {
        target.takeDamage(30);
    }
    void Bite(Member& target)
    {
        target.takeDamage(40);
    }
    void SwordAttack(Member& target) 
    {
    target.takeDamage(34);
    }
    void ArrowAttack(Member& target) 
    {
        target.takeDamage(25);
    }
};

class Warrior : public Member 
{
public:
    void heavyAttack(Member& target) 
    {
        target.takeDamage(50);
        decrementStamina(51);
    }

    void lightAttack(Member& target) 
    {
        target.takeDamage(23);
        decrementStamina(10);
    }

    void roundAttack(Member& target) 
    {
        target.takeDamage(36);
        decrementStamina(15);
    }
};

class Wizard : public Member 
{
public:
    void Fire(Member& target) 
    {
        target.takeDamage(30);
        decrementStamina(45);
    }
    void Ice(Member& target)
    {
        target.takeDamage(100);
        decrementStamina(50);
    }
    void Wind(Member& target)
    {
        target.takeDamage(100);
        decrementStamina(24);
    }
};

class NormalHuman : public Member 
{
public:
    void punch(Member& target) 
    {
        target.takeDamage(13);
        decrementStamina(8);
    }
    void kick(Member& target) 
    {
        target.takeDamage(10);
        decrementStamina(15);
    }
    void head(Member& target) 
    {
        target.takeDamage(15);
        decrementStamina(20);
    }
};

int main() 
{
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') 
    {
        cout << "Hello Player. Welcome to the game of 3 brothers." << endl;
        cout << "You first need to choose a class to play with:" << endl;
        cout << "1. Warrior\n2. Wizard\n3. Human" << endl;

        int choice;
        cin >> choice;

        Warrior Alex;
        Enemy CorpseEater, EvilBats, WoodenMan,bandit;
        Wizard Aloera;
        NormalHuman Mordo;

        switch (choice) 
        {
            case 1: 
            {
                cout << "You've chosen Warrior Alex. Alex has heavy attack, light attack, and round attack." << endl;
                cout << "You are walking through a thick forest containing awful creatures and suddenly a wooden man appears." << endl;
                cout << "He says 'Turn away or feel my wrath. WHAT DO YOU CHOOSE:" << endl;
                cout << "1. Turn away\n2. Fight" << endl;
                int subchoice1;
                cin >> subchoice1;
                if (subchoice1 == 1) 
                {
                    cout << "You turned away and started to walk to the mountains of Blackland." << endl;
                    cout << "On the way, you encounter a corpse-eater who stares at you menacingly and spits venom." << endl;
                    CorpseEater.poisonAttack(Alex);

                    while (Alex.getHealth() > 0 && CorpseEater.getHealth() > 0) 
                    {
                        cout << "Enter a move:" << endl;
                        cout << "1. Heavy attack\n2. Light attack\n3. Round attack" << endl;
                        int subchoice2;
                        cin >> subchoice2;

                        switch (subchoice2) 
                        {
                            case 1:
                                Alex.heavyAttack(CorpseEater);
                                break;
                            case 2:
                                Alex.lightAttack(CorpseEater);
                                break;
                            case 3:
                                Alex.roundAttack(CorpseEater);
                                break;
                            default:
                                cout << "Invalid choice. Exiting combat." << endl;
                                return 0;
                        }
                        CorpseEater.ShadowAttack(Alex);
                        setStats(Alex,Alex.getHealth(),Alex.getStamina());
                        
                        if (Alex.getHealth()==0) 
                        {
                            cout<<"Although he fought bravely , his efforts weren't enough."<<endl;
                        }
                    }
                    if (CorpseEater.getHealth()==0) 
                    {
                    cout<<"Story for Alex ended here because he knew acting coward wasn't unbrave.Congrats Player.Thanks for playing."<<endl;
                    cout << "\nDo you want to play again? (y/n): ";
                    cin >> playAgain;
                    }
                } 
                else if (subchoice1 == 2) 
                {
                    cout << "You performed amazing skills.However, at the end your journey ended."<<endl;
                    cout << "\nDo you want to play again? (y/n): ";
                    cin >> playAgain;
                }
                break;
            }
            case 2: 
            {
                cout << "You've chosen Wizard Aloera. Aloera has fire, ice, and wind powers." << endl;
                cout << "Aloera is in a cave and looking for a way out when she encounters huge teeth bats blocking the exit." << endl;
                cout << "What should Aloera do? 1. Take a step back 2. Fight" << endl;
                int choice2;
                cin >> choice2;
                if (choice2 == 2) 
                {
                    cout << "Aloera decides to fight the bats using her magical powers." << endl;
                    while (Aloera.getHealth() > 0 && EvilBats.getHealth() > 0) 
                    {
                    cout << "1. Fire\n2. Ice\n3. Wind" << endl;
                    int magic_choice;
                    cin >> magic_choice;

                    switch (magic_choice) 
                    {
                        case 1:
                            Aloera.Fire(EvilBats);
                            break;
                        case 2:
                            Aloera.Ice(EvilBats);
                            break;
                        case 3:
                            Aloera.Wind(EvilBats);
                            break;
                        default:
                            cout << "Invalid choice. Exiting combat." << endl;
                            return 0;
                    }
                    EvilBats.Bite(Aloera);
                    cout<<"Aloera is bitten by bats and barely fought back."<<endl;
                    setStats(Aloera,Aloera.getHealth(),Aloera.getStamina());

                    if (Aloera.getHealth()==0) 
                    {
                        cout<<"Aloera got eaten by bats and her story ended.Next time choose wisely."<<endl;
                        cout << "\nDo you want to play again? (y/n): ";
                        cin >> playAgain;
                    }
                    if (EvilBats.getHealth()==0) 
                    {
                        cout << "Aloera defeated evil bats "<<endl;
                        cout << "\nDo you want to play again? (y/n): ";
                        cin >> playAgain;
                    }
                }
                }
                else
                {
                    cout << "Aloera steps back to look for another way out." << endl;
                    cout << "She has come across a giving ceremony and is offered two options: 1. 20 Health 2. 15 Stamina" << endl;
                    int ceremonyChoice;
                    cin >> ceremonyChoice;
                    if (ceremonyChoice == 1) 
                    {
                        Aloera.setHealth(Aloera.getHealth() + 20);
                    }
                    else if (ceremonyChoice == 2) 
                    {
                        Aloera.setStamina(Aloera.getStamina()+15);
                    }
                    setStats(Aloera,Aloera.getHealth(),Aloera.getStamina());
                }
                cout<<"It turns out there was no need for extra buff,she got away succesfully."<<endl;
                break;
            }
            case 3:
                cout << "You've chosen Normal Human Mordo. Mordo has a kick, punch, and head kick." << endl;
                cout << "Mordo is in his village when suddenly it is raided by bandits." << endl;
                cout << "What should Mordo do? 1. Run away 2. Fight" << endl;
                int humanChoice;
                cin >> humanChoice;
                if (humanChoice == 2) 
                {
                    cout << "Mordo decides to fight the bandits using his human skills." << endl;
                    while (Mordo.getHealth() > 0 && WoodenMan.getHealth() > 0) 
                    {
                        cout << "Choose your move: 1. Punch 2. Kick 3. Head Kick" << endl;
                        int fightChoice;
                        cin >> fightChoice;
                        switch (fightChoice) 
                        {
                            case 1:
                                Mordo.punch(bandit);
                                break;
                            case 2:
                                Mordo.kick(bandit);
                                break;
                            case 3:
                                Mordo.head(bandit);
                                break;
                            default:
                                cout << "Invalid choice. Exiting combat." << endl;
                                return 0;
                        }
                        WoodenMan.ShadowAttack(Mordo);
                        setStats(Mordo,Mordo.getHealth(),Mordo.getStamina());
                    }
                    if (Mordo.getHealth()==0) 
                    {
                        cout<<"Mordo was a normal person and couldn't fight back to bandits."<<endl;
                    }
                } 
                else 
                {
                    cout << "Mordo tries to run away but is stabbed in the back." << endl;
                    Mordo.takeDamage(100);
                    cout << "Mordo's health after escaping: " << Mordo.getHealth() << endl;
                    cout << "\nDo you want to play again? (y/n): ";
                    cin >> playAgain;
                }
                break;
            default:
                cout << "Invalid choice. Please restart the game and select a valid class." << endl;
                return 0;
        }
    }
}
