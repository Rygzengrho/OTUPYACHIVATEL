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
#include <QVector>
#include <QRegExp>
#include <QDebug>
#include "Replacer.h"
#include "RandomAdder.h"
#include "Tags.h"

class CConfig
{
private:
    QVector <CReplacer>	    m_Replacer;
    QVector <CRandomAdder>  m_RandomAdder;
    QVector <CTagsVector>   m_TagsVec;
    CTags		    m_Style;

    // Config variables
    float m_fCapitalizationChance;
    float m_f3AdditionsChance;
    float m_f2AdditionsChance;
    float m_f1AdditionChance;
    float m_fNumToRep;
    QString m_sNumRepString;
    float m_fNumRepChance;
    ulong m_ulMinLengthForAddition;

    // Charsets
    QString m_sComment;
    QString m_sBlockCommentSymbol;
    QString m_sEndSymbol;
    QString m_sSpaces;
    QString m_sEquals;
    QString m_sStringID;
    QString m_sMacroID;
    QString m_sStyleID;
    QString m_sChanceSeparator;
    QString m_sResultsSeparator;
    QString m_sNumber;
    QString m_sDecimalPoint;
    QString m_sEngAlphabetLower;
    QString m_sEngAlphabetUpper;
    QString m_sRusAlphabetLower;
    QString m_sRusAlphabetUpper;
    QString m_sDash;
    QString m_sRandAddID;
    QString m_sTagID;
    QString m_sSeparatorsNotForChange;
    QString m_sSeparatorsChangeable;

    // Tags
    QString m_sUpMacro;
    QString m_sSaveMacro;

    QString ParseString( QString* sString, const QString sWhereToStop, bool* ok ) const;
    QString ParseStringDelim( QString* String, const QString sDelimiters, bool* ok ) const;
    uint ParseUInt( QString* String, bool* ok ) const;
    float ParseFloat( QString* String, bool* ok ) const;

    bool CheckAndChangeSubstring ( QString* sStrToCheck );
    bool AttemptToChangeString ( QString* String, int nIndex );

    uint GenerateAdditionsAmount () const;

public:
    CConfig(void);
    ~CConfig(void);

    void ResetStrings ();
    bool ParseConfig ( QString* sConfig );
    void Clear ();

    static void MakeLowerRus ( QString* sString );
    static void MakeUpperRus ( QString* sString );

    QVector <QString> OtupyachitText ( QString sText );
    long GenerateAdditionsText ( QString* sSubstring, uint unAmount );
    QVector <QString> GenerateAdditionsVector ( const ulong dwZlogenAmount );
    QVector <QString> AddTags( QVector <QString>* svVector, const uint unTagsGroup = 0 );
    QVector <QString>* AddStyle ( QVector <QString>* svVector );

    void TestRegExp ( QString* sString );

    static QString VectorToString ( QVector <QString>* svVector );

    int GetTagsVectorSize () const;
};
