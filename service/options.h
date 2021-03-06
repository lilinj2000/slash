// Copyright 2017 The Slash Authors.
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
//
// -----------------------------------------------------------------------------
// File: [file_name]
// -----------------------------------------------------------------------------
//
// [file_descrition]
//
// Example:
//
//   ... ...
//
//

#ifndef SERVICE_OPTIONS_H_
#define SERVICE_OPTIONS_H_

#include <string>
#include "soil/json.h"

namespace slash {

class Options {
 public:
  explicit Options(const rapidjson::Document& doc);

  virtual ~Options() {
  }

  std::string instrus_filter;

  std::string speed_file;
};

}  // namespace slash

#endif  // SERVICE_OPTIONS_H_
