# Dynamic Programming
---

## 0. DP Foundations

- [x] What is Dynamic Programming?
- [ ] Optimal substructure
- [ ] Overlapping subproblems
- [ ] State definition
- [ ] Transition definition
- [ ] Base cases
- [ ] State-space design
- [ ] Top-down DP / Memoization
- [ ] Bottom-up DP / Tabulation
- [ ] Choosing iteration order
- [ ] Space optimization
- [ ] Reconstructing the optimal solution
- [ ] Counting vs optimization vs decision DP
- [ ] Recognizing when DP is applicable
- [ ] DAG interpretation of DP
- [ ] DP complexity analysis

---

# 1. Linear / 1D DP

## 1.1 Basic Linear DP
- [ ] Fibonacci-style DP
- [ ] Climbing stairs
- [ ] Min/max cost on a line
- [ ] Prefix DP
- [ ] Suffix DP
- [ ] DP using previous 2 states
- [ ] DP using previous k states

## 1.2 Take / Skip DP
- [ ] Take-or-skip
- [ ] House Robber
- [ ] Non-adjacent selection
- [ ] Weighted selection
- [ ] Take/skip with additional state

## 1.3 Jump DP
- [ ] Fixed jumps
- [ ] Variable jumps
- [ ] Bounded jump distance
- [ ] Minimum jumps
- [ ] Number of ways to reach position

## 1.4 Advanced 1D Variants
- [ ] Cooldown DP
- [ ] Limited transitions
- [ ] Multiple state variables
- [ ] Prefix/suffix interaction
- [ ] DP + greedy observation

---

# 2. Grid / 2D DP

## 2.1 Basic Grid DP
- [ ] Unique paths
- [ ] Grid path counting
- [ ] Minimum path sum
- [ ] Maximum path sum
- [ ] Obstacles
- [ ] Different movement directions

## 2.2 Grid State Variants
- [ ] Grid with rewards
- [ ] Grid with costs
- [ ] Grid with keys/doors
- [ ] Grid with limited resources
- [ ] Grid with state-dependent movement
- [ ] 3D grid DP

## 2.3 Multi-Agent Grid DP
- [ ] Two-agent DP
- [ ] Simultaneous movement
- [ ] Cherry Pickup-style DP
- [ ] State compression for multiple agents

---

# 3. Knapsack DP

## 3.1 0/1 Knapsack
- [ ] Basic 0/1 knapsack
- [ ] Maximum value
- [ ] Minimum cost
- [ ] Exact capacity
- [ ] At-most capacity
- [ ] 1D space optimization

## 3.2 Unbounded Knapsack
- [ ] Unlimited items
- [ ] Coin Change — minimum coins
- [ ] Coin Change — number of ways
- [ ] Rod Cutting

## 3.3 Bounded / Multiple Knapsack
- [ ] Limited quantity
- [ ] Multiple copies
- [ ] Bounded knapsack optimization

## 3.4 Knapsack Variants
- [ ] Subset Sum
- [ ] Partition Equal Subset Sum
- [ ] Target Sum
- [ ] 0/1 counting DP
- [ ] Exact sum DP
- [ ] Resource allocation
- [ ] Multi-dimensional knapsack
- [ ] Knapsack + another state

---

# 4. Subsequence DP

## 4.1 LIS Family
- [ ] Longest Increasing Subsequence
- [ ] Longest Decreasing Subsequence
- [ ] Maximum Sum Increasing Subsequence
- [ ] Number of LIS
- [ ] Longest Bitonic Subsequence
- [ ] Weighted LIS
- [ ] LIS with constraints
- [ ] O(n log n) LIS

## 4.2 LCS Family
- [ ] Longest Common Subsequence
- [ ] Longest Common Substring
- [ ] Shortest Common Supersequence
- [ ] Sequence alignment
- [ ] LCS reconstruction

## 4.3 Subsequence Counting
- [ ] Count subsequences
- [ ] Count occurrences of a target subsequence
- [ ] Count distinct subsequences
- [ ] Pattern subsequence counting

---

# 5. String DP

## 5.1 Edit / Transformation DP
- [ ] Edit Distance
- [ ] Insertions
- [ ] Deletions
- [ ] Replacements
- [ ] Minimum insertions/deletions
- [ ] Weighted edit distance

