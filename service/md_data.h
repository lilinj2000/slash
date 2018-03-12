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


#ifndef SERVICE_MD_DATA_H_
#define SERVICE_MD_DATA_H_

#include <string>
#include <set>

#include "soil/data_file.h"
#include "soil/date_time.h"

namespace slash {

class MDataFile;

typedef std::set<std::string> InstrusFilter;

class MData : public soil::Data {
 public:
  virtual const std::string& instruID() const = 0;
};

class SpeedMData : public MData {
 public:
  virtual const std::string& instruID() const {
    return instru;
  }

  virtual void writeToFile(std::ofstream* os) const;

  std::string instru;
  std::string update_time;
  int update_millisec;

  soil::DateTime time_stamp;
};

class MDataFile : public soil::DataFile {
 public:
  MDataFile(const std::string& file_name,
            const std::string& instrus_filter = "");

  virtual ~MDataFile();

 protected:
  virtual bool filterData(
      std::shared_ptr<soil::Data> data);

 private:
  InstrusFilter instrus_filter_;
};

}  // namespace slash

#endif  // SERVICE_MD_DATA_H_
