#include <iostream>
using namespace std;
template <typename T> 
class Vector 
{ 
public: 
    Vector(int initCapacity) 

    { 
        size = 0; 
        capacity = initCapacity; 
        array = new T[capacity]; 

    }
    ~Vector()  

    { 

        delete[] array; 

    } 
    Vector & operator=(Vector & rhs)  
    { 

        if (this != &rhs)  

        { 
            delete[] array;        

            size = rhs.size;        

            capacity = rhs.capacity; 

            array = new T[capacity];
            for (int i = 0; i < size; i++) 

                array[i] = rhs.array[i]; 
        } 
        return *this; 
    } 
    int getSize()  
    { 

        return size; 

    } 
    bool isEmpty()  
    { 

        return (size == 0); 
    } 
    T & operator[](int index)  
    { 
        return array[index]; 
    } 
    void pushBack(T newElement)  

    { 
    size = size + 1;
    expand(size);
    array[size - 1] = newElement;   
    } 
    void insert(int pos, T newElement) 

    { 
     Vector<T> k(size + 1);
     int j = 0;
     for(int i = 0;i<size;i++)
     {
     	if(j != pos)
     	{
     	k.pushBack(array[i]);
     	j = j + 1;
        }
        else
		{
        i = i - 1;
        k.pushBack(newElement);
        j = j + 1;
		}
	
	 }
     *this = k;
    } 
    void popBack()  
    { 
        size--;
    } 
    void clear()  

    { 
        size = 0; 
    } 
    void erase(int pos) 
    { 
    Vector<T> k(size - 1);
     for(int i = 0;i<size;i++)
     {
     	if(i != pos)
     	{
     	k.pushBack(array[i]);
        }
	 }
    *this = k;
    } 
    void print() 
    {   
	    for (int i = 0; i < size; i++) 
        cout << array[i] << " "; 
        cout << endl; 
    } 
private: 
    int size; 
    int capacity; 
    T * array; 
    void expand(int newCapacity) 

    {  
        if (newCapacity <= size)   
            return; 
        T * old = array;              
        array = new T[newCapacity];        
        for (int i = 0; i < size; i++)    
            array[i] = old[i];     
        delete[] old;               
        capacity = newCapacity;     
    } 
}; 
int main() 
{   Vector<int> v(1); 
    v.pushBack(6); 
    v.pushBack(2); 
    v.pushBack(9); 
    v.pushBack(1); 
    v.pushBack(8); 
    cout << "Cac phan tu: "<<endl;
    v.print();                   
    cout << "Kich thuoc: " << v.getSize() << endl;
    v.insert(2, 7); 
    cout << "Sau khi chen 7 vao vi tri 2: "<<endl;
    v.print();                       
    v.popBack(); 
    v.erase(1); 
    cout << "Sau khi xoa 8 va 2: "<<endl;
    v.print();                        
    return 0; 

} 

 

 
