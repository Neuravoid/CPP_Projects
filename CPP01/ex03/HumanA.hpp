#include "Weapon.hpp"
#include <string>

class HumanA{
    private:
        std::string name;
        Weapon* weapon;
    public:
        HumanA(const std::string &Name, Weapon &weapon);
        void attack();
        ~HumanA();
};