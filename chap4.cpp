#include <cstdio>
#include <cstring>
#include <stdexcept>

static int rat_things_power = 200 ;// extern int rat_things_power = 200 ; 하면 다른 파일에서도 이 변수를 쓸 수 있다.

void
power_up_rat_thing (int nuclear_isotopes) {
    rat_things_power = rat_things_power + nuclear_isotopes ;
    const auto waste_heat = rat_things_power * 20 ;
    if (waste_heat > 10000) {
        printf("Warning! Hot doggie!\n") ;
    }
}

void
num_4_2 () {
    printf("Rat-thing power: %d\n", rat_things_power) ;
    power_up_rat_thing(100) ;
    printf("Rat-thing power: %d\n", rat_things_power) ;
    power_up_rat_thing(500) ;
    printf("Rat-thing power: %d\n", rat_things_power) ;
}

void
power_up_rat_thing2 (int nuclear_isotopes) {
    static int rat_things_power2 = 200 ; // encapsulation이다
    rat_things_power2 = rat_things_power2 + nuclear_isotopes ;
    const auto waste_heat = rat_things_power2 * 20 ;
    if (waste_heat > 10000) {
        printf("Warning! Hot doggie!\n") ;
    }
    printf("Rat-thing power: %d\n", rat_things_power2) ;
}

void
num_4_3 () {
    power_up_rat_thing2(100) ;
    power_up_rat_thing2(500) ;
}

struct RatThing {
    static int rat_things_power3 ; // thread로부터 안전하게 하려면 static thread_local int rat_things_power3 ; 로 선언
    static void
    power_up_rat_thing3 (int nuclear_isotopes) {
        rat_things_power3 = rat_things_power3 + nuclear_isotopes ;
        const auto waste_heat = rat_things_power3 * 20 ;
        if (waste_heat > 10000) {
            printf("Warning! Hot doggie!\n") ;
        }
        printf("Rat-thing power: %d\n", rat_things_power3) ;
    }
} ;

int RatThing::rat_things_power3 = 200 ;

void
num_4_4 () {
    RatThing::power_up_rat_thing3(100) ;
    RatThing::power_up_rat_thing3(500) ;
}

// num_4_5
struct Tracer {
    Tracer(const char* name) : name{ name } {
        printf("%s constructed.\n", name) ;
    }
    ~Tracer() {
        printf("%s destructed.\n", name) ;
    }
private:
    const char* const name ;
} ;

// static Tracer t1{ "Static variable" } ;
// thread_local Tracer t2{ "Thread-local variable" } ;

// void
// num_4_6 () {
//     const auto t2_ptr = &t2 ;
//     printf("A\n") ;
//     Tracer t3{ "Automatic variable" } ;
//     printf("B\n") ;
//     const auto* t4 = new Tracer{ "Dynamic variable" } ;
//     printf("C\n") ;
// }

//num_4_8
struct Groucho {
    void forget (int x) {
        if (x == 0xFACE) {
            throw std::runtime_error{ "I'd be glad to make an exception." } ; // 문제 빈칸에 들어가야할 것은? 
        }
        printf("Forgot 0x%x\n", x) ;
    }
} ;

void
num_4_9 () {
    Groucho groucho ;
    try {
        groucho.forget(0xC0DE) ;
        groucho.forget(0xFACE) ;
        groucho.forget(0xC0FFEE) ;
    } catch (const std::runtime_error &e) {
        printf("exception caught with message: %s\n", e.what()) ; // 문제: 빈칸에 들어가야 할 것은?
    }
}

// num_4_10
struct Superclass {
    int x ;
} ;

struct Subclass : Superclass {
    int y = 2;
    int foo () {
        return x + y ;
    }
} ;

// num_4_11
// try {
//     // some code
// } catch (const std::systemp_error& ex) {
//     if (ex.code() != std::errc::permission_denied) {
//         // Not a permission denied error
//         throw ; // main에서의 exception으로 간다.
//     }
//     // Recover from a permission denied
// }

// num_4_12 이해 안 된다.

struct CyberdyneSeries800 {
    CyberdyneSeries800 () {
        printf("I'm a friend of Sarah Connor.\n") ;
    }
    ~CyberdyneSeries800 () {
        throw std::runtime_error{ "I'll be back." } ;
    }
} ;

