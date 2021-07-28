#include <cstdio>

void
num_2_1 () {
    unsigned short a = 0b10101010 ; // binary : 앞에 '0b' 붙이기
    printf("%hu\n", a) ;

    int b = 0123 ; // octal : 앞에 '0' 붙이기
    printf("%d\n", b) ;

    unsigned long long d = 0xFFFFFFFFFFFFFFFF ; // hexadecimal : 앞에 '0x' 붙이기
    printf("%llu\n", d) ;
}

void
num_2_2 () {
    unsigned int a = 3669732608 ;
    printf("Yabba %x!\n", a) ; // hexidecimal format

    unsigned int b = 69 ;
    printf("There are %u, %o leaves here.\n", b, b) ; // unsigned integer format, octal integer format
}

void
num_2_3 () {
    double an = 6.0221409e23 ;
    printf("Avogadro's number: %le %lf %lg\n", an, an, an) ; // le : long double을 지수로, lf : long double, lg : 
    
    float hp = 9.75 ;
    printf("Hogwarts' Platform: %e %f %g\n", hp, hp, hp) ; // e : 지수로, f : double or float, g : double or float
}

void 
num_2_4 () {
    char x = 'M' ;
    wchar_t y = L'Z' ; // wide character, 문제: wchar_t y = 'Z'L ; 
    printf("Windows binaries start with %c%lc.\n", x, y) ;
}

void
num_2_5 () {
    bool b1 = true ;
    bool b2 = false ;
    printf("%d %d\n", b1, b2) ;
}

void
num_2_6 () {
    printf(" 7 ==  7: %d\n", 7 == 7) ;
    printf(" 7 !=  7: %d\n", 7 != 7) ;
    printf("10 >  20: %d\n", 10 > 20) ;
    printf("10 >= 20: %d\n", 10 >= 20) ;
    printf("10 <  20: %d\n", 10 < 20) ;
    printf("20 <= 20: %d\n", 20 <= 20) ; // 문제: printf(" 20 <= 20: %d\n", 20 =< 20)
}

void
num_2_7 () {
    bool t = true ;
    bool f = false ;
    printf("true  &&  false: %d\n", t &&  f) ;
    printf("true  && !false: %d\n", t && !f) ;
    printf("true  ||  false: %d\n", t ||  f) ;
    printf("false ||  false: %d\n", f ||  f) ;
}

void
num_2_8 () {
    size_t size_c = sizeof(char) ;
    printf("char : %zu\n", size_c) ; // lu도 되고 zu도 된다

    size_t size_s = sizeof(short) ;
    printf("short : %zu\n", size_s) ; 

    size_t size_i = sizeof(int) ;
    printf("int : %zu\n", size_i) ; 

    size_t size_l = sizeof(long) ;
    printf("long : %zu\n", size_l) ; 

    size_t size_ll = sizeof(long long) ;
    printf("long long : %zu\n", size_ll) ; 
}

void
num_2_9 () {
    int arr[] = { 1, 2, 3, 4 } ;
    printf("The third element is %d.\n", arr[2]) ;
 
    arr[2] = 100 ;
    printf("The third element is %d.\n", arr[2]) ;
}

void
num_2_10 () {
    unsigned long maximum = 0 ;
    unsigned long values[] = { 10, 50, 20, 40, 0 } ;
    for (size_t i = 0 ; i < 5 ; i++) {
        if (values[i] > maximum) 
            maximum = values[i] ;
    }
    printf("The maximum value is %lu\n", maximum) ;
}

void
num_2_11 () {
    unsigned long maximum = 0 ;
    unsigned long values[] = { 10, 50, 20, 40, 0 } ;
    for (unsigned long value : values) {
        if (value > maximum)
            maximum = value ;
    }
    printf("The maximum value is %lu\n", maximum) ;
}

void
num_2_12 () {
    char alphabet[27] ;
    for (int i = 0 ; i < 26 ; i++) {
        alphabet[i] = i + 97 ;
    }

    alphabet[26] = 0 ;
    printf("%s\n", alphabet) ;

    for (int i = 0 ; i < 26 ; i++) {
        alphabet[i] = i + 65 ;
    }
    printf("%s\n", alphabet) ;

}

// num_2_13
enum class Race {
    Dinan,
    Teklan,
    Ivyn,
    Moiran,
    Camite,
    Julian,
    Aidan
} ;

// num_2_14 는 switch 문법

void
num_2_15 () {
    Race race = Race::Dinan ;
    
    switch(race) {
        case Race::Dinan: {
            printf("You work hard.\n") ;
        } break ;
        case Race::Teklan: {
            printf("You are very strong.\n") ;
        } break ;
        case Race::Ivyn: {
            printf("You are a great leader.\n") ;
        } break ;
        case Race::Moiran: {
            printf("My, how vesatile you are!\n") ;
        } break ;
        case Race::Camite: {
            printf("You're incredible helpful.\n") ;
        } break ;
        case Race::Julian: {
            printf("Anything you want!\n") ;
        } break ;
        case Race::Aidan: {
            printf("What an enigma.\n") ;
        } break ;
        default: {
            printf("Error: unkown race!\n") ;
        }
    }
}

