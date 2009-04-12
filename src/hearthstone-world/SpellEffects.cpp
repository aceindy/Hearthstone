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

// thank god for macros

#include "StdAfx.h"

#define CREATESPELL(caster,info,triggered,aur) \
	SpellPointer(new Spell( caster, info, triggered, (aur == NULL ? NULLAURA : aur)));

pSpellEffect SpellEffectsHandler[TOTAL_SPELL_EFFECTS]={
		&Spell::SpellEffectNULL,//SPELL_EFFECT_NULL - 0
		&Spell::SpellEffectInstantKill,//SPELL_EFFECT_INSTAKILL - 1
		&Spell::SpellEffectSchoolDMG,//SPELL_EFFECT_SCHOOL_DAMAGE - 2
		&Spell::SpellEffectDummy,//SPELL_EFFECT_DUMMY - 3
		&Spell::SpellEffectNULL,//SPELL_EFFECT_PORTAL_TELEPORT - 4
		&Spell::SpellEffectTeleportUnits,//SPELL_EFFECT_TELEPORT_UNITS - 5
		&Spell::SpellEffectApplyAura,//SPELL_EFFECT_APPLY_AURA - 6
		&Spell::SpellEffectEnvironmentalDamage,//SPELL_EFFECT_ENVIRONMENTAL_DAMAGE - 7
		&Spell::SpellEffectPowerDrain,//SPELL_EFFECT_POWER_DRAIN - 8
		&Spell::SpellEffectHealthLeech,//SPELL_EFFECT_HEALTH_LEECH - 9
		&Spell::SpellEffectHeal,//SPELL_EFFECT_HEAL - 10
		&Spell::SpellEffectNULL,//SPELL_EFFECT_BIND - 11
		&Spell::SpellEffectNULL,//SPELL_EFFECT_PORTAL - 12
		&Spell::SpellEffectNULL,//SPELL_EFFECT_RITUAL_BASE - 13
		&Spell::SpellEffectNULL,//SPELL_EFFECT_RITUAL_SPECIALIZE - 14
		&Spell::SpellEffectNULL,//SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL - 15
		&Spell::SpellEffectQuestComplete,//SPELL_EFFECT_QUEST_COMPLETE - 16
		&Spell::SpellEffectWeapondamageNoschool,//SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL - 17
		&Spell::SpellEffectResurrect,//SPELL_EFFECT_RESURRECT - 18
		&Spell::SpellEffectAddExtraAttacks,//SPELL_EFFECT_ADD_EXTRA_ATTACKS - 19
		&Spell::SpellEffectDodge,//SPELL_EFFECT_DODGE - 20
		&Spell::SpellEffectNULL,//SPELL_EFFECT_EVADE - 21
		&Spell::SpellEffectParry,//SPELL_EFFECT_PARRY - 22
		&Spell::SpellEffectBlock,//SPELL_EFFECT_BLOCK - 23
		&Spell::SpellEffectCreateItem,//SPELL_EFFECT_CREATE_ITEM - 24
		&Spell::SpellEffectWeapon,//SPELL_EFFECT_WEAPON - 25
		&Spell::SpellEffectDefense,//SPELL_EFFECT_DEFENSE - 26
		&Spell::SpellEffectPersistentAA,//SPELL_EFFECT_PERSISTENT_AREA_AURA - 27
		&Spell::SpellEffectSummon,//SPELL_EFFECT_SUMMON - 28
		&Spell::SpellEffectLeap,//SPELL_EFFECT_LEAP - 29
		&Spell::SpellEffectEnergize,//SPELL_EFFECT_ENERGIZE - 30
		&Spell::SpellEffectWeaponDmgPerc,//SPELL_EFFECT_WEAPON_PERCENT_DAMAGE - 31
		&Spell::SpellEffectTriggerMissile,//SPELL_EFFECT_TRIGGER_MISSILE - 32
		&Spell::SpellEffectOpenLock,//SPELL_EFFECT_OPEN_LOCK - 33
		&Spell::SpellEffectTranformItem,//SPELL_EFFECT_TRANSFORM_ITEM - 34
		&Spell::SpellEffectApplyAA,//SPELL_EFFECT_APPLY_AREA_AURA - 35
		&Spell::SpellEffectLearnSpell,//SPELL_EFFECT_LEARN_SPELL - 36
		&Spell::SpellEffectSpellDefense,//SPELL_EFFECT_SPELL_DEFENSE - 37
		&Spell::SpellEffectDispel,//SPELL_EFFECT_DISPEL - 38
		&Spell::SpellEffectNULL,//SPELL_EFFECT_LANGUAGE - 39
		&Spell::SpellEffectDualWield,//SPELL_EFFECT_DUAL_WIELD - 40
		&Spell::SpellEffectNULL,//SPELL_EFFECT_SUMMON_WILD - 41
		&Spell::SpellEffectMegaJump,//SPELL_EFFECT_SUMMON_GUARDIAN - 42
		&Spell::SpellEffectNULL,//SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER - 43
		&Spell::SpellEffectSkillStep,//SPELL_EFFECT_SKILL_STEP - 44
		&Spell::SpellEffectAddHonor,//SPELL_ADD_HONOR - 45
		&Spell::SpellEffectSpawn,//SPELL_EFFECT_SPAWN - 46
		&Spell::SpellEffectNULL,//SPELL_EFFECT_TRADE_SKILL - 47
		&Spell::SpellEffectNULL,//SPELL_EFFECT_STEALTH - 48
		&Spell::SpellEffectNULL,//SPELL_EFFECT_DETECT - 49
		&Spell::SpellEffectSummonObject,//SPELL_EFFECT_SUMMON_OBJECT - 50
		&Spell::SpellEffectNULL,//SPELL_EFFECT_FORCE_CRITICAL_HIT - 51 NA
		&Spell::SpellEffectNULL,//SPELL_EFFECT_GUARANTEE_HIT - 52 NA
		&Spell::SpellEffectEnchantItem,//SPELL_EFFECT_ENCHANT_ITEM - 53
		&Spell::SpellEffectEnchantItemTemporary,//SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY - 54
		&Spell::SpellEffectTameCreature,//SPELL_EFFECT_TAMECREATURE - 55
		&Spell::SpellEffectSummonPet,//SPELL_EFFECT_SUMMON_PET	- 56
		&Spell::SpellEffectLearnPetSpell,//SPELL_EFFECT_LEARN_PET_SPELL - 57
		&Spell::SpellEffectWeapondamage,//SPELL_EFFECT_WEAPON_DAMAGE - 58
		&Spell::SpellEffectOpenLockItem,//SPELL_EFFECT_OPEN_LOCK_ITEM - 59
		&Spell::SpellEffectProficiency,//SPELL_EFFECT_PROFICIENCY - 60
		&Spell::SpellEffectSendEvent,//SPELL_EFFECT_SEND_EVENT - 61
		&Spell::SpellEffectPowerBurn,//SPELL_EFFECT_POWER_BURN - 62
		&Spell::SpellEffectThreat,//SPELL_EFFECT_THREAT - 63
		&Spell::SpellEffectTriggerSpell,//SPELL_EFFECT_TRIGGER_SPELL - 64
		&Spell::SpellEffectHealthFunnel,//SPELL_EFFECT_HEALTH_FUNNEL - 65
		&Spell::SpellEffectPowerFunnel,//SPELL_EFFECT_POWER_FUNNEL - 66
		&Spell::SpellEffectHealMaxHealth,//SPELL_EFFECT_HEAL_MAX_HEALTH - 67
		&Spell::SpellEffectInterruptCast,//SPELL_EFFECT_INTERRUPT_CAST - 68
		&Spell::SpellEffectDistract,//SPELL_EFFECT_DISTRACT - 69
		&Spell::SpellEffectNULL,//SPELL_EFFECT_PULL - 70
		&Spell::SpellEffectPickpocket,//SPELL_EFFECT_PICKPOCKET - 71
		&Spell::SpellEffectAddFarsight,//SPELL_EFFECT_ADD_FARSIGHT - 72
		&Spell::SpellEffectNULL,//SPELL_EFFECT_SUMMON_POSSESSED - 73
		&Spell::SpellEffectUseGlyph,//SPELL_EFFECT_USE_GLYPH - 74
		&Spell::SpellEffectHealMechanical,//SPELL_EFFECT_HEAL_MECHANICAL - 75
		&Spell::SpellEffectNULL,//SPELL_EFFECT_SUMMON_OBJECT_WILD - 76
		&Spell::SpellEffectScriptEffect,//SPELL_EFFECT_SCRIPT_EFFECT - 77
		&Spell::SpellEffectNULL,//SPELL_EFFECT_ATTACK - 78
		&Spell::SpellEffectSanctuary,//SPELL_EFFECT_SANCTUARY - 79
		&Spell::SpellEffectAddComboPoints,//SPELL_EFFECT_ADD_COMBO_POINTS - 80
		&Spell::SpellEffectCreateHouse,//SPELL_EFFECT_CREATE_HOUSE - 81
		&Spell::SpellEffectNULL,//SPELL_EFFECT_BIND_SIGHT - 82
		&Spell::SpellEffectDuel,//SPELL_EFFECT_DUEL - 83
		&Spell::SpellEffectStuck,//SPELL_EFFECT_STUCK - 84
		&Spell::SpellEffectSummonPlayer,//SPELL_EFFECT_SUMMON_PLAYER - 85
		&Spell::SpellEffectActivateObject,//SPELL_EFFECT_ACTIVATE_OBJECT - 86
		&Spell::SpellEffectNULL,//SPELL_EFFECT_SUMMON_TOTEM_SLOT1 - 87
		&Spell::SpellEffectNULL,//SPELL_EFFECT_SUMMON_TOTEM_SLOT2 - 88
		&Spell::SpellEffectNULL,//SPELL_EFFECT_SUMMON_TOTEM_SLOT3 - 89
		&Spell::SpellEffectNULL,//SPELL_EFFECT_SUMMON_TOTEM_SLOT4 - 90
		&Spell::SpellEffectNULL,//SPELL_EFFECT_THREAT_ALL - 91 UNUSED
		&Spell::SpellEffectEnchantHeldItem,//SPELL_EFFECT_ENCHANT_HELD_ITEM - 92
		&Spell::SpellEffectNULL,//SPELL_EFFECT_SUMMON_PHANTASM - 93 OLD
		&Spell::SpellEffectSelfResurrect,//SPELL_EFFECT_SELF_RESURRECT - 94
		&Spell::SpellEffectSkinning,//SPELL_EFFECT_SKINNING - 95
		&Spell::SpellEffectCharge,//SPELL_EFFECT_CHARGE - 96
		&Spell::SpellEffectNULL,//SPELL_EFFECT_SUMMON_CRITTER - 97
		&Spell::SpellEffectKnockBack,//SPELL_EFFECT_KNOCK_BACK - 98
		&Spell::SpellEffectDisenchant,//SPELL_EFFECT_DISENCHANT - 99
		&Spell::SpellEffectInebriate,//SPELL_EFFECT_INEBRIATE - 100
		&Spell::SpellEffectFeedPet,//SPELL_EFFECT_FEED_PET - 101
		&Spell::SpellEffectDismissPet,//SPELL_EFFECT_DISMISS_PET - 102
		&Spell::SpellEffectReputation,//SPELL_EFFECT_REPUTATION - 103
		&Spell::SpellEffectSummonObjectSlot,//SPELL_EFFECT_SUMMON_OBJECT_SLOT1 - 104
		&Spell::SpellEffectSummonObjectSlot,//SPELL_EFFECT_SUMMON_OBJECT_SLOT2 - 105
		&Spell::SpellEffectSummonObjectSlot,//SPELL_EFFECT_SUMMON_OBJECT_SLOT3 - 106
		&Spell::SpellEffectSummonObjectSlot,//SPELL_EFFECT_SUMMON_OBJECT_SLOT4 - 107
		&Spell::SpellEffectDispelMechanic,//SPELL_EFFECT_DISPEL_MECHANIC - 108
		&Spell::SpellEffectSummonDeadPet,//SPELL_EFFECT_SUMMON_DEAD_PET - 109
		&Spell::SpellEffectDestroyAllTotems,//SPELL_EFFECT_DESTROY_ALL_TOTEMS - 110
		&Spell::SpellEffectNULL,//SPELL_EFFECT_DURABILITY_DAMAGE - 111
		&Spell::SpellEffectNULL,//SPELL_EFFECT_SUMMON_DEMON - 112
		&Spell::SpellEffectResurrectNew,//SPELL_EFFECT_RESURRECT_NEW - 113
		&Spell::SpellEffectAttackMe,//SPELL_EFFECT_ATTACK_ME - 114
		&Spell::SpellEffectNULL,//SPELL_EFFECT_DURABILITY_DAMAGE_PCT - 115
		&Spell::SpellEffectSkinPlayerCorpse,//SPELL_EFFECT_SKIN_PLAYER_CORPSE - 116
		&Spell::SpellEffectNULL,//SPELL_EFFECT_SPIRIT_HEAL - 117//Not used
		&Spell::SpellEffectSkill,//SPELL_EFFECT_SKILL - 118
		&Spell::SpellEffectApplyPetAura,//SPELL_EFFECT_APPLY_PET_AURA - 119
		&Spell::SpellEffectNULL,//SPELL_EFFECT_TELEPORT_GRAVEYARD - 120//Not used
		&Spell::SpellEffectDummyMelee,//SPELL_EFFECT_DUMMYMELEE	- 121
		&Spell::SpellEffectNULL,//unknown - 122 //not used
		&Spell::SpellEffectNULL,//SPELL_EFFECT_FILMING - 123 // http://www.thottbot.com/?sp=27998: flightpath 
		&Spell::SpellEffectPlayerPull, // SPELL_EFFECT_PLAYER_PULL - 124 - http://thottbot.com/e2312
		&Spell::SpellEffectNULL,//unknown - 125 // Reduce Threat by % //http://www.thottbot.com/?sp=32835
		&Spell::SpellEffectSpellSteal,//SPELL_EFFECT_SPELL_STEAL - 126 // Steal Beneficial Buff (Magic) //http://www.thottbot.com/?sp=30449
		&Spell::SpellEffectProspecting,//unknown - 127 // Search 5 ore of a base metal for precious gems.  This will destroy the ore in the process.
		&Spell::SpellEffectApplyAura128,//unknown - 128 // Adjust a stats by %: Mod Stat // ITS FLAT
		&Spell::SpellEffectNULL,// unknown - 129 // Mod Dmg % (Spells)
		&Spell::SpellEffectNULL,// unknown - 130 // http://www.thottbot.com/s34477
		&Spell::SpellEffectNULL,// unknown - 131 // test spell
		&Spell::SpellEffectNULL,// unknown - 132 // no spells
		&Spell::SpellEffectNULL,// SPELL_EFFECT_FORGET_SPECIALIZATION - 133 // http://www.thottbot.com/s36441 // I think this is a gm/npc spell
		&Spell::SpellEffectNULL,// unknown - 134 // related to summoning objects and removing them, http://www.thottbot.com/s39161
		&Spell::SpellEffectNULL,// unknown - 135 // no spells
		&Spell::SpellEffectRestoreHealthPct,// Restore Health % - 136 // http://www.wowhead.com/?spell=48982
		&Spell::SpellEffectRestoreManaPct,// Restore Mana % - 137 // http://www.thottbot.com/s41542
		&Spell::SpellEffectNULL,// unknown - 138 // related to superjump or even "*jump" spells http://www.thottbot.com/?e=Unknown%20138
		&Spell::SpellEffectNULL,// unknown - 139 // no spells
		&Spell::SpellEffectTeleportUnits,//SPELL_EFFECT_TELEPORT_UNITS - 140 IronForge teleport / portal only it seems
		&Spell::SpellEffectNULL,// unknown - 141 // triggers spell, magic one,  (Mother spell) http://www.thottbot.com/s41065
		&Spell::SpellEffectTriggerSpellWithValue,// unknown - 142 // triggers some kind of "Put spell on target" thing... (dono for sure) http://www.thottbot.com/s40872 and http://www.thottbot.com/s33076
		&Spell::SpellEffectNULL, // Apply area aura- 143 // Master -> deamon effecting spell, http://www.thottbot.com/s25228 and http://www.thottbot.com/s35696
		&Spell::SpellEffectNULL,// unknown - 144 Spectral Blast
		&Spell::SpellEffectNULL,// unknown - 145 Black Hole Effect
		&Spell::SpellEffectNULL,// unknown - 146  unused
		&Spell::SpellEffectNULL,// unknown - 147 // Torch Tossing Training Failure
		&Spell::SpellEffectNULL,// unknown - 148 unused
		&Spell::SpellEffectNULL,// unknown - 149
		&Spell::SpellEffectNULL,// unknown - 150 unused
		&Spell::SpellEffectTriggerSpell,// 151 SPELL_EFFECT_TRIGGER_SPELL_2
		&Spell::SpellEffectNULL,// unknown - 152
		&Spell::SpellEffectNULL,// unknown - 153 // SPELL_EFFECT_CREATE_PET               misc value is creature entry
		&Spell::SpellEffectNULL, //154 unused
		&Spell::SpellEffectTitanGrip,// Titan's Grip - 155
		&Spell::SpellEffectNULL, //156 Add Socket
		&Spell::SpellEffectNULL, //157 create/learn random item/spell for profession
		&Spell::SpellEffectMilling, //158 milling
		&Spell::SpellEffectNULL //159 allow rename pet once again
};

void Spell::SpellEffectNULL(uint32 i)
{
	DEBUG_LOG("Spell","Unhandled spell effect %u in spell %u.\n",m_spellInfo->Effect[i],m_spellInfo->Id);
}

void Spell::SpellEffectInstantKill(uint32 i)
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	//Sacrifice: if spell caster has "void walker" pet, pet dies and spell caster gets a 
	/*Sacrifices the Voidwalker, giving its owner a shield that will absorb 
	305 damage for 30 sec. While the shield holds, spellcasting will not be \
	interrupted by damage.*/

	/*
	Demonic Sacrifice

	When activated, sacrifices your summoned demon to grant you an effect that lasts 
	30 minutes. The effect is canceled if any Demon is summoned. 
	Imp: Increases your Fire damage by 15%. 
	Voidwalker: Restores 3% of total Health every 4 sec. 
	Succubus: Increases your Shadow damage by 15%. 
	Felhunter: Restores 2% of total Mana every 4 sec.

	When activated, sacrifices your summoned demon to grant you an effect that lasts $18789d.  The effect is canceled if any Demon is summoned.

	Imp: Increases your Fire damage by $18789s1%.

	Voidwalker: Restores $18790s1% of total Health every $18790t1 sec.

	Succubus: Increases your Shadow damage by $18791s1%.

	Felhunter: Restores $18792s1% of total Mana every $18792t1 sec.

	*/
	uint32 spellId = m_spellInfo->Id;

	switch(spellId)
	{
	case 7814:
	case 7815:
	case 7816:
	case 7876:
	case 7877:
	case 7878:
	case 11778:
	case 11779:
	case 11780:
	case 15968:
	case 15969:
	case 18128:
	case 18129:
	case 20398:
	case 20399:
	case 20400:
	case 20401:
	case 20402:
		{
		}break;

	case 18788: //Demonic Sacrifice (508745)
		{
			uint32 spellid1 = 0;
			switch(unitTarget->GetEntry())
			{
				case 416: //Imp
				{   
					spellid1 = 18789;
				}break;
				case 417: //Felhunter
				{
					spellid1 = 18792;
				}break;
				case 1860: //VoidWalker
				{
					spellid1 = 18790;
				}break;
				case 1863: //Succubus
				{
					spellid1 = 18791;
				}break;
				case 17252: //felguard
				{
					spellid1 = 35701;
				}break;
			}
			//now caster gains this buff
			if (spellid1 && spellid1 != 0)
			{
				u_caster->CastSpell(u_caster, dbcSpell.LookupEntry(spellid1), true);
			}
		}

	case 7812: //Sacrifice Voidwalker
	case 19438:
	case 19440:
	case 19441:
	case 19442:
	case 19443:
	case 27273:
		{
			if( unitTarget->GetEntry() != 1860 )
				return;
		}break;
	case 29364:    //Encapsulate Voidwalker
		{
		if( unitTarget->GetEntry() != 16975 )
				return;
		}break;
	case 33974: //Power Burn for each Point consumed mana (Effect1) target get damage(Effect3) no better idea :P
		{
			unitTarget->GetPowerType() == POWER_TYPE_RAGE ? m_caster->DealDamage(unitTarget, m_spellInfo->EffectBasePoints[0], 0, spellId, false) : m_caster->DealDamage(unitTarget, m_spellInfo->EffectBasePoints[1], 0, spellId, false);
			return;
		}break;
	case 36484: //Mana Burn same like Power Burn
		{
			m_caster->DealDamage(unitTarget, m_spellInfo->EffectBasePoints[0], 0, spellId, false);
			return;
		}break;
	case 37056: //Kill Legion Hold Infernals
		{
			if( unitTarget->GetEntry() != 21316 )
				return;
		}break;
	case 40105: //Infusion (don't know why this should kill anything makes no sence)
		{
			return;
		}break;
	case 43135: //Bubbling Ooze
		{
			return;
		}break;
	case 41626:    //Destroy Spirit
	case 44659:
		{
			if( unitTarget->GetEntry() != 23109 )
				return;
		}break;
	case 45259: //Karazhan - Kill Chest Bunny
		{
			if( unitTarget->GetEntry() != 25213 )
				return;
		}break;
	}

	switch( m_spellInfo->NameHash )
	{
	case SPELL_HASH_SACRIFICE:
		{
			if( !u_caster->IsPet() )
				return;

			TO_PET(u_caster)->Dismiss( true );
			return;

		}break;

	default:
		{
			// moar cheaters
			if( p_caster == NULL || (u_caster != NULL && u_caster->IsPet() ) )
				return;

			if( p_caster->GetSession()->GetPermissionCount() == 0 )
				return;
		}
	}
	m_caster->DealDamage(unitTarget, unitTarget->GetUInt32Value(UNIT_FIELD_HEALTH), 0, 0, 0);
	uint8 buffer[100];
	StackPacket data(SMSG_SPELLINSTAKILLLOG, buffer, 100);
	data << m_caster->GetGUID() << unitTarget->GetGUID() << spellId;
	m_caster->SendMessageToSet(&data, true);
}

void Spell::SpellEffectSchoolDMG(uint32 i) // dmg school
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	if(unitTarget->SchoolImmunityList[m_spellInfo->School])
	{
		SendCastResult(SPELL_FAILED_IMMUNE);
		return;
	}
   
	uint32 dmg = 0;
	bool static_damage=false;

	if(m_spellInfo->EffectChainTarget[i])//chain
	{
		int32 reduce = (int32)(m_spellInfo->dmg_multiplier[i] * 100.0f);
		
		if(reduce && chaindamage)
		{
			if(m_spellInfo->SpellGroupType && u_caster)
			{
				SM_FIValue(u_caster->SM[SMT_JUMP_REDUCE][1],&reduce,m_spellInfo->SpellGroupType);
			}
			chaindamage = chaindamage * reduce / 100;
		}
		else
		{
			chaindamage = damage;
		}
		dmg = chaindamage;
	}
	else 
	{
		dmg = damage;
		switch(m_spellInfo->NameHash)
		{

			case SPELL_HASH_ICE_LANCE: // Ice Lance
				if (dmg>300)   //dirty bugfix.
					dmg = (int32)(damage >> 1);
				break;

			case SPELL_HASH_HAUNT:
				{
					unitTarget->m_lastHauntInitialDamage = dmg;
				}break;
			case SPELL_HASH_INCINERATE:	// Incinerate -> Deals x-x extra damage if the target is affected by immolate
				{
					if( unitTarget->GetAuraSpellIDWithNameHash( SPELL_HASH_IMMOLATE ) )
					{
						// random extra damage
						uint32 extra_dmg = 111 + (m_spellInfo->RankNumber * 11) + RandomUInt(m_spellInfo->RankNumber * 11);
						dmg += extra_dmg;
					}
				}break;
			case SPELL_HASH_GOUGE:	// Gouge: turns off your combat
				{
					if( p_caster != NULL )
					{
						p_caster->EventAttackStop();
						p_caster->smsg_AttackStop( unitTarget );
					}break;
				}break;
			case SPELL_HASH_BLIND:	// Blind: turns off your attack
				{
					if( p_caster != NULL )
					{
						p_caster->EventAttackStop();
						p_caster->smsg_AttackStop( unitTarget );
					}return;
				}break;
			case SPELL_HASH_MAIM:	// Maim: turns off your attack
				{
					if( p_caster != NULL )
					{
						p_caster->EventAttackStop();
						p_caster->smsg_AttackStop( unitTarget );
					}return;
				}break;
			case SPELL_HASH_ARCANE_SHOT: //hunter - arcane shot
				{
					if(u_caster)
						dmg += float2int32(float(u_caster->GetRAP())*0.15f);
				}break;			
			case SPELL_HASH_GORE: // boar/ravager: Gore (50% chance of double damage)
				{
					if( !u_caster->IsPet() )
						return;
					PlayerPointer plr = TO_PET(u_caster)->GetPetOwner();
					if( plr == NULL )
						return;
					dmg += (plr->GetRAP())/8;
					dmg *= Rand( 50 ) ? 2 : 1;
				}
				break;
			case SPELL_HASH_LIGHTNING_BREATH:
				{
					if( !u_caster->IsPet() )
						return;
					PlayerPointer plr = TO_PET(u_caster)->GetPetOwner();
					if( plr == NULL )
						return;
					 dmg += plr->GetRAP()/8;
			}break;
			case SPELL_HASH_CLAW:
				{
					if( !u_caster->IsPet() )
						return;
					PlayerPointer plr = TO_PET(u_caster)->GetPetOwner();
					if( plr == NULL )
						return;
					dmg += plr->GetRAP()/8;
				}break;
			case SPELL_HASH_POISON_SPIT:
				{
					if( !u_caster->IsPet() )
						return;
					PlayerPointer plr = TO_PET(u_caster)->GetPetOwner();
					if( plr == NULL )
						return;
					dmg += plr->GetRAP()/8;
				}break;
			case SPELL_HASH_FIRE_BREATH:
				{
					if( !u_caster->IsPet() )
						return;
					PlayerPointer plr = TO_PET(u_caster)->GetPetOwner();
					if( plr == NULL )
						return;
					dmg += plr->GetRAP()/8;
				}break;
			case SPELL_HASH_BITE:
			{
					if( !u_caster->IsPet() )
						return;
					PlayerPointer plr = TO_PET(u_caster)->GetPetOwner();
					if( plr == NULL )
						return;
				dmg += plr->GetRAP()/8;
			}break;
			case SPELL_HASH_SCORPID_POISON:
			{
					if( !u_caster->IsPet() )
						return;
					PlayerPointer plr = TO_PET(u_caster)->GetPetOwner();
					if( plr == NULL )
						return;
				dmg += plr->GetRAP()/8;
			}break;
			case SPELL_HASH_BLOODTHIRST:	// Bloodthirst
				{
			        dmg = u_caster->GetAP()*(m_spellInfo->EffectBasePoints[0]+1) / 100;
				}break;
		case SPELL_HASH_MOLTEN_ARMOR:		// fire armor, is static damage
			static_damage=true;
			break;
		case SPELL_HASH_CONFLAGRATE:
			if (unitTarget->GetAuraSpellIDWithNameHash(SPELL_HASH_IMMOLATE))
				unitTarget->RemoveAuraByNameHash(SPELL_HASH_IMMOLATE);
			else
			if (unitTarget->GetAuraSpellIDWithNameHash(SPELL_HASH_SHADOWFLAME))
				unitTarget->RemoveAuraByNameHash(SPELL_HASH_SHADOWFLAME);
			break;
		case SPELL_HASH_SHIELD_SLAM:	// Shield Slam - damage is increased by block value
			{
				if( p_caster != NULL )
				{
					ItemPointer it = TO_ITEM(p_caster->GetItemInterface()->GetInventoryItem( EQUIPMENT_SLOT_OFFHAND));
					if( it && it->GetProto()->InventoryType == INVTYPE_SHIELD )
					{
						float block_multiplier = ( 100.0f + float( p_caster->m_modblockabsorbvalue ) ) / 100.0f;
						if( block_multiplier < 1.0f )block_multiplier = 1.0f;
						int32 blockable_damage = float2int32( float( it->GetProto()->Block ) +( float( p_caster->m_modblockvaluefromspells + p_caster->GetUInt32Value( PLAYER_RATING_MODIFIER_BLOCK ) ) * block_multiplier ) + ( ( float( p_caster->GetUInt32Value( UNIT_FIELD_STAT0 ) ) / 20.0f ) - 1.0f ) );
						dmg += blockable_damage;
					}
				}
			}break;
		case SPELL_HASH_FEROCIOUS_BITE:  //Ferocious Bite dmg correction
			{
				dmg+=float2int32(float(p_caster->GetAP())*0.15f + float(p_caster->GetUInt32Value(UNIT_FIELD_POWER4))*m_spellInfo->dmg_multiplier[1]);
				p_caster->SetUInt32Value(UNIT_FIELD_POWER4,0);
			}break;
		case SPELL_HASH_SHATTER: //Gruul Shatter: Damage based on distance
			{
				if( u_caster )
				{
					float dist = u_caster->CalcDistance( TO_OBJECT( unitTarget ) );
					if( dist <= 20.0f && dist >= 0.0f )
						dmg = float2int32( -450 * dist + damage );
				}
			}break;
		case SPELL_HASH_JUDGEMENT_OF_COMMAND: //Libram of Avengement and Libram of Divine Judgement
			{
				if( p_caster && p_caster->HasAura(34258) )
					p_caster->CastSpell(TO_UNIT(p_caster),34260,true);
				if( p_caster && p_caster->HasAura(43745) && RandomFloat(100.0f) < 40.0f )
					p_caster->CastSpell(TO_UNIT(p_caster),43747,true);
			}break;
		case SPELL_HASH_JUDGEMENT_OF_BLOOD:
		case SPELL_HASH_JUDGEMENT_OF_VENGEANCE:
		case SPELL_HASH_JUDGEMENT_OF_RIGHTEOUSNESS:
			{
				if( p_caster && p_caster->HasAura(34258) )
					p_caster->CastSpell(TO_UNIT(p_caster),34260,true);
			}break;
		case SPELL_HASH_INTERCEPT:
			{
				if( u_caster )
					dmg = float2int32( u_caster->GetAP() * 0.12f );
			}break;
		case SPELL_HASH_HEROIC_THROW:
			{
				if( u_caster )
					dmg += float2int32( u_caster->GetAP() * 0.50f );
			}break;
		}
	}

	// check for no more damage left (chains)
	if(!dmg) return;

	// stealthed stuff
	if( m_projectileWait && unitTarget->InStealth() )
		return;

	/**************************************************************************
	* This handles the correct damage of "Judgement of Command" (all ranks)
	**************************************************************************/
	if (m_spellInfo->NameHash == SPELL_HASH_JUDGEMENT_OF_COMMAND && !unitTarget->IsStunned())
			dmg = dmg >> 1;

	if(m_spellInfo->speed > 0)
	{
		m_caster->SpellNonMeleeDamageLog(unitTarget,m_spellInfo->Id, dmg, pSpellId==0);
	}
	else
	{
		if( GetType() == SPELL_DMG_TYPE_MAGIC )		
		{
			m_caster->SpellNonMeleeDamageLog( unitTarget, m_spellInfo->Id, dmg, pSpellId == 0, static_damage );
		}
		else 
		{
			if( u_caster != NULL )
			{
				uint32 _type;
				if( GetType() == SPELL_DMG_TYPE_RANGED )
					_type = RANGED;
				else
				{
					if (m_spellInfo->Flags4 & FLAGS4_OFFHAND)
						_type =  OFFHAND;
					else
						_type = MELEE;
				}

				u_caster->Strike( unitTarget, _type, m_spellInfo, 0, 0, dmg, pSpellId == 0, true );
			}
		}
	}   
}

