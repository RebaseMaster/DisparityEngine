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
/// \date       20/11/2017
/// \project    Disparity
/// \package    Core/DSTL/Collection/Vector
/// \author     Vincent STEHLY--CALISTO

#ifndef TVECTOR_HPP__
#define TVECTOR_HPP__

#include "Platform/Configuration/Configuration.hh"

/// \namespace Disparity
namespace Disparity
{

/// \class  TVector
/// \brief  Custom dynamic array from the DSTL
/// \tparam Tp The stored object type
template <typename Tp>
class TVector
{
public:

    using value_t           = Tp;
    using pointer_t         = Tp*;
    using reference_t       = Tp&;
    using const_pointer_t   = Tp const*;
    using const_reference_t = Tp const&;

    reference_t       /* INLINE */ operator[](size_t pos);
    const_reference_t /* INLINE */ operator[](size_t pos) const;

private:

    static /* INLINE */ void      CopyRange  (...);
    static /* INLINE */ void      DeleteRange(...);

private:

    size_t      m_size;
    size_t      m_capacity;
    pointer_t   m_aStorage;
};

} // !Disparity

#endif // !TVECTOR_HPP__