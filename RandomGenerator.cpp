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

#include "RandomGenerator.h"

CRandomGenerator::CRandomGenerator(void)
{
}

CRandomGenerator::~CRandomGenerator(void)
{
}

// Функция проверки, сбылся ли определенный шанс, или нет
// Шанс поступает в процентах, генерится число от 0 до 100,
// если оно меньше чем поступившее - значит сбылся
bool CRandomGenerator::CheckChance( float fChance )
{
    return ( qrand() % 101 ) <= fChance ? true : false;

    /*
    int nMaxNum;
    if ( RAND_MAX )
	nMaxNum = RAND_MAX;
    else
	nMaxNum = 1;
    return ( qrand() / nMaxNum * 100 <= fChance ) ? true : false;
    */
}

// Функция генерации случайного числа в заданном диапазоне
float CRandomGenerator::GenerateNumber( float fMin, float fMax )
{
    int nMaxNum;
    if ( RAND_MAX )
	nMaxNum = RAND_MAX;
    else
	nMaxNum = 1;

    double dRandNum = double(qrand()) / double (nMaxNum);

    return float( ( dRandNum * ( fMax - fMin )) + ( dRandNum * fMin ) );
}
