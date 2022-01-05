#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(int argc, char const *argv[])
{
    /*arr+arrSize <-- this type*/

    
    // //sorting algorithm ---- this use multiple(mix) algo like insertion,heap,binary,etc.
    // int arr[]={1,89,456,6578,3257545};
    // sort(arr,arr+5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<arr[i]<<"\n";
    // }
    
    // //searching algorithm -- binary search (return 1 or 0)
    // int search_array[]={1,2,3,4,5,6,7,8,9};
    // cout << binary_search(search_array,search_array+9,3) << endl; 
    // cout << binary_search(search_array,search_array+9,10) << endl;


    // sort in vector
    vector<int> v{1,2,2,2,2000,3,456,53,69,732,81,900000};
    sort(v.begin(),v.end());
    vector<int> :: iterator i;
    for(i=v.begin();i!=v.end();i++)
        cout << *i << " ";
    printf("\n");

    // reverse in vector
    reverse(v.begin(),v.end());
    for(i=v.begin();i!=v.end();i++)
        cout << *i << " ";
    printf("\n");

    // find max and min element in vector
    cout << *max_element(v.begin(),v.end()) << endl;
    cout << *min_element(v.begin(),v.end()) << endl;

    // count occurance of x in vector
    int x=2;
    cout << count(v.begin(),v.end(),x) << endl;

    // find x in vector -- Returns an iterator to the first occurence of x in vector and points to last address of vector ((name_of_vector).end()) if element is not present in vector.
    i= find(v.begin(),v.end(),2000) ;
    // cout << *find(v.begin(),v.end(),2000) << endl;
    // cout << *i;
    (find(v.begin(),v.end(),20) != v.end()) ? cout << "element found" << endl : cout << "element not found" << endl ;

    // sort in vector
    sort(v.begin(),v.end());
    for(i=v.begin();i!=v.end();i++)
        cout << *i << " ";
    printf("\n");

    // binary search in vector
    cout << binary_search(v.begin(),v.end(),2000) << endl;

    return 0;
}

