#include <iostream>
#include<vector>
using namespace std;

class maxHeap
{
public:
    vector<int> heap;
    int size;

public:
    void createHeap()
    {
        size=0;
    }
    maxHeap mergeHeap(maxHeap &first,maxHeap &second){
        maxHeap newOne;
        for(int i=0;i<sizeof(first.heap)/4;i++){
            newOne.insert(first.heap[i]);
        }
        for(int i=0;i<sizeof(second.heap)/4;i++){
            newOne.insert(second.heap[i]);
        }
        return newOne;
    }
    maxHeap meldHeap(maxHeap &first,maxHeap &second){
        for(int i=0;i<sizeof(first.heap)/4;i++){
            first.insert(first.heap[i]);
        }
        for(int i=0;i<sizeof(second.heap)/4;i++){
            first.insert(second.heap[i]);
        }
        return first;
    }
    void insert(int x){
        heap.push_back(x);
        size++;
        int i = size-1;
        while (i>0)
        {
            int parentIdx = 0;
            if(i%2==0)
                parentIdx = i/2-1;
            else
                parentIdx = i/2;
            if(heap[parentIdx] < heap[i]){
                int tmp = heap[parentIdx];
                heap[parentIdx] = heap[i];
                heap[i] = tmp;
                i = parentIdx;
            }else{
                break;
            }
        }
    }
    int extractMax(){ // same as deletion in heap
        int maxi = heap[0];
        int tmp = heap[size-1];
        heap[size-1] = heap[0];
        heap[0] = tmp;
        size = size-1;
        int i=0;
        while(i<(size)/2){
            int maxIdx = 0;
            if((2*i+2) < size){
                if((heap[2*i+1] > heap[2*i+2])){
                    maxIdx = 2*i+1;
                }else{
                    maxIdx = 2*i + 2;
                }
            }
            else if(2*i+1 < size){
                maxIdx = 2*i+1;
            }
            
            if(heap[i] < heap[maxIdx]){
                int x = heap[i];
                heap[i] = heap[maxIdx];
                heap[maxIdx] = x;

                i = maxIdx;
            }else{
                break;
            }
        }
        return maxi;
    }
    int findMax(){
        return heap[0];
    }
    int sizeofHeap(){
        return this->size;
    }
    bool isEmpty(){
        return !sizeofHeap();
    }
    void heapify(int *arr, int n)
    {
        for(int i=0;i<n;i++){
            insert(arr[i]);
        }
    }
    void display(){
        for(int i=0;i<size;i++)
            cout << heap[i] << " ";
        cout << "\n";
    }
};

class minHeap
{
    public:
    vector<int> heap;
    int size;

public:
    void createHeap()
    {
        size=0;
    }
    minHeap mergeHeap(minHeap &first,minHeap &second){
        minHeap newOne;
        for(int i=0;i<sizeof(first.heap)/4;i++){
            newOne.insert(first.heap[i]);
        }
        for(int i=0;i<sizeof(second.heap)/4;i++){
            newOne.insert(second.heap[i]);
        }
        return newOne;
    }
    minHeap meldHeap(minHeap &first,minHeap &second){
        for(int i=0;i<sizeof(first.heap)/4;i++){
            first.insert(first.heap[i]);
        }
        for(int i=0;i<sizeof(second.heap)/4;i++){
            first.insert(second.heap[i]);
        }
        return first;
    }
    void insert(int x){
        heap.push_back(x);
        size++;
        int i = size-1;
        while (i>0)
        {
            int parentIdx = 0;
            if(i%2==0)
                parentIdx = i/2-1;
            else
                parentIdx = i/2;
            if(heap[parentIdx] > heap[i]){
                int tmp = heap[parentIdx];
                heap[parentIdx] = heap[i];
                heap[i] = tmp;
                i = parentIdx;
            }else{
                break;
            }
        }
    }
    int extractMin(){ // same as deletion in heap
        int mini = heap[0];
        int tmp = heap[size-1];
        heap[size-1] = heap[0];
        heap[0] = tmp;
        size = size-1;
        int i=0;
        while(i<(size)/2){
            int minIdx = 0;
            if((2*i+2) < size){
                if((heap[2*i+1] < heap[2*i+2])){
                    minIdx = 2*i+1;
                }else{
                    minIdx = 2*i + 2;
                }
            }
            else if(2*i+1 < size){
                minIdx = 2*i+1;
            }
            
            if(heap[i] > heap[minIdx]){
                int x = heap[i];
                heap[i] = heap[minIdx];
                heap[minIdx] = x;

                i = minIdx;
            }else{
                break;
            }
        }
        return mini;
    }
    int findMin(){
        return heap[0];
    }
    int sizeofHeap(){
        return this->size;
    }
    bool isEmpty(){
        return !sizeofHeap();
    }
    void heapify(int *arr, int n)
    {
        for(int i=0;i<n;i++){
            insert(arr[i]);
        }
    }
    void display(){
        for(int i=0;i<size;i++)
            cout << heap[i] << " ";
        cout << "\n";
    }
};

