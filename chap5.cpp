#include <cstdio>
#include <stdexcept>

struct ConsoleLogger {
    void
    log_transfer (long from, long to, double amount) {
        printf("%ld -> %ld: %f\n", from, to, amount) ;
    }
} ;

struct Bank {
    void
    make_transfer (long from, long to, double amount) {
        logger.log_transfer(from, to, amount) ;
    }
    ConsoleLogger logger ;
} ;

void
num_5_1 () {
    Bank bank ;
    bank.make_transfer(1000, 2000, 49.95) ;
    bank.make_transfer(2000, 4000, 20.00) ;
}

struct FileLogger {
    void
    log_transfer (long from, long to, double amount) {
        printf("[file] %ld, %ld, %f\n", from, to, amount) ;
    }
} ;

struct ConsoleLogger2 {
    void log_transfer (long from, long to, double amount) {
        printf("[cons] %ld -> %ld: %f\n", from, to, amount) ;
    }
} ;

enum class LoggerType {
    Console,
    File
} ;

struct Bank2 {
    Bank2() : type{ LoggerType::Console } {
    }
    void
    set_logger (LoggerType new_type) {
        type = new_type ;
    }

    void
    make_transfer (long from, long to, double amount) {
        switch (type) {
            case LoggerType::Console: {
                consoleLogger.log_transfer(from, to, amount) ;
                break ;
            }
            case LoggerType::File: {
                fileLogger.log_transfer(from, to, amount) ;
                break ;
            }
            default: {
                throw std::logic_error("Unknown Logger type encountered.") ;
            }
        }
    }
private:
    LoggerType type ;
    ConsoleLogger2 consoleLogger ;
    FileLogger fileLogger ;
} ;

void
num_5_2 () {
    Bank2 bank ;
    bank.make_transfer(1000, 2000, 49.95) ;
    bank.make_transfer(2000, 4000, 20.00) ;
    bank.set_logger(LoggerType::File) ;
    bank.make_transfer(3000, 2000, 75.00) ;
}

// num_5_3
struct Logger {
    virtual ~Logger() = default ;
    virtual void
    log_transfer (long from, long to, double amount) = 0 ;// = 0은 pure virtual method란 뜻
} ;

struct ConsoleLogger3 : Logger {
    void
    log_transfer (long from, long to, double amount) override {
        printf("%ld -> %ld: %f\n", from, to, amount) ;
    }
} ;

struct BaseClass {} ;
struct DerivedClass : BaseClass {} ;
void
are_belong_to_us (BaseClass& base) {}

void
num_5_4 () {
    DerivedClass derived ;
    are_belong_to_us(derived) ;
}

struct BaseClass2 {} ;
struct DerivedClass2 : BaseClass2 {} ;
void
all_about_that (DerivedClass2& derived) {}

void
num_5_5 () {
    BaseClass2 base ;
    // all_about_that(base) ; // 컴파일 에러
}

struct BaseClass3 {
    int the_answer() const {
        return 42 ;
    }

    const char* member = "gold" ;

private:
    const char* holistic_detective = "Dirk Gently" ;
} ;

struct DerivedClass3 : BaseClass3 {} ;

void
num_5_6 () {
    DerivedClass3 x ;
    printf("The answer is %d\n", x.the_answer()) ;
    printf("%s member\n", x.member) ;

}

struct BaseClass4 {
    virtual const char* final_message () const {
        return "We apologize for the incontinence." ;
    }
} ;

struct DerivedClass4 : BaseClass4 {
    const char* final_message() const override {
        return "We apologize for the inconvenience." ;
    }
} ;

void
num_5_7 () {
    BaseClass4 base ;
    DerivedClass4 derived ;
    BaseClass4& ref = derived ;
    printf("BaseClass:      %s\n", base.final_message()) ;
    printf("DerivedClass:   %s\n", derived.final_message()) ;
    printf("BaseClass&:     %s\n", ref.final_message()) ;
}

