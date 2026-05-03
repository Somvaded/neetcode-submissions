class DynamicArray {

public:
    int *arr;
    int index;
    int size;
    DynamicArray(int capacity) {
        size=capacity;
        cout<<size<<endl;
        arr=new int[size];
        index=0;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i]=n;
        return;
    }

    void pushback(int n) {
        if(index==size){
            resize();
        }
        arr[index++]=n;
        return;
    }

    int popback() {
        return arr[--index];
    }

    void resize() {
        int *newArr= new int[2*size];
        for(int i=0;i<index;i++){
            newArr[i]=arr[i];
        }
        delete []arr;
        arr=newArr;
        size=2*size;
        return;
    }

    int getSize() {
        return index;
    }

    int getCapacity() {
        cout<<size<<endl;
        return size;
    }
};
