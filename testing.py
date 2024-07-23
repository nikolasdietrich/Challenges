def simplify_polynomal(polynomal_str):
    
    # Split string into elements seperated by "+". "-" is transformed into "+ (-1)*"
    terms = polynomal_str.replace("-", "+-").split("+") 
    
    # Remove empty elements
    terms = [term for term in terms if term]
    
    # Sort every element alphabetically
    terms = ["".join(sorted(term)) for term in terms]
    
    # Create two arrays: one with only letters, one without letters
    terms_only_variables = ["".join([character for character in term if character.isalpha()]) \
                      for term in terms]
    terms_only_coefficients =["".join([character for character in term if not character.isalpha()]) \
                      for term in terms]
    
    # Generate a coefficient for every element, so for example "xy" becomes "1*xy"
    # This way "2xy - xy" can be easily calculated
    for idx, _ in enumerate(terms_only_coefficients):
        if not terms_only_coefficients[idx]: terms_only_coefficients[idx] = "1"
        if terms_only_coefficients[idx] == "-": terms_only_coefficients[idx] = "-1"
    
    # Sum up coefficients of same variables using dictionary
    poly_dict = {}
    for idx, term_coefficient in enumerate(terms_only_coefficients):
        term_variables = terms_only_variables[idx]
        if term_variables in poly_dict:
            poly_dict[term_variables] += int(term_coefficient)
            if poly_dict[term_variables] == 0: del poly_dict[term_variables]
        else:
            poly_dict[term_variables] = int(term_coefficient)
    
    # Sort elements, first by amount of variables, second alphabetically
    poly_dict = sorted(poly_dict.items(), key = lambda x: (len(x[0]), x[0]))

    # Generate output_str
    output_str = ""
    for term_variables, term_coefficient in poly_dict:
        if term_coefficient == -1: output_str += ("-" + term_variables)
        elif term_coefficient == 1: output_str += ("+" + term_variables)
        elif term_coefficient < 0: output_str += ("-" + str(-term_coefficient) + term_variables)
        else: output_str += ("+" + str(term_coefficient) + term_variables)

    # Remove a leading "+" if necessary
    if output_str[0] == "+": output_str = output_str[1:]
    
    return output_str

if __name__ == "__main__":

    for polynomal_str in ["2xy-yx", "-a+5ab+3a-c-2a", "a+ca-ab"]:
        print("Input:", polynomal_str, "\nOutput:", simplify_polynomal(polynomal_str), "\n")