void Spell::SpellEffectDummy(uint32 i) // Dummy(Scripted events)
{
	uint32 spellId = m_spellInfo->Id;
	
	// Try a dummy SpellHandler
	if(sScriptMgr.CallScriptedDummySpell(spellId, i, shared_from_this() ))
		return;

	// warrior: Slam
	if( m_spellInfo->NameHash == SPELL_HASH_SLAM )
	{
		if(p_caster && GetUnitTarget())
			p_caster->Strike( GetUnitTarget(), MELEE, NULL, damage, 0, 0, false, false);
	}

	switch(spellId)
	{
	/*****************************************
	 *	Class Spells
	 *****************************************/	
	case 49576:
		{
			if( !p_caster || !unitTarget ) return;

			// Move Effect
			unitTarget->CastSpellAoF( p_caster->GetPositionX(), p_caster->GetPositionY(), p_caster->GetPositionZ(), dbcSpell.LookupEntryForced(49575), true); 
			p_caster->CastSpell( unitTarget, 51399, true ); // Taunt Effect
		}break;

	/*************************
	 * WARRIOR SPELLS
	 *************************/
	case 60970: // Heroic Fury
		{
			if( !p_caster )
				return;

			uint32 ClearSpellId[1] =
			{
			20252,  /* Intercept */
			};

			for(i = 0; i < 1; i++)
			{
				if( p_caster->HasSpell( ClearSpellId[i] ) )
					p_caster->ClearCooldownForSpell( ClearSpellId[i] );
			}
		}break;
	case 50227: // Sword and Board
		{
			if( !p_caster )
				return;

			uint32 ClearSpellId[8] =
			{
			23922,  /* Shield Slam - Rank 1 */
			23923,  /* Shield Slam - Rank 2 */
			23924,  /* Shield Slam - Rank 3 */
			23925,  /* Shield Slam - Rank 4 */
			25258,  /* Shield Slam - Rank 5 */
			30356,  /* Shield Slam - Rank 6 */
			47487,  /* Shield Slam - Rank 7 */
			47488,  /* Shield Slam - Rank 8 */
			};

			for(i = 0; i < 8; i++)
			{
				if( p_caster->HasSpell( ClearSpellId[i] ) )
					p_caster->ClearCooldownForSpell( ClearSpellId[i] );
			}
		}break;

	case 5308:
	case 20658:
	case 20660:
	case 20661:
	case 20662:
	case 25234:
	case 25236:
	case 47470:
	case 47471:// Execute
		{
			if( !u_caster || !u_caster->IsInWorld() || !unitTarget || !unitTarget->IsInWorld() || !m_spellInfo)
				return;
			int32 value = m_spellInfo->EffectBasePoints[i]+1 + p_caster->GetAP() / 5;
			int32 rageUsed = p_caster->GetUInt32Value(UNIT_FIELD_POWER2);

			int32 rageLeft = 0; // We use all available rage by default
			AuraPointer suddenDeath = u_caster->FindActiveAura(52437);

			if(suddenDeath && unitTarget->GetHealthPct() > 20)
			{		
				SpellEntry * sd = dbcSpell.LookupEntry(suddenDeath->pSpellId);
				if(sd)
					rageLeft = sd->RankNumber > 1 ? sd->RankNumber * 30 + 10 : sd->RankNumber * 30;
				suddenDeath->Remove(); // Sudden Death is removed after 1 execute
				// With Sudden Death can only use up to 30 total rage. so 30-15 = 15 goes to execute damage
				rageLeft = std::max(rageLeft, rageUsed - 150);
				rageUsed = std::min(rageUsed, 150);
			}

			if(u_caster->HasAura(58367))
				rageUsed += 100; //Your Execute ability deals damage as if you had 10 additional rage.
			value += (int32) (rageUsed * m_spellInfo->dmg_multiplier[0]); 
			u_caster->SetPower(POWER_TYPE_RAGE, rageLeft);
			SpellEntry *spellInfo = dbcSpell.LookupEntry(20647 );
			u_caster->Strike(unitTarget,MELEE,spellInfo,0,0,value,false,false);
		}break;


	/*************************
	 * MAGE SPELLS
	 *************************
	 * IDs:
	 *	11189 Frost Warding   -	RANK 1,		STATUS: DONE
	 *  28332 Frost Warding   -	RANK 2,		STATUS: DONE
	 *  --------------------------------------------
	 *************************/
	
	/*
		Frost Warding
		Increases the armor and resistances given by your Frost Armor and Ice Armor spells by X%.  In addition, gives your Frost Ward a X% chance to reflect Frost spells and effects while active.
		
		Effect #1	Apply Aura: Add % Modifier (8)

		Effect #2	Apply Aura: Dummy
		11189, 28332
	*/
	case 11189:
	case 28332:
		{
			if(!unitTarget)
				break;
			for(std::list<struct ReflectSpellSchool*>::iterator i = unitTarget->m_reflectSpellSchool.begin(), i2;i != unitTarget->m_reflectSpellSchool.end();)
				if(m_spellInfo->Id == (*i)->spellId)
				{
					i2 = i++;
					unitTarget->m_reflectSpellSchool.erase(i2);
				}
				else
					++i;

			ReflectSpellSchool *rss = new ReflectSpellSchool;
			rss->chance = m_spellInfo->procChance;
			rss->spellId = m_spellInfo->Id;
			rss->require_aura_hash = 2161224959UL; 
			rss->school = m_spellInfo->School;		

			unitTarget->m_reflectSpellSchool.push_back(rss);
		}break;


	/*************************
	 * ROGUE SPELLS
	 *************************
	 * IDs:
	 * 14185 Preparation		STATUS: DONE
	 *  --------------------------------------------
	 * 35729 Cloak of Shadows	STATUS: DONE
	 *  --------------------------------------------
	 *************************/
		/*
		Hunger For Blood
		Enrages you, increasing all damage caused by 3%.  If used while a Bleed effect is afflicting you, it will attempt to remove it and refund 15 energy.  This effect can be stacked up to 3 times.  Lasts 30 sec.
		*/
	case 51662:
		{
			if( !p_caster ) return;

			if( p_caster->RemoveAllAurasByMechanic( MECHANIC_BLEEDING , 1 , true ) )
			{
				// Give 15 energy.
				p_caster->Energize(p_caster, 51662, 15, POWER_TYPE_ENERGY);
			}
		}break;

	/*
		Preparation
		When activated, this ability immediately finishes the cooldown on your Evasion, Sprint, Vanish, Cold Blood, Shadowstep and Premeditation abilities.		
		
		Effect	Dummy
	*/
	case 14185:
		{
			if( !p_caster )
				return;

			uint32 ClearSpellId[11] =
			{
			5277,  /* Evasion - Rank 1 */
			26669, /* Evasion - Rank 2 */
			2983,  /* Sprint  - Rank 1 */
			8696,  /* Sprint  - Rank 2 */
			11305, /* Sprint  - Rank 3 */
			1856,  /* Vanish  - Rank 1 */
			1857,  /* Vanish  - Rank 2 */
			26889, /* Vanish  - Rank 3 */
			14177, /* Cold Blood       */
			14183, /* Premeditation    */
			36554  /* Shadowstep       */
			};

			for(i = 0; i < 11; ++i)
			{
				if( p_caster->HasSpell( ClearSpellId[i] ) )
					p_caster->ClearCooldownForSpell( ClearSpellId[i] );
			}
		}break;
	/*
		Cloak of Shadows
		Instantly removes all existing harmful spell effects and increases your chance to resist all spells by 90% for 5 sec.  Does not remove effects that prevent you from using Cloak of Shadows.
		
		Effect #1	Apply Aura: Mod Attacker Spell Hit Chance (126)
			Value: -90
		Effect #2	Trigger Spell
			Spell #35729 <--- THIS SPELL
	*/
	case 35729:
		{
			if( !unitTarget || !unitTarget->isAlive())
				return;

			AuraPointer pAura;
			for(uint32 i = MAX_POSITIVE_AURAS; i < MAX_AURAS; ++i)
			{
				pAura = unitTarget->m_auras[i];
				if( pAura != NULL && !pAura->IsPassive() && !pAura->IsPositive() && !(pAura->GetSpellProto()->Attributes & ATTRIBUTES_IGNORE_INVULNERABILITY) &&
					pAura->GetSpellProto()->School != 0 )
				{
					pAura->Remove();
				}
			}
		}break;
	 case 5938:
		{
			if( !p_caster || !unitTarget || !unitTarget->isAlive())
				return;

			ItemPointer Offhand = p_caster->GetItemInterface()->GetInventoryItem( EQUIPMENT_SLOT_OFFHAND);

			if( Offhand == NULL || Offhand->GetEnchantment( 1 ) == NULL )
				return;

			SpellEntry* spellInfo = dbcSpell.LookupEntry(Offhand->GetEnchantment( 1 )->Enchantment->spell[0]);

			if(spellInfo && spellInfo->c_is_flags & SPELL_FLAG_IS_POISON )
			{
				SpellPointer spell(new Spell( p_caster, spellInfo, true, NULLAURA));
				SpellCastTargets targets;
				targets.m_unitTarget = unitTarget->GetGUID();
				spell->prepare( &targets );
			}
		}break;
	/*************************
	 * DRUID SPELLS
	 *************************
	 * IDs:
	 * 34297 Improved Leader of the Pack RANK 1		STATUS: DONE
	 * 34300 Improved Leader of the Pack RANK 2		STATUS: DONE
	 *  --------------------------------------------
	 *************************/

	/*
		Improved Leader of the Pack
		Your Leader of the Pack ability also causes affected targets to have a X% chance to heal themselves for X% of their total health when they critically hit with a melee or ranged attack.  The healing effect cannot occur more than once every 6 sec.
		
		Effect #1	Apply Aura: Add Flat Modifier (12)
			Value: X
		Effect #2	Dummy
			Value: 100
	*/
	case 34297:
	case 34300:
		{
			if (!u_caster->IsPlayer())
				return;
			ProcTriggerSpell ILotP;
			ILotP.origId = 34299;
			ILotP.spellId = 34299;
			ILotP.procChance = 100;
			ILotP.procFlags = PROC_ON_CRIT_ATTACK | PROC_TARGET_SELF;
			ILotP.deleted = false;
			ILotP.caster = u_caster->GetGUID();
			ILotP.LastTrigger = 0;
			ILotP.weapon_damage_type = 0;
			u_caster->m_procSpells.push_back(ILotP);
		}break;
	case 5420: // Tree of Life (Passive)
		{
			if (!u_caster->IsPlayer())
				return;
			SpellPointer spell(new Spell(u_caster,dbcSpell.LookupEntry(34123),true,NULLAURA));
			SpellCastTargets targets;
			targets.m_unitTarget = unitTarget->GetGUID();
			spell->prepare(&targets);
		}break;
	/*************************
	 * HUNTER SPELLS
	 *************************
	 * IDs:
	 * 35029 Focused Fire RANK 1		STATUS: ToDo
	 * 35030 Focused Fire RANK 2		STATUS: ToDo
	 *  --------------------------------------------
	 *************************/

	/*
		Focused Fire
		All damage caused by you is increased by 1% while your pet is active and the critical strike chance of your Kill Command ability is increased by 10%.
		
		Effect #1	Dummy
			Value: 1

		Effect #2	Apply Aura: Add Flat Modifier (7)
			Value: 10

	*/
//	case 35029:
//	case 35030:
//		{
//		}break;

	/*************************
	 * PALADIN SPELLS
	 *************************
	 * IDs:
	 * 31789 Righteous Defense		STATUS: DONE
	 *  --------------------------------------------
	 * 18350 illumination			STATUS: DONE
	 *  --------------------------------------------
	 *************************/

	/*
		Righteous Defense
		Come to the defense of a friendly target, commanding up to 3 enemies attacking the target to attack the Paladin instead.
		
		Effect #1	Dummy
			Radius: 5 yards

		Effect #2	Trigger Spell
			Spell #31980
	*/
	case 31789:
		{
			//we will try to lure 3 enemies from our target
			if(!unitTarget || !u_caster)
				break;
			UnitPointer targets[3];
			int targets_got=0;
			for(unordered_set<ObjectPointer >::iterator itr = unitTarget->GetInRangeSetBegin(), i2; itr != unitTarget->GetInRangeSetEnd(); )
			{
				i2 = itr++;
				// don't add objects that are not units and that are dead
				if((*i2)->GetTypeId()!= TYPEID_UNIT || !TO_UNIT(*i2)->isAlive())
					continue;
		        
				CreaturePointer cr=TO_CREATURE((*i2));
				if(cr->GetAIInterface()->GetNextTarget()==unitTarget)
					targets[targets_got++]=cr;
				if(targets_got==3)
					break;
			}
			for(int i=0;i<targets_got;i++)
			{
				//set threat to this target so we are the msot hated
				uint32 threat_to_him = targets[i]->GetAIInterface()->getThreatByPtr( unitTarget );
				uint32 threat_to_us = targets[i]->GetAIInterface()->getThreatByPtr(u_caster);
				int threat_dif = threat_to_him - threat_to_us;
				if(threat_dif>0)//should nto happen
					targets[i]->GetAIInterface()->modThreatByPtr(u_caster,threat_dif);
				targets[i]->GetAIInterface()->AttackReaction(u_caster,1,0);
				targets[i]->GetAIInterface()->SetNextTarget(u_caster);
			}
		}break;
	/*
		Illumination
		After getting a critical effect from your Flash of Light, Holy Light, or Holy Shock heal spell, gives you a X% chance to gain mana equal to 60% of the base cost of the spell.
		
		Effect #1	Apply Aura: Proc Trigger Spell
			Proc chance: 20%
			Spell #18350 <-- THIS SPELL	
		Effect #2	Apply Aura: Override Class Scripts (2689)
			Value: 60
	*/
	case 18350:
		{
			if(!p_caster) return;

			SpellEntry * sp = p_caster->last_heal_spell ? p_caster->last_heal_spell : m_spellInfo;
			if(!sp) return;

			uint32 cost = float2int32( p_caster->GetSpellBaseCost(sp) * 0.6f );
			p_caster->Energize(p_caster, pSpellId ? pSpellId : m_spellInfo->Id, cost, POWER_TYPE_MANA);
		}break;
	/*************************
	 * PRIEST SPELLS
	 *************************
	 * IDs:
	 * 33076 - Prayer of mending master spell
	 * 41637 - Prayer of mending
	 *  --------------------------------------------
	 *************************/
	case 33076:
		{
			if( !p_caster || p_caster->GetGroup() == NULL )
				return;

			p_caster->GetGroup()->m_prayerOfMendingCount = 5;		// 5 jumpz
			p_caster->GetGroup()->m_prayerOfMendingTarget = p_caster->GetLowGUID();
		}break;
	case 41637:
		{
			if( !p_caster )
				return;

			// perform actual heal
			p_caster->Heal(p_caster, m_spellInfo->Id, 800);

			// remove parent aura
			p_caster->RemoveAura(41635);

			// find a new party member within 20 yards
			if( p_caster->GetGroup() != NULL )
			{
				Group *grp = p_caster->GetGroup();
				if( grp->m_prayerOfMendingCount > 0 )
				{
					// decrement counter
					--grp->m_prayerOfMendingCount;
					
					vector<PlayerPointer  > possible_targets;
					SubGroup *sg;
					grp->Lock();
					for(uint32 sgid = 0; sgid < grp->GetSubGroupCount(); ++sgid)
					{
						sg = p_caster->GetGroup()->GetSubGroup(sgid);
						for(GroupMembersSet::iterator itr = sg->GetGroupMembersBegin(); itr != sg->GetGroupMembersEnd(); ++itr)
						{
							if( (*itr)->m_loggedInPlayer != NULL && (*itr)->m_loggedInPlayer->GetInstanceID() == p_caster->GetInstanceID() &&
								(*itr)->m_loggedInPlayer != p_caster && (*itr)->m_loggedInPlayer->GetDistance2dSq(p_caster) <= 400.0f )
							{
								// target ok
								possible_targets.push_back((*itr)->m_loggedInPlayer);
							}
						}
					}
					grp->Unlock();

					// pick a new target
					if( possible_targets.size() > 0 )
					{
						PlayerPointer tgt;
						if( possible_targets.size() > 1 )
							tgt = possible_targets[RandomUInt(possible_targets.size()-1)];
						else
							tgt = possible_targets[0];

						// cast us on them
						SpellPointer nsp = CREATESPELL(p_caster, dbcSpell.LookupEntry(41635), true, NULLAURA);
						SpellCastTargets tgts(tgt->GetGUID());
						nsp->prepare(&tgts);
						grp->m_prayerOfMendingTarget = tgt->GetLowGUID();
					}
					else
					{
						// clear the data
						grp->m_prayerOfMendingCount = 0;
						grp->m_prayerOfMendingTarget = 0;
					}
				}
				else
					grp->m_prayerOfMendingTarget = 0;
			}

		}break;

	/*************************
	 * SHAMAN SPELLS
	 *************************
	 * IDs:
	 * NO SPELLS
	 *  --------------------------------------------
	 *************************/
	case 55198:	// Tidal Force
		{
			SpellEffectTriggerSpell(i);
			SpellEffectTriggerSpell(i);
			SpellEffectTriggerSpell(i);	// want stack of 3 so cast it 3 times. hacky :/
		}break;

	/*************************
	 * WARLOCK SPELLS
	 *************************
	 * IDs:
	 * 19028 soul link effect		STATUS: DONE
	 *  --------------------------------------------
	 *************************/
	/*
		Soul Link - EFFECT
		20% of damage taken by master is split with demon. All damage increased by 5%.
	*/
	case 25228:
		{
			if(!u_caster || !u_caster->isAlive() || !unitTarget || !unitTarget->isAlive())
				return;
			uint32 pet_dmg = this->forced_basepoints[0]*20/100;
			unitTarget->ModUnsigned32Value(UNIT_FIELD_HEALTH,pet_dmg);
			unitTarget->DealDamage(u_caster,pet_dmg,0,0,25228,true);
		}break;
		//Demonic Circle
	case 48020:
		{
			if( !p_caster )
				return;
		
			GameObjectPointer DemonicCircle = p_caster->GetMapMgr()->GetGameObject( p_caster->m_ObjectSlots[0] );
			if( DemonicCircle )
			{
				p_caster->SafeTeleport( DemonicCircle->GetMapId(), DemonicCircle->GetInstanceID(), DemonicCircle->GetPosition());
			}
		}break;
	/*************************
	 * DEATH KNIGHT SPELLS
	 *************************/
	case 52375:
	case 49892:
	case 49893:
	case 49894:
	case 49895: //Death Coil
		{
			if(!u_caster || !unitTarget)
				return;
			if(spellId == 52375)
				damage = damage * 2 / 5;	// 40% for rank 1
			if(isAttackable(u_caster, unitTarget, false))
				u_caster->SpellNonMeleeDamageLog(unitTarget, spellId, damage, true);
			else if(unitTarget->IsCreature())
			{
				CreatureInfo * ci = TO_CREATURE(unitTarget)->GetCreatureName();
				if(ci && ci->Type == UNDEAD)
					u_caster->Heal(unitTarget, spellId, float2int32(damage * 1.5f));
			}
			else if(unitTarget->IsPlayer())
			{	// TODO: Check if player is considered undead (Lichborne)
				//TO_PLAYER(unitTarget)->
			}
		}break;

	/*************************
		Non-Class spells
		- Done
	 *************************/
	/*
		Living Root of the Wildheart
		Your spells and attacks in each form have a chance to grant you a blessing for 15 sec.
	*/
	case 37336:
		{
			if( !p_caster || !playerTarget )
				return;

			uint32 NewSpell = 0;
			uint8 shape = playerTarget->GetShapeShift();
			switch( shape )
			{
			case FORM_NORMAL:
				NewSpell = 37344; break;
			case FORM_BEAR:
				NewSpell = 37340; break;
			case FORM_DIREBEAR:
				NewSpell = 37340; break;
			case FORM_CAT:
				NewSpell = 37341; break;
			case FORM_TREE:
				NewSpell = 37342; break;
			case FORM_MOONKIN:
				NewSpell = 37343; break;
			}
			if( NewSpell != 0 )
				p_caster->CastSpell(playerTarget,NewSpell,true);
		}break;
	/*
		Poultryizer
		Turns the target into a chicken for 15 sec.   Well, that is assuming the transmogrification polarity has not been reversed...
	*/
	case 30507:
		{
			if( !unitTarget || !unitTarget->isAlive())
				return;

			u_caster->CastSpell(unitTarget->GetGUID(),30501,true);
		}break;
	/*
		Six Demon Bag
		Blasts enemies in front of you with the power of wind, fire, all that kind of thing!
	*/
	case 14537:
		{
			if( !unitTarget || !unitTarget->isAlive())
				return;

			uint32 ClearSpellId[6] = { 8401,8408,930,118,1680,10159 };
			int min = 1;
			uint32 effect = min + int( ((6-min)+1) * rand() / (RAND_MAX + 1.0) );
			
			u_caster->CastSpell(unitTarget, ClearSpellId[effect] ,true);
		}break;

	case 30427: // Extract Gas
		{
			bool check = false;
			uint32 cloudtype;
			CreaturePointer creature = NULLCREATURE;

			if(!p_caster)
				return;

			for(Object::InRangeSet::iterator i = p_caster->GetInRangeSetBegin(); i != p_caster->GetInRangeSetEnd(); ++i)
			{
				if((*i)->GetTypeId() == TYPEID_UNIT)
				{
					creature= TO_CREATURE(*i);
					cloudtype=creature->GetEntry();
					if(cloudtype == 24222 || cloudtype == 17408 || cloudtype == 17407 || cloudtype == 17378)
					{
						if(p_caster->GetDistance2dSq((*i)) < 400)
						{
							p_caster->SetSelection(creature->GetGUID());
							check = true;
							break;
						}
					}
				}
			}
			
			if(check)
			{
				uint32 item,count = 3+(rand()%3);
			
				if (cloudtype==24222) item=22572;//-air
				if (cloudtype==17408) item=22576;//-mana
				if (cloudtype==17407) item=22577;//-shadow
				if (cloudtype==17378) item=22578;//-water

				ItemPointer add = p_caster->GetItemInterface()->FindItemLessMax(item, count, false);
				if (!add)
				{
					ItemPrototype* proto = ItemPrototypeStorage.LookupEntry(item);
					SlotResult slotresult;

					slotresult = p_caster->GetItemInterface()->FindFreeInventorySlot(proto);
					if(!slotresult.Result)
					{
						p_caster->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM, INV_ERR_INVENTORY_FULL);
						return;
					}
					ItemPointer it=objmgr.CreateItem(item,p_caster);  
					it->SetUInt32Value( ITEM_FIELD_STACK_COUNT, count);
					p_caster->GetItemInterface()->SafeAddItem(it,slotresult.ContainerSlot, slotresult.Slot);
					creature->Despawn(3500,creature->proto->RespawnTime);
				}
				else
				{
					add->SetCount(add->GetUInt32Value(ITEM_FIELD_STACK_COUNT) + count);
					add->m_isDirty = true;
					creature->Despawn(3500,creature->proto->RespawnTime);
				}
			}
		}break;

	//curse of agony(18230) = periodic damage increased in 
	//flag 2031678
	case 1454://life tap
	case 1455:
	case 1456:
	case 11687:
	case 11688:
	case 11689:
	case 27222:
	case 57946:
		{//converts base+1+spirit*x points of health into mana
			if(!p_caster || !playerTarget)
				return;

			uint32 mod;	// spirit bonus coefficient multiplied by 2
			if(m_spellInfo->Id == 1454) mod = 2;
			else if(m_spellInfo->Id == 1455) mod = 3;
			else if(m_spellInfo->Id == 1456) mod = 4;
			else if(m_spellInfo->Id == 11687) mod = 5;
			else mod = 6;

			uint32 damage = m_spellInfo->EffectBasePoints[i] + 1 + mod * playerTarget->GetUInt32Value(UNIT_FIELD_STAT4) / 2;
			if (damage >= playerTarget->GetUInt32Value(UNIT_FIELD_HEALTH))
				return;
			p_caster->DealDamage(playerTarget,damage,0,0,spellId);
			damage = damage * (100 + playerTarget->m_lifetapbonus) / 100;	// Apply improved life tap
			p_caster->Energize(playerTarget, pSpellId ? pSpellId : m_spellInfo->Id, damage, POWER_TYPE_MANA);
		}break;
	case 39610://Mana Tide
		{
			if(unitTarget == NULL || unitTarget->isDead() || unitTarget->getClass() == WARRIOR || unitTarget->getClass() == ROGUE)
 				return;
 			uint32 gain = (uint32) (unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1)*0.06);
			unitTarget->Energize(unitTarget,16191,gain,POWER_TYPE_MANA);
		}break;
	case 20425: //Judgement of Command
	case 20961: //Judgement of Command
	case 20962: //Judgement of Command
	case 20967: //Judgement of Command
	case 20968: //Judgement of Command
	case 27172: //Judgement of Command
		{
			uint32 SpellID = m_spellInfo->EffectBasePoints[i]+1;
			SpellPointer spell= CREATESPELL(m_caster,dbcSpell.LookupEntry(SpellID),true,NULLAURA);
			SpellCastTargets targets;
			targets.m_unitTarget = unitTarget->GetGUID();
			spell->prepare(&targets);
		}break;

	case 20577:// Cannibalize
		{
			if(!p_caster)
				return;
			p_caster->CastSpell( p_caster, 20578, true);
			p_caster->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_CANNIBALIZE);
		}break;
	case 23074:// Arcanite Dragonling
	case 23075:// Mithril Mechanical Dragonling
	case 23076:// Mechanical Dragonling
	case 23133:// Gnomish Battle Chicken
		{
			uint32 spell_id;
			switch(m_spellInfo->Id)
			{
                case 23074: spell_id = 19804; break;
                case 23075: spell_id = 12749; break;
                case 23076: spell_id =  4073; break;
                case 23133: spell_id = 13166; break;
				default: 
					return;
			}
			u_caster->CastSpell(u_caster,spell_id,true);
		}break;
	case 23725:// Gift of Life
		{
			if(!playerTarget)
				break;

			SpellCastTargets tgt;
			tgt.m_unitTarget = playerTarget->GetGUID();
			SpellEntry * inf =dbcSpell.LookupEntry(23782);
			SpellPointer spe = CREATESPELL(u_caster,inf,true,NULLAURA);
			spe->prepare(&tgt);

		}break;
	case 12975:// Last Stand
		{
			if(!playerTarget)
				break;
			SpellCastTargets tgt;
			tgt.m_unitTarget = playerTarget->GetGUID();
			SpellEntry * inf =dbcSpell.LookupEntry(12976);
			SpellPointer spe = CREATESPELL(u_caster,inf,true,NULLAURA);
			spe->prepare(&tgt);
		}break;
	/*************************
		Non-Class spells
		- ToDo
	 *************************/
	case 6668:// Red Firework
		{
			// Shoots a firework into the air that bursts into a thousand red stars
		}break;
	case 8344:// Universal Remote
		{
			//FIXME:Allows control of a mechanical target for a short time.  It may not always work and may just root the machine or make it very very angry.  Gnomish engineering at its finest.
		}break;
	case 9976:// Polly Eats the E.C.A.C.
		{
			//FIXME: Don't know what this does
		}break;
	case 10137:// Fizzule's Whistle
		{
			//FIXME:Blow on the whistle to let Fizzule know you're an ally
			//This item comes after a finish of quest at venture co.
			//You must whistle this every time you reach there to make Fizzule
			//ally to you.
		}break;
	case 11540:// Blue Firework
		{
			//Shoots a firework into the air that bursts into a thousand blue stars
		}break;
	case 11541:// Green Firework
		{
			//Shoots a firework into the air that bursts into a thousand green stars
		}break;
	case 11542:// Red Streaks Firework
		{
			//Shoots a firework into the air that bursts into a thousand red streaks
		}break;
	case 11543:// Red, White and Blue Firework
		{
			//Shoots a firework into the air that bursts into red, white and blue stars
		}break;
	case 11544:// Yellow Rose Firework
		{
			//Shoots a firework into the air that bursts in a yellow pattern
		}break;
	case 12151:// Summon Atal'ai Skeleton
		{
			//8324	Atal'ai Skeleton

			//FIXME:Add here remove in time event
		}break;
	case 13535:// Tame Beast
		{
			
		}break;
	case 13006:// Shrink Ray
		{
			//FIXME:Schematic is learned from the gnomish engineering trainer. The gnomish/gobblin engineering decision is made when you are lvl40+ and your engineering is 200+. Interestingly, however, when this item fails to shrink the target, it can do a variety of things, such as...
			//-Make you bigger (attack power +250)
			//-Make you smaller (attack power -250)
			//-Make them bigger (same effect as above)
			//-Make your entire party bigger
			//-Make your entire party smaller
			//-Make every attacking enemy bigger
			//-Make ever attacking enemy smaller
			//Works to your advantage for the most part (about 70% of the time), but don't use in high-pressure situations, unless you're going to die if you don't. Could tip the scales the wrong way.
			//Search for spells of this


			//13004 - grow <- this one
			//13010 - shrink <-this one
			//
		}break;
	case 13180:// Gnomish Mind Control Cap
		{
			// FIXME:Take control of humanoid target by chance(it can be player)
		}break;
	case 13278:// Gnomish Death Ray
		{
			// FIXME:The devices charges over time using your life force and then directs a burst of energy at your opponent
			//Drops life			
		}break;
	case 13280:// Gnomish Death Ray
		{
			//FIXME: Drop life
		}break;
	case 17816:// Sharp Dresser
		{
			//Impress others with your fashion sense
		}break;
	case 21343:// Snowball
		{
		}break;
	case 23645:// Hourglass Sand
		{
			//Indeed used at the Chromo fight in BWL. Chromo has a stunning debuff, uncleansable, unless you have hourglass sand. This debuff will stun you every 4 seconds, for 4 seconds. It is resisted a lot though. Mage's and other casters usually have to do this fight with the debuff on, healers, tanks and hunters will get some to cure themselves from the debuff
		}break;
	case 24325:// Pagle's Point Cast - Create Mudskunk Lure
		{
			//FIXME:Load with 5 Zulian Mudskunks, and then cast from Pagle's Point in Zul'Gurub
		}
	case 24392:// Frosty Zap
		{
			//FIXME:Your Frostbolt spells have a 6% chance to restore 50 mana when cast.
			//damage == 50
		}break;
	case 25822:// Firecrackers
		{
			//FIXME:Find firecrackers
		}break;
	case 26373:// Lunar Invititation
		{
			//FIXME: Teleports the caster from within Greater Moonlight
		}break;
	case 26374:// Elune's Candle
		{
			if(!u_caster)
				return;
			u_caster->CastSpell(unitTarget,26622,true);
		}break;
	case 26889:// Give Friendship Bracelet
		{
			//Give to a Heartbroken player to cheer them up
			//laugh emote
		}break;
	case 27662:// Throw Cupid's Dart
		{
			//FIXME:Shoot a player, and Kwee Q. Peddlefeet will find them! (Only works on players with no current critter pets.)
		}break;
	case 28414:// Call Ashbringer
		{
			//http://www.thottbot.com/?i=53974
			if(!p_caster)
			 	return;
			
			uint32 ashcall = RandomUInt(12);

			WorldPacket data;
			data.SetOpcode(SMSG_PLAY_OBJECT_SOUND);

			WorldPacket *crap;
			std::stringstream Reply;

			switch(ashcall)
			{
			case 1:
				{
						data << uint32(8906) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "I... was... pure... once.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 2:
				{
						data << uint32(8907) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Fought... for... righteousness.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 3:
				{
						data << uint32(8908) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "I... was... once... called... Ashbringer.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 4:
				{
						data << uint32(8920) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Betrayed... by... my... order.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 5:
				{
						data << uint32(8921) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Destroyed... by... Kel'Thuzad.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 6:
				{
						data << uint32(8922) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Made... to serve.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 7:
				{
						data << uint32(8923) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "My... son... watched... me... die.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 8:
				{
						data << uint32(8924) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Crusades... fed his rage.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 9:
				{
						data << uint32(8925) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Truth... is... unknown... to him.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 10:
				{
						data << uint32(8926) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Scarlet... Crusade... is pure... no longer.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 11:
				{
						data << uint32(8927) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Balnazzar's... crusade... corrupted... my son.";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			case 12:
				{
						data << uint32(8928) << unitTarget->GetGUID();
						p_caster->SendMessageToSet(&data, true);
						Reply << "Kill... them... all!";
						crap = sChatHandler.FillMessageData( CHAT_MSG_WHISPER, LANG_UNIVERSAL, Reply.str().c_str(), p_caster->GetGUID(), 0);
				}break;
			}			
			p_caster->GetSession()->SendPacket(crap);
		}break;
	case 28806:// Toss Fuel on Bonfire
		{
			//FIXME:Dont know what this dummy does
		}break;
	case 7669:// Bethor's Potion
		{
			// related to Hex of Ravenclaw,
			// its a dispell spell.
			//FIXME:Dont know whats the usage of this dummy
		}break;
	case 8283:// Snufflenose Command
		{
			//FIXME:Quest Blueleaf Tubers
			//For use on a Snufflenose Gopher
		}break;
	case 8913:// Sacred Cleansing
		{
			//FIXME:Removes the protective enchantments around Morbent Fel
			//Quest Morbent Fel
		}break;
	case 9962://Capture Treant
		{
			//Quest Treant Muisek 
		}break;
	case 10113:// Flare Gun's flare
		{
			//FIXME:Quest Deep Cover
			//1543 may need to cast this
			//2 flares and the /salute
		}break;
	case 10617:// Release Rageclaw
		{
			//Quest Druid of the Claw
			//Use on the fallen body of Rageclaw
		}break;
	case 11402:// Shay's Bell
		{
			//FIXME:Quest Wandering Shay
			//Ring to call Shay back to you
		}break;

	case 45109: // Orb of Murloc Control
		{
			if(SpellEffectUpdateQuest( 11541 ))
			{
				CreaturePointer qtarget = TO_CREATURE(GetUnitTarget());
				if( qtarget )
				{
					p_caster->GetMapMgr()->GetInterface()->SpawnCreature(25085, qtarget->GetPositionX(), qtarget->GetPositionY(), qtarget->GetPositionZ(), qtarget->GetOrientation(), true, false, 0, 0)->Despawn(600000, 0);
					qtarget->Despawn(0, 600000);
				}
			}
		} break;
	case 44997: // Converting Sentry
		{
			if(!SpellEffectUpdateQuest( 11524 ))
				SpellEffectUpdateQuest( 11525 );
		}break;
	case 32042: // Arcane Disturbances for Karazan atunament
		{
			SpellEffectUpdateQuest( 9824 );
		} break;
	case 36904: // Scratches
		{
			SpellEffectUpdateQuest( 10556 );
		} break;
	case 33655:// Mission: The Murketh and Shaadraz Gateways and Mission: Gateways Murketh and Shaadraz
		{
			if(!SpellEffectUpdateQuest( 10129 ))
				SpellEffectUpdateQuest( 10146 );
		}break;
	case 38439:// Kindness
		{
			SpellEffectUpdateQuest( 10804 );
		}break;
	case 31927:// Blessing of Incineratus
		{
			SpellEffectUpdateQuest( 9805 );
		}break;
	case 11548:// Summon Spider God
		{
			float SSX = p_caster->GetPositionX();
			float SSY = p_caster->GetPositionY();
			float SSZ = p_caster->GetPositionZ();
			float SSO = p_caster->GetOrientation();

			p_caster->GetMapMgr()->GetInterface()->SpawnCreature(2707, SSX, SSY, SSZ, SSO, true, false, 0, 0)->Despawn(60000, 0);
		}break;
	case 11610:// Gammerita Turtle Camera
		{
			//Quest The Super Snapper FX 
		}break;
	case 11886:// Capture Wildkin
		{
			//Quest Testing the Vessel
			//Shrink and Capture a Fallen Wildkin
		}break;
	case 11887:// Capture Hippogryph
		{
			//FIXME:Same with 11888
			//Quest Hippogryph Muisek 
		}break;
	case 11888:// Capture Faerie Dragon
		{
			//FIXME:Check Faerie Dragon Muisek is killed or not if its killed update quest
			//And allow create of fearie Dragon which is effect 1
			//Quest: Faerie Dragon Muisek
		}break;
	case 11889:// Capture Mountain Giant
		{
			//FIXME:Same with 11888
			//Quest: Mountain Giant Muisek
		}break;
	case 12189:// Summon Echeyakee
		{
			//3475	Echeyakee

			//FIXME:Quest Echeyakee
		}break;
	case 12283:// Xiggs Signal Flare
		{
			//Quest Signal for Pickup
			//To be used at the makeshift helipad in Azshara. It will summon Pilot Xiggs Fuselighter to pick up the tablet rubbings
		}break;
	case 12938:// Fel Curse
		{
			//FIXME:Makes near target killable(servants of Razelikh the Defiler)
		}break;
	case 14247:// Blazerunner Dispel
		{
			//FIXME:Quest Aquementas and some more
		}break;
	case 14250:// Capture Grark
		{
			//Quest Precarious Predicament
		}break;
	case 14813:// Rocknot's Ale
		{
			//you throw the mug
			//and the guy gets pissed well everyone gets pissed and he crushes the door so you can get past
			//maybe after like 30 seconds so you can get past.  but lke I said I have never done it myself 
			//so i am not 100% sure what happens.
		}break;
	case 15991://Revive Ringo
		{
			//Quest A Little Help From My Friends 
			//Revive Ringo with water
		}break;
	case 15998:// Capture Worg Pup
		{
			//FIXME:Ends Kibler's Exotic Pets  (Dungeon) quest
		}break;
	case 16031:// Releasing Corrupt Ooze
		{
			//FIXME:Released ooze moves to master ooze and "Merged Ooze Sample"
			//occurs after some time.This item helps to finish quest
		}break;
	case 16378:// Temperature Reading
		{
			//FIXME:Quest Finding the Source
			//Take a reading of the temperature at a hot spot.
		}break;
	case 17166:// Release Umi's Yeti
		{
			//Quest Are We There, Yeti?
			//Select Umi's friend and click to release the Mechanical Yeti
		}break;
	case 17271:// Test Fetid Skull
		{
			//FIXME:Marauders of Darrowshire
			//Wave over a Fetid skull to test its resonance
		}break;
	case 18153:// Kodo Kombobulator
		{
			//FIXME:Kodo Roundup Quest
			//Kodo Kombobulator on any Ancient, Aged, or Dying Kodo to lure the Kodo to follow (one at a time)
		}break;
	case 19250:// Placing Smokey's Explosives
		{
			//This is something related to quest i think
		}break;
	case 19512:// Apply Salve
		{
			//FIXME:Cure a sickly animal afflicted by the taint of poisoning
            if(unitTarget->GetEntry() == 12298 && unitTarget->HasActiveAura(19502))
            {    
				//unitTarget->AddAuraVisual(19502, -1, true);
                unitTarget->SetUInt32Value(UNIT_FIELD_DISPLAYID, 347);
                sQuestMgr.OnPlayerKill(p_caster, TO_CREATURE(unitTarget));
                TO_CREATURE(unitTarget)->Despawn(5000, 360000);
            }else
                if(unitTarget->GetEntry() == 12296 && unitTarget->HasActiveAura(19502))
                {
                    //unitTarget->AddAuraVisual(19502, -1, true);
                    unitTarget->SetUInt32Value(UNIT_FIELD_DISPLAYID, 1547);
                    sQuestMgr.OnPlayerKill(p_caster, TO_CREATURE(unitTarget));
                    TO_CREATURE(unitTarget)->Despawn(5000, 360000);
                }else
                {
                    SendCastResult(SPELL_FAILED_BAD_TARGETS);
                    return;
                }			
		}break;
	case 20804:// Triage 
		{
			//Quest Triage
			//Use on Injured, Badly Injured, and Critically Injured Soldiers
		}break;
	case 21050:// Melodious Rapture
		{
			//Quest Deeprun Rat Roundup 
		}break;
	case 21332:// Aspect of Neptulon
		{
			//FIXME:Used on plagued water elementals in Eastern Plaguelands
			//Quest:Poisoned Water
		}break;
	case 21960:// Manifest Spirit
		{
			//FIXME:Forces the spirits of the first centaur Kahns to manifest in the physical world
			//thats a quest
			//its for maraudon i think
			//u use that on the spirit mobs
			//to release them
		}break;
	case 23359:// Transmogrify!
		{
			//Quest Zapped Giants 
			//Zap a Feralas giant into a more manageable form
		}break;
	case 27184:// Summon Mor Grayhoof
		{
			//16044	Mor Grayhoof Trigger
			//16080	Mor Grayhoof

			//Related to quests The Left Piece of Lord Valthalak's Amulet  (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet  (Dungeon)
		}break;
	case 27190:// Summon Isalien
		{
			//16045	Isalien Trigger
			//16097	Isalien

			//Related to quests The Left Piece of Lord Valthalak's Amulet  (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet  (Dungeon)
		}break;
	case 27191:// Summon the remains of Jarien and Sothos
		{
			/*
			16046	Jarien and Sothos Trigger
			16101	Jarien
			16103	Spirit of Jarien
			
			16102	Sothos
			16104	Spirit of Sothos
			*/

			//Related to quests The Left Piece of Lord Valthalak's Amulet  (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet  (Dungeon)
		}break;
	case 27201:// Summon the spirit of Kormok
		{
			/*16047	Kormok Trigger
			16118	Kormok
			*/
			//Related to quests The Left Piece of Lord Valthalak's Amulet  (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet  (Dungeon)
		}break;
	case 27202:// Summon Lord Valthalak
		{
			/*
			16042	Lord Valthalak
			16048	Lord Valthalak Trigger
			16073	Spirit of Lord Valthalak

			*/
			//Related to quests The Left Piece of Lord Valthalak's Amulet  (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet  (Dungeon)
		}break;
	case 27203:// Summon the spirits of the dead at haunted locations
		{
			//Related to quests The Left Piece of Lord Valthalak's Amulet  (Dungeon)
			//and The Right Piece of Lord Valthalak's Amulet  (Dungeon)
		}break;
	case 27517:// Use this banner at the Arena in Blackrock Depths to challenge Theldren
		{
			//This is used to make Theldren spawn at the place where it used
			//I couldnt find theldrin, and his men in creature names database
			//Someone has to write this and this is related to The Challange quest
			/*By moving to the center grate, you trigger the arena event. 
			A random group of mobs (spiders, worms, bats, raptors) spawns, 
			and you have to kill them. After the last one dies, and a small 
			break, a boss mob spawns. Successfully completing this event 
			turns the arena spectators from red to yellow*/
		}break;
	case 34026: //Kill Command
		{
			if( !p_caster  || ( p_caster && p_caster->GetSummon() == 0 ) )
				return;
			UnitPointer petunit = TO_UNIT(p_caster->GetSummon());
			if( petunit != NULL )
			{
				if( petunit->GetAIInterface() && petunit->GetAIInterface()->GetNextTarget() )
					petunit->CastSpell(petunit->GetAIInterface()->GetNextTarget(),34027,true);
			}
		}break;
	}										 
}

void Spell::SpellEffectTeleportUnits( uint32 i )  // Teleport Units
{
	uint32 spellId = m_spellInfo->Id;

	if( unitTarget == NULL )
		return;

	// Try a dummy SpellHandler
	if( sScriptMgr.CallScriptedDummySpell( spellId, i, shared_from_this() ) )
		return;

	// Shadowstep
	if( m_spellInfo->NameHash == SPELL_HASH_SHADOWSTEP && p_caster && p_caster->IsInWorld() )
	{
		/* this is rather tricky actually. we have to calculate the orientation of the creature/player, and then calculate a little bit of distance behind that. */
		float ang;
		UnitPointer pTarget = unitTarget;
		if( pTarget == m_caster )
		{
			/* try to get a selection */
 			pTarget = m_caster->GetMapMgr()->GetUnit(p_caster->GetSelection());
//			if( (unitTarget == NULL ) || !isHostile(p_caster, unitTarget) || (unitTarget->CalcDistance(p_caster) > 25.0f)) //removed by Zack : no idea why hostile is used. Isattackable should give a wider solution range
			if( (pTarget == NULL ) || !isAttackable(p_caster, pTarget, !(m_spellInfo->c_is_flags & SPELL_FLAG_IS_TARGETINGSTEALTHED) ) || (pTarget->CalcDistance(p_caster) > 25.0f))
				return;
		}

		if( pTarget->GetTypeId() == TYPEID_UNIT )
		{
			if( pTarget->GetUInt64Value( UNIT_FIELD_TARGET ) != 0 )
			{
				/* We're chasing a target. We have to calculate the angle to this target, this is our orientation. */
				ang = m_caster->calcAngle(m_caster->GetPositionX(), m_caster->GetPositionY(), pTarget->GetPositionX(), pTarget->GetPositionY());

				/* convert degree angle to radians */
				ang = ang * float(M_PI) / 180.0f;
			}
			else
			{
				/* Our orientation has already been set. */
				ang = pTarget->GetOrientation();
			}
		}
		else
		{
			/* Players orientation is sent in movement packets */
			ang = pTarget->GetOrientation();
		}

		// avoid teleporting into the model on scaled models
		const static float shadowstep_distance = 1.6f * GetScale( dbcCreatureDisplayInfo.LookupEntry( unitTarget->GetUInt32Value(UNIT_FIELD_DISPLAYID)));
		float new_x = pTarget->GetPositionX() - (shadowstep_distance * cosf(ang));
		float new_y = pTarget->GetPositionY() - (shadowstep_distance * sinf(ang));
		float new_z = pTarget->GetPositionZ() + 0.1f;
		if (pTarget->GetMapMgr() && pTarget->GetMapMgr()->IsCollisionEnabled())
		{
			float z2 = CollideInterface.GetHeight(pTarget->GetMapId(), pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ());
			if( z2 == NO_WMO_HEIGHT )
				z2 = p_caster->GetMapMgr()->GetLandHeight(new_x, new_y);

			if( fabs( new_z - z2 ) < 10.0f )
				new_z = z2 + 0.2f;
		}
		
		/* Send a movement packet to "charge" at this target. Similar to warrior charge. */
		p_caster->z_axisposition = 0.0f;
		p_caster->SafeTeleport(p_caster->GetMapId(), p_caster->GetInstanceID(), LocationVector(new_x, new_y, new_z, pTarget->GetOrientation()));
		
		return;
	}

	/* TODO: Remove Player From bg */

	if(unitTarget->GetTypeId() == TYPEID_PLAYER)
		HandleTeleport(spellId, unitTarget);
}

void Spell::SpellEffectApplyAura(uint32 i)  // Apply Aura
{
	if(!unitTarget)
		return;

	//Aura Immune Flag Check
	if ( !playerTarget )
	{
		CreaturePointer c = TO_CREATURE( unitTarget );
		if ( c != NULL && c->proto && c->proto->auraimmune_flag )
			if( c->proto->auraimmune_flag & m_spellInfo->auraimmune_flag )
				return;
	}

	if( unitTarget->isDead() && !(m_spellInfo->Flags4 & CAN_PERSIST_AND_CASTED_WHILE_DEAD) )
		return;

	//we shouldn't apply fireball dot if we have fireball glyph
	if( m_spellInfo->NameHash == SPELL_HASH_FIREBALL && p_caster && p_caster->m_DummyAuras[SPELL_HASH_GLYPH_OF_FIREBALL] )
		return;

	// can't apply stuns/fear/polymorph/root etc on boss
	if ( !playerTarget )
	{
		CreaturePointer c = TO_CREATURE( unitTarget );
		if (c&&c->GetCreatureName()&&c->GetCreatureName()->Rank == ELITE_WORLDBOSS)
		{
			switch(m_spellInfo->EffectApplyAuraName[i])
			{
			case 5:  // confuse
			case 6:  // charm
			case 7:  // fear
			case 12: // stun
			case 25: // pacify
			case 26: // root
			case 27: // silence
			case 31: // increase speed
			case 33: // decrease speed
				//SendCastResult(SPELL_FAILED_IMMUNE);
				return;
			}
		}
	}
	
	// avoid map corruption.
	if(unitTarget->GetInstanceID()!=m_caster->GetInstanceID())
		return;

	//check if we already have stronger aura
	AuraPointer pAura;

	std::map<uint32,AuraPointer >::iterator itr=unitTarget->tmpAura.find(m_spellInfo->Id);
	//if we do not make a check to see if the aura owner is the same as the caster then we will stack the 2 auras and they will not be visible client sided
	if(itr==unitTarget->tmpAura.end())
	{
		uint32 Duration=this->GetDuration();
		
		// Handle diminishing returns, if it should be resisted, it'll make duration 0 here.
		if(!(m_spellInfo->Attributes & ATTRIBUTES_PASSIVE)) // Passive
			::ApplyDiminishingReturnTimer(&Duration, unitTarget, m_spellInfo);

		if(!Duration)
		{
			//maybe add some resist messege to client here ?
			return;
		}
		if(g_caster && g_caster->GetUInt32Value(OBJECT_FIELD_CREATED_BY) && g_caster->m_summoner)
			pAura = AuraPointer(new Aura(m_spellInfo, Duration, g_caster->m_summoner, unitTarget));
		else
			pAura = AuraPointer(new Aura(m_spellInfo, Duration, m_caster, unitTarget));

		pAura->pSpellId = pSpellId; //this is required for triggered spells
		
		unitTarget->tmpAura[m_spellInfo->Id] = pAura;		
	}
	else
	{
		 pAura=itr->second;
	} 
	int32 miscValue = m_spellInfo->EffectMiscValue[i];

	if(i_caster && m_caster->IsPlayer() && m_spellInfo->EffectApplyAuraName[i]==SPELL_AURA_PROC_TRIGGER_SPELL)
		miscValue = p_caster->GetItemInterface()->GetInventorySlotByGuid( i_caster->GetGUID() ); // Need to know on which hands attacks spell should proc
	
	pAura->AddMod(m_spellInfo->EffectApplyAuraName[i],damage,miscValue,i);
}

void Spell::SpellEffectPowerDrain(uint32 i)  // Power Drain
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	uint32 powerField = UNIT_FIELD_POWER1+m_spellInfo->EffectMiscValue[i];
	uint32 curPower = unitTarget->GetUInt32Value(powerField);
	uint32 amt=damage+((u_caster->GetDamageDoneMod(m_spellInfo->School)*80)/100);
	if( GetPlayerTarget() )
		amt *= float2int32( 1 - ( ( TO_PLAYER(GetPlayerTarget())->CalcRating( PLAYER_RATING_MODIFIER_SPELL_CRIT_RESILIENCE ) * 2 ) / 100.0f ) );
	if(amt>curPower)
	{
		amt=curPower;
	}
	unitTarget->SetUInt32Value(powerField,curPower-amt);
	u_caster->Energize(u_caster, pSpellId ? pSpellId : m_spellInfo->Id, amt, m_spellInfo->EffectMiscValue[i]);
}

void Spell::SpellEffectHealthLeech(uint32 i) // Health Leech
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	uint32 curHealth = unitTarget->GetUInt32Value(UNIT_FIELD_HEALTH);
	uint32 amt = damage;
	if(amt > curHealth)
	{
		amt = curHealth;
	}
	m_caster->DealDamage(unitTarget, damage, 0, 0, m_spellInfo->Id);

	float coef = m_spellInfo->EffectMultipleValue[i]; // how much health is restored per damage dealt
	if(u_caster)
	{
		SM_FFValue(u_caster->SM[SMT_MULTIPLE_VALUE][0], &coef, m_spellInfo->SpellGroupType);
		SM_PFValue(u_caster->SM[SMT_MULTIPLE_VALUE][1], &coef, m_spellInfo->SpellGroupType);
	}

	amt = float2int32((float)amt * coef);

	uint32 playerCurHealth = m_caster->GetUInt32Value(UNIT_FIELD_HEALTH);
	uint32 playerMaxHealth = m_caster->GetUInt32Value(UNIT_FIELD_MAXHEALTH);

	if(playerCurHealth + amt > playerMaxHealth)
	{
		m_caster->SetUInt32Value(UNIT_FIELD_HEALTH, playerMaxHealth);
	}
	else
	{
		m_caster->SetUInt32Value(UNIT_FIELD_HEALTH, playerCurHealth + amt);		   
	}
}

void Spell::SpellEffectHeal(uint32 i) // Heal
{
	if(m_spellInfo->EffectChainTarget[i])//chain
	{
		if(!chaindamage)
		{
			AuraPointer riptide = NULLAURA;
			if(m_spellInfo->NameHash == SPELL_HASH_CHAIN_HEAL && unitTarget && (riptide = unitTarget->FindPositiveAuraByNameHash(SPELL_HASH_RIPTIDE)) != NULL)
			{
				damage += damage / 4; // +25%
				riptide->Remove();
			}
			chaindamage = damage;
			Heal((int32)chaindamage);
		}
		else
		{
			int32 reduce = (int32)(m_spellInfo->dmg_multiplier[i] * 100.0f);
			if(m_spellInfo->SpellGroupType && u_caster)
			{
				SM_FIValue(u_caster->SM[SMT_JUMP_REDUCE][1],&reduce,m_spellInfo->SpellGroupType);
			}
			chaindamage -= (reduce * chaindamage) / 100;
			Heal((int32)chaindamage);
		}
	}
	else
	{
		//yep, the usual special case. This one is shaman talent : Nature's guardian
		//health is below 30%, we have a mother spell to get value from
		switch (m_spellInfo->Id)
		{
		case 34299: //Druid: Improved Leader of the PAck
			{
				if (!unitTarget->IsPlayer() || !unitTarget->isAlive())
					break;

				PlayerPointer mPlayer = TO_PLAYER( unitTarget );
				if( !mPlayer->IsInFeralForm() || (
					mPlayer->GetShapeShift() != FORM_CAT &&
					mPlayer->GetShapeShift() != FORM_BEAR &&
					mPlayer->GetShapeShift() != FORM_DIREBEAR ) )
					break;
				uint32 max = mPlayer->GetUInt32Value( UNIT_FIELD_MAXHEALTH );
				uint32 val = float2int32( ( ( mPlayer->FindAura( 34300 ) ) ? 0.04f : 0.02f ) * max );
				if (val)
					mPlayer->Heal(mPlayer,34299,(uint32)(val));
			}break;
		case 22845: // Druid: Frenzied Regeneration
			{
				if (!unitTarget->IsPlayer() || !unitTarget->isAlive())
					break;
				PlayerPointer mPlayer = TO_PLAYER( unitTarget );
				if (!mPlayer->IsInFeralForm() || 
					(mPlayer->GetShapeShift() != FORM_BEAR &&
					mPlayer->GetShapeShift() != FORM_DIREBEAR))
					break;
				uint32 val = mPlayer->GetUInt32Value(UNIT_FIELD_POWER2);
				if (val>100)
					val = 100;
				mPlayer->SetUInt32Value(UNIT_FIELD_POWER2,mPlayer->GetUInt32Value(UNIT_FIELD_POWER2)-val);
				if (val)
					mPlayer->Heal(mPlayer,22845,uint32(val*2.5f));
			}break;
		case 18562: //druid - swiftmend
			{
				if( unitTarget )
				{
					uint32 new_dmg = 0;
					//consume rejuvenetaion and regrowth
					AuraPointer taura = unitTarget->FindPositiveAuraByNameHash( SPELL_HASH_REGROWTH ); //Regrowth
					if( taura != NULL && taura->GetSpellProto() != NULL)
					{
						uint32 amplitude = taura->GetSpellProto()->EffectAmplitude[1] / 1000;
						if( !amplitude )
							amplitude = 3;

						//our hapiness is that we did not store the aura mod amount so we have to recalc it
						SpellPointer spell(new Spell( m_caster, taura->GetSpellProto(), false, NULLAURA ));				
						uint32 healamount = spell->CalculateEffect( 1, unitTarget );  
						spell->Destructor();
						spell = NULLSPELL;
						new_dmg = healamount * 18 / amplitude;

						unitTarget->RemoveAura( taura );

						//do not remove flag if we still can cast it again
						if( !unitTarget->GetAuraSpellIDWithNameHash( SPELL_HASH_REJUVENATION ) )
						{
							unitTarget->RemoveFlag( UNIT_FIELD_AURASTATE, AURASTATE_FLAG_REJUVENATE );	
							sEventMgr.RemoveEvents( unitTarget, EVENT_REJUVENATION_FLAG_EXPIRE );
						}
					}
					else
					{
						taura = unitTarget->FindPositiveAuraByNameHash( SPELL_HASH_REJUVENATION );//Rejuvenation
						if( taura != NULL && taura->GetSpellProto() != NULL )
						{
							uint32 amplitude = taura->GetSpellProto()->EffectAmplitude[0] / 1000;
							if( !amplitude )
								amplitude = 3;

							//our hapiness is that we did not store the aura mod amount so we have to recalc it
							SpellPointer spell(new Spell( m_caster, taura->GetSpellProto(), false, NULLAURA ));				
							uint32 healamount = spell->CalculateEffect( 0, unitTarget );  
							spell->Destructor();
							spell = NULLSPELL;
							new_dmg = healamount * 12 / amplitude;

							unitTarget->RemoveAura( taura );

							unitTarget->RemoveFlag( UNIT_FIELD_AURASTATE,AURASTATE_FLAG_REJUVENATE );	
							sEventMgr.RemoveEvents( unitTarget,EVENT_REJUVENATION_FLAG_EXPIRE );
						}
					}
					if( new_dmg > 0 )
						Heal( (int32)new_dmg );
				}
			}break;
		default:
			Heal((int32)damage);
			break;
		}
	}
}

void Spell::SpellEffectQuestComplete(uint32 i) // Quest Complete
{
	//misc value is id of the quest to complete
}

//wand->
void Spell::SpellEffectWeapondamageNoschool(uint32 i) // Weapon damage + (no School)
{
	if(!unitTarget ||!u_caster)
		return;

	if( GetType() == SPELL_DMG_TYPE_RANGED && m_spellInfo->speed > 0.0f )
	{
		u_caster->Strike( unitTarget, RANGED, m_spellInfo, 0, 0, 0, false, true );
	}
	else
		u_caster->Strike( unitTarget, ( GetType() == SPELL_DMG_TYPE_RANGED ? RANGED : MELEE ), m_spellInfo, damage, 0, 0, false, true );
}

void Spell::SpellEffectAddExtraAttacks(uint32 i) // Add Extra Attacks
{
	if(!u_caster)
		return;
	u_caster->m_extraattacks += damage;		
}

void Spell::SpellEffectDodge(uint32 i)
{
	//i think this actually enbles the skill to be able to dodge melee+ranged attacks
	//value is static and sets value directly which will be modified by other factors
	//this is only basic value and will be overwiten elsewhere !!!
//	if(unitTarget->IsPlayer())
//		unitTarget->SetFloatValue(PLAYER_DODGE_PERCENTAGE,damage);
}

void Spell::SpellEffectParry(uint32 i)
{
	if(unitTarget)
		unitTarget->setcanperry(true);
}

void Spell::SpellEffectBlock(uint32 i)
{
	//i think this actually enbles the skill to be able to block melee+ranged attacks
	//value is static and sets value directly which will be modified by other factors
//	if(unitTarget->IsPlayer())
//		unitTarget->SetFloatValue(PLAYER_BLOCK_PERCENTAGE,damage);
}

void Spell::SpellEffectCreateItem(uint32 i) // Create item 
{
	if(!p_caster)
		return;

	ItemPointer newItem;
	ItemPointer add;
	uint8 slot;
	SlotResult slotresult;

	skilllinespell* skill = objmgr.GetSpellSkill(m_spellInfo->Id);

	for(int j=0; j<3; j++) // now create the Items
	{
		ItemPrototype *m_itemProto;
		m_itemProto = ItemPrototypeStorage.LookupEntry( m_spellInfo->EffectItemType[j] );
		if (!m_itemProto)
			 continue;

		if(m_spellInfo->EffectItemType[j] == 0)
			continue;

		uint32 item_count = 0;
		if (m_itemProto->Class != ITEM_CLASS_CONSUMABLE || m_spellInfo->SpellFamilyName != 3) //SpellFamilyName 3 is mage
			item_count = damage;
		else if(p_caster->getLevel() >= m_spellInfo->spellLevel)
			item_count = ((p_caster->getLevel() - (m_spellInfo->spellLevel-1))*damage);

		if(!item_count)
			item_count = damage;

		//conjure water ranks 7,8 & 9 and conjure food ranks 7 & 8 have different starting amounts
		// tailoring specializations get +1 cloth bonus
		switch(m_spellInfo->Id)
		{
		case 27389: //Conjure Food 7
		case 10140: //Conjure Water 7
		case 37420: //Conjure Water 8
			item_count += 8;
			break;
		case 36686: //Shadowcloth
			if(p_caster->HasSpell(26801)) item_count += 1;
			break;
		case 26751: // Primal Mooncloth
			if(p_caster->HasSpell(26798)) item_count += 1;
			break;
		case 31373: //Spellcloth
			if(p_caster->HasSpell(26797)) item_count += 1;
			break;
		}

		if (skill)
		{
			// Alchemy Specializations
			// http://www.wowwiki.com/Alchemy#Alchemy_Specializations
			if ( skill->skilline == SKILL_ALCHEMY && Rand(15) )
			{
				//Potion Master and Elixer Master (Elixers and Flasks)
				if( ( p_caster->HasSpell(28675) && m_itemProto->SubClass == ITEM_SUBCLASS_CONSUMABLE_POTION ) || 
					( p_caster->HasSpell(28677) && ( m_itemProto->SubClass == ITEM_SUBCLASS_CONSUMABLE_ELIXIR || m_itemProto->SubClass == ITEM_SUBCLASS_CONSUMABLE_FLASK ) ))
				{
					for(int x=0; x<5; x++)
					{
						SpellEntry *spellInfo;
						uint32 spellid = m_itemProto->Spells[x].Id;
						if ( spellid ) 
						{
							spellInfo = dbcSpell.LookupEntry(spellid);
							if ( spellInfo )
							{
								item_count = item_count + rand() % 4 + 1;
								break;
							}
						}
					}
				}
				//Transmutation Master
				else if ( p_caster->HasSpell(28672) && m_spellInfo->Category == 310 )
				{
					item_count = item_count + rand() % 4 + 1;
				}
			}
	
			// Profession Discoveries
			ProfessionDiscovery * pf = ProfessionDiscoveryStorage.LookupEntry( m_spellInfo->Id );
			if ( pf && !p_caster->HasSpell( pf->SpellToDiscover ) && Rand( pf->Chance )&& p_caster->_GetSkillLineCurrent( skill->skilline ) >= pf->SkillValue )
			{
				// if something discovered learn p_caster that recipe and broadcast message
				SpellEntry * se = dbcSpell.LookupEntry( pf->SpellToDiscover );
				if ( se != NULL )
				{
					p_caster->addSpell( pf->SpellToDiscover );
					WorldPacket * data;
					char msg[256];
					sprintf( msg, "%sDISCOVERY! %s has discovered how to create %s.|r", MSG_COLOR_GOLD, p_caster->GetName(), se->Name );
					data = sChatHandler.FillMessageData( CHAT_MSG_SYSTEM, LANG_UNIVERSAL,  msg, p_caster->GetGUID(), 0 );
					p_caster->GetMapMgr()->SendChatMessageToCellPlayers( p_caster, data, 2, 1, LANG_UNIVERSAL, p_caster->GetSession() );
				}
			}
		}

		// item count cannot be more than allowed in a single stack
		if (item_count > m_itemProto->MaxCount)
			item_count = m_itemProto->MaxCount;

		// item count cannot be more than item unique value
		if (m_itemProto->Unique && item_count > m_itemProto->Unique)
			item_count = m_itemProto->Unique;

		if(p_caster->GetItemInterface()->CanReceiveItem(m_itemProto, item_count, NULL)) //reversed since it sends >1 as invalid and 0 as valid
		{
			SendCastResult(SPELL_FAILED_TOO_MANY_OF_ITEM);
			return;
		}

		slot = 0;
		add = p_caster->GetItemInterface()->FindItemLessMax(m_spellInfo->EffectItemType[j],1, false);
		if (!add)
		{
			slotresult = p_caster->GetItemInterface()->FindFreeInventorySlot(m_itemProto);
			if(!slotresult.Result)
			{
				  SendCastResult(SPELL_FAILED_TOO_MANY_OF_ITEM);
				  return;
			}
			
			newItem =objmgr.CreateItem(m_spellInfo->EffectItemType[i],p_caster);
			newItem->SetUInt64Value(ITEM_FIELD_CREATOR,m_caster->GetGUID());
			newItem->SetUInt32Value(ITEM_FIELD_STACK_COUNT, item_count);

			if (m_itemProto->RandomPropId)
			{
				RandomProps * iRandomProperty = lootmgr.GetRandomProperties(m_itemProto);
				if( iRandomProperty )
				{
					newItem->SetRandomProperty(iRandomProperty->ID);
					newItem->ApplyRandomProperties(false);
				}
			}
			if (m_itemProto->RandomSuffixId)
			{
				ItemRandomSuffixEntry * iRandomSuffix = lootmgr.GetRandomSuffix(m_itemProto);
				if( iRandomSuffix )
				{
					newItem->SetRandomSuffix(iRandomSuffix->id);
					newItem->ApplyRandomProperties(false);
				}
			}

			if(p_caster->GetItemInterface()->SafeAddItem(newItem,slotresult.ContainerSlot, slotresult.Slot))
			{
				/*WorldPacket data(45);
				p_caster->GetSession()->BuildItemPushResult(&data, p_caster->GetGUID(), 1, item_count, m_spellInfo->EffectSpellGroupRelation[i] ,0,0xFF,1,0xFFFFFFFF);
				p_caster->SendMessageToSet(&data, true);*/
				p_caster->GetSession()->SendItemPushResult(newItem,true,false,true,true,slotresult.ContainerSlot,slotresult.Slot,item_count);
			} else {
				newItem->Destructor();
				newItem = NULLITEM;
			}

			if(skill)
				DetermineSkillUp(skill->skilline);
		} 
		else 
		{
			//scale item_count down if total stack will be more than 20
			if(add->GetUInt32Value(ITEM_FIELD_STACK_COUNT) + item_count > 20)
			{
				uint32 item_count_filled;
				item_count_filled = 20 - add->GetUInt32Value(ITEM_FIELD_STACK_COUNT);
				add->SetCount(20);
				add->m_isDirty = true;

				slotresult = p_caster->GetItemInterface()->FindFreeInventorySlot(m_itemProto);
				if(!slotresult.Result)
					item_count = item_count_filled;
				else
				{
					newItem =objmgr.CreateItem(m_spellInfo->EffectItemType[i],p_caster);
					newItem->SetUInt64Value(ITEM_FIELD_CREATOR,m_caster->GetGUID());
					newItem->SetUInt32Value(ITEM_FIELD_STACK_COUNT, item_count - item_count_filled);
					if(!p_caster->GetItemInterface()->SafeAddItem(newItem,slotresult.ContainerSlot, slotresult.Slot))
					{
						newItem->Destructor();
						newItem = NULLITEM;
						item_count = item_count_filled;
					}
					else
						p_caster->GetSession()->SendItemPushResult(newItem, true, false, true, true, slotresult.ContainerSlot, slotresult.Slot, item_count-item_count_filled);
                }
			}
			else
			{
				add->SetCount(add->GetUInt32Value(ITEM_FIELD_STACK_COUNT) + item_count);
				add->m_isDirty = true;
				p_caster->GetSession()->SendItemPushResult(add, true,false,true,false,p_caster->GetItemInterface()->GetBagSlotByGuid(add->GetGUID()),0xFFFFFFFF,item_count);
			}

			/*WorldPacket data(45);
			p_caster->GetSession()->BuildItemPushResult(&data, p_caster->GetGUID(), 1, item_count, m_spellInfo->EffectSpellGroupRelation[i] ,0,0xFF,1,0xFFFFFFFF);
			p_caster->SendMessageToSet(&data, true);*/
			if(skill)
				DetermineSkillUp(skill->skilline);
		}
	}	   
}

void Spell::SpellEffectWeapon(uint32 i)
{
	if( playerTarget == NULL )
		return;

	uint32 skill = 0;
	uint32 spell = 0;

	switch( this->m_spellInfo->Id )
	{
	case 201:    // one-handed swords
		{
			skill = SKILL_SWORDS;
		}break;
	case 202:   // two-handed swords
		{
			skill = SKILL_2H_SWORDS;
		}break;
	case 203:   // Unarmed
		{
			skill = SKILL_UNARMED;
		}break;
	case 199:   // two-handed maces
		{
			skill = SKILL_2H_MACES;
		}break;
	case 198:   // one-handed maces
		{
			skill = SKILL_MACES;
		}break;
	case 197:   // two-handed axes
		{
			skill = SKILL_2H_AXES;
		}break;
	case 196:   // one-handed axes
		{
			skill = SKILL_AXES;
		}break;
	case 5011: // crossbows
		{
			skill = SKILL_CROSSBOWS;
			spell = SPELL_RANGED_GENERAL;
		}break;
	case 227:   // staves
		{
			skill = SKILL_STAVES;
		}break;
	case 1180:  // daggers
		{
			skill = SKILL_DAGGERS;
		}break;
	case 200:   // polearms
		{
			skill = SKILL_POLEARMS;
		}break;
	case 15590: // fist weapons
		{
			skill = SKILL_UNARMED;
		}break;
	case 264:   // bows
		{
			skill = SKILL_BOWS;
			spell = SPELL_RANGED_GENERAL;
		}break;
	case 266: // guns
		{
			skill = SKILL_GUNS;
			spell = SPELL_RANGED_GENERAL;
		}break;
	case 2567:  // thrown
		{
			skill = SKILL_THROWN;
		}break;
	case 5009:  // wands
		{
			skill = SKILL_WANDS;
			spell = SPELL_RANGED_GENERAL;
		}break;
	//case 3386:  // spears
	//	skill = 0;   // ??!!
	//	break;
	default:
		{
			skill = 0;
			Log.Warning("Spell","Could not determine skill for spell id %d (SPELL_EFFECT_WEAPON)", this->m_spellInfo->Id);
		}break;
	}

	// Don't add skills to players logging in.
	/*if((m_spellInfo->Attributes & ATTRIBUTES_PASSIVE) && playerTarget->m_TeleportState == 1)
		return;*/

	if(skill)
	{
		if(spell)
			playerTarget->addSpell(spell);
		
		// if we do not have the skill line
		if(!playerTarget->_HasSkillLine(skill))
		{
			playerTarget->_AddSkillLine(skill, 1, playerTarget->getLevel()*5);
		}
		else // unhandled.... if we have the skill line
		{
		}
	}
}

void Spell::SpellEffectDefense(uint32 i)
{
	//i think this actually enbles the skill to be able to use defense
	//value is static and sets value directly which will be modified by other factors
	//this is only basic value and will be overwiten elsewhere !!!
//	if(unitTarget->IsPlayer())
//		unitTarget->SetFloatValue(UNIT_FIELD_RESISTANCES,damage);
}

void Spell::SpellEffectPersistentAA(uint32 i) // Persistent Area Aura
{
	if(m_AreaAura == true || !m_caster->IsInWorld())
		return;
	//create only 1 dyn object
	uint32 dur = GetDuration();
	float r = GetRadius(i);

	//Note: this code seems to be useless
	//this must be only source point or dest point
	//this AREA aura it's apllied on area
	//it can'be on unit or self or item or object
	//uncomment it if i'm wrong
	//We are thinking in general so it might be useful later DK
	DynamicObjectPointer dynObj = m_caster->GetMapMgr()->CreateDynamicObject();
	 
	if(g_caster && g_caster->IsInWorld() && g_caster->m_summoner)
	{
		if (g_caster->GetByte(GAMEOBJECT_BYTES_1, 1) == GAMEOBJECT_TYPE_TRAP && g_caster->m_summoner->dynObj != NULL)
			g_caster->m_summoner->dynObj->SetAliveDuration(1);
		
		if(!unitTarget)
		{
			dynObj->Create(g_caster, shared_from_this(), g_caster->GetPositionX(), g_caster->GetPositionY(), 
				g_caster->GetPositionZ(), dur, r);
		}
		else
		{
			dynObj->Create(g_caster, shared_from_this(), unitTarget->GetPositionX(), unitTarget->GetPositionY(),
				unitTarget->GetPositionZ(), dur, r);
		}
		m_AreaAura = true;
		return;
	}
		
	switch(m_targets.m_targetMask)
	{		
	case TARGET_FLAG_SELF:
		{
			dynObj->Create(u_caster, shared_from_this(),	m_caster->GetPositionX(), 
				m_caster->GetPositionY(), m_caster->GetPositionZ(), dur,r);		 
		}break;
	case TARGET_FLAG_UNIT:
		{
			if(!unitTarget||!unitTarget->isAlive())
				break;
			dynObj->Create( u_caster, shared_from_this(), unitTarget->GetPositionX(), unitTarget->GetPositionY(), unitTarget->GetPositionZ(),
				dur, r);
		}break;
	case TARGET_FLAG_OBJECT:
		{
			if(!unitTarget)
				break;
			if(!unitTarget->isAlive())
				break;
			dynObj->Create(u_caster, shared_from_this(), unitTarget->GetPositionX(), unitTarget->GetPositionY(), unitTarget->GetPositionZ(),
				dur, r);
		}break;
	case TARGET_FLAG_SOURCE_LOCATION:
		{
			dynObj->SetInstanceID(m_caster->GetInstanceID());
			dynObj->Create(u_caster, shared_from_this(), m_targets.m_srcX,
				m_targets.m_srcY, m_targets.m_srcZ, dur,r);
		}break;
	case TARGET_FLAG_DEST_LOCATION:
		{
			dynObj->SetInstanceID(m_caster->GetInstanceID());
			dynObj->Create(u_caster?u_caster:g_caster->m_summoner, shared_from_this(),
				m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ,dur,r);
		}break;
	default:
		return;
	}   
	
	if(u_caster)
	if(m_spellInfo->ChannelInterruptFlags > 0)
	{
		u_caster->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT,dynObj->GetGUID());
		u_caster->SetUInt32Value(UNIT_CHANNEL_SPELL,m_spellInfo->Id);
	}
	m_AreaAura = true;	
}

void Spell::SpellEffectSummon(uint32 i)
{
	if(!u_caster) return;

	SummonPropertiesEntry * spe = dbcSummonProps.LookupEntryForced( m_spellInfo->EffectMiscValueB[i] );
	if(!spe)
		return;

	m_summonProperties = spe;

	// Delete any objects in my slots. Slot 0 can have unlimited objects.
	if( spe->slot && spe->slot < 7 && u_caster->m_SummonSlots[ spe->slot ] )
	{
		if( u_caster->m_SummonSlots[ spe->slot ]->IsTotem() )
			u_caster->m_SummonSlots[ spe->slot ]->TotemExpire();
		else
			u_caster->m_SummonSlots[ spe->slot ]->SafeDelete();

		u_caster->m_SummonSlots[ spe->slot ] = NULLCREATURE;

		if( i_caster ) // Assume this is the 'toggle off' mode since we had one already.
			return;
	}

	switch( spe->Id )
	{
	case SUMMON_TYPE_POSSESSED:
		{
			SummonPossessed(i);
			break;
		}
	case SUMMON_TYPE_GUARDIAN:
		{
			SummonGuardian(i);
			break;
		}
	case SUMMON_TYPE_WILD:
		{
			SummonGuardian(i);
			break;
		}
	case SUMMON_TYPE_DEMON:
		{
			SummonGuardian(i);
			break;
		}
	case SUMMON_TYPE_TOTEM_1:
	case SUMMON_TYPE_TOTEM_2:
	case SUMMON_TYPE_TOTEM_3:
	case SUMMON_TYPE_TOTEM_4:
		{
			SummonTotem(i);
			break;
		}
	case SUMMON_TYPE_SUMMON:
		{
			SummonCreature(i);
			break;
		}
	case SUMMON_TYPE_CRITTER:
		{
			SummonNonCombatPet(i);
			break;
		}
	default:
		{
			SummonGuardian(i);
			break;
		}
	}
}

void Spell::SummonCreature(uint32 i) // Summon
{
	if(!p_caster || !p_caster->IsInWorld())
		return;

	/* This is for summon water elemenal, etc */
	CreatureInfo * ci = CreatureNameStorage.LookupEntry(m_spellInfo->EffectMiscValue[i]);
	CreatureProto * cp = CreatureProtoStorage.LookupEntry(m_spellInfo->EffectMiscValue[i]);
	if( !ci || !cp )
		return;

	if(m_spellInfo->EffectMiscValue[i] == 510)	// Water Elemental
	{
		PetPointer summon = objmgr.CreatePet();
		summon->SetInstanceID(m_caster->GetInstanceID());
		summon->CreateAsSummon(m_spellInfo->EffectMiscValue[i], ci, NULLCREATURE, p_caster, m_spellInfo, 1, 45000);
		summon->SetUInt32Value(UNIT_FIELD_LEVEL, p_caster->getLevel());
		summon->AddSpell(dbcSpell.LookupEntry(31707), true);
		summon->AddSpell(dbcSpell.LookupEntry(33395), true);
		summon->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, p_caster->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE));
		summon->_setFaction();
		if(p_caster->IsPvPFlagged())
			summon->SetPvPFlag();
		if( m_summonProperties->slot < 7 )
			p_caster->m_SummonSlots[ m_summonProperties->slot ] = summon;
	}
	else
	{
		float x, y, z;
		if( m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION && m_targets.m_destX && m_targets.m_destY && m_targets.m_destZ )
		{
			x = m_targets.m_destX;
			y = m_targets.m_destY;
			z = m_targets.m_destZ;
		}
		else
		{
			x = u_caster->GetPositionX();
			y = u_caster->GetPositionY();
			z = u_caster->GetPositionZ();
		}
		uint32 health = 0;
		uint32 count = m_spellInfo->EffectBasePoints[i] + 1;
		if( m_summonProperties->unk2 & 2 ) // one, please.
		{
			count = 1;
			health = m_spellInfo->EffectBasePoints[i] + 1;
		}

		for (uint32 j=0; j<count; j++)
		{
			CreaturePointer pCreature;
			float m_fallowAngle=-((float(M_PI)/2)*j);
			x += (GetRadius(i)*(cosf(m_fallowAngle+u_caster->GetOrientation())));
			y += (GetRadius(i)*(sinf(m_fallowAngle+u_caster->GetOrientation())));

			pCreature = p_caster->GetMapMgr()->CreateCreature(cp->Id);
			pCreature->Load(cp, x, y, z, p_caster->GetOrientation());
			if(health)
			{
				pCreature->SetUInt32Value(UNIT_FIELD_MAXHEALTH, health);
				pCreature->SetUInt32Value(UNIT_FIELD_HEALTH, health);
			}
			pCreature->_setFaction();
			pCreature->GetAIInterface()->Init(pCreature,AITYPE_PET,MOVEMENTTYPE_NONE,u_caster);
			pCreature->GetAIInterface()->SetUnitToFollow(u_caster);
			pCreature->GetAIInterface()->SetUnitToFollowAngle(float(-(M_PI/2)));
			pCreature->GetAIInterface()->SetFollowDistance(3.0f);
			pCreature->SetUInt32Value(UNIT_FIELD_LEVEL, p_caster->getLevel());
			pCreature->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, p_caster->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE));
			pCreature->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, p_caster->GetGUID());
			pCreature->_setFaction();
			p_caster->SetUInt64Value(UNIT_FIELD_SUMMON, pCreature->GetGUID());
			if( m_summonProperties->slot < 7 )
				p_caster->m_SummonSlots[ m_summonProperties->slot ] = pCreature;

			if ( m_spellInfo->EffectMiscValue[i] == 19668 ) //shadowfiend
			{
				float parent_bonus = (float)(p_caster->GetDamageDoneMod(SCHOOL_SHADOW)*0.065f);
				pCreature->SetFloatValue(UNIT_FIELD_MINDAMAGE, pCreature->GetFloatValue(UNIT_FIELD_MINDAMAGE) + parent_bonus);
				pCreature->SetFloatValue(UNIT_FIELD_MAXDAMAGE, pCreature->GetFloatValue(UNIT_FIELD_MAXDAMAGE) + parent_bonus);
				pCreature->BaseDamage[0] += parent_bonus;
				pCreature->BaseDamage[1] += parent_bonus;
			}		

			pCreature->PushToWorld(p_caster->GetMapMgr());
			sEventMgr.AddEvent(pCreature, &Creature::SafeDelete, EVENT_CREATURE_REMOVE_CORPSE, GetDuration(), 1, 0);
		}
	}
}

void Spell::SpellEffectLeap(uint32 i) // Leap
{
	float radius = GetRadius(i);

	//FIXME: check for obstacles
	 
	/*float ori = m_caster->GetOrientation();				
	float posX = m_caster->GetPositionX()+(radius*(cos(ori)));
	float posY = m_caster->GetPositionY()+(radius*(sin(ori)));
	float z= m_caster->GetMapMgr()->GetLandHeight(posX,posY);

	if(fabs(p_caster->GetPositionZ() - z) > 2)
		z=p_caster->GetPositionZ()+2;

	m_caster->SetPosition(posX,posY,z,ori,true);

	WorldPacket data(MSG_MOVE_HEARTBEAT, 33);
	data << m_caster->GetNewGUID();
	data << uint32(0) << uint32(0);
	data << posX;
	data << posY;
	data << z;
	data << ori;
	m_caster->SendMessageToSet(&data, true); */

	if(!p_caster) return;

	// remove movement impeding auras
	p_caster->RemoveAurasByInterruptFlag(AURA_INTERRUPT_ON_ANY_DAMAGE_TAKEN);

	if(p_caster->m_bg && !p_caster->m_bg->HasStarted())
		return;

	// just in case
	for(uint32 i = MAX_POSITIVE_AURAS; i < MAX_AURAS; ++i)
	{
		if( p_caster->m_auras[i] != NULL )
		{
			for(uint32 j = 0; j < 3; ++j)
			{
				if( p_caster->m_auras[i]->GetSpellProto()->EffectApplyAuraName[j] == SPELL_AURA_MOD_STUN || 
					p_caster->m_auras[i]->GetSpellProto()->EffectApplyAuraName[j] == SPELL_AURA_MOD_ROOT )
				{
					p_caster->m_auras[i]->Remove();
					break;
				}
			}
		}
	}

	if (p_caster->GetMapMgr() && p_caster->GetMapMgr()->IsCollisionEnabled())
	{
		float ori = m_caster->GetOrientation();				
		float posX = m_caster->GetPositionX()+(radius*(cosf(ori)));
		float posY = m_caster->GetPositionY()+(radius*(sinf(ori)));
		float posZ;
		/*float posZ = CollideInterface.GetHeight(m_caster->GetMapId(), posX, posY, m_caster->GetPositionZ());
		if(posZ == NO_WMO_HEIGHT)		// not found height, or on adt
			posZ = m_caster->GetMapMgr()->GetLandHeight(posX,posY);

		if( fabs( posZ - m_caster->GetPositionZ() ) >= 10.0f )
			return;*/

		if( CollideInterface.GetFirstPoint(m_caster->GetMapId(), m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), 
				posX, posY, m_caster->GetPositionZ() + 2.0f, posX, posY, posZ, -1.5f) )
		{
			float fz2 = CollideInterface.GetHeight(m_caster->GetMapId(), posX, posY, posZ);
			if( fz2 != NO_WMO_HEIGHT )
				posZ = fz2;

			p_caster->blinked = true;
			p_caster->SafeTeleport( p_caster->GetMapId(), p_caster->GetInstanceID(), posX, posY, posZ, m_caster->GetOrientation() );

			// reset heartbeat for a little while, 5 seconds maybe?
			p_caster->DelaySpeedHack( 5000 );
			++p_caster->m_heartbeatDisable;
			p_caster->z_axisposition = 0.0f;
		}
		else
		{
			// either no objects in the way, or no wmo height
			posZ = CollideInterface.GetHeight(m_caster->GetMapId(), posX, posY, m_caster->GetPositionZ());
			if(posZ == NO_WMO_HEIGHT)		// not found height, or on adt
				posZ = m_caster->GetMapMgr()->GetLandHeight(posX,posY);

			if( fabs( posZ - m_caster->GetPositionZ() ) >= 10.0f )
				return;

			p_caster->blinked = true;
			p_caster->SafeTeleport( p_caster->GetMapId(), p_caster->GetInstanceID(), posX, posY, posZ, m_caster->GetOrientation() );

			// reset heartbeat for a little while, 5 seconds maybe?
			p_caster->DelaySpeedHack( 5000 );
			++p_caster->m_heartbeatDisable;
			p_caster->z_axisposition = 0.0f;
		}
	}
	else
	{
		p_caster->blinked = true;

		WorldPacket data(SMSG_MOVE_KNOCK_BACK, 50);
		data << p_caster->GetNewGUID();
		data << getMSTime();
		data << cosf(p_caster->GetOrientation()) << sinf(p_caster->GetOrientation());
		data << radius;
		data << float(-10.0f);
		p_caster->GetSession()->SendPacket(&data);
		//m_caster->SendMessageToSet(&data, true);

		// reset heartbeat for a little while, 2 seconds maybe?
		p_caster->DelaySpeedHack( 10000 );
		++p_caster->m_heartbeatDisable;
		p_caster->z_axisposition = 0.0f;
	}
}

