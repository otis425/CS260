#include <iostream>
#include <cstdio>
using std::cout;
using std::cin;
using std::string;

class MarbleBag {
    // MarbleBag Class for keeping track of and managing marble count
    public:
    int marbles = 0;

    /// @brief This method adds marbles to the count if room is available
    void AddMarbles() {
        if (marbles == bag_size) {cout << "No more room in bag! \n";} 
        else {
            marbles = marbles + 1;
            cout << "Marble add \n" ;
            } 
    }

    /// @brief This method removes marbles to the count if any are in the bag
    void RemoveMarbles(){
        if (marbles <= 0) {cout << "No Marbles! \n";}
        else 
        {
            marbles = marbles - 1;
            cout << "Marble Remove \n";
        }
    }
    
    /// @brief This function prints the marble count
    void CountMarbles(){
        cout << "Marbles in bag = " << marbles << "\n";
    }

    private:
    int bag_size = 5;

};

int main() {
    MarbleBag bag;

    string x = "";
    
    // user input loop
    while (x != "x") {
        cout << " a = Add, r = remove, c = count, x = exit \n";
        cin >> x;
        if (x == "a") {bag.AddMarbles();}
        if (x == "r") {bag.RemoveMarbles();}
        if (x == "c") {bag.CountMarbles();}
    }
    return 0;
}