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
    int random,sizes=1000;
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

void selection_sort(){
    fstream read_file("keluaran.txt");
    vector <int> temp;

    while ((read_file >> output)){
        temp.push_back(output); //read le file and insert to vector
    }
    read_file.close();

    timer_start();
    int n=temp.size();
    for (int i=0; i<temp.size(); i++){
            int min_idx = i;
        for (int j=i+1; j<temp.size(); j++){
            if (temp[j] < temp[min_idx]){
                min_idx = j;
            }
        }
        swap(temp[i], temp[min_idx]);
    }

    outf.open("hasil_selection_sort.txt",ios::out); // create the file as "hasil_selection_sort.txt"
    for(int i=0;i<n;i++){
        outf<<temp[i]<<endl;
    }

    outf.close();

    timer_end();
    cout << "\nPress any key to return to the menu...";
    _getch();
}

void straight_select_sort(){
    fstream read_file("keluaran.txt");
    vector <int> temp;

    while ((read_file >> output)){
        temp.push_back(output); //read le file and insert to vector
    }
    read_file.close();
    timer_start();

    int n=temp.size();
    for (int i=0; i<temp.size(); i++){
        for (int j=i+1; j<temp.size(); j++){
            if (temp[i] > temp[j]){
                swap(temp[i], temp[j]);
            }
        }
    }
    outf.open("hasil_straight_select_sort.txt",ios::out); // create the file as "hasil_bubble_sort.txt"
    for(int i=0;i<n;i++){
        outf<<temp[i]<<endl;
    }

    outf.close();

    timer_end();
    cout << "\nPress any key to return to the menu...";
    _getch();
}

void bubble_sort(){
    fstream read_file("keluaran.txt");
    vector <int> temp;
    bool swapped;

    while ((read_file >> output)){
        temp.push_back(output); //read le file and insert to vector
    }
    read_file.close();

    int n=temp.size();
    timer_start();

    for (int i=0; i<n-1; i++){
            swapped = false;
        for (int j=0; j<n-1-i; j++){
            if (temp[j] > temp[j+1]){
                swap(temp[j], temp[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }

    outf.open("hasil_bubble_sort.txt",ios::out); // create the file as "hasil_bubble_sort.txt"
    for(int i=0;i<n;i++){
        outf<<temp[i]<<endl;
    }

    outf.close();

    timer_end();
    cout << "\nPress any key to return to the menu...";
    _getch();
    //2358.99 seconds
}

void two_way_bubble(){
    fstream read_file("keluaran.txt");
    vector <int> temp;
    bool swapped;

    while ((read_file >> output)){
        temp.push_back(output); //read le file and insert to vector
    }
    read_file.close();

    int n=temp.size();
    timer_start();

    for (int i=0; i<n-1; i++){
            swapped = false;
        for (int j=0; j<n-1-i; j++){
            if (temp[j] > temp[j+1]){
                swap(temp[j], temp[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
        for (int j=n-1-i; j>0; j++){
            if (temp[j-1] > temp[j]){
                swap(temp[j-1], temp[j]);
                swapped = true;
            }
        }
    }

    outf.open("hasil_two_way_bubble_sort.txt",ios::out); // create the file as "hasil_two_way_bubble_sort.txt"
    for(int i=0;i<n;i++){
        outf<<temp[i]<<endl;
    }

    outf.close();

    timer_end();
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
    cout << "2. Sorting Menu" << endl;
    cout << "0. Exit" << endl;
    cout << ">> "; cin >> menu_input;

        if (menu_input == 1){
            system("cls");
            time_state = 1;
            timer_start(); //start timer
            create_file(); // Create le file 😮‍💨
            timer_end(); // end timer
            cout << "The creation process has been completed, please restart the program.";
            cout << endl << endl;
            break;
        } else if (menu_input == 2){
            system("cls");
            time_state = 2;
            cout << "=== Pick a sorting method ===" << endl;
            cout << "1. Selection sort" << endl;
            cout << "2. Straight selection sort" << endl;
            cout << "3. Bubble sort" << endl;
            cout << "4. Two way bubble sort" << endl;
            cout << "0. <- Back" << endl;
            cout << ">> "; cin >> submenu_input;

            switch (submenu_input){
            case 1:
                system("cls");
                selection_sort();
                break;
            case 2:
                system("cls");
                straight_select_sort();
                break;
            case 3:
                system("cls");
                bubble_sort();
                break;
            case 4:
                system("cls");
                two_way_bubble();
                break;
            default:
                break;
            }
        }

    }while(menu_input!=0);

    return 0;
}
