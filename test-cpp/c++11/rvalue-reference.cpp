#include <string>
#include <memory>
#include <utility>
#include <algorithm>
#include <iostream>

template <typename T>
class Buffer 
{
   std::string          _name;
   size_t               _size;
   std::unique_ptr<T[]> _buffer;

public:
   // default constructor
   Buffer():
      _size(16),
      _buffer(new T[16])
   {
std::cout << "default constructor" << std::endl;
   }

   // constructor
   Buffer(const std::string& name, size_t size):
      _name(name),
      _size(size),
      _buffer(new T[size])
   {
std::cout << "constructor" << std::endl;
   }

   // copy constructor
   Buffer(const Buffer& copy):
      _name(copy._name),
      _size(copy._size),
      _buffer(new T[copy._size])
   {
      T* source = copy._buffer.get();
      T* dest = _buffer.get();
      std::copy(source, source + copy._size, dest);
std::cout << "copy constructor" << std::endl;
   }

   // copy assignment operator
   Buffer& operator=(const Buffer& copy)
   {
      if(this != &copy)
      {
         _name = copy._name;

         if(_size != copy._size)
         {
            _buffer = nullptr;
            _size = copy._size;
            _buffer = _size > 0 ? new T[_size] : nullptr;
         }

         T* source = copy._buffer.get();
         T* dest = _buffer.get();
         std::copy(source, source + copy._size, dest);
      }
std::cout << "copy assignment operator" << std::endl;
      return *this;
   }

   // move constructor
   Buffer(Buffer&& temp):
      _name(std::move(temp._name)),
      _size(temp._size),
      _buffer(std::move(temp._buffer))
   {
std::cout << "move constructor" << std::endl;
      temp._buffer = nullptr;
      temp._size = 0;
   }

   // move assignment operator
   Buffer& operator=(Buffer&& temp)
   {
std::cout << "move assignment operator" << std::endl;
      //assert(this != &temp); // assert if this is not a temporary

      _buffer = nullptr;
      _size = temp._size;
      _buffer = std::move(temp._buffer);

      _name = std::move(temp._name);

      temp._buffer = nullptr;
      temp._size = 0;
      
      return *this;
   }
};

template <typename T>
Buffer<T> getBuffer(const std::string& name) 
{
   Buffer<T> b(name, 128);
   return b;
}
int main()
{
   Buffer<int> b1;
   Buffer<int> b2("buf2", 64);
   Buffer<int> b3 = b2;
   Buffer<int> b4 = getBuffer<int>("buf4");
   b1 = getBuffer<int>("buf5");
   return 0;
}


/*
#include <iostream>
#include <string>

class Object
{
public:
	Object(const char* name) { this->name = name; std::cout << "Oject defult constructor" << std::endl; }
	Object(const Object& o) { std::cout << "Object copy constructor" << std::endl; }
	Object(Object&& o) { std::cout << "Object move constructor" << std::endl; }
	Object& operator=(const Object& o) { std::cout << "Object assign operator" << std::endl; return *this;}
	Object& operator=(Object&& o) { std::cout << "Object move assign operator" << std::endl; }

	std::string getName() const { return name; }

private:
	std::string name;
};

Object getObject()
{
	Object o("object name");
	return o;
}

void printObject(const Object& o)
{
	std::cout << o.getName() << std::endl;
}

int main()
{
//	printObject(getObject());

	Object o = getObject();
	Object o2 = o;


	return 0;
}
*/
