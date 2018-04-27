#include <iostream>
#include "Tree.h"



int main()
{
    Tree<int,int> test;
    test.add(11,22);
    test.add(10,64);
    test.add(12,11);
    test.add(9,6);
    test.add(6,323);
    test.add(15,1);
    test.add(14,7);
    test.add(2,674);
    test.add(20,1);
    test.add(16,2);
    test.add(13,5);
    test.add(8,2);
    test.add(5,3);
    //test.add(-3,513);
    test.show();
    return 0;
}
