#ifndef PLTOKENIZER_H
#define PLTOKENIZER_H

#include <vector>
#include <string>

struct PLToken
{
    enum
    {
        NAME, //some_name
        SEP, //separator comma or parentheses
        INFER, //:-
        QUERY, //?-
        END //.
    };

    int mType;
    std::string mData;
};

class PLTokenizer
{
    public:
        PLTokenizer();
        virtual ~PLTokenizer();

        std::vector <PLToken> tokenizeString(std::string str);

    protected:
    private:
};

#endif // PLTOKENIZER_H
