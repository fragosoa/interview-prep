from collections import defaultdict
from bisect import bisect_right, insort

queries = [
    ["ADD", "0"],
    ["ADD", "1"],
    ["ADD", "1"],
    ["ADD", "11"],
    ["ADD", "22"],
    ["ADD", "3"],
    ["ADD", "5"],
    ["GET_NEXT", "0"],
    ["GET_NEXT", "1"],
    ["REMOVE", "1"],
    ["GET_NEXT", "1"],
    ["ADD", "0"],
    ["ADD", "1"],
    ["ADD", "2"],
    ["ADD", "1"],
    ["GET_NEXT", "1"],
    ["GET_NEXT", "2"],
    ["GET_NEXT", "3"],
    ["GET_NEXT", "5"]
]

def binary_search_standard(keys,element):
    result = bisect_right(keys,element)
    if keys[result] <= element:
        return ""
    return keys[result]
def binary_search(lo,hi,arr,target):
    while lo < hi:
        m = (hi-lo)//2 + lo
        if arr[m] <= target:
            lo = m + 1
        else:
            hi = m
    return "" if arr[lo] <= target else arr[lo]
def solution(queries):
    output = []
    keys = []
    elements = defaultdict(int)
    for query in queries:
        operation, element = query
        element = int(element)
        n = len(elements.keys())
        if operation == "ADD":
            elements[element] += 1
            insort(keys,element)
            output.append("")
        elif operation == "EXISTS":
            if elements[element] == 0:
                output.append("false")
            else:
                output.append("true")
        elif operation == "REMOVE":
            if elements[element] == 0:
                output.append("false")
            else:
                elements[element] -= 1
                if elements[element] == 0:
                    del elements[element]
                    keys.remove(element)
                output.append("true")
        elif operation == "GET_NEXT":
            greater_element = binary_search_standard(keys,element)
            #greater_element = binary_search(0,n-1,sorted(elements.keys()),element)
            output.append(str(greater_element))
    return output 

result = solution(queries)
results = []
for res in result:
    process_string = ""
    if res == "":
        process_string = "''"
    else:
        process_string = str(res)
    results.append(process_string)

print(results)
            
''' 
sin insort
["''", "''", "''", "''", "''", "''", "''", '1', '3', 'true', '3', "''", "''", "''", "''", '2', '3', '5', '11']
["''", "''", "''", "''", "''", "''", "''", '1', '3', 'true', '3', "''", "''", "''", "''", '2', '3', '5', '11']
'''