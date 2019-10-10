#pragma once
#include <cstdint>

class Fixed16
{

    int64_t fixed_value;

public:

    inline Fixed16(int i)
    {
        fixed_value = i << 16;
    }  
    
    
    inline Fixed16(const Fixed16 & other)
    {
        this->fixed_value = other.fixed_value;
    }

    inline Fixed16 & operator *= (const int i)
    {
        fixed_value *= i;
        return *this;
    }
    
    inline Fixed16 & operator *= (Fixed16 & f)
    {
        fixed_value = (fixed_value * f.fixed_value )>> 16;
        return *this;
    }
    
    inline Fixed16 & operator /= (const int i)
    {
        fixed_value /= i;
        return *this;
    }
    
    inline Fixed16 & operator /= (const Fixed16 & f)
    {
        fixed_value = (fixed_value << 16) / f.fixed_value;
        return *this;
    }

    inline explicit operator int() const {
        return fixed_value >> 16;
    }

    inline operator bool() const {
        return fixed_value != 0;
    }
};
