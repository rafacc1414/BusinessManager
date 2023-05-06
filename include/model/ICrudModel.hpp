#ifndef ICRUDMODEL_HPP
#define ICRUDMODEL_HPP

template <typename T>
class ICrudModel
{
public:
    ~ICrudModel() {}
    virtual bool Create(T) = 0;
    virtual bool Read(unsigned int id, T&) const = 0;
    virtual bool Update(T) = 0;
    virtual bool Delete(T) = 0;
};

#endif