## 5.2 Palindrome DP
- [ ] Palindrome detection DP
- [ ] Longest Palindromic Substring
- [ ] Longest Palindromic Subsequence
- [ ] Count Palindromic Substrings
- [ ] Minimum insertions to palindrome
- [ ] Minimum deletions to palindrome
- [ ] Palindrome partitioning
- [ ] Minimum palindrome cuts

## 5.3 String Construction / Matching
- [ ] Word Break
- [ ] Decode Ways
- [ ] Interleaving String
- [ ] Wildcard Matching
- [ ] Regex-style matching
- [ ] String construction DP

---

# 6. Interval / Range DP

## 6.1 Basic Interval DP
- [ ] State `dp[l][r]`
- [ ] Expanding interval
- [ ] Shrinking interval
- [ ] Split interval at k

## 6.2 Classic Problems
- [ ] Matrix Chain Multiplication
- [ ] Burst Balloons
- [ ] Merge Stones
- [ ] Polygon Triangulation
- [ ] Optimal Binary Search Tree

## 6.3 Advanced Interval DP
- [ ] Interval + game theory
- [ ] Interval + palindrome
- [ ] Interval merging
- [ ] Range partitioning
- [ ] Interval DP with reconstruction
- [ ] Interval DP optimization

---

# 7. Partition DP

## 7.1 Basic Partition DP
- [ ] Partition array into groups
- [ ] Partition string
- [ ] Partition into exactly k groups
- [ ] Partition into at most k groups
- [ ] Minimum partition cost
- [ ] Maximum partition score

## 7.2 Standard Transition
- [ ] `dp[i][k]` formulation
- [ ] Split at j
- [ ] Precompute segment cost
- [ ] Reconstruct partitions

## 7.3 Advanced Partition DP
- [ ] Partition DP + prefix sums
- [ ] Partition DP + D&C optimization
- [ ] Partition DP + Knuth optimization
- [ ] Partition DP + Monge structure

---

# 8. Tree DP

## 8.1 Basic Tree DP
- [ ] Subtree DP
- [ ] Parent-child DP
- [ ] Rooted tree DP
- [ ] Tree maximum/minimum
- [ ] Tree counting

## 8.2 Classic Tree DP
- [ ] Maximum Independent Set on Tree
- [ ] Tree Matching
- [ ] Tree Coloring
- [ ] Tree Diameter DP
- [ ] Subtree size DP
- [ ] Depth-based DP

## 8.3 Tree Knapsack
- [ ] Tree + knapsack
- [ ] Subtree resource allocation
- [ ] Merging child DP tables
- [ ] Small-to-large style merging

## 8.4 Rerooting DP
- [ ] Rerooting concept
- [ ] Downward DP
- [ ] Upward DP
- [ ] All-roots answers
- [ ] Sum of distances
- [ ] Best root
- [ ] Tree eccentricity
- [ ] Rerooting with custom state

---

# 9. DAG / Graph DP

## 9.1 DAG DP
- [ ] Topological ordering
- [ ] Longest path in DAG
- [ ] Shortest path in DAG
- [ ] Number of paths
- [ ] Maximum path sum
- [ ] Dependency scheduling

## 9.2 Graph State DP
- [ ] DP over graph states
- [ ] State graph construction
- [ ] BFS + DP
- [ ] DFS + memoization
- [ ] DAG after state transformation

## 9.3 Advanced Graph DP
- [ ] SCC condensation + DP
- [ ] DP on condensed DAG
- [ ] Path counting with constraints
- [ ] Graph DP + bitmask

---

# 10. Bitmask DP

## 10.1 Basic Bitmask State
- [ ] Bit representation of sets
- [ ] Add/remove element
- [ ] Check membership
- [ ] Enumerate subsets
- [ ] Enumerate submasks

## 10.2 Classic Bitmask DP
- [ ] TSP
- [ ] Hamiltonian Path
- [ ] Visit-all problems
- [ ] Assignment problems
- [ ] Minimum cost matching
- [ ] Scheduling with subsets

## 10.3 Advanced Bitmask DP
- [ ] `dp[mask]`
- [ ] `dp[mask][last]`
- [ ] Bitmask + graph
- [ ] Bitmask + shortest path
- [ ] Bitmask + counting
- [ ] Bitmask + optimization

