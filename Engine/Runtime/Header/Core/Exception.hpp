//
// Created by maxim on 20/11/2017.
//

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <iostream>
#include <exception>

class Exception : public std::exception
{
public:
    //CTOR
    Exception(std::string const& type, std::string const& function) throw();

    //DTOR
    virtual ~Exception() throw() {};

    //MEMBER FUNC
    virtual char const* what() const throw();
    virtual char const* where() const throw();
    void				showError() const;
private:
    std::string			m_type;
    std::string			m_function;
};

#endif //!EXCEPTION_HPP_
