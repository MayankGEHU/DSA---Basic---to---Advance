/*The values are stored in a specific sorted order i.e. either ascending or descending. and unique */
/*              set <data_type> set_name;    */  
//---------- complexity ---------> log(n)        
#include<bits/stdc++.h>
using namespace std;
void LearnSet(){
    set<int>st;
    st.insert(3);
    st.emplace(2);
    st.insert(5);
    st.insert(3);
    st.insert(4);

    auto it = st.find(3);

    auto it = st.find(6); // remember one thing if the element is not present in the set then it always return st.end() +right.. its mean the iterator point end + right element or element after end

    st.erase(3); // delete

    int cnt = st.count(1);

    auto it = st.erase(4);
    st.erase(it); // it take constant time
}

//-------------- Multiset
//-------- Everything same as set only store duplicate elements / store multiple occurance
void LearnMultiSet(){
    multiset<int>ms;
    ms.insert(1);
    ms.insert(3);
    ms.insert(1);
    
    ms.erase(1); // all one's is erase

    int cnt = ms.count(1);

    // only erase single one
    ms.erase(ms.find(1)); // it find first occurance of one

    // ms.erase(ms.find(1), ms.find(1)+2);
    // rest all function same as set

}

void LearnUnorderdset(){
    // every thing is same as set but it does not store in sorted order
    //---------- complexity ---------> o(1) // every operaion
    // worst case-- > o(n)
    // the lower and uperbound operartion is not work
}
int main(){
    LearnSet();
    LearnMultiSet();
return 0;
}