void
num_4_13 () {
    try {
        CyberdyneSeries800 t800 ;
        throw std::runtime_error{ "Come with me if you want to live."} ;
    } catch (const std::exception& e) {
        printf("Caught exception: %s\n", e.what()) ;
    }
} // 출력은 "I'm a friend of Sarah Connor." -> throw하고 -> "I'll be back." -> 종료.

// num_4_14
struct SimpleString {
    SimpleString(size_t max_size) : max_size{ max_size }, length{} {
        if (max_size == 0) {
            throw std::runtime_error{ "Max size must be at least 1." } ;
        }
        buffer = new char[max_size] ;
        buffer[0] = 0 ;
    }
    ~SimpleString() {
        delete[] buffer ;
    }
// -- snip --

private:
    size_t max_size ;
    char *buffer ;
    size_t length ;
} ;

// num_4_15
struct SimpleString2 {
    SimpleString2(size_t max_size) : max_size{ max_size }, length{} {
        if (max_size == 0) {
            throw std::runtime_error{ "Max size must be at least 1." } ;
        }
        buffer = new char[max_size] ;
        buffer[0] = 0 ;
    }
    ~SimpleString2() {
        delete[] buffer ;
    }

    void
    print (const char* tag) const {
        printf("%s: %s", tag, buffer) ;
    }

    bool
    append_line (const char* x) {
        const auto x_len = strlen(x) ;
        if (x_len + length + 2 > max_size)
            return false ;
        std::strncpy(buffer + length, x, max_size - length) ;
        length += x_len ;
        buffer[length++] = '\n' ;
        buffer[length] = 0 ;
        return true ;
    }

private:
    size_t max_size ;
    char *buffer ;
    size_t length ;
} ;

void
num_4_16 () {
    SimpleString2 string{ 115 } ;
    string.append_line("starbuck, whaddya hear?") ;
    string.append_line("Nothin' but the rain.") ;
    string.print("A") ;
    string.append_line("Grab your gun and bring the cat in.") ;
    string.append_line("Aye-aye sir, coming home.") ;
    string.print("B") ;
    if (!string.append_line("Galactical!")) {
        printf("String was not big enough to append another message.\n") ;
    }
}

// num_4_18
struct SimpleStringOwner {
    SimpleStringOwner(const char* x) : string{ 10 } {
        if (!string.append_line(x)) {
            throw std::runtime_error{ "Not enough memory!" } ;
        }
        string.print("Constructed") ;
    }
    ~SimpleStringOwner() {
        string.print("About to destroy") ;
    }
private:
    SimpleString2 string ;
} ;

void
num_4_19 () {
    SimpleStringOwner x{ "x" } ;
    printf("x is alive\n") ;
}

void
fn_c () {
    SimpleStringOwner c{ "cccccccccc" } ;
}

void
fn_b () {
    SimpleStringOwner b{ "b" } ;
    fn_c() ;
}

void
num_4_20 () {
    try {
        SimpleStringOwner a{ "a" } ;
        fn_b() ;
        SimpleStringOwner d{ "d" } ;
    } catch (const std::exception& e) {
        printf("Exception: %s\n", e.what()) ;
    }
}

// struct HumptyDumpty {
//     HumptyDumpty() ;

//     bool
//     is_together_again () ;
//     // --snip--
// } ;

// bool
// send_kings_horses_and_men () {
//     HumptyDumpty hd{} ;
//     if (hd.is_together_again())
//         return false ;
//     return true ;
// }

// // num_4_22
// struct Result {
//     HumptyDumpty hd ;
//     bool success ;
// } ;

// Result
// make_humpty () {
//     HumptyDumpty hd{} ;
//     bool is_vaild ;
//     // check that hd is valid and set is_vaild appropriately
//     return { hd, is_vaild } ;
// }

// bool
// send_kings_horses_and_men2 () {
//     auto [hd, success] = make_humpty() ;
//     if (!success)
//         return false ;
//     // class invariants established
//     //--snip--
//     return true ;
// }

int
add_one_to (int x) {
    x++ ;
    return x ;
}

void
num_4_23 () {
    auto original = 1 ;
    auto result = add_one_to(original) ;
    printf("Original: %d; Result: %d\n", original, result) ;
}

// num_4_24
struct Point {
    int x, y ;
} ;

