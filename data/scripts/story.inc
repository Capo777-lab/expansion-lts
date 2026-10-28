
Story_Main::
	goto_if_eq VAR_UNUSED_0x40DC, 0, Story_NotStarted
	goto_if_eq VAR_UNUSED_0x40DC, 1, Story_Rival
	goto_if_eq VAR_UNUSED_0x40DC, 2, Story_Alfas
	goto_if_eq VAR_UNUSED_0x40DC, 3, Story_Deliver
	goto_if_eq VAR_UNUSED_0x40DC, 4, Story_GoMom
	goto_if_eq VAR_UNUSED_0x40DC, 5, Story_Continent
	msgbox Story_Text_Finished, MSGBOX_DEFAULT
	return

Story_NotStarted::
	setvar VAR_UNUSED_0x40DC, 1
	goto Story_Rival

Story_Rival::
	msgbox Story_Text_RivalIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Story_Return
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, Story_Text_RivalDefeat
	setvar VAR_UNUSED_0x40DC, 2
	msgbox Story_Text_RivalAfter, MSGBOX_DEFAULT
	return

Story_Return::
	return

Story_Alfas::
	msgbox Story_Text_AlfaMenu, MSGBOX_DEFAULT
	dynmultichoice 1, 1, FALSE, 5, 0, DYN_MULTICHOICE_CB_NONE, Story_Name_Alfa1, Story_Name_Alfa2, Story_Name_Alfa3, Story_Name_Alfa4, Story_Name_Back
	goto_if_eq VAR_RESULT, 0, Story_Alfa_1
	goto_if_eq VAR_RESULT, 1, Story_Alfa_2
	goto_if_eq VAR_RESULT, 2, Story_Alfa_3
	goto_if_eq VAR_RESULT, 3, Story_Alfa_4
	return

Story_Alfa_1::
	goto_if_set FLAG_UNUSED_0x021, Story_AlfaDone
	msgbox Story_Text_AlfaIntro1, MSGBOX_DEFAULT
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_ARCANINE, 30
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Story_Alfa_1_Win
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Story_Alfa_1_Win
	msgbox Story_Text_AlfaLost, MSGBOX_DEFAULT
	goto Story_Alfas

Story_Alfa_1_Win::
	setflag FLAG_UNUSED_0x021
	additem ITEM_FIRE_STONE
	msgbox Story_Text_AlfaWin1, MSGBOX_DEFAULT
	goto Story_AlfaCheck

Story_Alfa_2::
	goto_if_set FLAG_UNUSED_0x022, Story_AlfaDone
	msgbox Story_Text_AlfaIntro2, MSGBOX_DEFAULT
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_GYARADOS, 30
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Story_Alfa_2_Win
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Story_Alfa_2_Win
	msgbox Story_Text_AlfaLost, MSGBOX_DEFAULT
	goto Story_Alfas

Story_Alfa_2_Win::
	setflag FLAG_UNUSED_0x022
	additem ITEM_WATER_STONE
	msgbox Story_Text_AlfaWin2, MSGBOX_DEFAULT
	goto Story_AlfaCheck

Story_Alfa_3::
	goto_if_set FLAG_UNUSED_0x023, Story_AlfaDone
	msgbox Story_Text_AlfaIntro3, MSGBOX_DEFAULT
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_ELECTIVIRE, 32
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Story_Alfa_3_Win
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Story_Alfa_3_Win
	msgbox Story_Text_AlfaLost, MSGBOX_DEFAULT
	goto Story_Alfas

Story_Alfa_3_Win::
	setflag FLAG_UNUSED_0x023
	additem ITEM_THUNDER_STONE
	msgbox Story_Text_AlfaWin3, MSGBOX_DEFAULT
	goto Story_AlfaCheck

Story_Alfa_4::
	goto_if_set FLAG_UNUSED_0x024, Story_AlfaDone
	msgbox Story_Text_AlfaIntro4, MSGBOX_DEFAULT
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_VENUSAUR, 32
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Story_Alfa_4_Win
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Story_Alfa_4_Win
	msgbox Story_Text_AlfaLost, MSGBOX_DEFAULT
	goto Story_Alfas

