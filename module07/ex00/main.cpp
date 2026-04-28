#include <iostream>
#include "whatever.hpp"

int main( void ) {
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;
}

// int main() {
//     float   fa = 42.0f, fb = 21.0f;
//     int     ia = 33, ib = 77;
//     char    ca = 'a', cb = '0';

//     std::cout << "float :\n";
//     std::cout << "before swap: a = " << fa << " b = " << fb << " smallest = " << min(fa, fb) << " biggest = " << max<float>(fa, fb) << std::endl;
//     swap(fa, fb);
//     std::cout << "after swap: a = " << fa << " b = " << fb << " smallest = " << min(fa, fb) << " biggest = " << max<float>(fa, fb) << std::endl;

//     std::cout << "char :\n";
//     std::cout << "before swap: a = " << ca << " b = " << cb << " smallest = " << min(ca, cb) << " biggest = " << max<char>(ca, cb) << std::endl;
//     swap(ca, cb);
//     std::cout << "after swap: a = " << ca << " b = " << cb << " smallest = " << min(ca, cb) << " biggest = " << max<char>(ca, cb) << std::endl;

//     std::cout << "int :\n";
//     std::cout << "before swap: a = " << ia << " b = " << ib << " smallest = " << min(ia, ib) << " biggest = " << max<int>(ia, ib) << std::endl;
//     swap(ia, ib);
//     std::cout << "after swap: a = " << ia << " b = " << ib << " smallest = " << min(ia, ib) << " biggest = " << max<int>(ia, ib) << std::endl;
// }