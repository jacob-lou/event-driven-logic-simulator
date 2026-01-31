# Event-Driven Logic Simulator (C++)

An event-driven digital logic simulator written in C++.  
It parses a circuit description file, injects signal events, propagates changes through logic gates, and outputs a PlantUML-style timeline of wire states.

## Highlights
- Custom **m-ary heap** priority queue (`Heap<T, Comparator>`) used as the event scheduler
- Logic components:
  - `Wire` (0/1/X state)
  - `Gate` base class + `AND2`, `OR2`, `NOT`
  - `Event {time, wire, state}`
  - `Circuit` that advances simulation time and triggers gate updates
- Additional DS/recursion utilities:
  - `Stack<T>` with underflow protection
  - Recursive linked-list algorithms: `llfilter`, `llpivot`

## How It Works
1. Parse file sections: `WIRES`, `GATES`, `INJECT`
2. Push injected signal changes into the event priority queue (min-time first)
3. Repeatedly:
   - Pop all events at current time
   - Apply wire state updates
   - Ask each gate to compute output changes and schedule new events

## Build & Run
```bash
make
./logicsim exclusive_or.txt > out.uml
```

## Output
The simulator prints:
	•	@startuml header
	•	state changes at each timestamp: @0, @4, @6, …

You can render out.uml with PlantUML (optional).

## Project Structure
- heap.h — generic m-ary heap
- stack.h — stack wrapper on vector
-	llrec.h / llrec.cpp — recursive linked list functions
-	logicsim/ — circuit simulator implementation
-	exclusive_or.txt — sample circuit description

## Quick Demo
```bash
bash examples/run_demo.sh
```
