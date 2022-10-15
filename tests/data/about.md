# About the test data

## Folder Structure

`graphs/` contains the test graphs to be used as input to orca.
`expected/` contains the expected outputs from orca. Source: GraphCrunch2.
`actual/` should contain the output from our orca algorithm.

## Graphs

**Cn**: the cyclic graph on n nodes

- Each GDV should be identical.

**Chainn**: the chain graph on n nodes

- The GDV for node 0 and node n-1 should be identical.
- The GDV for node 1 through node n-2 should be identical.

**Kn**: the complete graph on n nodes

- each GDV should be identical

## Additional Notes

- The first value in each GDV is equal to the number of edges connected to that node.
- Our orca requires that the first line of the input graph be `[number of nodes] [number of edges]`, but GraphCrunch2 requires this line not exist.
- GraphCrunch2 returns the list of GDVs where the first value in each row is not part of the GDV, but the label of the node. Sometimes these GDVs are not listed in order, so for comparison between expected and actual, it does not suffice to ignore the first value in each row of the expected output.
