/*
 *  Copyright (c) 2019-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <vector>
#include <cstdint>
#include <fizz/record/Extensions.h>
#include <fizz/crypto/hpke/Types.h>

namespace fizz {
namespace extensions {

using Buf = std::unique_ptr<folly::IOBuf>;
using HpkePublicKey = Buf;
using HpkeNonce = std::array<uint8_t, 16>;

enum class ECHVersion: uint16_t {
    V7 = 0xff07,
};

struct HpkeCipherSuite {
    hpke::KDFId kdfId;
    hpke::AeadId aeadId;
};

struct ECHConfigContentDraft7 {
    Buf public_name;
    HpkePublicKey public_key;
    hpke::KEMId kem_id;
    std::vector<HpkeCipherSuite> cipher_suites;
    uint16_t maximum_name_length;
    std::vector<Extension> extensions;
};


struct ECHConfig {
    ECHVersion version;
    uint16_t length;
    Buf ech_config_content;
};

} // namespace extensions
} // namespace fizz

#include <fizz/extensions/ech/Types-inl.h>
