#pragma once
#include<expected>
#include <ranges>
#include<string>
#include <string_view>

/**
 *  @file       version.hpp
 *  @brief      提供语义化版本号解析功能
 */

class SemVer{
	int major;
	int minor;
	int patch;
public:
	SemVer(int major, int minor, int patch): major(major), minor(minor), patch(patch){}
	bool operator==(const SemVer& other) const{
		return major == other.major && minor == other.minor && patch == other.patch;
	}
	bool operator!=(const SemVer& other) const{
		return !(*this == other);
	}
	bool operator<(const SemVer& other) const{
		if(major != other.major) return major < other.major;
		if(minor != other.minor) return minor < other.minor;
		return patch < other.patch;
	}
	bool operator>(const SemVer& other) const{
		return other < *this;
	}
	bool operator<=(const SemVer& other) const{
		return !(other < *this);
	}
	bool operator>=(const SemVer& other) const{
		return !(*this < other);
	}
};

/** @brief 将字符串转换为语义化版本号
 *  @param version 版本号字符串
 *  @return 解析结果，成功则返回SemVer对象，失败则返回错误信息
 */
auto toSemVer(const std::string& version) -> std::expected<SemVer, std::string>{
	int major = 0, minor = 0, patch = 0;
	size_t pos = 0;
	try {
		major = std::stoi(version, &pos);
		if(pos >= version.size() || version[pos] != '.') 
			return std::unexpected("Invalid version format");
		pos++;
		minor = std::stoi(version, &pos);
		if(pos >= version.size() || version[pos] != '.') 
			return std::unexpected("Invalid version format");
		pos++;
		patch = std::stoi(version, &pos);
		if(pos != version.size()) 
			return std::unexpected("Invalid version format");
	} catch(const std::exception& e) {
		return std::unexpected(e.what());
	}
	return SemVer(major, minor, patch);
}

/** @brief 检查版本号是否匹配目标版本
 *  @param version 版本号字符串
 *  @param target 目标版本约束
 *  @return 解析结果，成功则返回是否匹配，失败则返回错误信息
 
 支持 ^ , 
 */
auto matchVersion(const SemVer& version, const std::string& target) -> std::expected<bool, std::string> {
	
	auto v = target | std::views::split(',');
	
	for(const auto& t : v) {
		std::string_view tv(t.begin(), t.end());
		if(tv.empty()) continue;
		
	}
}