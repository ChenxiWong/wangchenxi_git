// Last Update:2017-05-11 09:43:54
/**
 * @file strategy_pattern.cpp
 * @brief 策略模式相关代码、添加装饰模式相关代码。
 * @author wangchenxi
 * @version 0.1.00
 * @date 2017-05-11
 */
#include <iostream>
using namespace std;

class WeaponBehavior
{
    public:
        WeaponBehavior(){}
        virtual ~WeaponBehavior(){}
        void virtual useWeapon() = 0;
};

class Decorator: virtual public WeaponBehavior
{
    protected:
        WeaponBehavior* m_weapon;
    public:
        Decorator(WeaponBehavior* p_wp):m_weapon(p_wp){
        }
        virtual ~Decorator(){}
        void virtual decorateWeapon()
        {
            cout<<"Nothing Decorate The Weapon Body. ";
        }
        void virtual useWeapon()
        {
            decorateWeapon();
            m_weapon->useWeapon();
        }
};


class DecoratorDragon : virtual public Decorator
{
    public:
        DecoratorDragon(WeaponBehavior* p_wp):Decorator(p_wp){}
        virtual ~DecoratorDragon(){}
        void virtual decorateWeapon()
        {
            cout<<"A Dragon Decorate The Weapon Body. ";
        }
};

class DecoratorFlower : virtual public Decorator
{
    public:
        DecoratorFlower(WeaponBehavior* p_wp):Decorator(p_wp){}
        virtual ~DecoratorFlower(){}
        void virtual decorateWeapon()
        {
            cout<<"A Flower Decorate The Weapon Body. ";
        }
};

class AK47:public WeaponBehavior
{
    public:
        void useWeapon()
        {
            cout << "Use AK47 to shoot! "<< endl;
        }
};

class Knife:public WeaponBehavior
{
    public:
        void useWeapon()
        {
            cout << "Use Knife to kill! "<< endl;
        }
};

class Character
{
    public:
        Character()
        {
            weapon = 0;
        }
        void setWeapon(WeaponBehavior *w)
        {
            this->weapon = w;
        }
        void virtual fight() = 0;
    protected:
        WeaponBehavior *weapon;
};

class King:public Character
{
    public:
        void fight()
        {
            cout << "The king:" ;
            if ( this->weapon == NULL)
            {
                cout << "You don't have a weapon! Please Set Weapon!"<<endl;
            }
            else
            {
                weapon->useWeapon();
            }
        }
};

int main()
{
    Character *kin = new King();
    WeaponBehavior *ak47 = new AK47();
    WeaponBehavior *knife = new Knife();
    Decorator* p_d_wp = new Decorator(ak47);
    DecoratorDragon* dragon_wp = new DecoratorDragon(ak47);
    DecoratorFlower* flowe_wp = new DecoratorFlower(dragon_wp);

    kin->fight();
    cout << endl;

    kin->setWeapon(ak47);
    kin->fight();
    cout << endl;

    kin->setWeapon(knife);
    kin->fight();
    cout << endl;

    kin->setWeapon(p_d_wp);
    kin->fight();
    cout << endl;

    kin->setWeapon(dragon_wp);
    kin->fight();
    cout << endl;

    kin->setWeapon(flowe_wp);
    kin->fight();
    cout << endl;

    delete ak47;
    delete knife;
    delete p_d_wp;
    delete dragon_wp;
    delete flowe_wp;
    delete kin;

    return 0;
}

