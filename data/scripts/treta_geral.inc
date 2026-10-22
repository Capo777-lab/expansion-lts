
PkmnCenterNurse_ServiceMenu::
	msgbox PkmnCenterNurse_Text_ServiceAsk, MSGBOX_DEFAULT
	dynmultichoice 1, 1, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, Svc_Text_Candy, Svc_Text_Shop, Svc_Text_Tower, Svc_Text_Raid, Svc_Text_Quests, Svc_Text_Difficulty, Svc_Text_Teleport, Svc_Text_Exit
	goto_if_eq VAR_RESULT, 0, PkmnCenterNurse_Svc_Candy
	goto_if_eq VAR_RESULT, 1, PkmnCenterNurse_OpenShop
	goto_if_eq VAR_RESULT, 2, Tower_Start
	goto_if_eq VAR_RESULT, 3, Raid_Start
	goto_if_eq VAR_RESULT, 4, PkmnCenterNurse_Svc_Quests
	goto_if_eq VAR_RESULT, 5, PkmnCenterNurse_Svc_Difficulty
	goto_if_eq VAR_RESULT, 6, PkmnCenterNurse_Svc_Teleport
	return

PkmnCenterNurse_Svc_Teleport::
	call Teleport_Menu
	goto PkmnCenterNurse_ServiceMenu

PkmnCenterNurse_Svc_Candy::
	additem ITEM_RARE_CANDY, 100
	msgbox Svc_Text_CandyDone, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

PkmnCenterNurse_Svc_Quests::
	call QuestLog_Menu
	goto PkmnCenterNurse_ServiceMenu

PkmnCenterNurse_Svc_Difficulty::
	call Difficulty_Choose
	goto PkmnCenterNurse_ServiceMenu

Difficulty_Choose::
	msgbox Difficulty_Text_Ask, MSGBOX_DEFAULT
	dynmultichoice 1, 1, TRUE, 4, 2, DYN_MULTICHOICE_CB_NONE, Diff_Text_1, Diff_Text_2, Diff_Text_3, Diff_Text_4
	addvar VAR_RESULT, 1
	copyvar VAR_UNUSED_0x4083, VAR_RESULT
	msgbox Difficulty_Text_Done, MSGBOX_DEFAULT
	return

Tower_Start::
	msgbox Tower_Text_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PkmnCenterNurse_ServiceMenu
	random 14
	goto_if_eq VAR_RESULT, 0, Tower_Fight_0
	goto_if_eq VAR_RESULT, 1, Tower_Fight_1
	goto_if_eq VAR_RESULT, 2, Tower_Fight_2
	goto_if_eq VAR_RESULT, 3, Tower_Fight_3
	goto_if_eq VAR_RESULT, 4, Tower_Fight_4
	goto_if_eq VAR_RESULT, 5, Tower_Fight_5
	goto_if_eq VAR_RESULT, 6, Tower_Fight_6
	goto_if_eq VAR_RESULT, 7, Tower_Fight_7
	goto_if_eq VAR_RESULT, 8, Tower_Fight_8
	goto_if_eq VAR_RESULT, 9, Tower_Fight_9
	goto_if_eq VAR_RESULT, 10, Tower_Fight_10
	goto_if_eq VAR_RESULT, 11, Tower_Fight_11
	goto_if_eq VAR_RESULT, 12, Tower_Fight_12
	goto_if_eq VAR_RESULT, 13, Tower_Fight_13
	goto PkmnCenterNurse_ServiceMenu

Tower_Fight_0::
	trainerbattle_no_intro TRAINER_SIDNEY, Tower_Text_Defeat
	goto Tower_Won

Tower_Fight_1::
	trainerbattle_no_intro TRAINER_PHOEBE, Tower_Text_Defeat
	goto Tower_Won

Tower_Fight_2::
	trainerbattle_no_intro TRAINER_GLACIA, Tower_Text_Defeat
	goto Tower_Won

Tower_Fight_3::
	trainerbattle_no_intro TRAINER_DRAKE, Tower_Text_Defeat
	goto Tower_Won

Tower_Fight_4::
	trainerbattle_no_intro TRAINER_ROXANNE_1, Tower_Text_Defeat
	goto Tower_Won

Tower_Fight_5::
	trainerbattle_no_intro TRAINER_BRAWLY_1, Tower_Text_Defeat
	goto Tower_Won

Tower_Fight_6::
	trainerbattle_no_intro TRAINER_WATTSON_1, Tower_Text_Defeat
	goto Tower_Won

Tower_Fight_7::
	trainerbattle_no_intro TRAINER_FLANNERY_1, Tower_Text_Defeat
	goto Tower_Won

Tower_Fight_8::
	trainerbattle_no_intro TRAINER_NORMAN_1, Tower_Text_Defeat
	goto Tower_Won

Tower_Fight_9::
	trainerbattle_no_intro TRAINER_WINONA_1, Tower_Text_Defeat
	goto Tower_Won

Tower_Fight_10::
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_1, Tower_Text_Defeat
	goto Tower_Won

Tower_Fight_11::
	trainerbattle_no_intro TRAINER_JUAN_1, Tower_Text_Defeat
	goto Tower_Won

Tower_Fight_12::
	trainerbattle_no_intro TRAINER_WALLACE, Tower_Text_Defeat
	goto Tower_Won

Tower_Fight_13::
	trainerbattle_no_intro TRAINER_STEVEN, Tower_Text_Defeat
	goto Tower_Won