void Spell::SpellEffectEnergize(uint32 i) // Energize
{
	if(!unitTarget || !unitTarget->isAlive())
		return;

	uint32 modEnergy;
	//yess there is always someone special : shamanistic rage - talent
	if(m_spellInfo->Id==30824)
		modEnergy = damage*GetUnitTarget()->GetAP()/100;
	//paladin illumination
	else if(m_spellInfo->Id==20272 && ProcedOnSpell)
	{
		SpellEntry *motherspell=dbcSpell.LookupEntry(pSpellId);
		if(motherspell)
			modEnergy = (motherspell->EffectBasePoints[0]+1)*ProcedOnSpell->manaCost/100;
	}
	//paladin - Spiritual Attunement 
	else if(m_spellInfo->Id==31786 && ProcedOnSpell)
	{
		SpellEntry *motherspell=dbcSpell.LookupEntry(pSpellId);
		if(motherspell)
		{
			//heal amount from procspell (we only proced on a heal spell)
			uint32 healamt=0;
			if(ProcedOnSpell->Effect[0]==SPELL_EFFECT_HEAL || ProcedOnSpell->Effect[0]==SPELL_EFFECT_SCRIPT_EFFECT)
				healamt=ProcedOnSpell->EffectBasePoints[0]+1;
			else if(ProcedOnSpell->Effect[1]==SPELL_EFFECT_HEAL || ProcedOnSpell->Effect[1]==SPELL_EFFECT_SCRIPT_EFFECT)
				healamt=ProcedOnSpell->EffectBasePoints[1]+1;
			else if(ProcedOnSpell->Effect[2]==SPELL_EFFECT_HEAL || ProcedOnSpell->Effect[2]==SPELL_EFFECT_SCRIPT_EFFECT)
				healamt=ProcedOnSpell->EffectBasePoints[2]+1;
			modEnergy = (motherspell->EffectBasePoints[0]+1)*(healamt)/100;
		}
	}
	else if (m_spellInfo->Id==2687){
		modEnergy = damage;
		if( p_caster != NULL )
		{
			/*for(set<uint32>::iterator itr = p_caster->mSpells.begin(); itr != p_caster->mSpells.end(); ++itr)
			{
				if(*itr == 12818)
					modEnergy += 60;
				else if(*itr == 12301)
					modEnergy += 30;
			}*/
			if(p_caster->mSpells.find(12818) != p_caster->mSpells.end())
				modEnergy += 60;
			if(p_caster->mSpells.find(12301) != p_caster->mSpells.end())
				modEnergy += 30;
		}
	}
	else  
        modEnergy = damage;

	u_caster->Energize(unitTarget, m_spellInfo->logsId ? m_spellInfo->logsId : (pSpellId ? pSpellId : m_spellInfo->Id), 
		modEnergy, m_spellInfo->EffectMiscValue[i]);
}

