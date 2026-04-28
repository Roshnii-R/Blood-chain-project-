# Blood-chain-project-
# 🩸 Blood Chain

A real-time emergency blood request platform that connects patients with nearby verified donors and blood banks instantly — eliminating delays that cost lives.

---

##  Features

- Add, view, and search donors by blood group
- Remove donor with **Undo** support
- Blood request queue (FIFO — first come, first served)
- O(1) search by blood group

---

## Data Structures Used

| DS | Why | Why Not Others |
|---|---|---|
| `vector` | Donors list — random access by index | Array = fixed size, LinkedList = slow index |
| `stack` | Undo — last removed returns first (LIFO) | Queue = wrong order |
| `queue` | Blood requests — FIFO, fair order | Stack = last person served first |
| `unordered_map` | Search by blood group — O(1) | Map = O(log n), Vector = O(n) |

