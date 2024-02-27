//
// Created by student on 07.06.23.
//

#ifndef OOPPROJECT_LOGICEXCEPTION_H
#define OOPPROJECT_LOGICEXCEPTION_H

#include <string>
#include <stdexcept>

class LogicException : public std::logic_error {
public:
    explicit LogicException(const std::string& what_arg) : std::logic_error(what_arg) {}
};


#endif //OOPPROJECT_LOGICEXCEPTION_H