void Spell::SpellEffectWeaponDmgPerc(uint32 i) // Weapon Percent damage
{
	if(!unitTarget  || !u_caster)
		return;

	uint32 _type;
	if( GetType() == SPELL_DMG_TYPE_RANGED )
		_type = RANGED;
	else
	{
		if (m_spellInfo->Flags4 & FLAGS4_OFFHAND)
			_type = OFFHAND;
		else
			_type = MELEE;
	}

	if( GetType() == SPELL_DMG_TYPE_MAGIC )
	{
		float fdmg = (float)CalculateDamage( u_caster, unitTarget, _type, m_spellInfo );
		uint32 dmg = float2int32(fdmg*(float(damage/100.0f)));
		u_caster->SpellNonMeleeDamageLog(unitTarget, m_spellInfo->Id, dmg, false, false, false);
	}
	else
	{
		u_caster->Strike( unitTarget, _type, m_spellInfo, add_damage, damage, 0, false, true );
	}
}

void Spell::SpellEffectTriggerMissile(uint32 i) // Trigger Missile
{
	//Used by mortar team
	//Triggers area affect spell at destinatiom
	if(!m_caster)
		return;

	uint32 spellid = m_spellInfo->EffectTriggerSpell[i];
	if(spellid == 0)
		return;

	SpellEntry *spInfo = dbcSpell.LookupEntry(spellid);
	if(!spInfo)
		return;

	float spellRadius = GetRadius(i);

	for(unordered_set<ObjectPointer >::iterator itr = m_caster->GetInRangeSetBegin(); itr != m_caster->GetInRangeSetEnd(); itr++ )
	{
		if(!((*itr)->IsUnit()) || !(TO_UNIT(*itr))->isAlive())
			continue;
		UnitPointer t=TO_UNIT(*itr);
	
		float r;
		float d=m_targets.m_destX-t->GetPositionX();
		r=d*d;
		d=m_targets.m_destY-t->GetPositionY();
		r+=d*d;
		d=m_targets.m_destZ-t->GetPositionZ();
		r+=d*d;
		if(sqrt(r)> spellRadius)
			continue;
		
		if(!isAttackable(m_caster, TO_UNIT(*itr)))//Fixme only enemy targets?
			continue;

		SpellPointer sp=CREATESPELL(m_caster,spInfo,true,NULLAURA);
		SpellCastTargets tgt;
		tgt.m_unitTarget=(*itr)->GetGUID();
		sp->prepare(&tgt);
	}
}

void Spell::SpellEffectOpenLock(uint32 i) // Open Lock
{
	if(!p_caster)
		return;

	if( p_caster->InStealth() )
	{
		p_caster->RemoveAura(p_caster->m_stealth);
		p_caster->m_stealth = 0;
	}
		
	uint8 loottype = 0;

	uint32 locktype=m_spellInfo->EffectMiscValue[i];
	switch(locktype)
	{
		case LOCKTYPE_PICKLOCK:
		{
			uint32 v = 0;
			uint32 lockskill = p_caster->_GetSkillLineCurrent(SKILL_LOCKPICKING);

			if(itemTarget)
			{	
				if(!itemTarget->locked)
				return;
						
				Lock *lock = dbcLock.LookupEntry( itemTarget->GetProto()->LockId );
				if(!lock) return;
				for(int i=0;i<5;i++)
					if(lock->locktype[i] == 2 && lock->minlockskill[i] && lockskill >= lock->minlockskill[i])
					{
						v = lock->minlockskill[i];
						itemTarget->locked = false;
						itemTarget->SetFlag(ITEM_FIELD_FLAGS,4); // unlock
						DetermineSkillUp(SKILL_LOCKPICKING,v/5);
						break;
					}
			}
			else if(gameObjTarget)
			{
				if(gameObjTarget->GetByte(GAMEOBJECT_BYTES_1, GAMEOBJECT_BYTES_STATE) == 0)
					return;

				Lock *lock = dbcLock.LookupEntryForced(gameObjTarget->GetInfo()->SpellFocus);
				if( lock == NULL )
					return;

				for(int i=0;i<5;i++)
				{
					if(lock->locktype[i] == 2 && lock->minlockskill[i] && lockskill >= lock->minlockskill[i])
					{
						v = lock->minlockskill[i];
						gameObjTarget->SetUInt32Value(GAMEOBJECT_FLAGS, 0);
						gameObjTarget->SetByte(GAMEOBJECT_BYTES_1,GAMEOBJECT_BYTES_STATE, 1);
						lootmgr.FillGOLoot(&gameObjTarget->m_loot,gameObjTarget->GetEntry(), gameObjTarget->GetMapMgr() ? (gameObjTarget->GetMapMgr()->iInstanceMode ? true : false) : false);
						loottype = LOOT_CORPSE;
						DetermineSkillUp(SKILL_LOCKPICKING,v/5);
						break;
					}
				}
			}
		}break;
		case LOCKTYPE_HERBALISM:
		{
			if(!gameObjTarget) return;	  
			
			uint32 v = gameObjTarget->GetGOReqSkill();
			bool bAlreadyUsed = false;
		 
			if(Rand(100.0f)) // 3% chance to fail//why?
			{
				if( TO_PLAYER( m_caster )->_GetSkillLineCurrent( SKILL_HERBALISM ) < v )
				{
					//SendCastResult(SPELL_FAILED_LOW_CASTLEVEL);
					return;
				}
				else
				{
					if( gameObjTarget->m_loot.items.size() == 0 )
					{
						lootmgr.FillGOLoot(&gameObjTarget->m_loot,gameObjTarget->GetEntry(), gameObjTarget->GetMapMgr() ? (gameObjTarget->GetMapMgr()->iInstanceMode ? true : false) : false);
					}
					else
						bAlreadyUsed = true;
				}
				loottype = LOOT_SKINNING;
			}
			else
			{
				/*
				if(rand()%100 <= 30)
				{
					//30% chance to not be able to reskin on fail
					TO_CREATURE(unitTarget)->Skinned = true;
					WorldPacket *pkt=unitTarget->BuildFieldUpdatePacket(UNIT_FIELD_FLAGS,0);
					TO_PLAYER( m_caster )->GetSession()->SendPacket(pkt);
					delete pkt;

				}*/
				SendCastResult(SPELL_FAILED_TRY_AGAIN);
			}
			//Skill up
			if(!bAlreadyUsed) //Avoid cheats with opening/closing without taking the loot
				DetermineSkillUp(SKILL_HERBALISM,v/5); 
		}
		break;
		case LOCKTYPE_MINING:
		{
			if(!gameObjTarget) return;

			uint32 v = gameObjTarget->GetGOReqSkill();
			bool bAlreadyUsed = false;

			if( Rand( 100.0f ) ) // 3% chance to fail//why?
			{
				if( TO_PLAYER( m_caster )->_GetSkillLineCurrent( SKILL_MINING ) < v )
				{
					//SendCastResult(SPELL_FAILED_LOW_CASTLEVEL);
					return;
				}
				else if( gameObjTarget->m_loot.items.size() == 0 )
				{
					lootmgr.FillGOLoot(&gameObjTarget->m_loot,gameObjTarget->GetEntry(), gameObjTarget->GetMapMgr() ? (gameObjTarget->GetMapMgr()->iInstanceMode ? true : false) : false);
				}	
				else
					bAlreadyUsed = true;

				loottype = LOOT_SKINNING;
			}
			else
			{
				SendCastResult(SPELL_FAILED_TRY_AGAIN);
			}
			//Skill up
			if(!bAlreadyUsed) //Avoid cheats with opening/closing without taking the loot
				DetermineSkillUp(SKILL_MINING,v/5);
		}
		break;
		case LOCKTYPE_SLOW_OPEN: // used for BG go's
		{
			if(!gameObjTarget ) return;
			if(p_caster->m_bgFlagIneligible) return;

			if(p_caster && p_caster->m_bg)
				if(p_caster->m_bg->HookSlowLockOpen(gameObjTarget,p_caster,shared_from_this()))
					return;

			uint32 spellid = !gameObjTarget->GetInfo()->Unknown1 ? 23932 : gameObjTarget->GetInfo()->Unknown1;
			SpellEntry*en=dbcSpell.LookupEntry(spellid);
			SpellPointer sp = CREATESPELL(p_caster,en,true,NULLAURA);
			SpellCastTargets tgt;
			tgt.m_unitTarget=gameObjTarget->GetGUID();
			sp->prepare(&tgt);
		}	
		break;
		case LOCKTYPE_QUICK_CLOSE:
			{
				if(!gameObjTarget ) return;
				gameObjTarget->EventCloseDoor();
			}
		break;
		default://not profession
		{
			if(!gameObjTarget ) return;
			if(sQuestMgr.OnActivateQuestGiver(gameObjTarget, p_caster))
				return;

			if( gameObjTarget->GetByte(GAMEOBJECT_BYTES_1, 1) == GAMEOBJECT_TYPE_GOOBER)
				CALL_GO_SCRIPT_EVENT(gameObjTarget, OnActivate)(TO_PLAYER(p_caster));

			if(sQuestMgr.OnGameObjectActivate(p_caster, gameObjTarget))
			{
				p_caster->UpdateNearbyGameObjects();
				return;
			}

			if(gameObjTarget->m_loot.items.size() == 0)
			{
				lootmgr.FillGOLoot(&gameObjTarget->m_loot,gameObjTarget->GetEntry(), gameObjTarget->GetMapMgr() ? (gameObjTarget->GetMapMgr()->iInstanceMode ? true : false) : false);
			}
			loottype=LOOT_CORPSE;
		}
		break;
	};
	if( gameObjTarget != NULL && gameObjTarget->GetByte(GAMEOBJECT_BYTES_1, 1) == GAMEOBJECT_TYPE_CHEST)
		TO_PLAYER( m_caster )->SendLoot( gameObjTarget->GetGUID(), loottype );
}

