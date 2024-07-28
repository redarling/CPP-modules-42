#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
    public:
        Brain();
        Brain(const Brain& brain);
        ~Brain();
        Brain&      operator=(const Brain& brain);
        void        setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;

    private:
        std::string ideas[100];
};

#endif
