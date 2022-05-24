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
	int size_line = 0;
	int** array = nullptr;
	int length_line = 2;
	ListOfNum<edge> list_2;

    void Read_from_file(string file_name)
    {
        ifstream file;
        file.open(file_name);
		string text_from_file;
		int start_point = -1;
		int finish_point = -1;
		if (file.is_open())
		{
			int i = -1;
			while (!file.eof())
			{
				file >> text_from_file;
				i++;
				if (!list.contains(text_from_file) && i < length_line)
				{
					list.push_back(text_from_file);
				}
				else if (i == 2)
				{
					i = -1;
				}
				text_from_file = "";
			}
			file.close();
		}
		size_line = list.get_size();
		if (size_line > 0)
		{
			array = new int* [size_line];
			for (int i = 0; i < size_line; i++)
			{
				array[i] = new int[size_line];
				for (int j = 0; j < size_line; j++) array[i][j] = 0;
			}
			file.open(file_name);
			string sum;
			if (file.is_open())
			{
				while (!file.eof())
				{
					file >> text_from_file;
					if (start_point == -1)
					{
						start_point = list.search(text_from_file);
						continue;
					}
					else if (finish_point == -1)
					{
						start_point = list.search(text_from_file);
						continue;
					}
					array[start_point][finish_point] = atoi(text_from_file.c_str());
					start_point = finish_point = -1;
				}
				cout << "Matrix graph" << endl;
				for (int i = 0; i < size_line; i++)
				{
					for (int j = 0; j < size_line; j++) cout << array[i][j];
				}
				cout << endl;
				file.close();
			}
		}
    }
	int search_max_flow(string file_name)
	{
		Read_from_file(file_name);
		int start_point_2 = list.search("S");
		int finish_point_2 = list.search("T");
		int temp = 0;
		int min_value = 0;
		int flow = 0;
		edge symbol;
		bool is = false;
		do
		{
			for (int j = 0; j < size_line && !is; j++)
			{
				is = array[start_point_2][j];
			}
			if (is)
			{
				for (int j = 0, i = start_point_2; j < size_line; j++)
				{
					if (array[i][j] > 0)
					{
						symbol.num = j;
						symbol.value = array[i][j];
						list_2.push_back(symbol);
						i = j;
						j = -1;
					}
					if (i == finish_point_2) break;
					else if (j == size_line - 1)
					{
						if (list_2.get_size() == 1)
						{
							i = start_point_2;
						}
						else
						{
							i = list_2.get_elem(list_2.get_size() - 2).num;
						}
						array[i][list_2.get_elem(list_2.get_size() - 1).num] = 0;
						list_2.clear();
						j = -1;
						if (i == start_point_2)
						{
							break;
						}
						i = start_point_2;
					}
				}
				if (list_2.get_size())
				{
					min_value = list_2.get_elem(0).value;
				}
				for (int j = 0, i = start_point_2; j < list_2.get_size(); j++)
				{
					if (min_value > list_2.get_elem(j).value) min_value = list_2.get_elem(j).value;
					if (j == list_2.get_size() - 1) flow += min_value;
				}
				for (int j = 0, i = start_point_2; j < list_2.get_size(); i = list_2.get_elem(j).num, j++)
				{
					array[i][list_2.get_elem(j).num] -= min_value;
				}
				list_2.clear();
			}
		} while (is);
		cout << "Max flow is " << flow << endl;
		return flow;
	}
};