Tower_Won::
	addvar VAR_UNUSED_0x408B, 1
	copyvar VAR_0x8008, VAR_UNUSED_0x408B
	buffernumberstring STR_VAR_1, VAR_0x8008
	msgbox Tower_Text_Won, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Start::
	msgbox Raid_Text_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PkmnCenterNurse_ServiceMenu
	msgbox Raid_Text_Tier, MSGBOX_DEFAULT
	dynmultichoice 1, 1, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, Raid_Tier_1, Raid_Tier_2, Raid_Tier_3, Raid_Tier_4, Raid_Tier_Exit
	goto_if_ge VAR_RESULT, 4, PkmnCenterNurse_ServiceMenu
	copyvar VAR_0x800A, VAR_RESULT
	random 14
	goto_if_eq VAR_RESULT, 0, Raid_Boss_0
	goto_if_eq VAR_RESULT, 1, Raid_Boss_1
	goto_if_eq VAR_RESULT, 2, Raid_Boss_2
	goto_if_eq VAR_RESULT, 3, Raid_Boss_3
	goto_if_eq VAR_RESULT, 4, Raid_Boss_4
	goto_if_eq VAR_RESULT, 5, Raid_Boss_5
	goto_if_eq VAR_RESULT, 6, Raid_Boss_6
	goto_if_eq VAR_RESULT, 7, Raid_Boss_7
	goto_if_eq VAR_RESULT, 8, Raid_Boss_8
	goto_if_eq VAR_RESULT, 9, Raid_Boss_9
	goto_if_eq VAR_RESULT, 10, Raid_Boss_10
	goto_if_eq VAR_RESULT, 11, Raid_Boss_11
	goto_if_eq VAR_RESULT, 12, Raid_Boss_12
	goto_if_eq VAR_RESULT, 13, Raid_Boss_13
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_0::
	goto_if_eq VAR_0x800A, 0, Raid_Boss_0_T0
	goto_if_eq VAR_0x800A, 1, Raid_Boss_0_T1
	goto_if_eq VAR_0x800A, 2, Raid_Boss_0_T2
	goto_if_eq VAR_0x800A, 3, Raid_Boss_0_T3
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_0_T0::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_MEWTWO, 50
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_0_T1::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_MEWTWO, 70
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_0_T2::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_MEWTWO, 90
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_0_T3::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_MEWTWO, 100
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_1::
	goto_if_eq VAR_0x800A, 0, Raid_Boss_1_T0
	goto_if_eq VAR_0x800A, 1, Raid_Boss_1_T1
	goto_if_eq VAR_0x800A, 2, Raid_Boss_1_T2
	goto_if_eq VAR_0x800A, 3, Raid_Boss_1_T3
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_1_T0::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_RAYQUAZA, 50
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_1_T1::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_RAYQUAZA, 70
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_1_T2::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_RAYQUAZA, 90
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_1_T3::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_RAYQUAZA, 100
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_2::
	goto_if_eq VAR_0x800A, 0, Raid_Boss_2_T0
	goto_if_eq VAR_0x800A, 1, Raid_Boss_2_T1
	goto_if_eq VAR_0x800A, 2, Raid_Boss_2_T2
	goto_if_eq VAR_0x800A, 3, Raid_Boss_2_T3
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_2_T0::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_KYOGRE, 50
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_2_T1::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_KYOGRE, 70
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_2_T2::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_KYOGRE, 90
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_2_T3::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_KYOGRE, 100
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_3::
	goto_if_eq VAR_0x800A, 0, Raid_Boss_3_T0
	goto_if_eq VAR_0x800A, 1, Raid_Boss_3_T1
	goto_if_eq VAR_0x800A, 2, Raid_Boss_3_T2
	goto_if_eq VAR_0x800A, 3, Raid_Boss_3_T3
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_3_T0::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_GROUDON, 50
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_3_T1::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_GROUDON, 70
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_3_T2::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_GROUDON, 90
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_3_T3::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_GROUDON, 100
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_4::
	goto_if_eq VAR_0x800A, 0, Raid_Boss_4_T0
	goto_if_eq VAR_0x800A, 1, Raid_Boss_4_T1
	goto_if_eq VAR_0x800A, 2, Raid_Boss_4_T2
	goto_if_eq VAR_0x800A, 3, Raid_Boss_4_T3
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_4_T0::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_LUGIA, 50
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_4_T1::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_LUGIA, 70
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_4_T2::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_LUGIA, 90
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_4_T3::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_LUGIA, 100
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_5::
	goto_if_eq VAR_0x800A, 0, Raid_Boss_5_T0
	goto_if_eq VAR_0x800A, 1, Raid_Boss_5_T1
	goto_if_eq VAR_0x800A, 2, Raid_Boss_5_T2
	goto_if_eq VAR_0x800A, 3, Raid_Boss_5_T3
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_5_T0::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_HO_OH, 50
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_5_T1::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_HO_OH, 70
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_5_T2::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_HO_OH, 90
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_5_T3::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_HO_OH, 100
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_6::
	goto_if_eq VAR_0x800A, 0, Raid_Boss_6_T0
	goto_if_eq VAR_0x800A, 1, Raid_Boss_6_T1
	goto_if_eq VAR_0x800A, 2, Raid_Boss_6_T2
	goto_if_eq VAR_0x800A, 3, Raid_Boss_6_T3
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_6_T0::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_LATIAS, 50
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_6_T1::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_LATIAS, 70
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_6_T2::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_LATIAS, 90
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_6_T3::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_LATIAS, 100
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_7::
	goto_if_eq VAR_0x800A, 0, Raid_Boss_7_T0
	goto_if_eq VAR_0x800A, 1, Raid_Boss_7_T1
	goto_if_eq VAR_0x800A, 2, Raid_Boss_7_T2
	goto_if_eq VAR_0x800A, 3, Raid_Boss_7_T3
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_7_T0::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_LATIOS, 50
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_7_T1::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_LATIOS, 70
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_7_T2::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_LATIOS, 90
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_7_T3::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_LATIOS, 100
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_8::
	goto_if_eq VAR_0x800A, 0, Raid_Boss_8_T0
	goto_if_eq VAR_0x800A, 1, Raid_Boss_8_T1
	goto_if_eq VAR_0x800A, 2, Raid_Boss_8_T2
	goto_if_eq VAR_0x800A, 3, Raid_Boss_8_T3
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_8_T0::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_GIRATINA, 50
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_8_T1::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_GIRATINA, 70
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_8_T2::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_GIRATINA, 90
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_8_T3::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_GIRATINA, 100
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_9::
	goto_if_eq VAR_0x800A, 0, Raid_Boss_9_T0
	goto_if_eq VAR_0x800A, 1, Raid_Boss_9_T1
	goto_if_eq VAR_0x800A, 2, Raid_Boss_9_T2
	goto_if_eq VAR_0x800A, 3, Raid_Boss_9_T3
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_9_T0::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_DIALGA, 50
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_9_T1::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_DIALGA, 70
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_9_T2::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_DIALGA, 90
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_9_T3::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_DIALGA, 100
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_10::
	goto_if_eq VAR_0x800A, 0, Raid_Boss_10_T0
	goto_if_eq VAR_0x800A, 1, Raid_Boss_10_T1
	goto_if_eq VAR_0x800A, 2, Raid_Boss_10_T2
	goto_if_eq VAR_0x800A, 3, Raid_Boss_10_T3
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_10_T0::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_PALKIA, 50
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_10_T1::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_PALKIA, 70
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_10_T2::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_PALKIA, 90
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_10_T3::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_PALKIA, 100
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_11::
	goto_if_eq VAR_0x800A, 0, Raid_Boss_11_T0
	goto_if_eq VAR_0x800A, 1, Raid_Boss_11_T1
	goto_if_eq VAR_0x800A, 2, Raid_Boss_11_T2
	goto_if_eq VAR_0x800A, 3, Raid_Boss_11_T3
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_11_T0::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_ARCEUS, 50
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_11_T1::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_ARCEUS, 70
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_11_T2::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_ARCEUS, 90
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_11_T3::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_ARCEUS, 100
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_12::
	goto_if_eq VAR_0x800A, 0, Raid_Boss_12_T0
	goto_if_eq VAR_0x800A, 1, Raid_Boss_12_T1
	goto_if_eq VAR_0x800A, 2, Raid_Boss_12_T2
	goto_if_eq VAR_0x800A, 3, Raid_Boss_12_T3
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_12_T0::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_ZEKROM, 50
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_12_T1::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_ZEKROM, 70
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_12_T2::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_ZEKROM, 90
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_12_T3::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_ZEKROM, 100
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_13::
	goto_if_eq VAR_0x800A, 0, Raid_Boss_13_T0
	goto_if_eq VAR_0x800A, 1, Raid_Boss_13_T1
	goto_if_eq VAR_0x800A, 2, Raid_Boss_13_T2
	goto_if_eq VAR_0x800A, 3, Raid_Boss_13_T3
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_13_T0::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_RESHIRAM, 50
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_13_T1::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_RESHIRAM, 70
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_13_T2::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_RESHIRAM, 90
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Boss_13_T3::
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_RESHIRAM, 100
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Raid_Complete
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Raid_Complete
	msgbox Raid_Text_Failed, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