int main()
{
    int n;
    cout << "1.max heap\n2. min heap\n" << "enter your choice : ";
    cin >> n;
    if(n==1){
        maxHeap heap;
        heap.createHeap();
        int s;
        cout << "Enter size of heap : ";
        cin >> s;
        int a[s];
        cout << "Enter elements : ";
        for(int i=0;i<s;i++){
            cin >> a[i];
        }
        heap.heapify(a,s);
        cout <<"1.display\n2.insert element\n3.maximum element\n4.is empty\n5.size\n6.delete maximum element\7.merge two heap\n8.meld tow heap\n9.close\n";
        int c;
        
        do{
            cout << "Enter choice : ";
            cin >> c;
            if(c==1){
                heap.display();
            }else if(c==2){
                int x;
                cout << "Enter element : ";
                cin >> x;
                heap.insert(x);
            }else if(c==3){
                cout << heap.findMax() << endl;
            }else if(c==4){
                if(heap.isEmpty()){
                    cout << "Empty\n";
                }else{
                    cout << "Not empty\n";
                }
            }else if(c==5){
                cout << "size is : " << heap.sizeofHeap() << endl;
            }else if(c==6){
                cout << heap.extractMax() << endl;
                heap.display() ;
            }
            else if(c==7){
                maxHeap first,second;
                int x;
                cout << "Enter size of two heaps : ";
                cin >> x;
                cout << "Enter elements of first heap : ";
                for(int i=0;i<x;i++){
                    int tmp; cin>>tmp;
                    first.heap.push_back(tmp);
                }
                cout << "Enter elements of second heap : ";
                for(int i=0;i<x;i++){
                    int tmp; cin>>tmp;
                    second.heap.push_back(tmp);
                }
                maxHeap newOne = newOne.mergeHeap(first,second);
                newOne.display();
            }
            else if(c==8){
                maxHeap first,second;
                int x;
                cout << "Enter size of two heaps : ";
                cin >> x;
                cout << "Enter elements of first heap : ";
                for(int i=0;i<x;i++){
                    int tmp; cin>>tmp;
                    first.heap.push_back(tmp);
                }
                cout << "Enter elements of second heap : ";
                for(int i=0;i<x;i++){
                    int tmp; cin>>tmp;
                    second.heap.push_back(tmp);
                }
                first = first.mergeHeap(first,second);
                first.display();
            }
        }while(c!=9);
    }else{
        minHeap heap;
        heap.createHeap();
        int s;
        cout << "Enter size of heap : ";
        cin >> s;
        int a[s];
        cout << "Enter elements : ";
        for(int i=0;i<s;i++){
            cin >> a[i];
        }
        heap.heapify(a,s);
        cout <<"1.display\n2.insert element\n3.minimum element\n4.is empty\n5.size\n6.delete minimum element\7.merge two heap\n8.meld two heap\n9.close\n";
        int c;
        
        do{
            cout << "Enter choice : ";
            cin >> c;
            if(c==1){
                heap.display();
            }else if(c==2){
                int x;
                cout << "Enter element : ";
                cin >> x;
                heap.insert(x);
            }else if(c==3){
                cout << heap.findMin() << endl;
            }else if(c==4){
                if(heap.isEmpty()){
                    cout << "Empty\n";
                }else{
                    cout << "Not empty\n";
                }
            }else if(c==5){
                cout << "size is : " << heap.sizeofHeap() << endl;
            }else if(c==6){
                cout << heap.extractMin() << endl;
                heap.display() ;
            }
            else if(c==7){
                minHeap first,second;
                int x;
                cout << "Enter size of two heaps : ";
                cin >> x;
                cout << "Enter elements of first heap : ";
                for(int i=0;i<x;i++){
                    int tmp; cin>>tmp;
                    first.heap.push_back(tmp);
                }
                cout << "Enter elements of second heap : ";
                for(int i=0;i<x;i++){
                    int tmp; cin>>tmp;
                    second.heap.push_back(tmp);
                }
                minHeap newOne = newOne.mergeHeap(first,second);
                newOne.display();
            }
            else if(c==8){
                minHeap first,second;
                int x;
                cout << "Enter size of two heaps : ";
                cin >> x;
                cout << "Enter elements of first heap : ";
                for(int i=0;i<x;i++){
                    int tmp; cin>>tmp;
                    first.heap.push_back(tmp);
                }
                cout << "Enter elements of second heap : ";
                for(int i=0;i<x;i++){
                    int tmp; cin>>tmp;
                    second.heap.push_back(tmp);
                }
                first = first.mergeHeap(first,second);
                first.display();
            }
        }while(c!=9);
    }
    return 0;
}