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

initialiseSingleton( World );

DayWatcherThread* dw = NULL;
CharacterLoaderThread* ctl = NULL;

float World::m_movementCompressThreshold;
float World::m_movementCompressThresholdCreatures;
uint32 World::m_movementCompressRate;
uint32 World::m_movementCompressInterval;
float World::m_speedHackThreshold;
float World::m_wallhackthreshold;
float World::m_speedHackLatencyMultiplier;
uint32 World::m_speedHackResetInterval;
uint32 World::m_CEThreshold;

World::World()
{
	m_playerLimit = 0;
	m_allowMovement = true;
	m_gmTicketSystem = true;

	GmClientChannel = "";

	m_StartTime = 0;
	eventholder = new EventableObjectHolder(-1);
	m_holder = eventholder;
	m_event_Instanceid = eventholder->GetInstanceID();

	mQueueUpdateInterval = 10000;
	PeakSessionCount = 0;
	mInWorldPlayerCount = 0;
	mAcceptedConnections = 0;
	HordePlayers = 0;
	AlliancePlayers = 0;
	gm_skip_attunement = false;
	gm_force_robes = false;
	CheckProfessions = false;

	show_gm_in_who_list = true;
	map_unload_time=0;
#ifndef CLUSTERING
	SocketSendBufSize = WORLDSOCKET_SENDBUF_SIZE;
	SocketRecvBufSize = WORLDSOCKET_RECVBUF_SIZE;
#endif
	m_limitedNames=false;
	m_banTable = NULL;
	m_lfgForNonLfg = false;
	m_speedHackThreshold = -500.0f;
	m_speedHackLatencyMultiplier = 0.0f;
	m_speedHackResetInterval = 5000;
	m_CEThreshold = 10000;

	/* Wrath of the Lich King Server Update */
	QueryResult * result = CharacterDatabase.Query("SELECT setting_value FROM server_settings WHERE setting_id = 'expansionupdate'");
	if(result)
	{
		do
		{
			expansionUpdateTime = result->Fetch()[0].GetUInt32();
		}while(result->NextRow());
		delete result;
	}

	if(!result)
	{
		
		Log.Notice("Wrath of the Lich King", "Upgrading the realm to Wrath of the Lich King. This will take a very long time...");
		/*
		 * Why are we using this huge array?
		 * Because previously, we had the DBCs of 2.4.3 to rely on to reset talents. Now, we don't. If a talent was removed,
		 * we have no further record of it, and so it would stay on the character for eternity making him rigged since no one else
		 * could get it, and it didn't "count" as a talent.
		 */
		const static uint32 TalentArray[]={11069,12338,12339,12340,11103,12357,12358,12359,11119,11120,12846,12847,11100,12353,11078,11080,12342,18459,18460,11108,12349,12350,11366,11083,12351,11095,12872,12873,11094,13043,29074,29075,29076,31638,31639,31640,11115,11367,11368,11113,31641,31642,11124,12378,12398,12399,34293,34295,34296,11129,31679,31680,31656,31657,31658,31659,31661,11189,28332,11070,12473,16763,16765,29438,29439,29440,11207,12672,15047,15052,11071,12496,12497,11165,12475,11175,12569,12571,11151,12952,12953,12472,11185,12487,12488,16757,16758,11160,12518,12519,11170,12982,12983,12984,31667,31668,31669,11958,11190,12489,12490,31670,31672,11180,28592,28593,28594,11426,31674,31675,31676,31677,31682,31683,31684,31685,31687,11210,12592,11222,12839,12840,12841,11237,12463,12464,16769,6057,6085,29441,29444,29445,29446,11213,12574,12575,12576,11247,12606,11242,12467,12469,28574,11252,12605,11255,12598,18462,18463,18464,31569,31570,12043,11232,12500,12501,12502,31574,31575,15058,15059,15060,31571,31572,31573,31579,31582,31583,12042,35578,35581,31584,31585,31586,31587,31589,12282,12663,12664,16462,16463,16464,16465,12286,12658,12659,12285,12697,12300,12959,12960,12961,12287,12665,12666,12290,12963,12296,12834,12849,12867,12163,12711,12712,12713,16493,16494,12700,12781,12783,12784,12292,12284,12701,12702,12703,12281,12812,12813,12814,29888,29889,12289,12668,23695,29723,29724,29725,29836,29859,12294,29834,29838,35446,35448,35449,35450,29623,12301,12818,12295,12676,12677,12297,12750,12751,12752,12298,12724,12725,12726,12299,12761,12762,12763,12975,12945,12797,12799,12800,12303,12788,12789,12308,12810,12811,12313,12804,12807,12302,12765,12312,12803,12809,12311,12958,29598,29599,29600,16538,16539,16540,16541,29593,29594,29595,23922,29787,29790,29792,29140,29143,29144,29145,20243,12321,12835,12836,12837,12320,12852,12853,12855,12324,12876,12877,12878,12322,12999,13000,13001,12329,12950,20496,12323,16487,16489,16492,12318,12857,12858,12860,23584,23585,23586,23587,20502,20503,12317,13045,13046,13047,12862,12330,12328,20504,20505,20500,20501,12319,12971,12972,12973,29590,29591,29592,23881,29721,29776,29759,29760,29761,29762,29801,13741,13793,13792,13732,13863,13712,13788,13789,13790,14165,14166,14167,13713,13853,13854,13855,13705,13832,13843,13844,13742,13872,14251,13743,13875,13754,13867,13706,13804,13805,13806,13715,13848,13849,13851,13709,13800,13801,13802,13877,13960,13961,13962,13963,13707,13966,13967,13968,31124,31126,30919,30920,18427,18428,18429,31122,31123,13750,31130,31131,35541,35550,35551,35552,32601,14162,14163,14164,14144,14148,14138,14139,14140,14141,14156,14160,14161,14158,14159,13733,13865,13866,14179,14168,14169,14128,14132,14135,14136,14137,16513,16514,16515,16719,14113,14114,14115,14116,31208,31209,14177,14174,14175,14176,31244,31245,14186,14190,14193,14194,31226,31227,14983,31380,31382,31383,31384,31233,31239,31240,31241,1329,13958,13970,13971,13972,14057,14072,14073,14074,30892,30893,14076,14094,13975,14062,14063,14064,13976,13979,13980,14278,14079,14080,14081,13983,14070,14071,13981,14066,14171,14172,14173,30894,30895,14185,14082,14083,16511,31221,31222,31223,30902,30903,30904,30905,31211,31212,31213,14183,31228,31229,31230,31216,31217,31218,31219,36554,14522,14788,14789,14790,14524,14525,14526,14527,14523,14784,14785,14786,14749,14767,14748,14768,14769,14531,14774,33167,33171,33172,14751,14521,14776,14777,14747,14770,14771,14520,14780,14781,14782,14750,14772,18551,18552,18553,18554,14752,33174,33182,33186,33190,18544,18547,18548,18549,45234,45243,45244,10060,33201,33202,33203,33204,34908,34909,34910,34911,33206,14913,15012,14908,15020,17191,14889,15008,15009,15010,27900,27901,27902,27903,18530,18531,18533,18534,15237,27811,27815,27816,14892,15362,15363,27789,27790,14912,15013,15014,14909,15017,14911,15018,20711,14901,15028,15029,15030,33150,33154,14898,15349,15354,15355,34753,34859,34860,724,33142,33145,33146,33158,33159,33160,33161,34861,15270,15335,15336,15337,15268,15323,15324,15325,15318,15272,15320,15275,15317,15260,15327,15328,15329,15392,15448,15273,15312,15313,15314,15407,15274,15311,17322,17323,15257,15331,15332,15333,15487,15286,27839,27840,33213,33214,33215,14910,33371,15259,15307,15308,15309,15473,33221,33222,33223,33224,33191,33192,33193,33194,34914,16039,16109,16110,16111,16035,16105,16106,16107,16043,16130,28996,28997,28998,16038,16160,16161,16164,16040,16113,16114,16115,16041,16117,16118,16119,16086,16544,29062,29064,29065,30160,29179,29180,28999,29000,16089,30664,30665,30666,30667,30672,30673,30674,16578,16579,16580,16581,16166,30669,30670,30671,30675,30678,30679,30680,30706,16182,16226,16227,16228,16179,16214,16215,16216,16184,16209,16176,16235,16240,16173,16222,16223,16224,16180,16196,16198,16181,16230,16232,16233,16189,29187,29189,29191,16187,16205,16206,16207,16194,16218,16219,16220,29206,29205,29202,16188,30864,30865,30866,16178,16210,16211,16212,16190,30881,30883,30884,30885,30867,30868,30869,30872,30873,974,17485,17486,17487,17488,16253,16298,16299,16300,16258,16293,16255,16302,16303,16304,16262,16287,16261,16290,16291,16259,16295,43338,16254,16271,16272,16273,16256,16281,16282,16283,16252,16306,16307,16308,29192,29193,16268,16266,29079,29080,30812,30813,30814,29082,29084,29086,29087,30816,30818,30819,30798,17364,30802,30808,30809,30810,30823,16934,16935,16936,16937,16858,16859,16860,16861,16947,16948,16949,16940,16941,16929,16930,16931,17002,24866,16979,16942,16943,16944,16966,16968,16972,16974,16975,37116,37117,16998,16999,16857,33872,33873,17003,17004,17005,17006,33853,33855,33856,33851,33852,33957,17007,34297,34300,33859,33866,33867,33868,33917,17050,17051,17053,17054,17056,17058,17059,17060,17069,17070,17071,17072,17063,17065,17066,17067,16833,16834,16835,17106,17107,17108,17118,17119,17120,17121,16864,24968,24969,24970,24971,17111,17112,17113,17116,17104,24943,24944,24945,17123,17124,33879,33880,17074,17075,17076,17077,34151,34152,34153,18562,33881,33882,33883,33886,33887,33888,33889,33891,16814,16815,16816,16817,16689,17245,17247,17248,17249,16918,16919,16920,35363,35364,16821,16822,16836,16839,16840,5570,16819,16820,16909,16910,16911,16912,16850,16923,16924,33589,33590,33591,16880,16845,16846,16847,16896,16897,16899,16900,33592,33596,33597,33599,33956,24858,33600,33601,33602,33603,33604,33605,33606,33831,17793,17796,17801,17802,17778,17779,17780,17781,17788,17789,17790,17791,18119,18120,18121,18122,18126,18127,18128,18129,18130,18131,18132,18133,17877,18135,18136,17917,17918,17927,17929,17930,18096,18073,17815,17833,17834,17835,17959,30299,30301,30302,17954,17955,17956,17957,34935,34938,34939,17962,30293,30295,30296,30288,30289,30290,30291,30283,18174,18175,18176,18177,17810,17811,17812,17813,18179,18180,18213,18372,18182,18183,17804,17805,18827,18829,17783,17784,17785,17786,18288,18218,18219,18094,18095,32381,32382,32383,32385,32387,32392,32393,18265,18223,18271,18272,18273,18274,30060,30061,30062,30063,18220,30054,30057,32477,32483,32484,30108,18692,18693,18694,18695,18696,18697,18698,18699,18700,18703,18704,18705,18706,18707,18731,18743,18744,18754,18755,18756,18708,18748,18749,18750,30143,30144,30145,18709,18710,18769,18770,18771,18772,18821,18822,18788,18767,18768,30326,30327,30328,23785,23822,23823,23824,30319,30320,30321,19028,35691,35692,35693,30242,30245,30246,30247,30146,19552,19553,19554,19555,19583,19584,19585,19586,35029,35030,19549,19550,19551,19609,19610,19612,24443,19575,19559,19560,19596,19616,19617,19618,19619,19572,19573,19598,19599,19600,19601,19578,20895,19577,19590,19592,34453,34454,19621,19622,19623,19624,34455,34459,34460,19574,34462,34464,34465,34466,34467,34468,34469,34692,24293,24294,24295,19151,19152,19153,19498,19499,19500,19159,19160,19184,19387,19388,19295,19297,19298,19301,19228,19232,19233,19239,19245,19255,19256,19257,19258,19263,19376,19377,19290,19294,24283,19286,19287,34494,34496,19370,19371,19373,19306,34491,34492,34493,19168,19180,19181,24296,34497,34498,34499,19386,34500,34502,34503,34506,34507,34508,34838,23989,19407,19412,19413,19414,19426,19427,19429,19430,19421,19422,19423,19424,19416,19417,19418,19419,34950,34954,19454,19455,19456,19457,19434,34948,34949,19464,19465,19466,19467,19485,19487,19488,19489,35100,35102,35103,19503,19461,19462,24691,34475,34476,19507,19508,19509,19510,34482,34483,34484,19506,35104,35110,35111,34485,34486,34487,34488,34490,20042,20045,20046,20047,20101,20102,20103,20104,25956,25957,20335,20336,20337,20060,20061,20062,20063,9452,26016,26021,20117,20118,20119,20120,20375,26022,26023,44414,9799,25988,20091,20092,31866,31867,31868,20111,20112,20113,20218,31869,31870,20049,20056,20057,20058,31876,31877,31878,32043,35396,35397,20066,31871,31872,31873,31879,31880,31881,31882,35395,20262,20263,20264,20265,20257,20258,20259,20260,20205,20206,20207,20209,20224,20225,20330,20331,20237,20238,20239,31821,20234,20235,9453,25836,20210,20212,20213,20214,20244,20245,31822,31823,31824,20216,20359,20360,20361,31825,31826,5923,5924,5925,5926,31833,31835,31836,20473,31828,31829,31830,31837,31838,31839,31840,31842,20138,20139,20140,20141,20127,20130,20135,20136,20189,20192,20193,20174,20175,20143,20144,20145,20146,20217,20468,20469,20470,20148,20149,20150,20096,20097,20098,20099,31844,31845,20487,20488,20489,20254,20255,20256,31846,31847,20911,20177,20179,20181,20180,31848,31849,20196,20197,20198,20199,41021,41026,20925,31850,31851,31852,31853,31858,31859,31860,31861,31935,20218,31869,31870,12341,12360,12848,12400,31660,16766,15053,12985,28595,31678,31686,12842,16770,29447,12577,12503,31588,16466,12962,12714,12785,12704,12815,35451,12753,12727,12764,16542,29146,12838,12856,12879,13002,12861,23588,13048,12974,29763,13791,13856,13845,13807,13852,13803,13964,13969,35553,14142,14137,16720,14117,14195,31385,31242,13973,14075,14065,30906,31220,14791,14528,14787,14783,18555,18550,33205,34912,15011,27904,18535,15031,15356,33162,15338,15326,15330,15316,15334,15310,33225,33195,16112,16108,16116,16120,30668,16582,30681,16229,16217,16225,16234,16208,16221,16213,30886,17489,16301,16305,16274,16284,16309,29088,30811,16938,16862,24894,33869,17055,17061,17073,17068,17122,24972,24946,17078,33890,16818,16913,16901,33607,17803,17782,17792,18123,18134,17836,17958,30292,18178,17814,17787,32394,18275,30064,18701,18773,23825,30248,19556,19587,19620,19602,19625,34470,19300,19259,24297,34839,19415,19431,19425,19420,19458,19468,19490,19511,34489,20048,20105,20064,20121,20059,31883,20266,20261,20208,20332,20215,25829,31841,20142,20137,20147,20100,20182,20200,31854,31862,14267,14268};
		for(uint32 i = 0; i < sizeof(TalentArray) / sizeof(uint32); ++i)
		{
			CharacterDatabase.WaitExecute("UPDATE characters SET spells = REPLACE(spells, '%u,', '')", TalentArray[i]);
		}
		CharacterDatabase.WaitExecute("UPDATE characters SET available_talent_points = level - 9 WHERE level > 9");
		CharacterDatabase.WaitExecute("UPDATE characters SET auras = ''");
		expansionUpdateTime = getMSTime();
		CharacterDatabase.WaitExecute("INSERT INTO server_settings VALUES ('expansionupdate', %u)", expansionUpdateTime);
		Log.Notice("Wrath of the Lich King", "This server is now running Wrath of the Lich King.");
	}
}

