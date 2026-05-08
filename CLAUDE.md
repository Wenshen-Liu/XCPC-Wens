# XCPC Codebase

Competitive programming (XCPC/ICPC/CCPC) practice, contest solutions, and algorithm templates. BUAA student.

## Directory Structure

| Directory | Purpose |
|---|---|
| `platforms/` | Online judge practice (codeforces, luogu) |
| `contests/` | ICPC regional / on-site contest solutions |
| `training/` | Team training sessions (seasonal contests) |
| `coursework/` | BUAA data structures course assignments (C language) |
| `templates/` | Reusable algorithm templates and 知识点 knowledge base |
| `references/` | PDF references, courseware, template books |
| `reviews/` | Code reviews for classmates (NOT teammates) |
| `scratch/` | Temporary / throwaway code |
| `tool/` | Utility tools |

## Coding Conventions

- C++17 with GCC, `#include <bits/stdc++.h>`, `using namespace std`
- Fast I/O: custom `read()`/`write()` in `templates/快读输.cpp`
- Optimization pragmas: `templates/火车头.cpp`
- `typedef long long ll;` — not `#define int long long`
- Contest problems named A.cpp-H.cpp per round directory
- Constant `Maxn` for array sizing; `N`, `M` for graph problems
- `inline` on short functions (competitive habit, not always beneficial)

## Build & Run

```bash
g++ -std=c++17 -O2 -Wall -o /tmp/prog file.cpp && /tmp/prog < input.in
```

No build system — single-file compilation is the CP convention.

## Knowledge Base (templates/知识点/)

Organized by topic:
- 数据结构 — Segment tree, BIT, Splay, HLD, Sparse table, Block decomposition
- 图论 — Network flow (Dinic/EK/FF), Bipartite matching, SCC/Tarjan, MST, LCA, Shortest path
- 数论 — Fast pow, Modular inverse, CRT/exCRT, Gaussian elimination, Game theory, Combinatorics
- 动态规划 — Slope optimization, Expectation DP, Tree DP, Digit DP, Interval DP
- 字符串 — KMP, Aho-Corasick, Manacher

## Notes

- LiJiaXuan code in `reviews/` is for HELPING a classmate — not a teammate's work
- Do not commit backup copies or duplicate directories — use git branches
- `zcopy.cpp` and `output/` are gitignored as artifacts
