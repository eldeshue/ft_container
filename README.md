
## **ft_container**

## **Introduction**

ft_container is a compilation of datastructure library, written in 'C'.

ft_container works similar with STL(Standard Template Library) in 'C++'. 
- ft_container can hold **any type of data** using void*. To use data in the container, **you need to cast void\* to the type you want**.
- Handling memories are crucial in 'C', ft_container follows **RAII pattern** for memory safety.

In ft_container, there are 3 container.
- ft_string : dynamically resizable(heap allocated), non-NULL-terminating ASCII string.
- ft_vector : dynamically resizable(heap allocated), random accessible, contiguous allocated, array. 
- ft_deque : dynamically resizable(heap allocated), double-ended queue.

It was created to help student learning 'C' in ecole42. So datastructures in ft_container are perfectly meets condition of Norminette.

## **Installation**

To install ft_container, follow these steps:

1. Clone the repository:
```
 git clone https://github.com/eldeshue/ft_container.git
```
2. Navigate to the project directory:
```
cd ft_container
```
3. Copy the folder of datastructure you need :
```
cp -r ft_{NAME}
```
4. Build the library :
```
make all
```
5. Include the header and link the library

## **Usage**

Please refer to the example codes.

## **Authors and Acknowledgment**

ft_container was created by **[eldeshue](https://github.com/eldeshue)**.

## **FAQ**

**Q:** Can I use this library with C++?

**A:** There are no good to use this library in C++, use STL. In fact, I used 'this' symbol in this code. So It can cause problem.

**Q:** Could using this library be cheating?

**A:** I'm not so sure. Copying codes are forbidden in ecole42 because it is not good for education. I recommend you to fork and modify the library. It's up to you.

**Q:** How do I use ft_container?

**A:** Clone the repo and copy the library folder to your projects, link the library to your executable.  

## **Contact**

If you have any questions or comments about Project Title, please contact **[eldeshue](mailto:eldeshue@naver.com)**.
