/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
 * All rights reserved.
 */

/** \file KX_OrientationInterpolator.h
 *  \ingroup ketsji
 */

#ifndef __KX_ORIENTATIONINTERPOLATOR_H__
#define __KX_ORIENTATIONINTERPOLATOR_H__

#include "KX_IInterpolator.h"

class MT_Matrix3x3;
class KX_IScalarInterpolator;

class KX_OrientationInterpolator : public KX_IInterpolator {
public:
	KX_OrientationInterpolator(MT_Matrix3x3& target,
	                           KX_IScalarInterpolator **ipos)
	    : m_target(target)
	{
		m_ipos[0] = ipos[0];
		m_ipos[1] = ipos[1];
		m_ipos[2] = ipos[2];
	}

	virtual void Execute(float currentTime) const;

private:
	MT_Matrix3x3&            m_target;
	KX_IScalarInterpolator *m_ipos[3];


#ifdef WITH_CXX_GUARDEDALLOC
	MEM_CXX_CLASS_ALLOC_FUNCS("GE:KX_OrientationInterpolator")
#endif
};

#endif
