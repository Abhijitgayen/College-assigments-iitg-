#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> maxpq;
priority_queue<int, vector<int>, greater<int> > minpq;

void insertNum(int Num)
//insertion
{
    if (maxpq.empty() == true || Num <= maxpq.top()){

        maxpq.push(Num);
}
else
{
    minpq.push(Num);
}

//balancing

if (maxpq.size() > minpq.size() + 1)
{
    minpq.push(maxpq.top());
    maxpq.pop();
}

else if (minpq.size() > maxpq.size())
{
    int topele = minpq.top();
    maxpq.push(topele);
    minpq.pop();
}
}

double findMedian()
{
    if (minpq.size() == maxpq.size())
    {
        return (minpq.top() + maxpq.top()) / 2.0;
    }
    else
        return maxpq.top();
}

int main()
{

    insertNum(3);
    insertNum(1);
    cout << "Median so far :" << findMedian() << endl;
    insertNum(5);
    cout << "Median so far : " << findMedian() << endl;
    insertNum(4);
    insertNum(7);
    insertNum(8);
    cout << "Median so far :" << findMedian() << endl;
    return 0;
}