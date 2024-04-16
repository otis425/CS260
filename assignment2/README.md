# **Based on what we know about linked lists, stacks, and queues, design a queue data structure:**

Here are my design notes. I used resources from https://www.geeksforgeeks.org/queue-data-structure/ to help me understand.

![image](https://github.com/otis425/CS260/assets/71042122/010d2317-ef0c-469c-823c-7fcb5a1425a5)
![image](https://github.com/otis425/CS260/assets/71042122/a4b3d6b3-f078-4171-b56a-986fa4bd3204)

## **What functions are we likely to need for a queue to function like the one discussed in class?**

Basic functions needed for a queue to function are simply queueing new QNode objects into the Queue, and taking QNode items off the front of the queue.

## **What values will we need to know about the structure for our queue to function properly?**

The Queue needs a pointer to the first and last items, this is to take an item off the top, and to add a new item to the rear.

The QNode objects need the value they are storing, and an address to the queue item in line after them. This address is so the trail can be followed when they get pulled off the front.

# **Based on what we know about linked lists, design a list data structure that allows us to add (insert) or remove (delete) values at a given location in the list (instead of the top of a stack or the front or back of a queue):**

Here are my design notes :

![image](https://github.com/otis425/CS260/assets/71042122/10b985c1-0b15-4750-b292-c3d5b184b650)
![image](https://github.com/otis425/CS260/assets/71042122/59cebba1-2643-4a7b-a4b8-888b317d28f7)

## **What functions are we likely to need for a list to function like this?**

There would be quite a few to function like you requested. We would need adding, and deleting specific indexes, and also probably an initializing of the list. 

I used notes from arrays in that regard, as my list would not be dynamic.

## **What values will we need to know about the structure for our list to function properly?**

The List object would need the size (number of elements) and the first elements pointer. I figured we could write functions to follow the trail to the requested index. 

I know going index by index could be slow, but I didn't want the list object to hold a reference to every single element.

The LNodes would need to have their stored data, their index, and a pointer to the next indexed LNode. Technically you could operate without the LNode knowing it's index, but I bet it would be handy to reference while debugging your functions.
