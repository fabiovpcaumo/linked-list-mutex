import ctypes


class Node(ctypes.Structure):
    pass


Node.__fields__ = [
    ("next", ctypes.POINTER(Node)),
    ("data", ctypes.c_int),
]


class LinkedList(ctypes.Structure):
    _fields_ = [
        ("head", Node),
        ("int", ctypes.c_int),
    ]
