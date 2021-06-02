//
//  Contact.cpp
//  BinaryTreeLab
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#include "Contact.hpp"

/**
 * Prints the contact information to the provided std::ostream
 *
 * @detail
 * This prints the information in a 30 character block.  15 left justified for
 * the name and 15 right justified for the phone number.
 *
 * @param outfile std::ostream to be printed to
 */
ostream& Contact::write(ostream& outfile) const
{
    outfile << name << " " << phone << endl;
    return outfile;
}

/**
 * Overloaded stream insertion operator function for Contact
 *
 * @param outfile std::ostream to be printed to;  passed by reference
 * @param entry Contact to be printed;  passed by constant reference
 *
 * @return returns the std::ostream by reference
 */
ostream& operator<< (ostream& outfile, const Contact& entry)
{
    entry.write(outfile);
    
    return outfile;
}
