#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool containsString(const string& fruit, const string& searchTerm) {
    return (fruit.find(searchTerm) != string::npos);
}

bool isEven(int n) {
    return n % 2 == 0;
}

struct MonthTemperature{
    string month;
    double temperature;
};

int main() {
    //1
    vector<string> fruits {
            "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
    };

    string searchTerm = "berry";
    //cin >> searchTerm;

    auto found = find_if(fruits.begin(), fruits.end(), [searchTerm](const string& fruit) {
        return containsString(fruit, searchTerm);
    });

    if (found == fruits.end()) {
        cout << "Not found!\n";
    } else {
        cout << "Found!\n" << *found << endl;
    }
    //2
    array <int, 14> arr = {35, 65, 23, 2, 76, 112, 89, 34, 5, 90, 234, 6, 342, 656};
    bool allEven = std::all_of(arr.begin(), arr.end(), [](const int& param1) {
        return isEven(param1);
    });

    if (allEven) {
        std::cout << "All elements are even." << std::endl;
    } else {
        std::cout << "Not all elements are even." << std::endl;
    }
    cout << endl;

    //3
    for_each(arr.begin(), arr.end(), [](int& element){
        element *= 2;
    });
    cout << "Doubled array: ";
    for (int element : arr) {
        cout << element << " ";
    }
    cout << endl;

    //4
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };
    vector <string> fiveLetterMonths;
    copy_if(months.begin(), months.end(), back_inserter(fiveLetterMonths),
            [](const string& month){
        return month.size() == 5;
    });
    cout << "5 letter months: ";
    for (const string& month : fiveLetterMonths) {
        cout << month << " ";
    }
    cout << endl;

    //5
    vector<double> numbers = {3.5, 1.2, 4.8, 2.1, 5.3};

    //lambdaval
    sort(numbers.begin(), numbers.end(), [](const double& a, const double& b){
        return a > b;
    });

    //greater funktorral
    sort(numbers.begin(), numbers.end(), greater<double>());
    for(const double& num : numbers)
        cout << num << " ";
    cout << endl;

    //6
    vector<MonthTemperature> temperatureData = {
            {"January", 2.5},
            {"February", 4.3},
            {"March", 8.1},
            {"April", 15.0},
            {"May", 20.5},
            {"June", 25.3},
            {"July", 28.8},
            {"August", 27.0},
            {"September", 21.4},
            {"October", 15.7},
            {"November", 9.3},
            {"December", 4.0}
    };
    sort(temperatureData.begin(), temperatureData.end(), [](const MonthTemperature& a, const MonthTemperature& b){
        return a.temperature < b.temperature;
    });
    cout << "Months sorted by temperatures:\n";
    for(const auto& data : temperatureData){
        cout << data.month<< ": " << data.temperature << "\n";
    }

    //7
    vector<double> numbers1 = {-3.5, 1.2, -4.8, 2.1, -5.3};
    sort(numbers1.begin(), numbers1.end(), [](const double& a, const double& b){
        return abs(a) < abs(b);
    });
    cout << "Ordered array by their absolute value: \n";
    for(const double& num : numbers1)
        cout << num << " ";

    //8
    transform(months.begin(), months.end(), months.begin(), [](string& month){
        transform(month.begin(),month.end(), month.begin(), ::tolower);
        return month;
    });
    cout << "Months transformed to lower: \n";
    for(const string& month : months)
        cout << month << " ";
}
