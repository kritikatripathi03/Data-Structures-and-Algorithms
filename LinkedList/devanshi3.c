#include <stdio.h>
#include <stdlib.h>

int* relativeSortArray(int *Array1 , int* Array2)
{
    unordered_map <int , int> position;

    for(int i = 0 ; i < Array2.size() ; i++)
        position[Array2[i]] = i;

    sort(Array1.begin() , Array1.end() , [&](const int &first , const int &second)
     {
         if(position.find(first) == position.end() && position.find(second) == position.end())
             return first < second;
         if(position.find(first) == position.end())
             return false;
         if(position.find(second) == position.end())
             return true;
         return position[first] < position[second];
     });

    return Array1;
}

int main()
{
    int a[] = {4 , 5 , 6 , 4 , 5 , 6 , 7 , 1 , 12 , 99} , b[] = {5 , 6 , 12};
    a = relativeSortArray(a , b);
    for(int i = 0 ; i < a.size() ; i++)
        cout << a[i] << " ";
    return 0;
}