---

# 11. Digit DP

## 11.1 Core Digit DP
- [ ] Position state
- [ ] Tight flag
- [ ] Started / leading-zero flag
- [ ] Base cases
- [ ] Counting numbers from 0 to N

## 11.2 Digit Constraints
- [ ] Digit sum
- [ ] Digit count
- [ ] No repeated digits
- [ ] Adjacent digit restrictions
- [ ] Digit frequency
- [ ] Number divisibility
- [ ] Modulo state
- [ ] Digit XOR
- [ ] Digit AND/OR properties

## 11.3 Advanced Digit DP
- [ ] Digit DP + bitmask
- [ ] Digit DP + automaton
- [ ] Digit DP + modulo
- [ ] Digit DP + multiple constraints
- [ ] Range queries using `F(R) - F(L-1)`

---

# 12. Probability DP

## 12.1 Probability State DP
- [ ] Probability of reaching a state
- [ ] Probability of success
- [ ] Probability of failure
- [ ] Probability distribution DP

## 12.2 Random Walk DP
- [ ] 1D random walk
- [ ] 2D random walk
- [ ] Absorbing states
- [ ] Hitting probability
- [ ] Markov-style transitions

## 12.3 Dice / Random Events
- [ ] Dice DP
- [ ] Multiple random events
- [ ] Probability of reaching target
- [ ] Probability of exact sum

---

# 13. Expected Value / Stochastic DP

## 13.1 Expected Value
- [ ] Expected score
- [ ] Expected number of steps
- [ ] Expected cost
- [ ] Expected time
- [ ] Linearity of expectation in DP

## 13.2 Stochastic Transitions
- [ ] Random transition states
- [ ] Expected DP recurrence
- [ ] Random + deterministic transitions
- [ ] Absorbing expected-value DP

## 13.3 Optimal Decisions + Randomness
- [ ] Max + expectation
- [ ] Min + expectation
- [ ] Optimal stopping
- [ ] Stochastic decision processes

---

# 14. Game Theory DP

## 14.1 Win / Lose
- [ ] Win/Lose state
- [ ] Winning move
- [ ] Losing state
- [ ] Impartial games
- [ ] Take-away games
- [ ] Nim basics

## 14.2 Minimax
- [ ] Maximize score difference
- [ ] Max/min recurrence
- [ ] Actual-score minimax
- [ ] Maximin
- [ ] Optimal opponent assumption

## 14.3 Game Outcomes
- [ ] Win / Lose / Draw
- [ ] Cyclic game states
- [ ] Game graphs
- [ ] Retrograde analysis

## 14.4 Game Variants
- [ ] Stone games
- [ ] Interval games
- [ ] Grid games
- [ ] Resource games
- [ ] Partizan games
- [ ] Multi-player games

## 14.5 Stochastic Games
- [ ] Game + probability
- [ ] Minimax + expectation
- [ ] Stochastic game states
- [ ] Random + optimal decisions

---

# 15. State Machine DP

## 15.1 Basic State Machine
- [ ] Identify states
- [ ] State transitions
- [ ] Transition graph
- [ ] State compression

## 15.2 Stock DP
- [ ] Buy / sell
- [ ] Unlimited transactions
- [ ] At most k transactions
- [ ] Cooldown
- [ ] Transaction fee
- [ ] Multiple holding states

## 15.3 General State Machines
- [ ] Finite-state DP
- [ ] Mode-switching
- [ ] Resource state
- [ ] Multiple discrete states
- [ ] State machine + string
- [ ] State machine + counting

---

# 16. Automaton DP

## 16.1 Basic Automaton
- [ ] Finite automaton
- [ ] State transitions
- [ ] DP over automaton states

## 16.2 String Automata
- [ ] KMP automaton + DP
- [ ] Aho-Corasick + DP
- [ ] Forbidden patterns
- [ ] Required patterns
- [ ] Pattern counting

## 16.3 Advanced
- [ ] Automaton + digit DP
- [ ] Automaton + bitmask
- [ ] Multiple pattern constraints
- [ ] Automaton state minimization

---

# 17. Subset / Set DP

## 17.1 Subset DP
- [ ] `dp[mask]`
- [ ] Subset enumeration
- [ ] Submask enumeration
- [ ] Superset enumeration

