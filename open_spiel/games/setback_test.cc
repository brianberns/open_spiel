// Copyright 2019 DeepMind Technologies Ltd. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "open_spiel/games/setback.h"

#include "open_spiel/algorithms/get_all_states.h"
#include "open_spiel/spiel_utils.h"
#include "open_spiel/tests/basic_tests.h"

namespace open_spiel {
namespace setback {
namespace {

namespace testing = open_spiel::testing;

void BasicSetbackTests() {
  testing::LoadGameTest("setback");
  testing::ChanceOutcomesTest(*LoadGame("setback"));
  testing::RandomSimTest(*LoadGame("setback"), 100);
  for (Player players = 3; players <= 5; players++) {
    testing::RandomSimTest(
        *LoadGame("setback", {{"players", GameParameter(players)}}), 100);
  }
}

void CountStates() {
  std::shared_ptr<const Game> game = LoadGame("setback");
  auto states = algorithms::GetAllStates(*game, /*depth_limit=*/-1,
                                         /*include_terminals=*/true,
                                         /*include_chance_states=*/false);
  // 6 deals * 9 betting sequences (-, p, b, pp, pb, bp, bb, pbp, pbb) = 54
  SPIEL_CHECK_EQ(states.size(), 54);
}

}  // namespace
}  // namespace setback
}  // namespace open_spiel

int main(int argc, char **argv) {
  open_spiel::setback::BasicSetbackTests();
  open_spiel::setback::CountStates();
  open_spiel::testing::CheckChanceOutcomes(*open_spiel::LoadGame(
      "setback", {{"players", open_spiel::GameParameter(3)}}));
  open_spiel::testing::RandomSimTest(*open_spiel::LoadGame("setback"),
                                     /*num_sims=*/10);
  open_spiel::testing::ResampleInfostateTest(
      *open_spiel::LoadGame("setback"),
      /*num_sims=*/10);
}
