#include "MagicalContainer.hpp"
using namespace ariel;
using std::runtime_error;
// add element to the container with O(1)
void MagicalContainer::addElement(int element){
    _elements.push_back(element);//add the element to the end of the container
}
//remove element from the container with O(n)
void MagicalContainer::removeElement(int element){
    if (_elements.size() == 0)//check if the container is empty
    {
        throw runtime_error("The container is empty");
    }
    int flag = 0;
    //search for the element in the container
    for (auto it = _elements.begin(); it != _elements.end();)
    {
        if (*it == element)
        {
            it = _elements.erase(it);
            flag = 1;//find the element
        }
        else//if the element is not found
        {
            ++it;//move to the next element
        }
    }
    if (flag == 0)//if the element is not found
    {
        throw runtime_error("The element is not found");
    }
}
//return the size of the container with O(1)
size_t MagicalContainer::size() const {return _elements.size();}
//---------------------------------------------------------
//---------------------------------------------------------
//--------------------AscendingIterator--------------------
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)// Default constructor
    : MagicContainer(container), _elementLocation(0){
    // using std::sort library function
    std::sort(container._elements.begin(), container._elements.end());
}
//copy constructor
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
    : MagicContainer(other.MagicContainer), _elementLocation(other._elementLocation) {}
//Assignment operator
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){
    if(&MagicContainer != &other.MagicContainer){//check if the different iterators are equal
        throw runtime_error("The iterators are not equal");
    }
    if (this != &other)// check if this not the same object
    {
        MagicContainer = other.MagicContainer;//copy the container
        _elementLocation = other._elementLocation;//copy the location of the iterator
    }
    return *this;
}
//return the first element of the container
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
    if (MagicContainer.size() == 0)//check if the container is empty
    {
        throw runtime_error("The container is empty");
    }
    return AscendingIterator(MagicContainer);
    }
//return the last element of the container
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
    //call the default constructor
    AscendingIterator _endIter(MagicContainer);
    //set the location of the iterator to the last element
    _endIter._elementLocation = MagicContainer._elements.size();
    return _endIter;
}
//return the value of the current element
int& MagicalContainer::AscendingIterator::operator*() const{
    return MagicContainer._elements.at(_elementLocation);//return the value of the current element
}
//++i - move to the next element
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
    if (_elementLocation == MagicContainer.size())
    {
        throw runtime_error("size is out of range");
    }
    ++_elementLocation;//move to the next element
    return *this;//return the current element
}
//---------------------------------------------------------
//---------------------------------------------------------
//--------------------DescendingIterator-------------------
MagicalContainer::DescendingIterator::DescendingIterator(MagicalContainer &container)
    : MagicContainer(container), _elementLocation(0){
    std::sort(container._elements.rbegin(), container._elements.rend());//sort the container in descending order
}
//copy constructor
MagicalContainer::DescendingIterator::DescendingIterator(const DescendingIterator &other)
    : MagicContainer(other.MagicContainer), _elementLocation(other._elementLocation) {}
//Assignment operator
MagicalContainer::DescendingIterator& MagicalContainer::DescendingIterator::operator=(const DescendingIterator& other){
    if (&MagicContainer != &other.MagicContainer)//check if the iterators are equal
    {
        throw runtime_error("The iterators are not equal");
    }
    if (this != &other)// check if this not the same object
    {
        MagicContainer = other.MagicContainer;//copy the container
        _elementLocation = other._elementLocation;//copy the location of the iterator
    }
    return *this;
}
MagicalContainer::DescendingIterator MagicalContainer::DescendingIterator::begin(){
    if (MagicContainer.size() == 0)//check if the container is empty
    {
        throw runtime_error("The container is empty");
    }
    return DescendingIterator(MagicContainer);//return the first element of the container
}

MagicalContainer::DescendingIterator MagicalContainer::DescendingIterator::end(){
        //call the default constructor
    DescendingIterator _endIter(MagicContainer);
    //set the location of the iterator to the last element
    _endIter._elementLocation = MagicContainer._elements.size();
    return _endIter;
    }
