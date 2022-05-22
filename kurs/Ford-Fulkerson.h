#include "list.h"
#include "string.h"
#include <fstream>

using namespace std;

class Ford_Fulkerson
{
public:
	struct edge
	{
        int value;
		int num;

        edge()
            : value(value), num(0) {}
	};
	ListOfNum<string> list;
	int size = 0;
	int** array = nullptr;
	int length_line = 2;
	ListOfNum<edge> list_2;

    void Read_from_file(string file_name)
    {
        ifstream file;
        file.open(file_name);
		string text;
		int start = -1;
		int finish = -1;
		if (file.is_open())
		{
			int i = -1;
			while (!file.eof())
			{
				file >> text;
				i++;
				if (!list.contains(text) && i < length_line) list.push_back(text);
				else if (i == 2) i = -1;
				text = "";
			}
			file.close();
		}
		size = list.get_size();
		if (size > 0)
		{
			array = new int* [size];
			for (int i = 0; i < size; i++)
			{
				array[i] = new int[size];
				for (int j = 0; j < size; j++) array[i][j] = 0;
			}
			file.open(file_name);
			string sum;
			if (file.is_open())
			{
				while (!file.eof())
				{
					file >> text;
					if (start == -1)
					{
						start = list.search(text);
						continue;
					}
					else if (finish == -1)
					{
						start = list.search(text);
						continue;
					}
					array[start][finish] = atoi(text.c_str());
					start = -1;
					finish = -1;
				}
				/*std::cout << "Initial matrix" << endl;
				std::cout << "  ";
				for (int i = 0; i < size; i++)
				{
					cout << list.get_elem(i) << " ";
				}
				cout << endl;
				for (int i = 0; i < size; i++)
				{
					std::cout << list.get_elem(i) << " ";
					for (int j = 0; j < size; j++)
					{
						std::cout << array[i][j] << " ";
					}
					std::cout << endl;
				}
				std::cout << endl;*/
				file.close();
			}
		}
    }
	int max_flow()
	{
		int start = list.search("S");
		int finish = list.search("T");
		int temp = 0, min = 0, sum = 0;
		edge symbol;
		bool is = false;
		do
		{
			is = false;
			for (int j = 0; j < size && !is; j++) is = array[start][j];
			if (is)
			{
				for (int j = 0, i = start; j < size; j++)
				{
					if (array[i][j] > 0)
					{
						symbol.num = j;
						symbol.value = array[i][j];
						list_2.push_back(symbol);
						i = j;
						j = -1;
					}
					if (i == finish) break;
					else if (j == size - 1)
					{
						if (list_2.get_size() == 1) i = start;
						else i = list_2.get_elem(list_2.get_size() - 2).num;
						array[i][list_2.get_elem(list_2.get_size() - 1).num] = 0;
						list_2.clear();
						j = -1;
						if (i == start) break;
						i = start;
					}
				}
				if (list_2.get_size()) min = list_2.get_elem(0).value;
				for (int j = 0, i = start; j < list_2.get_size(); j++)
				{
					if (min > list_2.get_elem(j).value) min = list_2.get_elem(j).value;
					if (j == list_2.get_size() - 1) sum += min;
				}
				for (int j = 0, i = start; j < list_2.get_size(); i = list_2.get_elem(j).num, j++) array[i][list_2.get_elem(j).num] -= min;
				list_2.clear();
				/*for (i = 0; i < size; i++)
				{
					std::cout << namecol.get_elem(i) << " ";
				}
				std::cout << endl;
				for (i = 0; i < size; i++)
				{
					std::cout << namecol.get_elem(i) << " ";
					for (int j = 0; j < size; j++)
					{
						std::cout << matrix[i][j] << " ";
					}
					std::cout << endl;
				}
				std::cout << endl;*/
			}
		} while (is);
		return sum;
	}
};