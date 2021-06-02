//
//  Contact.hpp
//  BinaryTreeLab
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#ifndef Contact_hpp
#define Contact_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

/**
 * Contact contains a name (as a free-form std::string) and
 * phone number for a person or business.
 *
 * @remarks
 *     Contacts satisfy the following C++ concepts:
 *         LessThanComparable, EqualityComparable
 *     ( see http://en.cppreference.com/w/cpp/concept )
 */
class Contact{
public:
    // attributes:
    string name;       /// Contact's name (free-form string)
    string phone;      /// Contact's phone number (as a string)
    // constructor:
    Contact(string name="", string phone="")
    : name(name), phone(phone)                { }
    // operators:
    bool operator==     (const Contact& rhs)const { return name == rhs.name && phone == rhs.phone;                          }
    bool operator<      (const Contact& rhs)const { return (name  < rhs.name) || (name == rhs.name && phone < rhs.phone);   }
    // write method
    ostream& write (ostream& outfile)const;
};

// related non-member functions:
ostream& operator<< (ostream& outfile, const Contact& entry);


#endif /* Contact_hpp */
