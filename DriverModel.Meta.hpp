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
#include <optional>
#include <string_view>

template <typename EnumT>
struct MetaEnumMember
{
	EnumT value = {};
	std::string_view name;
	std::string_view string;
	size_t index = {};
};

template <typename EnumT, typename EnumeratorT, size_t size>
struct MetaEnum
{
	using enumerator_t = EnumeratorT;
	std::string_view string;
	std::array<MetaEnumMember<EnumT>, size> members = {};
};

namespace meta_enum_internal {


	constexpr bool is_nested(size_t a_brackets, bool a_quote)
	{
		return a_brackets != 0 || a_quote;
	}

	constexpr size_t next_enum_comma_or_end_pos(size_t a_start, std::string_view a_enum_str)
	{
		size_t l_brackets = 0; //()[]{}
		bool l_quote = false;  //""
		char l_lastchar = '\0';
		char l_nextchar = '\0';

		auto l_feedcounters = [&](char c)  constexpr {
			if (l_quote) {
				if (l_lastchar != '\\' && c == '"') //ignore " if they are backslashed
					l_quote = false;
				return;
			}

			switch (c) {
			case '"':
				if (l_lastchar != '\\') //ignore " if they are backslashed
					l_quote = true;
				break;
			case '(':
			case '<':
				if (l_lastchar == '<' || l_nextchar == '<')
					break;
				[[fallthrough]];
			case '{':
				++l_brackets;
				break;
			case ')':
			case '>':
				if (l_lastchar == '>' || l_nextchar == '>')
					break;
				[[fallthrough]];
			case '}':
				--l_brackets;
				break;
			default:
				break;
			}
		};

		size_t l_current = a_start;
		for (; l_current < a_enum_str.size() &&
			(is_nested(l_brackets, l_quote) || (a_enum_str.at(l_current) != ','));
			++l_current) {
			l_feedcounters(a_enum_str.at(l_current));
			l_lastchar = a_enum_str.at(l_current);
			l_nextchar = l_current + 2 < a_enum_str.size() ? a_enum_str.at(l_current + 2) : '\0';
		}

		return l_current;
	}

	constexpr bool is_allowed_id_char(char c)
	{
		return (c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z') ||
			(c >= '0' && c <= '9') ||
			c == '_';
	}

	constexpr std::string_view parse_enum_member_name(std::string_view a_member_str)
	{
		size_t l_name_start = 0;
		while (!is_allowed_id_char(a_member_str.at(l_name_start))) {
			++l_name_start;
		}

		size_t l_name_size = 0;

		while ((l_name_start + l_name_size) < a_member_str.size() &&
			is_allowed_id_char(a_member_str.at(l_name_start + l_name_size))) {
			++l_name_size;
		}

		return std::string_view(&a_member_str.at(l_name_start), l_name_size);
	}

	template <typename EnumT, typename EnumeratorT, size_t size>
	constexpr MetaEnum<EnumT, EnumeratorT, size> parse_meta_enum(std::string_view in,
		const std::array<EnumT, size>& a_values)
	{
		MetaEnum<EnumT, EnumeratorT, size> result;
		result.string = in;

		std::array<std::string_view, size> l_member_str;
		size_t l_amount_filled = 0;
		size_t l_curstr_start = 0;

		while (l_amount_filled < size) {
			const size_t l_curstr_end = next_enum_comma_or_end_pos(l_curstr_start + 1, in);
			size_t l_curstr_size = l_curstr_end - l_curstr_start;

			if (l_curstr_start != 0) {
				++l_curstr_start;
				--l_curstr_size;
			}

			l_member_str.at(l_amount_filled) = std::string_view(
				&in.at(l_curstr_start), l_curstr_size);
			++l_amount_filled;
			l_curstr_start = l_curstr_end;
		}

		for (size_t i = 0; i < l_member_str.size(); ++i) {
			result.members.at(i).name = parse_enum_member_name(l_member_str.at(i));
			result.members.at(i).string = l_member_str.at(i);
			result.members.at(i).value = a_values.at(i);
			result.members.at(i).index = i;
		}

		return result;
	}

	template <typename EnumeratorT>
	struct IntWrapper
	{
		constexpr IntWrapper() : value(0), empty(true)
		{
		}
		constexpr IntWrapper(EnumeratorT in) : value(in), empty(false)
		{
		}
		constexpr IntWrapper operator=(EnumeratorT in)
		{
			value = in;
			empty = false;
			return *this;
		}
		EnumeratorT value;
		bool empty;
	};

	template <typename EnumT, typename EnumeratorT, size_t size>
	constexpr std::array<EnumT, size> resolve_enum_values_array(
		const std::initializer_list<IntWrapper<EnumeratorT>>& in)
	{
		std::array<EnumT, size> result{};

		EnumeratorT l_next_value = 0;
		for (size_t i = 0; i < size; ++i) {
			auto it = in.begin();
			auto wrapper = (std::advance(it, i), *it);
			EnumeratorT  l_new_value = wrapper.empty ? l_next_value : wrapper.value;
			l_next_value = l_new_value + 1;
			result.at(i) = static_cast<EnumT>(l_new_value);
		}

		return result;
	}
}

#define meta_enum(Type, EnumeratorT, ...)\
    enum Type: EnumeratorT { __VA_ARGS__};\
    constexpr static auto Type##_internal_size = []() constexpr {\
        using IntWrapperType = meta_enum_internal::IntWrapper<EnumeratorT>;\
        IntWrapperType __VA_ARGS__;\
        return std::initializer_list<IntWrapperType>{__VA_ARGS__}.size();\
    };\
    constexpr static auto Type##_meta = meta_enum_internal::parse_meta_enum<\
        Type, EnumeratorT, Type##_internal_size()>(#__VA_ARGS__, []() {\
        using IntWrapperType = meta_enum_internal::IntWrapper<EnumeratorT>;\
        IntWrapperType __VA_ARGS__;\
        return meta_enum_internal::resolve_enum_values_array<\
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
            result = Type##_meta.members.at(i);\
        return result;\
    \
    }

#define meta_enum_class(Type, EnumeratorT, ...)\
    enum class Type: EnumeratorT { __VA_ARGS__};\
    constexpr static auto Type##_internal_size = []() constexpr {\
        using IntWrapperType = meta_enum_internal::IntWrapper<EnumeratorT>;\
        IntWrapperType __VA_ARGS__;\
        return std::initializer_list<IntWrapperType>{__VA_ARGS__}.size();\
    };\
    constexpr static auto Type##_meta = meta_enum_internal::parse_meta_enum<\
        Type, EnumeratorT, Type##_internal_size()>(#__VA_ARGS__, []() {\
        using IntWrapperType = meta_enum_internal::IntWrapper<EnumeratorT>;\
        IntWrapperType __VA_ARGS__;\
        return meta_enum_internal::resolve_enum_values_array<\
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
            result = Type##_meta.members.at(i);\
        return result;\
    \
    }

#endif