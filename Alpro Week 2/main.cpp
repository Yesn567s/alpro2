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

void create_file(){
    srand(time(0));
    int random,sizes=2000000;
    vector <int> isi;

    for (int i=1; i<sizes+1; i++){
        isi.push_back(i);
    }

    for (int i = sizes - 1; i > 0; i--) {
        random = rand() % (i + 1);
        swap(isi[i], isi[random]);
    }

    outf.open("keluaran.txt",ios::out); // create the file as "keluaran.txt"

    for (int i=0; i<sizes/2; i++) {
        outf << isi[i] << endl; 
    }

    outf.close();
}

void numbers_sort(){
    fstream read_file("keluaran.txt");
    vector <int> temp;

    while ((read_file >> output)){
        temp.push_back(output); //read le file and insert to vector
    }
    read_file.close();

    timer_start();
    cout << "Sorting numbers...";
    sort(temp.begin(), temp.end()); // pake sort algorithm biar cepet

    system("cls");
    timer_end();
    cout << "Sorting complete" << endl;

    outf.open("keluaran_sort.txt",ios::out); // create the file as "keluaran.txt"

    for (int i=0; i<temp.size(); i++){
        outf << temp[i] << endl;
    }

    outf.close();

    cout << "\nPress any key to return to the menu...";
    _getch();
}

void linear_search(){
    fstream read_file("keluaran_sort.txt");
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

    system("cls");
    timer_end();

    if (found == true){
        cout << "Number found, Index: " << i << endl;
    } else {
        cout << "Index not found" << endl;
    }

    cout << "\nPress any key to return to the menu...";
    _getch();
}

void binary_search(){
    fstream read_file("keluaran_sort.txt");
    vector <int> temp;
    bool found = false;
    int target, mid;

    while ((read_file >> output)){
        temp.push_back(output); //read le file and insert to vector
    }
    read_file.close();

    int n=temp.size();
    int low = 0, high = n-1;

    cout << "Enter number you want to find: " << endl << ">> "; cin >> target;

    system("cls");
    cout << "Searching...";

    timer_start();

    while (low <= high){
        mid = low + (high - low) /2;

        // check if target is equal with temp[mid]
        if (temp[mid] == target){
            found = true;
            break;
        }

        // If  greater, ignore left half
        if (temp[mid] < target){
            low = mid + 1;
        } else { // If x is smaller, ignore right half
            high = mid - 1;
        }
    }

    system("cls");
    timer_end();

    if (found == true){
        cout << "Number found, Index: " << mid << endl;
    } else {
        cout << "Index not found" << endl;
    }

    cout << "\nPress any key to return to the menu...";
    _getch();
}

void interpolation_search(){
    fstream read_file("keluaran_sort.txt");
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
    int low = 0, high = n-1,mid;

    while (low <= high && target >= temp[low] && target <= temp[high]){
        if (low == high){
            if (temp[low] == target){
                found = true;
                mid = low;
            }
            break;
        }

        mid = low + ((target - temp[low]) * (high - low)) / (temp[high] - temp[low]); // mid yg sebelumnya bnyk out of bound memory, apa yg anda ketik anjir

        if (mid < 0 || mid >= n){
            break; // prevent out of bound memory,  (pake ini lah rusak terus aku ngetesnya :momoi_nig-:)
        }

        if (temp[mid] == target) {
            found = true;
            break;
        }
        if (temp[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    system("cls");
    timer_end();

    if (found == true){
        cout << "Number found, Index: " << mid << endl;
    } else {
        cout << "Index not found" << endl;
    }

    cout << "\nPress any key to return to the menu...";
    _getch();
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
            cout << "1. Sort numbers" << endl;
            cout << "2. Linear search" << endl;
            cout << "3. Binary seacrh" << endl;
            cout << "4. Interpolation search" << endl;
            cout << "0. <- Back" << endl;
            cout << ">> "; cin >> submenu_input;

            switch (submenu_input){
            case 1:
                system("cls");
                numbers_sort();
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
