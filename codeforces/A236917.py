'''https://codeforces.com/group/viIfsUpAco/contest/236917/problem/A'''

def get_line():
    return str(input()).split(' ')


def print_tree(node):
    if not node.a:
        print(node.v, end=' ')
        return
    print_tree(node.a)
    print_tree(node.b)


class Node():
    def __init__(self, a, b, l, r, v, s): # child a, child b, left, right, value, state (or / xor)
        self.a = a
        self.b = b
        self.l = l
        self.r = r
        self.v = v
        self.s = s


def add_child(arr, l, r):
    if l == r:
        new_node = Node(None, None, l, l, arr[l], True)
        return new_node
    mid = (l+r) // 2
    a = add_child(arr, l, mid)
    b = add_child(arr, mid+1, r)
    if a.s:
        new_node = Node(a, b, l, r, a.v | b.v, False)
    else:
        new_node = Node(a, b, l, r, a.v ^ b.v, True)
    return new_node


def do_query(p, b, node):
    if not node.a:
        node.v = b
        return
    mid = (node.l + node.r) // 2
    if p > mid:
        do_query(p, b, node.b)
    else:
        do_query(p, b, node.a)
    if node.s:
        node.v = node.a.v ^ node.b.v
    else:
        node.v = node.a.v | node.b.v


def main():
    line = get_line()
    n = int(line[0])
    m = int(line[1])
    line = get_line()
    arr = [int(x) for x in line]
    root = add_child(arr, 0, len(arr)-1)
    for _ in range(m):
        line = get_line()
        p = int(line[0]) - 1
        b = int(line[1])
        do_query(p, b, root)
        print(root.v)


if __name__ == '__main__':
    main()
