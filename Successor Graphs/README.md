Another special class of directed graphs are successor graphs. In those graphs, the outdegree of each node is 1, i.e., each node has a unique successor.

***Finding Successors:
succ(x, k) - the node that we will reach if we begin at node x and walk k steps forward. - > O(K)
Preprocessing -> O(logK)

succ(x, k) = succ(x) k = 1
             succ(succ(x, k/2), k/2) k > 1, for k is a power of 2.

succ(x, 11) = succ(succ(succ(x, 8), 2), 1)

Cycle Detection in Successor graphs:
A simple way to detect the cycle is to walk in the graph and keep track of all nodes that have been visited. Once a node is visited for the second time, we can conclude that the node is the first node in the cycle. This method works in O(n) time and also uses O(n) memory

Floyd’s algorithm:

    a = succ(x);
    b = succ(succ(x));
    while (a != b) {
        a = succ(a);
        b = succ(succ(b));
    }
First node is found by:
    a = x;
    while (a != b) {
        a = succ(a);
        b = succ(b);
    }
    first = a;

After this, the length of the cycle can be calculated as follows:
    b = succ(a);
    length = 1;
    while (a != b) {
        b = succ(b);
        length++;
    }
