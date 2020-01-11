#ifndef __LLVM_BW_BUILTINS__H__
#define __LLVM_BW_BUILTINS__H__

using Comparison = int;
using Number = int;
using Player = int;
using ResourceType = int;
using UnitType = int;
using LocationId = int;
using ScoreType = int;
using SwitchNum = int;
using Text = int;
using Modifier = int;
using Time = int;
using WavFile = int;
using WavTime = int;
using UnitProperties = int;
using SwitchAction = int;
using AIScript = int;
using State = int;
using OrderType = int;
using ModAmount = int;
using AllyStatus = int;

#define NOT_IMPLEMENTED
#define PARTIALLY_IMPLEMENTED
#define FULLY_IMPLEMENTED

/**
  *************** CONDITIONS ********************
  Notes: NoCondition, Briefing, Always, Never intentionally omitted
*/

// Workaround: Deaths
NOT_IMPLEMENTED
bool CountdownTimer(Comparison, Number);

// Workaround: Deaths
NOT_IMPLEMENTED
bool Command(Player, Comparison, UnitType, Number);

// No workaround
NOT_IMPLEMENTED
bool Bring(Player, Comparison, UnitType, LocationId, Number);

// Workaround: Deaths
NOT_IMPLEMENTED
bool Accumulate(Player, Comparison, Number, ResourceType);

// Workaround: Deaths
NOT_IMPLEMENTED
bool Kill(Player, Comparison, UnitType, Number);

// No workaround
NOT_IMPLEMENTED
bool CommandTheMost(UnitType);

// No workaround
NOT_IMPLEMENTED
bool CommandsTheMostAt(UnitType, LocationId);

// No workaround
NOT_IMPLEMENTED
bool MostKills(UnitType);

// No workaround
NOT_IMPLEMENTED
bool HighestScore(ScoreType);

// No workaround
NOT_IMPLEMENTED
bool MostResources(ResourceType);

// Workaround: Deaths with bitmasking
NOT_IMPLEMENTED
bool Switch(SwitchNum);

// Workaround: Deaths
NOT_IMPLEMENTED
bool ElapsedTime(Comparison, Number);

// No workaround
NOT_IMPLEMENTED
bool Opponents(Player);

NOT_IMPLEMENTED
bool Deaths(Player, Comparison, UnitType, Number);

// No workaround
NOT_IMPLEMENTED
bool CommandTheLeast(UnitType);

// No workaround
NOT_IMPLEMENTED
bool CommandTheLeastAt(UnitType, LocationId);

// No workaround
NOT_IMPLEMENTED
bool LeastKills(UnitType);

// No workaround
NOT_IMPLEMENTED
bool LowestScore(ScoreType);

// No workaround
NOT_IMPLEMENTED
bool LeastResources(ResourceType);

// Workaround: deaths
NOT_IMPLEMENTED
bool Score(Player, Comparison, ScoreType, Number);

/**
  *************** ACTIONS ********************
  Notes: NoAction, PreserveTrigger, Wait, and Comment intentionally omitted
*/

NOT_IMPLEMENTED
void Victory();

NOT_IMPLEMENTED
void Defeat();

NOT_IMPLEMENTED
void PauseGame();

NOT_IMPLEMENTED
void UnpauseGame();

NOT_IMPLEMENTED
void Transmission(Text, UnitType, LocationId, Time, Modifier, WavFile, WavTime);

NOT_IMPLEMENTED
void PlayWav(WavFile, WavTime);

NOT_IMPLEMENTED
void DisplayTextMessage(Text);

NOT_IMPLEMENTED
void CenterView(LocationId);

NOT_IMPLEMENTED
void CreateUnitWithProperties(Player, UnitType, Number, LocationId, UnitProperties);

NOT_IMPLEMENTED
void SetMissionObjectives(Text);

NOT_IMPLEMENTED
void SetSwitch(SwitchNum, SwitchAction);

NOT_IMPLEMENTED
void SetCountdownTimer(Time, Modifier);

NOT_IMPLEMENTED
void RunAIScript(AIScript);

NOT_IMPLEMENTED
void RunAIScriptAtLocation(AIScript, LocationId);