//return the value of the current element
int& MagicalContainer::DescendingIterator::operator*() const{
    return MagicContainer._elements.at(_elementLocation);
}
//++i - move to the next element
MagicalContainer::DescendingIterator& MagicalContainer::DescendingIterator::operator++(){
    if (_elementLocation == MagicContainer.size())
    {
        throw runtime_error("size is out of range");
    }
    ++_elementLocation;//move to the next element
    return *this;//return the current element
}
//---------------------------------------------------------
//---------------------------------------------------------
//--------------------PrimeIterator------------------------
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
    : MagicContainer(container), _elementLocation(0){
    for(size_t i = 0; i < container._elements.size(); i++)
    {
        if(_isPrime(container._elements.at(i)) == true)
            _primeVector.push_back(&container._elements.at(i));
    }
}
//copy constructor
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
    : MagicContainer(other.MagicContainer), _elementLocation(other._elementLocation), _primeVector(other._primeVector) 
    {_primeVector = other._primeVector;}
//Assignment operator
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){
    if (&MagicContainer != &other.MagicContainer)//check if the iterators are equal
    {
        throw runtime_error("The iterators are not equal");
    }
    
    if (this != &other)// check if this not the same object
    {
        MagicContainer = other.MagicContainer;//copy the container
        _elementLocation = other._elementLocation;//copy the location of the iterator
        _primeVector = other._primeVector;//copy the prime vector of the iterator
    }
    return *this;
}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
    return PrimeIterator(MagicContainer);//return the first element of the container
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
    PrimeIterator _endIter(MagicContainer);//call the default constructor
    _endIter._elementLocation = _primeVector.size();//set the location of the iterator to the last element
    _endIter._primeVector = _primeVector;//copy the prime vector of the iterator
    return _endIter;
}
//check if the number is prime return true if it is
bool MagicalContainer::PrimeIterator::_isPrime(int p) const{
    if (p == 2)//check if the number is 2
    {
        return true;
    }
    if (p%2 == 0 || p < 2)//check if the number is even
    {
        return false;
    }
    for (int i = 3; i*i <= p; i+=2)//check if the number is divisible by any number smaller than it
    {
        if (p%i == 0)//check if the number is divisible by i
        {
            return false;
        }
    }
    return true;
}
//return the value of the current element(prime number)
int MagicalContainer::PrimeIterator::operator*() const{
    return *_primeVector.at(_elementLocation);//return the value of the current element
}
//++i - move to the next element
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){
    if (_elementLocation == _primeVector.size())
    {
        throw runtime_error("size is out of range");
    }
    ++_elementLocation;//move to the next element
    return *this;//return the current element
}
//---------------------------------------------------------
//--------------------SideCrossIterator--------------------
//from: 2 3 9 17 25      to:      2 25 3 17 9
//--------------------SideCrossIterator--------------------
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)
    : MagicContainer(container), _elementLocation(0){}
//copy constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
    : MagicContainer(other.MagicContainer), _elementLocation(other._elementLocation) {}
//Assignment operator
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
    if (&MagicContainer != &other.MagicContainer)//check if the iterators are equal
    {
        throw runtime_error("The iterators are not equal");
    }
    if (this != &other)
    {
        MagicContainer = other.MagicContainer;
        _elementLocation = other._elementLocation;
    }
    return *this;
}
 MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
    return SideCrossIterator(MagicContainer);
}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
    //call the default constructor
    SideCrossIterator _endIter(MagicContainer);
    //set the location of the iterator to the last element
    _endIter._elementLocation = MagicContainer._elements.size();
    return _endIter;
}
// // Return the value of the current element
int MagicalContainer::SideCrossIterator::operator*() const{
    size_t half_size = _elementLocation/2;//the middle of the container
    if (_elementLocation%2 != 0) {// take from the end of the container
        size_t end_element = (MagicContainer).size() - 1 - half_size;//the location of the current element
        return MagicContainer._elements.at(end_element);//return the value of the current element
    }
    return MagicContainer._elements.at(half_size); //return the value of the current element
 }

// // ++i - move to the next element
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){
    if (_elementLocation == MagicContainer.size())
    {
        throw runtime_error("size is out of range");
    }
    ++_elementLocation;//move to the next element
    return *this;//return the current element
}
//---------------------------------------------------------
