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

/// \file       TVector.hpp
/// \date       21/11/2017
/// \project    Disparity
/// \package    Core/DSTL/Trait/
/// \author     Vincent STEHLY--CALISTO

#ifndef TPLAIN_OLD_DATA_TRAIT_HPP_
#define TPLAIN_OLD_DATA_TRAIT_HPP_

template<typename _Tp, _Tp __v>
struct integral_constant
{
    static constexpr _Tp                  value = __v;
    typedef _Tp                           value_type;
    typedef integral_constant<_Tp, __v>   type;
    explicit constexpr operator value_type() { return value; }
};

template<typename _Tp, _Tp __v>
constexpr _Tp integral_constant<_Tp, __v>::value;

typedef integral_constant<bool, true>     true_type;
typedef integral_constant<bool, false>    false_type;

template<typename _Tp>
struct is_pod
        : public integral_constant<bool, __is_pod(_Tp)>
{ };

#endif // !TPLAIN_OLD_DATA_TRAIT_HPP_