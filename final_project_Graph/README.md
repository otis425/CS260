# Final Project (Graph Data Structure)
## Requirements :

(20%) Create a design before you start coding that describes or shows how a graph structure could be used to store some kinds of data and attempt to solve some kind of problem (yes, this can be a game that needs a graph to represent a map!),

(20%) Create some tests (at least two for each piece of functionality) before you start coding...

(40%) Implement a graph class with at least (this category effectively combines implementation and specification, partly to emphasize getting the algorithms working!):

(5%) a function to add a new vertex to the graph (perhaps add_vertex(vertex_name)),

(5%) a function to add a new edge between two vertices of the graph (perhaps add_edge(source, destination) or source.add_edge(destination)),

(15%) a function for a shortest path algorithm (perhaps shortest_path(source, destination)),

(15%) a function for a minimum spanning tree algorithm (example min_span_tree()).

(10%) Analyze the complexity of all of your graph behaviors (effectively a part of our documentation for grading purposes),

(10%) Once you have implemented and tested your code, add to the README file what line(s) of code or inputs and outputs show your work meeting each of the above requirements (or better, include a small screen snip of where it meets the requirement!).

## Meeting Requirements :
### -  DESIGN -
<details>
  <summary>PDF</summary>
  
  ![HW - page 5](https://github.com/otis425/CS260/assets/71042122/80a401b2-2d64-4a1d-a209-965b10af7436)
  
</details>

  ### TESTS
<details>
  <summary> show </summary>
  
``` c++
// Graph
    graph g(3);
    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 2);
    g.add_edge(1, 2, 2);
    g.print_vertices();
    
    // add vertices
    g.add_vertex();
    g.add_vertex();
    g.add_edge(1, 3, 4);
    g.add_edge(1, 4, 1);
    g.add_edge(2, 3, 10);
    g.add_edge(4, 3, 2);
    g.print_vertices();

    // Min Distances
    std::cout << "Min distance from 0 to 3: ";
    std::cout << g.min_distance(0, 3) << std::endl;
    std::cout << "Min distance from 0 to 4: ";
    std::cout << g.min_distance(0, 4) << std::endl;
    std::cout << "Min distance from 0 to 1: ";
    std::cout << g.min_distance(0, 1) << std::endl;

    // Min Spanning Tree
    std::cout << "Minimum Spanning Tree\n";
    graph mst = g.min_spanning_tree();
    mst.print_vertices();
    return 0;
```

</details>

### _ Graph Struct _
#### ADDING VERTICES
<details>
  <summary>show</summary>
  
Code -
```c++
void add_vertex() {
        vertex* new_vertices = new (std::nothrow)vertex[num_vertices + 1]; // new array
        if (!new_vertices) { // check if memory allocation failed
            std::cout << "Memory allocation failed\n";
            return;
        }
        for (int i = 0; i < num_vertices; i++) { 
            new_vertices[i] = vertices[i]; // copy old v[] to new v[]
            // loop edges to update the to_vertex pointer 
            edge* current = new_vertices[i].edges_start;
            while (current != NULL) { 
                current->to_vertex = &new_vertices[current->to_vertex->vertex_id]; // update pointer
                current = current->nextedge;
            }
        }
        //id the new vertex
        new_vertices[num_vertices].vertex_id = num_vertices;
    
        delete[] vertices; // clear v[]
        vertices = new_vertices; // reassign
        num_vertices++; 
    }
```
Inputs -
```c++
g.print_vertices();
    
    // add vertices
    g.add_vertex();
    g.add_vertex();
    g.add_edge(1, 3, 4);
    g.add_edge(1, 4, 1);
    g.add_edge(2, 3, 10);
    g.add_edge(4, 3, 2);
    g.print_vertices();
```
Outputs -

![image](https://github.com/otis425/CS260/assets/71042122/543cb46f-a54d-41f6-a291-9075173eee01)

</details>

#### ADDING EDGES

<details>
  <summary>show</summary>
  
Code -
```c++
void add_edge(int from, int to, int weight) {
        // create an edge from 'from' to 'to' with weight 'weight'
            edge* e1 = new edge(weight, &vertices[to]);
            vertices[from].add_edge_tolist(e1);
            // create an edge from 'to' to 'from' with weight 'weight'
            edge* e2 = new edge(weight, &vertices[from]);
            vertices[to].add_edge_tolist(e2);

    }
// ELSEWHERE IN VERTEX STRUCT
void add_edge_tolist(edge* e){
        if (edges_start == NULL) {
            edges_start = e; // if no edges yet, add the edge to the start
        } else {
            edge* current = edges_start;
            // loop through the list of edges
            while (current->nextedge != NULL) { // find the last edge in the list
                current = current->nextedge;
            }
            current->nextedge = e; // add the edge to the end of the list
        }
    }
```
Inputs -
```c++
 // Graph
    graph g(3);
    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 2);
    g.add_edge(1, 2, 2);
    g.print_vertices();
    
    // add vertices
    g.add_vertex();
    g.add_vertex();
    g.add_edge(1, 3, 4);
    g.add_edge(1, 4, 1);
    g.add_edge(2, 3, 10);
    g.add_edge(4, 3, 2);
    g.print_vertices();
```
Outputs -

![image](https://github.com/otis425/CS260/assets/71042122/947229ad-f836-4019-901f-14accc43704a)

</details>

#### SHORTEST MINIMUM PATH

<details>
  <summary>show</summary>
  
Code -
```c++
int min_distance(int start, int end){
        // set the start vertex to 0
        vertices[start].distance = 0;
        bool foundend = false;
        int current_id = start;
        while (!foundend) {
            int distance = std::numeric_limits<int>::max();
            if (vertices[end].visited) {
                foundend = true;
            }
            for (int i = 0; i < num_vertices; i++) { // loop through all vertices
                // track the vertex with the least distance
                if (vertices[i].distance < distance && !vertices[i].visited) {
                    current_id = i; // update least distance vertex
                    distance = vertices[i].distance;
                }
            }
            vertices[current_id].visited = true; // mark visited
            // loop each connected edge
            edge* current = vertices[current_id].edges_start;
            while (current != NULL) { // update the distance of each neighbor
                if (vertices[current->to_vertex->vertex_id].distance > vertices[current_id].distance + current->weight) {
                    vertices[current->to_vertex->vertex_id].distance = vertices[current_id].distance + current->weight;
                }
                current = current->nextedge;
            }
        }
        int distance = vertices[end].distance;

        //reset the vertices
        for (int i = 0; i < num_vertices; i++) {
            vertices[i].visited = false;
            vertices[i].distance = std::numeric_limits<int>::max();
        }

        return distance;
    }
```
Inputs -
```c++
g.print_vertices();
// Min Distances
    std::cout << "Min distance from 0 to 3: ";
    std::cout << g.min_distance(0, 3) << std::endl;
    std::cout << "Min distance from 0 to 4: ";
    std::cout << g.min_distance(0, 4) << std::endl;
    std::cout << "Min distance from 0 to 1: ";
    std::cout << g.min_distance(0, 1) << std::endl;

```
Outputs -

![image](https://github.com/otis425/CS260/assets/71042122/69783284-a53d-4843-a9ff-f486d981d9c1)

</details>

#### MINIMUM SPANNING TREE

<details>
  <summary>show</summary>
  
Code -
```c++
graph min_spanning_tree() {
        graph mst(1);
        mst.vertices[0].relation = &vertices[0];
        vertices[0].visited = true;
        bool operating = true;
        while (operating) {
            int min_edgeweight = std::numeric_limits<int>::max();
            edge* min_edge = NULL;
            int min_edge_v;
            // find min edge from all mst relations in graph
            for (int i = 0; i < mst.num_vertices; i++) { // for all vertices in mst
                edge* current = mst.vertices[i].relation->edges_start; // take related vertex
                while (current != NULL) { // for all edges of the vertex
                    if (current->weight < min_edgeweight && !current->to_vertex->visited) {
                        min_edgeweight = current->weight;
                        min_edge = current;
                        min_edge_v = i;
                    }
                    current = current->nextedge;
                }
            }
            if (min_edge == NULL) {
                std::cout << "could not find next edge\n";
                operating = false;
            } else {
                mst.add_vertex();
                min_edge->to_vertex->visited = true;
                mst.vertices[mst.num_vertices - 1].relation = min_edge->to_vertex;
                mst.add_edge(mst.num_vertices - 1, min_edge_v, min_edge->weight);
            }
            if (mst.num_vertices == num_vertices) {
                operating = false;
            }
        }
        return mst;
    }

    void print_vertices() { 
        std::cout << "_ VERTEX PRINT _\n";
        for (int i = 0; i < num_vertices; i++) {
            vertices[i].print_edges();
        }
        std::cout << "\n";
    }
```
Inputs -
```c++
// Min Spanning Tree
    g.print_vertices();
    std::cout << "Minimum Spanning Tree\n";
    graph mst = g.min_spanning_tree();
    mst.print_vertices();
```
Outputs -

![image](https://github.com/otis425/CS260/assets/71042122/0128c2a3-f459-4ffb-97f5-2402a95eeaa8)

</details>

## Complexity
**Add Vertex** is O(V), because it reassigns all vertices into a new array, this is to maintain easy retrieval for more complicated functions
**Add Edge** is best O(1) and worst O(n), this function has to travel down a linked list of edges for each vertex on either side.
**Min Distance Between** is O(V^2). This is Djikstra's algorithm, and Big O is calculated as that. V being vertices
**Minimum Spanning Tree** is O(ElogV). This algorithm is Primm's Algorithm, and has been calculated as that. E - edges, V - vertices.

