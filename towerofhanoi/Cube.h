#include<iostream>
using namespace std;
#ifndef _CUBE_HEADER_
#define _CUBE_HEADER_
namespace CUBE{
    int total_cube = 0;
}
class Cube{
    int length;
    int id;
    public:
        Cube();
        Cube(int);
        ~Cube();
        bool operator==(Cube&);
        bool operator>(Cube&);
        bool operator<(Cube&);
        friend std::ostream& operator<<(std::ostream&, const Cube& );

};
Cube::Cube(int a){
    length = a;
    id = CUBE::total_cube; 
    ++CUBE::total_cube;
}
Cube::Cube(){
    length = 0;
    id = CUBE::total_cube; 
    ++CUBE::total_cube; 
}
Cube::~Cube(){
    --CUBE::total_cube;
}
std::ostream& operator<<(std::ostream& out, const Cube& c){
    if(c.length != 0) out << "  [" << c.length << "] ";
    else out << '\0';
    return out; 
}
bool Cube::operator>(Cube& c){
    if(this->length > c.length) return true;
    return false;
}
bool Cube::operator<(Cube& c){
    if(this->length < c.length) return true;
    return false;
}

bool Cube::operator==(Cube& c){
if(this->length == c.length) return true;
    return false;
} 

#endif