# ifndef TARGETGENERATOR
# define TARGETGENERATOR

#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
    private:
    std::map<std::string,ATarget *>arrt;
    TargetGenerator(TargetGenerator const & other);
    TargetGenerator & operator = (TargetGenerator const & other);

    public:
    TargetGenerator();
    ~TargetGenerator ();

    void learnTargetType(ATarget*at);
    void forgetTargetType(std::string const &);
    ATarget* createTarget(std::string const &);




};




#endif

