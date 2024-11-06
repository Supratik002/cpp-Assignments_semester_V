#include<iostream>

class char_vec{
        int sz;
        char element[1];
public:
        static char_vec* new_char_vec(int s);

        virtual char& operator[](int i){
           return element[i];
        }
        char_vec(int s){ sz = s; }
};

/* The derived class has another member named element, now a char* */
class char_vec_derived : public char_vec{
        char *element;
public:
        char_vec_derived(int size, char* e): char_vec {size}, element {e}
        {
                element = e;
        }
        /* the operator is overriden to access "element" of this class instead of the base
         * This makes it safe to access element[i] (assuming i is within range)
         */
        char& operator[](int i) override{
           return element[i];
        }
};
char_vec* char_vec::new_char_vec(int s)
{
        char *e = new char[s]; // allocate and initialize memory
        for(unsigned int i=0;i<s;i++)
            e[i] = 'a' + i;

        char_vec* c = new char_vec_derived(s,e); // create a derived class obj and return its ptr
        return c;
}

int main()
{
        char_vec* cobj = char_vec::new_char_vec(3);
        for(unsigned int i=0;i<3;i++)
                /* operator[] being virtual, the derived virtual will be invoked */
                std::cout << cobj->operator[](i) << std::endl;
}

                                                                                                            