uint32 World::GetMaxLevel(PlayerPointer plr)
{
	uint32 level = 60; // Classic World of Warcraft
	if(LevelCap_Custom_All != 0)
		return LevelCap_Custom_All;
	if( plr->GetSession()->HasFlag(WMI_INSTANCE_XPACK_01) )
		level = 70;

	if( plr->GetSession()->HasFlag(WMI_INSTANCE_XPACK_02) )
		level = 80;

	return level;
}

void World::LogoutPlayers()
{
	Log.Notice("World", "Logging out players...");
	for(SessionMap::iterator i=m_sessions.begin();i!=m_sessions.end();i++)
	{
		(i->second)->LogoutPlayer(true);
	}

	Log.Notice("World", "Deleting sessions...");
	WorldSession * Session;
	for(SessionMap::iterator i=m_sessions.begin();i!=m_sessions.end();)
	{
		Session = i->second;
		++i;

		DeleteGlobalSession(Session);
	}
}

World::~World()
{
}

void World::Destructor()
{
	Log.Notice("LocalizationMgr", "~LocalizationMgr()");
	sLocalizationMgr.Shutdown();

	Log.Notice("WorldLog", "~WorldLog()");
	delete WorldLog::getSingletonPtr();

	Log.Notice("ObjectMgr", "~ObjectMgr()");
	delete ObjectMgr::getSingletonPtr();
	
	Log.Notice("LootMgr", "~LootMgr()");
	delete LootMgr::getSingletonPtr();
	
	Log.Notice("LfgMgr", "~LfgMgr()");
	delete LfgMgr::getSingletonPtr();

	Log.Notice("ChannelMgr", "~ChannelMgr()");
	delete ChannelMgr::getSingletonPtr();

	Log.Notice("QuestMgr", "~QuestMgr()");
	delete QuestMgr::getSingletonPtr();
  
	Log.Notice("WeatherMgr", "~WeatherMgr()");
	delete WeatherMgr::getSingletonPtr();

	Log.Notice("TaxiMgr", "~TaxiMgr()");
	delete TaxiMgr::getSingletonPtr();

	Log.Notice("ChatHandler", "~ChatHandler()");
	delete ChatHandler::getSingletonPtr();

	Log.Notice("InstanceMgr", "~InstanceMgr()");
	sInstanceMgr.Shutdown();

	//sLog.outString("Deleting Thread Manager..");
	//delete ThreadMgr::getSingletonPtr();
	Log.Notice("WordFilter", "~WordFilter()");
	delete g_chatFilter;
	delete g_characterNameFilter;

	for( AreaTriggerMap::iterator i = m_AreaTrigger.begin( ); i != m_AreaTrigger.end( ); ++ i ) 
	{
		delete i->second;
	}

	//eventholder = 0;
	delete eventholder;

	Storage_Cleanup();
	for(list<SpellEntry*>::iterator itr = dummyspells.begin(); itr != dummyspells.end(); ++itr)
		delete *itr;
}


WorldSession* World::FindSession(uint32 id)
{
	m_sessionlock.AcquireReadLock();
	WorldSession * ret = 0;
	SessionMap::const_iterator itr = m_sessions.find(id);

	if(itr != m_sessions.end())
		ret = m_sessions[id];
	
	m_sessionlock.ReleaseReadLock();

	return ret;
}

void World::RemoveSession(uint32 id)
{
	SessionMap::iterator itr = m_sessions.find(id);

	m_sessionlock.AcquireWriteLock();
	if(itr != m_sessions.end())
	{
		//If it's a GM, remove him from GM session map
		if(itr->second->HasGMPermissions())
		{
			gmList_lock.AcquireWriteLock();
			gmList.erase(itr->second);
			gmList_lock.ReleaseWriteLock();
		}
		delete itr->second;
		m_sessions.erase(itr);
	}
	m_sessionlock.ReleaseWriteLock();
}

void World::AddSession(WorldSession* s)
{
	if(!s)
		return;
	ASSERT(s);

	//add this session to the big session map
	m_sessionlock.AcquireWriteLock();
	m_sessions[s->GetAccountId()] = s;
	m_sessionlock.ReleaseWriteLock();

	//check max online counter, update when necessary
	if(m_sessions.size() >  PeakSessionCount)
		PeakSessionCount = (uint32)m_sessions.size();

	//If it's a GM, add to GM session map
	if(s->HasGMPermissions())
	{
		gmList_lock.AcquireWriteLock();
		gmList.insert(s);
		gmList_lock.ReleaseWriteLock();
	}
}

void World::AddGlobalSession(WorldSession *GlobalSession)
{
	if(!GlobalSession)
		return;

	SessionsMutex.Acquire();
	GlobalSessions.insert(GlobalSession);
	SessionsMutex.Release();
}

void World::RemoveGlobalSession(WorldSession *GlobalSession)
{
	SessionsMutex.Acquire();
	GlobalSessions.erase(GlobalSession);
	SessionsMutex.Release();
}

