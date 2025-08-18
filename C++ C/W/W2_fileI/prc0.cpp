#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

    fstream outfile;
    // write the data to the file (out)
    outfile.open ("prc0.txt", ios::out);

    if(!outfile) {
        cout << "Ërror writing data to file"<< endl;
        exit(1);
    }

    int size;
    cout << "Enter your size of your student" << endl;
    cin >> size;

    cout << "Write information to the file" << endl;
    for ( int i = 0 ; i < size; i++) {
        int age, ID;
        string name;
        cout << "Student No." << i + 1 << endl;
        cout << "Enter in order ID-> name -> age" << endl;
        cin >> ID >> name >> age;
        //write it to the file 
        outfile << ID << " " << name << " " << age << endl;
        cout << "------------------------------" << endl; 
    }
    outfile.close ();


    fstream infile;
    // read data from the file (in)
    infile.open ("prc0.txt",ios::in);

    int ID[100];
    string name[100];
    int age[100];

    int student_index = 0;

    if (!infile) {
        cout << "Error opening file: prc0.txt" << endl;
        exit(1);
    }

    while ( infile >> ID[student_index] >> name[student_index] >> age[student_index] ) {
        student_index++;
    }

    infile.close();

    cout << "Loading Student Information" << endl;
    cout << "-------------------------------" << endl;

    for ( int i = 0 ; i < student_index; i++) {
        cout << "Student No." << i + 1 << endl;
        cout << "ID: " << ID[i] << endl;
        cout << "Name: " << name[i] << endl;
        cout << "Age: " << age[i] << endl;
        cout << "-----------------------------" << endl;
    }
    
    return 0;
}