#include "sha1.h"

#include<cstdint>
#include<string>
#include<vector>
#include<iomanip>
#include<sstream>

uint32_t rotateLeft(uint32_t value, uint32_t bits) {
    return (value << bits) | (value >> (32 - bits));//rol
}

std::vector<uint8_t> padMessage(const std::string& input) {
    std::vector<uint8_t> message(input.begin(), input.end());

    uint64_t originalLength = input.size() * 8;
    message.push_back(0x80);

    while(message.size() % 64 != 56) {
        message.push_back(0x00);
    }

    for(int i=7; i>=0; --i) {
        message.push_back(static_cast<uint8_t>(originalLength >> (i * 8)));
    }

    return message;
}

void createMessageSchedule(const std::vector<uint8_t>& message, size_t offset, uint32_t words[80]) {

}

uint32_t roundFunction(uint32_t b, uint32_t c, uint32_t d, int round) {
    return 0;
}

uint32_t roundConstant(int round) {
    return 0;
}

std::string toHex(uint32_t value) {
    std::stringstream stream;

    stream << std::hex << std::setfill('0') << std::setw(8) << value;
    return stream.str();
}

std::string sha1(const std::string& input) {
    uint32_t h0 = 0x67452301;
    uint32_t h1 = 0xEFCDAB89;
    uint32_t h2 = 0x98BADCFE;
    uint32_t h3 = 0x10325476;
    uint32_t h4 = 0xC3D2E1F0;

    return "";
}