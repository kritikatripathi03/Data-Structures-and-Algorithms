from turtle import forward


class Node:
    def __init__(self, data):
        self.data = data
        self.next_element = None

class LinkedList:
    def __init__(self):
        self.head_node = None
    def is_empty(self):
        return self.head_node is None
    def insert_at_head(self, value):
        current_node = Node(value)
        if self.is_empty():
            self.head_node = current_node
        else:
            current_node.next_element = self.head_node
            self.head_node = current_node
    def search_node(self, value):
        if self.is_empty():
            return False
        else:
            current_node = self.head_node
            while current_node:
                if current_node.data == value:
                    return True
                current_node = current_node.next_element
            return False
    def get_count(self):
        current_node = self.head_node
        count = 0
        while current_node is not None:
            count += 1
            current_node = current_node.next_element
        return count
    def print_list(self):
        current_node = self.head_node
        while current_node:
            print(current_node.data, end = " -> ")
            current_node = current_node.next_element
        print("None")
    def reverse_ll(self):
        current_node = self.head_node
        previous_node = None
        forward_node = None
        while current_node:
            forward = current_node.next_element
            current_node.next_element = previous_node
            previous_node = current_node
            current_node = forward
        self.head_node = previous_node
        return previous_node
    def detect_loop(self):
        slow = self.head_node
        fast = self.head_node.next_element
        while fast and slow:
            fast = fast.next_element
            if fast:
                fast = fast.next_element
            slow = slow.next_element
            if slow == fast:
                return True
        return False
    def get_mid(self):
        slow = self.head_node
        fast = self.head_node.next_element
        while slow and fast:
            fast = fast.next_element
            if fast:
                fast = fast.next_element
            slow = slow.next_element
        return slow.data
    def remove_duplicates(self):
        present = {}
        current_node = self.head_node.next_element
        previous_node = self.head_node
        present[previous_node.data] = True
        while current_node:
            if current_node.data in present:
                previous_node.next_element = current_node.next_element
                current_node.next_element = None
            else:
                present[current_node.data] = True
                previous_node = previous_node.next_element
            current_node = previous_node.next_element
            
    def oddEvenList(self):
        odd_current = self.head_node
        even_current = self.head_node.next_element
        even_head = self.head_node.next_element
        while even_current and even_current.next_element:
            odd_current.next_element = odd_current.next_element.next_element
            even_current.next_element = even_current.next_element.next_element
            odd_current = odd_current.next_element
            even_current = even_current.next_element
        odd_current.next_element = even_head
        return self.head_node

    def kreverse_ll(self, value):
        current_node = self.head_node
        previous_node = None
        forward_node = None
        cnt = 0
        while cnt < value:
            forward_node = current_node.next_element
            current_node.next_element = previous_node
            previous_node = current_node
            current_node = forward_node
            cnt += 1
        self.head_node.next_element = forward_node
        self.head_node = previous_node
lst = LinkedList()
for i in range(1, 9):
    lst.insert_at_head(i)
    lst.insert_at_head(i)
print(lst.search_node(-5))
print(lst.get_count())
lst.print_list()
lst.reverse_ll()
lst.print_list()
print(lst.get_mid())
lst.remove_duplicates()
lst.print_list()
lst.oddEvenList()
lst.print_list()
print(lst.head_node.data)
lst.kreverse_ll(3)
lst.print_list()