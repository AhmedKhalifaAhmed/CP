class Node():
    def __init__(self, parent, l_child, r_child, l, r, v):
        self.parent = parent
        self.l_child = l_child
        self.l = l
        self.r = r
        self.v = v


class SegTree():
    def __init__(self, arr):
        self.root = add_child(arr, 0, len(arr))

    def add_child():
        pass



def main():
    print('Hello, world!')


if __name__ == '__main__':
    main()
