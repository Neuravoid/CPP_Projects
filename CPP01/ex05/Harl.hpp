#ifndef HARL_HPP
#define HARLH_HPP

#include <string>

class Harl{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        Harl() {};
        void complain(std::string str);
        ~Harl() {};


};

#endif