struct BaseClass5 {
    virtual const char* 
    final_message() const = 0 ; // pure virtual method가 하나라도 있으면 이 클래스는 abstract class가 된다. 문제 내기
} ;

struct DerivedClass5 : BaseClass5 {
    const char* 
    final_message() const override {
        return "We apologize for the inconvenience." ;
    }
} ;

void
num_5_8 () {
    // BaseClass5 base ; // BaseClass5는 abstract class이기 때문에 선언하면 컴파일 에러가 난다.
    DerivedClass5 derived ;
    BaseClass5& ref = derived ;
    printf("DerivedClass:  %s\n", derived.final_message()) ;
    printf("BaseClass:     %s\n", ref.final_message()) ;
}

struct BaseClass6 {} ;

struct DerivedClass6 : BaseClass6 {
    DerivedClass6 () {
        printf("DerivedClass() invoked.\n") ;
    }
    ~DerivedClass6() {
        printf("~DerivedClass() invoked.\n") ; // 이건 출력이 안 된다. why? BaseClass6에서 virtual이 아니기 때문에
    }
} ;

void
num_5_9 () {
    printf("Constructing DerivedClass x.\n") ;
    BaseClass6* x{ new DerivedClass6{} } ;
    printf("Deleting x as a BaseClass*.\n") ;
    delete x ;
}

struct BaseClass7 {
    virtual ~BaseClass7() = default ;
} ;

struct DerivedClass7 : BaseClass7 {
    DerivedClass7 () {
        printf("DerivedClass() invoked.\n") ;
    }
    ~DerivedClass7 () {
        printf("~DerivedClass() invoked.\n") ;
    }
} ;

void
num_5_10 () {
    printf("Constructing DerivedClass x.\n") ;
    BaseClass7* x{ new DerivedClass7() } ;
    printf("Deleting x as a BaseClass*.\n") ;
    delete x ;
}

// num_5_11
struct Logger4 {
    virtual ~Logger4() = default ;
    virtual void
    log_transfer (long from, long to, double amount) = 0 ; // pure virtual -> abstract class가 된다.
} ;

struct ConsoleLogger4 : Logger4 {
    void
    log_transfer(long from, long to, double amount) override {
        printf("[cons] %ld -> %ld: %f\n", from, to, amount) ;
    }
} ;

struct FileLogger4 : Logger4 {
    void
    log_transfer (long from, long to, double amount) override {
        printf("[file] %ld, %ld, %f\n", from, to, amount) ;
    }
} ;

struct Bank4 {
    Bank4 (Logger4& logger) : logger{ logger } {
    }
    void
    make_transfer (long from, long to, double amount) {
        logger.log_transfer(from, to, amount) ;
    }
private:
    Logger4& logger ;
} ;

void
num_5_12 () {
    ConsoleLogger4 logger ;
    Bank4 bank{ logger } ;
    bank.make_transfer(1000, 2000, 49.95) ;
    bank.make_transfer(2000, 4000, 20.00) ;
}


struct Bank5 {
    void
    set_logger (Logger4* new_logger) {
        logger = new_logger ;
    }
    void
    make_transfer (long from, long to, double amount) {
        if (logger)
            logger->log_transfer(from, to, amount) ;
    }
private:
    Logger4* logger{} ; // 0으로 초기화
} ;

void
num_5_13 () {
    ConsoleLogger4 console_logger ;
    FileLogger4 file_logger ;
    Bank5 bank ;
    bank.set_logger(&console_logger) ;
    bank.make_transfer(1000, 2000, 49.95) ;
    bank.set_logger(&file_logger) ;
    bank.make_transfer(2000, 4000, 20.00) ;
}

struct Bank6 {
    Bank6 (Logger4* logger) : logger{ logger } {
    }

    void
    set_logger (Logger4* new_logger) {
        logger = new_logger ;
    }
    
    void
    make_transfer (long from, long to, double amount) {
        if (logger)
            logger->log_transfer(from, to, amount) ;
    }
private:
    Logger4* logger ;
} ;


int
main () {
    
    num_5_13() ;

}