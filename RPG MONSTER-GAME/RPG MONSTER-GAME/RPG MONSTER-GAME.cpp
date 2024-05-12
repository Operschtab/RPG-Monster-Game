// RPG MONSTER-GAME.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <Windows.h>
#include <iostream>
#include "Hero.h"
#include "Archer.h"
#include "Creature.h"
#include "Mage.h"
#include "Warrior.h"
#include "Monster.h"
#include <iomanip>
using namespace std;
void fight(Hero& Hero_ptr);          // прототипы
void fight_choose(Hero&, Monster&);
void goto_Rodnik(Hero&);

Creature_Data Warrior_data{ 100, 30, 5, 10, 2, 15, 2, 30, 15, 20};    // шаблоны героев
Creature_Data Ranger_data{ 50, 50, 10, 5, 2, 5, 2, 30, 15, 20};
Creature_Data Mage_data{ 30, 100, 5, 2, 10, 5, 2, 30, 15, 20};
Creature_Data Goblin{ 30,1,1,1,1,1,1,1, 15, 5 };                      // Гоблин это Вик=)
Creature_Data Skeleton{ 2,1,1,1,1,1,1,1, 15, 5 };

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string new_hero_name="";  // имя героя. пользователь вводит с клавиатуры имя героя, далее это имя будет передано и присвоено выбранному пользователем типу героя
    cout << "\t\t\t\t\t\tДобро пожаловать в RPG игру MONSTER-GAME" << endl;
    cout << "Введите имя вашего персонажа: "; cin >> new_hero_name;
    Hero* hero_ptr = nullptr; // создали указатель на обьект класса Hero
    cout << "Кто ты "<< new_hero_name<<"? : \n"<<"1)Воин   2)Лучник   3)Маг"<<endl;
    int choose_hero;
    cin >> choose_hero;
    // создаем новый обьект исходя из выбора пользователя и присваиваем его указателю на героя 
    switch (choose_hero)
    {
    case 1:hero_ptr = new Warrior(Warrior_data, new_hero_name); break;  // в качестве аргумента передаем обьект структуры существа
    case 2:hero_ptr = new Archer(Ranger_data, new_hero_name); break;
    case 3:hero_ptr = new Mage(Mage_data, new_hero_name); break;
    }
    while (!hero_ptr->get_isDead())                                     // цикл выбора действий героя, пока герой жив цикл работает
    {
        cout << "Куда пойдем " << new_hero_name << "?" << endl;
        cout << "1)В лес искать грибы \t2)На родник восстановить ману \t3)В лавку к оружейнику" << endl;
        cin >> choose_hero;
        switch (choose_hero)
        {
        case 1:
            cout << "\n\n\t\t\t\tПока вы гуляли по лесу, на вас напал монстр Вик, ваши действия?" << endl;
            fight(*hero_ptr);                                           // метод создающий цикл битвы, принимает ссылку на героя 
            break;
        case 2:
            cout <<"\n\n\t\t\t\t"<< hero_ptr->get_name() << " после похода на родник Вы полностью восстановили здоровье и ману" << endl;
            goto_Rodnik(*hero_ptr);                                     // метод имитирующий поход на родник, вызывает 2 метода внутри себя, принимает ссылку на текущего героя
            cout << "\t\t\t\t\t\t\tВаше текущее состояние:\n\t\t\t\t\t\tМАНА- " << hero_ptr->get_mp() << "\t\tЗДОРОВЬЕ- " << hero_ptr->get_hp() << "\n\n\n";
            break;
        default:
            cout << "пока не работает" << endl;
            break;
        }
    }    
}
void fight(Hero& hero_ptr)                                              // метод создающий цикл битвы, принимает ссылку на героя
{
    Monster* vik = new Monster(Goblin);                                 // создаем обьект монстра и инициализируем параметрами
    do
    {
        vik->attack(hero_ptr);                                          // нас атакует монстр
        fight_choose(hero_ptr, *vik);                                   // метод обьявленный ниже, обеспечивающий выбор действий героя при нападении монстра
        hero_ptr.refresh_round();								        // метод обьявленный в классе Creature // пока ничего не делает
        vik->refresh_round();									        // метод обьявленный в классе Creature // пока ничего не делает
        cout << "здоровье" << hero_ptr.get_name() << ": " << hero_ptr.get_hp() << endl;
        cout << "здоровье врага: " << vik->get_hp() << endl;
    } while (!vik->get_isDead() && !hero_ptr.get_isDead());		        // продолжить битву пока не выживет кто-то один    
   
    if (vik->get_isDead() && hero_ptr.get_isDead())
    {
        cout << "В результате битвы вы оба мертвы" << endl;
    }
    else if (vik->get_isDead())									        // если монстр vik=false то он убит
    {
        cout << "Вы победили монстра" << endl;
    }
    else
    {
        cout << "Вас убил монстр в лесу" << endl;				        // иначе убиты вы
    }
}
void fight_choose(Hero& hero_ptr, Monster& vik)                         // метод принимает ссылки на героя и монстра, определяет действия героя в зависимости от выбора пользователя
{
    int temp_choose;
    cout << "\n1)Атакуем \t        2)защищаемся \n3)Использовать навык \t4)Использовать предмет" << endl;
    cin >> temp_choose;
    switch (temp_choose)
    {
    case 1: hero_ptr.attack(vik);                                       // атаковать монстра
        break;
    case 2: hero_ptr.defence();
        break;
    case 3: cout << "пока не работает" << endl;
        break;
    case 4: cout << "пока не работает" << endl;
        break;
    default: cout << "пока не работает" << endl;
        break;
    }   
}
void goto_Rodnik(Hero& hero_ptr)                                        // метод для похода на родник- восстановление маны и здоровья, принимает ссылку на текущего героя
{
    hero_ptr.HP_recover_Max();                                          // полное восстановление здоровья
    hero_ptr.MP_recover_Max();                                          // полное восстановление маны
}



