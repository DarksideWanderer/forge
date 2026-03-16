“Conventional Commits” 是一种 **Git 提交信息的规范**，目的是让提交历史 **可读、可自动化处理**，方便生成 changelog、自动版本号管理、CI/CD 等。

它不是工具，而是一套 **写 commit message 的约定**。

---

# 1️⃣ 基本格式

```
<type>[optional scope]: <description>

[optional body]

[optional footer(s)]
```

* `<type>`：提交类型（必需）
* `[scope]`：影响的模块/功能（可选）
* `<description>`：简短描述（必需）
* `body`：详细说明（可选）
* `footer`：关联 issue 或 BREAKING CHANGE（可选）

---

# 2️⃣ 常见 `<type>` 类型

| 类型       | 含义                |
| -------- | ----------------- |
| feat     | 新功能（feature）      |
| fix      | 修复 bug            |
| docs     | 文档修改              |
| style    | 格式/空格/分号等不影响逻辑的修改 |
| refactor | 重构，不新增功能也不修复 bug  |
| perf     | 性能优化              |
| test     | 添加或修改测试           |
| build    | 构建系统/依赖修改         |
| ci       | CI 配置修改           |
| chore    | 其他杂项（例如修改工具脚本）    |
| revert   | 回滚提交              |

---

# 3️⃣ 示例

### 添加新功能

```
feat(parser): support parsing new syntax
```

### 修复 bug

```
fix(renderer): fix crash when input is empty
```

### 文档修改

```
docs: update README with new examples
```

### 带 BREAKING CHANGE

```
feat(core): change API of FooBar

BREAKING CHANGE: FooBar::doSomething() now returns bool instead of int
```

---

# 4️⃣ 好处

1. **生成 changelog**

   * 工具可以自动生成版本说明，例如 `standard-version` 或 `semantic-release`
2. **自动语义化版本控制（SemVer）**

   * feat → minor bump
   * fix → patch bump
   * BREAKING CHANGE → major bump
3. **清晰历史记录**

   * 一眼就能看出每条提交做了什么
4. **方便团队协作**

   * 所有人都遵循同一个规范

---

# 5️⃣ 现代用法

* 在 CI/CD 中结合 `semantic-release` 或 `standard-version` 可以自动：

  * 生成 changelog
  * 提升版本号
  * 打 tag

* 对你的 C++ 包管理器项目也很适用：

  * `feat(rivet): add module support`
  * `fix(forge): correct clang pcm path`
  * `docs: update forge.toml specification`

---

如果你愿意，我可以帮你写一个 **针对 C++ 包管理器项目的 Conventional Commits 示例模板**，包括 feat/fix/build/module/ci 等类型，直接可以套在你的 `forge` 或 `rivet` 项目里。

你希望我帮你写吗？