Raid_Complete::
	addvar VAR_UNUSED_0x4091, 1
	copyvar VAR_0x8008, VAR_UNUSED_0x4091
	buffernumberstring STR_VAR_1, VAR_0x8008
	msgbox Raid_Text_Done, MSGBOX_DEFAULT
	goto PkmnCenterNurse_ServiceMenu

QR_GiveRandomLegend::
	random 35
	goto_if_eq VAR_RESULT, 0, QR_RL_0
	goto_if_eq VAR_RESULT, 1, QR_RL_1
	goto_if_eq VAR_RESULT, 2, QR_RL_2
	goto_if_eq VAR_RESULT, 3, QR_RL_3
	goto_if_eq VAR_RESULT, 4, QR_RL_4
	goto_if_eq VAR_RESULT, 5, QR_RL_5
	goto_if_eq VAR_RESULT, 6, QR_RL_6
	goto_if_eq VAR_RESULT, 7, QR_RL_7
	goto_if_eq VAR_RESULT, 8, QR_RL_8
	goto_if_eq VAR_RESULT, 9, QR_RL_9
	goto_if_eq VAR_RESULT, 10, QR_RL_10
	goto_if_eq VAR_RESULT, 11, QR_RL_11
	goto_if_eq VAR_RESULT, 12, QR_RL_12
	goto_if_eq VAR_RESULT, 13, QR_RL_13
	goto_if_eq VAR_RESULT, 14, QR_RL_14
	goto_if_eq VAR_RESULT, 15, QR_RL_15
	goto_if_eq VAR_RESULT, 16, QR_RL_16
	goto_if_eq VAR_RESULT, 17, QR_RL_17
	goto_if_eq VAR_RESULT, 18, QR_RL_18
	goto_if_eq VAR_RESULT, 19, QR_RL_19
	goto_if_eq VAR_RESULT, 20, QR_RL_20
	goto_if_eq VAR_RESULT, 21, QR_RL_21
	goto_if_eq VAR_RESULT, 22, QR_RL_22
	goto_if_eq VAR_RESULT, 23, QR_RL_23
	goto_if_eq VAR_RESULT, 24, QR_RL_24
	goto_if_eq VAR_RESULT, 25, QR_RL_25
	goto_if_eq VAR_RESULT, 26, QR_RL_26
	goto_if_eq VAR_RESULT, 27, QR_RL_27
	goto_if_eq VAR_RESULT, 28, QR_RL_28
	goto_if_eq VAR_RESULT, 29, QR_RL_29
	goto_if_eq VAR_RESULT, 30, QR_RL_30
	goto_if_eq VAR_RESULT, 31, QR_RL_31
	goto_if_eq VAR_RESULT, 32, QR_RL_32
	goto_if_eq VAR_RESULT, 33, QR_RL_33
	goto_if_eq VAR_RESULT, 34, QR_RL_34
	return

QR_RL_0::
	goto_if_eq VAR_0x8009, 1, QR_RLS_0
	givemon SPECIES_ARTICUNO, 70
	return

QR_RLS_0::
	givemon SPECIES_ARTICUNO, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_1::
	goto_if_eq VAR_0x8009, 1, QR_RLS_1
	givemon SPECIES_ZAPDOS, 70
	return

