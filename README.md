# learn-c-big-o

CLI program that takes a function f(n) as a list of terms and figures out its Big-O, plus the c and n0 that prove it.

## Big-O, quickly

f(n) is O(g(n)) if there's a constant c and a starting point n0 where:

```
f(n) <= c * g(n)   for all n >= n0
```

Past n0, g(n) (times some constant) caps how fast f(n) grows. Common classes: O(1), O(log n), O(n), O(n log n), O(n²).

## Input format

Each term is 3 numbers: coefficient, power of n, and whether it has a log n factor (1/0).

Term x :(coefficient, power of n, has log-n)

E.g.
`2n + 5 + 3log n` is 3 terms: `2 1 0`, `5 0 0`, `3 0 1`.

## Example

```
$ ./learn-c-big-o
How many terms are in the function: 3
Term 1 - coefficient: 2
Term 1 - power of n: 1
Term 1 - is log n (1/0): 0
Term 2 - coefficient: 5
Term 2 - power of n: 0
Term 2 - is log n (1/0): 0
Term 3 - coefficient: 3
Term 3 - power of n: 0
Term 3 - is log n (1/0): 1

=====================================
 Big-O Classification:  O(n)
 c  (constant factor):  10.00
 n0 (valid starting n): 2
=====================================
 f(n) <= 10.00 * n   for all n >= 2
=====================================
```

## Build

```bash
gcc -Wall -o learn-c-big-o learn-c-big-o.c
./learn-c-big-o
```

## Notes

- `n log n` support is limited to power 1; higher powers with log n get downgraded with a warning.
- Negative coefficients don't add to c, since a negative term only shrinks f(n) and can't break the upper bound.
