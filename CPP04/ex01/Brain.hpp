#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Brain
{
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
        std::string getIdea(int pos) const;
        void    setIdea(int pos, const std::string& newIdea);
    
    protected:
        std::string ideas[100];


};

#endif