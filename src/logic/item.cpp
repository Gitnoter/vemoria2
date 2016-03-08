////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////
#include "item.h"
#include <iostream>
using namespace std;

Item::Item()
{

}

void Item::hello()
{
    cout << "Hello World" << endl;
}

Item::~Item()
{
    cout << "The object has been deleted" << endl;
}
