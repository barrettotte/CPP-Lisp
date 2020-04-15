# CPP-Lisp

Screwing around with C++ to learn more about lisp, refresh on a bit of C++, and make a basic lisp interpreter.
Specifically, this is a Scheme interpreter (a minimalist dialect of lisp).

I used [Make a Lisp(MAL)](https://github.com/kanaka/mal) as a general guide, but somewhat went off course in implementation.


## Why...does the code...look like...that?
So, I'm definitely not a C++ programmer. This is a completely bastardized C++ implementation.
C++ was one of the first languages I started with, but I never went too deep into modern C++ or OOP.

I really did start out trying to use proper OOP concepts (polymorphism, inheritance, etc), but
after screwing around for a couple coding sessions I threw my hands in the air.
Namely, I was fighting with dynamic casting objects...it could have been something silly.

I decided it would be a lot more fun to do this off of "pure instinct" instead.
What it produced was a janky object hierarchy and some stuff that should be limited to C.

One day I do hope to come back and strengthen up my C++ OOP...



## Notes on Scheme
* Scheme programs only contain expressions.
* Atoms - numbers/symbols -> they cannot be broken into smaller pieces.
* Everything else is a list expression. ```'(' expression* ')'```
  * list[0] is keyword, special form. ```(if ...)```
  * list[0] is non-keyword, function call. ```(fn ...)```
* symbols ending in '!' - function that mutates something else



## References
* Lispy - http://norvig.com/lispy.html
* Make a Lisp - https://github.com/kanaka/mal
* Fascinating background - https://en.wikipedia.org/wiki/Scheme_(programming_language)