Story_Alfa_4_Win::
	setflag FLAG_UNUSED_0x024
	additem ITEM_LEAF_STONE
	msgbox Story_Text_AlfaWin4, MSGBOX_DEFAULT
	goto Story_AlfaCheck

Story_AlfaDone::
	msgbox Story_Text_AlfaDone, MSGBOX_DEFAULT
	goto Story_Alfas

Story_AlfaCheck::
	goto_if_unset FLAG_UNUSED_0x021, Story_Alfas
	goto_if_unset FLAG_UNUSED_0x022, Story_Alfas
	goto_if_unset FLAG_UNUSED_0x023, Story_Alfas
	goto_if_unset FLAG_UNUSED_0x024, Story_Alfas
	setvar VAR_UNUSED_0x40DC, 3
	msgbox Story_Text_AllAlfas, MSGBOX_DEFAULT
	return

Story_Deliver::
	checkitem ITEM_FIRE_STONE
	goto_if_eq VAR_RESULT, FALSE, Story_MissingStones
	checkitem ITEM_WATER_STONE
	goto_if_eq VAR_RESULT, FALSE, Story_MissingStones
	checkitem ITEM_THUNDER_STONE
	goto_if_eq VAR_RESULT, FALSE, Story_MissingStones
	checkitem ITEM_LEAF_STONE
	goto_if_eq VAR_RESULT, FALSE, Story_MissingStones
	removeitem ITEM_FIRE_STONE
	removeitem ITEM_WATER_STONE
	removeitem ITEM_THUNDER_STONE
	removeitem ITEM_LEAF_STONE
	addmoney 50000
	setvar VAR_UNUSED_0x40DC, 4
	msgbox Story_Text_Delivered, MSGBOX_DEFAULT
	return

Story_MissingStones::
	msgbox Story_Text_MissingStones, MSGBOX_DEFAULT
	return

Story_GoMom::
	msgbox Story_Text_GoMom, MSGBOX_DEFAULT
	return

Story_Continent::
	msgbox Story_Text_Continent, MSGBOX_DEFAULT
	return

Story_Prologue::
	msgbox Story_Text_Prologue, MSGBOX_DEFAULT
	return

MomTravel_Interact::
	lock
	faceplayer
	goto_if_ge VAR_UNUSED_0x40DC, 4, MomTravel_Offer
	msgbox MomTravel_Text_Normal, MSGBOX_DEFAULT
	release
	end

MomTravel_Offer::
	msgbox MomTravel_Text_Offer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MomTravel_No
	goto_if_eq VAR_UNUSED_0x40DC, 4, MomTravel_First
	goto MomTravel_Go

MomTravel_First::
	setvar VAR_UNUSED_0x40DC, 5
	msgbox MomTravel_Text_First, MSGBOX_DEFAULT
	goto MomTravel_Go

MomTravel_Go::
	msgbox MomTravel_Text_Go, MSGBOX_DEFAULT
	warp MAP_TRETA_CONTINENTE, 31, 43
	waitstate
	end

MomTravel_No::
	msgbox MomTravel_Text_No, MSGBOX_DEFAULT
	release
	end

TC_Boatman::
	lock
	faceplayer
	msgbox TC_Text_BoatmanAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TC_BoatmanNo
	warp MAP_LITTLEROOT_TOWN, 5, 9
	waitstate
	end

TC_BoatmanNo::
	msgbox TC_Text_BoatmanNo, MSGBOX_DEFAULT
	release
	end

TC_AddOne::
	addvar VAR_0x8008, 1
	return

TC_AddOneB::
	addvar VAR_0x8009, 1
	return

TC_Count::
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	call_if_set FLAG_UNUSED_0x025, TC_AddOne
	call_if_set FLAG_UNUSED_0x026, TC_AddOne
	call_if_set FLAG_UNUSED_0x027, TC_AddOne
	call_if_set FLAG_UNUSED_0x028, TC_AddOneB
	call_if_set FLAG_UNUSED_0x029, TC_AddOneB
	call_if_set FLAG_UNUSED_0x02A, TC_AddOneB
	buffernumberstring STR_VAR_1, VAR_0x8008
	buffernumberstring STR_VAR_2, VAR_0x8009
	return

