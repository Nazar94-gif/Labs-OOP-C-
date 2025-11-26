#include <iostream>    
using namespace std;    



template <typename T>
T absValue(T x) {
    return (x < 0) ? -x : x;  
}


template <typename T>
class Search {
private:
    T* arr;      
    int size;   

public:
   
    Search(T* a, int s) {
        arr = a;
        size = s;
    }

    
    void search(T key) {
        for (int i = 0; i < size; i++) {   
            if (arr[i] == key) {           
                cout << "Елемент знайдено: " << arr[i] << endl;
                return;
            }
        }
        cout << "Елемент НЕ знайдено!" << endl; 
    }
};



int main() {
    setlocale(LC_ALL, "ukrainian");  

  
    cout << "absValue(-5) = " << absValue(-5) << endl;        
    cout << "absValue(-3.14) = " << absValue(-3.14) << endl;  

    
    int a[5] = { 3, 7, 1, 9, 4 };     

    Search<int> obj(a, 5);            
    obj.search(1);    
    obj.search(10);   

    return 0;
}
