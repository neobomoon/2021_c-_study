# 2021.07.27 화요일
1. (chap 02) 오늘은 c++ Crash Course책의 예제코드를 직접 작성하고 돌려보면서 c++ 언어를 기초부터 공부하는 시간을 가졌다. 공부를 하면서 user-defined type인 union에 대해 알게 되었다.  
   union type은 union으로 선언된 것 안에서 제일 큰 type의 크기를 메모리에 할당한다. 따라서 사용할 땐 하나의 멤버만 사용하도록 해야 한다.

```
union Variant {
    char string[100] ;
    int integer ;
    double floating_point ;
} ;
```

또한 private과 public에 대해 알게 되었다. 만약 class로 선언하게 된다면 default값으로 변수들이 private으로 되어 public을 따로 설정해주면 되고, struct에서는 따로 private을 설정해줘야 data를 숨길 수 있다.

```
class ClockOfTheLongNow {
    int year ; // private
public:
    void
    add_year () {
      -- snip --
    }
} ;
```

또한 struct를 사용할 떈 constructor을 사용하면 구조체 안의 변수들을 초기화 할 수 있다. 하지만 이때 초기화 함수를 소괄호()를 이용하여 호출하면 함수로 인식할 수 있기 떄문에 중괄호{}를 사용해야 한다.

```
struct Taxonomist {
    Taxonomist () {
        printf("(no argument)\n) ;
    }
    Taxonomist (char x) {
          printf("char: %c\n", x) ;
    }
} ;

int
main () {
    Taxonomist t1{} ;
    Taxonomist t2() ; // 안 된다.
}
```

# 2021.07.28 수요일
1. (chap 03) chap3에서는 c++의 reference에 관한 내용을 살펴봤다. reference는 ampersand(&)와 함께 쓰인다.

```
struct ClockOfTheLongNow {
    --snip--
} ;

void
add_year (ClockOfTheLongNow& clock) {
    clock.set_year(clock.get_year() + 1) ;
}

int
main () {
    ClockOfTheLongNow clock ;
    printf("The year is %d.\n", clock.get_year()) ;
    add_year(clock) ;
    printf("The year is %d.\n", clock.get_year()) ;
}
/*
output
The year is 2019 ;
The year is 2020 ;
*/
```

const는 위치에 따라 사용되는 방법이 달리진다.

```
const char* a = "abc" ;   // char가 const이므로 abc에서 다른 값으로 변경을 못 한다.
char const * b = "def" ;  // char가 const이므로 def에서 다른 값으로 변경을 못 한다.
char* const c = b;        // char*가 const이므로 다른 주소 값으로 변경을 못 한다.
```

또한 auto type은 할당되는 값에 따라 저절로 type을 정해준다.

```
auto year{ 2019 } ;             // int
auto& year_ref = year ;         // int&
const auto& year_cref = year ;  // const int&
auto* year_ptr = &year ;        // int*
const auto* year_cptr = &year ; // const int*
```

2. (chap 04) chap 04에선 평소에 잘 몰랐던 내용들이 많이 나와서 한번 더 복습을 해야겠다고 생각을 했다. 먼저 destruction은 construction과 반대되는 것으로 구조체가 사라질 때 자동으로 실행되는 함수이다.

```
struct Tracer {
    Tracer (const char* name) : name{ name } { // construction
        printf("%s constructed.\n", name) ;
    }
    ~Tracer () { // destruction
        printf("%s destructed.\n", name) ;
    }
private:
    const char* const name ;
} ;

child class는 parent class에서 private이 아닌 것만 상속 받는다.
struct Superclass {
    int x ;
} ;

struct Subclass : Superclass {
    int y ;
    int foo () {
        return x + y ;
    }
} ;
```

r-value : right value를 의미하며 변수를 선언할 때 오른쪽에 오는 unnamed인 값을 의미한다. 함수에서 argument로 쓸 때 &&로 받아야 한다.  
l-value : left value를 의미하며 왼쪽에 선언할 때 왼쪽에 있는 named인 값을 의미한다. 함수에서 argument로 쓸 때 &로 받아야 한다.

```
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
/*
output
lvalue reference 1
rvalue reference 2
rvalue reference 3
*/
```

# 2021.07.29 목요일
1. (chap 05) 오늘은 virtual을 이용해서 클래스의 함수를 상속받는 것을 알게 되었다. virtual function을 사용하기 위해선 함수가 public부분에 선언되어 있어야 한다. 또한 이렇게 선언된 함수를 pure virtual function으로 만들게 되면 그 클래스는 abstract class로 바뀌게 된다. 이러한 것들을 통해 클래스간에 공통된 것을 하나로 묶어둬 child class를 선언할 때 공통된 함수를 빠트리는 경우를 예방할 수 있게 된다.

```
#include <cstdio>

struct BaseClass {
    virtual const char* 
    final_message() const = 0 ; // pure virtual method가 하나라도 있으면 이 클래스는 abstract class가 된다.
} ;

struct DerivedClass : BaseClass {
    const char* 
    final_message() const override {
        return "We apologize for the inconvenience." ;
    }
} ;

void
num_5_8 () {
    // BaseClass base ; // BaseClass는 abstract class이기 때문에 선언하면 컴파일 에러가 난다.
    DerivedClass derived ;
    BaseClass& ref = derived ;
    printf("DerivedClass:  %s\n", derived.final_message()) ;
    printf("BaseClass:     %s\n", ref.final_message()) ;
}
```
또한 default 와 delete내용이 있었지만 아직 완전히 이해하지 못 해서 한번 더 복습하고 TIL에 기록해야겠다 생각했다.

