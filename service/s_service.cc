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

#include "service/s_service.h"
#include "service/smack_service.h"
#include "service/zebra_service.h"

namespace slash {

SService* SService::create(const rapidjson::Document& doc,
                           SCallback* callback) {
  auto itr = doc.FindMember("smack");
  if (itr != doc.MemberEnd()) {
    return new SmackService(doc, callback);
  }

  itr = doc.FindMember("zebra");
  if (itr != doc.MemberEnd()) {
    return new ZebraService(doc, callback);
  }

  return nullptr;
}

};  // namespace slash
