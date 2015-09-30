/*
 * Praktikum Informatik 1
 * Versuch 6.1: Templates und �berladen von Operatoren
 *
 * Datei:  StackSpeicher.h
 * Inhalt: generischer Stackspeicher
 */

#ifndef STACKSPEICHER_H_
#define STACKSPEICHER_H_

// StackClass
template<int size, class T>
class StackSpeicher
{
  public:
	StackSpeicher();
	void push (const T& e);
	void pop (T& e);
	void sort();
  
  private:
	T space[size];
	int index;
	//non voglio che gli argomenti di quick_sort siano accessibili dal main
	void quick_sort(int left, int right);
	int partition(int left, int right);
	void exchange(int x, int y);
};

template <int size, class T>
int StackSpeicher <size, T>::partition(int left, int right)
{
	int i,j,k;
	T v;
	k = right;
	v = space[k]; //Trennelement
	i = left; //Starting at left edge
	j = right-1;

	while(1)
	{
		while(i < right && space[i] <= v)
			i++;
		while(j >= left && space[j] >= v)
			j--;
		if(i > j)
			break;
		else
			exchange(i, j);
	}

	exchange(i, k);

	return i;
}

template <int size, class T>
void StackSpeicher <size, T>::exchange(int x, int y)
{
	T temp = space[x];
	space[x] = space[y];
	space[y] = temp;
}

template <int size, class T>
void StackSpeicher<size, T>::quick_sort(int left, int right)
{
	int k;
	if(right <= left)
		return;

	k = partition(left, right);
	quick_sort(left, k-1);
	quick_sort(k+1, right);
}

template <int size, class T>
void StackSpeicher <size, T> ::sort()
{
	quick_sort(0, index);
}

/**
 * @brief Constructor
 */
template <int size, class T>
StackSpeicher <size, T> :: StackSpeicher():index(-1)
{
}

/**
 * @brief Function to push an Element
 * @param e Element to save
 */
template <int size, class T>
void StackSpeicher <size, T>::push(const T& e)
{
	if (index < (size-1))
	{
		index += 1;
		space[index] = e;
	}
}

/**
 * @brief Function to retriev an Element from the Stack
 * @param e Position to save the Element
 */
template<int size, class T>
void StackSpeicher<size, T>::pop(T& e)
{
	if (index >= 0)
	{
		e = space[index];
		index -= 1;
	}
}

// Insert your Implementation here

#endif /*STACKSPEICHER_H_*/
