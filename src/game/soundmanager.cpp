/*	
	This file is part of Ingnomia https://github.com/rschurade/Ingnomia
    Copyright (C) 2017-2020  Ralph Schurade, Ingnomia Team

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "soundmanager.h"

#include "game.h"

#include "../gui/eventconnector.h"

#include "../base/gamestate.h"
#include "../base/position.h"
#include "../base/db.h"
#include "../base/config.h"



#include <QDebug>
#include <QJsonDocument>

SoundManager::SoundManager( Game* parent ) :
	g( parent ),
	QObject( parent )
{
	
}

SoundManager::~SoundManager()
{
}

void SoundManager::onTick( quint64 tick )
{
	
}

void SoundManager::playEffect( QString type, Position& pos, QString material)
{
	playEffect(type, pos, material, 0);
}

void SoundManager::playEffect( QString type, Position& pos, QString material, int duration)
{

	
	QVariantMap newEffect;
	newEffect.insert( "ID", type );
	newEffect.insert( "x", pos.x );
	newEffect.insert( "y", pos.y );
	newEffect.insert( "z", pos.z );
	newEffect.insert( "Material", material );
	
	emit signalPlayEffect( newEffect );
		

	return;
}
