#include <iostream>
#include <cassert>
#include <cstring>


class MyString
{
  char* m_data{};
  int m_length{};
  
public:
    MyString(const char* source= "")
    {
        assert(source);
        
        m_length=std::strlen(source)+1;//Plus 1 for the terminator char
        
        m_data = new char[m_length];
        
        for(int i{0}; i< m_length; i++)
        {
            m_data[i]= source[i];
        }   
    }
    
    MyString(const MyString& copy)
    {
       deepCopy(copy);
    }
    
    void deepCopy(const MyString& source)
    {
        delete[] m_data;
        
        m_length = source.m_length;
        
        if(source.m_data)
        {
           m_data = new char[m_length];
        
            for(int i{0}; i<m_length;i++)
            {
                m_data[i]= source.m_data[i];
            } 
        }
        else
          m_data = nullptr;
    }
    
    MyString& operator=(const MyString& source)
    {
        if(this == &source)
            return *this;
        deepCopy(source);
    }
    
    ~MyString()
    {
        delete[] m_data;
    }
    
    char* getString() {return m_data;}
    int getLength() {return m_length;}
};

int main()
{
    MyString hello{ "Hello, world!" };
    {
        MyString copy{ hello }; // compiler will use default copy constructor if the copy constructor has not been defined, we need to define a deep copy when there is dynamic allocation of memory 
    } // copy is a local variable, so it gets destroyed here.  The destructor deletes copy's string, which leaves hello with a dangling pointer if not for the deep copy 

    std::cout << hello.getString() << '\n'; // this will have undefined behavior if not for deep copy

    return 0;
}
