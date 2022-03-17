/*
MIT License

Copyright(c) 2022 Wuping Xin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sub license, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
MIT License

Copyright (c) 2018 Tobias Widlund

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sub license, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef _DRIVERMODEL_META_H
#define _DRIVERMODEL_META_H

#include <array>
#include <concepts>
#include <optional>
#include <string_view>

namespace vissim_drivermodel {

template<typename EnumT> requires std::is_enum_v<EnumT>
struct MetaEnumMember {
  EnumT value = {};
  std::string_view name;
  std::string_view string;
  size_t index = {};
};

template<typename EnumT, typename EnumeratorT, size_t size> requires std::is_enum_v<EnumT>&& std::is_integral_v<EnumeratorT>
struct MetaEnum {
  using enumerator_t = EnumeratorT;
  std::string_view string;
  std::array<MetaEnumMember<EnumT>, size> members = {};
};

namespace meta_enum_internal {

constexpr bool IsNested(size_t a_brackets, bool a_quote) {
  return a_brackets != 0 || a_quote;
}

constexpr size_t NextEnumCommaOrEndPos(size_t a_start, std::string_view a_enum_str) {
  size_t l_brackets = 0; //()[]{}
  bool l_quote = false;  //""
  char l_last_char = '\0';
  char l_next_char = '\0';

  auto l_feed_counters = [&](char c) constexpr {
    if (l_quote) {
      if (l_last_char != '\\' && c == '"') //ignore " if they are backslashes
        l_quote = false;
      return;
    }

    switch (c) {
    case '"':
      if (l_last_char != '\\') //ignore " if they are backslashes
        l_quote = true;
      break;
    case '(':
    case '<':
      if (l_last_char == '<' || l_next_char == '<')
        break;
      [[fallthrough]];
    case '{':++l_brackets;
      break;
    case ')':
    case '>':
      if (l_last_char == '>' || l_next_char == '>')
        break;
      [[fallthrough]];
    case '}':--l_brackets;
      break;
    default:break;
    }
  };

  size_t l_current = a_start;
  for (; l_current < a_enum_str.size() && (IsNested(l_brackets, l_quote) || (a_enum_str[l_current] != ',')); ++l_current) {
    l_feed_counters(a_enum_str[l_current]);
    l_last_char = a_enum_str[l_current];
    l_next_char = l_current + 2 < a_enum_str.size() ? a_enum_str[l_current + 2] : '\0';
  }

  return l_current;
}

constexpr bool IsAllowedIdChar(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_';
}

constexpr std::string_view ParseEnumMemberName(std::string_view a_member_str) {
  size_t l_name_start = 0;
  while (!IsAllowedIdChar(a_member_str[l_name_start])) {
    ++l_name_start;
  }

  size_t l_name_size = 0;
  while ((l_name_start + l_name_size) < a_member_str.size() && IsAllowedIdChar(a_member_str[l_name_start + l_name_size])) {
    ++l_name_size;
  }

  return { &a_member_str[l_name_start], l_name_size };
}

template<typename EnumT, typename EnumeratorT, size_t size>
constexpr MetaEnum<EnumT, EnumeratorT, size> ParseMetaEnum(std::string_view in, const std::array<EnumT, size>& a_values) {
  MetaEnum<EnumT, EnumeratorT, size> result;
  result.string = in;

  std::array<std::string_view, size> l_member_str;
  size_t l_amount_filled = 0;
  size_t l_startpos = 0;

  while (l_amount_filled < size) {
    const size_t l_endpos = NextEnumCommaOrEndPos(l_startpos + 1, in);
    size_t l_strlen = l_endpos - l_startpos;

    if (l_startpos != 0) {
      ++l_startpos;
      --l_strlen;
    }

    l_member_str[l_amount_filled] = { &in[l_startpos], l_strlen };
    ++l_amount_filled;
    l_startpos = l_endpos;
  }

  for (size_t i = 0; i < l_member_str.size(); ++i) {
    result.members[i].name = ParseEnumMemberName(l_member_str[i]);
    result.members[i].string = l_member_str[i];
    result.members[i].value = a_values[i];
    result.members[i].index = i;
  }

  return result;
}

template<typename EnumeratorT>
struct IntWrapper {
  constexpr IntWrapper() : value(0), empty(true) {
  }

  explicit(false) constexpr IntWrapper(EnumeratorT in) : value(in), empty(false) // NOLINT(google-explicit-constructor)
  {
  }

  constexpr IntWrapper& operator=(EnumeratorT in) {
    value = in;
    empty = false;
    return *this;
  }

  EnumeratorT value;
  bool empty;
};

template<typename EnumT, typename EnumeratorT, size_t size>
constexpr std::array<EnumT, size> ResolveEnumValuesArray(const std::initializer_list<IntWrapper<EnumeratorT>>& in) {
  std::array<EnumT, size> result{};

  EnumeratorT l_next_value = 0;
  for (size_t i = 0; i < size; ++i) {
    auto it = in.begin();
    auto wrapper = (std::advance(it, i), *it);
    EnumeratorT l_new_value = wrapper.empty ? l_next_value : wrapper.value;
    l_next_value = l_new_value + 1;
    result[i] = static_cast<EnumT>(l_new_value);
  }

  return result;
}
}

#define meta_enum_class(Type, EnumeratorT, ...)\
  enum class Type: EnumeratorT { __VA_ARGS__};\
  constexpr static auto Type##_internal_size = []() constexpr {\
    using IntWrapperType = meta_enum_internal::IntWrapper<EnumeratorT>;\
    IntWrapperType __VA_ARGS__;\
    return std::initializer_list<IntWrapperType>{__VA_ARGS__}.size();\
  };\
  constexpr static auto Type##_meta = meta_enum_internal::ParseMetaEnum<\
    Type, EnumeratorT, Type##_internal_size()>(#__VA_ARGS__, []() {\
    using IntWrapperType = meta_enum_internal::IntWrapper<EnumeratorT>;\
    IntWrapperType __VA_ARGS__;\
    return meta_enum_internal::ResolveEnumValuesArray<\
      Type, EnumeratorT, Type##_internal_size()>({__VA_ARGS__});\
  }());\
  constexpr static auto Type##_value_to_string = [](Type e) {\
    for(const auto& member: Type##_meta.members) {\
      if(member.value == e)\
        return member.name;\
    }\
    return std::string_view("__INVALID_ENUM_VAL__");\
  \
  };\
  constexpr static auto Type##_meta_from_name = \
    [](std::string_view s)->std::optional<MetaEnumMember<Type>> {\
    for(const auto& member: Type##_meta.members) {\
      if(member.name == s)\
        return member;\
    }\
    return std::nullopt;\
  \
  };\
  constexpr static auto Type##_meta_from_value = \
    [](Type v)->std::optional<MetaEnumMember<Type>> {\
    for(const auto& member: Type##_meta.members) {\
      if(member.value == v)\
        return member;\
    }\
    return std::nullopt;\
  \
  };\
  constexpr static auto Type##_meta_from_index = [](size_t i) {\
    std::optional<MetaEnumMember<Type>> result;\
    if(i < Type##_meta.members.size())\
      result = Type##_meta.members[i];\
    return result;\
  \
  }

}

#endif