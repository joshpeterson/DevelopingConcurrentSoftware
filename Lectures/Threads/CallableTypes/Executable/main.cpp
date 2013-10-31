#include <iostream>
#include <thread> 
#include "callable_types.h"

using namespace callable_types;

int main()
{
	std::thread free_function_thread(free_function);
    free_function_thread.join();

	functor f;
	std::thread functor_thread(f);
    functor_thread.join();

	example e;
	std::thread member_function_thread(&example::member_function, e);
	member_function_thread.join();

	std::thread lambda_thread([] { std::cout << "Lambda expression\n";  });
	lambda_thread.join();

	std::cout << "Press any key to continue...\n";
	std::getchar();
}