## 17.2 SOS DP
- [ ] Sum Over Subsets DP
- [ ] Sum Over Supersets DP
- [ ] Zeta Transform
- [ ] Möbius Transform

## 17.3 Advanced Set DP
- [ ] Subset convolution
- [ ] Set partition
- [ ] Set cover
- [ ] Minimum subset cost
- [ ] Counting subset configurations

---

# 18. Profile / Broken-Profile DP

## 18.1 Core
- [ ] Frontier representation
- [ ] Bitmask profile
- [ ] Row-by-row processing
- [ ] Transition generation

## 18.2 Applications
- [ ] Domino tiling
- [ ] Grid filling
- [ ] Independent sets on narrow grids
- [ ] Grid coloring
- [ ] Connectivity constraints

## 18.3 Advanced
- [ ] Profile DP + counting
- [ ] Profile DP + optimization
- [ ] Profile DP with multiple states
- [ ] Profile compression

---

# 19. Matrix / Linear Recurrence DP

## 19.1 Linear Recurrence
- [ ] Fibonacci
- [ ] k-th order recurrence
- [ ] Multiple-state recurrence
- [ ] Matrix representation

## 19.2 Matrix Exponentiation
- [ ] Matrix multiplication
- [ ] Fast exponentiation
- [ ] DP recurrence → matrix
- [ ] O(log N) recurrence computation

## 19.3 Graph Applications
- [ ] Number of walks
- [ ] Fixed-length paths
- [ ] Adjacency matrix DP
- [ ] Graph transition matrices

---

# 20. DP Optimization

## 20.1 Basic Optimization
- [ ] Prefix sums
- [ ] Prefix minimum
- [ ] Prefix maximum
- [ ] Suffix optimization
- [ ] Sliding window optimization
- [ ] Monotonic deque

## 20.2 Divide & Conquer Optimization
- [ ] D&C DP optimization
- [ ] Monotone opt property
- [ ] Transition optimization
- [ ] Complexity analysis

## 20.3 Convex Hull Trick
- [ ] Line interpretation
- [ ] Minimum query
- [ ] Maximum query
- [ ] Monotonic slopes
- [ ] Monotonic queries
- [ ] Li Chao Tree

## 20.4 Knuth Optimization
- [ ] Knuth conditions
- [ ] Optimal split monotonicity
- [ ] Interval DP optimization

## 20.5 Monge / Quadrangle Optimization
- [ ] Monge arrays
- [ ] Quadrangle inequality
- [ ] Monotone minima
- [ ] SMAWK connection

---

# 21. Advanced DP Techniques

## 21.1 DP + Data Structures
- [ ] DP + Fenwick Tree
- [ ] DP + Segment Tree
- [ ] DP + Sparse Table
- [ ] DP + Ordered Set
- [ ] DP + Heap
- [ ] DP + Monotonic Queue

## 21.2 DP + Graph Algorithms
- [ ] DP + BFS
- [ ] DP + DFS
- [ ] DP + Dijkstra
- [ ] DP + SCC
- [ ] DP + Topological Sort
- [ ] DP + Shortest Path

## 21.3 DP + Binary Search
- [ ] Binary search on DP answer
- [ ] DP feasibility check
- [ ] Parametric optimization
- [ ] DP + coordinate compression

## 21.4 DP + Bitset
- [ ] Bitset subset sum
- [ ] Bitset reachability
- [ ] Bitset optimization
- [ ] Bitset acceleration

---

# 22. Hybrid DP Patterns

## 22.1 Common Combinations
- [ ] Tree DP + Knapsack
- [ ] Tree DP + Rerooting
- [ ] Tree DP + Bitmask
- [ ] Graph DP + Bitmask
- [ ] DAG DP + Counting
- [ ] Interval DP + Game Theory
- [ ] String DP + Automaton
- [ ] Digit DP + Automaton
- [ ] Digit DP + Bitmask
- [ ] Probability DP + Game Theory
- [ ] State Machine + Probability
- [ ] Knapsack + Bitmask
- [ ] Grid DP + Bitmask
- [ ] Profile DP + Bitmask
- [ ] DP + Segment Tree
- [ ] DP + Convex Hull Trick

---

# 23. DP Reconstruction