Point
make_transpose (Point p) {
    int tmp = p.x ;
    p.x = p.y ;
    p.y = tmp ;
    return p ;
}

// num_4_25
struct SimpleString3 {
    SimpleString3(size_t max_size) : max_size{ max_size }, length{} {
        if (max_size == 0) {
            throw std::runtime_error{ "Max size must be at least 1." } ;
        }
        buffer = new char[max_size] ;
        buffer[0] = 0 ;
    }

    SimpleString3(const SimpleString3& other) : max_size{ other.max_size }, buffer{ new char[other.max_size] }, length{ other.length} {
        std::strncpy(buffer, other.buffer, max_size) ;
    }

    ~SimpleString3() {
        delete[] buffer ;
    }

    void
    print (const char* tag) const {
        printf("%s: %s", tag, buffer) ;
    }

    bool
    append_line (const char* x) {
        const auto x_len = strlen(x) ;
        if (x_len + length + 2 > max_size)
            return false ;
        std::strncpy(buffer + length, x, max_size - length) ;
        length += x_len ;
        buffer[length++] = '\n' ;
        buffer[length] = 0 ;
        return true ;
    }

private:
    size_t max_size ;
    char *buffer ;
    size_t length ;
} ;

void
num_4_26 () {
    SimpleString3 a{ 50 } ;
    a.append_line("We apologize for the") ;
    SimpleString3 a_copy{ a } ;
    a.append_line("inconvenience.") ;
    a_copy.append_line("incontinence.") ;
    a.print("a") ;
    a_copy.print("a_copy") ;
}

void
foo (SimpleString3 x) {
    x.append_line("This change is lost.") ;
}

void
num_4_27 () {
    SimpleString3 a{ 20 } ;
    foo(a) ;
    a.print("Still empty") ;
}

// num_4_28
void
dont_do_this() {
    SimpleString3 a{ 50 } ;
    a.append_line("We apologize for the") ;
    SimpleString3 b{ 50 } ;
    b.append_line("Last message") ;
    a.print("a") ;
    b.print("b") ;
    b = a ; // 하기 전에 b clean하고 쓰기
    a.print("a") ;
    b.print("b") ;
}

// num_4_29 & num_4_30
struct SimpleString4 {
    SimpleString4(size_t max_size) : max_size{ max_size }, length{} {
        if (max_size == 0) {
            throw std::runtime_error{ "Max size must be at least 1." } ;
        }
        buffer = new char[max_size] ;
        buffer[0] = 0 ;
    }

    SimpleString4(const SimpleString4& other) : max_size{ other.max_size }, buffer{ new char[other.max_size] }, length{ other.length} {
        std::strncpy(buffer, other.buffer, max_size) ;
    }

    SimpleString4& operator = (const SimpleString4& other) {
        if (this == &other)
            return *this ;
        const auto new_buffer = new char[other.max_size] ;
        delete[] buffer ; // 문제: 이거 지우기 
        buffer = new_buffer ;
        length = other.length ;
        max_size = other.max_size ;
        std::strncpy(buffer, other.buffer, max_size) ;
        return *this ;
    }

    ~SimpleString4() {
        delete[] buffer ;
    }

    void
    print (const char* tag) const {
        printf("%s: %s", tag, buffer) ;
    }

    bool
    append_line (const char* x) {
        const auto x_len = strlen(x) ;
        if (x_len + length + 2 > max_size)
            return false ;
        std::strncpy(buffer + length, x, max_size - length) ;
        length += x_len ;
        buffer[length++] = '\n' ;
        buffer[length] = 0 ;
        return true ;
    }

private:
    size_t max_size ;
    char *buffer ;
    size_t length ;
} ;

void
num_4_31 () {
    SimpleString4 a{ 50 } ;
    a.append_line("We apologize for the") ;
    SimpleString4 b{ 50 } ;
    b.append_line("Last message") ;
    a.print("a") ;
    b.print("b") ;
    b = a ;
    a.print("a") ;
    b.print("b") ;
}

void
ref_type (int &x) {
    printf("lvalue reference %d\n", x) ;
}

void
ref_type (int &&x) {
    printf("rvalue reference %d\n", x) ;
}

void
num_4_33 () { 
    auto x = 1 ;
    ref_type(x) ;
    ref_type(2) ;
    ref_type(x + 2) ;
}

