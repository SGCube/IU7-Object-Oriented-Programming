#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <memory>
#include <vector>

class Object
{
public:
    Object() = default;
    virtual ~Object() = default;
};

typedef std::vector<std::shared_ptr<Object>>::iterator ObjIter;

#endif // OBJECT_H
