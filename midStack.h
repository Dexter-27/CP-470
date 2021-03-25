#include "DLL.h"
template<typename T>


class MidStack{
  DLL<T> * top;
  DLL<T> * mid;
  int count;

public:
  MidStack<T> (){
    top = NULL;
    mid = NULL;
    count = 0;
  }

  bool isEmpty(){
    return top==NULL;
  }

  T getTop(){
    if(isEmpty()) return 0;
    return top->data;
  }

  T getMid(){
    if(isEmpty()) return 0;
    return mid->data;
  }

  void push(T data){
    DLL<T> *newNode = new DLL<T>(data);
    if(isEmpty()){
      top = newNode;
      mid = top;
      ++count;
    }
    else{
      newNode->next = top;
      top->prev = newNode;
      if(count%2 ==1){
        // cout<<"hy";
        mid = mid->prev;
      }
      top = newNode;
      ++count;
    }
    // cout<<"Pushing in"<<data<<endl;
  }

  //60 50 40 30 20 10

  T pop(){
    if(isEmpty()) return 0;
    DLL<int> * temp = top;
    if(count%2==0){
      mid = mid->next;
    }
    top = top->next;
    --count;
    return temp->data;

  }

  int size(){
    return count;
  }



};
