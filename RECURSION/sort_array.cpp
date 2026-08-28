#include <iostream>
#include <vector>
using namespace std;

void Insert(vector<int>& arr,int last){
    if(arr.size() == 0 || arr.back() <= last){
        arr.push_back(last);
        return ;
    }

    int val = arr.back();
    arr.pop_back();

    Insert(arr,last);

    arr.push_back(val);           // push back the last element
}

void RecursionSort(vector<int>& arr){
    if(arr.size() == 1) return ;

    int last = arr.back();
    arr.pop_back();

    RecursionSort(arr);                    // recursive call

    Insert(arr,last);             // insert last element in sorted array

}

int main(){
    vector<int> arr = {5,1,1,2,0,0};

    RecursionSort(arr);                    // main function

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}