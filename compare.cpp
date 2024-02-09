// /*
// Author: Zuhayer Tashin
// Course: CSCI-135
// Instructor: TongYi

// This is a program E3.5
// */


#include <fstream>
#include <cstdlib>
#include <climits>
#include<iostream>
using namespace std;

int main() {

    string startDate;
    cout << "Enter starting date: ";
    cin >> startDate;

    string endDate;
    cout << "Enter ending date: ";
    cin >> endDate;

    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()){
        cerr<<"File cannot be opened for reading."<<endl;
        exit(1);
    }

    string junk;
    getline(fin, junk);
    int dateRange = 0;

    string date;
    double eastSt, eastEl, westSt, westEl;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {


      fin.ignore(INT_MAX, '\n');

        if(date == startDate){
          dateRange = 1;
          }
        if(date > endDate){
          dateRange = 0;
          }

        if(dateRange == 1){
            if (eastEl > westEl) {
              cout<< date <<" East "<< endl;
              }else if(eastEl < westEl){
              cout << date << " West "<< endl;
              }else {
              cout << date << " Equal "<< endl;
              }
        }
    }
    fin.close();
  
  return 0;
}