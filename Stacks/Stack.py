class StackUnderFlowException(Exception):
    def __str__(self):
        return "Stack Is Empty"

class Stack:


    def __init__(self):
        self._top = -1
        self._array = []

    def push(self, element):
        if element != None:
            self._top += 1
            self._array.append(element)

    def pop(self):
        if not self.isEmpty():
            element = self._array[self._top]
            self._top -= 1
            self._array.pop()
            return element
        else:
            raise StackUnderFlowException

    def top(self):
        return self._array[self._top]


    def elements(self):
        return self._top + 1;

    def isEmpty(self):
        return self._top == -1
