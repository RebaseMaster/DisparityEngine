/// Copyright (C) 2017-2018
///
/// Owners :
///
/// JORDAN BAS
/// Maxime PERAULT
/// Vincent STEHLY--CALISTO
///
/// This program is free software; you can redistribute it and/or modify
/// it under the terms of the GNU General Public License as published by
/// the Free Software Foundation; either version 2 of the License, or
/// (at your option) any later version.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License along
/// with this program; if not, write to the Free Software Foundation, Inc.,
/// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

/// \file       TArrayIterator.hpp
/// \date       23/11/2017
/// \project    Disparity
/// \package    Core/DSTL/Iterator/
/// \author     Vincent STEHLY--CALISTO

#ifndef TARRAY_ITERATOR_HPP__
#define TARRAY_ITERATOR_HPP__

#include <vector>
#include <Runtime/Header/Platform/Configuration/Type.hh>
#include "Core/DSTL/Trait/TIteratorTrait.hpp"

template<typename Iterator, typename Container>
class TArrayIterator
{
public:

    using trait_t = TIteratorTrait<Iterator>;

    using iterator_t  = Iterator;
    using container_t = Container;

    using typename value_t     = trait_t::value_t;
    using typename pointer_t   = trait_t::pointer_t;
    using typename reference_t = trait_t::reference_t;

public:

    /* inline */ constexpr TArrayIterator()                            noexcept;
    /* inline */ explicit  TArrayIterator(TArrayIterator const& other) noexcept;

    // Forward iterator requirements
    reference_t operator *() noexcept;
    pointer_t   operator->() noexcept;

    TArrayIterator& operator++()    noexcept;
    TArrayIterator  operator++(int) noexcept;

    // Bidirectional iterator requirements
    TArrayIterator& operator--()    noexcept;
    TArrayIterator  operator--(int) noexcept;

    // Random access iterator requirements
    reference_t     operator[](size __n) const noexcept;
    TArrayIterator& operator+=(size __n)       noexcept;
    TArrayIterator  operator+ (size __n) const noexcept;
    TArrayIterator& operator-=(size __n)       noexcept;
    TArrayIterator  operator- (size __n) const noexcept;

    const _Iterator&
    base() const _GLIBCXX_NOEXCEPT
    { return _M_current; }
};

#endif // !TARRAY_ITERATOR_HPP__