TC_Guide::
	lock
	faceplayer
	goto_if_ge VAR_UNUSED_0x40DC, 6, TC_GuideDone
	call TC_Count
	msgbox TC_Text_Guide, MSGBOX_DEFAULT
	release
	end

TC_GuideDone::
	msgbox TC_Text_GuideDone, MSGBOX_DEFAULT
	release
	end

TC_Relic_1::
	lock
	goto_if_set FLAG_UNUSED_0x025, TC_RelicEmpty
	msgbox TC_Text_RelicFound, MSGBOX_DEFAULT
	giveitem ITEM_RED_SHARD
	setflag FLAG_UNUSED_0x025
	release
	end

TC_Relic_2::
	lock
	goto_if_set FLAG_UNUSED_0x026, TC_RelicEmpty
	msgbox TC_Text_RelicFound, MSGBOX_DEFAULT
	giveitem ITEM_BLUE_SHARD
	setflag FLAG_UNUSED_0x026
	release
	end

TC_Relic_3::
	lock
	goto_if_set FLAG_UNUSED_0x027, TC_RelicEmpty
	msgbox TC_Text_RelicFound, MSGBOX_DEFAULT
	giveitem ITEM_YELLOW_SHARD
	setflag FLAG_UNUSED_0x027
	release
	end

TC_RelicEmpty::
	msgbox TC_Text_RelicEmpty, MSGBOX_DEFAULT
	release
	end

TC_Duel_1::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x028, TC_DuelDone
	msgbox TC_Text_DuelIntro1, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PHOEBE, TC_Text_DuelDefeat1
	setflag FLAG_UNUSED_0x028
	msgbox TC_Text_DuelAfter1, MSGBOX_DEFAULT
	release
	end

TC_Duel_2::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x029, TC_DuelDone
	msgbox TC_Text_DuelIntro2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GLACIA, TC_Text_DuelDefeat2
	setflag FLAG_UNUSED_0x029
	msgbox TC_Text_DuelAfter2, MSGBOX_DEFAULT
	release
	end

TC_Duel_3::
	lock
	faceplayer
	goto_if_set FLAG_UNUSED_0x02A, TC_DuelDone
	msgbox TC_Text_DuelIntro3, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DRAKE, TC_Text_DuelDefeat3
	setflag FLAG_UNUSED_0x02A
	msgbox TC_Text_DuelAfter3, MSGBOX_DEFAULT
	release
	end

TC_DuelDone::
	msgbox TC_Text_DuelDone, MSGBOX_DEFAULT
	release
	end

TC_Altar::
	lock
	goto_if_ge VAR_UNUSED_0x40DC, 6, TC_AltarFinished
	call TC_Count
	goto_if_ne VAR_0x8008, 3, TC_AltarSealed
	goto_if_ne VAR_0x8009, 3, TC_AltarSealed
	msgbox TC_Text_AltarOpen, MSGBOX_DEFAULT
	setvar VAR_UNUSED_0x40B8, 1
	setwildbattle SPECIES_RAYQUAZA, 80
	dowildbattle
	setvar VAR_UNUSED_0x40B8, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TC_AltarWin
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TC_AltarWin
	msgbox TC_Text_AltarLost, MSGBOX_DEFAULT
	release
	end

TC_AltarWin::
	setvar VAR_UNUSED_0x40DC, 6
	addmoney 999999
	msgbox TC_Text_AltarWin, MSGBOX_DEFAULT
	setvar VAR_0x8009, 1
	call QR_ChooseLegend
	msgbox TC_Text_AltarEnd, MSGBOX_DEFAULT
	release
	end

TC_AltarSealed::
	msgbox TC_Text_AltarSealed, MSGBOX_DEFAULT
	release
	end

TC_AltarFinished::
	msgbox TC_Text_AltarFinished, MSGBOX_DEFAULT
	release
	end

QuestLog_Story::
	goto_if_le VAR_UNUSED_0x40DC, 1, QuestLog_Story_1
	goto_if_eq VAR_UNUSED_0x40DC, 2, QuestLog_Story_2
	goto_if_eq VAR_UNUSED_0x40DC, 3, QuestLog_Story_3
	goto_if_eq VAR_UNUSED_0x40DC, 4, QuestLog_Story_4
	goto_if_eq VAR_UNUSED_0x40DC, 5, QuestLog_Story_5
	msgbox QL_Story_6, MSGBOX_DEFAULT
	goto QuestLog_Menu

