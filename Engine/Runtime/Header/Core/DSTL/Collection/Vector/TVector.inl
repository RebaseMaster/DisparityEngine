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

#include <memory.h>
#include <cstdlib>
#include "TVector.hpp"

/// \namespace Disparity
namespace Disparity
{

/// \brief  Default constructor
template <typename Tp>
/* explicit */ TVector<Tp>::TVector() noexcept
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
/* explicit */ TVector<Tp>::TVector(size n) : TVector<Tp>::TVector()
{
    // TODO : Collapse code
    Reserve(n);
    ConstructRange(begin(), begin() + n, TPODType<Tp>());
}

/// \brief  Fill constructor
///         Fills the vector with the given value
/// \param  n The number of values to fill the vector
/// \param  val The value to copy
template <typename Tp>
/* explicit */ TVector<Tp>::TVector(size n, const_reference_t val)
: TVector<Tp>::TVector()
{
    // TODO : Collapse code
    Reserve(n);
    ConstructRange(begin(), begin() + n, val, TPODType<Tp>());
}

/// \brief  Copy constructor
/// \param  other The other vector to copy
template <typename Tp>
TVector<Tp>::TVector(TVector<value_t> const& other)
: TVector<Tp>::TVector()
{
    // TODO : Collapse code
    Reserve(other.m_size);
    CopyRange(begin(), end(), other.begin(), TPODType<Tp>());
}

/// \brief  Move constructor
/// \param  other A rvalue on the vector to move
template <typename Tp>
TVector<Tp>::TVector(TVector<value_t>&& other) noexcept
: m_size(other.m_size)
, m_capacity(other.m_capacity)
, m_aStorage(other.m_aStorage)
{
    other.m_size     = 0;
    other.m_capacity = 0;
    other.m_aStorage = nullptr;
}

/// \brief  Initializer
/// \param  il The initializer list to append to the vector
template <typename Tp>
TVector<Tp>::TVector(std::initializer_list<value_t> il)
{
    Reserve(il.size());

    // TODO : Optimize with future iterators
    size nItem = 0;
    for(value_t & val : il)
    {
        new((void *)&m_aStorage[nItem]) Tp(static_cast<value_t&&>(val));
        ++nItem;
    }
}

/// \brief  Destructor
template <typename Tp>
TVector<Tp>::~TVector() noexcept
{
    DestructRange(begin(), end(), TPODType<Tp>());
    delete[] m_aStorage;
}

/// \brief  Removes all elements from the vector
template <typename Tp>
void TVector<Tp>::Clear() noexcept
{
    DestructRange(begin(), end(), TPODType<Tp>());

    // Resets the size to 0
    m_size = 0;
}

/// \brief  Reserves the storage space for n elements
/// \param  n The number of elements to reserve
template <typename Tp>
void TVector<Tp>::Reserve(size n)
{
    if(m_capacity == 0)
    {
        m_capacity = 2;
    }

    // TODO : Search for optimizations
    if(n > m_capacity)
    {
        // Determines the next power of two higher than count
        while(m_capacity < n)
        { m_capacity <<= 1; }

        // Reallocates and copy old values
        Reallocate(/* None */);
    }
}

/// \brief  Removes the last elements of the vector
///         If the container is empty, causes undefined behavior
template <typename Tp>
void TVector<Tp>::PopBack() noexcept
{
    // TODO : Move in allocator, Collapse code
    m_aStorage[m_size - 1].~Tp();
    --m_size;
}

/// \brief  Adds the given element at the end of the vector
/// \param  val A const_reference_t on the element
///             to add at the end of the vector
template <typename Tp>
void TVector<Tp>::PushBack(const_reference_t val)
{
    if(m_size == m_capacity)
    {
        Grow(/* None */);
    }

    // TODO : Move this code in allocator
    new((void *)&m_aStorage[m_size]) Tp(val);
    ++m_size;
}

/// \brief  Adds the given element at the end of the vector
///         by using move semantics / ctor
/// \param  A value_t rvalue on the element to add
template <typename Tp>
void TVector<Tp>::PushBack(value_t && val)
{
    if(m_size == m_capacity)
    {
        Grow(/* None */);
    }

    // TODO : Move this code in allocator
    new((void *)&m_aStorage[m_size]) Tp(static_cast<Tp&&>(val));
    ++m_size;
}

/// \brief  Adds elements at the end of the vector by using move semantics
/// \tparam Args Variadic template parameters
/// \param  args Rvalues elements to add at the end of the vector
template <typename Tp>
template <class ... Args>
void TVector<Tp>::EmplaceBack(Args&& ...args)
{
    // TODO : Later
}

/// \brief  Returns the element at the given position with bounds checking
/// \param  pos The pos of the element to return
/// \return A reference_t on the element
template <typename Tp>
typename TVector<Tp>::reference_t TVector<Tp>::at(size pos) noexcept
{
    // TODO : Assert pos
    return m_aStorage[pos];
}

/// \brief  Returns the element at the given position with bounds checking
/// \param  pos The pos of the element to return
/// \return A const_reference_t on the element
template <typename Tp>
typename TVector<Tp>::const_reference_t TVector<Tp>::at(size pos) const noexcept
{
    // TODO : Assert pos
    return m_aStorage[pos];
}

/// \brief  Returns the element at the given position without bounds checking
/// \param  pos The pos of the element to return
/// \return A reference_t on the element
template <typename Tp>
typename TVector<Tp>::reference_t TVector<Tp>::operator[](size pos) noexcept
{
    return m_aStorage[pos];
}

/// \brief  Returns the element at the given position without bounds checking
/// \param  pos The pos of the element to return
/// \return A const_reference_t on the element
template <typename Tp>
typename TVector<Tp>::const_reference_t TVector<Tp>::operator[](size pos) const noexcept
{
    return m_aStorage[pos];
}

/// \brief  Returns the last element of the vector
///         If the vector is empty, causes an undefined behavior
/// \return A reference_t on the last element of the vector
template <typename Tp>
typename TVector<Tp>::reference_t TVector<Tp>::Back() noexcept
{
    return m_aStorage[m_size - 1];
}

/// \brief  Returns the last element of the vector
///         If the vector is empty, causes an undefined behavior
/// \return A const_reference_t on the last element of the vector
template <typename Tp>
typename TVector<Tp>::const_reference_t TVector<Tp>::Back() const noexcept
{
    return m_aStorage[m_size - 1];
}

/// \brief  Returns the first element of the vector
///         If the vector is empty, causes an undefined behavior
/// \return A reference_t on the first element of the vector
template <typename Tp>
typename TVector<Tp>::reference_t TVector<Tp>::Front() noexcept
{
    return *m_aStorage;
}

/// \brief  Returns the first element of the vector
///         If the vector is empty, causes an undefined behavior
/// \return A const_reference_t on the first element of the vector
template <typename Tp>
typename TVector<Tp>::const_reference_t TVector<Tp>::Front() const noexcept
{
    return *m_aStorage;
}

/// \brief  Returns the end iterator
/// \return The end iterator
template <typename Tp>
typename TVector<Tp>::iterator TVector<Tp>::end() noexcept
{
    return &m_aStorage[m_size];
}

/// \brief  Returns the end iterator
/// \return The end const_iterator
template <typename Tp>
typename TVector<Tp>::const_iterator TVector<Tp>::end() const noexcept
{
    return &m_aStorage[m_size];
}

/// \brief  Returns the begin iterator
/// \return The begin iterator
template <typename Tp>
typename TVector<Tp>::iterator TVector<Tp>::begin() noexcept
{
    return m_aStorage;
}

/// \brief  Returns the begin iterator
/// \return The begin const_iterator
template <typename Tp>
typename TVector<Tp>::const_iterator TVector<Tp>::begin() const noexcept
{
    return m_aStorage;
}

/// \brief  Returns the current size of the vector
/// \return The size of the vector
template <typename Tp>
size TVector<Tp>::Size() const noexcept
{
    return m_size;
}

/// \brief  Returns the current capacity of the vector
/// \return The capacity of the vector
template <typename Tp>
size TVector<Tp>::Capcity() const noexcept
{
    return m_capacity;
}

/// \brief  Tells if the vector is empty or not
/// \return True or false
template <typename Tp>
bool TVector<Tp>::Empty() const noexcept
{
    return (m_size == 0);
}

/// \brief  Returns a pointer on the internal storage of the vector
/// \return A pointer_t on the internal storage
template <typename Tp>
typename TVector<Tp>::pointer_t TVector<Tp>::Data() noexcept
{
    return m_aStorage;
}

/// \brief  Returns a read only pointer on the internal storage of the vector
/// \return A const_pointer_t on the internal storage
template <typename Tp>
typename TVector<Tp>::const_pointer_t TVector<Tp>::Data() const noexcept
{
    return m_aStorage;
}

/// \brief  Increases the capacity of the vector
template <typename Tp>
void TVector<Tp>::Grow()
{
    // TODO : Remove magic constant, Minimize code
    m_capacity = m_capacity ? m_capacity * 2 : 8;
    Reallocate();
}

/// \brief  Increases the storage space and copy all elements in the new
///         buffer
template <typename Tp>
void TVector<Tp>::Reallocate()
{
    Tp * oldStorage = m_aStorage;
    m_aStorage = (Tp *)malloc(m_capacity * sizeof(Tp));

    // Copies the old storage space into the new one
    CopyRange(begin(), end(), oldStorage, TPODType<Tp>());

    free(oldStorage);
}

/// \brief  Copies raw memory from begin to dest
///         This method is optimized for POD structure
/// \param  begin The begin of the range to copy
/// \param  end The end of the range to copy
/// \param  dest The destination buffer
/// \param  tag The object is a POD structure
template <typename Tp>
/* static */ void TVector<Tp>::CopyRange(iterator begin, const_iterator end, iterator dest, PODTag tag)
{
    memcpy((void *)dest, (const void *)begin, (end - begin) * sizeof(Tp));
}

/// \brief  Copies all element in the range into dest
/// \param  begin The begin of the range to copy
/// \param  end The end of the range to copy
/// \param  dest The destination buffer
/// \param  tag The object is not a POD structure
template <typename Tp>
/* static */ void TVector<Tp>::CopyRange(iterator begin, const_iterator end, iterator dest, NonPODTag tag)
{
    // TODO : Minimize / Collapse code
    while(begin != end)
    {
        new((void *)dest) Tp(*begin);
        ++begin;
        ++dest;
    }
}

/// \brief  Does nothing because of POD structure
///         This method is optimized for POD struc
/// \param  begin The begin of the range
/// \param  end The end of the range
/// \param  PODTag The object is a POD structure
template <typename Tp>
/* static */ void TVector<Tp>::DestructRange(iterator begin, const_iterator end, PODTag tag)
{
    // TODO : Minimize / Collapse code
    // None
}

/// \brief  Calls destructor on all the elements in the range
/// \param  begin The begin of the range
/// \param  end The end of the range
/// \param  NonPODTag The object is not a POD structure
template <typename Tp>
/* static */ void TVector<Tp>::DestructRange(iterator begin, const_iterator end, NonPODTag tag)
{
    // TODO : Minimize / Collapse code
    while(begin != end)
    {
        begin->~Tp();
        ++begin;
    }
}

/// \brief  Does nothing because of POD structure
///         This method is optimized for POD structure
/// \param  begin The begin of the range
/// \param  end The end of the range
/// \param  PODTag The object is a POD structure
template <typename Tp>
/* static */ void TVector<Tp>::ConstructRange(iterator begin, const_iterator end, PODTag tag)
{
    // TODO : Minimize / Collapse code
    // None
}

/// \brief  Constructs all objects in the range
/// \param  begin The begin of the range
/// \param  end The end of the range
/// \param  NonPODTag The object is not a POD structure
template <typename Tp>
/* static */ void TVector<Tp>::ConstructRange(iterator begin, const_iterator end, NonPODTag tag)
{
    // TODO : Minimize / Collapse code
    while(begin != end)
    {
        new((void*)begin) Tp; // Avoid zero initialization
        ++begin;
    }
}

/// \brief  Does nothing because of POD structure
///         This method is optimized for POD structure
/// \param  begin The begin of the range
/// \param  end The end of the range
/// \param  PODTag The object is a POD structure
template <typename Tp>
/* static */ void TVector<Tp>::ConstructRange(iterator begin, const_iterator end, const_reference_t val, PODTag tag)
{
    // TODO : Optimize / Minimize / Collapse code
    while(begin != end)
    {
        new((void*)begin) Tp(val); // Avoid zero initialization
        ++begin;
    }
}

/// \brief  Constructs all objects in the range
/// \param  begin The begin of the range
/// \param  end The end of the range
/// \param  NonPODTag The object is not a POD structure
template <typename Tp>
/* static */ void TVector<Tp>::ConstructRange(iterator begin, const_iterator end, const_reference_t val, NonPODTag tag)
{
    // TODO : Minimize / Collapse code
    while(begin != end)
    {
        new((void*)begin) Tp(val); // Avoid zero initialization
        ++begin;
    }
}

/// \brief  Returns an the begin iterator of the given vector
/// \return The begin iterator
template <typename Tp>
typename TVector<Tp>::iterator begin(TVector<Tp>& vector) noexcept
{
    return vector.begin();
}

/// \brief  Returns an the end iterator of the given vector
/// \return The end iterator
template <typename Tp>
typename TVector<Tp>::iterator end(TVector<Tp>& vector) noexcept
{
    return vector.begin();
}

} // !Disparity
