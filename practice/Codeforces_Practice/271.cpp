#include <iostream>
using namespace std;

bool check_distinct(int year){

    bool digits[10] = {false};

    while(year > 0){
        int temp = year % 10;
        if(digits[temp] == true) return false;
        else digits[temp] = true;

        year = year /10;
    }

    return true;
}

int main(){

    int year;
    cin >> year;

    year++;
    while(year <= 9123){
        if (check_distinct(year)){
            cout << year <<endl;
            break;
        }
        year++;
    }

    return 0;
}