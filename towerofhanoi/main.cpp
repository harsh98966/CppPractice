#include "stack.h"
#include <vector>
using namespace std;
#define print cout<<stack[0]<<'\n'<<stack[1]<<'\n'<<stack[2]<<'\n';
#define size 8
Cube c[size]{8,7,6,5,4,3,2,1};
Stack stack[3] = {size,size,size};

void move(int start,int from, int where){
    if(*stack[from].last_element() == c[start]){
        stack[from].del();
        stack[where].push_back(&c[start]);
    }
}
void solve(int start,int end,int from,int dest, int spare){
      if(start == end) move(start,from,dest);
      else{
            solve(start + 1,end,from,spare,dest);
            solve(start,start,from,dest,spare);
            solve(start + 1,end,spare,dest,from);
        }      
}
int main(){
    for(int i = 0; i < size; i++){
        stack[0].push_back(&c[i]);
    }
    int from = 0,cube = 0,destination = 2, spare = 1;
    cout << "Initial State : " << endl;
    print
    solve(0,CUBE::total_cube - 1,0,2,1);
    cout << "Final State : " << endl;
    print
return 0;
}

