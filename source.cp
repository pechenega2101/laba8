#include <iostream>
#include <fstream>
#include <string>


#include "File.h"
#include "student.h"
#include "List.h"

using namespace std;



int main()
{
    student u1("Ivanov", 13565, 5, 500);
    student u2("Petrov", 62351, 2, 1000);
    student u3("Sidorov", 30525, 8, 800);
    student u4("Bodryak", 32525, 6, 300);
    student flg[4] = { u1,u2,u3,u4 };
    File f1("1.txt", txt);
    f1.open("w");
    f1.set_size(4);
    f1 << u1;
    f1 << u2;
    f1 << u3;
    f1 << u4;
    f1.close();
    f1.open("r");
    cout << f1;
    f1.close();
    cout << "\n\n";
    File f2("2.txt", bin);
    f2.open("w");
    f2.set_size(4);
    f2 << u1;
    f2 << u2;
    f2 << u3;
    f2 << u4;
    f2.close();
    f2.open("r");
    cout << f2;
    f2.close();
    cout << "\n\n";
    File f3("3.bin", bin);
    f3.open("w");
    f3.set_size(4);
    f3 << u1;
    f3 << u2;
    f3 << u3;
    f3 << u4;
    f3.close();
    f3.open("r");
    cout << f3;
    f3.close();
    cout << "\n\n";

    cout << "Sort by name:" << endl;
    f1.sort_name();
    f1.open("r");
    cout << f1;
    f1.close();

    cout << "Sort by group:" << endl;
    f1.sort_group();
    f1.open("r");
    cout << f1;
    f1.close();

    cout << "Sort by rating :" << endl;
    f1.sort_rating();
    f1.open("r");
    cout << f1;
    f1.close();

    /*  Ring a;
      f1.open("r");
      student t;
      for (int i = 0; i < f1.get_size(); i++)
      {
          t = f1.read();
          a.push(t);
      }
      cout << endl << endl;
      a.show();
      Iterator I(&a);
      cout << endl << endl;
      I.ShellSort();
      a.show();

  */

  /*int i = 0, line = 0;
  do {
      cout << "Enter the line that you want to change:" << endl;
      cin >> line;
      f2.edit(line, flg);
      f2.open("r");
      cout << "\n--------------------------------------------------------\n";
      cout << f2;
      f2.close();
      cout << "Do you want to change anything else?\n1 - yes\n0 - no" << endl;
      rewind(stdin);
      cin >> i;
  } while (i);*/
    return 0;
}
