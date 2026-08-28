#include <iostream>
#include <stack>
using namespace std;

void Insert(stack<int>& st,int last){
    if(st.size() == 0 || st.top() <= last){// it is for descending order, for ascending order change <= to >=
        st.push(last);
        return ;
    }

    int val = st.top();
    st.pop();

    Insert(st,last);

    st.push(val);           // push back the last element
}

void Sort(stack<int>& st){
    if(st.empty()) return ;

    int last = st.top();
    st.pop();

    Sort(st);                    // recursive call

    Insert(st,last);             // insert last element in sorted stack

}

int main(){
    stack<int> st({5,1,1,2,0,0});

    Sort(st);                    // main function

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}