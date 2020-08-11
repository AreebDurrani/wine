/*
 *     Copyright 2002 Marcus Meissner
 *     Copyright 2004 Mike Hearn, for CodeWeavers
 *     Copyright 2004 Rob Shearman, for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#define COBJMACROS
#include "objbase.h"

/***********************************************************************
 *            CoMarshalHresult        (combase.@)
 */
HRESULT WINAPI CoMarshalHresult(IStream *stream, HRESULT hresult)
{
    return IStream_Write(stream, &hresult, sizeof(hresult), NULL);
}

/***********************************************************************
 *            CoUnmarshalHresult      (combase.@)
 */
HRESULT WINAPI CoUnmarshalHresult(IStream *stream, HRESULT *phresult)
{
    return IStream_Read(stream, phresult, sizeof(*phresult), NULL);
}