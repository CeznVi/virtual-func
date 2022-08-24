#include <iostream>
#include <Windows.h>
#include "file_load.h"

int main()
{
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);
     
   //Базовий клас. Друкує вміст файлу.
   printFile pf;
   pf.Display("text1.txt");

   //Нащадок. Друкує вміст файлу у вигляді кодування аскі.
   printFileAscii pfa;
   pfa.Display("text1.txt");
    
   //Нащадок. Друкує вміст файлу у вигляді восьмеричного (oct) кодування.
   printFileOct pfoct;
   pfoct.Display("text1.txt");

   //Нащадок. Друкує вміст файлу у вигляді шістнадцяткового (hex) кодування.
   printFileHex pfhex;
   pfhex.Display("text1.txt");

   return 0;
}

