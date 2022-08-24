#include <iostream>
#include <Windows.h>

#include "file_load.h"

int main()
{
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);

   // std::cout << "Клас для роботи з файлами\n";

   printFile pf;
   pf.Display("text1.txt");
    //lf.print();

    

    return 0;
}

