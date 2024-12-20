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

bool isStrLowerEqual(string str1, string str2) {
    bool result;
    
    int size1 = str1.size();
    int size2 = str2.size();
    
    if (size1 == size2) {
        if (size2 == 0) {
            result = true;
        } else if (str1[0] != str2[0]) {
            result = str1[0] < str2[0];
        } else {
            str1.pop_back();
            str2.pop_back();
            result = isStrLowerEqual(str1, str2);
        }
    } else {
        result = size1 < size2;
    }

    return result;
}

int lowerEqualBinarySearch(const vector<string> & vect, string z, int low, int high) {
    int index;

    if (low <= high) {
        int mid = (low + high) / 2;
        if (z <= vect[mid]) {
            int leftVal = lowerEqualBinarySearch(vect, z, low, mid - 1);
            if (leftVal != 1) {
                index = leftVal;
            } else {
                index = mid;
            }
        } else {
            index = lowerEqualBinarySearch(vect, z, mid + 1, high);
        } 
    } else {
        index = 1;
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
    return lowerEqualBinarySearch(vect, z, 0, vect.size() - 1);
}

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