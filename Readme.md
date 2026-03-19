# Forge 🛠️

Forge 是一个为 C++ 开发设计的现代包管理器和构建前端，旨在简化 C++ 项目的依赖管理、构建和分发流程。

目前 Forge 处于早期开发阶段，首要目标是实现一个基于 `clang` + `cmake` 的极简版本，随后将逐步扩展功能并支持更多编译器与构建系统。

## 🌟 核心特性 (路线图)

- **现代配置文件**: 使用 `toml` 格式定义项目元数据和依赖。
- **依赖解析**: 自动解析依赖树并处理版本冲突。
- **自动构建集成**: 无缝生成并调用 CMake 脚本或其他构建系统。
- **多编译器支持**: 初始支持 Clang，计划扩展至 GCC 和 MSVC。
- **跨平台**: 设计之初即考虑 Linux, macOS 及 Windows 支持。

## 🏗️ 快速开始

### 项目配置

在项目根目录下创建 `forge.toml` (参考 [example/sample.toml](example/sample.toml)):

```toml
[package]
name = "my_project"
version = "0.1.0"
authors = ["Your Name"]

[compiler]
name = "clang"
cpp_standard = "c++20"

[dependencies.fmt]
version = "10.2.1"
```

### 常用命令

> 注：命令集目前正在定义中，详情请参阅 [docs/CLI命令集.md](docs/CLI%E5%91%BD%E4%BB%A4%E9%9B%86.md)

- `forge init`: 初始化新项目
- `forge build`: 编译项目
- `forge run`: 运行项目
- `forge add <pkg>`: 添加依赖

## 📂 项目结构

- `src/`: 源代码目录
  - `cli/`: 命令行接口实现
  - `config/`: 配置解析 (`toml`)
  - `dependency/`: 依赖图解析与管理
  - `fetch/`: 源码/二进制获取
  - `generator/`: 构建系统文件生成 (如 CMakeLists.txt)
- `docs/`: 设计文档与规范
- `example/`: 示例配置文件

## 🛠️ 开发计划

请关注 [TODO/Plan.md](TODO/Plan.md) 了解最新开发进度。

1. [ ] 实现 TOML 解析工具
2. [ ] 依赖关系解析算法实现
3. [ ] 自动生成基础 CMake 构建文件
4. [ ] 实现基础命令行工具

## 📄 许可证

本项目采用 [LICENSE](LICENSE) 许可。
