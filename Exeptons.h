#ifndef TECPROG2_EXEPTONS_H
#define TECPROG2_EXEPTONS_H

class BaseException : public std::exception {
public:
    const char *what() const noexcept override { return message_; }

protected:
    const char *message_;
};

class ErrorBadInput : public BaseException {
public:
    ErrorBadInput() { message_ = "Wrong input"; }
};

class WrongDoubleInput : public BaseException {
public:
    WrongDoubleInput() { message_ = "Double input error!"; }
};

class WrongUnsignedLongLongInput : public BaseException {
public:
    WrongUnsignedLongLongInput() { message_ = "Unsigned long long input error!"; }
};

#endif //TECPROG2_EXEPTONS_H
