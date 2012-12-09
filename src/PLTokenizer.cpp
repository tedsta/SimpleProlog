#include "PLTokenizer.h"

#include <iostream>

PLTokenizer::PLTokenizer()
{
    //ctor
}

PLTokenizer::~PLTokenizer()
{
    //dtor
}

std::vector <PLToken> PLTokenizer::tokenizeString(std::string str)
{
    std::vector <PLToken> tokens;
    PLToken token;
    token.mType = -1;

    for (unsigned int i = 0; i < str.size(); i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_')
        {
            if (token.mType == PLToken::NAME)
                token.mData += str[i];
            else
            {
                if (token.mType != -1)
                    tokens.push_back(token);
                token.mType = PLToken::NAME;
                token.mData = str[i];
            }
        }
        else if (str[i] == '(' || str[i] == ')' || str[i] == ',')
        {
            if (token.mType != -1)
                tokens.push_back(token);
            token.mType = PLToken::SEP;
            token.mData = str[i];
        }
        else if (str[i] == '.')
        {
            if (token.mType != -1)
                tokens.push_back(token);
            token.mType = PLToken::END;
            token.mData = ".";
        }
        else if (str[i] == ':' && i+1 < str.size() && str[i+1] == '-')
        {
            if (token.mType != -1)
                tokens.push_back(token);
            token.mType = PLToken::INFER;
            token.mData = ":-";
            i++;
        }
        else if (str[i] == '?' && i+1 < str.size() && str[i+1] == '-')
        {
            if (token.mType != -1)
                tokens.push_back(token);
            token.mType = PLToken::QUERY;
            token.mData = "?-";
            i++;
        }
    }

    //add the last token
    if (token.mType != -1)
        tokens.push_back(token);

    return tokens;
}
