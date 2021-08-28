from ClassGenerator import ClassGenerator

class_data = {
    "definition": {
        "className": "",
        "classParent": "",
    },
    "options": {
        "preventMultiplImport": False,
        "generateDefaultConstructor": False,
        "generateDefaultDestructor": False
    },
    "comments": {
        "classDoc": False,
        "author": "",
        "date": ""
    }
}

def askClassDefinition():
    """
    """
    global class_data
    className = input("give class name: ")
    # fixes the name format if necessary
    classParent = input("give the class parent's name if it exist: ")
    
    class_data['definition']['className'] = className
    class_data['definition']['classParent'] = classParent

def setOptions():
    """
    """
    global class_data
    # manage multople import ?
    preventMultipleInclusion = input("do you want to prevent multiple inclusion ? (y/n): ")
    if preventMultipleInclusion.lower() in ["y", "yes"]:
        class_data['options']['preventMultiplImport'] = True

    # generate default construcor
    generateDefaulConstrucor = input("do you want to generate a default construcor ? (y/n): ")
    if generateDefaulConstrucor.lower() in ["y", "yes"]:
        class_data['options']["generateDefaultConstructor"]
    
    # generate a destructor
    generateDefaulDestructor= input("do you want to generate a default destructor? (y/n): ")
    if generateDefaulDestructor.lower() in ["y", "yes"]:
        class_data['options']["generateDefaultDestructor"] = True


def addComment():
    """
    """
    global class_data
    pass

def generate():
    """
    """
    global class_data
    generator = ClassGenerator(class_data)
    generator.generate()

if __name__ == '__main__':
    askClassDefinition()
    #setOptions()
    #addComment()
    generate()