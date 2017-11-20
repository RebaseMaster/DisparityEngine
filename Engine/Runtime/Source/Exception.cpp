//
// Created by maxim on 20/11/2017.
//

#include "Core/Exception.hpp"
#include <iostream>

Exception::Exception(std::string const& type, std::string const& function) throw()
{
    m_function = function;
    m_type = type;
}

char const*	Exception::what() const throw()
{
    return (m_type.c_str());
}

char const* Exception::where() const throw()
{
    return (m_function.c_str());
}

void		Exception::showError() const
{
    /*
    std::cout << "\033[1;31mError\033[0m : " << this->what() << std::endl;
    std::cout << "\033[1;32m->\033[0m " << this->where() << std::endl;
    */

    std::cout << "Error : " << this->what() << std::endl;
    std::cout << "-> " << this->where() << std::endl;
}