void
num_4_34 () {
    auto x = 1 ;
    ref_type(std::move(x)) ; // move()는 l-value를 r-value로 바꾸는 것.
    ref_type(2) ;
    ref_type(x + 2) ;
}

// num_4_35
struct SimpleString5 {
    SimpleString5(size_t max_size) : max_size{ max_size }, length{} {
        if (max_size == 0) {
            throw std::runtime_error{ "Max size must be at least 1." } ;
        }
        buffer = new char[max_size] ;
        buffer[0] = 0 ;
    }
    SimpleString5(const SimpleString5& other) : max_size{ other.max_size }, buffer{ new char[other.max_size] }, length{ other.length} {
        std::strncpy(buffer, other.buffer, max_size) ;
    }
    SimpleString5(SimpleString5&& other) noexcept : max_size{ other.max_size }, buffer{ other.buffer }, length{ other.length } {
        other.length = 0 ;
        other.buffer = nullptr ;
        other.max_size = 0 ;
    }
    SimpleString5& operator = (const SimpleString5& other) {
        if (this == &other)
            return *this ;
        const auto new_buffer = new char[other.max_size] ;
        delete[] buffer ; // 문제: 이거 지우기 
        buffer = new_buffer ;
        length = other.length ;
        max_size = other.max_size ;
        std::strncpy(buffer, other.buffer, max_size) ;
        return *this ;
    }

    ~SimpleString5() {
        delete[] buffer ;
    }

    void
    print (const char* tag) const {
        printf("%s: %s", tag, buffer) ;
    }

    bool
    append_line (const char* x) {
        const auto x_len = strlen(x) ;
        if (x_len + length + 2 > max_size)
            return false ;
        std::strncpy(buffer + length, x, max_size - length) ;
        length += x_len ;
        buffer[length++] = '\n' ;
        buffer[length] = 0 ;
        return true ;
    }

private:
    size_t max_size ;
    char *buffer ;
    size_t length ;
} ;

void
num_4_37 () {
    SimpleString5 a{ 50 } ;
    a.append_line("We apologize for the") ;
    SimpleString5 b{ 50 } ;
    b.append_line("Last message") ;
    a.print("a") ;
    b.print("b") ;
    b = std::move(a) ;
    b.print("b") ;
}

// num_4_38
struct SimpleString6 {
    SimpleString6(size_t max_size) : max_size{ max_size }, length{} {
        if (max_size == 0) {
            throw std::runtime_error{ "Max size must be at least 1." } ;
        }
        buffer = new char[max_size] ;
        buffer[0] = 0 ;
    }
    ~SimpleString6() {
        delete[] buffer ;
    }
    SimpleString6(const SimpleString6& other) : max_size{ other.max_size }, buffer{ new char[other.max_size] }, length{ other.length} {
        std::strncpy(buffer, other.buffer, max_size) ;
    }
    SimpleString6(SimpleString6&& other) noexcept : max_size{ other.max_size }, buffer{ other.buffer }, length{ other.length } {
        other.length = 0 ;
        other.buffer = nullptr ;
        other.max_size = 0 ;
    }
    SimpleString6& operator = (const SimpleString6& other) {
        if (this == &other)
            return *this ;
        const auto new_buffer = new char[other.max_size] ;
        delete[] buffer ;
        buffer = new_buffer ;
        length = other.length ;
        max_size = other.max_size ;
        std::strncpy(buffer, other.buffer, max_size) ;
        return *this ;
    }
    SimpleString6& operator = (SimpleString6&& other) noexcept {
        if (this == &other)
            return *this ;
        delete[] buffer ; // 문제: 이거 지우기 
        buffer = other.buffer ;
        length = other.length ;
        max_size = other.max_size ;
        other.buffer = nullptr ;
        other.length = 0 ;
        other.max_size = 0 ;
        return *this ;
    }

    void
    print (const char* tag) const {
        printf("%s: %s", tag, buffer) ;
    }

    bool
    append_line (const char* x) {
        const auto x_len = strlen(x) ;
        if (x_len + length + 2 > max_size)
            return false ;
        std::strncpy(buffer + length, x, max_size - length) ;
        length += x_len ;
        buffer[length++] = '\n' ;
        buffer[length] = 0 ;
        return true ;
    }

private:
    size_t max_size ;
    char *buffer ;
    size_t length ;
} ;

int
main () {
    
    num_4_37() ;

}