void Spell::SpellEffectOpenLockItem(uint32 i)
{
	UnitPointer caster = u_caster;
	if(!caster && i_caster)
		caster = i_caster->GetOwner();

	if(!gameObjTarget || !gameObjTarget->IsInWorld()) 
		return;

	if( caster && caster->IsPlayer() && sQuestMgr.OnGameObjectActivate( (TO_PLAYER(caster)), gameObjTarget ) )
		TO_PLAYER(caster)->UpdateNearbyGameObjects();
	
	CALL_GO_SCRIPT_EVENT(gameObjTarget, OnActivate)(TO_PLAYER(caster));
	gameObjTarget->SetByte(GAMEOBJECT_BYTES_1,GAMEOBJECT_BYTES_STATE, 0);	

	if( gameObjTarget->GetEntry() == 183146)
	{
		gameObjTarget->Despawn(1);
		return;
	}

	if( gameObjTarget->GetByte(GAMEOBJECT_BYTES_1, 1) == GAMEOBJECT_TYPE_CHEST)
	{
		lootmgr.FillGOLoot(&gameObjTarget->m_loot,gameObjTarget->GetEntry(), gameObjTarget->GetMapMgr() ? (gameObjTarget->GetMapMgr()->iInstanceMode ? true : false) : false);
		if(gameObjTarget->m_loot.items.size() > 0)
		{
			TO_PLAYER(caster)->SendLoot(gameObjTarget->GetGUID(),LOOT_CORPSE);
		}
		gameObjTarget->SetUInt32Value(GAMEOBJECT_FLAGS, 1);
	}

	if( gameObjTarget->GetByte(GAMEOBJECT_BYTES_1, 1) == GAMEOBJECT_TYPE_DOOR)
	{
		gameObjTarget->SetUInt32Value(GAMEOBJECT_FLAGS, 33);

		if(gameObjTarget->GetMapMgr()->GetMapInfo()->type==INSTANCE_NULL)//dont close doors for instances
			sEventMgr.AddEvent(gameObjTarget,&GameObject::EventCloseDoor, EVENT_GAMEOBJECT_DOOR_CLOSE,10000,1,0);
	}

	sEventMgr.AddEvent(gameObjTarget, &GameObject::Despawn, (uint32)1, EVENT_GAMEOBJECT_ITEM_SPAWN, 6*60*1000, 1, 0);
}

void Spell::SpellEffectProficiency(uint32 i)
{
	uint32 skill = 0;
	skilllinespell* skillability = objmgr.GetSpellSkill(m_spellInfo->Id);
	if (skillability)
		skill = skillability->skilline;
	skilllineentry* sk = dbcSkillLine.LookupEntry(skill);
	if(skill)
	{
		if(playerTarget)
		{
			if(playerTarget->_HasSkillLine(skill))
			{
				// Increase it by one
			   // playerTarget->AdvanceSkillLine(skill);
			}
			else
			{
				// Don't add skills to players logging in.
				/*if((m_spellInfo->Attributes & 64) && playerTarget->m_TeleportState == 1)
					return;*/

				if(sk && sk->type == SKILL_TYPE_WEAPON)
					playerTarget->_AddSkillLine(skill, 1, 5*playerTarget->getLevel());
				else
					playerTarget->_AddSkillLine(skill, 1, 1);				
			}
		}
	}
}

void Spell::SpellEffectSendEvent(uint32 i) //Send Event
{
	//This is mostly used to trigger events on quests or some places

	uint32 spellId = m_spellInfo->Id;

	// Try a dummy SpellHandler
	if(sScriptMgr.CallScriptedDummySpell(spellId, i, shared_from_this()))
		return;

	switch(spellId)
	{

	// Place Loot
	case 25720: // Places the Bag of Gold at the designated Drop-Off Point.
		{

		}break;

	// Item - Cleansing Vial DND
	case 29297: // Empty the vial near the Bones of Aggonar to cleanse the waters of their demonic taint.
		{
			QuestLogEntry *en=p_caster->GetQuestLogForEntry(9427);
			if(!en)
				return;
			en->SendQuestComplete();
		}break;

	//Warlock: Summon Succubus Quest
	case 8674:
	case 9223:
	case 9224:
		{
			CreatureInfo * ci = CreatureNameStorage.LookupEntry(5677);
			CreatureProto * cp = CreatureProtoStorage.LookupEntry(5677);
			if( !ci || !cp )
				return;

		   CreaturePointer pCreature = p_caster->GetMapMgr()->CreateCreature(cp->Id);
		   pCreature->Load(cp, p_caster->GetPositionX(), p_caster->GetPositionY(), p_caster->GetPositionZ(), p_caster->GetOrientation());
		   pCreature->_setFaction();
		   pCreature->GetAIInterface()->Init(pCreature,AITYPE_AGRO,MOVEMENTTYPE_NONE);
		   pCreature->GetAIInterface()->taunt(p_caster,true);
		   pCreature->_setFaction();
		   pCreature->PushToWorld(p_caster->GetMapMgr());
		   sEventMgr.AddEvent(pCreature, &Creature::SafeDelete, EVENT_CREATURE_REMOVE_CORPSE,60000, 1, 0);
		}break;

	//Warlock: Summon Voidwalker Quest
	case 30208:
	case 9221:
	case 9222:
	case 7728:
		{
			CreatureInfo * ci = CreatureNameStorage.LookupEntry(5676);
			CreatureProto * cp = CreatureProtoStorage.LookupEntry(5676);
			if( !ci || !cp )
				return;

		   CreaturePointer pCreature = p_caster->GetMapMgr()->CreateCreature(cp->Id);
		   pCreature->Load(cp, p_caster->GetPositionX(), p_caster->GetPositionY(), p_caster->GetPositionZ(), p_caster->GetOrientation());
		   pCreature->_setFaction();
		   pCreature->GetAIInterface()->Init(pCreature,AITYPE_AGRO,MOVEMENTTYPE_NONE);
		   pCreature->GetAIInterface()->taunt(p_caster,true);
		   pCreature->_setFaction();
		   pCreature->PushToWorld(p_caster->GetMapMgr());
		   sEventMgr.AddEvent(pCreature, &Creature::SafeDelete, EVENT_CREATURE_REMOVE_CORPSE,60000, 1, 0);
		}break;

	//Warlock: Summon Felhunter Quest
	case 8712:
		{
			CreatureInfo * ci = CreatureNameStorage.LookupEntry(6268);
			CreatureProto * cp = CreatureProtoStorage.LookupEntry(6268);
			if( !ci || !cp )
				return;

		   CreaturePointer pCreature = p_caster->GetMapMgr()->CreateCreature(cp->Id);
		   pCreature->Load(cp, p_caster->GetPositionX(), p_caster->GetPositionY(), p_caster->GetPositionZ(), p_caster->GetOrientation());
		   pCreature->_setFaction();
		   pCreature->GetAIInterface()->Init(pCreature,AITYPE_AGRO,MOVEMENTTYPE_NONE);
		   pCreature->GetAIInterface()->taunt(p_caster,true);
		   pCreature->_setFaction();
		   pCreature->PushToWorld(p_caster->GetMapMgr());
		   sEventMgr.AddEvent(pCreature, &Creature::SafeDelete, EVENT_CREATURE_REMOVE_CORPSE,60000, 1, 0);
		}break;

	}
}

void Spell::SpellEffectApplyAA(uint32 i) // Apply Area Aura
{
	if(!unitTarget || !unitTarget->isAlive())
		return;
	if(u_caster!=unitTarget)
		return;

	AuraPointer pAura;
	std::map<uint32,AuraPointer >::iterator itr=unitTarget->tmpAura.find(m_spellInfo->Id);
	if(itr==unitTarget->tmpAura.end())
	{
		pAura = AuraPointer(new Aura(m_spellInfo,GetDuration(),m_caster,unitTarget));
		
		unitTarget->tmpAura [m_spellInfo->Id]= pAura;
	
		float r=GetRadius(i);
		r *= r;
		if(!sEventMgr.HasEvent(pAura, EVENT_AREAAURA_UPDATE))		/* only add it once */
		{
			if( u_caster->IsPlayer() || (u_caster->GetTypeId() == TYPEID_UNIT && TO_CREATURE(u_caster)->IsTotem() ))
				sEventMgr.AddEvent(pAura, &Aura::EventUpdatePlayerAA,r, EVENT_AREAAURA_UPDATE, m_spellInfo->area_aura_update_interval, 0,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);	
			else if( u_caster->GetTypeId() == TYPEID_UNIT )
			{
				sEventMgr.AddEvent(pAura, &Aura::EventUpdateCreatureAA,r, EVENT_AREAAURA_UPDATE, m_spellInfo->area_aura_update_interval, 0,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);	
				pAura->m_creatureAA = true;
			}
		}
	}else 
	{
		pAura=itr->second;	
	}
 
	pAura->AddMod(m_spellInfo->EffectApplyAuraName[i],damage,m_spellInfo->EffectMiscValue[i],i);
}

void Spell::SpellEffectLearnSpell(uint32 i) // Learn Spell
{
	if(playerTarget == 0 && unitTarget && unitTarget->IsPet())
	{
		// bug in target map fill?
		//playerTarget = m_caster->GetMapMgr()->GetPlayer((uint32)m_targets.m_unitTarget);
		SpellEffectLearnPetSpell(i);
		return;
	}

	if( m_spellInfo->Id == 483 || m_spellInfo->Id == 55884 )		// "Learning"
	{
		if( !i_caster || !p_caster )
			return;

		uint32 spellid = 0;
		for(int i = 0; i < 5; ++i)
		{
			if( i_caster->GetProto()->Spells[i].Trigger == LEARNING && i_caster->GetProto()->Spells[i].Id != 0 )
			{
				spellid = i_caster->GetProto()->Spells[i].Id;
				break;
			}
		}

		if( !spellid || !dbcSpell.LookupEntryForced(spellid) )
			return;

		// learn me!
		p_caster->addSpell( spellid );

		// no normal handler
		return;
	}

	if(playerTarget)
	{
		/*if(u_caster && isHostile(playerTarget, u_caster))
			return;*/

		uint32 spellToLearn = m_spellInfo->EffectTriggerSpell[i];
		playerTarget->addSpell(spellToLearn);
		//smth is wrong here, first we add this spell to player then we may cast it on player...
		SpellEntry *spellinfo = dbcSpell.LookupEntry(spellToLearn);
 		//remove specializations
		switch(spellinfo->Id)
 		{
		case 26801: //Shadoweave Tailoring
			playerTarget->removeSpell(26798,false,false,0); //Mooncloth Tailoring
			playerTarget->removeSpell(26797,false,false,0); //Spellfire Tailoring
 			break;
		case 26798: // Mooncloth Tailoring
			playerTarget->removeSpell(26801,false,false,0); //Shadoweave Tailoring
			playerTarget->removeSpell(26797,false,false,0); //Spellfire Tailoring
 			break;
		case 26797: //Spellfire Tailoring
			playerTarget->removeSpell(26801,false,false,0); //Shadoweave Tailoring
			playerTarget->removeSpell(26798,false,false,0); //Mooncloth Tailoring
 			break;
 		case 10656: //Dragonscale Leatherworking
			playerTarget->removeSpell(10658,false,false,0); //Elemental Leatherworking
			playerTarget->removeSpell(10660,false,false,0); //Tribal Leatherworking
 			break;
 		case 10658: //Elemental Leatherworking
			playerTarget->removeSpell(10656,false,false,0); //Dragonscale Leatherworking
			playerTarget->removeSpell(10660,false,false,0); //Tribal Leatherworking
 			break;
 		case 10660: //Tribal Leatherworking
			playerTarget->removeSpell(10656,false,false,0); //Dragonscale Leatherworking
			playerTarget->removeSpell(10658,false,false,0); //Elemental Leatherworking
 			break;
 		case 28677: //Elixir Master
			playerTarget->removeSpell(28675,false,false,0); //Potion Master
			playerTarget->removeSpell(28672,false,false,0); //Transmutation Maste
 			break;
 		case 28675: //Potion Master
			playerTarget->removeSpell(28677,false,false,0); //Elixir Master
			playerTarget->removeSpell(28672,false,false,0); //Transmutation Maste
 			break;
 		case 28672: //Transmutation Master
			playerTarget->removeSpell(28675,false,false,0); //Potion Master
			playerTarget->removeSpell(28677,false,false,0); //Elixir Master
 			break;
 		case 20219: //Gnomish Engineer
			playerTarget->removeSpell(20222,false,false,0); //Goblin Engineer
 			break;
 		case 20222: //Goblin Engineer
			playerTarget->removeSpell(20219,false,false,0); //Gnomish Engineer
 			break;
 		case 9788: //Armorsmith
			playerTarget->removeSpell(9787,false,false,0); //Weaponsmith
			playerTarget->removeSpell(17039,false,false,0); //Master Swordsmith
			playerTarget->removeSpell(17040,false,false,0); //Master Hammersmith
			playerTarget->removeSpell(17041,false,false,0); //Master Axesmith
 			break;
 		case 9787: //Weaponsmith
			playerTarget->removeSpell(9788,false,false,0); //Armorsmith
 			break;
 		case 17041: //Master Axesmith
			playerTarget->removeSpell(9788,false,false,0); //Armorsmith
			playerTarget->removeSpell(17040,false,false,0); //Master Hammersmith
			playerTarget->removeSpell(17039,false,false,0); //Master Swordsmith
 			break;
 		case 17040: //Master Hammersmith
			playerTarget->removeSpell(9788,false,false,0); //Armorsmith
			playerTarget->removeSpell(17039,false,false,0); //Master Swordsmith
			playerTarget->removeSpell(17041,false,false,0); //Master Axesmith
 			break;
 		case 17039: //Master Swordsmith
			playerTarget->removeSpell(9788,false,false,0); //Armorsmith
			playerTarget->removeSpell(17040,false,false,0); //Master Hammersmith
			playerTarget->removeSpell(17041,false,false,0); //Master Axesmith
 			break;
 		}
		for(uint32 i=0;i<3;i++)
			if(spellinfo->Effect[i] == SPELL_EFFECT_WEAPON ||
			   spellinfo->Effect[i] == SPELL_EFFECT_PROFICIENCY ||
			   spellinfo->Effect[i] == SPELL_EFFECT_DUAL_WIELD )
			{
				SpellPointer sp = CREATESPELL(unitTarget, spellinfo, true, NULLAURA);
				SpellCastTargets targets;
				targets.m_unitTarget = unitTarget->GetGUID();
				targets.m_targetMask = TARGET_FLAG_UNIT;
				sp->prepare(&targets);
				break;
			}	  
		return;
	}

	// if we got here... try via pet spells..
	SpellEffectLearnPetSpell(i);
}

void Spell::SpellEffectSpellDefense(uint32 i)
{
	//used to enable this ability. We use it all the time ...
}

void Spell::SpellEffectLearnPetSpell(uint32 i)
{
	/*if(unitTarget && m_caster->GetTypeId() == TYPEID_PLAYER)
	{
		if(unitTarget->IsPet() && unitTarget->GetTypeId() == TYPEID_UNIT)
		{
			TO_PLAYER(m_caster)->AddPetSpell(m_spellInfo->EffectTriggerSpell[i], unitTarget->GetEntry());
		}
	}*/

	if(unitTarget && unitTarget->IsPet() && p_caster)
	{
		for(uint32 i=0;i<3;i++)
		{
			if (m_spellInfo->EffectTriggerSpell[i])
			{
				PetPointer pPet = TO_PET( unitTarget );
				if(pPet->IsSummon())
					p_caster->AddSummonSpell(unitTarget->GetEntry(), m_spellInfo->EffectTriggerSpell[i]);
		
				pPet->AddSpell( dbcSpell.LookupEntry( m_spellInfo->EffectTriggerSpell[i] ), true );
			}
		}
	}
}

void Spell::SpellEffectDispel(uint32 i) // Dispel
{
	if(!u_caster || !unitTarget)
		return;

	AuraPointer aur;
	uint32 start,end;
	if(isAttackable(u_caster,unitTarget))
	{
		start=0;
		end=MAX_POSITIVE_AURAS;
	}
	else
	{
		start=MAX_POSITIVE_AURAS;
		end=MAX_AURAS;
	}
	
	WorldPacket data(SMSG_SPELLDISPELLOG, 16);

	for(uint32 x=start;x<end;x++)
	if(unitTarget->m_auras[x])
	{
		aur = unitTarget->m_auras[x];
		//Nothing can dispel resurrection sickness;
		if(!aur->IsPassive() && !(aur->GetSpellProto()->Attributes & ATTRIBUTES_IGNORE_INVULNERABILITY))
		{
			if(m_spellInfo->DispelType == DISPEL_ALL)
			{
				unitTarget->HandleProc( PROC_ON_PRE_DISPELL_AURA_VICTIM , u_caster , m_spellInfo, aur->GetSpellId() );
				data.clear();
				data << m_caster->GetNewGUID();
				data << unitTarget->GetNewGUID();
				data << (uint32)1;//probably dispel type
				data << aur->GetSpellId();
				m_caster->SendMessageToSet(&data,true);
				aur->AttemptDispel( u_caster );
				if(!--damage)
					return;
			}
			else if(aur->GetSpellProto()->DispelType == m_spellInfo->EffectMiscValue[i])
			{
				data.clear();
				data << m_caster->GetNewGUID();
				data << unitTarget->GetNewGUID();
				data << (uint32)1;
				data << aur->GetSpellId();
				m_caster->SendMessageToSet(&data,true);
				aur->AttemptDispel( u_caster );
				if(!--damage)
					return;
			}			
		}
	}   
}

void Spell::SpellEffectDualWield(uint32 i)
{
	if(m_caster->GetTypeId() != TYPEID_PLAYER) 
		return;

	PlayerPointer pPlayer = TO_PLAYER( m_caster );

	if( !pPlayer->_HasSkillLine( SKILL_DUAL_WIELD ) )
		 pPlayer->_AddSkillLine( SKILL_DUAL_WIELD, 1, 1 );
	
		// Increase it by one
		//dual wield is 1/1 , it never increases it's not even displayed in skills tab

	//note: probably here must be not caster but unitVictim
}

void Spell::SpellEffectSummonWildOld(uint32 i)  // Summon Wild
{
	//these are some cretures that have your faction and do not respawn
	//number of creatures is actualy dmg (the usual formula), sometimes =3 sometimes =1
	uint32 cr_entry=m_spellInfo->EffectMiscValue[i];
	CreatureProto * proto = CreatureProtoStorage.LookupEntry(cr_entry);
	CreatureInfo * info = CreatureNameStorage.LookupEntry(cr_entry);
	if(!proto || !info)
	{
		OUT_DEBUG("Warning : Missing summon creature template %u used by spell %u!",cr_entry,m_spellInfo->Id);
		return;
	}
	for(int i=0;i<damage;i++)
	{
		float m_fallowAngle=-((float(M_PI)/2)*i);
		float x = u_caster->GetPositionX()+(3*(cosf(m_fallowAngle+u_caster->GetOrientation())));
		float y = u_caster->GetPositionY()+(3*(sinf(m_fallowAngle+u_caster->GetOrientation())));
		float z = u_caster->GetPositionZ();
		CreaturePointer p = u_caster->GetMapMgr()->CreateCreature(cr_entry);
		//ASSERT(p);
		p->Load(proto, x, y, z, 0.0f);
       		//p->SetZoneId(m_caster->GetZoneId());
		p->SetZoneId( m_caster->GetZoneId() );

		if ( p->proto && p->proto->Faction == 35 )
		{
			p->SetUInt64Value( UNIT_FIELD_SUMMONEDBY, m_caster->GetGUID() );
			p->SetUInt64Value( UNIT_FIELD_CREATEDBY, m_caster->GetGUID() );
			p->SetUInt32Value( UNIT_FIELD_FACTIONTEMPLATE, u_caster->GetUInt32Value( UNIT_FIELD_FACTIONTEMPLATE ) );
		}
		else
		{
			p->SetUInt32Value( UNIT_FIELD_FACTIONTEMPLATE, proto->Faction );
		}

		p->m_faction = dbcFactionTemplate.LookupEntry(proto->Faction);
		if(p->m_faction)
			p->m_factionDBC = dbcFaction.LookupEntry(p->m_faction->Faction);
		p->PushToWorld(u_caster->GetMapMgr());
		//make sure they will be desumonized (roxor)
		sEventMgr.AddEvent(p, &Creature::SummonExpire, EVENT_SUMMON_EXPIRE, GetDuration(), 1,0);
	}
}

void Spell::SummonGuardian(uint32 i) // Summon Guardian
{
	if ( !u_caster )
		return;

	uint32 cr_entry = m_spellInfo->EffectMiscValue[i];
	uint32 level = u_caster->getLevel();
	float angle_for_each_spawn = -float(M_PI) * 2 / damage;
	
	bool isVehicle = false;

	if( m_summonProperties->unk2 & 2 || m_summonProperties->Id == 711) // it's health., or a fucked up infernal.
		damage = 1;

	if( i != 0 && m_spellInfo->Effect[i-1] == SPELL_EFFECT_APPLY_AURA && m_spellInfo->EffectApplyAuraName[i-1] == SPELL_AURA_MOUNTED )
	{
		damage = 1;
		isVehicle = true;
	}

	for( int d = 0; d < damage; d++ )
	{
		float m_fallowAngle = angle_for_each_spawn * d;
		if( isVehicle )
		{
			CreatureProto * cp = CreatureProtoStorage.LookupEntry(cr_entry);
			if(!cp) return;

			if(cp->vehicle_entry == -1 || cp->vehicle_entry < 0)
			{
				Log.Error("SpellEffect", "Creature %u, has invalid vehicle_entry, please check your creature_proto table", cr_entry);
				return;
			}

			VehiclePointer veh = VehiclePointer( u_caster->GetMapMgr()->CreateVehicle( cr_entry ) );
			veh->m_CreatedFromSpell = true;
			veh->m_mountSpell = m_spellInfo->EffectBasePoints[i];
			veh->Load( cp, u_caster->GetPositionX(), u_caster->GetPositionY(), u_caster->GetPositionZ(), u_caster->GetOrientation());
			veh->SetInstanceID( u_caster->GetInstanceID() );
			veh->PushToWorld( u_caster->GetMapMgr() ); // we can do this safely since we're in the mapmgr's context
			veh->InitSeats( cp->vehicle_entry, p_caster );
		}
		else
		{
			if ( g_caster ) 
			{
				u_caster = g_caster->m_summoner;
				u_caster->m_SummonSlots[ m_summonProperties->slot < 7 ? m_summonProperties->slot : 0 ] = TO_CREATURE(g_caster->CreateTemporaryGuardian(cr_entry,GetDuration(),m_fallowAngle, u_caster));
			}
			else
				u_caster->m_SummonSlots[ m_summonProperties->slot < 7 ? m_summonProperties->slot : 0 ] = TO_CREATURE(u_caster->CreateTemporaryGuardian(cr_entry,GetDuration(),m_fallowAngle,level));
		}
	}
}

void Spell::SpellEffectSkillStep(uint32 i) // Skill Step
{
	PlayerPointer target;
	if(m_caster->GetTypeId() != TYPEID_PLAYER)
	{
		// Check targets
		if( m_targets.m_unitTarget )
		{
			target = objmgr.GetPlayer((uint32)m_targets.m_unitTarget);
			if( target == NULL ) 
				return;
		}
		else
			return;
	}
	else
	{
		target = TO_PLAYER( m_caster );
	}
	
	uint32 skill = m_spellInfo->EffectMiscValue[i];
	if( skill == 242 )
		skill = SKILL_LOCKPICKING; // somehow for lockpicking misc is different than the skill :s

	skilllineentry* sk = dbcSkillLine.LookupEntry( skill );

	if( sk == NULL )
		return;

	uint32 max = 1;
	switch( sk->type )
	{
		case SKILL_TYPE_PROFESSION:
		case SKILL_TYPE_SECONDARY:
			max = damage * 75;
			break;
		case SKILL_TYPE_WEAPON:
			max = 5 * target->getLevel();
			break;
		case SKILL_TYPE_CLASS:
		case SKILL_TYPE_ARMOR:
			if( skill == SKILL_LOCKPICKING )
				max = damage * 75;
			else
				max = 1;
			break;
		default: //u cant learn other types in game
			return;
	};

	if( target->_HasSkillLine( skill ) )
	{
		target->_ModifySkillMaximum( skill, max );
	}		
	else
	{
		// Don't add skills to players logging in.
		/*if((m_spellInfo->Attributes & 64) && playerTarget->m_TeleportState == 1)
			return;*/

		if( sk->type == SKILL_TYPE_PROFESSION )
			target->ModUnsigned32Value( PLAYER_CHARACTER_POINTS2, -1 );
	  
		if( skill == SKILL_RIDING )
			target->_AddSkillLine( skill, max, max );
		else
			target->_AddSkillLine( skill, 1, max );
	}

	//professions fix, for unknow reason when u learn profession it 
	//does not teach find herbs for herbalism etc. moreover there is no spell
	//in spell.dbc that would teach u this. It means blizz does it in some tricky way too
	switch( skill )
	{
	case SKILL_ALCHEMY:
		target->addSpell( 2330 );//Minor Healing Potion
		target->addSpell( 2329 );//Elixir of Lion's Strength
		target->addSpell( 7183 );//Elixir of Minor Defense
		break;
	case SKILL_ENCHANTING:
		target->addSpell( 7418 );//Enchant Bracer - Minor Health
		target->addSpell( 7428 );//Enchant Bracer - Minor Deflection
		target->addSpell( 7421 );//Runed Copper Rod
		target->addSpell( 13262 );//Disenchant
		break;
	case SKILL_HERBALISM:
		target->addSpell( 2383 );//find herbs
		break;
	case SKILL_MINING:
		target->addSpell( 2657 );//smelt copper
		target->addSpell( 2656 );//smelting
		target->addSpell( 2580 );//find minerals
		break;
	case SKILL_FIRST_AID:
		target->addSpell( 3275 );//Linen Bandage
		break;
	case SKILL_TAILORING:
		target->addSpell( 2963 );//Bolt of Linen Cloth

		target->addSpell( 2387 );//Linen Cloak
		target->addSpell( 2393 );//White Linen Shirt
		target->addSpell( 3915 );//Brown Linen Shirt
		target->addSpell( 12044 );//Simple Linen Pants
		break;
	case SKILL_LEATHERWORKING:
		target->addSpell( 2149 );//Handstitched Leather Boots
		target->addSpell( 2152 );//Light Armor Kit
		target->addSpell( 2881 );//Light Leather
		target->addSpell( 7126 );//Handstitched Leather Vest
		target->addSpell( 9058 );//Handstitched Leather Cloak
		target->addSpell( 9059 );//Handstitched Leather Bracers
		break;
	case SKILL_ENGINERING:
		target->addSpell( 3918 );//Rough Blasting Powder
		target->addSpell( 3919 );//Rough Dynamite
		target->addSpell( 3920 );//Crafted Light Shot
		break;
	case SKILL_COOKING:
		target->addSpell( 2538 );//Charred Wolf Meat
		target->addSpell( 2540 );//Roasted Boar Meat
		target->addSpell( 818 );//Basic Campfire
		target->addSpell( 8604 );//Herb Baked Egg
		break;
	case SKILL_BLACKSMITHING:
		target->addSpell( 2660 );//Rough Sharpening Stone
		target->addSpell( 2663 );//Copper Bracers
		target->addSpell( 12260 );//Rough Copper Vest
		target->addSpell( 2662 );//Copper Chain Pants
		target->addSpell( 3115 );//Rough Weightstone
		break;
	case SKILL_JEWELCRAFTING:
		target->addSpell( 25255 );// Delicate Copper Wire
		target->addSpell( 25493 );// Braided Copper Ring
		target->addSpell( 26925 );// Woven Copper Ring
		target->addSpell( 32259 );// Rough Stone Statue
		break;
	case SKILL_INSCRIPTION:
		target->addSpell( 51005 );// Milling
		target->addSpell( 48116 );// Scroll of Spirit
		target->addSpell( 48114 );// Scroll of Intellect
		target->addSpell( 45382 );// Scroll of Stamina
		target->addSpell( 52738 );// Ivory Ink

	};
}

void Spell::SpellEffectSummonObject(uint32 i)
{
	if( !p_caster )
		return;

	uint32 entry = m_spellInfo->EffectMiscValue[i];

	uint32 mapid = u_caster->GetMapId();
	float px = u_caster->GetPositionX();
	float py = u_caster->GetPositionY();
	float pz = u_caster->GetPositionZ();
	float orient = m_caster->GetOrientation();
	float posx = 0,posy = 0,posz = 0;
	
	if( entry == GO_FISHING_BOBBER )
	{
		float co = cos( orient );
		float si = sin( orient );
		MapMgrPointer map = m_caster->GetMapMgr();
		SpellPointer spell = u_caster->GetCurrentSpell();

		float r;
		for( r = 20; r > 10; r-- )
		{
			posx = px+r*co;
			posy = py+r*si;
			if( !(map->GetWaterType( posx, posy ) & 1) )//water 
				continue;
			posz = map->GetWaterHeight( posx, posy );
			if( posz > map->GetLandHeight( posx, posy ) )//water 
				break;
		}

		posx = px + r * co;
		posy = py + r * si;
		   
		// Todo / Fix me: This should be loaded / cached
		uint32 zone = p_caster->GetAreaID();
		if( zone == 0 ) // If the player's area ID is 0, use the zone ID instead
			zone = p_caster->GetZoneId();

		uint32 minskill;
		FishingZoneEntry *fishentry = FishingZoneStorage.LookupEntry( zone );
		if( !fishentry ) // Check database if there is fishing area / zone information, if not, return
			return;
		
		// Todo / Fix me: Add fishskill to the calculations
		minskill = fishentry->MinSkill;
		spell->SendChannelStart( 20000 ); // 30 seconds
		/*spell->SendSpellStart();
		spell->SendCastResult(SPELL_CANCAST_OK);
		spell->SendSpellGo ();*/

		GameObjectPointer go = u_caster->GetMapMgr()->CreateGameObject(GO_FISHING_BOBBER);
		if( go == NULL || !go->CreateFromProto( GO_FISHING_BOBBER, mapid, posx, posy, posz, orient, 0.0f, 0.0f, 0.0f, 0.0f ))
			return;

		go->SetUInt32Value( GAMEOBJECT_FLAGS, 0 );
		go->SetByte(GAMEOBJECT_BYTES_1, 0, 0 );
		go->SetUInt64Value( OBJECT_FIELD_CREATED_BY, m_caster->GetGUID() );
		u_caster->SetUInt64Value( UNIT_FIELD_CHANNEL_OBJECT, go->GetGUID() );
			 
		go->SetInstanceID( m_caster->GetInstanceID() );
		go->PushToWorld( m_caster->GetMapMgr() );
	   
		if( lootmgr.IsFishable( zone ) ) // Only set a 'splash' if there is any loot in this area / zone
		{
			uint32 seconds = RandomUInt(17) + 2;
			sEventMgr.AddEvent( go, &GameObject::FishHooked, TO_PLAYER( m_caster ), EVENT_GAMEOBJECT_FISH_HOOKED, seconds * 1000, 1, 0 );
		}
		sEventMgr.AddEvent( go, &GameObject::EndFishing, TO_PLAYER( m_caster ),false, EVENT_GAMEOBJECT_END_FISHING, 20000, 1, 0 );
		p_caster->SetSummonedObject( go );
	}
	else
	{//portal, lightwell
		posx=px;
		posy=py;		
		GameObjectInfo * goI = GameObjectNameStorage.LookupEntry(entry);
		if(!goI)
		{
			if( p_caster != NULL )
			{
				sChatHandler.BlueSystemMessage(p_caster->GetSession(),
				"non-existant gameobject %u tried to be created by SpellEffectSummonObject. Report to devs!", entry);
			}
			return;
		}

		GameObjectPointer go=u_caster->GetMapMgr()->CreateGameObject(entry);
		if( go == NULL || !go->CreateFromProto(entry,mapid,posx,posy,pz,orient, 0.0f, 0.0f, 0.0f, 0.0f))
			return;
	
		go->SetInstanceID(m_caster->GetInstanceID());
		go->SetByte(GAMEOBJECT_BYTES_1,GAMEOBJECT_BYTES_STATE, 1);
		go->SetUInt64Value(OBJECT_FIELD_CREATED_BY,m_caster->GetGUID());
		go->PushToWorld(m_caster->GetMapMgr());	  
		sEventMgr.AddEvent(go, &GameObject::ExpireAndDelete, EVENT_GAMEOBJECT_EXPIRE, GetDuration(), 1,0);
		if(entry ==17032)//this is a portal
		{
			//enable it for party only
			go->SetByte(GAMEOBJECT_BYTES_1, 0, 0);

			//disable by default
			WorldPacket *pkt = go->BuildFieldUpdatePacket(GAMEOBJECT_BYTES_1, 1);
			SubGroup * pGroup = p_caster->GetGroup() ? p_caster->GetGroup()->GetSubGroup(p_caster->GetSubGroup()) : NULL;

			if(pGroup)
			{
				p_caster->GetGroup()->Lock();
				for(GroupMembersSet::iterator itr = pGroup->GetGroupMembersBegin();
					itr != pGroup->GetGroupMembersEnd(); ++itr)
				{
					if((*itr)->m_loggedInPlayer && m_caster != (*itr)->m_loggedInPlayer)
						(*itr)->m_loggedInPlayer->GetSession()->SendPacket(pkt);
				}
				p_caster->GetGroup()->Unlock();
			}
			delete pkt;
		}
		else if(entry == 36727 || entry == 177193) // Portal of Summoning and portal of doom
		{
			PlayerPointer pTarget = p_caster->GetMapMgr()->GetPlayer((uint32)p_caster->GetSelection());
			if(!pTarget)
				return;

			go->m_ritualmembers[0] = p_caster->GetLowGUID();
			go->m_ritualcaster = p_caster->GetLowGUID();
			go->m_ritualtarget = pTarget->GetLowGUID();
			go->m_ritualspell = m_spellInfo->Id;	 
		}
		else//Lightwell,if there is some other type -- add it
		{
			go->charges=5;//Max 5 charges
		}
		p_caster->SetSummonedObject(go);		
	}
}