bool BasicTaskExecutor::run()
{
	/* Set thread priority, this is a bitch for multiplatform :P */
#ifdef WIN32
	switch(priority)
	{
		case BTE_PRIORITY_LOW:
			::SetThreadPriority( ::GetCurrentThread(), THREAD_PRIORITY_LOWEST );
			break;

		case BTW_PRIORITY_HIGH:
			::SetThreadPriority( ::GetCurrentThread(), THREAD_PRIORITY_ABOVE_NORMAL );
			break;

		default:		// BTW_PRIORITY_MED
			::SetThreadPriority( ::GetCurrentThread(), THREAD_PRIORITY_NORMAL );
			break;
	}
#else
	struct sched_param param;
	switch(priority)
	{
	case BTE_PRIORITY_LOW:
		param.sched_priority = 0;
		break;

	case BTW_PRIORITY_HIGH:
		param.sched_priority = 10;
		break;

	default:		// BTW_PRIORITY_MED
		param.sched_priority = 5;
		break;
	}
	pthread_setschedparam(pthread_self(), SCHED_OTHER, &param);
#endif

	// Execute the task in our new context.
	cb->execute();
#ifdef WIN32
	::SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_NORMAL);
#else
	param.sched_priority = 5;
	pthread_setschedparam(pthread_self(), SCHED_OTHER, &param);
#endif

	return true;
}

void ApplyNormalFixes();

void PreStartQueries()
{
	QueryResult * result;
	
	result = WorldDatabase.Query("SELECT * FROM prestartqueries ORDER BY seq ASC");
	if(result)
	{
		Log.Notice("DataBase","Found and executing %u prestart queries on World tables.",result->GetRowCount());
		do
		{
			Field * f = result->Fetch();
			string e_query =  f[0].GetString();
			WorldDatabase.Execute(e_query.c_str());
		}while(result->NextRow());

		delete result;
		WorldDatabase.Execute("DELETE FROM prestartqueries WHERE SingleShot = 1;");
	}

	result = CharacterDatabase.Query("SELECT * FROM prestartqueries ORDER BY seq ASC");
	if(result)
	{
		Log.Notice("DataBase","Found and executing %u prestart queries on Character tables.",result->GetRowCount());
		do
		{
			Field * f = result->Fetch();
			string e_query =  f[0].GetString();
			CharacterDatabase.Execute(e_query.c_str());
		}while(result->NextRow());

		delete result;
		CharacterDatabase.Execute("DELETE FROM prestartqueries WHERE SingleShot = 1;");
	}
}

bool World::SetInitialWorldSettings()
{
	Log.Line();
	//Perform pre-starting queries on World- and Character-DataBase
	PreStartQueries();
	CharacterDatabase.WaitExecute("UPDATE characters SET online = 0 WHERE online = 1");

	Log.Notice("World", "Starting up...");  
	Log.Line();

	Player::InitVisibleUpdateBits();

	m_lastTick = UNIXTIME;

	// TODO: clean this
	time_t tiempo;
	char hour[3];
	char minute[3];
	char second[3];
	struct tm *tmPtr;
	tiempo = UNIXTIME;
	tmPtr = localtime(&tiempo);
	strftime( hour, 3, "%H", tmPtr );
	strftime( minute, 3, "%M", tmPtr );
	strftime( second, 3, "%S", tmPtr );
	m_gameTime = (3600*atoi(hour))+(atoi(minute)*60)+(atoi(second)); // server starts at noon

	// TODO: clean this
	// fill in emotes table
	// it appears not every emote has an animation
	mPrices[1] = 10;
	mPrices[4] = 80;
	mPrices[6] = 150;
	mPrices[8] = 200;
	mPrices[10] = 300;
	mPrices[12] = 800;
	mPrices[14] = 900;
	mPrices[16] = 1800;
	mPrices[18] = 2200;
	mPrices[20] = 2300;
	mPrices[22] = 3600;
	mPrices[24] = 4200;
	mPrices[26] = 6700;
	mPrices[28] = 7200;
	mPrices[30] = 8000;
	mPrices[32] = 11000;
	mPrices[34] = 14000;
	mPrices[36] = 16000;
	mPrices[38] = 18000;
	mPrices[40] = 20000;
	mPrices[42] = 27000;
	mPrices[44] = 32000;
	mPrices[46] = 37000;
	mPrices[48] = 42000;
	mPrices[50] = 47000;
	mPrices[52] = 52000;
	mPrices[54] = 57000;
	mPrices[56] = 62000;
	mPrices[58] = 67000;
	mPrices[60] = 72000;

	// Start

	uint32 start_time = getMSTime();
	if( !LoadDBCs() )
	{
		Log.LargeErrorMessage(LARGERRORMESSAGE_ERROR, "One or more of the DBC files are missing.", "These are absolutely necessary for the server to function.", "The server will not start without them.", NULL);
		return false;
	}

	/* Convert area table ids/flags */
	DBCFile area;

	if( !area.open( "DBC/AreaTable.dbc" ) )
	{
		Log.Error( "World", "Cannot find file ./DBC/AreaTable.dbc" );
		return false;
	}

	uint32 flag_, area_, zone_;
	for(uint32 i = 0; i < area.getRecordCount(); ++i)
	{
		area_ = area.getRecord(i).getUInt(0);
		flag_ = area.getRecord(i).getUInt(3);
		zone_ = area.getRecord(i).getUInt(2);

		mAreaIDToTable[flag_] = dbcArea.LookupEntryForced(area_);
		if(mZoneIDToTable.find(zone_) != mZoneIDToTable.end())
		{
			if(mZoneIDToTable[zone_]->AreaFlags != 312 &&
				mAreaIDToTable[flag_]->AreaFlags == 312)
			{
				// over ride.
				mZoneIDToTable[zone_] = mAreaIDToTable[flag_];
			}
		}
		else
		{
			mZoneIDToTable[zone_] = mAreaIDToTable[flag_];
		}
	}

	new ObjectMgr;
	new QuestMgr;
	new LootMgr;
	new LfgMgr;
	new WeatherMgr;
	new TaxiMgr;
	new AddonMgr;
	new WorldLog;
	new ChatHandler;

	// grep: this only has to be done once between version updates
	// to re-fill the table.

	/*sLog.outString("Filling spell replacements table...");
	FillSpellReplacementsTable();
	sLog.outString("");*/

#define MAKE_TASK(sp, ptr) tl.AddTask(new Task(new NoSharedPtrCallbackP0<sp>(sp::getSingletonPtr(), &sp::ptr)))
	// Fill the task list with jobs to do.
	TaskList tl;
	Storage_FillTaskList(tl);

	// spawn worker threads (2 * number of cpus)
	tl.spawn();

	/* storage stuff has to be loaded first */
	tl.wait();

	Storage_LoadAdditionalTables();

	MAKE_TASK(ObjectMgr, LoadPlayerCreateInfo);
	MAKE_TASK(ObjectMgr, LoadPlayersInfo);
	MAKE_TASK(ObjectMgr, LoadSpellSkills);

	tl.wait();

	ApplyNormalFixes();

	MAKE_TASK(ObjectMgr, LoadAchievements);
	MAKE_TASK(ObjectMgr, LoadCreatureWaypoints);
	MAKE_TASK(ObjectMgr, LoadTrainers);
	MAKE_TASK(ObjectMgr, LoadTotemSpells);
	MAKE_TASK(ObjectMgr, LoadSpellOverride);
	MAKE_TASK(ObjectMgr, LoadVendors);
	MAKE_TASK(ObjectMgr, LoadAIThreatToSpellId);
	MAKE_TASK(ObjectMgr, LoadSpellFixes);
	MAKE_TASK(ObjectMgr, LoadGuildCharters);
	MAKE_TASK(ObjectMgr, LoadGMTickets);
	MAKE_TASK(AddonMgr, LoadFromDB);
	MAKE_TASK(ObjectMgr, SetHighestGuids);
	MAKE_TASK(ObjectMgr, LoadReputationModifiers);
	MAKE_TASK(ObjectMgr, LoadMonsterSay);
	MAKE_TASK(WeatherMgr, LoadFromDB);
	MAKE_TASK(ObjectMgr,LoadGroups);

	MAKE_TASK(ObjectMgr, LoadExtraCreatureProtoStuff);
	MAKE_TASK(ObjectMgr, LoadExtraItemStuff);
	MAKE_TASK(QuestMgr, LoadExtraQuestStuff);
	MAKE_TASK(ObjectMgr, LoadArenaTeams);

#undef MAKE_TASK

	// wait for all loading to complete.
	tl.wait();
	sLocalizationMgr.Reload(false);

	CommandTableStorage::getSingleton().Load();
	Log.Notice("WordFilter", "Loading...");
	
	g_characterNameFilter = new WordFilter();
	g_chatFilter = new WordFilter();
	g_characterNameFilter->Load("wordfilter_character_names");
	g_chatFilter->Load("wordfilter_chat");

	Log.Notice("WordFilter", "Done.");

	sLog.outString("");
	Log.Notice("World", "Database loaded in %ums.", getMSTime() - start_time);
	sLog.outString("");

	if (sWorld.Collision)
		CollideInterface.Init();
	sScriptMgr.LoadScripts();

	// calling this puts all maps into our task list.
	sInstanceMgr.Load(&tl);

	// wait for the events to complete.
	tl.wait();

	// wait for them to exit, now.
	tl.kill();
	tl.waitForThreadsToExit();
	sLog.outString("");
	LoadNameGenData();

	Log.Notice("World", "Object size: %u bytes", sizeof(Object));
	Log.Notice("World", "Unit size: %u bytes", sizeof(Unit) + sizeof(AIInterface));
	Log.Notice("World", "Creature size: %u bytes", sizeof(Creature) + sizeof(AIInterface));
	Log.Notice("World", "Vehicle size: %u bytes", sizeof(Vehicle) + sizeof(AIInterface));
	Log.Notice("World", "Player size: %u bytes", sizeof(Player) + sizeof(ItemInterface) + 50000 + 30000 + 1000 + sizeof(AIInterface));
	Log.Notice("World", "GameObject size: %u bytes", sizeof(GameObject));

// ------------------------------------------------------------------------------------------------

	Log.Notice("World","Starting Transport System...");
	objmgr.LoadTransporters();

	// start mail system
	Log.Notice("World","Starting Mail System...");
	MailSystem::getSingleton().StartMailSystem();

	Log.Notice("World", "Starting Auction System...");
	new AuctionMgr;
	sAuctionMgr.LoadAuctionHouses();

	m_queueUpdateTimer = mQueueUpdateInterval;
	if(Config.MainConfig.GetBoolDefault("Startup", "BackgroundLootLoading", true))
	{
		Log.Notice("World", "Backgrounding loot loading...");

		// loot background loading in a lower priority thread.
		ThreadPool.ExecuteTask(new BasicTaskExecutor(new NoSharedPtrCallbackP0<LootMgr>(LootMgr::getSingletonPtr(), &LootMgr::LoadCreatureLoot), 
			BTE_PRIORITY_LOW));
	}
	else
	{
		Log.Notice("World", "Loading loot in foreground...");
		lootmgr.LoadCreatureLoot();
	}

	Log.Notice("World", "Loading Channel config...");
	Channel::LoadConfSettings();

	Log.Notice("World", "Starting BattlegroundManager...");
	BattlegroundMgrPointer BattlegroundMgr(new CBattlegroundManager);
	BattlegroundMgr->Init();

	Log.Notice("World", "Starting Daywatcher...");
	dw = new DayWatcherThread();
	ThreadPool.ExecuteTask( dw );

	Log.Notice("World", "Starting ChracterLoader...");
	ctl = new CharacterLoaderThread();
	ThreadPool.ExecuteTask( ctl );
	ThreadPool.ExecuteTask( new NewsAnnouncer() );

#ifdef ENABLE_COMPRESSED_MOVEMENT
	Log.Notice("World", "Starting MovementCompressor...");
	MovementCompressor = new CMovementCompressorThread();
	ThreadPool.ExecuteTask( MovementCompressor );
#endif

	// Preload and compile talent and talent tab data to speed up talent inspect

	uint32 talent_max_rank;
	uint32 talent_pos;
	uint32 talent_class;

    for( uint32 i = 0; i < dbcTalent.GetNumRows(); ++i )
    {
        TalentEntry const* talent_info = dbcTalent.LookupRow( i );
		if( talent_info == NULL )
			continue;

		TalentTabEntry const* tab_info = dbcTalentTab.LookupEntry( talent_info->TalentTree );
		if( tab_info == NULL )
			continue;

        talent_max_rank = 0;
        for( uint32 j = 5; j > 0; --j )
        {
            if( talent_info->RankID[j - 1] )
            {
                talent_max_rank = j;
                break;
            }
		}

		InspectTalentTabBit[( talent_info->Row << 24 ) + ( talent_info->Col << 16 ) + talent_info->TalentID] = talent_max_rank;
		InspectTalentTabSize[talent_info->TalentTree] += talent_max_rank;
	}

	for( uint32 i = 0; i < dbcTalentTab.GetNumRows(); ++i )
	{
		TalentTabEntry const* tab_info = dbcTalentTab.LookupRow( i );
		if( tab_info == NULL )
			continue;

		talent_pos = 0;
        
		for( talent_class = 0; talent_class < 12; ++talent_class )
		{
			if( tab_info->ClassMask & ( 1 << talent_class ) )
				break;
		}

		InspectTalentTabPages[talent_class + 1][tab_info->TabPage] = tab_info->TalentTabID;

		for( std::map< uint32, uint32 >::iterator itr = InspectTalentTabBit.begin(); itr != InspectTalentTabBit.end(); ++itr )
		{
			uint32 talent_id = itr->first & 0xFFFF;
			TalentEntry const* talent_info = dbcTalent.LookupEntry( talent_id );
			if( talent_info == NULL )
				continue;

			if( talent_info->TalentTree != tab_info->TalentTabID )
				continue;

			InspectTalentTabPos[talent_id] = talent_pos;
			talent_pos += itr->second;
		}
	}

	sEventMgr.AddEvent(CAST(World,shared_from_this()), &World::CheckForExpiredInstances, EVENT_WORLD_UPDATEAUCTIONS, 120000, 0, 0);
	return true;
}

