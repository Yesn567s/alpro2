#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <time.h>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

chrono::high_resolution_clock::time_point start;


void timer_start(){
 start = chrono::high_resolution_clock::now(); // Start timer
}

void timer_end(){
    auto end = chrono::high_resolution_clock::now(); // End timer
    chrono::duration<double> elapsed = end - start; // Calculate duration

    cout << "Elapsed time: " << elapsed.count() << " seconds\n";
}

void create_file(){
    srand(time(0));
    fstream outf;
    int random,temp,sizes=500000;
    int isi[sizes]; // array for "isi" variables

    for(int i=0;i<sizes;i++){
        isi[i]=i+1; // input numbers
    }

    for (int i = sizes - 1; i > 0; i--) {
    int random = rand() % (i + 1); // swap and randomize the numbers
    swap(isi[i], isi[random]);
    }

    outf.open("keluaran.txt",ios::out); // create the file as "keluaran.txt"
    for(int i=0;i<sizes;i++){
        outf<<isi[i]<<endl;
    }

    outf.close();
}

int main()
{
    int menu_input, submenu_input;

    do{
    system("cls");
    cout << "1. Create File" << endl;
    cout << "2. Randomize numbers" << endl;
    cout << "0. Exit" << endl;
    cout << ">> "; cin >> menu_input;

        if (menu_input == 1){
            system("cls");
//            create_file();
            cout << "The creation process has been completed, please restart the program.";
            break;
        }

    }while(menu_input!=0);

    return 0;
}
