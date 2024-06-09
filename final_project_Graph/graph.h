#include <iostream>
#include <limits>

struct vertex; // forward declaration

struct edge {
    int weight;
    vertex* to_vertex;
    edge * nextedge;

    edge(int w, vertex* v) {
        weight = w;
        to_vertex = v;
        nextedge = NULL;
    }
};

struct vertex {
    int vertex_id;
    int distance = std::numeric_limits<int>::max();
    bool visited = false;
    vertex * relation;
    edge* edges_start = NULL;

    vertex() {
        vertex_id = 0;
        relation = NULL;
        edges_start = NULL;
    }

    // append given edge to end of list of edges
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

    void print_edges() {
        std::cout << "Vertex " << vertex_id << ":" << std::endl;
        edge* current = edges_start;
        if (current == NULL) {
            std::cout << "No edges\n";
        }
        while (current != NULL) {
            std::cout << "to " << current->to_vertex->vertex_id << " with weight " << current->weight << "\n";
            current = current->nextedge;
        }
    }
};

struct graph {
    vertex* vertices;
    int num_vertices;

    graph(int num) {
        vertices = new vertex[num];
        for (int i = 0; i < num; i++) {
            vertices[i].vertex_id = i;
        }
        this->num_vertices = num;
    }

    void add_edge(int from, int to, int weight) {
        // create an edge from 'from' to 'to' with weight 'weight'
            edge* e1 = new edge(weight, &vertices[to]);
            vertices[from].add_edge_tolist(e1);
            // create an edge from 'to' to 'from' with weight 'weight'
            edge* e2 = new edge(weight, &vertices[from]);
            vertices[to].add_edge_tolist(e2);

    }

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
};