void World::Update(time_t diff)
{
	eventholder->Update((uint32)diff);
	sAuctionMgr.Update();
	sMailSystem.UpdateMessages();
	_UpdateGameTime();
	UpdateQueuedSessions((uint32)diff);
#ifdef SESSION_CAP
	if( GetSessionCount() >= SESSION_CAP )
		TerminateProcess(GetCurrentProcess(),0);
#endif
}

void World::SendMessageToGMs(WorldSession *self, const char * text, ...)
{
	char buf[500];
	va_list ap;
	va_start(ap, text);
	vsnprintf(buf, 2000, text, ap);
	va_end(ap);
	WorldSession *gm_session;

	WorldPacket *data = sChatHandler.FillSystemMessageData(buf);
	gmList_lock.AcquireReadLock();	
	SessionSet::iterator itr;
	for (itr = gmList.begin(); itr != gmList.end();itr++)
	{
		gm_session = (*itr);
		if(gm_session->GetPlayer() != NULL && gm_session != self)  // dont send to self!)
			gm_session->SendPacket(data);
	}
	gmList_lock.ReleaseReadLock();
	delete data;
}

void World::SendGlobalMessage(WorldPacket *packet, WorldSession *self)
{
	m_sessionlock.AcquireReadLock();

	SessionMap::iterator itr;
	for (itr = m_sessions.begin(); itr != m_sessions.end(); itr++)
	{
		if (itr->second->GetPlayer() &&
			itr->second->GetPlayer()->IsInWorld()
			&& itr->second != self)  // dont send to self!
		{
			itr->second->SendPacket(packet);
		}
	}

	m_sessionlock.ReleaseReadLock();
}
void World::SendFactionMessage(WorldPacket *packet, uint8 teamId)
{
	m_sessionlock.AcquireReadLock();
	SessionMap::iterator itr;
	PlayerPointer plr;
	for(itr = m_sessions.begin(); itr != m_sessions.end(); itr++)
	{
		plr = itr->second->GetPlayer();
		if(!plr || !plr->IsInWorld())
			continue;

		if(plr->GetTeam() == teamId)
			itr->second->SendPacket(packet);
	}
	m_sessionlock.ReleaseReadLock();
}

void World::SendZoneMessage(WorldPacket *packet, uint32 zoneid, WorldSession *self)
{
	m_sessionlock.AcquireReadLock();

	SessionMap::iterator itr;
	for (itr = m_sessions.begin(); itr != m_sessions.end(); itr++)
	{
		if (itr->second->GetPlayer() && itr->second->GetPlayer()->IsInWorld() && itr->second != self)  // dont send to self!
		{
			if (itr->second->GetPlayer()->GetZoneId() == zoneid)
				itr->second->SendPacket(packet);
		}
	}

	m_sessionlock.ReleaseReadLock();
}

void World::SendInstanceMessage(WorldPacket *packet, uint32 instanceid, WorldSession *self)
{
	m_sessionlock.AcquireReadLock();

	SessionMap::iterator itr;
	for (itr = m_sessions.begin(); itr != m_sessions.end(); itr++)
	{
		if (itr->second->GetPlayer() &&
			itr->second->GetPlayer()->IsInWorld()
			&& itr->second != self)  // dont send to self!
		{
			if (itr->second->GetPlayer()->GetInstanceID() == (int32)instanceid)
				itr->second->SendPacket(packet);
		}
	}

	m_sessionlock.ReleaseReadLock();
}

void World::SendWorldText(const char* text, WorldSession *self)
{
    uint32 textLen = (uint32)strlen((char*)text) + 1;

    WorldPacket data(textLen + 40);

	data.Initialize(SMSG_MESSAGECHAT);
	data << uint8(CHAT_MSG_SYSTEM);
	data << uint32(LANG_UNIVERSAL);
	
	data << (uint64)0; // Who cares about guid when there's no nickname displayed heh ?
	data << (uint32)0;
	data << (uint64)0;

	data << textLen;
	data << text;
	data << uint8(0);

	SendGlobalMessage(&data, self);

	sLog.outString("> %s", text);
}

void World::SendWorldWideScreenText(const char *text, WorldSession *self)
{
	WorldPacket data(256);
	data.Initialize(SMSG_AREA_TRIGGER_MESSAGE);
	data << (uint32)0 << text << (uint8)0x00;
	SendGlobalMessage(&data, self);
}

void World::UpdateSessions(uint32 diff)
{
	SessionSet::iterator itr, it2;
	WorldSession *GlobalSession;
	int result;
	SessionsMutex.Acquire();
	for(itr = GlobalSessions.begin(); itr != GlobalSessions.end();)
	{
		GlobalSession = (*itr);
		it2 = itr;
		++itr;
		//We have been moved to mapmgr, remove us here.
		if( GlobalSession->GetInstance() != 0 )
		{
			GlobalSessions.erase(it2);
			continue;
		}
		result = GlobalSession->Update(0);
		if(result)
		{
			if(result == 1)//socket don't exist anymore, delete from worldsessions.
				DeleteGlobalSession(GlobalSession);

			//We have been (re-)moved to mapmgr, remove us here.
			GlobalSessions.erase(it2);
		}
	}
	SessionsMutex.Release();
}

std::string World::GenerateName(uint32 type)
{
	if(_namegendata[type].size() == 0)
		return "ERR";

	uint32 ent = RandomUInt((uint32)_namegendata[type].size()-1);
	return _namegendata[type].at(ent).name;
}

void World::DeleteGlobalSession(WorldSession *GlobalSession)
{
	//If it's a GM, remove him from GM session map
	if(GlobalSession->HasGMPermissions())
	{
		gmList_lock.AcquireWriteLock();
		gmList.erase(GlobalSession);
		gmList_lock.ReleaseWriteLock();
	}

	// remove from big map
	m_sessionlock.AcquireWriteLock();
	m_sessions.erase(GlobalSession->GetAccountId());
	m_sessionlock.ReleaseWriteLock();

	// delete us
	GlobalSession->Delete();
}
uint32 World::AddQueuedSocket(WorldSocket* Socket)
{
	// Since we have multiple socket threads, better guard for this one,
	// we don't want heap corruption ;)
	queueMutex.Acquire();

	// Add socket to list
	mQueuedSessions.push_back(Socket);
	queueMutex.Release();
	// Return queue position
	return (uint32)mQueuedSessions.size();
}

void World::RemoveQueuedSocket(WorldSocket* Socket)
{
	// Since we have multiple socket threads, better guard for this one,
	// we don't want heap corruption ;)
	queueMutex.Acquire();

	// Find socket in list
	QueueSet::iterator iter = mQueuedSessions.begin();
	for(; iter != mQueuedSessions.end(); ++iter)
	{
		if((*iter) == Socket)
		{
			// Remove from the queue and abort.
			// This will be slow (Removing from middle of a vector!) but it won't
			// get called very much, so it's not really a big deal.

			mQueuedSessions.erase(iter);
			queueMutex.Release();
			return;
		}
	}
	queueMutex.Release();
}

uint32 World::GetQueuePos(WorldSocket* Socket)
{
	// Since we have multiple socket threads, better guard for this one,
	// we don't want heap corruption ;)
	queueMutex.Acquire();

	// Find socket in list
	QueueSet::iterator iter = mQueuedSessions.begin();
	uint32 QueuePos = 1;
	for(; iter != mQueuedSessions.end(); ++iter, ++QueuePos)
	{
		if((*iter) == Socket)
		{
			queueMutex.Release();
			// Return our queue position.
			return QueuePos;
		}
	}
	queueMutex.Release();
	// We shouldn't get here..
	return 1;
}

