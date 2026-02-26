input_string = "A1=B1,C1={D1=E1,F1=G1},I1=J1"

def parse_string(input_string):
    preprocessed_string = ""
    balance = 0

    # add semicolons to easily separate tokens
    for char in input_string:
        if char == "{":
            balance += 1
        elif char == "}":
            balance -= 1
        elif char == "," and balance == 0:
            preprocessed_string += ";"
            continue
        preprocessed_string += char

    elements = preprocessed_string.split(";")
    result_dict = {}
    for element in elements:
        key,value = element.split("=",1)
        if "{" in value:
            value = parse_string(value[1:-1])
        result_dict[key] = value
    return result_dict

parsed_json = parse_string(input_string)
print(parsed_json["C1"]["D1"])