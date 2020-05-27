#include "Cube.h"
#include<cassert>
#ifndef _Stack_HEADER_
#define _Stack_HEADER_
class Stack{
// private:
private:
    Cube **data;
    int capacity,index,id;
    friend std::ostream& operator<<(std::ostream& os,const Stack &t){
        os << "Stack" << t.id << ":";
        for(int i = 0; i < t.index; i++){
            os << *(t.data[i]);
        }
        return os;
    }
public:
    static int total;    
    Stack(int, string);  
    Stack(int);  
    Cube* last_element();
    void push_back(Cube*);
    void operator<<(Stack&);
    void del();
};
/**********************************************************************
*   Static variable 
***********************************************************************/
 int Stack::total = 0;

/**********************************************************************
* Contructor and destructor
***********************************************************************/
 Stack::Stack(int a, string classname){

    ++total;
    capacity = a;
    index = 0;
    id = total;
    data = new Cube*[a];
}
 Stack::Stack(int a){

    ++total;
    capacity = a;
    index = 0;
    id = total;
    data = new Cube*[a];
}

/**********************************************************************
*   Member Function 
***********************************************************************/
 void Stack::push_back(Cube *c){
    if(index > 0){
        if(*data[index - 1] < *c){
            assert(*data[index - 1] > *c);
            data[index] =  c;
            ++index;
        } 
    }
    
    data[index] =  c;
    ++index;
}
Cube* Stack::last_element(){
    assert(index <= capacity);
    return &(*(data[index - 1]));
}
void Stack::del(){
    --index;
    data[index] = new Cube;
}

#endif