void World::UpdateQueuedSessions(uint32 diff)
{
#ifndef CLUSTERING
	if(diff >= m_queueUpdateTimer) 
	{
		m_queueUpdateTimer = mQueueUpdateInterval;
		queueMutex.Acquire();

		if(mQueuedSessions.size() == 0)
		{
			queueMutex.Release();
			return;
		}
		
		while(m_sessions.size() < m_playerLimit && mQueuedSessions.size())
		{
			// Yay. We can let another player in now.
			// Grab the first fucker from the queue, but guard of course, since
			// this is in a different thread again.

			QueueSet::iterator iter = mQueuedSessions.begin();
			WorldSocket * QueuedSocket = *iter;
			mQueuedSessions.erase(iter);

			// Welcome, sucker.
			if(QueuedSocket->GetSession())
			{
				QueuedSocket->GetSession()->deleteMutex.Acquire();
				QueuedSocket->Authenticate();
				QueuedSocket->GetSession()->deleteMutex.Release();
			}
		}

		if(mQueuedSessions.size() == 0)
		{
			queueMutex.Release();
			return;
		}

		// Update the remaining queue members.
		QueueSet::iterator iter = mQueuedSessions.begin();
		uint32 Position = 1;
		while(iter != mQueuedSessions.end())
		{
			(*iter)->UpdateQueuePosition(Position++);
			if(iter==mQueuedSessions.end())
				break;
			else
				++iter;
		}
		queueMutex.Release();
	} 
	else 
	{
		m_queueUpdateTimer -= diff;
	}
#endif
}

void World::SaveAllPlayers()
{
	if(!(ObjectMgr::getSingletonPtr()))
		return;

	sLog.outString("Saving all players to database...");
	uint32 count = 0;
	PlayerStorageMap::const_iterator itr;
		// Servers started and obviously runing. lets save all players.
	uint32 mt;
	objmgr._playerslock.AcquireReadLock();   
	for (itr = objmgr._players.begin(); itr != objmgr._players.end(); itr++)
		{
			if(itr->second->GetSession())
			{
				mt = getMSTime();
				itr->second->SaveToDB(false);
				sLog.outString("Saved player `%s` (level %u) in %ums.", itr->second->GetName(), itr->second->GetUInt32Value(UNIT_FIELD_LEVEL), getMSTime() - mt);
				++count;
			}
		}
	objmgr._playerslock.ReleaseReadLock();
	sLog.outString("Saved %u players.", count);
}

WorldSession* World::FindSessionByName(const char * Name)//case insensetive
{
	m_sessionlock.AcquireReadLock();

	// loop sessions, see if we can find him
	SessionMap::iterator itr = m_sessions.begin();
	for(; itr != m_sessions.end(); ++itr)
	{
		if(!stricmp(itr->second->GetAccountName().c_str(),Name))
		{
			m_sessionlock.ReleaseReadLock();
			return itr->second;
		}
	}
	m_sessionlock.ReleaseReadLock();
	return 0;
}

void World::GetStats(uint32 * GMCount, float * AverageLatency)
{
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

	*AverageLatency = count ? (float)((float)avg / (float)count) : 0;
	*GMCount = gm;
}

void TaskList::AddTask(Task * task)
{
	queueLock.Acquire();
	tasks.insert(task);
	queueLock.Release();
}

Task * TaskList::GetTask()
{
	queueLock.Acquire();

	Task* t = 0;
	for(set<Task*>::iterator itr = tasks.begin(); itr != tasks.end(); ++itr)
	{
		if(!(*itr)->in_progress)
		{
			t = (*itr);
			t->in_progress = true;
			break;
		}
	}
	queueLock.Release();
	return t;
}

void TaskList::spawn()
{
	running = true;
	thread_count = 0;

	uint32 threadcount;
	if(Config.MainConfig.GetBoolDefault("Startup", "EnableMultithreadedLoading", true))
	{
		// get processor count
#ifndef WIN32
#if UNIX_FLAVOUR == UNIX_FLAVOUR_LINUX
#ifdef X64
		threadcount = 2;
#else
		long affmask;
		sched_getaffinity(0, 4, (cpu_set_t*)&affmask);
		threadcount = (BitCount8(affmask)) * 2;
		if(threadcount > 8) threadcount = 8;
		else if(threadcount <= 0) threadcount = 1;
#endif
#else
		threadcount = 2;
#endif
#else
		SYSTEM_INFO s;
		GetSystemInfo(&s);
		threadcount = s.dwNumberOfProcessors * 2;
		if(threadcount>8)
			threadcount=8;
#endif
	}
	else
		threadcount = 1;

	Log.Line();
	Log.Notice("World", "Beginning %s server startup with %u threads.", (threadcount == 1) ? "progressive" : "parallel", threadcount);
	Log.Line();

	for(uint32 x = 0; x < threadcount; ++x)
		ThreadPool.ExecuteTask(new TaskExecutor(this));
}

void TaskList::wait()
{
	bool has_tasks = true;
	time_t t;
	while(has_tasks)
	{
		queueLock.Acquire();
		has_tasks = false;
		for(set<Task*>::iterator itr = tasks.begin(); itr != tasks.end(); ++itr)
		{
			if(!(*itr)->completed)
			{
				has_tasks = true;
				break;
			}
		}
		queueLock.Release();

		// keep updating time lol
		t = time(NULL);
		if( UNIXTIME != t )
		{
			UNIXTIME = t;
			g_localTime = *localtime(&t);
		}

		Sleep(20);
	}
}

void TaskList::kill()
{
	running = false;
}

void Task::execute()
{
	_cb->execute();
}

bool TaskExecutor::run()
{
	Task * t;
	while(starter->running)
	{
		t = starter->GetTask();
		if(t)
		{
			t->execute();
			t->completed = true;
			starter->RemoveTask(t);
			delete t;
		}
		else
			Sleep(20);
	}
	return true;
}

void TaskList::waitForThreadsToExit()
{
	while(thread_count)
	{
		Sleep(20);
	}
}

void World::DeleteObject(ObjectPointer obj)
{
	obj->Destructor();
	obj = NULLOBJ;
}

