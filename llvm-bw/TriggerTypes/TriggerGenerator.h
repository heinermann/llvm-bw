#pragma once

#include "../../chklib/MappingCore.h"

#include <cstdint>

namespace llvmbw {
  namespace ConditionGen {
    Chk::Condition NoCondition();
    Chk::Condition CountdownTimer();
    Chk::Condition Command();
    Chk::Condition Bring();
    Chk::Condition Accumulate();
    Chk::Condition Kill();
    Chk::Condition CommandTheMost();
    Chk::Condition CommandTheMostAt();
    Chk::Condition MostKills();
    Chk::Condition HighestScore();
    Chk::Condition MostResources();
    Chk::Condition Switch();
    Chk::Condition ElapsedTime();
    Chk::Condition IsBriefing();
    Chk::Condition Opponents();
    Chk::Condition Deaths(Sc::Player::Id player, Chk::Condition::Comparison comparison, uint32_t amount, Sc::Unit::Type unitType);
    Chk::Condition CommandTheLeast();
    Chk::Condition CommandTheLeastAt();
    Chk::Condition LeastKills();
    Chk::Condition LowestScore();
    Chk::Condition LeastResources();
    Chk::Condition Score();
    Chk::Condition Always();
    Chk::Condition Never();
  };
  namespace ActionGen {
    Chk::Action NoAction();
    Chk::Action Victory();
    Chk::Action Defeat();
    Chk::Action PreserveTrigger();
    Chk::Action Wait(uint32_t time);
    Chk::Action PauseGame();
    Chk::Action UnpauseGame();
    Chk::Action Transmission();
    Chk::Action PlaySound();
    Chk::Action DisplayTextMessage();
    Chk::Action CenterView();
    Chk::Action CreateUnitWithProperties();
    Chk::Action SetMissionObjectives();
    Chk::Action SetSwitch();
    Chk::Action SetCountdownTimer();
    Chk::Action RunAiScript();
    Chk::Action RunAiScriptAtLocation();
    Chk::Action LeaderboardCtrl();
    Chk::Action LeaderboardCtrlAtLoc();
    Chk::Action LeaderboardResources();
    Chk::Action LeaderboardKills();
    Chk::Action LeaderboardPoints();
    Chk::Action KillUnit();
    Chk::Action KillUnitAtLocation();
    Chk::Action RemoveUnit();
    Chk::Action RemoveUnitAtLocation();
    Chk::Action SetResources();
    Chk::Action SetScore();
    Chk::Action MinimapPing();
    Chk::Action TalkingPortrait();
    Chk::Action MuteUnitSpeech();
    Chk::Action UnmuteUnitSpeech();
    Chk::Action LeaderboardCompPlayers();
    Chk::Action LeaderboardGoalCtrl();
    Chk::Action LeaderboardGoalCtrlAtLoc();
    Chk::Action LeaderboardGoalResources();
    Chk::Action LeaderboardGoalKills();
    Chk::Action LeaderboardGoalPoints();
    Chk::Action MoveLocation();
    Chk::Action MoveUnit();
    Chk::Action LeaderboardGreed();
    Chk::Action SetNextScenario();
    Chk::Action SetDoodadState();
    Chk::Action SetInvincibility();
    Chk::Action CreateUnit();
    Chk::Action SetDeaths(Sc::Player::Id player, Chk::Action::ValueModifier modifier, uint32_t number, Sc::Unit::Type unitType);
    Chk::Action SetMemory(uint32_t memAddress, Chk::Action::ValueModifier modifier, uint32_t number);
    Chk::Action Order();
    Chk::Action Comment();
    Chk::Action GiveUnitsToPlayer();
    Chk::Action ModifyUnitHitpoints();
    Chk::Action ModifyUnitEnergy();
    Chk::Action ModifyUnitShieldPoints();
    Chk::Action ModifyUnitResourceAmount();
    Chk::Action ModifyUnitHangerCount();
    Chk::Action PauseTimer();
    Chk::Action UnpauseTimer();
    Chk::Action Draw();
    Chk::Action SetAllianceStatus();
    Chk::Action DisableDebugMode(); // 58
    Chk::Action EnableDebugMode(); // 59
  };
};
