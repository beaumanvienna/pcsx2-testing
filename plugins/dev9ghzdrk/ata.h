/*  PCSX2 - PS2 Emulator for PCs
 *  Copyright (C) 2002-2014 David Quintana [gigaherz]
 *
 *  PCSX2 is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU Lesser General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  PCSX2 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with PCSX2.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include "DEV9.h"

void ata_init();
void ata_term();

template<int sz>
void ata_write(u32 addr, u32 value);
template<int sz>
u8 ata_read(u32 addr);

EXPORT_C_(void)
ata_readDMA8Mem(u32 *pMem, int size);
EXPORT_C_(void)
ata_writeDMA8Mem(u32 *pMem, int size);
