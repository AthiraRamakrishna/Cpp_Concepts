/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <array>
#include <cassert>
#include <iostream>



class Stack
{
    using container_type = std::array<int,10>;
    using size_type = container_type::size_type;
    
    container_type m_array{};
    size_type m_next{0};

    public:
    Stack()
    {
        m_next=0;
    }
    
    void reset()
    {
        m_next=0;
    }
    
    bool push(int val)
    {
        if(m_next<m_array.size())
        {
            m_array[m_next]=val;
            ++m_next;
            return true;
        }
        return false;
        
    }
    
    int pop()
    {
       assert(m_next>0 && "Can not pop empty stack");
       
       return m_array[--m_next];
    }
    
    void print()
    {
        std::cout << "( ";
        for(size_type i=0;i<m_next;i++)
        {
            std::cout<<m_array[i]<<" ";
        }
        std::cout << ") ";
    }
    
};


int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
    
	stack.print();

	return 0;
}
