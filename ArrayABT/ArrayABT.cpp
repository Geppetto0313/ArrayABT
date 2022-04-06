#include <iostream>
using namespace std;

class Array {
    //Data Members
private:
    int *array;      //Pointer Variable
    int Capacity;    //Maxinum number of elements it can hold
    int size;        //Current amount of elements defined

    //Member Functions
public:
    Array(int ArrayCap = 10);
    ~Array();
    bool isFull();
    bool isEmpty();
    int SizeofArray();
    friend istream& operator>>(istream& is, Array& a);
    friend ostream& operator<<(ostream& os, Array& a);
};

//Constructor Class name followed by scope resolution operator :: followed by constructor name.
Array::Array(int ArrayCap) : Capacity(ArrayCap) {
    array = new int[Capacity];  //Creating new array off the parameter passed in.
    size = 0;                   //Setting size to 0 as it is not initialized.
}

//Decontructor
Array::~Array() {
    delete[] array;             //Deleting the array.
}

//isFull function to check if Array is full
bool Array::isFull() {
    if (size == Capacity) { //Compare size to Capacity to check if full.
        return true;
    }
    else {
        return false;
    }
    
}

//isEmpty function to check if Array is empty
bool Array::isEmpty() {
    if (size == 0) {            //Check to see if amount of elements is 0
        return true;
    }
    else {
        return false;
    }
    
}

//Check the current Size of the array.
int Array::SizeofArray() {
    return size;                //Return the current size.
}

//friend class does not have to specifiy the class name or scope resolution operator
istream& operator >> (istream& is, Array& a) {  //Making a reference to istream class with istream&
    cout << "\nEnter an Element to be inserted in Array: \n";
    is >> a.array[a.size++];    //Use the object name a to call array. We want to place it in the next spot with size. Call object a.size since size is a data member.
                                //Important to increment the size for the next data element location.
    return is;
}

//Because we do not know the data elements
ostream& operator << (ostream& os, Array& a) {  //Making a reference to ostream class with istream&
    for (int i = 0; i < a.size; ++i) {
        os << a.array[i] << " ";                //To loop through since its a friend class we must call an object to get the private data member array.
    }
    return os;
    
}

int main()
{
    
    //Array a(50);                              //Create an object of array class with a parameter of 50
    Array a;                                    //Using the default constructor with a size of 10     
    int num;                                    //Variable to hold user input
    cout << "\nEnter how many Elements? \n";
    cin >> num;

    for (int i = 0; i < num; ++i) {             //Loop through by amount specified by user
        cin >> a;
        cout << "\nEntered Elements are: \n";
        cout << a;                              //Calling cout to display the current contents.
    }

    if (a.isFull()) {                           //Call member functions with object name
        cout << "\nArray is FULL";
    }
    else {
        cout << "\nArray is Not FULL";
    }

    if (a.isEmpty()) {                          //Call member functions with object name
        cout << "\nArray is Empty";
    }
    else {
        cout << "\nArray is Not Empty";
    }

    cout << "\nSize of Array is: " << a.SizeofArray(); //Size of Array called
        
}

