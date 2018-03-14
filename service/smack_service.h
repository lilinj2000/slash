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

#ifndef SERVICE_SMACK_SERVICE_H_
#define SERVICE_SMACK_SERVICE_H_

#include <string>
#include "service/s_service.h"
#include "smack/md_service.h"

namespace slash {

class SmackService : public SService, public smack::MDServiceCallback {
 public:
  explicit SmackService(const rapidjson::Document& doc, SCallback* callback);

  virtual ~SmackService();

  virtual void onReceiveNormal(const smack::guava_udp_normal* data);

 private:
  std::unique_ptr<smack::MDService> md_service_;

  SCallback* callback_;
};

}  // namespace slash

#endif  // SERVICE_SMACK_SERVICE_H_
