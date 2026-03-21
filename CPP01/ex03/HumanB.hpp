#include "Weapon.hpp"
#include <string>

class HumanB{
    private:
        std::string name;
        Weapon *weapon;
    public:
        HumanB();
        HumanB(const std::string Name);
        HumanB(const std::string Name, Weapon *weapon);
        void attack();
        void setWeapon(Weapon &newWeapon);
        ~HumanB();
};