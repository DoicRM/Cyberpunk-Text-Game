#include "item.h"

Item::Item(string n, string t, string d, float p)
{
    name = n;
    type = t;
    description = d;
    price = p;

    nextItem = 0;
}

Item::~Item()
{

}