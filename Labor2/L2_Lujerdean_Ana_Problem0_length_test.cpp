#include <iostream>
#include "L2_Lujerdean_Ana_Problem0_length.h"
#include <assert.h>


void testAll(){
    Length l1(11.5, "m");
    //std::clog<<l1.get_value();
    assert(l1.get_value()==11.5);
    assert(l1.get_unit()=="m");
    Length l2(15, "m");
    assert(l1.add(l2).get_value()==26.5 and l1.add(l2).get_unit()=="m");
    assert((l1+l2).get_value()==26.5 and (l1+l2).get_unit()=="m");
    assert(l2.substract(l1).get_value()==3.5);
    assert(l2.scale(2).get_value()==30);
    assert(l2.divide(2).get_value()==7.5);
    //std::cout<<l1.text();
    assert(l1.text()=="value: 11.50\t unit: m\n");
    assert(l1.compare(l2)==-1);

    std::cout<<"ALL TESTS SUCCESSFUL!"<<std::endl;
}

int main() {

    ///Tests aus length_test.cpp
    testAll();

    float val1, val2;
    std::string unit1, unit2;

    std::cout<<"value1= ";
    std::cin>>val1;
    std::cout<<"unit1= ";
    std::cin>>unit1;

    std::cout<<"value2= ";
    std::cin>>val2;
    std::cout<<"unit2= ";
    std::cin>>unit2;

    float number;
    std::cout<<"number= ";
    std::cin>>number;

    Length l1_read(val1, unit1);
    Length l2_read(val2, unit2);

    std::cout<<std::endl;

    std::cout<<l1_read.text();
    std::cout<<l2_read.text();

    std::cout<<std::endl;

    std::cout<<(l1_read+l2_read).text();
    std::cout<<(l1_read-l2_read).text();
    std::cout<<(l1_read*number).text();
    std::cout<<(l1_read/number).text();
    std::cout<<"l1 vs l2: "<<l1_read.compare(l2_read)<<std::endl;


    std::cout << std::endl << "Hello, World!" << std::endl;
    return 0;
}