void World::Rehash(bool load)
{
	if(load)
	{
		#ifdef WIN32
		Config.MainConfig.SetSource("hearthstone-world.conf", true);
		#else
		Config.MainConfig.SetSource((char*)CONFDIR "/hearthstone-world.conf", true);
		#endif
	}

	if(!ChannelMgr::getSingletonPtr())
		new ChannelMgr;

	if(!MailSystem::getSingletonPtr())
		new MailSystem;

	channelmgr.seperatechannels = Config.MainConfig.GetBoolDefault("Server", "SeperateChatChannels", false);
	MapPath = Config.MainConfig.GetStringDefault("Terrain", "MapPath", "maps");
	vMapPath = Config.MainConfig.GetStringDefault("Terrain", "vMapPath", "vmaps");
	UnloadMapFiles = Config.MainConfig.GetBoolDefault("Terrain", "UnloadMapFiles", true);
	BreathingEnabled = Config.MainConfig.GetBoolDefault("Server", "EnableBreathing", true);
	SendStatsOnJoin = Config.MainConfig.GetBoolDefault("Server", "SendStatsOnJoin", true);
	compression_threshold = Config.MainConfig.GetIntDefault("Server", "CompressionThreshold", 1000);

	StartLevel = Config.MainConfig.GetIntDefault("Server", "StartLevel", 1);

	// load regeneration rates.
	setRate(RATE_HEALTH,Config.MainConfig.GetFloatDefault("Rates", "Health",1));
	setRate(RATE_POWER1,Config.MainConfig.GetFloatDefault("Rates", "Power1",1));
	setRate(RATE_POWER2,Config.MainConfig.GetFloatDefault("Rates", "Power2",1));
	setRate(RATE_POWER3,Config.MainConfig.GetFloatDefault("Rates", "Power4",1));
	setRate(RATE_DROP0,Config.MainConfig.GetFloatDefault("Rates", "DropGrey",1));
	setRate(RATE_DROP1,Config.MainConfig.GetFloatDefault("Rates", "DropWhite",1));
	setRate(RATE_DROP2,Config.MainConfig.GetFloatDefault("Rates", "DropGreen",1));
	setRate(RATE_DROP3,Config.MainConfig.GetFloatDefault("Rates", "DropBlue",1));
	setRate(RATE_DROP4,Config.MainConfig.GetFloatDefault("Rates", "DropPurple",1));
	setRate(RATE_DROP5,Config.MainConfig.GetFloatDefault("Rates", "DropOrange",1));
	setRate(RATE_DROP6,Config.MainConfig.GetFloatDefault("Rates", "DropArtifact",1));
	setRate(RATE_XP,Config.MainConfig.GetFloatDefault("Rates", "XP",1));
	setRate(RATE_RESTXP,Config.MainConfig.GetFloatDefault("Rates", "RestXP", 1));
	setRate(RATE_QUESTXP,Config.MainConfig.GetFloatDefault("Rates", "QuestXP", 1));
	setIntRate(INTRATE_SAVE, Config.MainConfig.GetIntDefault("Rates", "Save", 1));
	setRate(RATE_MONEY, Config.MainConfig.GetFloatDefault("Rates", "DropMoney", 1.0f));
	setRate(RATE_QUESTREPUTATION, Config.MainConfig.GetFloatDefault("Rates", "QuestReputation", 1.0f));
	setRate(RATE_KILLREPUTATION, Config.MainConfig.GetFloatDefault("Rates", "KillReputation", 1.0f));
	setRate(RATE_HONOR, Config.MainConfig.GetFloatDefault("Rates", "Honor", 1.0f));
	setRate(RATE_SKILLCHANCE, Config.MainConfig.GetFloatDefault("Rates", "SkillChance", 1.0f));
	setRate(RATE_SKILLRATE, Config.MainConfig.GetFloatDefault("Rates", "SkillRate", 1.0f));
	setIntRate(INTRATE_COMPRESSION, Config.MainConfig.GetIntDefault("Rates", "Compression", 1));
	setIntRate(INTRATE_PVPTIMER, Config.MainConfig.GetIntDefault("Rates", "PvPTimer", 300000));
	setRate(RATE_ARENAPOINTMULTIPLIER2X, Config.MainConfig.GetFloatDefault("Rates", "ArenaMultiplier2x", 1.0f));
	setRate(RATE_ARENAPOINTMULTIPLIER3X, Config.MainConfig.GetFloatDefault("Rates", "ArenaMultiplier3x", 1.0f));
	setRate(RATE_ARENAPOINTMULTIPLIER5X, Config.MainConfig.GetFloatDefault("Rates", "ArenaMultiplier5x", 1.0f));
	Collision = Config.MainConfig.GetBoolDefault("Server", "Collision", false);
	free_arena_teams = Config.MainConfig.GetBoolDefault("Server", "FreeArenaTeams", false);
	free_guild_charters = Config.MainConfig.GetBoolDefault("Server", "FreeGuildCharters", false);
	setRate(RATE_EOTS_CAPTURERATE, Config.MainConfig.GetFloatDefault("Rates", "EOTSCaptureRate", 1.0f));
	SetPlayerLimit(Config.MainConfig.GetIntDefault("Server", "PlayerLimit", 1000));

	SetMotd(Config.MainConfig.GetStringDefault("Server", "Motd", "Ascent Default MOTD").c_str());
	mQueueUpdateInterval = Config.MainConfig.GetIntDefault("Server", "QueueUpdateInterval", 5000);
	SetKickAFKPlayerTime(Config.MainConfig.GetIntDefault("Server", "KickAFKPlayers", 0));
	gm_skip_attunement = Config.MainConfig.GetBoolDefault("Server", "SkipAttunementsForGM", true);
	gm_force_robes = Config.MainConfig.GetBoolDefault("Server", "ForceRobesForGM", false);

	CheckProfessions = Config.MainConfig.GetBoolDefault("Server", "CheckProfessions", false);

#ifndef CLUSTERING
	SocketRecvBufSize = Config.MainConfig.GetIntDefault("WorldSocket", "RecvBufSize", WORLDSOCKET_RECVBUF_SIZE);
	SocketSendBufSize = Config.MainConfig.GetIntDefault("WorldSocket", "SendBufSize", WORLDSOCKET_SENDBUF_SIZE);
#endif

	bool log_enabled = Config.MainConfig.GetBoolDefault("Log", "Cheaters", false);
	if(Anticheat_Log->IsOpen())
	{
		if(!log_enabled)
			Anticheat_Log->Close();
	}
	else
		if(log_enabled)
			Anticheat_Log->Open();

	log_enabled = Config.MainConfig.GetBoolDefault("Log", "GMCommands", false);
	if(GMCommand_Log->IsOpen())
	{
		if(!log_enabled)
			GMCommand_Log->Close();
	}
	else
		if(log_enabled)
			GMCommand_Log->Open();

	log_enabled = Config.MainConfig.GetBoolDefault("Log", "Player", false);
	if(Player_Log->IsOpen())
	{
		if(!log_enabled)
			Player_Log->Close();
	}
	else
	{
		if(log_enabled)
			Player_Log->Open();
	}

#ifdef WIN32
	DWORD current_priority_class = GetPriorityClass( GetCurrentProcess() );
	bool high = Config.MainConfig.GetBoolDefault( "Server", "AdjustPriority", false );

	if( high )
	{
		if( current_priority_class != HIGH_PRIORITY_CLASS )
			SetPriorityClass( GetCurrentProcess(), HIGH_PRIORITY_CLASS );
	}
	else
	{
		if( current_priority_class != NORMAL_PRIORITY_CLASS )
			SetPriorityClass( GetCurrentProcess(), NORMAL_PRIORITY_CLASS );
	}
#endif

	if(!Config.MainConfig.GetString("GMClient", "GmClientChannel", &GmClientChannel))
	{
		GmClientChannel = "";
	}

	m_reqGmForCommands = !Config.MainConfig.GetBoolDefault("Server", "AllowPlayerCommands", false);
	m_lfgForNonLfg = Config.MainConfig.GetBoolDefault("Server", "EnableLFGJoin", false);

	realmtype = Config.MainConfig.GetBoolDefault("Server", "RealmType", false);
	TimeOut= uint32(1000* Config.MainConfig.GetIntDefault("Server", "ConnectionTimeout", 180) );

	uint32 config_flags = 0;
	if(Config.MainConfig.GetBoolDefault("Mail", "DisablePostageCostsForGM", true))
		config_flags |= MAIL_FLAG_NO_COST_FOR_GM;

	if(Config.MainConfig.GetBoolDefault("Mail", "DisablePostageCosts", false))
		config_flags |= MAIL_FLAG_DISABLE_POSTAGE_COSTS;

	if(Config.MainConfig.GetBoolDefault("Mail", "DisablePostageDelayItems", true))
		config_flags |= MAIL_FLAG_DISABLE_HOUR_DELAY_FOR_ITEMS;

	if(Config.MainConfig.GetBoolDefault("Mail", "DisableMessageExpiry", false))
		config_flags |= MAIL_FLAG_NO_EXPIRY;

	if(Config.MainConfig.GetBoolDefault("Mail", "EnableInterfactionMail", true))
		config_flags |= MAIL_FLAG_CAN_SEND_TO_OPPOSITE_FACTION;

	if(Config.MainConfig.GetBoolDefault("Mail", "EnableInterfactionForGM", true))
		config_flags |= MAIL_FLAG_CAN_SEND_TO_OPPOSITE_FACTION_GM;

	sMailSystem.config_flags = config_flags;
	flood_lines = Config.MainConfig.GetIntDefault("FloodProtection", "Lines", 0);
	flood_seconds = Config.MainConfig.GetIntDefault("FloodProtection", "Seconds", 0);
	flood_message = Config.MainConfig.GetBoolDefault("FloodProtection", "SendMessage", false);
	flood_message_time = Config.MainConfig.GetIntDefault("FloodProtection", "FloodMessageTime", 0);
	flood_mute_after_flood = Config.MainConfig.GetIntDefault("FloodProtection", "MuteAfterFlood", 0);
	flood_caps_min_len = Config.MainConfig.GetIntDefault("FloodProtection", "CapsMinLen", 0);
	flood_caps_pct = Config.MainConfig.GetFloatDefault("FloodProtection", "CapsPct", 0.0f);
	show_gm_in_who_list = Config.MainConfig.GetBoolDefault("Server", "ShowGMInWhoList", true);

	if(!flood_lines || !flood_seconds)
		flood_lines = flood_seconds = 0;

	map_unload_time=Config.MainConfig.GetIntDefault("Server", "MapUnloadTime", 0);
	cross_faction_world = Config.MainConfig.GetBoolDefault("Server", "CrossFactionInteraction", false);

	antihack_teleport = Config.MainConfig.GetBoolDefault("AntiHack", "Teleport", true);
	antihack_speed = Config.MainConfig.GetBoolDefault("AntiHack", "Speed", true);
	antihack_flight = Config.MainConfig.GetBoolDefault("AntiHack", "Flight", true);
	no_antihack_on_gm = Config.MainConfig.GetBoolDefault("AntiHack", "DisableOnGM", false);
	SpeedhackProtection = antihack_speed;
	m_limitedNames = Config.MainConfig.GetBoolDefault("Server", "LimitedNames", true);
	m_useAccountData = Config.MainConfig.GetBoolDefault("Server", "UseAccountData", false);

	// ======================================
	m_movementCompressInterval = Config.MainConfig.GetIntDefault("Movement", "FlushInterval", 1000);
	m_movementCompressRate = Config.MainConfig.GetIntDefault("Movement", "CompressRate", 1);
	
	m_movementCompressThresholdCreatures = Config.MainConfig.GetFloatDefault("Movement", "CompressThresholdCreatures", 15.0f);
	m_movementCompressThresholdCreatures *= m_movementCompressThresholdCreatures;

	m_movementCompressThreshold = Config.MainConfig.GetFloatDefault("Movement", "CompressThreshold", 25.0f);
	m_movementCompressThreshold *= m_movementCompressThreshold;		// square it to avoid sqrt() on checks

	m_speedHackThreshold = Config.MainConfig.GetFloatDefault("AntiHack", "SpeedThreshold", -500.0f);
	m_speedHackLatencyMultiplier = Config.MainConfig.GetFloatDefault("AntiHack", "SpeedLatencyCompensation", 0.25f);
	m_speedHackResetInterval = Config.MainConfig.GetIntDefault("AntiHack", "SpeedResetPeriod", 5000);
	antihack_cheatengine = Config.MainConfig.GetBoolDefault("AntiHack", "CheatEngine", false);
	m_CEThreshold = Config.MainConfig.GetIntDefault("AntiHack", "CheatEngineTimeDiff", 10000);
	m_wallhackthreshold = Config.MainConfig.GetFloatDefault("AntiHack", "WallHackThreshold", 5.0f);
	// ======================================

	m_deathKnightOnePerAccount = Config.MainConfig.GetBoolDefault("DeathKnight", "OnePerRealm", true);
	m_deathKnightReqLevel = Config.MainConfig.GetIntDefault("DeathKnight", "RequiredLevel", 55);


	// LevelCaps
	LevelCap_Custom_All = Config.MainConfig.GetIntDefault("Server", "LevelCap_Custom_All", 0);

	if( m_banTable != NULL )
		free( m_banTable );

	m_banTable = NULL;
	string s = Config.MainConfig.GetStringDefault( "Server", "BanTable", "" );
	if( !s.empty() )
		m_banTable = strdup( s.c_str() );

	if( load )
		Channel::LoadConfSettings();
}

void World::LoadNameGenData()
{
	DBCFile dbc;

	if( !dbc.open( "DBC/NameGen.dbc" ) )
	{
		Log.Error( "World", "Cannot find file ./DBC/NameGen.dbc" );
		return;
	}

	for(uint32 i = 0; i < dbc.getRecordCount(); ++i)
	{
		NameGenData d;
		if(dbc.getRecord(i).getString(1)==NULL)
			continue;

		d.name = string(dbc.getRecord(i).getString(1));
		d.type = dbc.getRecord(i).getUInt(3);
		_namegendata[d.type].push_back(d);
	}
}

void World::CharacterEnumProc(QueryResultVector& results, uint32 AccountId)
{
	WorldSession * s = FindSession(AccountId);
	if(s == NULL)
		return;

	s->CharacterEnumProc(results[0].result);
}

void World::LoadAccountDataProc(QueryResultVector& results, uint32 AccountId)
{
	WorldSession * s = FindSession(AccountId);
	if(s == NULL)
		return;

	s->LoadAccountDataProc(results[0].result);
}

void World::CheckForExpiredInstances()
{
	sInstanceMgr.CheckForExpiredInstances();
}

#define LOAD_THREAD_SLEEP 180

void CharacterLoaderThread::OnShutdown()
{
#ifdef WIN32
	SetEvent(hEvent);
#else
	pthread_cond_signal(&cond);
#endif
	m_threadRunning = false;
}

CharacterLoaderThread::CharacterLoaderThread()
{

}

CharacterLoaderThread::~CharacterLoaderThread()
{
#ifdef WIN32
	CloseHandle(hEvent);
#else
	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&mutex);
#endif
}

struct insert_playeritem
{
	uint32 ownerguid;
	uint32 entry;
	uint32 wrapped_item_id;
	uint32 wrapped_creator;
	uint32 creator;
	uint32 count;
	uint32 charges;
	uint32 flags;
	uint32 randomprop;
	uint32 randomsuffix;
	uint32 itemtext;
	uint32 durability;
	int32 containerslot;
	int32 slot;
	string enchantments;
};

bool CharacterLoaderThread::run()
{
	SetThreadName("Char Loader");
#ifdef WIN32
	hEvent = CreateEvent(NULL,FALSE,FALSE,NULL);
#else
	struct timeval now;
	struct timespec tv;

	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);
