#ifndef CVIEW_HPP
#define CVIEW_HPP

#include <string>

class CView
{

public:
    ~CView() {}
    CView();

    void WaitEnter() const;
    int GetNumber() const;
    std::string GetString() const;

};

#endif