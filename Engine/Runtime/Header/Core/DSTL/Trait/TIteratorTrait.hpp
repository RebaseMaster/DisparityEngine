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

/// \file       TIteratorTrait.hpp
/// \date       22/11/2017
/// \project    Disparity
/// \package    Core/DSTL/Trait/
/// \author     Vincent STEHLY--CALISTO

#ifndef TITERATOR_TRAIT_HPP__
#define TITERATOR_TRAIT_HPP__

/// \brief  TODO
template<typename Iterator>
struct _TIteratorTrait
{
    using typename value_t     = Iterator::value_t;
    using typename pointer_t   = Iterator::pointer_t;
    using typename reference_t = Iterator::reference_t;
};

/// \brief  TODO
template<typename Iterator>
struct TIteratorTrait : public _TIteratorTrait<Iterator> {};

/// \brief Specialization for pointer types.
template<typename Tp>
struct TIteratorTrait<Tp*>
{
    using value_t     = Tp;
    using pointer_t   = Tp*;
    using reference_t = Tp&;
};

/// \brief Specialization for const pointer types.
template<typename Tp>
struct TIteratorTrait<const Tp*>
{
    using value_t     = Tp;
    using pointer_t   = const Tp*;
    using reference_t = const Tp&;
};

#endif // !TITERATOR_TRAIT_HPP__