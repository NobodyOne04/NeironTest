# NeironTest

A single perceptron in C++17 that learns to recognise one 3×5 pattern (the digit 6) and reject
everything else. Usage and examples: `README.md`.

## Commands
```sh
cmake -B build && cmake --build build                    # builds ./build/model
./build/model -learn -iter 500000 -data Model/Data      # train, saves Model/Data/weight.txt
./build/model -check -iter 300000 -data Model/Data      # accuracy on fresh samples
```
Visual Studio: open `Model.sln` (debug working dir is `Model/`, so `-data Data` works).

## Layout
- `Model/Model.cpp`: command-line parsing (`-learn | -check`, `-iter`, `-data`, `-v`).
- `Model/BaseClass/Base.cpp`: weights, sum, prediction, sample selection.
- `Model/Mode/Learn.cpp` / `Check.cpp`: training / evaluation; `Model/Interfaces/*.h` the classes.
- `Model/WorkWithData/File.cpp`: reads `example.txt`, reads/writes `weight.txt`.
- `Model/Operation/Randome.cpp`: random 15-pixel noise that never equals the pattern.
- `Model/Data/`: `example.txt` (the pattern), `weight.txt` (trained weights, committed).
- `docs/adr/`: decision records (`.adr`), index in `docs/adr/README.md`.

## Conventions
- Read the ADR before changing a recorded decision; commit subjects carry its number.
- Builds with `-Wall -Wextra -Wpedantic` (MSVC `/W4 /utf-8`): keep it warning-free.
- `weight.txt` format: input count, weights, threshold; files without a threshold line must
  still load (threshold 9).
- Comments in the code are Russian (the original lab); keep new ones consistent with the file.
