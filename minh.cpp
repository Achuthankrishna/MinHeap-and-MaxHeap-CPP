#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Heap
{
    private:
        int size{};
        vector<int> tree;
        int p(int i){return i>>1;};
        int l(int i){return i<<1;};
        int r(int i){return (i<<1)+1;};
    public:
        bool isEmpty() const{return size==0;};
        int getmin() const{return tree[1];};
        void insert(int val);
        void ShiftU(int i);
        void shiftD(int i);
        int extractMin();
        void printHeap();
};
void Heap::insert(int val){
    if(size+1>=tree.size()){
        tree.push_back(0);
    }
    tree[++size]=val;

    ShiftU(size);
    return;
}
void Heap::ShiftU(int i){
    if(i>tree.size())
        return;
    if(i==1)
        return; 
    if(tree[i]>tree[p(i)]){
        std::swap(tree[p(i)],tree[i]);
        ShiftU(p(i));

    }
    else{
        return;
    }

}
void Heap::shiftD(int i){
    if(i>size) return;
    int sw=i;
    if(l(i)<=size && tree[sw]<tree[l(i)]){
        sw=l(i);
    }
    if(r(i)<=size && tree[sw]<tree[r(i)]){
        sw=r(i);
    }
    if(sw!=i){
        std::swap(tree[i],tree[sw]);
        shiftD(sw);
    }
    return;
}

int Heap::extractMin(){
    int minr=tree[1];
    std::swap(tree[1],tree[size--]);
    shiftD(1);
    return minr;
}

void Heap::printHeap() {
    for(int i=1; i<=size; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
}

int main(){
    Heap* pq=new Heap();
    if(pq->isEmpty()){
        cout<<"Empty"<<endl;
    }
    pq->insert(10);
    pq->insert(120);
    pq->insert(20);
    pq->insert(30);
    pq->insert(5);
    pq->printHeap();
    cout<<pq->getmin()<< endl;
    pq->extractMin();
    pq->printHeap();
    cout<<pq->getmin()<< endl;

    if(pq->isEmpty()){
        cout<<"Not";
    }
    else{
        cout<<"Correct";
    }
    return 0;
}
