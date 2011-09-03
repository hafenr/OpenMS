// -*- mode: C++; tab-width: 2; -*-
// vi: set ts=2:
//
// --------------------------------------------------------------------------
//                   OpenMS Mass Spectrometry Framework
// --------------------------------------------------------------------------
//  Copyright (C) 2003-2011 -- Oliver Kohlbacher, Knut Reinert
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// --------------------------------------------------------------------------
// $Maintainer: Stephan Aiche $
// $Authors: Anton Pervukhin <Anton.Pervukhin@CeBiTec.Uni-Bielefeld.DE> $
// --------------------------------------------------------------------------
//

#ifndef OPENMS_CHEMISTRY_MASSDECOMPOSITION_IMS_UNKNOWNCHARACTEREXCEPTION_H
#define OPENMS_CHEMISTRY_MASSDECOMPOSITION_IMS_UNKNOWNCHARACTEREXCEPTION_H

#include <OpenMS/CHEMISTRY/MASSDECOMPOSITION/IMS/Exception.h>

namespace OpenMS {

namespace ims {

/** 
 * An exception thrown if a character is unknown. Note that the word "character" 
 * is used in an abstract sense, meaning "element of an alphabet".
 */
class UnknownCharacterException : public OpenMS::ims::Exception {
public:
  explicit UnknownCharacterException() : Exception() { }
  explicit UnknownCharacterException(const std::string& msg) : Exception(msg) { }
};

} // namespace ims
} // namespace OpenMS

#endif // OPENMS_CHEMISTRY_MASSDECOMPOSITION_IMS_UNKNOWNCHARACTEREXCEPTION_H