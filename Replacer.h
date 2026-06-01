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

#pragma once
#include "stdlib.h"
#include <QString>
#include <QVector>
#include "RandomGenerator.h"

struct CReplacerResult
{
public:
    QString	m_sResultStr;
    float	m_fResultChance;

    CReplacerResult();
    CReplacerResult( QString sNewString, float fNewChance );
    ~CReplacerResult();
};

class CReplacer
{
protected:
    QString m_sStrToChange;
    QVector <CReplacerResult> m_Result;

public:
    CReplacer(void);
    ~CReplacer(void);

    QString GetStrToChange () const;
    QString GetResultString ( const unsigned int unIndex ) const;
    float GetResultChance ( const unsigned int unIndex ) const;

    bool SetStrToChange ( const QString sNewStrToChange );
    bool SetResult ( const QString sNewResult, const float fNewChance );

    int Size ();
};