#endif
	for(;;)
	{
		// Get a single connection to maintain for the whole process.
		DatabaseConnection * con = CharacterDatabase.GetFreeConnection();

		// this hasn't been updated in some time, enable it if you want to fix/use it
#if 0
		sWorld.PollCharacterInsertQueue(con);
#endif

		sWorld.PollMailboxInsertQueue(con);
		/* While this looks weird, it ensures the system doesn't waste time switching to these contexts.
		WaitForSingleObject will suspend the thread,
		and on unix, select will as well. - Burlex
		*/
		con->Busy.Release();
#ifdef WIN32
		if (hEvent)
			WaitForSingleObject(hEvent,LOAD_THREAD_SLEEP*1000);
#else
		gettimeofday(&now, NULL);
		tv.tv_sec = now.tv_sec + LOAD_THREAD_SLEEP;
		tv.tv_nsec = now.tv_usec * 1000;
		pthread_mutex_lock(&mutex);
		pthread_cond_timedwait(&cond, &mutex, &tv);
		pthread_mutex_unlock(&mutex);
#endif
		if(!m_threadRunning)
			break;
	}

	return true;
}

void World::PollMailboxInsertQueue(DatabaseConnection * con)
{
	QueryResult * result;
	Field * f;
	ItemPointer pItem;
	uint32 itemid;
	uint32 stackcount;

	result = CharacterDatabase.FQuery("SELECT * FROM mailbox_insert_queue", con);
	if( result != NULL )
	{
		Log.Notice("MailboxQueue", "Sending queued messages....");
		do 
		{
			f = result->Fetch();
			itemid = f[6].GetUInt32();
			stackcount = f[7].GetUInt32();

			if( itemid != 0 )
			{
				pItem = objmgr.CreateItem( itemid, NULLPLR );
				if( pItem != NULL )
				{
					pItem->SetUInt32Value( ITEM_FIELD_STACK_COUNT, stackcount );
					pItem->SaveToDB( 0, 0, true, NULL );
				}
			}
			else
				pItem = NULLITEM;

			Log.Notice("MailboxQueue", "Sending message to %u (item: %u)...", f[1].GetUInt32(), itemid);
			sMailSystem.DeliverMessage( 0, f[0].GetUInt64(), f[1].GetUInt64(), f[2].GetString(), f[3].GetString(), f[5].GetUInt32(),
				0, pItem ? pItem->GetGUID() : 0, f[4].GetUInt32(), true );

			if( pItem != NULL )
			{
				pItem->Destructor();
				pItem = NULLITEM;
			}

		} while ( result->NextRow() );
		delete result;
		Log.Notice("MailboxQueue", "Done.");
		CharacterDatabase.FWaitExecute("DELETE FROM mailbox_insert_queue", con);
	}
}

void World::PollCharacterInsertQueue(DatabaseConnection * con)
{
	// Our local stuff..
	bool has_results = false;
	map<uint32, vector<insert_playeritem> > itemMap;
	map<uint32,vector<insert_playeritem> >::iterator itr;
	Field * f;
	insert_playeritem ipi;                          
	static const char * characterTableFormat = "uSuuuuuussuuuuuuuuuuuuuuffffuususuufffuuuuusuuuUssuuuuuuffffuuuuufffssssssuuuuuuuu";

	// Lock the table to prevent any more inserts
	CharacterDatabase.FWaitExecute("LOCK TABLES `playeritems_insert_queue` WRITE", con);

	// Cache all items in memory. This will save us doing additional queries and slowing down the db.
	QueryResult * result = CharacterDatabase.FQuery("SELECT * FROM playeritems_insert_queue", con);
	if(result)
	{
		do 
		{
			f = result->Fetch();

			ipi.ownerguid = f[0].GetUInt32();
			ipi.entry = f[1].GetUInt32();
			ipi.wrapped_item_id = f[2].GetUInt32();
			ipi.wrapped_creator = f[3].GetUInt32();
			ipi.creator = f[4].GetUInt32();
			ipi.count = f[5].GetUInt32();
			ipi.charges = f[6].GetUInt32();
			ipi.flags = f[7].GetUInt32();
			ipi.randomprop = f[8].GetUInt32();
			ipi.randomsuffix = f[9].GetUInt32();
			ipi.itemtext = f[10].GetUInt32();
			ipi.durability = f[11].GetUInt32();
			ipi.containerslot = f[12].GetInt32();
			ipi.slot = f[13].GetInt32();
			ipi.enchantments = string(f[14].GetString());

			itr = itemMap.find(ipi.ownerguid);
			if(itr == itemMap.end())
			{
				vector<insert_playeritem> to_insert;
				to_insert.push_back(ipi);
				itemMap.insert(make_pair(ipi.ownerguid,to_insert));
			}
			else
			{
				itr->second.push_back(ipi);
			}

		} while(result->NextRow());
		delete result;
	}

	// Unlock the item table
	CharacterDatabase.FWaitExecute("UNLOCK TABLES", con);

	// Lock the character table
	CharacterDatabase.FWaitExecute("LOCK TABLES `characters_insert_queue` WRITE", con);

	// Load the characters, and assign them their new guids, and insert them into the main db.
	result = CharacterDatabase.FQuery("SELECT * FROM characters_insert_queue", con);

	// Can be unlocked now.
	CharacterDatabase.FWaitExecute("UNLOCK TABLES", con);

	if(result)
	{
		uint32 guid;
		std::stringstream ss;
		do 
		{
			f = result->Fetch();
			char * p = (char*)characterTableFormat;
			uint32 i = 1;
			guid = f[0].GetUInt32();
			uint32 new_guid = objmgr.GenerateLowGuid(HIGHGUID_TYPE_PLAYER);
			uint32 new_item_guid;
			ss << "INSERT INTO characters VALUES(" << new_guid;

			// create his playerinfo in the server
			PlayerInfo * inf = new PlayerInfo();
			inf->acct = f[1].GetUInt32();
#ifdef VOICE_CHAT
			inf->groupVoiceId = -1;
#endif

			while(*p != 0)
			{
				switch(*p)
				{
				case 's':
					ss << ",'" << CharacterDatabase.EscapeString(f[i].GetString(), con) << "'";
					break;

				case 'f':
					ss << ",'" << f[i].GetFloat() << "'";
					break;

				case 'S':
					{
						// this is the character name, append a hex version of the guid to it to prevent name clashes.
						char newname[100];
						snprintf(newname,20,"%5s%X",f[i].GetString(),new_guid);
						ss << ",'" << CharacterDatabase.EscapeString(newname,con) << "'";
						inf->name = strdup(newname);
					}break;

				case 'U':
					{
						// this is our forced rename field. force it to one.
						ss << ",1";
					}break;

				default:
					ss << "," << f[i].GetUInt32();
					break;
				}

				++i;
				++p;
			}

			ss << ")";
			CharacterDatabase.FWaitExecute(ss.str().c_str(),con);

			inf->cl = f[4].GetUInt32();
			inf->gender = f[5].GetUInt32();
			inf->guid = new_guid;
			inf->lastLevel = f[7].GetUInt32();
			inf->lastOnline = UNIXTIME;
			inf->lastZone = 0;
			inf->m_Group=NULL;
			inf->m_loggedInPlayer=NULLPLR;
			inf->guild=NULL;
			inf->guildRank=NULL;
			inf->guildMember=NULL;
			inf->race=f[3].GetUInt32();
			inf->subGroup=0;
			switch(inf->race)
			{
			case RACE_HUMAN:
			case RACE_GNOME:
			case RACE_DWARF:
			case RACE_NIGHTELF:
			case RACE_DRAENEI:
				inf->team=0;
				break;

			default:
				inf->team=1;
				break;
			}

			// add playerinfo to objectmgr
			objmgr.AddPlayerInfo(inf);

			// grab all his items, assign them their new guids and insert them
			itr = itemMap.find(guid);
			if(itr != itemMap.end())
			{
				for(vector<insert_playeritem>::iterator vtr = itr->second.begin(); vtr != itr->second.end(); ++vtr)
				{
					ss.rdbuf()->str("");
					ss << "INSERT INTO playeritems VALUES(";
					new_item_guid = objmgr.GenerateLowGuid(HIGHGUID_TYPE_ITEM);
					ss << new_guid << ","
						<< new_item_guid << ","
						<< (*vtr).entry << ","
						<< (*vtr).wrapped_item_id << ","
						<< (*vtr).wrapped_creator << ","
						<< (*vtr).creator << ","
						<< (*vtr).count << ","
						<< (*vtr).charges << ","
						<< (*vtr).flags << ","
						<< (*vtr).randomprop << ","
						<< (*vtr).randomsuffix << ","
						<< (*vtr).itemtext << ","
						<< (*vtr).durability << ","
						<< (*vtr).containerslot << ","
						<< (*vtr).slot << ",'"
						<< (*vtr).enchantments << "')";
					CharacterDatabase.FWaitExecute(ss.str().c_str(),con);
				}
			}
			ss.rdbuf()->str("");
		} while(result->NextRow());
		has_results = true;
		delete result;
	}

	// Clear all the data in the tables.
	if(has_results)
	{
		CharacterDatabase.FWaitExecute("DELETE FROM characters_insert_queue", con);
		CharacterDatabase.FWaitExecute("DELETE FROM playeritems_insert_queue", con);
	}
}

void World::DisconnectUsersWithAccount(const char * account, WorldSession * m_session)
{
	SessionMap::iterator itr;
	WorldSession * worldsession;
	m_sessionlock.AcquireReadLock();
	for(itr = m_sessions.begin(); itr != m_sessions.end();)
	{
		worldsession = (itr->second);
		++itr;

		if(!stricmp(account, worldsession->GetAccountNameS()))
		{
			m_session->SystemMessage("Disconnecting user with account `%s` IP `%s` Player `%s`.", worldsession->GetAccountNameS(), 
				worldsession->GetSocket() ? worldsession->GetSocket()->GetRemoteIP().c_str() : "noip", worldsession->GetPlayer() ? worldsession->GetPlayer()->GetName() : "noplayer");

			worldsession->Disconnect();
		}
	}
	m_sessionlock.ReleaseReadLock();
}

void World::DisconnectUsersWithIP(const char * ip, WorldSession * m_session)
{
	SessionMap::iterator itr;
	WorldSession * worldsession;
	m_sessionlock.AcquireReadLock();
	for(itr = m_sessions.begin(); itr != m_sessions.end();)
	{
		worldsession = (itr->second);
		++itr;

		if(!worldsession->GetSocket())
			continue;

		string ip2 = worldsession->GetSocket()->GetRemoteIP().c_str();
		if(!stricmp(ip, ip2.c_str()))
		{
			m_session->SystemMessage("Disconnecting user with account `%s` IP `%s` Player `%s`.", worldsession->GetAccountNameS(), 
				ip2.c_str(), worldsession->GetPlayer() ? worldsession->GetPlayer()->GetName() : "noplayer");

			worldsession->Disconnect();
		}
	}
	m_sessionlock.ReleaseReadLock();
}

