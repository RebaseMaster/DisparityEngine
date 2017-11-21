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

/// \file       TPODTrait.hpp
/// \date       21/11/2017
/// \project    Disparity
/// \package    Core/DSTL/Trait/
/// \author     Vincent STEHLY--CALISTO

#ifndef TPOD_TRAIT_HPP__
#define TPOD_TRAIT_HPP__

/// \brief  Encapsulates std::is_pod<T>
/// \tparam Tp The type to check POD compatibility
template <typename Tp>
struct IsPod
{
    static bool value;
};

// Static member initialization of IsPod<Tp>::value
template <typename Tp> bool IsPod<Tp>::value = std::is_pod<Tp>::value;

#endif // !TPOD_TRAIT_HPP__