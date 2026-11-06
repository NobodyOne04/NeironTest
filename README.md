# NeironTest

A single perceptron that learns to recognise one 3×5 black-and-white pattern
(the digit **6** in `Model/Data/example.txt`) and reject everything else.

```
1 1 1
1 0 0
1 1 1
1 0 1
1 1 1
```

## Build

**Visual Studio:** open `Model.sln` and build. The debugger's working
directory is `Model/`, so the default `-data Data` folder is found.

**CMake (any platform):**

```sh
cmake -B build && cmake --build build
./build/model -check -iter 10000 -data Model/Data
```

## Usage

```
model (-learn | -check) -iter N [-data DIR] [-v]
  -learn     train on N samples, then save weights to DIR/weight.txt
  -check     evaluate saved weights on N samples
  -iter N    number of samples
  -data DIR  folder with example.txt / weight.txt (default: Data)
  -v         (check) print every prediction
```

Every third sample is the pattern (answer `1`); the rest are random 15-pixel
images guaranteed to differ from it (answer `0`).

```
$ model -learn -iter 500000
No saved weights, starting from zero
Iterations: 500000, corrections: 133 (last at iteration 76368)
Weights: 2 2 2 2 -5 -5 3 2 1 2 -4 1 1 4 2
Threshold: 24

$ model -check -iter 300000
Accuracy:  100.00% (300000/300000)
  pattern: 100.00% (100000/100000)
  noise:   100.00% (200000/200000)
```

Delete `weight.txt` to train from scratch; otherwise `-learn` continues from
the saved weights.

## How it works

`prediction = sum(x[i] * w[i]) >= threshold`. On a wrong answer the weights of
active inputs move by ±1 and the threshold moves the opposite way (classic
perceptron rule). The threshold has to be learned: with a fixed threshold the
"6" can't be separated from images missing a single pixel.

`weight.txt` format: input count, the weights, then the threshold. Files
without a threshold line are still accepted (threshold defaults to 9).

| File | Role |
|---|---|
| `Model/Model.cpp` | command-line parsing |
| `Model/BaseClass/Base.cpp` | weights, summation, prediction, sample selection |
| `Model/Mode/Learn.cpp` | training |
| `Model/Mode/Check.cpp` | evaluation |
| `Model/WorkWithData/File.cpp` | reading/writing data files |
| `Model/Operation/Randome.cpp` | random noise samples |
