//Assingment -5 Question no-1
//By Abhijit Gayen (Roll  No-202123002)
#include <bits/stdc++.h>
using namespace std;

priority_queue<int> maHep;
priority_queue<int, vector<int>, greater<int> > miHep; //use to make miHep

void addNum(int num)
{ //if the added data is less than top of the max Heap and max heap is empty then add this data to max heap. else add it to min Heap
    if (maHep.empty() || num < maHep.top())
    {
        maHep.push(num);
    }
    else
    {
        miHep.push(num);
    }
    //if no of element of max Heap less than min Heap , then take the top of the min Heap and add to max Heap
    if (maHep.size() < miHep.size())
    {
        int teM = miHep.top();
        miHep.pop();
        maHep.push(teM);
    }
    //we need to see difference of no of element in those two heap be at most one
    if (maHep.size() > miHep.size() + 1)
    {
        int teM = maHep.top();
        maHep.pop();
        miHep.push(teM);
    }
}
double searchMedian()
{
    if (!maHep.empty()) //if max heap non empty then we return the median
    {
        return maHep.size() > miHep.size() ? maHep.top() : (maHep.top() + miHep.top()) * 0.5;
    }
    else
    {
        cout << "\n \terror there are no element ...\n";
        return -1;
    }
}
void deleteNum()
{ //frist we cheak theose heap are empty or not if not empty then we delete data
    if (!maHep.empty())
    {
        if (maHep.size() == miHep.size()) //when n is even
        {
            //miHep.pop();//for upper median
          maHep.pop(); //for lower median
            if (maHep.size() < miHep.size())
            {
                int teM = miHep.top();
                miHep.pop();
                maHep.push(teM);
            }
        }
        else //when n is odd
        {
            maHep.pop();
        }
    }
    else
        cout << "\n\tthere are no data to delete" << endl;
}

int main()
{
	system("COLOR 6");
    cout << "chooses:\n\t 1.Add\n\t 2.Search Median\n\t 3.Remove median\n\t 4.exist\n"
         << endl;
    int a;
    do
    {
        cout << "choose:";
        cin >> a;
        switch (a)
        {
        case 1:
            int num;
            cout << "\tInsert a Element:";
            cin >> num;
            addNum(num);
            break;
        case 2:
            if (searchMedian() != -1)
            {
                cout << "\t\tMedian is :" << searchMedian() << endl;
            }
            break;
        case 3:
            deleteNum();
            cout << "\t\tRemove is sucessfully\n";
            break;
        case 4:
            cout << "\t\t terminating......" << endl;
            break;
        default:
            cout << "\t\tError Enter the Right chooses....\n"
                 << endl;
            break;
        }
    } while (a != 4);
}