void Spell::SpellEffectEnchantItem(uint32 i) // Enchant Item Permanent
{
	if(!itemTarget || !p_caster) return;
	EnchantEntry * Enchantment = dbcEnchant.LookupEntry(m_spellInfo->EffectMiscValue[i]);
	if(!Enchantment) return;

	if(p_caster->GetSession()->GetPermissionCount() > 0)
		sGMLog.writefromsession(p_caster->GetSession(), "enchanted item for %s", itemTarget->GetOwner()->GetName());

	//remove other perm enchantment that was enchanted by profession
	itemTarget->RemoveProfessionEnchant();
	int32 Slot = itemTarget->AddEnchantment(Enchantment, 0, true, true, false, 0);
	if(Slot < 0)
		return; // Apply failed
			
	DetermineSkillUp(SKILL_ENCHANTING);
	itemTarget->m_isDirty = true;
}

void Spell::SpellEffectEnchantItemTemporary(uint32 i)  // Enchant Item Temporary
{
	if(!itemTarget || !p_caster) return;
	uint32 Duration = damage > 1 ? damage : 1800;

	EnchantEntry * Enchantment = dbcEnchant.LookupEntry(m_spellInfo->EffectMiscValue[i]);
	if(!Enchantment) return;

	itemTarget->RemoveEnchantment(1);
	int32 Slot = itemTarget->AddEnchantment(Enchantment, Duration, false, true, false, 1);
	if(Slot < 0)
		return; // Apply failed

	skilllinespell* skill = objmgr.GetSpellSkill(m_spellInfo->Id);
	if(skill)
		DetermineSkillUp(skill->skilline,itemTarget->GetProto()->ItemLevel);

	itemTarget->m_isDirty = true;
}

void Spell::SpellEffectTameCreature(uint32 i)
{
	CreaturePointer tame = ((unitTarget->GetTypeId() == TYPEID_UNIT) ? TO_CREATURE(unitTarget) : NULLCREATURE);
	if(!tame)
		return;

	uint8 result = SPELL_CANCAST_OK;

	if(!tame || !p_caster || !p_caster->isAlive() || !tame->isAlive() || p_caster->getClass() != HUNTER )
		result = SPELL_FAILED_BAD_TARGETS;
	else if(!tame->GetCreatureName())
		result = SPELL_FAILED_BAD_TARGETS;
	else if(tame->GetCreatureName()->Type != BEAST)
		result = SPELL_FAILED_BAD_TARGETS;
	else if(tame->getLevel() > p_caster->getLevel())
		result = SPELL_FAILED_HIGHLEVEL;
	else if(p_caster->GeneratePetNumber() == 0)
		result = SPELL_FAILED_BAD_TARGETS;
	else if(!tame->GetCreatureName()->Family)
		result = SPELL_FAILED_BAD_TARGETS;
	else if(p_caster->GetSummon() || p_caster->GetUnstabledPetNumber())
		result = SPELL_FAILED_ALREADY_HAVE_SUMMON;
	{
		CreatureFamilyEntry *cf = dbcCreatureFamily.LookupEntry(tame->GetCreatureName()->Family);
		if(cf && !cf->tameable)
				result = SPELL_FAILED_BAD_TARGETS;
	}
	if(result != SPELL_CANCAST_OK)
	{
		SendCastResult(result);
		return;
	}
	// Remove target
	tame->GetAIInterface()->HandleEvent(EVENT_LEAVECOMBAT, p_caster, 0);
	PetPointer pPet = objmgr.CreatePet();
	pPet->SetInstanceID(p_caster->GetInstanceID());
	pPet->CreateAsSummon(tame->GetEntry(), tame->GetCreatureName(), tame, TO_UNIT(p_caster), NULL, 2, 0);
	//tame->SafeDelete();
	//delete tame;
	tame->Despawn(0,tame->proto? tame->proto->RespawnTime:0);
}

void Spell::SpellEffectSummonPet(uint32 i) //summon - pet
{
	if(m_spellInfo->Id == 883)
	{
		// "Call Pet" spell
		if(!p_caster)
			return;

		if(p_caster->GetSummon() != 0)
		{
			p_caster->GetSession()->SendNotification("You already have a pet summoned.");
			return;
		}

		uint32 petno = p_caster->GetUnstabledPetNumber();

		if(petno)
		{
			p_caster->SpawnPet(petno);
		}
		else
		{
			WorldPacket data(SMSG_AREA_TRIGGER_MESSAGE, 50);
			data << uint32(0) << "You do not have any pets to call." << uint8(0);
			p_caster->GetSession()->SendPacket(&data);
		}
		return;
	}
	
	//uint32 entryId = m_spellInfo->EffectMiscValue[i];

	//VoidWalker:torment, sacrifice, suffering, consume shadows
	//Succubus:lash of pain, soothing kiss, seduce , lesser invisibility
	//felhunter:	 Devour Magic,Paranoia,Spell Lock,	Tainted Blood
 
	if(!p_caster || p_caster->getClass() != WARLOCK)
		return;
	
	// remove old pet
	PetPointer old = TO_PLAYER(m_caster)->GetSummon();
	if(old)
		old->Dismiss(false);		
	
	CreatureInfo *ci = CreatureNameStorage.LookupEntry(m_spellInfo->EffectMiscValue[i]);
	if(ci)
	{
		//if demonic sacrifice auras are still active, remove them
		//uint32 spids[] = { 18789, 18790, 18791, 18792, 35701, 0 };
		//p_caster->RemoveAuras(spids);
		p_caster->RemoveAura(18789);
		p_caster->RemoveAura(18790);
		p_caster->RemoveAura(18791);
		p_caster->RemoveAura(18792);
		p_caster->RemoveAura(35701);

		PetPointer summon = objmgr.CreatePet();
		summon->SetInstanceID(m_caster->GetInstanceID());
		summon->CreateAsSummon(m_spellInfo->EffectMiscValue[i], ci, NULLCREATURE, u_caster, m_spellInfo, 1, 0);
		if( u_caster->IsPvPFlagged() )
			summon->SetPvPFlag();
	}
}

void Spell::SpellEffectWeapondamage( uint32 i ) // Weapon damage +
{
	if( unitTarget == NULL || u_caster == NULL )
		return;

	//Hackfix for Mangle
	if( m_spellInfo->NameHash == SPELL_HASH_MANGLE___CAT && u_caster->IsPlayer() )
		TO_PLAYER( u_caster )->AddComboPoints( unitTarget->GetGUID(), 1 );

	// Rune Strike
	if(m_spellInfo->Id == 56815 && u_caster)
	{
		add_damage = u_caster->GetAP() / 5;
		return;
	}

	// Hacky fix for druid spells where it would "double attack".
	if( m_spellInfo->Effect[2] == SPELL_EFFECT_WEAPON_PERCENT_DAMAGE || m_spellInfo->Effect[1] == SPELL_EFFECT_WEAPON_PERCENT_DAMAGE )
	{
		add_damage += damage;
		return;
	}

	uint32 _type;
	if( GetType() == SPELL_DMG_TYPE_RANGED )
		_type = RANGED;
	else
	{
		if (m_spellInfo->Flags4 & FLAGS4_OFFHAND)
			_type =  OFFHAND;
		else
			_type = MELEE;
	}
	u_caster->Strike( unitTarget, _type, m_spellInfo, damage, 0, 0, false, true );
}

void Spell::SpellEffectPowerBurn(uint32 i) // power burn
{
	if(!unitTarget)
		return;
	if(!unitTarget->isAlive())
		return;
	if (unitTarget->GetPowerType() != POWER_TYPE_MANA)
		return;

	//Resilience reduction
	if(unitTarget->IsPlayer())
	{
		float dmg_reduction_pct = 2.2f * TO_PLAYER(unitTarget)->CalcRating( PLAYER_RATING_MODIFIER_SPELL_CRIT_RESILIENCE ) / 100.0f;
		if( dmg_reduction_pct > 0.33f )
			dmg_reduction_pct = 0.33f; // 3.0.3
		damage = float2int32( damage - damage * dmg_reduction_pct );
	}

	int32 mana = (int32)min( (int32)unitTarget->GetUInt32Value( UNIT_FIELD_POWER1 ), damage );
	unitTarget->ModUnsigned32Value(UNIT_FIELD_POWER1,-mana);
	
	float coef = m_spellInfo->EffectMultipleValue[i]; // damage per mana burned
	if(u_caster)
	{
		SM_FFValue(u_caster->SM[SMT_MULTIPLE_VALUE][0], &coef, m_spellInfo->SpellGroupType);
		SM_PFValue(u_caster->SM[SMT_MULTIPLE_VALUE][1], &coef, m_spellInfo->SpellGroupType);
	}
	mana = float2int32((float)mana * coef);

	m_caster->SpellNonMeleeDamageLog(unitTarget,m_spellInfo->Id, mana, pSpellId==0,true);   
}

void Spell::SpellEffectThreat(uint32 i) // Threat
{
	if(!unitTarget || !unitTarget->isAlive() )
		return;

	bool chck = unitTarget->GetAIInterface()->modThreatByPtr(u_caster,damage);
	if(chck == false)
		unitTarget->GetAIInterface()->AttackReaction(u_caster,1,0);	
}

void Spell::SpellEffectTriggerSpell(uint32 i) // Trigger Spell
{
	if(!unitTarget || !m_caster )
		return;

	SpellEntry *spe = dbcSpell.LookupEntryForced(m_spellInfo->EffectTriggerSpell[i]);
	if(!spe)
		return;

	SpellPointer sp=CREATESPELL(m_caster,spe,true,NULLAURA);
	SpellCastTargets tgt((spe->procFlags & PROC_TARGET_SELF) ? m_caster->GetGUID() :unitTarget->GetGUID());
	sp->prepare(&tgt);
}

void Spell::SpellEffectHealthFunnel(uint32 i) // Health Funnel
{
	if(!unitTarget)
		return;		
	if(!unitTarget->isAlive() || !unitTarget->IsPet())
		return;

	//does not exist
}

void Spell::SpellEffectPowerFunnel(uint32 i) // Power Funnel
{
	if(!unitTarget)
		return;		
	if(!unitTarget->isAlive() || !unitTarget->IsPet())
		return;

	//does not exist
}

void Spell::SpellEffectHealMaxHealth(uint32 i)   // Heal Max Health
{
	if( unitTarget == NULL || !unitTarget->isAlive() )
		return;

	uint32 dif = unitTarget->GetUInt32Value( UNIT_FIELD_MAXHEALTH ) - unitTarget->GetUInt32Value( UNIT_FIELD_HEALTH );
	if( !dif )
	{
		SendCastResult( SPELL_FAILED_ALREADY_AT_FULL_HEALTH );
		return;
	}

	if( unitTarget->GetTypeId() == TYPEID_PLAYER)
	{
		 SendHealSpellOnPlayer( TO_PLAYER( m_caster ), TO_PLAYER( unitTarget ), dif, false, 0, pSpellId ? pSpellId : m_spellInfo->Id );
	}
	unitTarget->ModUnsigned32Value( UNIT_FIELD_HEALTH, dif );
}

void Spell::SpellEffectInterruptCast(uint32 i) // Interrupt Cast
{
	if(!unitTarget || !unitTarget->isAlive())
		return;
	// can't apply stuns/fear/polymorph/root etc on boss
	if(unitTarget->GetTypeId()==TYPEID_UNIT)
	{
		CreaturePointer c = TO_CREATURE( unitTarget );
		if (c&&c->GetCreatureName()&&c->GetCreatureName()->Rank == ELITE_WORLDBOSS)
			return;
	}
	// FIXME:This thing prevent target from spell casting too but cant find.
	uint32 school=0;
	if( unitTarget->GetCurrentSpell() != NULL && (unitTarget->GetCurrentSpell()->getState() == SPELL_STATE_PREPARING || unitTarget->GetCurrentSpell()->getState() == SPELL_STATE_CASTING) && unitTarget->GetCurrentSpell() != shared_from_this() )
	{
		school=unitTarget->GetCurrentSpell()->m_spellInfo->School;
		unitTarget->InterruptCurrentSpell();
		if(school)//prevent from casts in this school
		{
			unitTarget->SchoolCastPrevent[school]=GetDuration()+getMSTime();
		}
	}

}

void Spell::SpellEffectDistract(uint32 i) // Distract
{
	//spellId 1725 Distract:Throws a distraction attracting the all monsters for ten sec's
	if(!unitTarget)
		return;
	if(!unitTarget->isAlive())
		return;

	if(m_targets.m_destX != 0.0f || m_targets.m_destY != 0.0f || m_targets.m_destZ != 0.0f)
	{
//		unitTarget->GetAIInterface()->MoveTo(m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ, 0);
		uint32 Stare_duration=GetDuration();
		if(Stare_duration>30*60*1000)
			Stare_duration=10000;//if we try to stare for more then a half an hour then better not stare at all :P (bug)
		float newo=unitTarget->calcRadAngle(unitTarget->GetPositionX(),unitTarget->GetPositionY(),m_targets.m_destX,m_targets.m_destY);
		unitTarget->GetAIInterface()->StopMovement(Stare_duration);
		unitTarget->SetFacing(newo);
	}

	//Smoke Emitter 164870
	//Smoke Emitter Big 179066
	//Unit Field Target of 
}

void Spell::SpellEffectPickpocket(uint32 i) // pickpocket
{
	//Show random loot based on roll,	
	if(!unitTarget)
		return; // impossible..
	if(!p_caster)
		return;

	if(unitTarget->GetTypeId() != TYPEID_UNIT)
		return;

	CreaturePointer target = TO_CREATURE( unitTarget );
	if(target->IsPickPocketed() || (target->GetCreatureName() && target->GetCreatureName()->Type != HUMANOID))
	{
		SendCastResult(SPELL_FAILED_TARGET_NO_POCKETS);
		return;
	}
			
  lootmgr.FillPickpocketingLoot(&TO_CREATURE(unitTarget)->m_loot,unitTarget->GetEntry());

	uint32 _rank = TO_CREATURE(unitTarget)->GetCreatureName() ? TO_CREATURE(unitTarget)->GetCreatureName()->Rank : 0;
	unitTarget->m_loot.gold = float2int32((_rank+1) * unitTarget->getLevel() * (RandomUInt(5) + 1) * sWorld.getRate(RATE_MONEY));

	p_caster->SendLoot(unitTarget->GetGUID(), LOOT_PICKPOCKETING);
	target->SetPickPocketed(true);
}

void Spell::SpellEffectAddFarsight(uint32 i) // Add Farsight
{
	if(!p_caster)
		return;

	DynamicObjectPointer dyn = p_caster->GetMapMgr()->CreateDynamicObject();
	dyn->Create(p_caster, shared_from_this(), m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ, GetDuration(), GetRadius(i));
	dyn->SetUInt32Value(OBJECT_FIELD_TYPE, 65);
	dyn->SetUInt32Value(DYNAMICOBJECT_BYTES, 0x80000002);
	dyn->AddToWorld(p_caster->GetMapMgr());
	p_caster->SetUInt64Value(PLAYER_FARSIGHT, dyn->GetGUID());
	p_caster->GetMapMgr()->ChangeFarsightLocation(p_caster, m_targets.m_destX, m_targets.m_destY, true);	
}

void Spell::SummonPossessed(uint32 i) // eye of kilrog
{
	/*
	m_target->DisableAI();
	pCaster->SetUInt64Value(UNIT_FIELD_SUMMON, 0);
	m_target->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, 0);
	pCaster->SetUInt64Value(UNIT_FIELD_CHARM, m_target->GetGUID());
	m_target->SetUInt64Value(UNIT_FIELD_CHARMEDBY, pCaster->GetGUID());
	pCaster->SetUInt64Value(PLAYER_FARSIGHT, m_target->GetGUID());
	pCaster->m_CurrentCharm = TO_CREATURE(m_target);
	m_target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED_CREATURE);
	pCaster->m_noInterrupt = 1;
	pCaster->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOCK_PLAYER);

	WorldPacket data(SMSG_DEATH_NOTIFY_OBSOLETE);
	data << m_target->GetNewGUID() << uint8(1);
	pCaster->GetSession()->SendPacket(&data);
	*/

/*
	CreatureInfo *ci = CreatureNameStorage.LookupEntry(m_spellInfo->EffectMiscValue[i]);
	if( ci)
	{
		CreaturePointer NewSummon = m_caster->GetMapMgr()->CreateCreature();
		// Create
		NewSummon->SetInstanceID(m_caster->GetInstanceID());
		NewSummon->Create( ci->Name, m_caster->GetMapId(), 
			m_caster->GetPositionX()+(3*(cos((float(M_PI)/2)+m_caster->GetOrientation()))), m_caster->GetPositionY()+(3*(cos((float(M_PI)/2)+m_caster->GetOrientation()))), m_caster->GetPositionZ(), m_caster->GetOrientation());

		// Fields
		NewSummon->SetUInt32Value(UNIT_FIELD_LEVEL,m_caster->GetUInt32Value(UNIT_FIELD_LEVEL));
		NewSummon->SetUInt32Value(UNIT_FIELD_DISPLAYID,  ci->Male_DisplayID);
		NewSummon->SetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID, ci->Male_DisplayID);
		NewSummon->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, m_caster->GetGUID());
		NewSummon->SetUInt64Value(UNIT_FIELD_CREATEDBY, m_caster->GetGUID());
		NewSummon->SetUInt32Value(UNIT_FIELD_HEALTH , 100);
		NewSummon->SetUInt32Value(UNIT_FIELD_MAXHEALTH , 100);
		NewSummon->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 35);
		NewSummon->SetFloatValue(OBJECT_FIELD_SCALE_X,1.0f);
		NewSummon->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_9 | UNIT_FLAG_PLAYER_CONTROLLED_CREATURE);

		//Setting faction
		NewSummon->_setFaction();
		NewSummon->m_temp_summon=true;

		// Add To World
		NewSummon->PushToWorld(m_caster->GetMapMgr());
		
		// Force an update on the player to create this guid.
		p_caster->ProcessPendingUpdates();

		//p_caster->SetUInt64Value(UNIT_FIELD_SUMMON, NewSummon->GetGUID());
		//p_caster->SetUInt64Value(PLAYER_FARSIGHT, NewSummon->GetGUID());
		//p_caster->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_LOCK_PLAYER);
		p_caster->Possess(NewSummon);
	}*/
}

void Spell::SpellEffectUseGlyph(uint32 i)
{
	if(!p_caster)
		return;
	uint8 result = p_caster->SetGlyph(m_glyphIndex, m_spellInfo->EffectMiscValue[i]);
	if(result)
		SendCastResult(result);
}

void Spell::SpellEffectHealMechanical(uint32 i)
{
	if(!unitTarget)
		return;
	if(unitTarget->GetTypeId() != TYPEID_UNIT)
		return;
	if(TO_CREATURE(unitTarget)->GetCreatureName()->Type != MECHANICAL)
		return;

	Heal((int32)damage);
}

void Spell::SpellEffectSummonObjectWild(uint32 i)
{
	if(!u_caster)
		return;

	// spawn a new one
	GameObjectPointer GoSummon = u_caster->GetMapMgr()->CreateGameObject(m_spellInfo->EffectMiscValue[i]);
	if( GoSummon == NULL || !GoSummon->CreateFromProto(m_spellInfo->EffectMiscValue[i],	m_caster->GetMapId(), m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), m_caster->GetOrientation(), 0.0f, 0.0f, 0.0f, 0.0f ))
		return;
	
	GoSummon->SetInstanceID(m_caster->GetInstanceID());
	GoSummon->SetUInt32Value(GAMEOBJECT_LEVEL, u_caster->getLevel());
	GoSummon->SetUInt64Value(OBJECT_FIELD_CREATED_BY, m_caster->GetGUID());
	GoSummon->SetByte(GAMEOBJECT_BYTES_1,GAMEOBJECT_BYTES_STATE, 0);
	GoSummon->PushToWorld(u_caster->GetMapMgr());
	GoSummon->SetSummoned(u_caster);
	
	sEventMgr.AddEvent(GoSummon, &GameObject::ExpireAndDelete, EVENT_GAMEOBJECT_EXPIRE, GetDuration(), 1,0);
}

void Spell::SpellEffectScriptEffect(uint32 i) // Script Effect
{
	uint32 spellId = m_spellInfo->Id;

	// Try a dummy SpellHandler
	if(sScriptMgr.CallScriptedDummySpell(spellId, i, shared_from_this()))
		return;

	switch(spellId)
	{

	// Arcane Missiles
	/*
	case 5143://Rank 1
	case 5144://Rank 2
	case 5145://Rank 3
	case 8416://Rank 4
	case 8417://Rank 5
	case 10211://Rank 6
	case 10212://Rank 7
	case 25345://Rank 8
	{
		if(m_tmpAffect == 0)
		{
			Affect* aff = new Affect(m_spellInfo,GetDuration(sSpellDuration.LookupEntry(m_spellInfo->DurationIndex)),m_GetGUID(),m_caster);
			m_tmpAffect = aff;
		}
		if(m_spellInfo->EffectBasePoints[0] < 0)
			m_tmpAffect->SetNegative();

		m_tmpAffect->SetPeriodicTriggerSpell(m_spellInfo->EffectTriggerSpell[0],m_spellInfo->EffectAmplitude[0],damage);
	}break;
	*/

	// Warlock Healthstones, just how much health does a lock need?
	case 6201:		// Minor Healthstone
		if (p_caster->HasSpell(18692))
		{
			CreateItem(19004);
			break;
		}
		if (p_caster->HasSpell(18693))
		{
			CreateItem(19005);
			break;
		}
		CreateItem(5512);
		break;
	case 6202:		// Lesser Healthstone
		if (p_caster->HasSpell(18693))	// Improved Healthstone (2)
		{
			CreateItem(19007);
			break;
		}
		if (p_caster->HasSpell(18692))	// Improved Healthstone (1)
		{
			CreateItem(19006);
			break;
		}
		CreateItem(5511);
		break;
	case 5699:		// Healthstone
		if (p_caster->HasSpell(18693))	// Improved Healthstone (2)
		{
			CreateItem(19009);
			break;
		}
		if (p_caster->HasSpell(18692))	// Improved Healthstone (1)
		{
			CreateItem(19008);
			break;
		}
		CreateItem(5509);
		break;
	case 11729:		// Greater Healthstone
		if (p_caster->HasSpell(18693))	// Improved Healthstone (2)
		{
			CreateItem(19011);
			break;
		}
		if (p_caster->HasSpell(18692))	// Improved Healthstone (1)
		{
			CreateItem(19010);
			break;
		}
		CreateItem(5510);
		break;
	case 11730:		// Major Healthstone
		if (p_caster->HasSpell(18693))	// Improved Healthstone (2)
		{
			CreateItem(19013);
			break;
		}
		if (p_caster->HasSpell(18692))	// Improved Healthstone (1)
		{
			CreateItem(19012);
			break;
		}
		CreateItem(9421);
		break;
	case 27230:		// Master Healthstone
		if (p_caster->HasSpell(18693))	// Improved Healthstone (2)
		{
			CreateItem(22105);
			break;
		}
		if (p_caster->HasSpell(18692))	// Improved Healthstone (1)
		{
			CreateItem(22104);
			break;
		}
		CreateItem(22103);
		break;
	case 47871:		// Demonic Healthstone
		if (p_caster->HasSpell(18693))	// Improved Healthstone (2)
		{
			CreateItem(36891);
			break;
		}
		if (p_caster->HasSpell(18692))	// Improved Healthstone (1)
		{
			CreateItem(36890);
			break;
		}
		CreateItem(36889); 
		break;
	case 47878:		// Fel Healthstone
		if (p_caster->HasSpell(18693))	// Improved Healthstone (2)
		{
			CreateItem(36894);
			break;
		}
		if (p_caster->HasSpell(18692))	// Improved Healthstone (1)
		{
			CreateItem(36893);
			break;
		}
		CreateItem(36892);
		break;

	// Holy Light
	case 635:
	case 639:
	case 647:
	case 1026:
	case 1042:
	case 3472:
	case 10328:
	case 10329:
	case 10348:
	case 25292:
	case 27135:
	case 27136:
	//Flash of light
	case 19750:
	case 19939:
	case 19940:
	case 19941:
	case 19942:
	case 19943:
	case 27137:
		{
			uint32 NewSpell;
			switch(m_spellInfo->Id)
			{
				// hehe xD
				case 19750: NewSpell = 19993; break;
				case 19939: NewSpell = 35211; break;
				case 19940: NewSpell = 35212; break;
				case 19941: NewSpell = 35213; break;
				case 19942: NewSpell = 35214; break;
				case 19943: NewSpell = 35215; break;
				case 27137: NewSpell = 35216; break;
				case 635: NewSpell = 19982; break;
				case 639: NewSpell = 19981; break;
				case 647: NewSpell = 19980; break;
				case 1026: NewSpell = 19968; break;
				case 1042: NewSpell = 35217; break;
				case 3472: NewSpell = 35218; break;
				case 10328: NewSpell = 35219; break;
				case 10329: NewSpell = 35220; break;
				case 25292: NewSpell = 35221; break;
				case 27135: NewSpell = 35222; break;
				case 27136: NewSpell = 35223; break;
			}
			if( u_caster && NewSpell)
			{
				SpellPointer sp = CREATESPELL(u_caster,dbcSpell.LookupEntry(NewSpell),true,NULLAURA);
				SpellCastTargets tgt(unitTarget->GetGUID());
				//sp->damage = damage;
				sp->forced_basepoints[0] = damage;
				sp->prepare(&tgt);
			}
		}
	break;

	// Judgements
	case 20271: //Light
	case 53407: //Justice
	case 53408: //Wisdom
		{
			if(!unitTarget || !p_caster) 
				return;

			if( p_caster->judgespell )
			{
				SpellEntry*en=dbcSpell.LookupEntry(p_caster->judgespell);
				SpellPointer sp=CREATESPELL(p_caster,en,true,NULLAURA);
				SpellCastTargets tgt;
				tgt.m_unitTarget=unitTarget->GetGUID();
				tgt.m_targetMask=TARGET_FLAG_UNIT;
				sp->judgement = true;
				sp->prepare(&tgt);
			}

			uint32 judge_extra = 0;
			// This is for handling specific Judgement's debuff application spells
			switch(m_spellInfo->Id)
			{
			case 20271:
				judge_extra = 20185;
				break;
			case 53407:
				judge_extra = 20184;
				break;
			case 53408:
				judge_extra = 20186;
				break;
			}
			p_caster->CastSpell( unitTarget, judge_extra, true );
		}break;
	//warlock - Master Demonologist
	case 23784:
		{
			if( p_caster == NULL || unitTarget == NULL)
				return; //can't imagine how this talent got to anybody else then a player casted on pet
			uint32 casted_spell_id = 0 ;
			uint32 inc_resist_by_level = 0 ;
			uint32 inc_resist_by_level_spell = 0 ;
			if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 416 ) //in case it is imp
				casted_spell_id = 23759 ;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1860 ) //VoidWalker
				casted_spell_id = 23760 ;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1863 ) //Succubus
				casted_spell_id = 23761 ;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 417 ) //Felhunter
			{
				casted_spell_id = 0 ;
				inc_resist_by_level_spell = 23762 ;
				inc_resist_by_level = 20 ;
			}
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 17252 ) //Felguard
			{
				casted_spell_id = 35702 ;
				inc_resist_by_level_spell = 23762 ;
				inc_resist_by_level = 10 ;
			}
			if( casted_spell_id )
			{
				//for self
				SpellPointer sp = CREATESPELL( p_caster, dbcSpell.LookupEntry( casted_spell_id ), true, NULLAURA );
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = CREATESPELL(  unitTarget, dbcSpell.LookupEntry( casted_spell_id ), true, NULLAURA );
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
			if( inc_resist_by_level_spell )
			{
				//for self
				SpellPointer sp = CREATESPELL( p_caster, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULLAURA );
				sp->forced_basepoints[0] = p_caster->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = CREATESPELL( unitTarget, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULLAURA );
				sp->forced_basepoints[0] = unitTarget->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
		}break;
	case 23830:
		{
			if( p_caster == NULL || unitTarget == NULL)
				return; //can't imagine how this talent got to anybody else then a player casted on pet
			uint32 casted_spell_id = 0 ;
			uint32 inc_resist_by_level = 0 ;
			uint32 inc_resist_by_level_spell = 0 ;
			if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 416 ) //in case it is imp
				casted_spell_id = 23826 ;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1860 ) //VoidWalker
				casted_spell_id = 23841 ;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1863 ) //Succubus
				casted_spell_id = 23833 ;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 417 ) //Felhunter
			{
				casted_spell_id = 1 ;
				inc_resist_by_level_spell = 23837 ;
				inc_resist_by_level = 40 ;
			}
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 17252 ) //Felguard
			{
				casted_spell_id = 35703 ;
				inc_resist_by_level_spell = 23837 ;
				inc_resist_by_level = 20 ;
			}
			if( casted_spell_id )
			{
				//for self
				SpellPointer sp = CREATESPELL( p_caster, dbcSpell.LookupEntry( casted_spell_id ), true, NULLAURA );
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = CREATESPELL(  unitTarget, dbcSpell.LookupEntry( casted_spell_id ), true, NULLAURA );
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
			if( inc_resist_by_level_spell )
			{
				//for self
				SpellPointer sp = CREATESPELL( p_caster, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULLAURA );
				sp->forced_basepoints[0] = p_caster->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = CREATESPELL( unitTarget, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULLAURA );
				sp->forced_basepoints[0] = unitTarget->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
		}break;
	case 23831:
		{
			if( p_caster == NULL || unitTarget == NULL)
				return; //can't imagine how this talent got to anybody else then a player casted on pet
			uint32 casted_spell_id = 0 ;
			uint32 inc_resist_by_level = 0 ;
			uint32 inc_resist_by_level_spell = 0 ;
			if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 416 ) //in case it is imp
				casted_spell_id = 23827 ;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1860 ) //VoidWalker
				casted_spell_id = 23842 ;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1863 ) //Succubus
				casted_spell_id = 23834 ;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 417 ) //Felhunter
			{
				casted_spell_id = 0 ;
				inc_resist_by_level_spell = 23838 ;
				inc_resist_by_level = 60 ;
			}
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 17252 ) //Felguard
			{
				casted_spell_id = 35704 ;
				inc_resist_by_level_spell = 23838 ;
				inc_resist_by_level = 30 ;
			}
			if( casted_spell_id )
			{
				//for self
				SpellPointer sp = CREATESPELL( p_caster, dbcSpell.LookupEntry( casted_spell_id ), true, NULLAURA );
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = CREATESPELL(  unitTarget, dbcSpell.LookupEntry( casted_spell_id ), true, NULLAURA );
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
			if( inc_resist_by_level_spell )
			{
				//for self
				SpellPointer sp(new Spell( p_caster, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULLAURA ));
				sp->forced_basepoints[0] = p_caster->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = SpellPointer(new Spell( unitTarget, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULLAURA ));
				sp->forced_basepoints[0] = unitTarget->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
		}break;
	case 23832:
		{
			if( p_caster == NULL || unitTarget == NULL)
				return; //can't imagine how this talent got to anybody else then a player casted on pet
			uint32 casted_spell_id = 0 ;
			uint32 inc_resist_by_level = 0 ;
			uint32 inc_resist_by_level_spell = 0 ;
			if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 416 ) //in case it is imp
				casted_spell_id = 23828 ;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1860 ) //VoidWalker
				casted_spell_id = 23843 ;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1863 ) //Succubus
				casted_spell_id = 23835 ;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 417 ) //Felhunter
			{
				casted_spell_id = 0 ;
				inc_resist_by_level_spell = 23839 ;
				inc_resist_by_level = 80 ;
			}
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 17252 ) //Felguard
			{
				casted_spell_id = 35705 ;
				inc_resist_by_level_spell = 23839 ;
				inc_resist_by_level = 40 ;
			}
			if( casted_spell_id )
			{
				//for self
				SpellPointer sp = CREATESPELL( p_caster, dbcSpell.LookupEntry( casted_spell_id ), true, NULLAURA );
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = CREATESPELL(  unitTarget, dbcSpell.LookupEntry( casted_spell_id ), true, NULLAURA );
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
			if( inc_resist_by_level_spell )
			{
				//for self
				SpellPointer sp(new Spell( p_caster, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULLAURA ));
				sp->forced_basepoints[0] = p_caster->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				sp = SpellPointer(new Spell( unitTarget, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULLAURA ));
				sp->forced_basepoints[0] = unitTarget->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				sp->prepare( &tgt1 );
			}
		}break;
	case 35708:
		{
			if( p_caster == NULL || unitTarget == NULL)
				return; //can't imagine how this talent got to anybody else then a player casted on pet
			uint32 casted_spell_id = 0 ;
			uint32 inc_resist_by_level = 0 ;
			uint32 inc_resist_by_level_spell = 0 ;
			if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 416 ) //in case it is imp
				casted_spell_id = 23829 ;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1860 ) //VoidWalker
				casted_spell_id = 23844 ;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1863 ) //Succubus
				casted_spell_id = 23836 ;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 417 ) //Felhunter
			{
				casted_spell_id = 0 ;
				inc_resist_by_level_spell = 23840 ;
				inc_resist_by_level = 100 ;
			}
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 17252 ) //Felguard
			{
				casted_spell_id = 35706 ;
				inc_resist_by_level_spell = 23840 ;
				inc_resist_by_level = 50 ;
			}
			if( casted_spell_id )
			{
				//for self
				SpellPointer sp(new Spell( p_caster, dbcSpell.LookupEntry( casted_spell_id ), true, NULLAURA ));
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				SpellPointer Petsp(new Spell(  unitTarget, dbcSpell.LookupEntry( casted_spell_id ), true, NULLAURA ));
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				Petsp->prepare( &tgt1 );
			}
			if( inc_resist_by_level_spell )
			{
				//for self
				SpellPointer sp(new Spell( p_caster, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULLAURA ));
				sp->forced_basepoints[0] = p_caster->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt( p_caster->GetGUID() );
				sp->prepare( &tgt );
				//for pet
				SpellPointer Petsp(new Spell( unitTarget, dbcSpell.LookupEntry( inc_resist_by_level_spell ), true, NULLAURA ));
				Petsp->forced_basepoints[0] = unitTarget->GetUInt32Value( UNIT_FIELD_LEVEL ) * inc_resist_by_level / 100;
				SpellCastTargets tgt1( unitTarget->GetGUID() );
				Petsp->prepare( &tgt1 );
			}
		}break;
	case 44876:
		{
			if( !u_caster || !unitTarget )
				return;
			u_caster->CastSpell(unitTarget,damage,true);
		}break;
	case 47193: // [Warlock] Demonic Empowerment
		{
			if(!unitTarget)
				return;

			uint32 nspellid = 0;
			if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 416 ) //Imp
				nspellid = 54444;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1860 ) //VoidWalker
				nspellid = 54443;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 1863 ) //Succubus
				nspellid = 54436;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 417 ) //Felhunter
				nspellid = 54509;
			else if ( unitTarget->GetUInt32Value( OBJECT_FIELD_ENTRY ) == 17252 ) //Felguard
				nspellid = 54508;

			unitTarget->CastSpell(unitTarget, nspellid, true);
		}break;
	}
}

