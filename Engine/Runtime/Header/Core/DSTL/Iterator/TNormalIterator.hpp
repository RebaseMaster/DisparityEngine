/// Copyright (C) 2017-2018
///
/// Owners :
///
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

/// \file       TNormalIterator.hpp
/// \date       22/11/2017
/// \project    Disparity
/// \package    Core/DSTL/Iterator/
/// \author     Vincent STEHLY--CALISTO

#ifndef TNORMAL_ITERATOR_HPP__
#define TNORMAL_ITERATOR_HPP__

#include "Core/DSTL/Trait/TIteratorTrait.hpp"

template<typename Iterator, typename Container>
class TNormalIterator
{
public:

    using trait_t = TIteratorTrait<Iterator>;

    using iterator_t  = Iterator;
    using container_t = Container;

    using typename value_t     = trait_t::value_t;
    using typename pointer_t   = trait_t::pointer_t;
    using typename reference_t = trait_t::reference_t;

public:

    reference_t operator*()  const;
    pointer_t   operator->() const;
    TNormalIterator<Iterator, Container>& operator++();
    TNormalIterator<Iterator, Container>  operator++(int);

    TNormalIterator<Iterator, Container>& operator--();
    TNormalIterator<Iterator, Container>  operator--(int);

    reference_t operator[](const difference_type& __n) const;
    TNormalIterator<Iterator, Container>& operator+=(const difference_type& __n);
    TNormalIterator<Iterator, Container>  operator+ (const difference_type& __n) const;
    TNormalIterator<Iterator, Container>& operator-=(const difference_type& __n);

    TNormalIterator<Iterator, Container> operator-(const difference_type& __n) const;
    const Iterator& base() const;
};

#endif TNORMAL_ITERATOR_HPP__