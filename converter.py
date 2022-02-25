###
def big2little(string):
    array = string.split(',')
    for i in range(len(array) // 2):
        array[2 * i], array[2 * i + 1] = array[2 * i + 1], array[2 * i]
    return ','.join(array)

def rgb888to565(r, g, b):
    return ((r & 0b11111000) << 8) | ((g & 0b11111100) << 3) | (b >> 3)

def rgb888to565(rgb):
    r, g, b = rgb
    return ((r & 0b11111000) << 8) | ((g & 0b11111100) << 3) | (b >> 3)

def rgb565to888(color):
    return (((((color >> 11) & 0x1F) * 527) + 23) >> 6, ((((color >> 5) & 0x3F) * 259) + 33) >> 6, (((color & 0x1F) * 527) + 23) >> 6)

###
from PIL import Image

def dec2hexs(n):
    """
    converts an integer to a hexadecimal string
    """
    s = ''
    while n > 15:
        s = "0123456789ABCDEF"[n % 16] + s
        n //= 16
    return "0123456789ABCDEF"[n] + s

def toupper(s):
    """
    string to uppercase
    only lowercase letters are modified
    """
    _s = ''
    for c in s:
        if ord(c) >= 97 and ord(c) <= 122:
            _s += chr(ord(c) - 32)
        else:
            _s += c
    return _s

def toalphanum(s):
    """
    gets rid of the unwanted characters
    """
    _s = ''
    for c in s:
        if c in '\\ /(.)-':
            _s += '_'
        else:
            _s += c
    return _s

def convert2define(name):
    """
    returns the name of the define used according to 'name' which is the name of the file
    """
    header = toupper(toalphanum(name))
    return "__" + header + "__"

def convert(path, tile_width = 16, tile_height = 16):
    """
    converts a tileset (an image with every tile) to an array of hex number (with little endianness to work on Nspire)
    then stores this array with the appropriate format into a .h file
    which can then be directly included in the C project
    """
    im = Image.open(path)
    img = im.load()

    w, h = im.size
    tile_per_line = w // tile_width
    tile_per_column = h // tile_height

    data = []

    for i in range(tile_per_line * tile_per_column):
        for y in range(tile_height):
            for x in range(tile_width):
                ix = (i % tile_per_line) * tile_width + x
                iy = (i // tile_per_line) * tile_height + y
                #print(ix, iy)
                data += [rgb888to565(img[ix, iy][:3])]
    #data now contains the color pf each pixel of the .png file
    im.close()

    #now converting that array to a file .h directly usable and include-able

    lpath = path.split('\\')
    lpath[-1] = '_'.join(lpath[-1].split('.')[:-1]) + '.h'
    data_path = '\\'.join(lpath)

    with open(data_path, 'w') as fdata:
        define = convert2define(lpath[-1])
        fdata.write("#ifndef " + define + "\n#define " + define + "\n\n")
        fdata.write("#include <libndls.h>\n\n")
        fdata.write('#define TILES_NUMBER ' + str(len(data) // (tile_width * tile_height)) + "\n\n") #adds the appropriate #define at the beginning of the .h file

        data_name = lpath[-1].split('.')[0]
        fdata.write("uint16_t " + data_name + "[] = {") #gives a proper name to the array

        for i in range(len(data)):
            hexs = dec2hexs(data[i])
            if len(hexs) < 4:
                hexs = ("0" * (4 - len(hexs))) + hexs
            hexs = "0x" + hexs + ', '
            if i % (tile_width * tile_height) == 0: #each line will contain the data for each tile
                hexs = '\n\t' + hexs
            fdata.write(hexs)

        fdata.write("\n};\n\n")
        fdata.write("#endif")

    return data_path #returns the path of the newly created .h file
