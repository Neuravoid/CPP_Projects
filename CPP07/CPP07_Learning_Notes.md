# CPP07 — C++ Templates: Learning Notes

Personal reference notes from working through CPP07 (ex00–ex02). Code samples
here are toy/generic examples used to explain each concept — not copies of the
actual exercise solutions.

---

## 1. What a function template actually is

Without templates, supporting multiple types means hand-writing near-identical
overloads:

```cpp
int addTwo(int a, int b) { return a + b; }
double addTwo(double a, double b) { return a + b; }
```

A function template writes the logic **once**, with a placeholder type:

```cpp
template <typename T>
T addTwo(T a, T b)
{
    return a + b;
}
```

`template <typename T>` declares "this takes a placeholder type `T`." When you
call `addTwo(3, 4)`, the compiler looks at the argument types, deduces `T = int`,
and **instantiates** (generates, at compile time) a real `addTwo<int>` function.
Call it again with doubles and it generates a separate `addTwo<double>`. You
write the logic once; the compiler stamps out copies per type, only for the
types you actually use.

### Operators aren't magic — they're just functions with symbols for names

`a + b` works for `int` because the compiler has built-in support for it.
For a user type, `+` only works if someone wrote `operator+` for it:

```cpp
struct Money { int cents; };
Money operator+(Money a, Money b) { Money r; r.cents = a.cents + b.cents; return r; }
```

A template that does `a + b` internally doesn't define what `+` means — it
just **trusts** that whatever `T` ends up being, `T`'s `+` already exists
somewhere (built into the language for primitives, or overloaded by a class
author for user types). This is why exercises like `min`/`max` require "the
two arguments must support all comparison operators" — the template's body
uses `<`/`>`/`==`, and needs those to already be defined for whatever `T` is.

### Pass by value vs. by reference

```cpp
void increment(int x) { x = x + 1; }        // x is a COPY — caller unaffected
void incrementRef(int &x) { x = x + 1; }     // x IS the caller's variable, aliased
```

A reference isn't a copy — it's another name for the same memory. Changes
through it are changes to the original.

### Explicit template argument specification

Normally the compiler deduces template types from your arguments. You can
also tell it directly instead of relying on deduction:

```cpp
template <typename T, typename F, typename K>
void doSomething(T a, F f, K b);

doSomething<int, void, std::string>(5, someFunc, "hi");
//           ^T    ^F     ^K
```

This matters when template parameters are **independent** (not all tied
together through the function's own parameter types) — the compiler may not
have enough information to guess them from the call alone, especially when
one of the arguments (like a function pointer) is itself the address of
*another* template, which can't be resolved without knowing the target type
first.

---

## 2. Function pointers vs. `void*`

A `void*` is "a pointer to some memory, unknown type" — the compiler can't
call through it, doesn't know its signature, nothing.

```cpp
void shout(std::string s) { std::cout << s << "!!!"; }

void callTwice(void (*action)(std::string), std::string msg)
{
    action(msg);
    action(msg);
}
```

`void (*action)(std::string)` = "pointer to a function taking a `std::string`,
returning `void`." This tells the compiler the exact shape needed to actually
call the function safely.

### Taking the address of a template function

If `shout` were itself a template (`template<typename T> void shout(T s)`),
`&shout` alone is ambiguous — a template isn't one function, it's a blueprint;
nothing tells the compiler which instantiation you mean. It can only be
resolved if the surrounding context provides a concrete target type to match
against (e.g. a parameter typed `void(*)(std::string)` lets the compiler pick
`shout<std::string>`). If the target parameter is just `void*`, there's no
type information at all, and deduction fails outright.

### Decoupling a function's own type instead of hardcoding its shape

```cpp
template <typename T, typename F>
void applyOnce(T value, F func) { func(value); }
```

Two *independent* template parameters: `F` is deduced fresh from whatever
callable is actually passed — not constrained to a pre-declared shape like
`void(*)(T&)`. This is what allows one generic function to accept callbacks
that take their argument by value, by `const&`, or by non-`const&`, without
the caller needing to match one fixed signature.

### Array parameters

Arrays decay to pointers when passed as function parameters:

```cpp
int nums[] = {1,2,3};    // T ref[] parameter  -> decays to T*  (pointer to int)
int *ptrs[3];              // T* ref[] parameter -> "array of pointers", decays to T**
int (*p)[3];                 // pointer to a whole array of 3 ints — a different type entirely
```

`&arr` (address of the whole array object) is **not** the same type as `arr`
used bare (which decays to a pointer to the first element). Function
parameters expecting "the address of an array" want the latter.

---

## 3. Class templates

Same blueprint idea as function templates, but for a whole class — every
member variable, constructor, and method can use the placeholder type.

```cpp
template <typename T>
class Box
{
    private:
        T value;
    public:
        Box(T v);
        T getValue() const;
};
```

### Defining members outside the class body

Every out-of-class definition needs `template <typename T>` repeated, and the
name scoped with `Box<T>::`:

```cpp
template <typename T>
Box<T>::Box(T v) : value(v) {}

template <typename T>
T Box<T>::getValue() const { return value; }
```

Constructors follow the same pattern — no return type, ever, name repeated:

```cpp
template <typename T>
Box<T>::Box() { }
```

### The injected class name

*Inside* a class template's own scope (inside the body, or after `Box<T>::`
has already appeared), the bare name `Box` is understood to mean `Box<T>`.
But a return type written *before* the `Box<T>::` qualifier is **not** yet in
that scope:

```cpp
Box<T>& Box<T>::operator=(const Box<T>& other) { ... }   // correct
Box&    Box<T>::operator=(const Box& other) { ... }        // WRONG — return type
                                                              // needs <T> explicitly
```

