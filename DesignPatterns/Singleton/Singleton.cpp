/*
 * Example of a singleton design pattern.
 * Copyright (C) 2022 HarisMirza
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


/*
    Singleton Design Pattern Are One Of The Most Popular Design Patterns
    Singleton Design Pattern Are Used To Design The Program To Create
    A Single Object Of Class And Perform The Task Across Systems
    This Design Pattern Is Mostly Used In Printers.

    Now Let's Look At The Example Code
*/

#include <iostream>
using namespace std;

class Printer{
public:
    /*Static Function to get instance*/
    static Printer *getInstance() {
        if(!m_instance) {
            m_instance = new Printer;
        }
        return m_instance;
    }

    void SetData(const char *aData) {
        m_data = aData;
    }

    std::string GetData() {
        return m_data;
    }
private:
    /*Making Default Constructor Private So No Other Instances Can Be Created*/
    Printer() {}
    /*Default Instance Will Be Stored Here*/
    static Printer *m_instance;
    std::string m_data;
};
/*Initialize The Instance To Null So It Can Be Initialized At First Call*/
Printer *Printer::m_instance = nullptr;


int main() {
    Printer *printer = Printer::getInstance();
    Printer *nPrinter = Printer::getInstance();
    printer->SetData("The Quick Brown Fox Jumped Over The Lazy Dog");
    std::cout <<  nPrinter->GetData() << std::endl;
    std::cout <<  printer->GetData() << std::endl;
    std::cout <<  nPrinter << std::endl;
    std::cout <<  printer << std::endl;

    /*Both Objects Have Same Data And Same Addresses In Memory*/
}