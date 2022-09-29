/*
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef ACSDK_CRYPTOINTERFACES_TEST_MOCKCRYPTOCODEC_H_
#define ACSDK_CRYPTOINTERFACES_TEST_MOCKCRYPTOCODEC_H_

#include <acsdk/CryptoInterfaces/CryptoCodecInterface.h>
#include <acsdk/Test/GmockExtensions.h>

namespace alexaClientSDK {
namespace cryptoInterfaces {
namespace test {

/**
 * Mock class for @c CryptoCodecInterface.
 */
class MockCryptoCodec : public CryptoCodecInterface {
public:
    MOCK_NOEXCEPT_METHOD2(_init, bool(const Key&, const IV&));
    MOCK_NOEXCEPT_METHOD1(_processAAD, bool(const DataBlock&));
    MOCK_NOEXCEPT_METHOD2(_processAAD, bool(const DataBlock::const_iterator&, const DataBlock::const_iterator&));
    MOCK_NOEXCEPT_METHOD2(_process, bool(const DataBlock&, DataBlock&));
    MOCK_NOEXCEPT_METHOD3(
        _process,
        bool(const DataBlock::const_iterator&, const DataBlock::const_iterator&, DataBlock&));
    MOCK_NOEXCEPT_METHOD1(_finalize, bool(DataBlock&));
    MOCK_NOEXCEPT_METHOD1(_getTag, bool(Tag&));
    MOCK_NOEXCEPT_METHOD1(_setTag, bool(const Tag&));
};

}  // namespace test
}  // namespace cryptoInterfaces
}  // namespace alexaClientSDK

#endif  // ACSDK_CRYPTOINTERFACES_TEST_MOCKCRYPTOCODEC_H_
