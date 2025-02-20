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
#include <unordered_set>

using namespace std;

chrono::high_resolution_clock::time_point start;
int time_state, output;
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
    unordered_set <int> isi; // unordered set can only store unique numbers (you know what that means :grins:)

    while (isi.size() < sizes){
        random = rand() % 1000000 + 1;
        isi.insert(random);
    }

    outf.open("keluaran.txt",ios::out); // create the file as "keluaran.txt"

    for (int num : isi) {
        outf << num << endl; // harus di ganti agak repot juga :moai:
    }

    outf.close();
}

void insertion_sort(){
    cout << "Hello World!";
}

void linear_search(){
    fstream read_file("keluaran.txt");
    vector <int> temp;
    bool found = false;
    int i, target;

    while ((read_file >> output)){
        temp.push_back(output); //read le file and insert to vector
    }
    read_file.close();

    int n=temp.size();

    cout << "Enter number you want to find: " << endl << ">> "; cin >> target;

    system("cls");
    cout << "Searching...";

    timer_start();

    for (i=0; i<n; i++){
        if (temp[i] == target){
            found = true;
            break;
        }
    }

    timer_end();

    system("cls");

    if (found == true){
        cout << "Number found, Index: " << i << endl;
    } else {
        cout << "Index not found" << endl;
    }

    cout << "\nPress any key to return to the menu...";
    _getch();
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
