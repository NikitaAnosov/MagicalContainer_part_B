#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP
#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;
/*
operations:
• Default constructor
• Copy constructor
• Destructor
• Assignment operator
• Equality comparison (operator==)
• Inequality comparison (operator!=)
*/
namespace ariel{
    class MagicalContainer{
    private:
        vector<int> _elements;
    public:
        void addElement(int element);// add element to the container with O(1)
        void removeElement(int element);//remove element from the container with O(n)
        size_t size() const;//return the size of the container with O(1)
        //getters
        vector<int> getElements() const { return _elements; }//return the elements of the container(private member)
//----------------------------------------------------------------------------------------------------------------------
        class AscendingIterator{//iterator class for the container that iterate over the elements in ascending order
        private:
            MagicalContainer &MagicContainer;//reference to the container
            size_t _elementLocation;//the location of the iterator
        public:
            AscendingIterator(MagicalContainer &container); // Default constructor
            AscendingIterator(const AscendingIterator &other);    // Copy constructor
            AscendingIterator& operator=(const AscendingIterator& other);//Assignment operator
            AscendingIterator begin();//return the first element of the container
            AscendingIterator end();//return the last element of the container
            // operators
            //  AscendingIterator& operator=(const AscendingIterator& other);//Assignment operator
            bool operator==(const AscendingIterator &other) const{return (_elementLocation == other._elementLocation);} // Equality comparison (operator==)
            bool operator!=(const AscendingIterator &other) const{return (_elementLocation != other._elementLocation);} // Inequality comparison (operator!=)
            bool operator>(const AscendingIterator &other) const{return (_elementLocation > other._elementLocation);} // GT
            bool operator<(const AscendingIterator &other) const{return (_elementLocation < other._elementLocation);} // LT
            int& operator*() const;//return the value of the current element
            AscendingIterator &operator++(); //++i
            //for Tidy test
            ~AscendingIterator() = default;// Destructor
            AscendingIterator(AscendingIterator&& other) = default; // Move constructor
            AscendingIterator& operator=(AscendingIterator&& other)noexcept;// Move assignment operator

        };
//----------------------------------------------------------------------------------------------------------------------
        class DescendingIterator
        {
        private:
            MagicalContainer &MagicContainer;//reference to the container
            size_t _elementLocation;//the location of the iterator
        public:
            DescendingIterator(MagicalContainer &container);// Default constructor
            DescendingIterator(const DescendingIterator &other);// Copy constructor
            DescendingIterator& operator=(const DescendingIterator& other);//Assignment operator
            DescendingIterator begin();//return the first element of the container
            DescendingIterator end();//return the last element of the container
            // operators
            //  DescendingIterator& operator=(const DescendingIterator& other);
            bool operator==(const DescendingIterator &other) const{return (_elementLocation == other._elementLocation);} // Equality comparison (operator==)
            bool operator!=(const DescendingIterator &other) const{return (_elementLocation != other._elementLocation);} // Inequality comparison (operator!=)
            bool operator>(const DescendingIterator &other) const{return (_elementLocation > other._elementLocation);} // GT
            bool operator<(const DescendingIterator &other) const{return (_elementLocation < other._elementLocation);} // LT
            int& operator*() const;//return the value of the current element
            DescendingIterator &operator++();//++i
            //for Tidy test
            ~DescendingIterator() = default;// Destructor
            DescendingIterator(DescendingIterator&& other) = default; // Move constructor
            DescendingIterator& operator=(DescendingIterator&& other)noexcept;// Move assignment operator
        };
//----------------------------------------------------------------------------------------------------------------------
        class PrimeIterator//iterator class for the container that iterate over the prime elements
        {
        private:
            MagicalContainer &MagicContainer;//reference to the MagicalContainer
            vector<int *> _primeVector;//vector of the prime elements
            size_t _elementLocation;//the location of the current element

        public:
            PrimeIterator(MagicalContainer &container);// Default constructor
            PrimeIterator(const PrimeIterator &other);// Copy constructor
            PrimeIterator& operator=(const PrimeIterator& other);//Assignment operator
            PrimeIterator begin();//return the first element of the container
            PrimeIterator end();//return the last element of the container
            // operators
            //  PrimeIterator& operator=(const PrimeIterator& other);
            bool operator==(const PrimeIterator &other) const{return (_elementLocation == other._elementLocation);} // Equality comparison (operator==)
            bool operator!=(const PrimeIterator &other) const{return (_elementLocation != other._elementLocation);} // Inequality comparison (operator!=)
            bool operator>(const PrimeIterator &other) const{return (_elementLocation > other._elementLocation);} // GT
            bool operator<(const PrimeIterator &other) const{return (_elementLocation < other._elementLocation);} // LT
            int operator*() const;//return the value of the current element
            PrimeIterator &operator++(); //++i
            //helper function
            bool _isPrime(int) const ;//return true if the number is prime
            //for Tidy test
            ~PrimeIterator() = default;// Destructor
            PrimeIterator(PrimeIterator&& other) = default; // Move constructor
            PrimeIterator& operator=(PrimeIterator&& other)noexcept;// Move assignment operator
        };
//----------------------------------------------------------------------------------------------------------------------
        class SideCrossIterator
        {
        private:
            MagicalContainer &MagicContainer;//reference to the MagicalContainer
            size_t _elementLocation;//the location of the current element
        public:
            SideCrossIterator(MagicalContainer &container);// Default constructor
            SideCrossIterator(const SideCrossIterator &other);// Copy constructor
            SideCrossIterator& operator=(const SideCrossIterator& other);//Assignment operator
            SideCrossIterator begin();//return the first element of the container
            SideCrossIterator end();//return the last element of the container
            // operators
            //  SideCrossIterator& operator=(const SideCrossIterator& other);
            bool operator==(const SideCrossIterator &other) const{return (_elementLocation == other._elementLocation);} // Equality comparison (operator==)
            bool operator!=(const SideCrossIterator &other) const{return (_elementLocation != other._elementLocation);} // Inequality comparison (operator!=)
            bool operator>(const SideCrossIterator &other) const{return (_elementLocation > other._elementLocation);} // GT
            bool operator<(const SideCrossIterator &other) const{return (_elementLocation < other._elementLocation);} // LT
            int operator*() const;//return the value of the current element
            SideCrossIterator &operator++(); //++i
            //for Tidy test
            ~SideCrossIterator() = default;// Destructor
            SideCrossIterator(SideCrossIterator&& other) = default; // Move constructor
            SideCrossIterator& operator=(SideCrossIterator&& other)noexcept;// Move assignment operator
        };
//----------------------------------------------------------------------------------------------------------------------
    };
}
#endif