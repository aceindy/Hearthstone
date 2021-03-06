/*
 * Aspire Hearthstone
 * Copyright (C) 2008 - 2009 AspireDev <http://www.aspiredev.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "StdAfx.h"
#include <git_revision.h>
#include "ConsoleCommands.h"

bool HandleInfoCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	uint32 clientsNum = (uint32)sWorld.GetSessionCount();

	int gm = 0;
	int count = 0;
	int avg = 0;
	PlayerStorageMap::const_iterator itr;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		if(itr->second->GetSession())
		{
			count++;
			avg += itr->second->GetSession()->GetLatency();
			if(itr->second->GetSession()->GetPermissionCount())
				gm++;
		}			
	}
	objmgr._playerslock.ReleaseReadLock();

	pConsole->Write("======================================================================\r\n");
	pConsole->Write("Server Information: \r\n");
	pConsole->Write("======================================================================\r\n");
	pConsole->Write("Server Revision: Hearthstone %s (%s)/%s-%s-%s\r\n", BUILD_BRANCH, BUILD_REVISION, CONFIG, PLATFORM_TEXT, ARCH);
	pConsole->Write("Server Uptime: %s\r\n", sWorld.GetUptimeString().c_str());
	pConsole->Write("Current Players: %u (%d GMs, %d queued)\r\n", clientsNum, gm,  0);
	pConsole->Write("Alliance Online: %u\r\n",sWorld.AlliancePlayers);
	pConsole->Write("Horde Online: %u\r\n",sWorld.HordePlayers);
	pConsole->Write("Connection Peak: %u\r\n", sWorld.PeakSessionCount);
	pConsole->Write("Accepted Connections: %u\r\n", sWorld.mAcceptedConnections);
	pConsole->Write("Active Thread Count: %u\r\n", ThreadPool.GetActiveThreadCount());
	pConsole->Write("Free Thread Count: %u\r\n", ThreadPool.GetFreeThreadCount());
	pConsole->Write("Average Latency: %.3fms\r\n", count ?  ((float)((float)avg / (float)count)) : 0.0f);
	pConsole->Write("SQL Query Cache Size (World): %u queries delayed\r\n", WorldDatabase.GetQueueSize());
	pConsole->Write("SQL Query Cache Size (Character): %u queries delayed\r\n", CharacterDatabase.GetQueueSize());
	pConsole->Write("======================================================================\r\n\r\n");

	return true;
}

bool HandleGMsCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	WorldPacket data;
	//bool first = true;

	pConsole->Write("There are the following GM's online on this server: \r\n");
	pConsole->Write("======================================================\r\n");
	pConsole->Write("| %21s | %15s | %04s  |\r\n" , "Name", "Permissions", "Latency");
	pConsole->Write("======================================================\r\n");

	PlayerStorageMap::const_iterator itr;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		if(itr->second->GetSession()->GetPermissionCount())
		{
			pConsole->Write("| %21s | %15s | %04u ms |\r\n" , itr->second->GetName(), itr->second->GetSession()->GetPermissions(), itr->second->GetSession()->GetLatency());
		}
	}
	objmgr._playerslock.ReleaseReadLock();

	pConsole->Write("======================================================\r\n\r\n");
	return true;
}


void ConcatArgs(string & outstr, int argc, int startoffset, const char * argv[])
{
	for(int i = startoffset + 1; i < argc; ++i)
	{
		outstr += argv[i];
		if((i+1) != (argc))
			outstr += " ";
	}
}
bool HandleAnnounceCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	char pAnnounce[1024];
	string outstr;
	if(argc < 2)
		return false;

	ConcatArgs(outstr, argc, 0, argv);
	snprintf(pAnnounce, 1024, "%sConsole: |r%s", MSG_COLOR_LIGHTBLUE, outstr.c_str());
	sWorld.SendWorldText(pAnnounce); // send message
	pConsole->Write("Message sent.\r\n");
	return true;
}

bool HandleWAnnounceCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	char pAnnounce[1024];
	string outstr;
	if(argc < 2)
		return false;

	ConcatArgs(outstr, argc, 0, argv);
	snprintf(pAnnounce, 1024, "%sConsole: |r%s", MSG_COLOR_LIGHTBLUE, outstr.c_str());
	sWorld.SendWorldWideScreenText(pAnnounce); // send message
	pConsole->Write("Message sent.\r\n");
	return true;
}

bool HandleKickCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 3)
		return false;

	char pAnnounce[1024];
	PlayerPointer pPlayer;

	pPlayer = objmgr.GetPlayer(argv[1]);
	if( pPlayer == NULL )
	{
		pConsole->Write("Could not find player, %s.\r\n", argv[1]);
		return true;
	}
	string outstr;
	ConcatArgs(outstr, argc, 1, argv);
	snprintf(pAnnounce, 1024, "%sConsole:|r %s was kicked from the server for: %s.", MSG_COLOR_LIGHTBLUE, pPlayer->GetName(), argv[2]);
	pPlayer->BroadcastMessage("You were kicked by the console for: %s", argv[2]);
	sWorld.SendWorldText(pAnnounce, NULL);
	pPlayer->Kick(5000);
	pConsole->Write("Kicked player %s.\r\n", pPlayer->GetName());
	return true;
}

bool HandleQuitCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	uint32 delay = 5;
	if(argc >= 2)
		delay = atoi(argv[1]);

	pConsole->Write("Shutdown initiated.\r\n");
	sWorld.QueueShutdown(delay, SERVER_SHUTDOWN_TYPE_SHUTDOWN);
	return true;
}

bool HandleCancelCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	pConsole->Write("Shutdown canceled.\r\n");
	sWorld.CancelShutdown();
	return true;
}

bool HandleUptimeCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	string up = sWorld.GetUptimeString();
	pConsole->Write("Server Uptime: %s\r\n", up.c_str());
	return true;
}

bool HandleBanAccountCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 4)
		return false;

	int32 timeperiod = GetTimePeriodFromString(argv[2]);
	if(timeperiod < 0)
		return false;

	uint32 banned = (timeperiod ? (uint32)UNIXTIME+timeperiod : 1);

	/// apply instantly in db
	sLogonCommHandler.Account_SetBanned(argv[1], banned, argv[3]);

	pConsole->Write("Account '%s' has been banned %s%s. The change will be effective with the next reload cycle.\r\n", argv[1], 
		timeperiod ? "until " : "forever", timeperiod ? ConvertTimeStampToDataTime(timeperiod+(uint32)UNIXTIME).c_str() : "");
	
	return true;
}

bool HandleUnbanAccountCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 2)
		return false;

	sLogonCommHandler.Account_SetBanned(argv[1], 0, "");

	pConsole->Write("Account '%s' has been unbanned.\r\n", argv[1]);
	return true;
}

bool HandleCreateAccountCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 5)
		return false;

	const char * username = argv[1];
	const char * password = argv[2];
	const char * email = argv[3];

	if(strlen(username) == 0 || strlen(password) == 0 || strlen(email) == 0)
		return false;
	return true;
}

bool HandleMOTDCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 2)
	{
		pConsole->Write( "The current motd is: '%s'.\r\n", sWorld.GetMotd() );
	}else
	{
		char set_motd[1024];
		string outstr;
		ConcatArgs( outstr, argc, 0, argv );
		snprintf( set_motd, 1024, "%s", outstr.c_str() );

		sWorld.SetMotd( set_motd );
		pConsole->Write( "The motd has been set to: '%s'.\r\n", sWorld.GetMotd() );
	}
	return true;
}

bool HandlePlayerInfoCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if(argc < 2)
		return false;

	PlayerPointer plr = objmgr.GetPlayer(argv[1]);
	if( plr == NULL )
	{
		pConsole->Write("Player not found.\r\n");
		return true;
	}

	pConsole->Write("Player: %s\r\n", plr->GetName());
	pConsole->Write("Race: %s\r\n", plr->myRace->name1);
	pConsole->Write("Class: %s\r\n", plr->myClass->name);
	pConsole->Write("IP: %s\r\n", plr->GetSession()->GetSocket() ? plr->GetSession()->GetSocket()->GetRemoteIP().c_str() : "disconnected");
	pConsole->Write("Level: %u\r\n", plr->getLevel());
	pConsole->Write("Account: %s\r\n", plr->GetSession()->GetAccountNameS());
	return true;
}

void TestConsoleLogin(string& username, string& password, uint32 requestno)
{
	sLogonCommHandler.TestConsoleLogon(username, password, requestno);
}

bool HandleRehashCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	pConsole->Write("Config file re-parsed.\n");
	sWorld.Rehash(true);
	return true;
}

bool HandleBPStatsCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	g_bufferPool.Stats();
	return true;
}

bool HandleBackupDBCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	sWorld.BackupDB();
	return true;
}

bool HandleSaveAllCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	PlayerStorageMap::const_iterator itr;
	uint32 stime = now();
	uint32 count = 0;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		if(itr->second->GetSession())
		{
			itr->second->SaveToDB(false);
			count++;
		}
	}
	objmgr._playerslock.ReleaseReadLock();
	char msg[100];
	snprintf(msg, 100, "Saved all %d online players in %d msec.", (int)count, int((uint32)now() - stime));
	sWorld.SendWorldText(msg);
	sWorld.SendWorldWideScreenText(msg);

	return true;
}
bool HandleWhisperCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	char pAnnounce[1024];
	PlayerPointer pPlayer;
	string outstr;

	if(argc < 3)
		return false;

	pPlayer = objmgr.GetPlayer(argv[1]);

	if( pPlayer == NULL )
	{
		pConsole->Write("Could not find player, %s.\r\n", argv[1]);
		return true;
	}

	ConcatArgs(outstr, argc, 1, argv);
	snprintf(pAnnounce, 1024, "%sConsole whisper: |r%s", MSG_COLOR_MAGENTA, outstr.c_str());

	pPlayer->BroadcastMessage(pAnnounce);
	pConsole->Write("Message sent to %s.\r\n", pPlayer->GetName());
	return true;
}
bool HandleNameHashCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	if( !argc )
		return false;
	string spstring;
		ConcatArgs(spstring, argc, 0, argv);
	uint32 spellid = (int)atoi((char*)spstring.c_str());
	SpellEntry * sp = dbcSpell.LookupEntryForced(spellid);
	if ( !sp )
	{
		pConsole->Write( "Spell %u could not be found in spell.dbc\n", spellid );
		return true;
	}
	else
	{
		pConsole->Write( "Name Hash for %u [%s] is 0x%X\n" ,sp->Id, sp->Name , uLong(sp->NameHash));
		return true;
	}
}
bool HandleOnlinePlayersCommand(BaseConsole * pConsole, int argc, const char * argv[])
{
	WorldPacket data;
	//bool first = true;

	pConsole->Write("There following players online on this server: \r\n");
	pConsole->Write("======================================================\r\n");
	pConsole->Write("| %21s | %15s | % 04s  |\r\n" , "Name", "Level", "Latency");
	pConsole->Write("======================================================\r\n");

	PlayerStorageMap::const_iterator itr;
	objmgr._playerslock.AcquireReadLock();
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
	{
		pConsole->Write("| %21s | %15u | %04u ms |\r\n" , itr->second->GetName(), itr->second->GetSession()->GetPlayer()->getLevel(), itr->second->GetSession()->GetLatency());
	}
	objmgr._playerslock.ReleaseReadLock();

	pConsole->Write("======================================================\r\n\r\n");
	return true;
}


