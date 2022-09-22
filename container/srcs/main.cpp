#include <iostream>
#include <string>
#include <deque>
#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	#include <set>
	namespace ft = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
	#include <set.hpp>
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs)
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}

	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;

	ft::vector<int> v;

	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	std::cout << "[vector]" << std::endl;
	std::cout << "v[0] : " << v[0] << std::endl;
	std::cout << "v[1] : " << v[1] << std::endl;
	std::cout << "v[2] : " << v[2] << std::endl;

	ft::stack<int> s;

	s.push(3);
	s.push(2);
	s.push(4);
	std::cout << "[stack]" << std::endl;
	std::cout << "top : " << s.top() << std::endl;

	ft::map<int, int> m;
	ft::map<int, int>::iterator mi;

	m.insert(ft::make_pair(3,1));
	m.insert(ft::make_pair(1,2));
	m.insert(ft::make_pair(3,1));
	std::cout << "[map]" << std::endl;
	for (mi = m.begin() ; mi != m.end() ; mi++)
	{
		std::cout << mi->first << " " << mi->second << std::endl;
	}

	ft::set<int> set_type;
	ft::set<int>::iterator si;

	set_type.insert(30);
	set_type.insert(30);
	set_type.insert(20);
	set_type.insert(40);

	std::cout << "[set]" << std::endl;
	for (si = set_type.begin() ; si != set_type.end() ; si++)
	{
		std::cout << *si << std::endl;
	}

	return (0);
}
