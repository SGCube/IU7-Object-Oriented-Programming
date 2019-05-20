#include "pch.h"

#include <iostream>
using namespace std;

#include "error.hpp"
#include "list.hpp"
#include "list_iter.hpp"
#include "list_node.hpp"

int main()
{
    cout << "List container test" << endl;
    try
    {
		////////////////////////////////////////////

        cout << "\n\n===Constructors===" << endl;
        
        cout << "\nDefault constructor" << endl;
		List<int> list0;
        cout << list0 << endl;
        
        cout << "\nVarg constructor" << endl;
		List<char> list1(3, 'a', 'b', 'c');
        cout << list1 << endl;

		cout << "\nInitialization constructor" << endl;
		List<int> list2 = { 1, 2, 3 };
		cout << list2 << endl;
        
        cout << "\nCopy constructor" << endl;
        list0 = list2;
        cout << list0 << endl;

		List<char> list3(list1);
		cout << list3 << endl;
        
		////////////////////////////////////////////

        cout << "\n===Elements add===" << endl;
        
        List <int> list4;
        List <int> list5;
        List <int> list6;
        
        cout << "\nappend" << endl;
        cout << list4 << endl;
        list4.append(1);
        cout << list4 << endl;
        list4.append(2);
        cout << list4 << endl;
        
        cout << "\ninsert(data, iter)" << endl;
        cout << list5 << endl;

        ListIter<int> iter0(list5.begin());
        list5.insert(1, iter0);
        cout << list5 << endl;

        ListIter<int> iter1(list5.begin());
        list5.insert(2, iter1);
        cout << list5 << endl;

        ListIter<int> iter2(list5.end());
        list5.insert(3, iter2);
        cout << list5 << endl;

        list5.insert(4, iter2);
        cout << list5 << endl;
        
        cout << "\nextend(list)" << endl;
        cout << list6 << endl;
        list6.extend(list6);
        cout << list6 << endl;
        list6.extend(list4);
        cout << list6 << endl;
        list6.extend(list5);
        cout << list6 << endl;
        
		////////////////////////////////////////////

        cout << "\n===Element remove===" << endl;
        
        cout << "\nremove(iter)" << endl;

		List <int> list7(list6);
        ListIter<int> iter3(list7.begin());
        cout << list7 << endl;

        list7.remove(iter3);
        cout << list7 << endl;

        ListIter<int> iter4(list7.begin());
        iter4++;
        iter4++;
        list7.remove(iter4);
        cout << list7 << endl;
        
        cout << "\npop()" << endl;
		cout << list7 << endl;
        list7.pop();
        cout << list7 << endl;
        list7.pop();
        cout << list7 << endl;
        list7.pop();
        cout << list7 << endl;
        
        cout << "\nclear()" << endl;
		list7.clear();
		cout << list7 << endl;
        
		////////////////////////////////////////////

        cout << "\n===Operators===" << endl;
		
		cout << "\n==/!=" << endl;
		cout << list6 << endl;
		cout << list4 << endl;
        if (list6 != list4)
            cout << "Lists are not equal" << endl;
		else
			cout << "Lists are equal" << endl;

		cout << "\n+=" << endl;
		cout << list4 << endl;
		cout << list6 << endl;
        list4 += list6;
        cout << list4 << endl;
        list4 += 0;
        cout << list4 << endl << endl;
        
		cout << "\nsize()" << endl;
		cout << list6 << endl;
		cout << "List size: " << list6.size() << endl;

        list7.clear();
		cout << list7 << endl;
		cout << "List size: " << list7.size() << endl;

		////////////////////////////////////////////

		cout << "\n===Error check===" << endl;
		list4.clear();
		cout << list4 << endl;
		list4.pop();

    }
    catch(Error& error)
    {
        cout << error.what() << endl;
    }
    return 0;
}
