#include <iostream>
#include "Tree.h"



int main()
{
    Tree<int,int> test;
    test.add(1,2);
    test.add(3,3);
    test.show();
    test.remove(1);
    test.show();
    return 0;
}
