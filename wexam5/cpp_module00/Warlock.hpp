#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
    private:
    std::string name;
    std::string title;
    Warlock();
    Warlock(Warlock const &other);
    Warlock &operator=(Warlock const &other);

    public:

    std::string const &getName()const;
    std::string const &getTitle()const;
    Warlock(std::string const &name, std::string const &title);
    void introduce() const;
    void setTitle(std::string const &str);
    ~Warlock();




};

#endif
