FlashFill++: Scaling Programming by Example by Cutting to the Chase

https://dl.acm.org/doi/abs/10.1145/3546189.3549924

______________________________________________________________________________________________________

0. ABSTRACT

A key PBE strategy has been to restrict the search to a carefully designed small domain-specific language (DSL)
with eectively-invertible (EI) operators at the top and eectively-enumerable (EE) operators at the bottom.

______________________________________________________________________________________________________

1. INTRODUCTION

Programming-by-examples (PBE) applications range from:
- non-experts to author programs for spreadsheet data manipulation
- application creation in a low-code/no-code setting (data scientists with data wrangling tasks)
- and even automating professional developers repeated edits

A flagship application for PBE is that of string transformations, for
instance, converting ‘Alan Turing’ to ‘turing, alan’ — such tasks are very common

We focus on such string transformations, though our
technical contributions are more generally applicable to any grammar-based synthesis setting

The idea behind abstraction is that instead of computing the exact set of values that can be generated
(in either top-down or bottom-up strategy), we compute overapproximations of the sets of values.

In this paper, we present two novel techniques - cuts and precedence - to effectively address
the scalability challenges of PBE synthesis.

In general, we get a novel search strategy, middle-out synthesis, which uses cuts
to reduce the original PBE problem over a large DSL (with potentially non-EI and non-EE operators)
into simpler PBE problems over (smaller depth) sub-DSLs with only EI or only EE operators.

Our second key idea is to introduce precedence over operators in the grammar of domain-specific
languages.

We show that if the precedence is a series-parallel
partial order, then it can be encoded as an ordering on grammar rules to create a guarded DSL (gDSL)

______________________________________________________________________________________________________

2. OVERVIEW

These challenges were compiled in collaboration with two key industrial deployers of PBE:
the Microsoft Excel and the Microsoft PowerBI teams.

FlashFill++’s program is much more readable and its readability
is further improved by renaming variables using a pretrained large language model, as shown.

While generating readable code is challenging, the need is sorely felt in industrial PBE tools—
users are more likely to trust and use PBE tools if they produce idiomatic, readable code.

“don’t know what is going on there, so I don’t know if I
can trust it if I want to extend it to other tasks. I saw my examples were correctly transformed, but
because the code is hard to read, I would not be able to trust what it is doing”

- Multiple Target Languages:
	Apart from the obvious benefit, multiple target support can also help with learning:
	seeing the same program in multiple languages helps with cross-language knowledge transfer
	
- Date-Time and Numeric Transformations

- Extended Domain-Specific Language. The main strength of FlashFill++ compared to previous
systems is its expanded DSL containing over 40 operators, including 25 for just strings and the rest
for datetime and numbers, such as for rounding and bucketing.

- Cuts and Middle-Out Synthesis. Our new DSL contains several non-EI operators (required for
number and datetime operations) that inhibit use of a top-down synthesis strategy across those
operators.

stopped at page 8



