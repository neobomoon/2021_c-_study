#include <cstdio>

void
num_3_1 () {
    int gettysburg{} ; // uniform 초기화. 0으로 초기화 된다. 형변환이 안 된다. 문제: int gettysburg(4.5) ;
    printf("gettysburg: %d\n", gettysburg) ;

    int *gettysburg_address = &gettysburg ;
    printf("&gettysburg: %p\n", gettysburg_address) ;
}

void
num_3_2 () {
    int gettysburg{} ;
    int * gettysburg_address = &gettysburg ;
    printf("Value at gettysburg_address: %d\n", *gettysburg_address) ;
    printf("Gettysburg Address: %p\n", gettysburg_address) ;

    *gettysburg_address = 17325 ;

    printf("Value at gettysburg_address: %d\n", *gettysburg_address) ;
    printf("Gettysburg Address: %p\n", gettysburg_address) ;
}

struct ClockOfTheLongNow {
    ClockOfTheLongNow () {
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

void
num_3_3 () {
    ClockOfTheLongNow clock ;
    ClockOfTheLongNow* clock_ptr = &clock ;
    clock_ptr->set_year(2020) ;
    printf("Address of clock: %p\n", clock_ptr) ;
    printf("Value of clock's year: %d\n", clock_ptr->get_year()) ;
}

struct College {
    char name[256] ;
} ;

void print_name (College * collge_ptr) {
    printf("%s College\n", collge_ptr->name) ;
}

void
num_3_4 () {
    College best_colleges[] = { "Magdalen", "Nuffield", "Kellogg" } ;
    print_name(best_colleges) ;
}

void print_names (College * colleges, size_t n_colleges) {
    for (size_t i = 0 ; i < n_colleges ; i++) {
        printf("%s College\n", colleges[i].name) ;
    }
}

void
num_3_5 () {
    College oxford[] = { "Magdalen", "Nuffield", "Kellogg" } ;
    print_names(oxford, sizeof(oxford) / sizeof(College)) ;
}

void
num_3_6 () {
    char lower[] = "abc?e" ;
    char upper[] = "ABC?e" ;
    char * upper_ptr = upper ;

    lower[3] = 'd' ;
    upper_ptr[3] = 'D' ;

    char letter_d = lower[3] ;
    char letter_D = upper_ptr[3] ;

    printf("lower: %s\nupper: %s\n", lower, upper) ;

    lower[7] = 'g' ; // bad things
}

void
num_3_7 () {
    char lower[] = "abc?e" ;
    char upper[] = "ABC?E" ;
    char *upper_ptr = &upper[0] ;

    *(lower + 3) = 'd' ;
    *(upper_ptr + 3) = 'D' ;

    char letter_d = *(lower + 3) ;
    char letter_D = *(upper_ptr + 3) ;

    printf("lower: %s\nupper: %s\n", lower, upper) ;
}

void
add_year (ClockOfTheLongNow& clock) {
    clock.set_year(clock.get_year() + 1) ;
}

void
num_3_8 () {
    ClockOfTheLongNow clock ;
    printf("The year is %d.\n", clock.get_year()) ;
    add_year(clock) ;
    printf("The year is %d.\n", clock.get_year()) ;
}

// 문제
// void
// add_year (ClockOfTheLongNow* clock) {
//     clock->set_year(clock->get_year() + 1) ;
// }

// void
// num_3_8 () {
//     ClockOfTheLongNow clock ;
//     printf("The year is %d.\n", clock->get_year()) ;
//     add_year(clock) ;
//     printf("The year is %d.\n", clock->get_year()) ;
// } // 바르게 고치세요 

// num_3_9
struct Element1 {
    Element1* next {} ;
    void insert_after(Element1 * new_element) {
        new_element->next = next ;
        next = new_element ;
    }
    char prefix[2] ;
    short operating_number ;
} ;

void
num_3_10 () {
    Element1 trooper1, trooper2, trooper3 ;
    trooper1.prefix[0] = 'T' ;
    trooper1.prefix[1] = 'K' ;
    trooper1.operating_number = 421 ;

    trooper1.insert_after(&trooper2) ;
    trooper2.prefix[0] = 'F' ;
    trooper2.prefix[1] = 'N' ;
    trooper2.operating_number = 2187 ;

    trooper2.insert_after(&trooper3) ;
    trooper3.prefix[0] = 'L' ;
    trooper3.prefix[1] = 'S' ;
    trooper3.operating_number = 005 ;

    for (Element1* cursor = &trooper1 ; cursor ; cursor = cursor->next) {
        printf("stormtrooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number) ;
    }
}

void
num_3_11 () {
    int original = 100 ;
    int &original_ref = original ;
    printf("Original:   %d\n", original) ;
    printf("Reference:  %d\n", original_ref) ;
    
    int new_value = 200 ;
    original_ref = new_value ;

    printf("Origianl:   %d\n", original) ;
    printf("New Value:  %d\n", new_value) ;
    printf("Reference:  %d\n", original_ref) ;
}

// num_3_12
struct Element2 {
    Element2* next {} ;
    void 
    insert_after (Element2* new_element) {
        new_element->next = this->next ;
        this->next = new_element ;
    }
    char prefix[2] ;
    short operating_number ;
} ;

// num_3_13
struct ClockOfTheLongNow2 {
    ClockOfTheLongNow2 () {
        year = 2019 ;
    }

    void
    add_year () {
        year++ ;
    }

    bool
    set_year (int year) {
        if (year < 2019)
            return false ;
        this->year = year ;
        return true ;
    }

    int get_year () {
        return year ;
    }

private:
    int year ;
} ;

// num_3_14
// void petruchio (const char* shrew) {
//     printf("Fear not, sweet wench, they shall not touch thee, %s.\n", shrew) ;
//     shrew[0] = 'K' ; // 컴파일 에러: argument의 char가 const이기 때문이다
// }

// num_3_15
struct ClockOfTheLongNow3 {
    ClockOfTheLongNow3 () {
        year = 2019 ;
    }

    ClockOfTheLongNow3 (int year_in) {
        year = year_in ;
    }

    void
    add_year () {
        year++ ;
    }

    bool
    set_year (int year) {
        if (year < 2019)
            return false ;
        this->year = year ;
        return true ;
    }

    int get_year () const { // 함수 안에서 다른 함수를 부를 때 'const'만 있는 함수 부를 수 있다. 함수 안에서 미리 선언된 변수는 바꿀 수 없다.
        // int i = 0 ; // 가능 but year = 2020 ; 은 불가능 
        return year ;
    }

private:
    int year ;
} ;

// num_3_16
bool
is_leap_year (const ClockOfTheLongNow3& clock) { // 문제: const 빼면 ? 
    printf("%d\n", clock.get_year()) ;
    if (clock.get_year() % 4 > 0)
        return false ;
    printf("check\n") ;
    if (clock.get_year() % 100 > 0)
        return true ;
    printf("check\n") ;
    if (clock.get_year() % 400 > 0)
        return false ;
    printf("check\n") ;
    return true ;
}

// num_3_17
struct Avout {
    const char* name = "Erasmas" ; // 문제: 구조체 선언할 떄 초기화 안 해주면 에러난다 but Avout a = {1 or 1,} ;으로 초기화 해야함
    ClockOfTheLongNow3 apert ;
} ;

struct Avout2 {
    Avout2 (const char* name, long year_of_apert) 
        : name{ name }, apert{ (int) year_of_apert } {
    }

    void
    announce () const {
        printf("My name is %s and my next apert is %d.\n", name, apert.get_year()) ;
    }

    const char* name ;
    ClockOfTheLongNow3 apert ;
} ;

void num_3_18 () { 
    Avout2 raz { "Erasmas", 3010 } ;
    Avout2 jad { "Jad", 4000 } ;
    raz.announce() ;
    jad.announce() ;
}







int
main () {

    num_3_18() ;

}