# Visualizing the Flow (CPP09-Ex01)

## Start Program:

- Action: btc.loadDatabase("data.csv");
- Result: Your program now knows the price of Bitcoin for every day from 2009 to 2022. It stores this in your std::map.
- Process Argument (av[1] / input.txt):
- Action: btc.processInput("input.txt");

## Logic:

- Read line from input.txt: "2011-01-03 | 3"
- Look up "2011-01-03" in map (which loaded from data.csv).
- Find price: 0.3.
- Math: 3 \* 0.3 = 0.9.
- Print: 0.9.

> Summary: Load data.csv so you have the answers. Read input.txt to get the questions.
