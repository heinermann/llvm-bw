#pragma once

#include "TriggerGenerator.h"
#include "../../chklib/MappingCore.h"

using namespace llvmbw;
using namespace llvmbw;

Chk::Condition ConditionGen::NoCondition() {
  Chk::Condition cond{};
  cond.conditionType = Chk::Condition::Type::NoCondition;
  cond.flags = 0;
  return cond;
}

Chk::Condition ConditionGen::CountdownTimer() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::Command() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::Bring() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::Accumulate() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::Kill() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::CommandTheMost() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::CommandTheMostAt() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::MostKills() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::HighestScore() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::MostResources() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::Switch() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::ElapsedTime() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::IsBriefing() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::Opponents() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::Deaths(Sc::Player::Id player, Chk::Condition::Comparison comparison, uint32_t amount, Sc::Unit::Type unitType) {
  Chk::Condition cond{};
  cond.conditionType = Chk::Condition::Type::Deaths;
  cond.player = player;
  cond.comparison = comparison;
  cond.amount = amount;
  cond.unitType = unitType;
  cond.flags = 0;
  cond.maskFlag = Chk::Condition::MaskFlag::Disabled;
  return cond;
}
Chk::Condition ConditionGen::CommandTheLeast() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::CommandTheLeastAt() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::LeastKills() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::LowestScore() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::LeastResources() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::Score() {
  Chk::Condition cond{};

  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::Always() {
  Chk::Condition cond{};
  cond.conditionType = Chk::Condition::Type::Always;
  cond.flags = 0;
  return cond;
}
Chk::Condition ConditionGen::Never() {
  Chk::Condition cond{};
  cond.conditionType = Chk::Condition::Type::Never;
  cond.flags = 0;
  return cond;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

Chk::Action ActionGen::NoAction() {
  Chk::Action act{};
  act.actionType = Chk::Action::Type::NoAction;
  act.flags = 0;
  return act;
}
Chk::Action ActionGen::Victory() {
  Chk::Action act{};
  act.actionType = Chk::Action::Type::Victory;
  act.flags = 0;
  return act;
}
Chk::Action ActionGen::Defeat() {
  Chk::Action act{};
  act.actionType = Chk::Action::Type::Defeat;
  act.flags = 0;
  return act;
}
Chk::Action ActionGen::PreserveTrigger() {
  Chk::Action act{};
  act.actionType = Chk::Action::Type::PreserveTrigger;
  act.flags = 0;
  return act;
}
Chk::Action ActionGen::Wait(uint32_t time) {
  Chk::Action act{};
  act.actionType = Chk::Action::Type::Wait;
  act.time = time;
  act.flags = 0;
  return act;
}
Chk::Action ActionGen::PauseGame() {
  Chk::Action act{};
  act.actionType = Chk::Action::Type::PauseGame;
  act.flags = 0;
  return act;
}
Chk::Action ActionGen::UnpauseGame() {
  Chk::Action act{};
  act.actionType = Chk::Action::Type::UnpauseGame;
  act.flags = 0;
  return act;
}
Chk::Action ActionGen::Transmission() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::PlaySound() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::DisplayTextMessage() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::CenterView() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::CreateUnitWithProperties() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::SetMissionObjectives() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::SetSwitch() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::SetCountdownTimer() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::RunAiScript() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::RunAiScriptAtLocation() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::LeaderboardCtrl() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::LeaderboardCtrlAtLoc() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::LeaderboardResources() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::LeaderboardKills() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::LeaderboardPoints() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::KillUnit() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::KillUnitAtLocation() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::RemoveUnit() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::RemoveUnitAtLocation() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::SetResources() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::SetScore() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::MinimapPing() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::TalkingPortrait() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::MuteUnitSpeech() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::UnmuteUnitSpeech() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::LeaderboardCompPlayers() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::LeaderboardGoalCtrl() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::LeaderboardGoalCtrlAtLoc() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::LeaderboardGoalResources() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::LeaderboardGoalKills() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::LeaderboardGoalPoints() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::MoveLocation() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::MoveUnit() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::LeaderboardGreed() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::SetNextScenario() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::SetDoodadState() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::SetInvincibility() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::CreateUnit() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::SetDeaths(Sc::Player::Id player, Chk::Action::ValueModifier modifier, uint32_t number, Sc::Unit::Type unitType) {
  Chk::Action act{};
  act.actionType = Chk::Action::Type::SetDeaths;
  act.group = player;
  act.type2 = modifier;
  act.number = number;
  act.type = unitType;
  act.flags = 0;
  act.maskFlag = Chk::Action::MaskFlag::Disabled;
  return act;
}
Chk::Action ActionGen::SetMemory(uint32_t memAddress, Chk::Action::ValueModifier modifier, uint32_t number)
{
  Chk::Action act{};
  act.actionType = Chk::Action::Type::SetDeaths;
  act.group = (memAddress - 0x58A364) / 4;
  act.type2 = modifier;
  act.number = number;
  act.type = 0;
  act.flags = 0;
  act.maskFlag = Chk::Action::MaskFlag::Disabled;
  return act;
}
Chk::Action ActionGen::Order() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::Comment() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::GiveUnitsToPlayer() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::ModifyUnitHitpoints() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::ModifyUnitEnergy() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::ModifyUnitShieldPoints() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::ModifyUnitResourceAmount() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::ModifyUnitHangerCount() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::PauseTimer() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::UnpauseTimer() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::Draw() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::SetAllianceStatus() {
  Chk::Action act{};

  act.flags = 0;

  return act;
}
Chk::Action ActionGen::DisableDebugMode() {
  Chk::Action act{};

  act.flags = 0;

  return act;
} // 58
Chk::Action ActionGen::EnableDebugMode() {
  Chk::Action act{};

  act.flags = 0;

  return act;
} // 59