NOT_IMPLEMENTED
void LeaderboardControl(Text, UnitType);

NOT_IMPLEMENTED
void LeaderboardControlAtLocation(Text, UnitType, LocationId);

NOT_IMPLEMENTED
void LeaderboardResources(Text, ResourceType);

NOT_IMPLEMENTED
void LeaderboardKills(Text, UnitType);

NOT_IMPLEMENTED
void LeaderboardPoints(Text, ScoreType);

NOT_IMPLEMENTED
void KillUnit(Player, UnitType);

NOT_IMPLEMENTED
void KillUnitAtLocation(Player, UnitType, Number, LocationId);

NOT_IMPLEMENTED
void RemoveUnit(Player, UnitType);

NOT_IMPLEMENTED
void RemoveUnitAtLocation(Player, UnitType, Number, LocationId);

NOT_IMPLEMENTED
void SetResources(Player, Number, Modifier, ResourceType);

NOT_IMPLEMENTED
void SetScore(Player, Number, Modifier, ResourceType);

NOT_IMPLEMENTED
void MinimapPing(LocationId);

NOT_IMPLEMENTED
void TalkingPortrait(UnitType, Time);

NOT_IMPLEMENTED
void MuteUnitSpeech();

NOT_IMPLEMENTED
void UnmuteUnitSpeech();

NOT_IMPLEMENTED
void LeaderboardComputerPlayers(State);

NOT_IMPLEMENTED
void LeaderboardGoalControl(Text, UnitType, Number);

NOT_IMPLEMENTED
void LeaderboardGoalControlAtLocation(Text, UnitType, Number, LocationId);

NOT_IMPLEMENTED
void LeaderboardGoalResources(Text, UnitType, Number, ResourceType);

NOT_IMPLEMENTED
void LeaderboardGoalKills(Text, UnitType, Number);

NOT_IMPLEMENTED
void LeaderboardGoalPoints(Text, Number, ScoreType);

NOT_IMPLEMENTED
void MoveLocation(Player, UnitType, LocationId sourceLocation, LocationId destLocation);

NOT_IMPLEMENTED
void MoveUnit(Player, UnitType, Number, LocationId sourceLocation, LocationId destLocation);

NOT_IMPLEMENTED
void LeaderboardGreed(Number);

NOT_IMPLEMENTED
void SetNextScenario(Text);

NOT_IMPLEMENTED
void SetDoodadState(Player, UnitType, LocationId, State);

NOT_IMPLEMENTED
void SetInvincibility(Player, UnitType, LocationId, State);

NOT_IMPLEMENTED
void CreateUnit(Player, UnitType, Number, LocationId);

NOT_IMPLEMENTED
void SetDeaths(Player, UnitType, Number, Modifier);

NOT_IMPLEMENTED
void Order(Player, UnitType, LocationId sourceLocation, LocationId destLocation, OrderType);

NOT_IMPLEMENTED
void GiveUnitsToPlayer(Player sourcePlayer, Player destPlayer, UnitType, Number, LocationId);

NOT_IMPLEMENTED
void ModifyUnitHitPoints(Player, UnitType, Number, ModAmount, LocationId);

NOT_IMPLEMENTED
void ModifyUnitEnergy(Player, UnitType, Number, ModAmount, LocationId);

NOT_IMPLEMENTED
void ModifyUnitShieldPoints(Player, UnitType, Number, ModAmount, LocationId);

NOT_IMPLEMENTED
void ModifyUnitResourceAmount(Player, UnitType, Number, ModAmount, LocationId);

NOT_IMPLEMENTED
void ModifyUnitHangerCount(Player, UnitType, Number, ModAmount, LocationId);

NOT_IMPLEMENTED
void PauseTimer();

NOT_IMPLEMENTED
void UnpauseTimer();

NOT_IMPLEMENTED
void Draw();

NOT_IMPLEMENTED
void SetAllianceStatus(Player, AllyStatus);

NOT_IMPLEMENTED
void DisableDebugMode();

NOT_IMPLEMENTED
void EnableDebugMode();


#endif
