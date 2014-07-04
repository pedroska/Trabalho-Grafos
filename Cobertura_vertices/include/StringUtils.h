#ifndef STRINGUTILS_H_INCLUDED
#define STRINGUTILS_H_INCLUDED

using namespace std;

class StringUtils
{

private:

    static  vector<string> &split(const string &s, char delim, vector<string> &elems)
    {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim))
        {
            elems.push_back(item);
        }
        return elems;
    }

public:

    static vector<string> split(const string &s, char delim)
    {
        vector<string> elems;
        split(s, delim, elems);
        return elems;
    }

};

#endif // STRINGUTILS_H_INCLUDED
