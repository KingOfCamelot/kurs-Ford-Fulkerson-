#include <iostream>
#include "Ford-Fulkerson.h"
#include "string.h"

using namespace std;

int main()
{
	Ford_Fulkerson example;
	string file_name = "test.txt";
	example.search_max_flow(file_name);
	return 0;
}