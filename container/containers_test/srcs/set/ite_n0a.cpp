#include "common.hpp"

#define T1 int

int		main(void)
{
	TESTED_NAMESPACE::set<T1> st;

	TESTED_NAMESPACE::set<T1>::const_iterator ite = st.begin();
	*ite = 42; // < -- error
	return (0);
}
