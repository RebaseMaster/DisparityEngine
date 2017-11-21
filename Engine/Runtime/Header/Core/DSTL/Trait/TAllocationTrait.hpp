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

/// \file       TAllocationTrait.hpp
/// \date       21/11/2017
/// \project    Disparity
/// \package    Core/DSTL/Utility/
/// \author     Vincent STEHLY--CALISTO

#ifndef TALLOCATION_TRAIT_HPP__
#define TALLOCATION_TRAIT_HPP__

/// \struct TypeTrait
/// \tparam T The type
template <typename T>
struct TypeTrait
{
    /// \brief  Constructs an object in the given memory block
    /// \param  pBlock The location where to construct the object
    /// \param  object The reference object to copy
    static constexpr /* inline */ void Construct(void * pBlock, const T & object)
    { new(pBlock) T(object); }

    /// \brief  Constructs an object in the given memory block, calls move constructor
    /// \param  pBlock The location where to construct the object
    /// \param  object The reference object to move
    static constexpr /* inline */ void Construct(void * pBlock, T && object)
    { new(pBlock) T(static_cast<T&&>(object)); }

    /// \brief  Destroys the given object
    /// \param  object The reference object to copy
    static constexpr /* inline */ void Destroy(T & object)
    { object.~T(); }
};

/// \struct TypeTrait
/// \brief  Partial specialization for pointer types
/// \tparam T * A pointer on a type
template <typename T>
struct TypeTrait <T*>
{
    /// \brief  Copies pointer into the given memory block
    /// \param  pBlock The location where to copy the pointer
    /// \param  object The pointer to copy
    static constexpr /* inline */ void Construct(void * pBlock, T * object)
    { new (pBlock) T*(object); }

    /// \brief  Does nothing
    /// \param  object The pointer to destroy
    static constexpr /* inline */ void Destroy(T * object)
    { /* None */ }
};

#endif // !TALLOCATION_TRAIT_HPP__