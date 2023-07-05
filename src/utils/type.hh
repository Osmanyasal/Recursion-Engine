#ifndef RECURSION_ENGINE__SRC__UTILS__TYPE
#define RECURSION_ENGINE__SRC__UTILS__TYPE

/*
    Following works like this class structure..

    class Base
    {
        public:
            virtual ~Base() {}
    };

    class Derived : public Base
    {
    };

    # takes references

        Derived dd;
        Base& bref = dd;

        INSTANCEOF(Base, dd) -> true
        INSTANCEOF(Derived, dd) -> true

        INSTANCEOF(Base, bref) -> true
        INSTANCEOF(Derived, bref) -> true

    # takes pointers

        Derived* dd = new Derived;
        INSTANCEOF_PTR(Base, dd) -> true
        INSTANCEOF_PTR(Derived, dd) -> true
*/

#define INSTANCEOF(derivedType, baseREF) (dynamic_cast<derivedType *>(&baseREF) != nullptr)
#define INSTANCEOF_PTR(derivedType, basePTR) (dynamic_cast<derivedType *>(basePTR) != nullptr)

#endif