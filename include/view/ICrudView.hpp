#ifndef ICRUDVIEW_HPP
#define ICRUDVIEW_HPP

#include "./../GeneralTypes.hpp"

class ICrudView
{
public:
    virtual ~ICrudView() {}
    
    virtual crud_options ShowMenu() const = 0;
    virtual void run() = 0;

    virtual void Create() = 0;
    virtual void Read() const = 0;
    virtual void Update() = 0;
    virtual void Delete() = 0;
};

#endif