struct Book {
    char name[256] ;
    int year ;
    int pages ;
    bool hardcover ;
} ;

void
num_2_16 () {
    Book neuromancer ;
    neuromancer.pages = 271 ;
    printf("Neuromancer has %d pages.\n", neuromancer.pages) ;
}

// num_2_17
union Variant {
    char string[10] ;
    int integer ;
    double floating_point ;
} ; // 가장 큰 변수 크기만 메모리에 할당 된다. (double) 또한 하나의 멤버만 사용해야 한다.

void
num_2_18 () {
    Variant v ;
    v.integer = 42 ;
    printf("The ultimate answer: %d\n", v.integer) ;

    v.floating_point = 2.7182818284 ;
    printf("Euler's number e:   %f\n", v.floating_point) ;
    printf("A dumster fire:     %d\n", v.integer) ;
}

struct ClockOfTheLongNow1 {
    void
    add_year () {
        year++ ; 
    }
    int year ;
} ;

void
num_2_19 () {
    ClockOfTheLongNow1 clock ;
    clock.year = 2017 ;
    clock.add_year() ;
    printf("year: %d\n", clock.year) ;
    clock.add_year() ;
    printf("year: %d\n", clock.year) ;
}

// num_2_20
struct ClockOfTheLongNow2 {
    void
    add_year () {
        year++ ;
    }

    bool
    set_year (int new_year) {
        if (new_year < 2019)
            return false ;
        year = new_year ;
        return true ;
    }

    int get_year () {
        return year ;
    }

private:
    int year ;
} ;

void
num_2_21 () {
    ClockOfTheLongNow2 clock ;
    if (!clock.set_year(2018)) {
        clock.set_year(2019) ;
    }
    clock.add_year() ;
    printf("year: %d\n", clock.get_year()) ;
}
// 문제
// void
// num_2_21 () {
//     ClockOfTheLongNow2 clock ;
//     clock.year = 2019 ;
//     clock.add_year() ;
//     printf("year: %d\n", clock.get_year()) ;
// }

// num_2_22
struct ClockOfTheLongNow3 {
    ClockOfTheLongNow3 () {
        year = 2019 ;
    }

    void
    add_year () {
        year++ ;
    }

    bool
    set_year (int new_year) {
        if (new_year < 2019)
            return false ;
        year = new_year ;
        return true ;
    }

    int get_year () {
        return year ;
    }

private:
    int year ;
} ;

// num_2_23
struct ClockOfTheLongNow4 {
    ClockOfTheLongNow4 (int year_in) {
        if(!set_year(year_in)) {
            year = 2019 ;
        }
    }

    void
    add_year () {
        year++ ;
    }

    bool
    set_year (int new_year) {
        if (new_year < 2019)
            return false ;
        year = new_year ;
        return true ;
    }

    int get_year () {
        return year ;
    }

private:
    int year ;
} ;

void
num_2_23 () {
    ClockOfTheLongNow4 clock{ 2021 } ; // ClockOfTheLongNow4 clock( 2020 ) ; 도 가능한가?
    printf("Year: %d\n", clock.get_year()) ;
}

struct PodStrcut {
    __uint64_t a ;
    char b[256] ;
    bool c ;
} ;

void
num_2_24 () {
    PodStrcut initialized_pod1{} ; // a, b, c = 0
    PodStrcut initialized_pod2 = {} ; // a, b, c = 0

    PodStrcut initialized_pod3{ 42, "Hello" } ; // a, b는 set. c = 0
    PodStrcut initialized_pod4{ 42, "Hello", true } ; // a, b, c set
}

void
num_2_25 () {
    int array_1[]{ 1, 2, 3 } ;
    int array_2[5]{} ;
    int array_3[5]{ 1, 2, 3 } ;
    int array_4[5] ;
}

//num_2_26
struct Taxonomist {
    Taxonomist () {
        printf("(no argument)\n") ;
    }

    Taxonomist (char x) {
        printf("char: %c\n", x) ;
    }
    Taxonomist (int x) {
        printf("int: %d\n", x) ;
    }
    Taxonomist (float x) {
        printf("float: %f\n", x) ;
    }
} ;

void
num_2_27 () {
    Taxonomist t1 ;
    Taxonomist t2 { 'c' } ;
    Taxonomist t3 { 65537 } ;
    Taxonomist t4 { 6.02e23f } ;
    Taxonomist t5 { 'g' } ;
    Taxonomist t6 { '1' } ;
    Taxonomist t7 {} ;
    Taxonomist t8 () ; // 함수선언으로 보이기 때문에 아무것도 출력 안 된다
}

int 
main() {

    num_2_3() ;

}