### No class template argument deduction in C++98

Unlike function templates, **class templates never deduce their type
parameter automatically pre-C++17** (CTAD is a C++17 feature; irrelevant when
compiling `-std=c++98`). You must always write it explicitly:

```cpp
Box<int> b(5);        // correct
Box b(5);                // ERROR: "argument list for class template Box is missing"
```

Also: `T` only has meaning **inside** the template definition. Outside it
(e.g. in `main`), `T` is not a real type — you must substitute an actual
concrete type name in the angle brackets.

---

## 4. References, lvalues, and `operator[]`

### What makes something assignable (an "lvalue")

```cpp
int nums[3] = {1,2,3};

int getCopy(int idx) { return nums[idx]; }     // returns a temporary COPY
int &getRef(int idx) { return nums[idx]; }      // returns a REFERENCE (an alias)

getCopy(0) = 99;   // ERROR: lvalue required — assigning into a temporary
getRef(0) = 99;      // OK — really modifies nums[0]
```

A function returning by value hands back a temporary; assigning into that
temporary is meaningless to the compiler. A function returning by reference
hands back an alias to the real storage — assignment through it is real.

This is exactly why `operator[]` on a custom container needs to return `T&`
(not `T`, and not `T*`) if you want `myContainer[i] = value;` to work:

```cpp
// operator[] is sugar: myArray[2] is rewritten by the compiler as
// myArray.operator[](2)
T& operator[](int index);
```

### `const` correctness on member functions

A member function that promises not to modify the object needs `const` after
its parameter list — this is an enforceable compiler contract, not just a
comment:

```cpp
int size() const { return _size; }
```

---

## 5. Exceptions: `throw` is not tied to `try`

A common misconception: `throw` needs to live inside a `try` block. It
doesn't. Think of it as a smoke detector (`throw`, wherever a problem is
*detected*) and a fire extinguisher (`try`/`catch`, wherever the problem is
*handled*) — usually in different functions entirely.

```cpp
void checkValue(int x)
{
    if (x < 0)
        throw std::exception();     // no try/catch here at all
    std::cout << "ok: " << x;
}

int main()
{
    try
    {
        checkValue(5);
        checkValue(-1);                // throws here
        std::cout << "never reached";   // skipped
    }
    catch (const std::exception &e)
    {
        std::cout << "caught: " << e.what();
    }
}
```

`checkValue` has zero `try`/`catch` — it just detects and throws. Execution
jumps straight out of it to the nearest matching `catch`, skipping everything
in between.

**Important:** raw array/pointer out-of-bounds access does **not**
automatically throw anything in C++ — it's undefined behavior (might crash,
might silently return garbage). Bounds checking + `throw` has to be written
manually; wrapping the raw access in a `try`/`catch` inside the same function
catches nothing, because nothing was ever thrown.

---

## 6. Deep copy vs. shallow copy

When a class holds a pointer member, copying the *pointer* is very different
from copying the *data it points to*:

```cpp
class Holder
{
    int *data;
    public:
        // shallow — WRONG for most cases: both objects now share one buffer
        Holder(const Holder &other) { data = other.data; }

        // deep — allocates its own buffer, copies contents over
        Holder(const Holder &other)
        {
            data = new int[SIZE];
            for (int i = 0; i < SIZE; i++)
                data[i] = other.data[i];
        }
};
```

With a shallow copy, mutating one object's data mutates the "other" object
too (they're the same memory), and both destructors will eventually try to
`delete` the same pointer — a double free.

**Copy constructor vs. `operator=` aren't interchangeable via simple delegation:**
a copy constructor builds a *brand-new* object — none of its members have
valid values yet, so it can't safely reuse assignment logic that assumes
`this` already has a valid, correctly-sized buffer to write into. It needs to
allocate first.

**`operator=` must also handle differently-sized sources** — if it reuses
`this`'s old size/buffer as a loop bound instead of the incoming object's,
assigning a bigger object into a smaller one silently truncates instead of
actually copying everything.

---

## 7. A sharp gotcha: templates aren't checked until instantiated

Non-template code is fully type-checked every time you compile it. **A
template's member/function body is only checked once it's actually used**
with some concrete type. This means genuinely broken code inside a template
(e.g. an invalid line like `this = someReference;`) can sit there compiling
"successfully" indefinitely if nothing in the program ever calls that
particular function — the compiler never had a reason to look closely at it.

This is exactly why exercises explicitly require you to submit `main.cpp`
with real tests: an untested code path in a template class can hide a fully
broken implementation behind a clean compile.

---

## 8. Quick checklist this module kept coming back to

- [ ] Templates (function *and* class) must be defined in the header — only
      non-template helper functions belong in `.cpp` files.
- [ ] Class template instantiations always need explicit `<Type>` in C++98 —
      no deduction.
- [ ] Return type before `ClassName<T>::` needs `<T>` explicitly too.
- [ ] `operator[]` returning by value ≠ assignable; needs `T&` for mutation.
- [ ] Raw array/pointer bounds are never checked automatically — manual
      `if` + `throw`, no `try`/`catch` needed at the detection site.
- [ ] Copy constructor and `operator=` need actual deep copies when the class
      owns a pointer — and each needs to handle allocation/sizing correctly
      for its own situation (brand-new object vs. an existing one that might
      be a different size).
- [ ] Every `new[]` needs a matching `delete[]`, normally in the destructor.
- [ ] `const` on a member function is an enforced promise, not decoration.
- [ ] A clean compile does **not** prove a template class works — only
      actually calling every member function (in your own `main.cpp` tests)
      does.