QuestLog_Story_1::
	msgbox QL_Story_1, MSGBOX_DEFAULT
	goto QuestLog_Menu

QuestLog_Story_2::
	msgbox QL_Story_2, MSGBOX_DEFAULT
	goto QuestLog_Menu

QuestLog_Story_3::
	msgbox QL_Story_3, MSGBOX_DEFAULT
	goto QuestLog_Menu

QuestLog_Story_4::
	msgbox QL_Story_4, MSGBOX_DEFAULT
	goto QuestLog_Menu

QuestLog_Story_5::
	msgbox QL_Story_5, MSGBOX_DEFAULT
	goto QuestLog_Menu

Story_Text_Prologue:
	.string "Enfermeira: Que bom que voce\nacordou, jovem treinador!\pUma grande tempestade mudou\ntudo. Os ginasios sumiram.\pSurgiu uma forca chamada Eco.\nEla desperta os lendarios.\pAssim comecou a Treta Geral,\num mundo livre de batalhas!\pFale comigo e escolha\nHISTORIA para seguir a lenda.$"
Story_Text_RivalIntro:
	.string "Enfermeira: Um rival quer\ntestar sua forca agora!\pEsta pronto para o duelo?$"
Story_Text_RivalDefeat:
	.string "Nossa, voce e forte!$"
Story_Text_RivalAfter:
	.string "Rival: Ganhou desta vez...\nOs Alfas, Pokemon gigantes,\nguardam as Pedras do Eco.\pDerrote os 4 Alfas pelo\nmenu HISTORIA!$"
Story_Text_AlfaMenu:
	.string "Qual Alfa voce vai\ndesafiar?$"
Story_Text_AlfaIntro1:
	.string "Um Alfa de Fogo ruge\nem sua direcao!$"
Story_Text_AlfaIntro2:
	.string "Um Alfa de Agua surge\ndas ondas furiosas!$"
Story_Text_AlfaIntro3:
	.string "Um Alfa de Raio desce\ncom relampagos!$"
Story_Text_AlfaIntro4:
	.string "Um Alfa de Folha emerge\nda mata fechada!$"
Story_Text_AlfaWin1:
	.string "Voce obteve a Pedra do Eco\nde Fogo!$"
Story_Text_AlfaWin2:
	.string "Voce obteve a Pedra do Eco\nde Agua!$"
Story_Text_AlfaWin3:
	.string "Voce obteve a Pedra do Eco\nde Raio!$"
Story_Text_AlfaWin4:
	.string "Voce obteve a Pedra do Eco\nde Folha!$"
Story_Text_AlfaLost:
	.string "O Alfa venceu...\nTreine e volte mais forte!$"
Story_Text_AlfaDone:
	.string "Voce ja derrotou este Alfa.$"
Story_Text_AllAlfas:
	.string "Enfermeira: Voce reuniu as 4\nPedras! Escolha HISTORIA de\nnovo para entrega-las.$"
Story_Text_Delivered:
	.string "Enfermeira: As Pedras do Eco\nabriram um caminho no mar!\pVa a Littleroot e fale com\nsua mae, a casa do inicio.\pEla conhece o barqueiro\nque leva ao novo continente.$"
Story_Text_MissingStones:
	.string "Voce precisa das 4 Pedras do\nEco na bolsa para entrega-las.$"
Story_Text_GoMom:
	.string "Fale com sua mae na casa\nde Littleroot. Ela tem um\nbarqueiro de confianca.$"
Story_Text_Continent:
	.string "No Continente Eco, ache 3\nFragmentos, venca 3 duelistas\ne abra o Altar do Eco.$"
Story_Text_Finished:
	.string "A lenda do Eco foi\ncompleta! Parabens, campeao!$"
MomTravel_Text_Normal:
	.string "Mae: Filho, cuide-se bem.\pQuando suas missoes ficarem\nmais avancadas, tenho uma\nsurpresa para voce.$"
MomTravel_Text_Offer:
	.string "Mae: As Pedras do Eco abriram\num novo continente!\pQuer que o barqueiro leve\nvoce agora?$"
