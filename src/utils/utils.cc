#include <utils.hh>

std::string generateGUID()
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> dis(0, 0xFFFFFFFFFFFFFFFF);

    std::stringstream ss;
    ss << std::hex << std::setfill('0');

    // Generate first part (8 digits)
    ss << std::setw(8) << dis(gen);

    // Generate second part (4 digits)
    ss << '-';
    ss << std::setw(4) << dis(gen);

    // Generate third part (4 digits)
    ss << '-';
    ss << std::setw(4) << dis(gen);

    // Generate fourth part (4 digits)
    ss << '-';
    ss << std::setw(4) << dis(gen);

    // Generate fifth part (12 digits)
    ss << '-';
    ss << std::setw(12) << dis(gen);
    return ss.str();
}