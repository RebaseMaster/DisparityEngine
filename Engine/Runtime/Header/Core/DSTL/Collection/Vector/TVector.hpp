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

#include <initializer_list>
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

    // Experimental version
    using iterator       = pointer_t;
    using const_iterator = const_pointer_t;

public:

    explicit /* inline */ TVector() noexcept;
    explicit /* inline */ TVector(size n);
    explicit /* inline */ TVector(size n, const_reference_t val);

    /* inline */ TVector(TVector<value_t> const& other);
    /* inline */ TVector(TVector<value_t>&&      other) noexcept;
    /* inline */ TVector(std::initializer_list<value_t> il);

    /* inline */ ~TVector() noexcept;

    /* inline */ void Clear() noexcept;
    /* inline */ void Reserve(size n);

    /* inline */ void PopBack() noexcept;
    /* inline */ void PushBack(const_reference_t val);
    /* inline */ void PushBack(value_t && val);

    template <class ... Args>
    /* inline */  void EmplaceBack(Args&& ...args);

    /* inline */ reference_t       at(size pos)       noexcept;
    /* inline */ const_reference_t at(size pos) const noexcept;
    /* inline */ reference_t       operator[](size pos)       noexcept;
    /* inline */ const_reference_t operator[](size pos) const noexcept;

    /* inline */ reference_t       Back()        noexcept;
    /* inline */ const_reference_t Back()  const noexcept;
    /* inline */ reference_t       Front()       noexcept;
    /* inline */ const_reference_t Front() const noexcept;

    /* inline */ iterator          End()         noexcept;
    /* inline */ const_iterator    End()   const noexcept;
    /* inline */ iterator          Begin()       noexcept;
    /* inline */ const_iterator    Begin() const noexcept;

    /* inline */ size Size()    const noexcept;
    /* inline */ size Capcity() const noexcept;
    /* inline */ bool Empty()   const noexcept;

    /* inline */ pointer_t       Data()       noexcept;
    /* inline */ const_pointer_t Data() const noexcept;

private:

    /* inline */ void Grow();
    /* inline */ void Reallocate();

    /* inline */ template <bool IsPOD> static void FillRange     (const_iterator begin, const_iterator end);
    /* inline */ template <bool IsPOD> static void DeleteRange   (const_iterator begin, const_iterator end);
    /* inline */ template <bool IsPOD> static void DestructRange (const_iterator begin, const_iterator end);
    /* inline */ template <bool IsPOD> static void ConstructRange(const_iterator begin, const_iterator end);

private:

    size        m_size;
    size        m_capacity;
    pointer_t   m_aStorage;
};

} // !Disparity

#include "Core/DSTL/Collection/Vector/TVector.inl"

#endif // !TVECTOR_HPP__