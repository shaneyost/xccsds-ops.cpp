#include "CcsdsPrimaryHeader.hpp"
#include "BbyEpochSecondaryHeader.hpp"
#include "CcsdsPacket.hpp"
#include <iostream>
#include <iomanip>

int main()
{
    auto primaryHeader = CcsdsPrimaryHeader::createTelemetryPacket(42);
    auto secondaryHeader = BbyEpochSecondaryHeader::now();

    std::cout << "BBY Epoch (sec. since BBY): "
    << secondaryHeader.getEpoch()
    << std::endl;

    std::vector<uint8_t> data = {0xDE, 0xAD, 0xBE, 0xEF};

    CcsdsPacket packet(primaryHeader, secondaryHeader, std::move(data));
    auto serializedPacket = packet.serialize();

    std::cout << "Serialized CCSDS Packet: ";
    for (auto byte : serializedPacket)
    {
        std::cout << std::hex
        << std::setw(2)
        << std::setfill('0')
        << static_cast<int>(byte) << " ";
    }
    std::cout << std::dec << std::endl;

    return 0;
}
