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

/// \file       Compiler.hh
/// \date       20/11/2017
/// \project    Disparity
/// \package    Platform/Configuration
/// \author     Vincent STEHLY--CALISTO

#ifndef DISPARITY_COMPILER_HH__
#define DISPARITY_COMPILER_HH__

/// \brief  Cross-compiler settings (GCC | MSVC)
#if   defined(DISPARITY_USE_GCC)
#   define INLINE                 inline
#   define RESTRICT             __restrict__
#   define NO_INLINE            __attribute__ ((noinline))
#   define ALIGNMENT(ALIGNMENT) __attribute__ ((aligned (ALIGNMENT)))
#   define FORCE_INLINE         __attribute__ ((always_inline))

#elif defined(DISPARITY_USE_MSVC)
#   define INLINE                 inline
#   define RESTRICT             __restrict
#   define NO_INLINE            __declspec    (noinline)
#   define ALIGNMENT(ALIGNMENT) __declspec    (align (ALIGNMENT))
#   define FORCE_INLINE         __forceinline

#else
// None

#endif

#endif // !DISPARITY_COMPILER_HH__