QR_RLS_1::
	givemon SPECIES_ZAPDOS, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_2::
	goto_if_eq VAR_0x8009, 1, QR_RLS_2
	givemon SPECIES_MOLTRES, 70
	return

QR_RLS_2::
	givemon SPECIES_MOLTRES, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_3::
	goto_if_eq VAR_0x8009, 1, QR_RLS_3
	givemon SPECIES_MEWTWO, 70
	return

QR_RLS_3::
	givemon SPECIES_MEWTWO, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_4::
	goto_if_eq VAR_0x8009, 1, QR_RLS_4
	givemon SPECIES_MEW, 70
	return

QR_RLS_4::
	givemon SPECIES_MEW, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_5::
	goto_if_eq VAR_0x8009, 1, QR_RLS_5
	givemon SPECIES_RAIKOU, 70
	return

QR_RLS_5::
	givemon SPECIES_RAIKOU, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_6::
	goto_if_eq VAR_0x8009, 1, QR_RLS_6
	givemon SPECIES_ENTEI, 70
	return

QR_RLS_6::
	givemon SPECIES_ENTEI, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_7::
	goto_if_eq VAR_0x8009, 1, QR_RLS_7
	givemon SPECIES_SUICUNE, 70
	return

QR_RLS_7::
	givemon SPECIES_SUICUNE, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_8::
	goto_if_eq VAR_0x8009, 1, QR_RLS_8
	givemon SPECIES_LUGIA, 70
	return

QR_RLS_8::
	givemon SPECIES_LUGIA, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_9::
	goto_if_eq VAR_0x8009, 1, QR_RLS_9
	givemon SPECIES_HO_OH, 70
	return

QR_RLS_9::
	givemon SPECIES_HO_OH, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_10::
	goto_if_eq VAR_0x8009, 1, QR_RLS_10
	givemon SPECIES_CELEBI, 70
	return

QR_RLS_10::
	givemon SPECIES_CELEBI, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_11::
	goto_if_eq VAR_0x8009, 1, QR_RLS_11
	givemon SPECIES_REGIROCK, 70
	return

QR_RLS_11::
	givemon SPECIES_REGIROCK, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_12::
	goto_if_eq VAR_0x8009, 1, QR_RLS_12
	givemon SPECIES_REGICE, 70
	return

QR_RLS_12::
	givemon SPECIES_REGICE, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_13::
	goto_if_eq VAR_0x8009, 1, QR_RLS_13
	givemon SPECIES_REGISTEEL, 70
	return

QR_RLS_13::
	givemon SPECIES_REGISTEEL, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_14::
	goto_if_eq VAR_0x8009, 1, QR_RLS_14
	givemon SPECIES_LATIAS, 70
	return

QR_RLS_14::
	givemon SPECIES_LATIAS, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_15::
	goto_if_eq VAR_0x8009, 1, QR_RLS_15
	givemon SPECIES_LATIOS, 70
	return

QR_RLS_15::
	givemon SPECIES_LATIOS, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_16::
	goto_if_eq VAR_0x8009, 1, QR_RLS_16
	givemon SPECIES_KYOGRE, 70
	return

QR_RLS_16::
	givemon SPECIES_KYOGRE, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_17::
	goto_if_eq VAR_0x8009, 1, QR_RLS_17
	givemon SPECIES_GROUDON, 70
	return

QR_RLS_17::
	givemon SPECIES_GROUDON, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_18::
	goto_if_eq VAR_0x8009, 1, QR_RLS_18
	givemon SPECIES_RAYQUAZA, 70
	return

QR_RLS_18::
	givemon SPECIES_RAYQUAZA, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_19::
	goto_if_eq VAR_0x8009, 1, QR_RLS_19
	givemon SPECIES_JIRACHI, 70
	return

QR_RLS_19::
	givemon SPECIES_JIRACHI, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_20::
	goto_if_eq VAR_0x8009, 1, QR_RLS_20
	givemon SPECIES_DIALGA, 70
	return

QR_RLS_20::
	givemon SPECIES_DIALGA, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_21::
	goto_if_eq VAR_0x8009, 1, QR_RLS_21
	givemon SPECIES_PALKIA, 70
	return

QR_RLS_21::
	givemon SPECIES_PALKIA, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_22::
	goto_if_eq VAR_0x8009, 1, QR_RLS_22
	givemon SPECIES_GIRATINA, 70
	return

QR_RLS_22::
	givemon SPECIES_GIRATINA, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_23::
	goto_if_eq VAR_0x8009, 1, QR_RLS_23
	givemon SPECIES_ARCEUS, 70
	return

QR_RLS_23::
	givemon SPECIES_ARCEUS, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_24::
	goto_if_eq VAR_0x8009, 1, QR_RLS_24
	givemon SPECIES_REGIGIGAS, 70
	return

QR_RLS_24::
	givemon SPECIES_REGIGIGAS, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_25::
	goto_if_eq VAR_0x8009, 1, QR_RLS_25
	givemon SPECIES_ZEKROM, 70
	return

QR_RLS_25::
	givemon SPECIES_ZEKROM, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_26::
	goto_if_eq VAR_0x8009, 1, QR_RLS_26
	givemon SPECIES_RESHIRAM, 70
	return

QR_RLS_26::
	givemon SPECIES_RESHIRAM, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_27::
	goto_if_eq VAR_0x8009, 1, QR_RLS_27
	givemon SPECIES_XERNEAS, 70
	return

QR_RLS_27::
	givemon SPECIES_XERNEAS, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_28::
	goto_if_eq VAR_0x8009, 1, QR_RLS_28
	givemon SPECIES_YVELTAL, 70
	return

QR_RLS_28::
	givemon SPECIES_YVELTAL, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_29::
	goto_if_eq VAR_0x8009, 1, QR_RLS_29
	givemon SPECIES_SOLGALEO, 70
	return

QR_RLS_29::
	givemon SPECIES_SOLGALEO, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_30::
	goto_if_eq VAR_0x8009, 1, QR_RLS_30
	givemon SPECIES_LUNALA, 70
	return

