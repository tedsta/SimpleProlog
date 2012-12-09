#include <iostream>

#include "Prolog.h"

int main(int argc, char *argv[])
{
    Program *program1 = new Program;
    PLParser *parser = new PLParser;
    parser->parseString(program1,
    "parent(david, john)."\
    "parent(jim, david)."\
    "parent(steve, jim)."\
    "parent(nathan, steve)."\
    "ancestor(A, B) :- parent(A, B)."\
    //"ancestor(A, B) :- parent(A, X), ancestor(X, B)."\
    "?- parent(adsf, asdf)."
    );

   return 0;
}
