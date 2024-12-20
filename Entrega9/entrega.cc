#include <iostream>
#include <vector>
using namespace std;

///////////////////////////////////////////
// 
// if necessary, write additional functions here
//
///////////////////////////////////////////
void read_vector(vector<string> & vect) {
    int size = vect.size();

    for (int i = 0; i < size; ++i) {
        cin >> vect[i];
    }
}

// 11 23 34 55 55 55 55 55 55 65   - 10
// 1 2 2 2 5 6 7 8 9 10 10 10 11    - 13
int findFinalGrtEqBinarySearch(const vector<string> & vect, string z, int low, int high) {
    int index = high;
    --high;

    if (low <= high) {
        int mid = (low + high) / 2;
        if (z <= vect[mid]) {
            index = findFinalGrtEqBinarySearch(vect, z, low, mid);
        } else {
            index = findFinalGrtEqBinarySearch(vect, z, mid + 1, high);
        }
    }

    return index;
}

// 1 2 3 4 5 6 7 8 9 10            -- 10
int greaterEqualBinarySearch(const vector<string> & vect, string z, int low, int high) {
    int index;

    if (low > high) {
        index = 1;
    } else {
        int mid = (low + high) / 2;
        if (z <= vect[mid]) {
            int leftResult = greaterEqualBinarySearch(vect, z, low, mid - 1);
            if (leftResult != 1) {
                index = leftResult;
            } else {
                index = mid;
            }
        } else {
            index = greaterEqualBinarySearch(vect, z, mid + 1, high);
        }
    }

    return index;
}

///////////////////////////////////////////
//
// 
// function first_position  must be here
//
///////////////////////////////////////////
int first_position(const vector<string> & vect, string z) {
    return greaterEqualBinarySearch(vect, z, 0, vect.size() - 1);
    //return findFinalGrtEqBinarySearch(vect, z, 0, vect.size() - 1);
}
// 8 9 9 12 12 12 12 13 13

int main() {
    int n;
    cin >> n;
    
    vector<string> v(n);
    read_vector(v);
    string z;
    while (cin >> z) {
        cout << first_position(v, z) << endl;
    }
        
}