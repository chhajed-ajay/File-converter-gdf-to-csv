#ifndef BASE_H
#define  BASE_H

class Base
{
    public:
    Base();
    virtual void readInputFile() = 0;
    virtual void process() = 0;
    virtual void writeOutput() = 0;
};

#endif