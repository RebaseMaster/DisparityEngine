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

/// \file       UnitTestTPlainOldDataTrait.hpp
/// \date       21/11/2017
/// \project    Disparity
/// \author     Vincent STEHLY--CALISTO

#include "gtest/gtest.h"
#include "Core/DSTL/Trait/TPODTrait.hpp"
#include "Platform/Configuration/Type.hh"

/// \brief  Tests if IsPod<Type>::value is true for trivial literals
TEST(PODUnitTest, LiteralsPODTest)
{
    EXPECT_TRUE(IsPod<uint8> ::value);
    EXPECT_TRUE(IsPod<uint16>::value);
    EXPECT_TRUE(IsPod<uint32>::value);
    EXPECT_TRUE(IsPod<uint64>::value);

    EXPECT_TRUE(IsPod<int8> ::value);
    EXPECT_TRUE(IsPod<int16>::value);
    EXPECT_TRUE(IsPod<int32>::value);
    EXPECT_TRUE(IsPod<int64>::value);
}

/// \brief  Tests if IsPod<Type>::value is true for trivial literal pointers
TEST(PODUnitTest, LiteralPointersPODTest)
{
    EXPECT_TRUE(IsPod<uint8  *>::value);
    EXPECT_TRUE(IsPod<uint16 *>::value);
    EXPECT_TRUE(IsPod<uint32 *>::value);
    EXPECT_TRUE(IsPod<uint64 *>::value);

    EXPECT_TRUE(IsPod<int8  *>::value);
    EXPECT_TRUE(IsPod<int16 *>::value);
    EXPECT_TRUE(IsPod<int32 *>::value);
    EXPECT_TRUE(IsPod<int64 *>::value);
}

// Test classes
class PODClass   { /* None */ };
class SPODClass  { uint8 x; uint8 y; };
class NPODClass  { uint8 x; NPODClass() { x = 42; } };
class HPODClass  : public SPODClass     { /* None */ };
class HNPODClass : public NPODClass     { /* None */ };

/// \brief  Test if IsPod<Type>::value is true or false depending the object
TEST(PODUnitTest, ObjectPODTest)
{
    EXPECT_TRUE(IsPod<PODClass> ::value);
    EXPECT_TRUE(IsPod<SPODClass>::value);
    EXPECT_TRUE(IsPod<HPODClass>::value);

    EXPECT_FALSE(IsPod<NPODClass> ::value);
    EXPECT_FALSE(IsPod<HNPODClass>::value);
}