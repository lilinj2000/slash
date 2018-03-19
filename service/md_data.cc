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

#include <iomanip>
#include "service/md_data.h"
#include "soil/string.h"
#include "soil/json.h"
#include "soil/log.h"

namespace slash {

void SpeedMData::writeToFile(std::ofstream* os) const {
  SOIL_TRACE("SpeedMData::writeToFile()");

  soil::DateTime start_time(update_time);

  start_time += std::chrono::milliseconds(update_millisec);

  std::chrono::system_clock::duration delay = time_stamp - start_time;

  (*os) << update_time << "." << std::setfill('0') << std::setw(3)
        << update_millisec << "\t" << start_time << "\t" << time_stamp << "\t"
        << delay.count();

  if (t_pcap) {
    soil::DateTime tk(std::chrono::system_clock::from_time_t(t_pcap->tv_sec));
    tk += std::chrono::microseconds(t_pcap->tv_usec);

    std::chrono::system_clock::duration delay = tk - start_time;

    (*os) << "\t" << tk << "\t" << delay.count();
  }

  (*os) << std::endl;
}

MDataFile::MDataFile(const std::string& file_name,
                     const std::string& instrus_filter)
    : soil::DataFile(file_name) {
  SOIL_TRACE("MDataFile::MDataFile()");

  soil::splitString(&instrus_filter_, instrus_filter);
}

MDataFile::~MDataFile() { SOIL_TRACE("MDataFile::~MDataFile()"); }

bool MDataFile::filterData(std::shared_ptr<soil::Data> data) {
  SOIL_TRACE("MData::filterData()");

  const MData* mdata = dynamic_cast<const MData*>(data.get());

  if (instrus_filter_.empty() || instrus_filter_.count(mdata->instruID()) > 0) {
    SOIL_DEBUG_PRINT(mdata->instruID());

    return true;
  }

  return false;
}

}  // namespace slash