MomTravel_Text_First:
	.string "Mae: Fique atento, la existem\nfragmentos antigos e duelistas\nmuito fortes.$"
MomTravel_Text_Go:
	.string "Mae: Boa viagem, e volte\ninteiro!$"
MomTravel_Text_No:
	.string "Mae: Sem pressa. Estarei\naqui quando quiser ir.$"
TC_Text_BoatmanAsk:
	.string "Barqueiro: Quer voltar para\nLittleroot?$"
TC_Text_BoatmanNo:
	.string "Barqueiro: Estarei aqui.$"
TC_Text_Guide:
	.string "Guia: Bem-vindo ao Continente\nEco! Prove seu valor.\pFragmentos: {STR_VAR_1}/3\nDuelistas vencidos: {STR_VAR_2}/3\pAo completar as provas, o\nAltar ao norte se abre.$"
TC_Text_GuideDone:
	.string "Guia: Voce libertou o Eco e\nvenceu a Treta Geral!$"
TC_Text_RelicFound:
	.string "Um brilho antigo vem do chao...$"
TC_Text_RelicEmpty:
	.string "Aqui ja nao ha mais nada.$"
TC_Text_DuelIntro1:
	.string "Duelista Fenix: So passa\nquem vencer meu fogo gelado!$"
TC_Text_DuelIntro2:
	.string "Duelista Gelo: O frio testa\nquem tem coragem de verdade.$"
TC_Text_DuelIntro3:
	.string "Duelista Draco: Sua jornada\nacaba nas minhas asas!$"
TC_Text_DuelDefeat1:
	.string "Seu espirito arde mais forte!$"
TC_Text_DuelDefeat2:
	.string "Voce quebrou meu gelo...$"
TC_Text_DuelDefeat3:
	.string "Seus dragoes me superaram!$"
TC_Text_DuelAfter1:
	.string "Siga em frente, o Altar\naguarda quem prova o valor.$"
TC_Text_DuelAfter2:
	.string "Va! O Eco escolheu voce.$"
TC_Text_DuelAfter3:
	.string "Voce merece o Altar do Eco.$"
TC_Text_DuelDone:
	.string "Voce ja venceu este duelista.$"
TC_Text_AltarSealed:
	.string "O Altar esta selado. Reuna os\n3 Fragmentos e venca os 3\nduelistas para abri-lo.$"
TC_Text_AltarOpen:
	.string "O Altar do Eco se abre!\nUma sombra gigante desce\ndo ceu!$"
TC_Text_AltarLost:
	.string "O Eco venceu... Volte mais\nforte e tente de novo!$"
TC_Text_AltarWin:
	.string "O Eco foi libertado!\nO mundo de Treta Geral\nrespira em paz.\pVoce recebeu um premio!$"
TC_Text_AltarEnd:
	.string "A lenda ficara para sempre\nem sua memoria, campeao!$"
TC_Text_AltarFinished:
	.string "O Altar agora descansa em paz.$"
Story_Name_Alfa1:
	.string "Alfa de Fogo$"
Story_Name_Alfa2:
	.string "Alfa de Agua$"
Story_Name_Alfa3:
	.string "Alfa de Raio$"
Story_Name_Alfa4:
	.string "Alfa de Folha$"
Story_Name_Back:
	.string "Voltar$"
Svc_Text_Story:
	.string "Historia$"
QL_Name_Story:
	.string "Historia$"
QL_Story_1:
	.string "Objetivo: derrote o rival\nno Pokecentro. Use o menu\nHISTORIA da enfermeira.$"
QL_Story_2:
	.string "Objetivo: derrote os 4 Alfas\n(Fogo, Agua, Raio e Folha)\npelo menu HISTORIA.$"
QL_Story_3:
	.string "Objetivo: entregue as 4\nPedras do Eco a enfermeira\npelo menu HISTORIA.$"
QL_Story_4:
	.string "Objetivo: fale com sua mae\nna casa de Littleroot.$"
QL_Story_5:
	.string "Objetivo: no Continente Eco,\n3 Fragmentos, 3 duelistas\ne o Altar do Eco.$"
QL_Story_6:
	.string "Historia concluida!\nParabens, campeao!$"
