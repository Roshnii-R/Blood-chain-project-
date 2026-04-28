# Blood-chain-project-
Blood Chain is a real-time emergency blood request platform designed to connect patients in critical need of blood with nearby verified donors and blood banks instantly. The system aims to eliminate the delays and communication gaps that often cost lives during medical emergencies.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Vector — donors list
Need random access (remove by index)
Array → fixed size, LinkedList → slow index access
Stack — undo
Last removed donor should return first → LIFO needed
Queue → would restore in wrong order
Queue — blood request
First requested should be served first → FIFO needed
Stack → last person would get served first, unfair
Unordered Map — search by blood group
Need O(1) search
Map → O(log n), Vector → O(n) linear search
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
feat: implement blood donor management system

- Add/view/search donors using vector and unordered_map
- Remove donor with undo support via stack (LIFO)
- Blood request queue using FIFO order
- O(1) search by blood group using unordered_map
