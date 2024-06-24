#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
public:
    Harl();
    void    complain(const std::string& level);

private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);

    typedef void    (Harl::*HarlMemFn)(void);
    struct LevelMap
    {
        const char* levelName;
        HarlMemFn   function;
    };
    static const LevelMap*  getComplaintMap();
};

#endif
