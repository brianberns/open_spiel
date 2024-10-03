// Copyright 2019 DeepMind Technologies Limited
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <string>
#include <vector>

#include "open_spiel/abseil-cpp/absl/strings/str_split.h"

namespace open_spiel {
namespace chess {

constexpr const char* kChess960StartingFens =
    R"(bbqnnrkr/pppppppp/8/8/8/8/PPPPPPPP/BBQNNRKR w KQkq - 0 1
bbqnrnkr/pppppppp/8/8/8/8/PPPPPPPP/BBQNRNKR w KQkq - 0 1
bbqnrknr/pppppppp/8/8/8/8/PPPPPPPP/BBQNRKNR w KQkq - 0 1
bbqnrkrn/pppppppp/8/8/8/8/PPPPPPPP/BBQNRKRN w KQkq - 0 1
bbqrnnkr/pppppppp/8/8/8/8/PPPPPPPP/BBQRNNKR w KQkq - 0 1
bbqrnknr/pppppppp/8/8/8/8/PPPPPPPP/BBQRNKNR w KQkq - 0 1

... TOO LONG ...

rkrnnqbb/pppppppp/8/8/8/8/PPPPPPPP/RKRNNQBB w KQkq - 0 1)";

std::vector<std::string> Chess960StartingPositions() {
  return absl::StrSplit(kChess960StartingFens, '\n');
}

}  // namespace chess
}  // namespace open_spiel
