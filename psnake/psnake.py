#!/usr/bin/python

import sys

def generate_input( dimension):
    return [range(x*dimension, x*dimension + dimension) for x in range(0,dimension)]


def print_input ( array ):
    for row in array:
        print row

# tl stands for top left, tr sands for top right
# bl stands for bottom left, br stands for bottom right
def calculate_coords(rounds,dimension):
    corner_coords={}
    corner_coords["tf"] = {'x':rounds,'y':rounds}
    corner_coords["tr"] = {'x':dimension - 1 - rounds, 'y':corner_coords["tf"]['y']}
    corner_coords["br"] = {'x':corner_coords["tr"]['x'],'y':dimension - 1 - rounds }
    corner_coords["bl"] = {'x':corner_coords["tf"]['x'],'y':corner_coords["br"]['y']}

    return corner_coords


def snake_print(rounds, dimension, array):

    remaining_dimension = dimension - 2 * rounds

    if ( remaining_dimension == 0 ):
        return

    if ( remaining_dimension == 1):
        print ("%5d\n"%array[rounds][rounds])
        return

    coords = calculate_coords(rounds,dimension)

    result=""
    for  col in range(coords["tf"]['x'],coords["tr"]['x']) :
        result = result + ("%5d" % array[coords["tf"]['x']][col])
    print result

#     result = ""
#     result = reduce(lambda r,col:r+'{!s:>5}'.format(array[coords['tf']['x']][col]),
#                     range(coords['tf']['x'],coords['tr']['x']),
#                     '')
#     print result

    result=""
    for  row in range(coords["tr"]['y'],coords["br"]['y']):
        result = result + ("%5d" % array[row][coords["tr"]['x']])
    print result

    result = ""
    for  col in range(coords["br"]['x'],coords["bl"]['x'],-1):
        result = result +  ("%5d" % array[coords["br"]['y']][col])
    print result

    result = ""
    for row in range(coords["bl"]['y'],coords["tf"]['y'],-1):
        result = result +  ("%5d" % array[row][coords["tf"]['x']])
    print result

    rounds = rounds + 1

    snake_print(rounds,dimension,array)
    

if __name__ == '__main__':
    
    input = generate_input(10)

    print "dump the input for reference purpose\n"
    print_input( input )

    print "\n\n"
    
    print "input print out in snake pattern\n"
    snake_print(0,10,input)
    


