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
#include <string>

using namespace std;

chrono::high_resolution_clock::time_point start;
int time_state;
fstream outf;

void timer_start(){
 start = chrono::high_resolution_clock::now(); // Start timer
}

void timer_end(){
    auto end = chrono::high_resolution_clock::now(); // End timer
    chrono::duration<double> elapsed = end - start; // Calculate duration

    if (time_state == 1){ // males ngetik satu satu
        cout << "Time taken to make file: " << elapsed.count() << " seconds\n";
    } else if (time_state == 2){
        cout << "Elapsed time: " << elapsed.count() << " seconds\n";
    }
}

void create_file(){ // belom di random
    srand(time(0));
    int random,sizes=1000000;
    vector <int> isi; // array for "isi" variables

    for(int i=1;i<=sizes;i++){
        isi.push_back(i); // input numbers
    }

    for (int i = sizes - 1; i > 0; i--) {
    random = rand() % (i + 1); // swap and randomize the numbers
    swap(isi[i], isi[random]);
    }

    outf.open("keluaran.txt",ios::out); // create the file as "keluaran.txt"
    for(int i=0;i<sizes;i++){
        outf<<isi[i]<<endl;
    }

    outf.close();
}

void insertion_sort(){
    cout << "Hello World!";
}

void linear_search(){
    cout << "Hello World!";
}

void binary_search(){
    cout << "Hello World!";
}

void interpolation_search(){
    cout << "Hello World!";
}

int main()
{
    int menu_input, submenu_input;

    do{
    system("cls");
    time_state = 0;
    cout << "1. Create File" << endl;
    cout << "2. Manipulation Menu" << endl;
    cout << "0. Exit" << endl;
    cout << ">> "; cin >> menu_input;

        if (menu_input == 1){
            system("cls");
            time_state = 1;
            timer_start(); //start timer
            create_file(); // Create le file
            timer_end(); // end timer
            cout << "The creation process has been completed, please restart the program.";
            cout << endl << endl;
            break;
        } else if (menu_input == 2){
            system("cls");
            time_state = 2;
            cout << "=== Pick a manipulation method ===" << endl;
            cout << "1. Insertion sort" << endl;
            cout << "2. Linear search" << endl;
            cout << "3. Binary seacrh" << endl;
            cout << "4. Interpolation search" << endl;
            cout << "0. <- Back" << endl;
            cout << ">> "; cin >> submenu_input;

            switch (submenu_input){
            case 1:
                system("cls");
                insertion_sort();
                break;
            case 2:
                system("cls");
                linear_search();
                break;
            case 3:
                system("cls");
                binary_search();
                break;
            case 4:
                system("cls");
                interpolation_search();
                break;
            default:
                break;
            }
        }

    }while(menu_input!=0);
    return 0;
}