QR_RLS_30::
	givemon SPECIES_LUNALA, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_31::
	goto_if_eq VAR_0x8009, 1, QR_RLS_31
	givemon SPECIES_ZACIAN, 70
	return

QR_RLS_31::
	givemon SPECIES_ZACIAN, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_32::
	goto_if_eq VAR_0x8009, 1, QR_RLS_32
	givemon SPECIES_ZAMAZENTA, 70
	return

QR_RLS_32::
	givemon SPECIES_ZAMAZENTA, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_33::
	goto_if_eq VAR_0x8009, 1, QR_RLS_33
	givemon SPECIES_KORAIDON, 70
	return

QR_RLS_33::
	givemon SPECIES_KORAIDON, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_RL_34::
	goto_if_eq VAR_0x8009, 1, QR_RLS_34
	givemon SPECIES_MIRAIDON, 70
	return

QR_RLS_34::
	givemon SPECIES_MIRAIDON, 70, shinyMode=SHINY_MODE_ALWAYS
	return

QR_ChooseLegend::
	msgbox QR_Text_Choose, MSGBOX_DEFAULT
	dynmultichoice 1, 1, TRUE, 6, 0, DYN_MULTICHOICE_CB_NONE, QR_Name_0, QR_Name_1, QR_Name_2, QR_Name_3, QR_Name_4, QR_Name_5, QR_Name_6, QR_Name_7, QR_Name_8, QR_Name_9, QR_Name_10, QR_Name_11, QR_Name_12, QR_Name_13, QR_Name_14, QR_Name_15, QR_Name_16, QR_Name_17, QR_Name_18, QR_Name_19, QR_Name_20, QR_Name_21, QR_Name_22, QR_Name_23, QR_Name_24, QR_Name_25, QR_Name_26, QR_Name_27, QR_Name_28, QR_Name_29, QR_Name_30, QR_Name_31, QR_Name_32, QR_Name_33, QR_Name_34
	goto_if_eq VAR_RESULT, 0, QR_RL_0
	goto_if_eq VAR_RESULT, 1, QR_RL_1
	goto_if_eq VAR_RESULT, 2, QR_RL_2
	goto_if_eq VAR_RESULT, 3, QR_RL_3
	goto_if_eq VAR_RESULT, 4, QR_RL_4
	goto_if_eq VAR_RESULT, 5, QR_RL_5
	goto_if_eq VAR_RESULT, 6, QR_RL_6
	goto_if_eq VAR_RESULT, 7, QR_RL_7
	goto_if_eq VAR_RESULT, 8, QR_RL_8
	goto_if_eq VAR_RESULT, 9, QR_RL_9
	goto_if_eq VAR_RESULT, 10, QR_RL_10
	goto_if_eq VAR_RESULT, 11, QR_RL_11
	goto_if_eq VAR_RESULT, 12, QR_RL_12
	goto_if_eq VAR_RESULT, 13, QR_RL_13
	goto_if_eq VAR_RESULT, 14, QR_RL_14
	goto_if_eq VAR_RESULT, 15, QR_RL_15
	goto_if_eq VAR_RESULT, 16, QR_RL_16
	goto_if_eq VAR_RESULT, 17, QR_RL_17
	goto_if_eq VAR_RESULT, 18, QR_RL_18
	goto_if_eq VAR_RESULT, 19, QR_RL_19
	goto_if_eq VAR_RESULT, 20, QR_RL_20
	goto_if_eq VAR_RESULT, 21, QR_RL_21
	goto_if_eq VAR_RESULT, 22, QR_RL_22
	goto_if_eq VAR_RESULT, 23, QR_RL_23
	goto_if_eq VAR_RESULT, 24, QR_RL_24
	goto_if_eq VAR_RESULT, 25, QR_RL_25
	goto_if_eq VAR_RESULT, 26, QR_RL_26
	goto_if_eq VAR_RESULT, 27, QR_RL_27
	goto_if_eq VAR_RESULT, 28, QR_RL_28
	goto_if_eq VAR_RESULT, 29, QR_RL_29
	goto_if_eq VAR_RESULT, 30, QR_RL_30
	goto_if_eq VAR_RESULT, 31, QR_RL_31
	goto_if_eq VAR_RESULT, 32, QR_RL_32
	goto_if_eq VAR_RESULT, 33, QR_RL_33
	goto_if_eq VAR_RESULT, 34, QR_RL_34
	return

QR_GiveShinyFull::
	random 14
	goto_if_eq VAR_RESULT, 0, QR_SF_0
	goto_if_eq VAR_RESULT, 1, QR_SF_1
	goto_if_eq VAR_RESULT, 2, QR_SF_2
	goto_if_eq VAR_RESULT, 3, QR_SF_3
	goto_if_eq VAR_RESULT, 4, QR_SF_4
	goto_if_eq VAR_RESULT, 5, QR_SF_5
	goto_if_eq VAR_RESULT, 6, QR_SF_6
	goto_if_eq VAR_RESULT, 7, QR_SF_7
	goto_if_eq VAR_RESULT, 8, QR_SF_8
	goto_if_eq VAR_RESULT, 9, QR_SF_9
	goto_if_eq VAR_RESULT, 10, QR_SF_10
	goto_if_eq VAR_RESULT, 11, QR_SF_11
	goto_if_eq VAR_RESULT, 12, QR_SF_12
	goto_if_eq VAR_RESULT, 13, QR_SF_13
	return

QR_SF_0::
	givemon SPECIES_DRAGONITE, 70, shinyMode=SHINY_MODE_ALWAYS, hpEv=252, atkEv=252, defEv=252, speedEv=252, spAtkEv=252, spDefEv=252, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31
	return

QR_SF_1::
	givemon SPECIES_TYRANITAR, 70, shinyMode=SHINY_MODE_ALWAYS, hpEv=252, atkEv=252, defEv=252, speedEv=252, spAtkEv=252, spDefEv=252, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31
	return