- [ ] Reconstruct maximum/minimum solution
- [ ] Reconstruct chosen items
- [ ] Reconstruct path
- [ ] Reconstruct subsequence
- [ ] Reconstruct partition
- [ ] Reconstruct game strategy
- [ ] Parent-pointer reconstruction
- [ ] Lexicographically smallest optimal solution
- [ ] Lexicographically largest optimal solution

---

# 24. DP State Compression

- [ ] Remove redundant dimensions
- [ ] Rolling arrays
- [ ] Previous/current row
- [ ] Previous/current layer
- [ ] Derive one state variable from others
- [ ] Compress boolean states
- [ ] Bitmask state compression
- [ ] Sparse state representation

---

# 25. DP Counting

## 25.1 Basic Counting
- [ ] Count paths
- [ ] Count ways
- [ ] Count configurations
- [ ] Count partitions

## 25.2 Advanced Counting
- [ ] Counting modulo M
- [ ] Inclusion-exclusion + DP
- [ ] DP + combinatorics
- [ ] Distinct configuration counting
- [ ] Avoiding overcounting
- [ ] Counting with symmetry

---

# 26. DP with Constraints

- [ ] Capacity constraints
- [ ] Time constraints
- [ ] Number-of-operations constraints
- [ ] At-most-k constraints
- [ ] Exactly-k constraints
- [ ] Modulo constraints
- [ ] Parity constraints
- [ ] Adjacency constraints
- [ ] Distance constraints
- [ ] Resource constraints
- [ ] Multiple simultaneous constraints

---

# 27. DP Problem-Solving Meta-Skills

- [ ] Identify whether DP is needed
- [ ] Find the smallest sufficient state
- [ ] Define state in one sentence
- [ ] Derive transition mathematically
- [ ] Identify base cases
- [ ] Determine dependency direction
- [ ] Choose top-down vs bottom-up
- [ ] Estimate time complexity before coding
- [ ] Estimate memory complexity before coding
- [ ] Find redundant state dimensions
- [ ] Optimize transitions
- [ ] Prove correctness
- [ ] Handle edge cases
- [ ] Reconstruct the solution
- [ ] Recognize hybrid patterns
- [ ] Recognize DP hidden inside other problems
- [ ] Convert recursive search to DP
- [ ] Convert DP to graph interpretation
- [ ] Identify equivalent DP formulations

---

# 28. Expert DP Checklist

- [ ] Can derive a DP state from a new problem
- [ ] Can derive transitions without seeing the pattern before
- [ ] Can recognize multiple valid state formulations
- [ ] Can choose the simplest formulation
- [ ] Can optimize memory
- [ ] Can optimize transitions
- [ ] Can prove recurrence correctness
- [ ] Can recognize when DP is NOT appropriate
- [ ] Can combine multiple DP patterns
- [ ] Can recognize hidden DAG structure
- [ ] Can recognize state-machine structure
- [ ] Can recognize min/max/count/probability variants
- [ ] Can recognize game-theoretic DP
- [ ] Can recognize digit/state/automaton combinations
- [ ] Can handle DP with data structures
- [ ] Can handle advanced DP optimization
- [ ] Can derive unfamiliar DP under contest pressure

---

# Suggested Mastery Levels

## Level 1 — Foundation
- [ ] 1D DP
- [ ] Grid DP
- [ ] Basic Knapsack
- [ ] Basic Take/Skip
- [ ] Basic State Machine

## Level 2 — Core
- [ ] LIS
- [ ] LCS
- [ ] String DP
- [ ] Interval DP
- [ ] Partition DP
- [ ] DAG DP

## Level 3 — Strong
- [ ] Tree DP
- [ ] Rerooting DP
- [ ] Bitmask DP
- [ ] Digit DP
- [ ] Game Theory DP
- [ ] Probability DP

## Level 4 — Advanced
- [ ] Automaton DP
- [ ] Profile DP
- [ ] SOS DP
- [ ] Tree Knapsack
- [ ] Hybrid DP
- [ ] DP + Data Structures

## Level 5 — Expert
- [ ] Convex Hull Trick
- [ ] Li Chao Tree
- [ ] Divide & Conquer Optimization
- [ ] Knuth Optimization
- [ ] Monge Optimization
- [ ] Matrix Exponentiation
- [ ] Advanced hybrid DP
- [ ] Derive novel DP states independently
