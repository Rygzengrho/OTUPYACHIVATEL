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

// Класс, отвечающий за представление тегов.
class CTags
{
    QString	m_sOpenTag;
    float	m_fOpenTagChance;
    QString	m_sCloseTag;
    float	m_fCloseTagChance;
    // Флаг того, что тэг уже был открыт
    bool	m_bOpen;

public:
    CTags(void);
    ~CTags(void);

    QString GetOpenTag () const;
    float GetOpenTagChance () const;
    QString GetCloseTag () const;
    float GetCloseTagChance () const;
    bool IsOpened () const;

    void SetOpenTag ( const QString sNewOpenTag );
    void SetOpenTagChance ( const float fNewOpenTagChance );
    void SetCloseTag ( const QString sNewCloseTag );
    void SetCloseTagChance ( const float fNewCloseTagChance );
    void SetStatus ( const bool bOpen );

    void Clear ();
};

// Класс, отвечающий за вектор из тегов
class CTagsVector
{
public:
    CTagsVector(void);
    CTagsVector( CTags* Tag );
    ~CTagsVector(void);

    QVector <CTags> m_TagsVector;
};
