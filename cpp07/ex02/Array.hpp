#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array
{
    private:

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        ~Array();

        Array &operator=(const Array &other);
};

#endif