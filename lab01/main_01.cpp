#include <iostream>
#include <cmath>
#include <sstream>
#include "functions.h"

using namespace std;
int main(int argc ) {
    /*cout<< "Enter a number: " << endl;
    int n;
    cin >> n;
    cout << "The number of bits in "<<endl<< n << ": " << countBits(n);
    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)){
            cout<<i<<" ---> " << n <<endl;
        }else{
            cout<<"Impossible operation!" << endl;
        }
    }
    double *array = (double*)malloc(n * sizeof (double));
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    if(!isnan(mean(array, n)))
        cout << "A tomb atlaga: " << mean(array, n);
    else
        cout << "A tomb ures!";
    if(!isnan(stddev(array, n)))
        cout << "A tomb szorasa: " << stddev(array, n);
    else
        cout<< "A tomb ures!";
    pair<double, double> result = max2(array, n);
    cout << "Az elso legnagyobb elem: " << result.first << endl;
    cout << "A masodik legnagyobb elem: " << result.second;*/\
    istringstream inputsream("1.3 2.2 3.3 alma korte 4.4");
    string word;
    double sum = 0;
    while(inputsream >> word){
        istringstream wordstream(word);
        double number;
        if(wordstream >> number){
            sum += number;
        }
    }
    cout <<"A szamok atlaga: "<< sum << endl;
    string inputText = "Ez egy pelda a szavak szamolasara.";
    cout << "Az adott kijelentes "<< countWords(inputText)<< " szobol all." << endl;
    cout << "A kijelentes kodolasa: "<< code(inputText) << endl;
    cout << "A mondat visszaalakitasa: " << decode(code(inputText)) << endl;
    cout << "Irjon be szavakat a bemenetre!" << endl;
    string line;
    while(getline(cin, line)){
        if(line.empty())
            break;
        string capitalized = capitalizeWords(line);
        cout << capitalized << endl;
    }
}
