#pragma once
#include "CcsdsPrimaryHeader.hpp"
#include "BbyEpochSecondaryHeader.hpp"
#include <vector>
#include <cstdint>

class CcsdsPacket
{
public:
    CcsdsPacket(const CcsdsPrimaryHeader& primary,
                const BbyEpochSecondaryHeader& secondary,
                std::vector<uint8_t>&& data);

    std::vector<uint8_t> serialize() const;

private:
    CcsdsPrimaryHeader primary_;
    BbyEpochSecondaryHeader secondary_;
    std::vector<uint8_t> data_;
    static inline uint16_t sequenceCounter_ = 0;
};