QR_SF_2::
	givemon SPECIES_SALAMENCE, 70, shinyMode=SHINY_MODE_ALWAYS, hpEv=252, atkEv=252, defEv=252, speedEv=252, spAtkEv=252, spDefEv=252, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31
	return

QR_SF_3::
	givemon SPECIES_METAGROSS, 70, shinyMode=SHINY_MODE_ALWAYS, hpEv=252, atkEv=252, defEv=252, speedEv=252, spAtkEv=252, spDefEv=252, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31
	return

QR_SF_4::
	givemon SPECIES_GARCHOMP, 70, shinyMode=SHINY_MODE_ALWAYS, hpEv=252, atkEv=252, defEv=252, speedEv=252, spAtkEv=252, spDefEv=252, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31
	return

QR_SF_5::
	givemon SPECIES_GENGAR, 70, shinyMode=SHINY_MODE_ALWAYS, hpEv=252, atkEv=252, defEv=252, speedEv=252, spAtkEv=252, spDefEv=252, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31
	return

QR_SF_6::
	givemon SPECIES_HYDREIGON, 70, shinyMode=SHINY_MODE_ALWAYS, hpEv=252, atkEv=252, defEv=252, speedEv=252, spAtkEv=252, spDefEv=252, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31
	return

QR_SF_7::
	givemon SPECIES_GOODRA, 70, shinyMode=SHINY_MODE_ALWAYS, hpEv=252, atkEv=252, defEv=252, speedEv=252, spAtkEv=252, spDefEv=252, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31
	return

QR_SF_8::
	givemon SPECIES_KOMMO_O, 70, shinyMode=SHINY_MODE_ALWAYS, hpEv=252, atkEv=252, defEv=252, speedEv=252, spAtkEv=252, spDefEv=252, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31
	return

QR_SF_9::
	givemon SPECIES_DRAGAPULT, 70, shinyMode=SHINY_MODE_ALWAYS, hpEv=252, atkEv=252, defEv=252, speedEv=252, spAtkEv=252, spDefEv=252, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31
	return

QR_SF_10::
	givemon SPECIES_BAXCALIBUR, 70, shinyMode=SHINY_MODE_ALWAYS, hpEv=252, atkEv=252, defEv=252, speedEv=252, spAtkEv=252, spDefEv=252, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31
	return

QR_SF_11::
	givemon SPECIES_HAXORUS, 70, shinyMode=SHINY_MODE_ALWAYS, hpEv=252, atkEv=252, defEv=252, speedEv=252, spAtkEv=252, spDefEv=252, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31
	return

QR_SF_12::
	givemon SPECIES_SCIZOR, 70, shinyMode=SHINY_MODE_ALWAYS, hpEv=252, atkEv=252, defEv=252, speedEv=252, spAtkEv=252, spDefEv=252, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31
	return

QR_SF_13::
	givemon SPECIES_LUCARIO, 70, shinyMode=SHINY_MODE_ALWAYS, hpEv=252, atkEv=252, defEv=252, speedEv=252, spAtkEv=252, spDefEv=252, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31
	return

EventScript_QuestLog::
	lockall
	call QuestLog_Menu
	releaseall
	end

QuestLog_Menu::
	msgbox QL_Text_Header, MSGBOX_DEFAULT
	dynmultichoice 1, 1, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, QL_Name_1, QL_Name_2, QL_Name_3, QL_Name_4, QL_Name_5, QL_Name_Exit
	goto_if_eq VAR_RESULT, 0, QuestLog_Q1
	goto_if_eq VAR_RESULT, 1, QuestLog_Q2
	goto_if_eq VAR_RESULT, 2, QuestLog_Q3
	goto_if_eq VAR_RESULT, 3, QuestLog_Q4
	goto_if_eq VAR_RESULT, 4, QuestLog_Q5
	return

QuestLog_Claimed::
	msgbox QL_Text_AlreadyClaimed, MSGBOX_DEFAULT
	goto QuestLog_Menu

QuestLog_Reward_Done::
	msgbox QL_Text_Claimed, MSGBOX_DEFAULT
	goto QuestLog_Menu

QuestLog_Q1::
	goto_if_ne VAR_UNUSED_0x409B, 0, QuestLog_Claimed
	special CountCaughtForQuest
	copyvar VAR_0x8008, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008
	msgbox QL_Text_Q1, MSGBOX_DEFAULT
	goto_if_ge VAR_0x8008, 50, QuestLog_Q1_Claim
	goto QuestLog_Menu

QuestLog_Q1_Claim::
	msgbox QL_Text_ClaimAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, QuestLog_Menu
	setvar VAR_UNUSED_0x409B, 1
	setvar VAR_0x8009, 0
	call QR_GiveRandomLegend
	addmoney 500000
	goto QuestLog_Reward_Done

QuestLog_Q2::
	goto_if_ne VAR_UNUSED_0x409D, 0, QuestLog_Claimed
	copyvar VAR_0x8008, VAR_UNUSED_0x408B
	buffernumberstring STR_VAR_1, VAR_0x8008
	msgbox QL_Text_Q2, MSGBOX_DEFAULT
	goto_if_ge VAR_0x8008, 10, QuestLog_Q2_Claim
	goto QuestLog_Menu

QuestLog_Q2_Claim::
	msgbox QL_Text_ClaimAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, QuestLog_Menu
	setvar VAR_UNUSED_0x409D, 1
	call QR_GiveShinyFull
	addmoney 999999
	goto QuestLog_Reward_Done

QuestLog_Q3::
	goto_if_ne VAR_UNUSED_0x40A1, 0, QuestLog_Claimed
	copyvar VAR_0x8008, VAR_UNUSED_0x4091
	buffernumberstring STR_VAR_1, VAR_0x8008
	msgbox QL_Text_Q3, MSGBOX_DEFAULT
	goto_if_ge VAR_0x8008, 1, QuestLog_Q3_Claim
	goto QuestLog_Menu