void Spell::SpellEffectSanctuary(uint32 i) // Stop all attacks made to you
{
	if(!u_caster)
		return;

	Object::InRangeSet::iterator itr = u_caster->GetInRangeOppFactsSetBegin();
	Object::InRangeSet::iterator itr_end = u_caster->GetInRangeOppFactsSetBegin();
	UnitPointer pUnit;

	for( ; itr != itr_end; ++itr )
	{
		pUnit = TO_UNIT(*itr);
		
		if( pUnit->GetTypeId() == TYPEID_UNIT )
			pUnit->GetAIInterface()->RemoveThreatByPtr( u_caster );
	}

	// also cancel any spells we are casting
	if( u_caster->GetCurrentSpell() != NULL && u_caster->GetCurrentSpell() != shared_from_this() && u_caster->GetCurrentSpell()->getState() == SPELL_STATE_PREPARING )
		u_caster->InterruptCurrentSpell();
}

void Spell::SpellEffectAddComboPoints(uint32 i) // Add Combo Points
{
	if(!p_caster)
		return;
  
	//if this is a procspell Ruthlessness (maybe others later)
	if(pSpellId && m_spellInfo->Id==14157)
	{
		//it seems this combo adding procspell is going to change combopoint count before they will get reseted. We add it after the reset
		/* burlex - this is wrong, and exploitable.. :/ if someone uses this they will have unlimited combo points */
		//re-enabled this by Zack. Explained why it is used + recheked to make sure initialization is good ...
		// while casting a spell talent will trigger uppon the spell prepare faze
		// the effect of the talent is to add 1 combo point but when triggering spell finishes it will clear the extra combo point
		p_caster->m_spellcomboPoints += damage;
		return;
	}
	p_caster->AddComboPoints(p_caster->GetSelection(), damage);
}

void Spell::SpellEffectCreateHouse(uint32 i) // Create House
{


}

void Spell::SpellEffectDuel(uint32 i) // Duel
{
	if(!p_caster)
		return;
	if(!p_caster->isAlive())
		return;

	if(p_caster->m_bg)
	{
		SendCastResult(SPELL_FAILED_NOT_IN_BATTLEGROUND);
		return;
	}

	if (p_caster->InStealth())
	{
		SendCastResult(SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED);
		return; // Player is stealth
	}
	if(!playerTarget)
		return;
	if(playerTarget == p_caster)
		return;

	if (!playerTarget)
	{
		SendCastResult(SPELL_FAILED_BAD_TARGETS);
		return; // invalid Target
	}
	if (!playerTarget->isAlive())
	{
		SendCastResult(SPELL_FAILED_TARGETS_DEAD);
		return; // Target not alive
	}
	if (playerTarget->hasStateFlag(UF_ATTACKING))
	{
		SendCastResult(SPELL_FAILED_TARGET_IN_COMBAT);
		return; // Target in combat with another unit
	}
	if (playerTarget->DuelingWith != NULL)
	{
		SendCastResult(SPELL_FAILED_TARGET_DUELING);
		return; // Already Dueling
	}

	if(playerTarget->bGMTagOn && !p_caster->GetSession()->HasPermissions())
	{
		SendCastResult(SPELL_FAILED_BAD_TARGETS);
		return;
	}

	p_caster->RequestDuel(playerTarget);
}

void Spell::SpellEffectStuck(uint32 i)
{
    if(!playerTarget || playerTarget != p_caster)
        return;

	float orientation = 0;

	sEventMgr.AddEvent(playerTarget,&Player::EventTeleport,playerTarget->GetBindMapId(),playerTarget->GetBindPositionX(),playerTarget->GetBindPositionY(),
		playerTarget->GetBindPositionZ(),orientation,EVENT_PLAYER_TELEPORT,50,1,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
	/*
	playerTarget->SafeTeleport(playerTarget->GetBindMapId(), 0, playerTarget->GetBindPositionX(), playerTarget->GetBindPositionY(), playerTarget->GetBindPositionZ(), 3.14f);*/
}

void Spell::SpellEffectSummonPlayer(uint32 i)
{
	if(!playerTarget)
		return;

	if(m_caster->GetMapMgr()->GetMapInfo() && m_caster->GetMapMgr()->GetMapInfo()->type != INSTANCE_NULL)
		return;
	
	playerTarget->SummonRequest(m_caster->GetLowGUID(), m_caster->GetZoneId(), m_caster->GetMapId(),
		m_caster->GetInstanceID(), m_caster->GetPosition());
}

void Spell::SpellEffectActivateObject(uint32 i) // Activate Object
{
	/*if(!p_caster)
		return;

	if(!gameObjTarget)
		return;

	gameObjTarget->SetUInt32Value(GAMEOBJECT_DYNAMIC, 1);

	sEventMgr.AddEvent(gameObjTarget, &GameObject::Deactivate, EVENT_GAMEOBJECT_DEACTIVATE, GetDuration(), 1);*/
}

void Spell::SummonTotem(uint32 i) // Summon Totem
{
	if(!p_caster) 
		return;

	float x = p_caster->GetPositionX();
	float y = p_caster->GetPositionY();
	uint32 slot = m_summonProperties->slot;

	switch(m_spellInfo->EffectMiscValueB[i])
	{
	case SUMMON_TYPE_TOTEM_1: 
		x -= 1.5f;
		y -= 1.5f;
		break;
	case SUMMON_TYPE_TOTEM_2: 
		x -= 1.5f;
		y += 1.5f;
		break;
	case SUMMON_TYPE_TOTEM_3:  
		x += 1.5f;
		y -= 1.5f;
		break;
	case SUMMON_TYPE_TOTEM_4: 
		x += 1.5f;
		y += 1.5f;
		break;
	default:
		break;
	}

	uint32 entry = m_spellInfo->EffectMiscValue[i];

	CreatureInfo* ci = CreatureNameStorage.LookupEntry(entry);
	if(!ci)
	{
		OUT_DEBUG("Missing totem creature entry : %u \n",entry);
		return;
	}

	// Obtain the spell we will be casting.
	SpellEntry * TotemSpell = ObjectMgr::getSingleton().GetTotemSpell(m_spellInfo->Id);
	if(TotemSpell == 0) 
	{
		OUT_DEBUG("Totem %u does not have any spells to cast, exiting\n",entry);
		return;
	}

	CreaturePointer pTotem = p_caster->GetMapMgr()->CreateCreature(entry);

	if( slot < 7 )
		p_caster->m_SummonSlots[slot] = pTotem;

	pTotem->SetTotemOwner(p_caster);
	pTotem->SetTotemSlot( int32(slot) );

	float landh = NO_WMO_HEIGHT;
	if (p_caster->GetMapMgr() && p_caster->GetMapMgr()->IsCollisionEnabled())
	{
		landh = CollideInterface.GetHeight(p_caster->GetMapId(), x, y, p_caster->GetPositionZ());
	}
	if(landh == NO_WMO_HEIGHT)
		landh = p_caster->GetMapMgr()->GetLandHeight(x,y);

	if(landh == 0.0f || landh == NO_LAND_HEIGHT || landh < p_caster->GetPositionZ())
	{
		landh = p_caster->GetPositionZ();
	}
	landh += 1.5f;

	pTotem->Create(ci->Name, p_caster->GetMapId(), x, y, landh, p_caster->GetOrientation());

	uint32 displayID = 0;

	if( p_caster->GetTeam() == 0 )
	{
		if ( ci->Female_DisplayID != 0 )
		{
			displayID = ci->Female_DisplayID; //this is the nice solution provided by emsy
		}
		else //this is the case when you are using a blizzlike db
		{
			if( ci->Male_DisplayID == 4587 )
				displayID = 19075;
			else if( ci->Male_DisplayID == 4588 )
				displayID = 19073;
			else if( ci->Male_DisplayID == 4589 )
				displayID = 19074;
			else if( ci->Male_DisplayID == 4590 )
				displayID = 19071;
			else if( ci->Male_DisplayID == 4683 )
				displayID = 19074;
			else
				displayID = ci->Male_DisplayID;
		}
	}
	else
	{
		displayID = ci->Male_DisplayID;
	}

	// Set up the creature.
	pTotem->SetUInt32Value(OBJECT_FIELD_ENTRY, entry);
	pTotem->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
	pTotem->SetUInt64Value(UNIT_FIELD_CREATEDBY, p_caster->GetGUID());
	pTotem->SetUInt32Value(UNIT_FIELD_HEALTH, damage > 1 ? damage: 5 );
	pTotem->SetUInt32Value(UNIT_FIELD_MAXHEALTH, damage > 1 ? damage: 5);
	pTotem->SetUInt32Value(UNIT_FIELD_POWER3, p_caster->getLevel() * 30);
	pTotem->SetUInt32Value(UNIT_FIELD_MAXPOWER3, p_caster->getLevel() * 30);
	pTotem->SetUInt32Value(UNIT_FIELD_LEVEL, p_caster->getLevel());
	pTotem->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, p_caster->GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE));
	pTotem->SetUInt32Value(UNIT_FIELD_BYTES_0, (1 << 8) | (2 << 16) | (1 << 24));
	pTotem->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED | UNIT_FLAG_SELF_RES);
	pTotem->SetUInt32Value(UNIT_FIELD_BASEATTACKTIME, 2000);
	pTotem->SetUInt32Value(UNIT_FIELD_RANGEDATTACKTIME, 2000);
	pTotem->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 1.0f);
	pTotem->SetFloatValue(UNIT_FIELD_COMBATREACH, 1.0f);
	pTotem->SetUInt32Value(UNIT_FIELD_DISPLAYID, displayID);
	pTotem->SetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID, ci->Male_DisplayID); //blizzlike :P
	pTotem->SetFloatValue(UNIT_MOD_CAST_SPEED, 1.0f);
	pTotem->SetUInt32Value(UNIT_CREATED_BY_SPELL, m_spellInfo->Id);
	if( p_caster->IsPvPFlagged() )
		pTotem->SetPvPFlag();

	if( p_caster->IsFFAPvPFlagged() )
		pTotem->SetFFAPvPFlag();

	// Initialize faction stuff.
	pTotem->m_faction = p_caster->m_faction;
	pTotem->m_factionDBC = p_caster->m_factionDBC;

	//added by Zack : Some shaman talents are casted on player but it should be inherited or something by totems
	pTotem->InheritSMMods(p_caster);
	// Totems get spell damage and healing bonus from the Shaman
	for(int school=0;school<7;school++){
		pTotem->ModDamageDone[school] = (int32)(p_caster->GetUInt32Value( PLAYER_FIELD_MOD_DAMAGE_DONE_POS + school ) - (int32)p_caster->GetUInt32Value( PLAYER_FIELD_MOD_DAMAGE_DONE_NEG + school ));
		pTotem->HealDoneMod[school] = p_caster->HealDoneMod[school];
	}

	// Set up AI, depending on our spells.
	uint32 j;
	for( j = 0; j < 3; ++j )
	{
		if( TotemSpell->Effect[j] == SPELL_EFFECT_APPLY_AREA_AURA || TotemSpell->Effect[j] == SPELL_EFFECT_PERSISTENT_AREA_AURA )
		{
			break;
		}
	}
	// Setup complete. Add us to the world.
	pTotem->PushToWorld(m_caster->GetMapMgr());

	if(j != 3)
	{
		// We're an area aura. Simple. Disable AI and cast the spell.
		pTotem->DisableAI();
		pTotem->GetAIInterface()->totemspell = m_spellInfo;

		SpellPointer pSpell(new Spell(pTotem, TotemSpell, true, NULLAURA));

		SpellCastTargets targets;
		targets.m_destX = pTotem->GetPositionX();
		targets.m_destY = pTotem->GetPositionY();
		targets.m_destZ = pTotem->GetPositionZ();
		targets.m_targetMask = TARGET_FLAG_DEST_LOCATION;

		pSpell->prepare(&targets);
	}
	else
	{
		// We're a casting totem. Switch AI on, and tell it to cast this spell.
		pTotem->EnableAI();
		pTotem->GetAIInterface()->Init(pTotem, AITYPE_TOTEM, MOVEMENTTYPE_NONE, p_caster);
		pTotem->GetAIInterface()->totemspell = TotemSpell;
		int32 totemspelltimer = 3000, totemspelltime = 3000;	// need a proper resource for this.

		switch(TotemSpell->Id)
		{
		case 51975: //Poison Cleansing Totem
		case 52025: //Disease Cleansing Totem
			{
				totemspelltime =  5000;
				totemspelltimer = 0; //First tick done immediately
				break;
			}
		case 8146: //Tremor Totem
			{
				totemspelltime = 1000;	// not sure about correctness, but spell amplitude = 1000
				totemspelltimer = 0; //First tick done immediately
				break;
			}
		default:break;
		}
		switch(m_spellInfo->NameHash)
		{
		case SPELL_HASH_STONECLAW_TOTEM:
			{
				totemspelltime = 30000; // Should be casted only once
				totemspelltimer = 0; // Casted immediately
				break;
			}
		case SPELL_HASH_MAGMA_TOTEM:
		case SPELL_HASH_MANA_SPRING_TOTEM:
		case SPELL_HASH_HEALING_STREAM_TOTEM:
			{
				totemspelltimer = totemspelltime = 2000;
				break;
			}
		case SPELL_HASH_SEARING_TOTEM:
			{
				totemspelltimer = totemspelltime = 2200;
				break;
			}
		case SPELL_HASH_FIRE_NOVA_TOTEM:
			{
				totemspelltime = totemspelltimer =  4000;
				break;
			}
		default:break;
		}

		pTotem->GetAIInterface()->m_totemspelltimer = totemspelltimer;
		pTotem->GetAIInterface()->m_totemspelltime = totemspelltime;
	}

	//in case these are our elemental totems then we should set them up
	if(m_spellInfo->Id==2062)
	{
		pTotem->GetAIInterface()->Event_Summon_EE_totem(GetDuration());
		pTotem->DisableAI();
	}
	else if(m_spellInfo->Id==2894)
	{
		pTotem->GetAIInterface()->Event_Summon_FE_totem(GetDuration());
		pTotem->DisableAI();
	}

	// Set up the deletion event. The totem needs to expire after a certain time, or upon its death.
	sEventMgr.AddEvent(pTotem, &Creature::TotemExpire, EVENT_TOTEM_EXPIRE, GetDuration(), 1,0);

	if( p_caster )
	{
		WorldPacket data(SMSG_TOTEM_CREATED, 20);
		data << uint8(m_summonProperties->slot - 1);
		data << pTotem->GetGUID();
		data << GetDuration();
		data << m_spellInfo->Id;
		p_caster->CopyAndSendDelayedPacket(&data);
	}
	
}

void Spell::SpellEffectSelfResurrect(uint32 i)
{
	if(!p_caster)   
		return;
	if(playerTarget->isAlive())
		return;
	uint32 mana;
	uint32 health;
	uint32 class_=unitTarget->getClass();
	
	switch(m_spellInfo->Id)
	{
	case 3026:
	case 20758:
	case 20759:
	case 20760:
	case 20761:
	case 27240:
		{
			health = m_spellInfo->EffectMiscValue[i];
			mana = -damage;
		}break;
	case 21169: //Reincarnation. Ressurect with 20% health and mana
		{
			health = uint32((unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH)*damage)/100);
			mana = uint32((unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1)*damage)/100);
		}
		break;
	default:
		{
			if(damage < 0) return;
			health = uint32(unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH)*damage/100);
			mana = uint32(unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1)*damage/100);
		}break;
        }

	if(class_==WARRIOR||class_==ROGUE)
		mana=0;
	
	playerTarget->m_resurrectHealth = health;
	playerTarget->m_resurrectMana = mana;

	playerTarget->ResurrectPlayer(NULLPLR);
	playerTarget->m_resurrectHealth = 0;
	playerTarget->m_resurrectMana = 0;
	playerTarget->SetMovement(MOVE_UNROOT, 1);

	playerTarget->SetUInt32Value(PLAYER_SELF_RES_SPELL, 0);

	if(m_spellInfo->Id==21169)
		AddCooldown();
}

void Spell::SpellEffectSkinning(uint32 i)
{
	if( unitTarget == NULL )
		return;

	uint32 sk = TO_PLAYER( m_caster )->_GetSkillLineCurrent( SKILL_SKINNING );
	uint32 lvl = unitTarget->getLevel();

	if( ( sk >= lvl * 5 ) || ( ( sk + 100 ) >= lvl * 10 ) )
	{
		//Fill loot for Skinning
		lootmgr.FillSkinningLoot(&TO_CREATURE(unitTarget)->m_loot,unitTarget->GetEntry());
		TO_PLAYER( m_caster )->SendLoot( unitTarget->GetGUID(), 2 );
		
		//Not skinable again
		TO_CREATURE(unitTarget)->Skinned = true;
		unitTarget->BuildFieldUpdatePacket( p_caster, UNIT_FIELD_FLAGS, 0 );

		//still lootable
		//pkt=unitTarget->BuildFieldUpdatePacket(UNIT_DYNAMIC_FLAGS,U_DYN_FLAG_LOOTABLE);
		//TO_PLAYER( m_caster )->GetSession()->SendPacket(pkt);
		//delete pkt;	 
		DetermineSkillUp(SKILL_SKINNING,sk<lvl*5?sk/5:lvl);
	}
	else
	{
		SendCastResult(SPELL_FAILED_TARGET_UNSKINNABLE);
	}   
			
//	DetermineSkillUp(SKILL_SKINNING,unitTarget->getLevel());
}

void Spell::SpellEffectCharge(uint32 i)
{
	if(!unitTarget)
		return;
	if(!p_caster)
		return;
	if(!unitTarget->isAlive())
		return;
    if (p_caster->IsStunned() || p_caster->m_rooted || p_caster->IsPacified() || p_caster->IsFeared())
        return;

	float x, y, z;
	float dx,dy;

	//if(unitTarget->GetTypeId() == TYPEID_UNIT)
	//	if(unitTarget->GetAIInterface())
	//		unitTarget->GetAIInterface()->StopMovement(5000);
	if(unitTarget->GetPositionX() == 0.0f || unitTarget->GetPositionY() == 0.0f)
		return;
	
	dx=unitTarget->GetPositionX()-m_caster->GetPositionX();
	dy=unitTarget->GetPositionY()-m_caster->GetPositionY();
	if(dx == 0.0f || dy == 0.0f)
		return;

	float d = sqrt(dx*dx+dy*dy)-unitTarget->GetFloatValue(UNIT_FIELD_BOUNDINGRADIUS)-m_caster->GetFloatValue(UNIT_FIELD_BOUNDINGRADIUS);
	float alpha = atanf(dy/dx);
	if(dx<0)
		alpha += float(M_PI);

	x = d*cosf(alpha)+m_caster->GetPositionX();
	y = d*sinf(alpha)+m_caster->GetPositionY();
	z = unitTarget->GetPositionZ();

	uint32 time = uint32( (m_caster->CalcDistance(unitTarget) / ((m_caster->m_runSpeed * 3.5) * 0.001f)) + 0.5);

	WorldPacket data(SMSG_MONSTER_MOVE, 50);
	data << m_caster->GetNewGUID();
	data << m_caster->GetPositionX();
	data << m_caster->GetPositionY();
	data << m_caster->GetPositionZ();
	data << getMSTime();
	data << uint8(0x00);
	data << uint32(0x00000100);
	data << time;
	data << uint32(1);
	data << x << y << z;
	if(unitTarget->GetTypeId() == TYPEID_UNIT)
		unitTarget->GetAIInterface()->StopMovement(2000);

	p_caster->SendMessageToSet(&data, true);   
	
	p_caster->SetPosition(x,y,z,alpha,true);
	p_caster->addStateFlag(UF_ATTACKING);
	p_caster ->smsg_AttackStart( unitTarget );
	p_caster->EventAttackStart();
	p_caster->setAttackTimer(time, false);
	p_caster->setAttackTimer(time, true);
	p_caster->ResetHeartbeatCoords();

	// trigger an event to reset speedhack detection
	p_caster->DelaySpeedHack( time + 1000 );
	p_caster->z_axisposition = 0.0f;
}

void Spell::SpellEffectPlayerPull( uint32 i )
{
	if( unitTarget == NULL || !unitTarget->isAlive() || !unitTarget->IsPlayer() )
		return;

	PlayerPointer p_target = TO_PLAYER( unitTarget );

	// calculate destination
	float pullD = p_target->CalcDistance( m_caster ) - p_target->GetFloatValue( UNIT_FIELD_BOUNDINGRADIUS ) - m_caster->GetFloatValue( UNIT_FIELD_BOUNDINGRADIUS ) - 1.0f;
	float pullO = p_target->calcRadAngle( p_target->GetPositionX(), p_target->GetPositionY(), m_caster->GetPositionX(), m_caster->GetPositionY() );
	float pullX = p_target->GetPositionX() + pullD * cosf( pullO );
	float pullY = p_target->GetPositionY() + pullD * sinf( pullO );
	float pullZ = m_caster->GetPositionZ() + 0.3f;
	uint32 time = uint32( pullD * 42.0f );

	p_target->SetOrientation( pullO );

	WorldPacket data( SMSG_MONSTER_MOVE, 60 );
	data << p_target->GetNewGUID();
	data << p_target->GetPositionX() << p_target->GetPositionY() << p_target->GetPositionZ();
	data << getMSTime();
	data << uint8( 4 );
	data << pullO;
	data << uint32( 0x00000100 );
	data << time;
	data << uint32( 1 );
	data << pullX << pullY << pullZ;

	p_target->SendMessageToSet( &data, true );   
}

void Spell::SummonNonCombatPet(uint32 i)
{
	if(!u_caster || u_caster->IsInWorld() == false)
		return;

	uint32 SummonCritterID = m_spellInfo->EffectMiscValue[i];

	// m_spellInfo->EffectDieSides[i] has something to do with dismissing our critter
	// when it is 1, it means to just dismiss it if we already have it
	// when it is 0, it could mean to always summon a new critter, but there seems to be exceptions

	if(!SummonCritterID) return;

	CreatureInfo * ci = CreatureNameStorage.LookupEntry(SummonCritterID);
	CreatureProto * cp = CreatureProtoStorage.LookupEntry(SummonCritterID);

	if(!ci || !cp) return;

	CreaturePointer pCreature = u_caster->GetMapMgr()->CreateCreature(SummonCritterID);
	pCreature->SetInstanceID(u_caster->GetMapMgr()->GetInstanceID());
	pCreature->Load(cp, m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), m_caster->GetOrientation());
	pCreature->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, 35);
	pCreature->_setFaction();
	pCreature->SetUInt32Value(UNIT_FIELD_LEVEL, 1);
	pCreature->GetAIInterface()->Init(pCreature,AITYPE_PET,MOVEMENTTYPE_NONE,u_caster);
	pCreature->GetAIInterface()->SetUnitToFollow(u_caster);
	pCreature->GetAIInterface()->SetUnitToFollowAngle(float(-(M_PI/2)));
	pCreature->GetAIInterface()->SetFollowDistance(3.0f);
	pCreature->GetAIInterface()->disable_melee = true;
	pCreature->bInvincible = true;
	pCreature->PushToWorld(u_caster->GetMapMgr());
	if( m_summonProperties->slot < 7 )
		u_caster->m_SummonSlots[ m_summonProperties->slot ] = pCreature;
}

void Spell::SpellEffectKnockBack(uint32 i)
{
	if(!unitTarget || !playerTarget || !m_caster)
		return;

	float dx, dy;
	float value1 = float(m_spellInfo->EffectBasePoints[i]+1);
	float value2 = float(m_spellInfo->EffectMiscValue[i]);
	float proportion;
	value2 ? proportion = value1/value2 : proportion = 0;

	if(proportion)
	{
		value1 = value1 / (10 * proportion);
		value2 = value2 / 10 * proportion;
	}
	else
	{
		value2 = value1 / 10;
		value1 = 0.1f;
	}

	dx = sinf(m_caster->GetOrientation());
	dy = cosf(m_caster->GetOrientation());

	WorldPacket data(SMSG_MOVE_KNOCK_BACK, 50);
	data << unitTarget->GetNewGUID();
	data << getMSTime();
	data << dy << dx;
	data << value1;
	data << -value2;
	if (playerTarget)
	{
		playerTarget->GetSession()->SendPacket(&data);
		playerTarget->DelaySpeedHack( 5000 );
	}
}

void Spell::SpellEffectDisenchant(uint32 i)
{
	PlayerPointer caster = TO_PLAYER( m_caster );
	ItemPointer it = caster->GetItemInterface()->GetItemByGUID(m_targets.m_itemTarget);
	if( it == NULL )
	{
		SendCastResult(SPELL_FAILED_CANT_BE_DISENCHANTED);
		return;
	}

	if( !it->m_looted )
	{
		lootmgr.FillDisenchantingLoot(&it->m_loot, it->GetEntry());

		if( it->m_loot.items.size() > 0 )
		{
			//Check for skill, we can increase it upto 75 
			uint32 skill=caster->_GetSkillLineCurrent( SKILL_ENCHANTING );
			if(skill < 75)//can up skill
			{
				if(Rand(float(100-skill*100.0/75.0)))
					caster->_AdvanceSkillLine(SKILL_ENCHANTING, float2int32( 1.0f * sWorld.getRate(RATE_SKILLRATE)));
			}
			OUT_DEBUG("SpellEffect","Succesfully disenchanted item %d", uint32(itemTarget->GetEntry()));
			p_caster->SendLoot( itemTarget->GetGUID(), LOOT_DISENCHANTING );
		} 
		else
		{
			OUT_DEBUG("SpellEffect","Disenchanting failed, item %d has no loot", uint32(itemTarget->GetEntry()));
			SendCastResult(SPELL_FAILED_CANT_BE_DISENCHANTED);
			return;
		}
		// delete from db so it won't be re-saved
		it->DeleteFromDB();
		it->m_looted = true;
	}
	if(it==i_caster)
		i_caster=NULLITEM;
}
void Spell::SpellEffectInebriate(uint32 i) // lets get drunk!
{
	if(!p_caster)
		return;

	// Drunkee!
	uint8 b2 = m_caster->GetByte(PLAYER_BYTES_3,1);
	b2 += damage;	// 10 beers will get you smassssshed!
  
	m_caster->SetByte(PLAYER_BYTES_3,1,b2>90?90:b2);
	sEventMgr.RemoveEvents(p_caster, EVENT_PLAYER_REDUCEDRUNK);
	sEventMgr.AddEvent(p_caster, &Player::EventReduceDrunk, false, EVENT_PLAYER_REDUCEDRUNK, 300000, 0,EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT);
}

