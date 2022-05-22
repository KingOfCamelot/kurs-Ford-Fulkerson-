#include "string.h" 
#include <cctype>

using std::cin;
using std::cout;
using namespace std;


int String::num = 0;

int String::quantity()
{
    return num;
}

String::String(const char* temp)
{
    length = std::strlen(temp);
    line = new char[length + 1];
    strcpy(line, temp);
    num++;
}

String::String()
{
    length = 0;
    line = new char[1];
    line[0] = '\0';
    num++;
}

String::String(const String& str)
{
    num++;
    length = str.length;
    line = new char[length + 1];
    std::strcpy(line, str.line);
}

String::~String()
{
    --num;
    delete[] line;
}

char* get_value()
{
    return line;
}

char& String::operator[](int i)
{
    return line[i];
}

const char& String::operator[](int i) const
{
    return line[i];
}

bool operator<(const String& str_1, const String& str_2)
{
    return (std::strcmp(str_1.line, str_2.line) < 0);
}

bool operator>(const String& str_1, const String& str_2)
{
    return str_2 < str_1;
}

bool operator==(const String& str_1, const String& str_2)
{
    return (std::strcmp(str_1.line, str_2.line) == 0);
}

static ListOfNum<String> division(String& origin, char temp)
{
    ListOfNum<String> result;
    size_t newStringCount = 1, length = origin.length_();
    char* value = origin.line;

    for (size_t i = 0; i < length; i++) {
        if (value[i] == temp) newStringCount++;
    }

    size_t* markers = new size_t[newStringCount];
    markers[newStringCount - 1] = length;

    size_t counter = 0;
    for (size_t i = 0; i < length; i++)
    {
        if (value[i] == temp)
        {
            markers[counter] = i;
            counter++;
        }
    }

    size_t markerIndex = -1;
    size_t lastMarkerIndex = -1;
    for (size_t i = 0; i < newStringCount; i++)
    {
        markerIndex++;
        String segment;
        for (size_t j = lastMarkerIndex + 1; j < length; j++)
        {
            if (j > length - 1) break;

            if (j < markers[markerIndex]) segment = segment + (value[j]);
            else break;
        }
        if (segment.length > 0) result.push_back(segment);
        lastMarkerIndex = markers[markerIndex];
    }
    delete[] markers;
    return result;
}

ostream& operator<<(ostream& os, const String& str)
{
    os << str.line;
    return os;
}

String& String::operator=(const String& str)
{
    if (this == &str) return *this;
    delete[] line;
    length = str.length;
    line = new char[length + 1];
    std::strcpy(line, str.line);
    return *this;
}

String& String::operator=(const char* temp)
{
    delete[] line;
    length = std::strlen(temp);
    line = new char[length + 1];
    std::strcpy(line, temp);
    return *this;
}

String operator+(const String& str_1, const String& str_2)
{
    String _temp;
    delete[] _temp.line;
    _temp.length = str_1.length + str_2.length;
    _temp.line = new char[_temp.length + 1];
    std::strcpy(_temp.line, str_1.line);
    std::strcpy(_temp.line + str_1.length, str_2.line);
    return _temp;
}

istream& operator>>(istream& is, String& st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is) st = temp;
    while (is && is.get() != '\n') continue;
    return is;
}