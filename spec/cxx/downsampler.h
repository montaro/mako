// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// see the license for the specific language governing permissions and
// limitations under the license.

//
// For more information about Mako see: go/mako.
//
#ifndef SPEC_CXX_DOWNSAMPLER_H_
#define SPEC_CXX_DOWNSAMPLER_H_

#include <memory>
#include <string>

#include "spec/cxx/fileio.h"
#include "spec/proto/mako.pb.h"

namespace mako {

// An abstract class which describes the Mako C++ Downsampler interface.
//
// The Downsampler class is used to downsample user data to fit within Mako
// storage limits. See go/mako-storage#limits for more info on these limits.
//
// See implementing classes for detailed description on usage. See below for
// details on individual functions.
class Downsampler {
 public:
  // Set the FileIO implementation that is used to read samples.
  virtual void SetFileIO(std::unique_ptr<FileIO> fileio) = 0;

  // Perform downsampling to ensure data is suitable for storage system.
  // Returned std::string contains error message, if empty then operation was
  // successful.
  virtual std::string Downsample(
      const mako::DownsamplerInput& downsampler_input,
      mako::DownsamplerOutput* downsampler_output) = 0;

  virtual ~Downsampler() {}
};

}  // namespace mako

#endif  // SPEC_CXX_DOWNSAMPLER_H_