void Spell::SpellEffectFeedPet(uint32 i)  // Feed Pet
{
	// food flags and food level are checked in Spell::CanCast()
	if(!itemTarget || !p_caster)
		return;
	
	PetPointer pPet = p_caster->GetSummon();
	if(!pPet)
		return;

	/**	Cast feed pet effect
	- effect is item level and pet level dependent, aura ticks are 35, 17, 8 (*1000) happiness
	- http://petopia.brashendeavors.net/html/articles/basics_feeding.shtml */
	int8 deltaLvl = pPet->getLevel() - itemTarget->GetProto()->ItemLevel;
	damage /= 1000; //damage of Feed pet spell is 35000
	if(deltaLvl > 10) damage = damage >> 1;//divide by 2
	if(deltaLvl > 20) damage = damage >> 1;
	damage *= 1000;

	SpellEntry *spellInfo = dbcSpell.LookupEntry(m_spellInfo->EffectTriggerSpell[i]);
	SpellPointer sp(new Spell(p_caster,spellInfo,true,NULLAURA));
	sp->forced_basepoints[0] = damage - 1;
	SpellCastTargets tgt;
	tgt.m_unitTarget=pPet->GetGUID();
	sp->prepare(&tgt);

	if(itemTarget->GetUInt32Value(ITEM_FIELD_STACK_COUNT)>1)
	{
		itemTarget->ModUnsigned32Value(ITEM_FIELD_STACK_COUNT, -1);
		itemTarget->m_isDirty=true;
	}
	else
	{
		p_caster->GetItemInterface()->SafeFullRemoveItemByGuid(itemTarget->GetGUID());
		itemTarget=NULLITEM;
	}
}

void Spell::SpellEffectReputation(uint32 i)
{
	if(!playerTarget)
		return;

	//playerTarget->modReputation(m_spellInfo->EffectMiscValue[i], damage, true);
	playerTarget->ModStanding(m_spellInfo->EffectMiscValue[i], damage);
}

void Spell::SpellEffectSummonObjectSlot(uint32 i)
{
	if(!u_caster || !u_caster->IsInWorld())
		return;

	GameObjectPointer GoSummon = NULLGOB;

	uint32 slot=m_spellInfo->Effect[i] - SPELL_EFFECT_SUMMON_OBJECT_SLOT1;
	GoSummon = u_caster->m_ObjectSlots[slot] ? u_caster->GetMapMgr()->GetGameObject(u_caster->m_ObjectSlots[slot]) : NULLGOB;
	u_caster->m_ObjectSlots[slot] = 0;
	
	if( GoSummon )
	{
		if(GoSummon->GetInstanceID() != u_caster->GetInstanceID())
			GoSummon->ExpireAndDelete();
		else
		{
			if( GoSummon->IsInWorld() )
				GoSummon->RemoveFromWorld(true);
			GoSummon->Destructor();
			GoSummon = NULLGOB;
		}
	}

   
	// spawn a new one
	GoSummon = u_caster->GetMapMgr()->CreateGameObject(m_spellInfo->EffectMiscValue[i]);
	if( GoSummon == NULL || !GoSummon->CreateFromProto(m_spellInfo->EffectMiscValue[i], m_caster->GetMapId(), m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), m_caster->GetOrientation(), 0.0f, 0.0f, 0.0f, 0.0f ))
		return;
	
	GoSummon->SetUInt32Value(GAMEOBJECT_LEVEL, u_caster->getLevel());
	GoSummon->SetUInt64Value(OBJECT_FIELD_CREATED_BY, m_caster->GetGUID()); 
	GoSummon->SetInstanceID(m_caster->GetInstanceID());

	if(GoSummon->GetByte(GAMEOBJECT_BYTES_1, GAMEOBJECT_BYTES_TYPE_ID) == GAMEOBJECT_TYPE_TRAP)
	{
		GoSummon->invisible = true;
		GoSummon->invisibilityFlag = INVIS_FLAG_TRAP;
		GoSummon->charges = 1;
		GoSummon->checkrate = 1;
		sEventMgr.AddEvent(GoSummon, &GameObject::TrapSearchTarget, EVENT_GAMEOBJECT_TRAP_SEARCH_TARGET, 100, 0,0);
	}
	else
	{
		sEventMgr.AddEvent(GoSummon, &GameObject::ExpireAndDelete, EVENT_GAMEOBJECT_EXPIRE, GetDuration(), 1,0);
	}
	GoSummon->PushToWorld(m_caster->GetMapMgr());
	GoSummon->SetSummoned(u_caster);
	u_caster->m_ObjectSlots[slot] = GoSummon->GetUIdFromGUID();
}

void Spell::SpellEffectDispelMechanic(uint32 i)
{
	if( !unitTarget || !unitTarget->isAlive() )
		return;

	int32 sMisc = (int32)m_spellInfo->EffectMiscValue[i];
	uint32 x;
	SpellEntry *p;

	if( unitTarget == u_caster || !isAttackable( u_caster, unitTarget ) )
	{
		for( x = MAX_POSITIVE_AURAS ; x<MAX_AURAS ; x++ )
		{
			if( unitTarget->m_auras[x] && !unitTarget->m_auras[x]->IsPositive())
			{
				p = unitTarget->m_auras[x]->GetSpellProto();
				if( Spell::HasMechanic(p, sMisc) )
				{
					unitTarget->m_auras[x]->AttemptDispel( u_caster );
				}
			}
		}
	}
	else
	{
		for( x = 0 ; x<MAX_POSITIVE_AURAS ; x++ )
		{
			if( unitTarget->m_auras[x] && unitTarget->m_auras[x]->IsPositive())
			{
				p = unitTarget->m_auras[x]->GetSpellProto();
				if( Spell::HasMechanic(p, sMisc) )
				{
					unitTarget->m_auras[x]->AttemptDispel( u_caster );
				}
			}
		}
	}

	if( playerTarget && m_spellInfo->NameHash == SPELL_HASH_DAZED && playerTarget->IsMounted() )
		TO_UNIT(playerTarget)->Dismount();
}

void Spell::SpellEffectSummonDeadPet(uint32 i)
{//this is pet resurrect
	if(!p_caster) 
		return;
	PetPointer pPet = p_caster->GetSummon();
	if(pPet)
	{
		pPet->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);
		pPet->SetUInt32Value(UNIT_FIELD_HEALTH, (uint32)((pPet->GetUInt32Value(UNIT_FIELD_MAXHEALTH) * damage) / 100));
		pPet->setDeathState(ALIVE);
		pPet->GetAIInterface()->HandleEvent(EVENT_FOLLOWOWNER, pPet, 0);
		sEventMgr.RemoveEvents(pPet, EVENT_PET_DELAYED_REMOVE);
	}
}

/* This effect has 2 functions
 * 1. It delete's all current totems from the player
 * 2. It returns a percentage of the mana back to the player
 *
 * Bur kick my ass if this is not safe:P
*/

void Spell::SpellEffectDestroyAllTotems(uint32 i)
{
	if(!p_caster || !p_caster->IsInWorld()) return;

	uint32 energize_amt = 0;
	for(uint32 x=SUMMON_TYPE_TOTEM_1;x<SUMMON_TYPE_TOTEM_4+1;x++)
	{
		SummonPropertiesEntry * spe = dbcSummonProps.LookupEntryForced(x);
		if(!spe) continue;

		// Ahh this code sucks
		if( x != SUMMON_TYPE_TOTEM_1 && x!= SUMMON_TYPE_TOTEM_2 && x != SUMMON_TYPE_TOTEM_3 && x != SUMMON_TYPE_TOTEM_4 )
			continue;

		uint32 slot = spe->slot;
		// atm totems are considert creature's
		if(p_caster->m_SummonSlots[slot])
		{
			uint32 SpellID = p_caster->m_SummonSlots[slot]->GetUInt32Value(UNIT_CREATED_BY_SPELL);
			SpellEntry * sp = dbcSpell.LookupEntry(SpellID);
			if (!sp)
				continue;

			if( sp->manaCost )
				energize_amt += float2int32( (sp->manaCost) * (damage/100.0f) );
			else if( sp->ManaCostPercentage )
				energize_amt += float2int32(((p_caster->GetUInt32Value(UNIT_FIELD_BASE_MANA)*sp->ManaCostPercentage)/100.0f) * (damage/100.0f) );

			p_caster->m_SummonSlots[slot]->TotemExpire();
			p_caster->m_SummonSlots[slot] = NULLCREATURE;
		}
	}

	if( energize_amt > 0 )
		p_caster->Energize(p_caster, m_spellInfo->Id, energize_amt, POWER_TYPE_MANA);
}

void Spell::SpellEffectSummonDemonOld(uint32 i)
{
	if(!p_caster/* ||  p_caster->getClass() != WARLOCK */) //summoning a demon shouldn't be warlock only, see spells 25005, 24934, 24810 etc etc
		return;
	PetPointer pPet = p_caster->GetSummon();
	if(pPet)
	{
		pPet->Dismiss(false);
	}

	CreatureInfo *ci = CreatureNameStorage.LookupEntry(m_spellInfo->EffectMiscValue[i]);
	if(ci)
	{

		pPet = objmgr.CreatePet();
		pPet->SetInstanceID(p_caster->GetInstanceID());
		pPet->CreateAsSummon(m_spellInfo->EffectMiscValue[i], ci, NULLCREATURE, p_caster, m_spellInfo, 1, 300000);
	}
	//Create Enslave Aura if its inferno spell
	if(m_spellInfo->Id == 1122)
	{
		SpellEntry *spellInfo = dbcSpell.LookupEntry(11726);
		
		SpellPointer sp(new Spell(TO_OBJECT(pPet),spellInfo,true,NULLAURA));
		SpellCastTargets tgt;
		tgt.m_unitTarget=pPet->GetGUID();
		sp->prepare(&tgt);
	}
}

void Spell::SpellEffectResurrect(uint32 i) // Resurrect (Flat)
{
	if(!playerTarget)
	{
		if(!corpseTarget)
		{
			// unit resurrection handler
			if(unitTarget)
			{
				if(unitTarget->GetTypeId()==TYPEID_UNIT && unitTarget->IsPet() && unitTarget->isDead())
				{
					uint32 hlth = ((uint32)m_spellInfo->EffectBasePoints[i] > unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH)) ? unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH) : (uint32)m_spellInfo->EffectBasePoints[i];
					uint32 mana = ((uint32)m_spellInfo->EffectBasePoints[i] > unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1)) ? unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1) : (uint32)m_spellInfo->EffectBasePoints[i];

					if(!unitTarget->IsPet())
					{
						sEventMgr.RemoveEvents(unitTarget, EVENT_CREATURE_REMOVE_CORPSE);
					}
					else
					{
						sEventMgr.RemoveEvents(unitTarget, EVENT_PET_DELAYED_REMOVE);
						sEventMgr.RemoveEvents(unitTarget, EVENT_CREATURE_REMOVE_CORPSE);
					}
					unitTarget->SetUInt32Value(UNIT_FIELD_HEALTH, hlth);
					unitTarget->SetUInt32Value(UNIT_FIELD_POWER1, mana);
					unitTarget->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);
					unitTarget->setDeathState(ALIVE);
					unitTarget->ClearLoot();
					TO_CREATURE(unitTarget)->ClearTag();
				}
			}

			return;
		}
		playerTarget = objmgr.GetPlayer(corpseTarget->GetUInt32Value(CORPSE_FIELD_OWNER));
		if(!playerTarget) return;
	}

	if(playerTarget->isAlive() || !playerTarget->IsInWorld())
		return;

	uint32 health = m_spellInfo->EffectBasePoints[i];
	uint32 mana = m_spellInfo->EffectMiscValue[i];
	
	playerTarget->m_resurrectHealth = health;
	playerTarget->m_resurrectMana = mana;

	SendResurrectRequest(playerTarget);   
	playerTarget->SetMovement(MOVE_UNROOT, 1);
}

void Spell::SpellEffectAttackMe(uint32 i)
{
	if(!unitTarget)
		return;
	if(!unitTarget->isAlive())
		return;

	unitTarget->GetAIInterface()->AttackReaction(u_caster,1,0);	
}

void Spell::SpellEffectSkinPlayerCorpse(uint32 i)
{
	CorpsePointer corpse = NULLCORPSE;
	if(!playerTarget)
	{
		// means we're "skinning" a corpse
		corpse = objmgr.GetCorpse((uint32)m_targets.m_unitTarget);  // hacky
	}
	else if(playerTarget->getDeathState() == CORPSE)	// repopped while we were casting 
	{
		corpse = objmgr.GetCorpse(playerTarget->GetLowGUID());
	}

	if(!m_caster->IsPlayer()) 
		return;
 
	if(playerTarget && !corpse)
	{
		if(!playerTarget->m_bg || !playerTarget->isDead() || playerTarget->m_insigniaTaken)
			return;

		// Set all the lootable stuff on the player. If he repops before we've looted, we'll set the flags
		// on corpse then :p
		playerTarget->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);

		// don't allow him to spawn a corpse
		playerTarget->m_insigniaTaken = true;

		// and.. force him to the graveyard and repop him.
		// this will also convert the corpse to bones.
		CorpsePointer pCorpse = playerTarget->RepopRequestedPlayer();

		// sanity checks
		if( pCorpse == NULL )
		{
			playerTarget->m_insigniaTaken = false;
			return;
		}

		// Send a message to the died player, telling him he has to resurrect at the graveyard.
		// Send an empty corpse location too, :P
		playerTarget->GetSession()->OutPacket(SMSG_PLAYER_SKINNED, 1, "\x00");
		playerTarget->GetSession()->OutPacket(MSG_CORPSE_QUERY, 1, "\x00");

		// fill loot vector
		playerTarget->GenerateLoot(pCorpse);

		// flag as lootable
		pCorpse->SetUInt32Value(CORPSE_FIELD_DYNAMIC_FLAGS, CORPSE_DYN_FLAG_LOOTABLE);

		// send the corpse's loot
		if( pCorpse != NULL )		// should never be null but /shrug
			p_caster->SendLoot(pCorpse->GetGUID(), 2);

	}else if(corpse)
	{
		if(corpse->GetUInt32Value(CORPSE_FIELD_FLAGS) != 60)
		{
			// cheater?
			return;
		}

		// find the corpses' owner
		PlayerPointer owner = objmgr.GetPlayer(corpse->GetUInt32Value(CORPSE_FIELD_OWNER));
		if(owner == NULL || owner->m_bg == NULL)
			return;

		owner->GetSession()->OutPacket(SMSG_PLAYER_SKINNED, 1, "\x00");
		owner->GetSession()->OutPacket(MSG_CORPSE_QUERY, 1, "\x00");

		// fill loot vector
		owner->GenerateLoot(corpse);
		
		// set lootable flag
		corpse->SetUInt32Value(CORPSE_FIELD_DYNAMIC_FLAGS, 1); // sets it so you can loot the plyr
		
		// remove skinnable flag
		corpse->SetUInt32Value(CORPSE_FIELD_FLAGS, 5);

		// remove owner association
		corpse->SetUInt64Value(CORPSE_FIELD_OWNER, 0);
		corpse->SetCorpseState(CORPSE_STATE_BONES);
		corpse->DeleteFromDB();
		objmgr.CorpseAddEventDespawn(corpse);

		// send loot
		p_caster->SendLoot(corpse->GetGUID(), 2);
	}
}

void Spell::SpellEffectSkill(uint32 i)
{
	// Used by professions only
	// Effect should be renamed in RequireSkill
	if(!p_caster)
		return;

	uint32 val = damage * 75 > 450 ? 450 :damage * 75;

	if( p_caster->_GetSkillLineMax(m_spellInfo->EffectMiscValue[i]) >= val )
		return;

	if( m_spellInfo->EffectMiscValue[i] == SKILL_RIDING )
		p_caster->_AddSkillLine( m_spellInfo->EffectMiscValue[i], val, val );
	else
	{
		if( p_caster->_HasSkillLine(m_spellInfo->EffectMiscValue[i]) )
			p_caster->_ModifySkillMaximum(m_spellInfo->EffectMiscValue[i], val);
		else
			p_caster->_AddSkillLine( m_spellInfo->EffectMiscValue[i], 1, val);
	}
}

void Spell::SpellEffectApplyPetAura(uint32 i)
{
	SpellEffectApplyAura(i);
}

void Spell::SpellEffectDummyMelee( uint32 i ) // Normalized Weapon damage +
{

	if( unitTarget == NULL || u_caster == NULL )
		return;

	if( m_spellInfo->NameHash == SPELL_HASH_OVERPOWER && p_caster != NULL ) //warrior : overpower - let us clear the event and the combopoint count
	{
		p_caster->NullComboPoints(); //some say that we should only remove 1 point per dodge. Due to cooldown you can't cast it twice anyway..
		sEventMgr.RemoveEvents( p_caster, EVENT_COMBO_POINT_CLEAR_FOR_TARGET );
	}
	else if( m_spellInfo->NameHash == SPELL_HASH_DEVASTATE)
	{
		//count the number of sunder armors on target
		uint32 sunder_count=0;
		SpellEntry *spellInfo=dbcSpell.LookupEntry(25225);
		for(uint32 x = MAX_POSITIVE_AURAS; x < MAX_AURAS; ++x)
		{
			if(unitTarget->m_auras[x] && unitTarget->m_auras[x]->GetSpellProto()->NameHash==SPELL_HASH_SUNDER_ARMOR)
			{
				sunder_count++;
				spellInfo=unitTarget->m_auras[x]->GetSpellProto();
			}
		}
		if(!spellInfo)
			return; //omg how did this happen ?
		//we should also cast sunder armor effect on target with or without dmg
		SpellPointer spell(new Spell(u_caster, spellInfo ,true, NULLAURA));
		spell->ProcedOnSpell = m_spellInfo;
		spell->pSpellId=m_spellInfo->Id;
		SpellCastTargets targets(unitTarget->GetGUID());
		spell->prepare(&targets);
		if(!sunder_count)
			return; //no damage = no joy
		damage = damage*sunder_count;
	}
	
	//Hemorrhage
	if( p_caster != NULL && m_spellInfo->NameHash == SPELL_HASH_HEMORRHAGE )
		p_caster->AddComboPoints(p_caster->GetSelection(), 1);

	switch( m_spellInfo->Id )
	{
			// AMBUSH
	case 8676: add_damage = 70; return; break;			// r1
	case 8724: add_damage = 100; return; break;			// r2
	case 8725: add_damage = 125; return; break;			// r3
	case 11267: add_damage = 185; return; break;		// r4
	case 11268: add_damage = 230; return; break;		// r5
	case 11269: add_damage = 290; return; break;		// r6
	case 27441: add_damage = 335; return; break;		// r7

			// BACKSTAB
	case 53: add_damage = 15; return; break;			// r1
	case 2589: add_damage = 30; return; break;			// r2
	case 2590: add_damage = 48; return; break;			// r3
	case 2591: add_damage = 69; return; break;			// r4
	case 8721: add_damage = 90; return; break;			// r5
	case 11279: add_damage = 135; return; break;		// r6
	case 11280: add_damage = 165; return; break;		// r7
	case 11281: add_damage = 210; return; break;		// r8
	case 25300: add_damage = 225; return; break;		// r9
	case 26863: add_damage = 255; return; break;		// r10
	}

	// rogue ambush etc
	for (uint32 x =0;x<3;x++)
		if(m_spellInfo->Effect[x] == SPELL_EFFECT_WEAPON_PERCENT_DAMAGE)
		{
			add_damage = damage * (m_spellInfo->EffectBasePoints[x]+1) /100;
			return;
		}

	//rogue - mutilate ads dmg if target is poisoned
	uint32 pct_dmg_mod = 100;
	if(	m_spellInfo->NameHash == SPELL_HASH_MUTILATE && unitTarget->IsPoisoned() )
		pct_dmg_mod = 120;

	uint32 _type;
	if( GetType() == SPELL_DMG_TYPE_RANGED )
		_type = RANGED;
	else
	{
		if (m_spellInfo->Flags4 & FLAGS4_OFFHAND)
			_type =  OFFHAND;
		else
			_type = MELEE;
	}
	u_caster->Strike( unitTarget, _type, m_spellInfo, damage, pct_dmg_mod, 0, false, true );
}

void Spell::SpellEffectSpellSteal( uint32 i )
{
	if (!unitTarget || !u_caster || !unitTarget->isAlive())
		return;

		AuraPointer aur;
	uint32 start,end;
	int32 spells_to_steal = damage;
	uint32 m;
	if(isAttackable(u_caster,unitTarget))
	{
		start=0;
		end=MAX_POSITIVE_AURAS;
	}
	else
		return;
	
	WorldPacket data(SMSG_SPELLDISPELLOG, 16);

	for(uint32 x=start;x<end;x++)
	if(unitTarget->m_auras[x])
	{
		aur = unitTarget->m_auras[x];
		if(aur->GetSpellId() != 15007 && !aur->IsPassive() && aur->IsPositive()) //Nothing can dispel resurrection sickness
		{
			if(aur->GetSpellProto()->DispelType == DISPEL_MAGIC && aur->GetDuration() > 0)
			{
				data.clear();
				data << m_caster->GetNewGUID();
				data << unitTarget->GetNewGUID();
				data << (uint32)1;
				data << aur->GetSpellId();
				m_caster->SendMessageToSet(&data,true);
				AuraPointer aura(new Aura(aur->GetSpellProto(), (aur->GetDuration()>120000) ? 120000 : aur->GetDuration(), u_caster, u_caster));
				aura->stackSize = aur->stackSize;

				// copy the mods across
				for( m = 0; m < aur->GetModCount(); ++m )
				{
					Modifier *mod = aur->GetMod(m);
					aura->AddMod(mod->m_type, mod->m_baseAmount, mod->m_miscValue, mod->i);
				}

				u_caster->AddAura(aura, NULLAURA);
				unitTarget->RemoveAura(aur);
				if( --spells_to_steal <= 0 )
					break; //exit loop now
			}			
		}
	}   
}

void Spell::SpellEffectProspecting(uint32 i)
{
	if(!p_caster) return;

	if(!itemTarget) // this should never happen
	{
		SendCastResult(SPELL_FAILED_ITEM_GONE);
		return;
	}

	uint32 entry = itemTarget->GetEntry();

	if(p_caster->GetItemInterface()->RemoveItemAmt(entry, 5))
	{
		p_caster->SetLootGUID(p_caster->GetGUID());
		lootmgr.FillProspectingLoot(&p_caster->m_loot, entry);
		p_caster->SendLoot(p_caster->GetGUID(), 2);
	}
	else // this should never happen either
	{
		SendCastResult(SPELL_FAILED_ITEM_GONE);
		return;
	}
}

void Spell::SpellEffectResurrectNew(uint32 i)
{
	//base p =hp,misc mana
	if(!playerTarget)
	{
		if(!corpseTarget)
		{
			// unit resurrection handler
			if(unitTarget)
			{
				if(unitTarget->GetTypeId()==TYPEID_UNIT && unitTarget->IsPet() && unitTarget->isDead())
				{
					uint32 hlth = ((uint32)m_spellInfo->EffectBasePoints[i] > unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH)) ? unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH) : (uint32)m_spellInfo->EffectBasePoints[i];
					uint32 mana = ((uint32)m_spellInfo->EffectBasePoints[i] > unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1)) ? unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1) : (uint32)m_spellInfo->EffectBasePoints[i];

					if(!unitTarget->IsPet())
					{
						sEventMgr.RemoveEvents(unitTarget, EVENT_CREATURE_REMOVE_CORPSE);
					}
					else
					{
						sEventMgr.RemoveEvents(unitTarget, EVENT_PET_DELAYED_REMOVE);
						sEventMgr.RemoveEvents(unitTarget, EVENT_CREATURE_REMOVE_CORPSE);
					}
					unitTarget->SetUInt32Value(UNIT_FIELD_HEALTH, hlth);
					unitTarget->SetUInt32Value(UNIT_FIELD_POWER1, mana);
					unitTarget->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);
					unitTarget->setDeathState(ALIVE);
					unitTarget->ClearLoot();
					TO_CREATURE(unitTarget)->ClearTag();
				}
			}

			return;
		}
		playerTarget = objmgr.GetPlayer(corpseTarget->GetUInt32Value(CORPSE_FIELD_OWNER));
		if(!playerTarget) return;
	}

	if(playerTarget->isAlive() || !playerTarget->IsInWorld())
		return;
   //resurr
	playerTarget->resurrector = p_caster->GetLowGUID();
	playerTarget->m_resurrectHealth = damage;
	playerTarget->m_resurrectMana = m_spellInfo->EffectMiscValue[i];
	playerTarget->m_resurrectLoction = p_caster->GetPosition();

	SendResurrectRequest(playerTarget);
}

void Spell::SpellEffectTranformItem(uint32 i)
{
	bool result;
	AddItemResult result2;

	if(!i_caster)
		return;
	uint32 itemid=m_spellInfo->EffectItemType[i];
	if(!itemid)
		return;

	//Save durability of the old item
	PlayerPointer owner=i_caster->GetOwner();
	uint32 dur= i_caster->GetUInt32Value(ITEM_FIELD_DURABILITY);
	//	int8 slot=owner->GetItemInterface()->GetInventorySlotByGuid(i_caster->GetGUID());
	//	uint32 invt=i_caster->GetProto()->InventoryType;

	   result  = owner->GetItemInterface()->SafeFullRemoveItemByGuid(i_caster->GetGUID());
	if(!result)
	{
		//something went wrong if this happen, item doesnt exist, so it wasnt destroyed.
		return;
	}

	i_caster=NULLITEM;

	ItemPointer it=objmgr.CreateItem(itemid,owner);
	it->SetDurability(dur);
	//additem
	
	   //additem
	result2 = owner->GetItemInterface()->AddItemToFreeSlot(it);
	if(!result2) //should never get here
	{ 
		owner->GetItemInterface()->BuildInventoryChangeError(NULLITEM, NULLITEM,INV_ERR_BAG_FULL);
		it->Destructor();
		it = NULLITEM;
	}
}

void Spell::SpellEffectEnvironmentalDamage(uint32 i)
{
	if(!playerTarget)
		return;

	if(unitTarget->SchoolImmunityList[m_spellInfo->School])
	{
		SendCastResult(SPELL_FAILED_IMMUNE);
		return;
	}
	//this is GO, not unit	
	m_caster->SpellNonMeleeDamageLog(unitTarget,m_spellInfo->Id,damage, pSpellId==0);
  
	WorldPacket data(SMSG_ENVIRONMENTALDAMAGELOG, 13);
	data << unitTarget->GetGUID();
	data << uint8(DAMAGE_FIRE);
	data << uint32(damage);
	unitTarget->SendMessageToSet( &data, true );
}

void Spell::SpellEffectDismissPet(uint32 i)
{
	// remove pet.. but don't delete so it can be called later
	if(!p_caster)
		return;

	PetPointer pPet = p_caster->GetSummon();
	if(!pPet)
		return;
	pPet->Remove(true, true, true);
}

void Spell::SpellEffectEnchantHeldItem( uint32 i )
{
	if( playerTarget == NULL )
		return;

	ItemPointer item = playerTarget->GetItemInterface()->GetInventoryItem( EQUIPMENT_SLOT_MAINHAND );
	if( item == NULL )
		return;

	uint32 Duration = 1800; // Needs to be found in dbc.. I guess?
	EnchantEntry * Enchantment = dbcEnchant.LookupEntry( m_spellInfo->EffectMiscValue[i] );
	
	if( Enchantment == NULL )
		return;

	item->RemoveEnchantment( 1 );
	item->AddEnchantment( Enchantment, Duration, false, true, false, 1 );
	item->SaveToDB(-1, EQUIPMENT_SLOT_MAINHAND, true, NULL);
}

void Spell::SpellEffectAddHonor(uint32 i)
{
	if( playerTarget == NULL )
		return;

	HonorHandler::AddHonorPointsToPlayer( playerTarget, m_spellInfo->EffectImplicitTargetA[i] );
}

void Spell::SpellEffectSpawn(uint32 i)
{
	// this effect is mostly for custom teleporting
	switch(m_spellInfo->Id)
	{
	  case 10418: // Arugal spawn-in spell , teleports it to 3 locations randomly sneeking players (bastard ;P)   
	  { 
		if(!u_caster || u_caster->IsPlayer())
			return;
		 
		static float coord[3][3]= {{-108.9034f,2129.5678f,144.9210f},{-108.9034f,2155.5678f,155.678f},{-77.9034f,2155.5678f,155.678f}};
		
		int i = (int)(rand()%3);
		u_caster->GetAIInterface()->SendMoveToPacket(coord[i][0],coord[i][1],coord[i][2],0.0f,0,u_caster->GetAIInterface()->getMoveFlags());
	  }
	}
}

void Spell::SpellEffectApplyAura128(uint32 i)
{
	if( u_caster->GetTypeId() == TYPEID_UNIT )
	{
		SpellEffectApplyAA(i);
	}
	else
	{
		if(m_spellInfo->EffectApplyAuraName[i] != 0)
			SpellEffectApplyAura(i);
	}
}

void Spell::SpellEffectRestoreManaPct(uint32 i)
{
	if(!u_caster || !unitTarget || !unitTarget->isAlive())
		return;

	uint32 maxMana = (uint32)unitTarget->GetUInt32Value(UNIT_FIELD_MAXPOWER1);
	uint32 modMana = damage * maxMana / 100;	

	u_caster->Energize(unitTarget, pSpellId ? pSpellId : m_spellInfo->Id, modMana, POWER_TYPE_MANA);
}

void Spell::SpellEffectRestoreHealthPct(uint32 i)
{
	if(!u_caster || !unitTarget || !unitTarget->isAlive())
		return;

	uint32 maxHp = (uint32)unitTarget->GetUInt32Value(UNIT_FIELD_MAXHEALTH);
	uint32 modHp = damage * maxHp / 100;

	u_caster->Heal(unitTarget, m_spellInfo->Id, modHp);
}

void Spell::SpellEffectTriggerSpellWithValue(uint32 i)
{
	if( unitTarget == NULL )
		return;

	SpellEntry* TriggeredSpell = dbcSpell.LookupEntryForced(m_spellInfo->EffectTriggerSpell[i]);
	if( TriggeredSpell == NULL )
		return;

	SpellPointer sp= CREATESPELL(m_caster,dbcSpell.LookupEntry(TriggeredSpell->Id),true,NULLAURA);

	for(uint32 x=0;x<3;x++)
	{
		sp->forced_basepoints[x] = TriggeredSpell->EffectBasePoints[i];
	}

	SpellCastTargets tgt(unitTarget->GetGUID());
	sp->prepare(&tgt);
}

void Spell::SpellEffectMegaJump(uint32 i)
{
	if(!u_caster) return;

	if( m_targets.m_destX == 0.0f && m_targets.m_destY == 0.0f && m_targets.m_destZ == 0.0f && m_targets.m_unitTarget )
	{
		UnitPointer u = u_caster->GetMapMgr()->GetUnit( m_targets.m_unitTarget );
		if( !u )
			return; // or we'll TP to some far off land :P
		
		m_targets.m_destX = u->GetPositionX();
		m_targets.m_destY = u->GetPositionY();
		m_targets.m_destZ = u->GetPositionZ();
		
	}

	// Time formula is derived from andy's logs, 271ms to move ~14.5 units
	float distance = u_caster->GetDistanceSq( m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ );
	uint32 moveTime = FL2UINT((distance * 271.0f) / 212.65f);
	u_caster->GetAIInterface()->SendMoveToPacket( m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ, 0.0f, moveTime, u_caster->GetAIInterface()->getMoveFlags() );

	u_caster->SetPosition( m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ, 0.0f, false );
	if( p_caster )
	{
		p_caster->ResetHeartbeatCoords();
		p_caster->DelaySpeedHack(5000);
	}
}

void Spell::SpellEffectMilling(uint32 i)
{
	if(!p_caster) return;

	if(!itemTarget)
	{
		SendCastResult(SPELL_FAILED_ITEM_GONE);
		return;
	}

	uint32 entry = itemTarget->GetEntry();

	if(p_caster->GetItemInterface()->RemoveItemAmt(entry, 5))
	{
		p_caster->SetLootGUID(p_caster->GetGUID());
		lootmgr.FillMillingLoot(&p_caster->m_loot, entry);
		p_caster->SendLoot(p_caster->GetGUID(), 2);
	}
	else
	{
		SendCastResult(SPELL_FAILED_ITEM_GONE);
		return;
	}
}

void Spell::SpellEffectTitanGrip(uint32 i)
{
	if (!playerTarget)
		return;
	playerTarget->titanGrip = true;
}

bool Spell::SpellEffectUpdateQuest(uint32 questid)
{ 
	QuestLogEntry *en=p_caster->GetQuestLogForEntry( questid );
	if( en != NULL && en->GetMobCount( 0 ) < en->GetQuest()->required_mobcount[0])
	{
		en->SetMobCount( 0, en->GetMobCount( 0 ) + 1 );//(collumn,count)
		en->SendUpdateAddKill( 0 );//(collumn)
		en->UpdatePlayerFields();
		return true;
	}
	return false;
}