QuestLog_Q3_Claim::
	msgbox QL_Text_ClaimAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, QuestLog_Menu
	setvar VAR_UNUSED_0x40A1, 1
	setvar VAR_0x8009, 1
	call QR_GiveRandomLegend
	goto QuestLog_Reward_Done

QuestLog_Q4::
	goto_if_ne VAR_UNUSED_0x40A8, 0, QuestLog_Claimed
	copyvar VAR_0x8008, VAR_UNUSED_0x4091
	buffernumberstring STR_VAR_1, VAR_0x8008
	msgbox QL_Text_Q4, MSGBOX_DEFAULT
	goto_if_ge VAR_0x8008, 5, QuestLog_Q4_Claim
	goto QuestLog_Menu

QuestLog_Q4_Claim::
	msgbox QL_Text_ClaimAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, QuestLog_Menu
	setvar VAR_UNUSED_0x40A8, 1
	setvar VAR_0x8009, 1
	call QR_ChooseLegend
	goto QuestLog_Reward_Done

QuestLog_Q5::
	goto_if_ne VAR_UNUSED_0x40BB, 0, QuestLog_Claimed
	special CountCaughtForQuest
	copyvar VAR_0x8008, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008
	msgbox QL_Text_Q5, MSGBOX_DEFAULT
	goto_if_ge VAR_0x8008, 10, QuestLog_Q5_Claim
	goto QuestLog_Menu

QuestLog_Q5_Claim::
	msgbox QL_Text_ClaimAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, QuestLog_Menu
	setvar VAR_UNUSED_0x40BB, 1
	setvar VAR_0x8009, 0
	call QR_ChooseLegend
	addmoney 500000
	goto QuestLog_Reward_Done

PkmnCenterNurse_Text_ServiceAsk:
	.string "O que voce deseja?$"
Svc_Text_Candy:
	.string "100 Rare Candy$"
Svc_Text_Shop:
	.string "Loja$"
Svc_Text_Tower:
	.string "Torre de Batalha$"
Svc_Text_Raid:
	.string "Raid$"
Svc_Text_Quests:
	.string "Missoes$"
Svc_Text_Difficulty:
	.string "Dificuldade$"
Svc_Text_Teleport:
	.string "Teleporte$"
Svc_Text_Exit:
	.string "Sair$"
Svc_Text_CandyDone:
	.string "100 Rare Candies foram\ncolocadas na sua bolsa!$"
Difficulty_Text_Ask:
	.string "Escolha a dificuldade.$"
Difficulty_Text_Done:
	.string "Dificuldade definida!$"
Diff_Text_1:
	.string "Nunca Joguei$"
Diff_Text_2:
	.string "Facil$"
Diff_Text_3:
	.string "Normal$"
Diff_Text_4:
	.string "Dificil$"
Tower_Text_Intro:
	.string "Torre de Batalha!\nEnfrentar um treinador?$"
Tower_Text_Defeat:
	.string "Voce venceu esta luta!$"
Tower_Text_Won:
	.string "Vitoria! Total na torre:\n{STR_VAR_1}.$"
Raid_Text_Intro:
	.string "Um chefe de raid apareceu!\nAceita o desafio?$"
Raid_Text_Failed:
	.string "O chefe da raid venceu...\nTente de novo!$"
Raid_Text_Done:
	.string "Raid concluida! Total de\nraids: {STR_VAR_1}.$"
QR_Text_Choose:
	.string "Escolha o seu lendario.$"
QL_Text_Header:
	.string "MISSOES\nEscolha uma missao.$"
QL_Name_1:
	.string "Capture 50 Pokemon$"
QL_Name_2:
	.string "Torre: 10 vitorias$"
QL_Name_3:
	.string "Conclua 1 raid$"
QL_Name_4:
	.string "Conclua 5 raids$"
QL_Name_5:
	.string "Capture 10 Pokemon$"
QL_Name_Exit:
	.string "Fechar$"
QL_Text_AlreadyClaimed:
	.string "Voce ja resgatou esta\nrecompensa.$"
QL_Text_Claimed:
	.string "Recompensa resgatada!$"
QL_Text_ClaimAsk:
	.string "Missao concluida!\nResgatar a recompensa?$"
QL_Text_Q1:
	.string "Capture 50 Pokemon diferentes.\nProgresso: {STR_VAR_1}/50\pRecompensa: 1 lendario\naleatorio + 500.000 yens.$"
QL_Text_Q2:
	.string "Venca 10 lutas na torre.\nProgresso: {STR_VAR_1}/10\pRecompensa: 1 Shiny full\n+ 1 milhao de yens.$"
QL_Text_Q3:
	.string "Conclua 1 raid.\nProgresso: {STR_VAR_1}/1\pRecompensa: 1 lendario\nshiny aleatorio.$"
QL_Text_Q4:
	.string "Conclua 5 raids.\nProgresso: {STR_VAR_1}/5\pRecompensa: 1 lendario\nshiny a sua escolha.$"
QL_Text_Q5:
	.string "Capture 10 Pokemon diferentes.\nProgresso: {STR_VAR_1}/10\pRecompensa: lendario a\nsua escolha + 500.000 yens.$"
QR_Name_0:
	.string "Articuno$"
QR_Name_1:
	.string "Zapdos$"
QR_Name_2:
	.string "Moltres$"
QR_Name_3:
	.string "Mewtwo$"
QR_Name_4:
	.string "Mew$"
QR_Name_5:
	.string "Raikou$"
QR_Name_6:
	.string "Entei$"
QR_Name_7:
	.string "Suicune$"
QR_Name_8:
	.string "Lugia$"
QR_Name_9:
	.string "Ho-oh$"
QR_Name_10:
	.string "Celebi$"
QR_Name_11:
	.string "Regirock$"
QR_Name_12:
	.string "Regice$"
QR_Name_13:
	.string "Registeel$"
QR_Name_14:
	.string "Latias$"
QR_Name_15:
	.string "Latios$"
QR_Name_16:
	.string "Kyogre$"
QR_Name_17:
	.string "Groudon$"
QR_Name_18:
	.string "Rayquaza$"
