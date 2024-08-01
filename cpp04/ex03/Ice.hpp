#ifndef ICE_HPP
# define ICE_HPP

class Ice
{
    public:
        Ice();
        Ice(const Cure& other);
        ~Ice();
        Ice& operator=(const Ice& other);
        
        virtual AMateria*   clone() const;
        virtual void        use(ICharacter& target);
};

#endif