void World::DisconnectUsersWithPlayerName(const char * plr, WorldSession * m_session)
{
	SessionMap::iterator itr;
	WorldSession * worldsession;
	m_sessionlock.AcquireReadLock();
	for(itr = m_sessions.begin(); itr != m_sessions.end();)
	{
		worldsession = (itr->second);
		++itr;

		if(!worldsession->GetPlayer())
			continue;

		if(!stricmp(plr, worldsession->GetPlayer()->GetName()))
		{
			m_session->SystemMessage("Disconnecting user with account `%s` IP `%s` Player `%s`.", worldsession->GetAccountNameS(), 
				worldsession->GetSocket() ? worldsession->GetSocket()->GetRemoteIP().c_str() : "noip", worldsession->GetPlayer() ? worldsession->GetPlayer()->GetName() : "noplayer");

			worldsession->Disconnect();
		}
	}
	m_sessionlock.ReleaseReadLock();
}

string World::GetUptimeString()
{
	char str[300];
	time_t pTime = (time_t)UNIXTIME - m_StartTime;
	tm * tmv = gmtime(&pTime);

	snprintf(str, 300, "%u days, %u hours, %u minutes, %u seconds.", tmv->tm_yday, tmv->tm_hour, tmv->tm_min, tmv->tm_sec);
	return string(str);
}

void World::UpdateShutdownStatus()
{
	uint32 time_left = ((uint32)UNIXTIME > m_shutdownTime) ? 0 : m_shutdownTime - (uint32)UNIXTIME;
	uint32 time_period = 1;

	if( time_left && m_shutdownTime )
	{
		// determine period
		if( time_left <= 30 )
		{
			// every 1 sec
			time_period = 1;
		}
		else if( time_left <= (TIME_MINUTE * 2) )
		{
			// every 30 secs
			time_period = 30;
		}
		else
		{
			// every minute
			time_period = 60;
		}

		// time to send a new packet?
		if( ( (uint32)UNIXTIME - m_shutdownLastTime ) >= time_period )
		{
			// send message
			m_shutdownLastTime = (uint32)UNIXTIME;

			WorldPacket data(SMSG_SERVER_MESSAGE, 200);
			if( m_shutdownType == SERVER_SHUTDOWN_TYPE_RESTART )
				data << uint32(SERVER_MSG_RESTART_TIME);
			else
				data << uint32(SERVER_MSG_SHUTDOWN_TIME);

			char tbuf[100];
			snprintf(tbuf, 100, "%02u:%02u", (time_left / 60), (time_left % 60));
			data << tbuf;
			SendGlobalMessage(&data, NULL);

			printf("Server shutdown in %s.\n", tbuf);
		}
	}
	else
	{
		// shutting down?
		sEventMgr.RemoveEvents(CAST(World,shared_from_this()), EVENT_WORLD_SHUTDOWN);
		if( m_shutdownTime )
		{
			SendWorldText("Server is saving and shutting down. You will be disconnected shortly.", NULL);
			Master::m_stopEvent = true;
		}
		else
		{
			WorldPacket data(SMSG_SERVER_MESSAGE, 200);
			if( m_shutdownTime == SERVER_SHUTDOWN_TYPE_RESTART )
				data << uint32(SERVER_MSG_RESTART_CANCELLED);
			else
				data << uint32(SERVER_MSG_SHUTDOWN_CANCELLED);

			data << uint8(0);
			SendGlobalMessage(&data, NULL);
		}
	}
}

void World::CancelShutdown()
{
	m_shutdownTime = 0;
	m_shutdownType = 0;
	m_shutdownLastTime = 0;
}

void World::QueueShutdown(uint32 delay, uint32 type)
{
	// set parameters
	m_shutdownLastTime = 0;
	m_shutdownTime = (uint32)UNIXTIME + delay;
	m_shutdownType = type;

	// add event
	sEventMgr.AddEvent(CAST(World,shared_from_this()), &World::UpdateShutdownStatus, EVENT_WORLD_SHUTDOWN, 50, 0, 0);

	// send message
	char buf[1000];
	snprintf(buf, 1000, "Server %s initiated. Server will save and shut down in approx. %u seconds.", type == SERVER_SHUTDOWN_TYPE_RESTART ? "restart" : "shutdown", delay);
	SendWorldText(buf, NULL);
}


void World::BackupDB()
{
#ifndef WIN32
	const char *tables[] =
	{ "account_data", "account_forced_permissions", "achievements", "arenateams", "auctions",
	  "banned_names", "characters", "characters_insert_queue", "charters", "corpses", "gm_tickets",
	  "groups", "guild_bankitems", "guild_banklogs", "guild_banktabs",
	  "guild_data", "guild_logs", "guild_ranks", "guilds",
	  "instances", "mailbox", "mailbox_insert_queue", "news_timers",
	  "playercooldowns", "playeritems", "playeritems_insert_queue", "playerpets",
	  "playerpetspells", "playersummons", "playersummonspells", "questlog",
	  "server_settings", "social_friends", "social_ignores", "tutorials",
	  "worldstate_save_data", NULL };
	char cmd[1024];
	char datestr[256];
	char path[256];
	std::string user, pass;
	std::string host, name;
	struct tm tm;
	time_t t;
	int i;

	user = Config.MainConfig.GetStringDefault("CharacterDatabase", "Username", "");
	pass = Config.MainConfig.GetStringDefault("CharacterDatabase", "Password", "");
	host = Config.MainConfig.GetStringDefault("CharacterDatabase", "Hostname", "");
	name = Config.MainConfig.GetStringDefault("CharacterDatabase", "Name", "");
	t = time(NULL);
	localtime_r(&t, &tm);
	strftime(datestr, 256, "%Y.%m.%d", &tm);

	snprintf(path, 256, "bk/%s", datestr);
	snprintf(cmd, 1024, "mkdir -p %s", path);

	sLog.outString("Backing up character db into %s", path);

	for (i=0; tables[i] != NULL; i++)
	{
		snprintf(cmd, 1024, "mkdir -p %s", path);
		system(cmd);

		snprintf(cmd, 1024, "mysqldump -u\"%s\" -p\"%s\" -h\"%s\" --result-file=\"%s/%s.sql\" \"%s\" \"%s\"", user.c_str(), pass.c_str(), host.c_str(), path, tables[i], name.c_str(), tables[i]);
		system(cmd);
	}

	sLog.outString("Done!");
#endif
}

//////////////////////////////////////////////////////////////////////////
// News Announcer
//////////////////////////////////////////////////////////////////////////

bool NewsAnnouncer::run()
{
	SetThreadName("News Announcer");

	map<uint32, NewsAnnouncement>::iterator itr;
	uint32 last_load_time = 0;

	// init
	_Init();
	last_load_time = (uint32)UNIXTIME;

	while(m_threadRunning)
	{
		// loop through messages
		for( itr = m_announcements.begin(); itr != m_announcements.end(); ++itr )
		{
			// it can be send time pl0x?
			if( ((uint32)UNIXTIME - itr->second.m_lastTime) >= itr->second.m_timePeriod )
				_SendMessage(&itr->second);
		}

		if( ((uint32)UNIXTIME - last_load_time) > 120 )			// reload every 2 minutes
			_ReloadMessages();

		// sleep
		Sleep(10000);
	}

	// delete us :P
	return true;
}

void NewsAnnouncer::_SendMessage(NewsAnnouncement *ann)
{
	char buf[10000];

	// fill out the message buffer
	buf[0] = 0;
	strcat(buf, MSG_COLOR_WHITE"Server News:|r ");
	strcat(buf, ann->m_message.c_str());

	// build the packet
	WorldPacket *data_to_send = sChatHandler.FillSystemMessageData(buf);

	// send to sessions
	if( ann->m_factionMask < 0 )
	{
		// send to all
		sWorld.SendGlobalMessage(data_to_send, NULL);
	}
	else
	{
		// send to team
		sWorld.SendFactionMessage(data_to_send, ann->m_factionMask);
	}

	// update last time
	ann->m_lastTime = (uint32)UNIXTIME;
	CharacterDatabase.Execute("REPLACE INTO news_timers VALUES(%u, %u)", ann->m_id, ann->m_lastTime);

	// send it to the console too
	puts(buf);
}

void NewsAnnouncer::_ReloadMessages()
{
	QueryResult *res;
	NewsAnnouncement ann;
	map<uint32, NewsAnnouncement>::iterator itr, itr2;
	set<uint32> db_msgs;
	Field *f;
	uint32 id;

	// query db
	res = WorldDatabase.Query("SELECT * FROM news_announcements");

	if( res != NULL )
	{
		do 
		{
			f = res->Fetch();
			id = f[0].GetUInt32();

			// create structure/update structure
			db_msgs.insert(id);
			itr = m_announcements.find(id);
			if( itr == m_announcements.end() )
			{
				ann.m_id = id;
				ann.m_factionMask = f[1].GetInt32();
				ann.m_timePeriod = f[2].GetUInt32();
				ann.m_lastTime = (uint32)UNIXTIME;
				ann.m_message = f[3].GetString();
				m_announcements.insert(make_pair(ann.m_id, ann));
			}
			else
			{
				// update
				itr->second.m_factionMask = f[1].GetInt32();
				itr->second.m_timePeriod = f[2].GetUInt32();
				itr->second.m_message = f[3].GetString();
			}

		} while (res->NextRow());
		delete res;
	}

	for(itr = m_announcements.begin(); itr != m_announcements.end();)
	{
		itr2 = itr++;
		if( db_msgs.find(itr2->second.m_id) == db_msgs.end() )
		{
			// message no longer exists
			CharacterDatabase.Execute("DELETE FROM news_timers WHERE id = %u", itr2->second.m_id);
			m_announcements.erase(itr2);
		}
	}
}

void NewsAnnouncer::_Init()
{
	// load messages
	_ReloadMessages();

	// get initial last timestamps
	QueryResult *res = CharacterDatabase.Query("SELECT * FROM news_timers");
	if( res != NULL )
	{
		do 
		{
			uint32 id = res->Fetch()[0].GetUInt32();
			uint32 t = res->Fetch()[1].GetUInt32();

			// update "last" timestamp
			map<uint32, NewsAnnouncement>::iterator itr = m_announcements.find(id);
			if( itr == m_announcements.end() )
				CharacterDatabase.Execute("DELETE FROM news_timers WHERE id = %u", id);
			else
				itr->second.m_lastTime = t;

		} while (res->NextRow());
		delete res;
	}
}