QR_Name_19:
	.string "Jirachi$"
QR_Name_20:
	.string "Dialga$"
QR_Name_21:
	.string "Palkia$"
QR_Name_22:
	.string "Giratina$"
QR_Name_23:
	.string "Arceus$"
QR_Name_24:
	.string "Regigigas$"
QR_Name_25:
	.string "Zekrom$"
QR_Name_26:
	.string "Reshiram$"
QR_Name_27:
	.string "Xerneas$"
QR_Name_28:
	.string "Yveltal$"
QR_Name_29:
	.string "Solgaleo$"
QR_Name_30:
	.string "Lunala$"
QR_Name_31:
	.string "Zacian$"
QR_Name_32:
	.string "Zamazenta$"
QR_Name_33:
	.string "Koraidon$"
QR_Name_34:
	.string "Miraidon$"

EventScript_Teleport::
	lockall
	call Teleport_Menu
	releaseall
	end

Teleport_Menu::
	msgbox Teleport_Text_Ask, MSGBOX_DEFAULT
	dynmultichoice 1, 1, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, TP_Name_0, TP_Name_1, TP_Name_2, TP_Name_3, TP_Name_4, TP_Name_5, TP_Name_6, TP_Name_7, TP_Name_8, TP_Name_9, TP_Name_10, TP_Name_11, TP_Name_12, TP_Name_13, TP_Name_14, TP_Name_Exit
	goto_if_eq VAR_RESULT, 0, Teleport_Go_0
	goto_if_eq VAR_RESULT, 1, Teleport_Go_1
	goto_if_eq VAR_RESULT, 2, Teleport_Go_2
	goto_if_eq VAR_RESULT, 3, Teleport_Go_3
	goto_if_eq VAR_RESULT, 4, Teleport_Go_4
	goto_if_eq VAR_RESULT, 5, Teleport_Go_5
	goto_if_eq VAR_RESULT, 6, Teleport_Go_6
	goto_if_eq VAR_RESULT, 7, Teleport_Go_7
	goto_if_eq VAR_RESULT, 8, Teleport_Go_8
	goto_if_eq VAR_RESULT, 9, Teleport_Go_9
	goto_if_eq VAR_RESULT, 10, Teleport_Go_10
	goto_if_eq VAR_RESULT, 11, Teleport_Go_11
	goto_if_eq VAR_RESULT, 12, Teleport_Go_12
	goto_if_eq VAR_RESULT, 13, Teleport_Go_13
	goto_if_eq VAR_RESULT, 14, Teleport_Go_14
	return

Teleport_Go_0::
	warp MAP_DEWFORD_TOWN_POKEMON_CENTER_1F, 0
	waitstate
	end

Teleport_Go_1::
	warp MAP_EVER_GRANDE_CITY_POKEMON_CENTER_1F, 0
	waitstate
	end

Teleport_Go_2::
	warp MAP_FALLARBOR_TOWN_POKEMON_CENTER_1F, 0
	waitstate
	end

Teleport_Go_3::
	warp MAP_FORTREE_CITY_POKEMON_CENTER_1F, 0
	waitstate
	end

Teleport_Go_4::
	warp MAP_LAVARIDGE_TOWN_POKEMON_CENTER_1F, 0
	waitstate
	end

Teleport_Go_5::
	warp MAP_LILYCOVE_CITY_POKEMON_CENTER_1F, 0
	waitstate
	end

Teleport_Go_6::
	warp MAP_MAUVILLE_CITY_POKEMON_CENTER_1F, 0
	waitstate
	end

Teleport_Go_7::
	warp MAP_MOSSDEEP_CITY_POKEMON_CENTER_1F, 0
	waitstate
	end

Teleport_Go_8::
	warp MAP_OLDALE_TOWN_POKEMON_CENTER_1F, 0
	waitstate
	end

Teleport_Go_9::
	warp MAP_PACIFIDLOG_TOWN_POKEMON_CENTER_1F, 0
	waitstate
	end

Teleport_Go_10::
	warp MAP_PETALBURG_CITY_POKEMON_CENTER_1F, 0
	waitstate
	end

Teleport_Go_11::
	warp MAP_RUSTBORO_CITY_POKEMON_CENTER_1F, 0
	waitstate
	end

Teleport_Go_12::
	warp MAP_SLATEPORT_CITY_POKEMON_CENTER_1F, 0
	waitstate
	end

Teleport_Go_13::
	warp MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_1F, 0
	waitstate
	end

Teleport_Go_14::
	warp MAP_VERDANTURF_TOWN_POKEMON_CENTER_1F, 0
	waitstate
	end

Teleport_Text_Ask:
	.string "Para onde quer ir?$"
TP_Name_Exit:
	.string "Fechar$"
TP_Name_0:
	.string "Dewford Town$"
TP_Name_1:
	.string "Ever Grande City$"
TP_Name_2:
	.string "Fallarbor Town$"
TP_Name_3:
	.string "Fortree City$"
TP_Name_4:
	.string "Lavaridge Town$"
TP_Name_5:
	.string "Lilycove City$"
TP_Name_6:
	.string "Mauville City$"
TP_Name_7:
	.string "Mossdeep City$"
TP_Name_8:
	.string "Oldale Town$"
TP_Name_9:
	.string "Pacifidlog Town$"
TP_Name_10:
	.string "Petalburg City$"
TP_Name_11:
	.string "Rustboro City$"
TP_Name_12:
	.string "Slateport City$"
TP_Name_13:
	.string "Sootopolis City$"
TP_Name_14:
	.string "Verdanturf Town$"

Raid_Text_Tier:
	.string "Escolha a dificuldade\nda raid.$"
Raid_Tier_1:
	.string "Facil - Nv 50$"
Raid_Tier_2:
	.string "Media - Nv 70$"
Raid_Tier_3:
	.string "Dificil - Nv 90$"
Raid_Tier_4:
	.string "Lendaria - Nv 100$"
Raid_Tier_Exit:
	.string "Voltar$"
