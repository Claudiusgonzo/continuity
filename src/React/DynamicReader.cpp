#include <string>


#include <React/DynamicReader.h>

namespace Microsoft::React
{

const folly::dynamic* FindDynamicChild(const folly::dynamic& data, const char* const name) noexcept
{
    const auto iter = data.find(name);
    if (data.items().end() == iter)
    {
        return nullptr;
    }

    return &iter->second;
}

folly::dynamic GetDynamicObject(const folly::dynamic& data, const char* const name, folly::dynamic&& defaultValue) noexcept
{
    const auto child = FindDynamicChild(data, name);
    if (!child || !child->isObject())
    {
        return defaultValue;
    }

    return *child;
}

std::optional<std::string> GetDynamicString(const folly::dynamic& data, const char* const name) noexcept
{
    const auto child = FindDynamicChild(data, name);
    if (!child || !child->isString())
    {
        return std::nullopt;
    }

    return child->getString();
}

std::string GetDynamicString(const folly::dynamic& data, const char* const name, const char* const defaultValue) noexcept
{
    auto value = GetDynamicString(data, name);
    if (!value)
    {
        return defaultValue;
    }

    return *value;
}

std::optional<double> GetDynamicDouble(const folly::dynamic& data, const char* const name) noexcept
{
    const auto child = FindDynamicChild(data, name);
    if (!child || !child->isDouble())
    {
        return std::nullopt;
    }

    return child->getDouble();
}

double GetDynamicDouble(const folly::dynamic& data, const char* const name, double defaultValue) noexcept
{
    auto value = GetDynamicDouble(data, name);
    if (!value)
    {
        return defaultValue;
    }

    return *value;
}

std::optional<int64_t> GetDynamicInt(const folly::dynamic& data, const char* const name) noexcept
{
    const auto child = FindDynamicChild(data, name);
    if (!child || !child->isInt())
    {
        return std::nullopt;
    }

    return child->getInt();
}

int64_t GetDynamicInt(const folly::dynamic& data, const char* const name, int64_t defaultValue) noexcept
{
    auto value = GetDynamicInt(data, name);
    if (!value)
    {
        return defaultValue;
    }

    return *value;
}

bool GetDynamicBool(const folly::dynamic& data, const char* const name, bool defaultValue) noexcept
{
    const auto child = FindDynamicChild(data, name);
    if (!child || !child->isBool())
    {
        return defaultValue;
    }

    return child->getBool();
}

}
