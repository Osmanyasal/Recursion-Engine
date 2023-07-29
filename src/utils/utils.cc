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

std::string read_file(std::string location)
{
    std::stringstream buffer;
    std::ifstream file(location);
    if (OPT_UNLIKELY(!file.is_open()))
    {
        REC_CORE_ERROR("file not found at the location {}",location);
        throw std::runtime_error("Failed to open the file: " + location);
    }
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}