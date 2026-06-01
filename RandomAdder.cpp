// Copyright (C) 2009 Blade <rygzengrho@yandex.ru>
//
// This file is part of OTUPYACHIVATEL.
//
// OTUPYACHIVATEL is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// OTUPYACHIVATEL is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with OTUPYACHIVATEL.  If not, see <http://www.gnu.org/licenses/>.

#include "RandomAdder.h"

CRandomAdder::CRandomAdder(void)
{
    m_sStrToAdd = "";
    m_fChance = 0;
}

CRandomAdder::~CRandomAdder(void)
{
}

QString CRandomAdder::GetStrToAdd () const
{
    return m_sStrToAdd;
}

float CRandomAdder::GetChance () const
{
    return m_fChance;
}

void CRandomAdder::SetStrToAdd ( const QString sNewStrToAdd )
{
    m_sStrToAdd = sNewStrToAdd;
}
void CRandomAdder::SetChance ( const float fNewChance )
{
    m_fChance = fNewChance;
}
