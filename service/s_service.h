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

#ifndef SERVICE_S_SERVICE_H_
#define SERVICE_S_SERVICE_H_

#include <string>
#include "soil/json.h"

namespace slash {

class SCallback {
 public:
  virtual void onMData(const std::string& instru,
                       const std::string& update_time, int update_millisec,
                       const struct timeval* t_pcap = nullptr) = 0;

  virtual ~SCallback() {}
};

class SService {
 public:
  static SService* create(const rapidjson::Document& doc, SCallback* callback);

  virtual ~SService() {}
};

}  // namespace slash

#endif  // SERVICE_S_SERVICE_H_
