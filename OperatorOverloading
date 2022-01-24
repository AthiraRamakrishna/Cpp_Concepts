#include<iostream>
#include <cassert>

using namespace std;

template<typename T>
T average(const T* myArray, int values)
{
    T sum{0};
    
    for(int count{0}; count < values; ++count)
        sum += myArray[count];
    sum /= values;
    
    return sum;
    
}


class Cents
{
    private:
        int m_cents{};
    
    public:
        Cents(int cents = 0):m_cents{cents}
        {
            
        }
        
    friend ostream& operator<< (ostream& out, const Cents& cents)
    {
        out<<cents.m_cents<< " cents";
        return out;
    }
    
    friend bool operator < (const Cents& c1, const Cents& c2)
    {
        return c1.m_cents<c2.m_cents;
    }
    
    friend bool operator > (const Cents& c1, const Cents& c2)
    {
        return !(operator <(c1,c2));
    }
    
    Cents& operator+= (const Cents& c)
    {
        m_cents += c.m_cents;
        return *this;
    }
    
    Cents& operator/= (int val)
    {
        assert(val!=0);
        m_cents /= val;
        return *this;
    }
};

int main()
{
    Cents centsArray[] { Cents { 5 }, Cents { 10 }, Cents { 15 }, Cents { 14 } };
    std::cout << average(centsArray, 4) << '\n';
    std::cout << (Cents{5} < Cents{15}) << '\n';
    std::cout << (Cents{5} > Cents{15}) << '\n';
    return 0;
}
