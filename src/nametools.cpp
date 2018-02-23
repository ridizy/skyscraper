/***************************************************************************
 *            nametools.cpp
 *
 *  Tue Feb 20 12:00:00 CEST 2018
 *  Copyright 2018 Lars Muldjord
 *  muldjordlars@gmail.com
 ****************************************************************************/
/*
 *  This file is part of skyscraper.
 *
 *  skyscraper is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  skyscraper is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with skyscraper; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 */

#include <QFileInfo>
#include <QDir>
#include <QSettings>

#include "nametools.h"

QString NameTools::getMameName(const QString &baseName, const QMap<QString, QString> &mameMap)
{
  if(!mameMap[baseName].isEmpty()) {
    return mameMap[baseName];
  }
  return baseName;
}

QString NameTools::getScummName(const QString &baseName)
{
  // Set to global for RetroPie
  QString scummIniStr = "/opt/retropie/configs/scummvm/scummvm.ini";

  // If local exists, use that one instead
  if(QFileInfo::exists(QDir::homePath() + "/.scummvmrc")) {
    scummIniStr = QDir::homePath() + "/.scummvmrc";
  }

  QSettings scummIni(scummIniStr, QSettings::IniFormat);
  if(scummIni.contains(baseName + "/description")) {
    return scummIni.value(baseName + "/description").toString();
  }
  return baseName;
}