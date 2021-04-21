//assigment -5  problem 2
//By Abhijit Gayen
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
class data1
{
public:
    int a, b;
    int left;
    data1(int a, int b)
    {
        left = (-a - 2 * b * b);
        a = a;
        b = b;
    }
   
};

class comparison2
{
public:
    bool operator()(data2 that, data2 sec)
    {
        return (sec.right > that.right);
    }
};
class comparison1
{
public:
    bool operator()(data1 that, data1 sec)
    {
        return (sec.left < that.left);
    }
};
class data2
{
public:
    int c, d;
    int right;
    data2(int c, int d)
    {
        right = (3 * c * c * c + 4 * d * d * d * d);
        c = c;
        d = d;
    }
    // int compare(data2 that, data2 sec)
    // {
    //     if (sec.right < that.right)
    //         return -1;
    //     if (sec.right > that.right)
    //         return -1;
    //     return 0;
    // }
};
int main()
{
    int d = 0, k, n;
    priority_queue<data1, vector<data1>, comparison1> max;
    priority_queue<data2, vector<data2>, comparison2> min;
    cout << "type your number : ";
    cin >> n;
    for (int a = 1; a < n; a++)
    {
        for (int b = 1; b < n; b++)
        {
            max.push(data1(a, b));
        }
    }
    for (int c = 1; c < n; c++)
    {
        for (int d = 1; d < n; d++)
        {
            min.push(data2(c, d));
        }
    }
    while (max.empty() == false)
    {
        while (min.top().right > -(max.top().left) && max.empty() == false)
        {
            max.pop();
        }

        while (min.top().right < -(max.top().left) && min.empty() == false)
            min.pop();
        while (min.top().right == -(max.top().left) && max.empty() == false)
        {
            d++;
            cout << max.top().a << "+"<< "2" << max.top().b << "^2"<< "="<< "3" << min.top().c << "^3"<< "+"<< "4" << min.top().d << "^4" << endl;
            max.pop();
            min.pop();
        }
    }
    cout << "No. of solution is : " << d << endl;
    return 0;
}