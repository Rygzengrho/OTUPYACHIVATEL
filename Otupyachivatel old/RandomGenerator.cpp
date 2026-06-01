// Copyright (C) 2008 Blade <rygzengrho@yandex.ru>
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

#include "StdAfx.h"
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
bool CRandomGenerator::ChanceChecker( FLOAT fChance )
{
	return ( FLOAT( rand() * 100 / RAND_MAX ) < fChance ) ? 1 : 0;

	return 0;
}

// Функция генерации случайного числа в заданном диапазоне
FLOAT CRandomGenerator::RandomGenerator( FLOAT fMin, FLOAT fMax )
{
	return ( fMin + FLOAT( rand() * ( fMax - fMin ) / ( RAND_MAX )) );
}