#ifndef STACK_H
#define STACK_H
#define MAX 10
#include <iostream>
template <typename T>
class stack{
	private:
		int top = -1;
		int arr[MAX];
		
		
		
	public:
		bool isEmpty() {
			return (top < 0);
		}	
		//isFull
		bool isFull(){
			return (top >= MAX-1);
		}
		//peek
		void peek(){
			if (isEmpty()){
				std::cout<<"The stack is Empty\n";
				
			}
			else{
			    std::cout<<"The value of the top is: " <<arr[top]<< std::endl;
			}
			
		}
	    //push
	    void push(T value){
	    	if (isFull()){
	    		std::cout<<"STACK OVERFLOW!!"<<std::endl;
	    		
			}
	    	else{
	    		arr[++top]=value;
	    		std::cout<<"Successfully pushed"<<value<<std::endl;
			}
		}
		//pop
		void pop(){
			if (isEmpty()){
				std::cout<<"The Stack is Empty. ";
			}
			else {
				std::cout<<"Successfully popped " <<arr[--top] <<std::endl;
				
			}
		}
		//display
		void display(){
			if (isEmpty()){
		
			    std::cout<<"The stack is Empty. " <<std::endl;
		    }
		    else{
		    	for(int i=top;  i >=0; i--){
		    		std::cout<< arr[i] <<std::endl;
				}
			}
			
		}
		
		
	};


#endif

