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

/// \file       TVector.inl
/// \date       20/11/2017
/// \project    Disparity
/// \package    Core/DSTL/Collection/Vector
/// \author     Vincent STEHLY--CALISTO

#include "TVector.hpp"

/// \namespace Disparity
namespace Disparity
{

/// \brief  Default constructor
template <typename Tp>
/* explicit */ TVector<Tp>::TVector() /* noexcept */
: m_size(0)
, m_capacity(0)
, m_aStorage(nullptr_t)
{
    // None
}

/// \brief  Fill constructor
///         Fills the vector with n values
/// \param  n The number of values to fill the vector
template <typename Tp>
/* explicit */ TVector<Tp>::TVector(size_t n)
{
    // TODO
}

/// \brief  Fill constructor
///         Fills the vector with the given value
/// \param  n The number of values to fill the vector
/// \param  val The value to copy
template <typename Tp>
/* explicit */ TVector<Tp>::TVector(size_t n, const_reference_t val)
{
    // TODO
}

/// \brief  Copy constructor
/// \param  other The other vector to copy
template <typename Tp>
TVector<Tp>::TVector(TVector<value_t> const& other)
{
    // TODO
}

/// \brief  Move constructor
/// \param  other A rvalue on the vector to move
template <typename Tp>
TVector<Tp>::TVector(TVector<value_t>&& other) /* noexcept */
{
    // TODO
}

/// \brief  Initializer
/// \param  il The initializer list to append to the vector
template <typename Tp>
TVector<Tp>::TVector(std::initializer_list<value_t> il)
{
    // TODO
}

/// \brief  Destructor
template <typename Tp>
TVector<Tp>::~TVector()
{
    // TODO
}

/// \brief  Removes all elements from the vector
template <typename Tp>
void TVector<Tp>::Clear() /* noexcept */
{
    // TODO
}

/// \brief  Reserves the storage space for n elements
/// \param  n The number of elements to reserve
template <typename Tp>
void TVector<Tp>::Reserve(size_t n)
{
    // TODO
}

/// \brief  Removes the last elements of the vector
///         If the container is empty, causes undefined behavior
template <typename Tp>
void TVector<Tp>::PopBack() /* noexcept */
{
    // TODO
}

/// \brief  Adds the given element at the end of the vector
/// \param  val A const_reference_t on the element to add at the end of the vector
template <typename Tp>
void TVector<Tp>::PushBack(const_reference_t val)
{
    // TODO
}

/// \brief  Adds the given element at the end of the vector by using move semantics / ctor
/// \param  A value_t rvalue on the element to add
template <typename Tp>
void TVector<Tp>::PushBack(value_t &&  val)
{
    // TODO
}

/// \brief  Adds elements at the end of the vector by using move semantics
/// \tparam Args Variadic template parameters
/// \param  args Rvalues elements to add at the end of the vector
template <typename Tp>
template <class ... Args>
void TVector<Tp>::EmplaceBack(Args&& ...args)
{
    // TODO
}

/// \brief  Returns the element at the given position with bounds checking
/// \param  pos The pos of the element to return
/// \return A reference_t on the element
template <typename Tp>
TVector<Tp>::reference_t TVector<Tp>::at(size_t pos) /* noexcept */
{
    // TODO
}

/// \brief  Returns the element at the given position with bounds checking
/// \param  pos The pos of the element to return
/// \return A const_reference_t on the element
template <typename Tp>
TVector<Tp>::const_reference_t TVector<Tp>::at(size_t pos) const /* noexcept */
{
    // TODO
}

/// \brief  Returns the element at the given position without bounds checking
/// \param  pos The pos of the element to return
/// \return A reference_t on the element
template <typename Tp>
TVector<Tp>::reference_t TVector<Tp>::operator[](size_t pos) /* noexcept */
{
    // TODO
}

/// \brief  Returns the element at the given position without bounds checking
/// \param  pos The pos of the element to return
/// \return A const_reference_t on the element
template <typename Tp>
TVector<Tp>::const_reference_t TVector<Tp>::operator[](size_t pos) const /* noexcept */
{
    // TODO
}

/// \brief  Returns the last element of the vector
///         If the vector is empty, causes an undefined behavior
/// \return A reference_t on the last element of the vector
template <typename Tp>
TVector<Tp>::reference_t TVector<Tp>::Back()  /* noexcept */
{
    // TODO
}

/// \brief  Returns the last element of the vector
///         If the vector is empty, causes an undefined behavior
/// \return A const_reference_t on the last element of the vector
template <typename Tp>
TVector<Tp>::const_reference_t TVector<Tp>::Back() const /* noexcept */
{
    // TODO
}

/// \brief  Returns the first element of the vector
///         If the vector is empty, causes an undefined behavior
/// \return A reference_t on the first element of the vector
template <typename Tp>
TVector<Tp>::reference_t TVector<Tp>::Front() /* noexcept */
{
    // TODO
}

/// \brief  Returns the first element of the vector
///         If the vector is empty, causes an undefined behavior
/// \return A const_reference_t on the first element of the vector
template <typename Tp>
TVector<Tp>::const_reference_t TVector<Tp>::Front() const /* noexcept */
{
    // TODO
}

/// \brief  Returns the current size of the vector
/// \return The size of the vector
template <typename Tp>
size_t TVector<Tp>::Size()    const /* noexcept */
{
    // TODO
}

/// \brief  Returns the current capacity of the vector
/// \return The capacity of the vector
template <typename Tp>
size_t TVector<Tp>::Capcity() const /* noexcept */
{
    // TODO
}

/// \brief  Tells if the vector is empty or not
/// \return True or false
template <typename Tp>
bool TVector<Tp>::Empty() const /* noexcept */
{
    // TODO
}

/// \brief  Returns a pointer on the internal storage of the vector
/// \return A pointer_t on the internal storage
template <typename Tp>
TVector<Tp>::pointer_t TVector<Tp>::Data() /* noexcept */
{
    // TODO
}

/// \brief  Returns a read only pointer on the internal storage of the vector
/// \return A const_pointer_t on the internal storage
template <typename Tp>
TVector<Tp>::const_pointer_t TVector<Tp>::Data() const /* noexcept */
{
    // TODO
}

} // !Disparity
