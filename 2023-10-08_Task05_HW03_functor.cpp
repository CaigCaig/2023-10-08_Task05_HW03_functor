#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

struct get_sum
{
    get_sum() :sum(0) {};
    int sum;

    void operator()(int n)
    {
        if (!(n % 3)) sum += n;
    }
};

struct get_count
{
    get_count() :count(0) {};
    int count;

    void operator()(int n)
    {
        if (!(n%3)) count++;
    }
};


int main()
{
    vector<int> arr { 4, 1, 3, 6, 25, 54 };
    cout << "[IN]:";
    for (int i = 0; i < arr.size(); i++) cout << " " << arr[i];
    cout << endl;

    auto s = for_each(arr.begin(), arr.end(), get_sum());
    cout << "[OUT] : get_sum() = " << s.sum;
    cout << endl;

    auto n = for_each(arr.begin(), arr.end(), get_count());
    cout << "[OUT] : get_count() = " << n.count;
    cout << endl;

    system("pause");
}