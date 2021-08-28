class ClassGenerator:
    """
    """

    def __init__(self, class_data) -> None:
        self._className = class_data['definition']['className']

    def generate(self):
        """
        """
        fileName = self._className
        extension = '.h'
        with open(fileName+extension, 'wt') as i_file:
            self.writeContain(i_file)

    def writeContain(self, i_file):
        """
        """
        classDefinition = "// code"
        i_file.write("#ifndef " + self._className.upper() + "_H\n")
        i_file.write("#define " + self._className.upper() + "_H\n")

        i_file.write("\n" + classDefinition + "\n\n")
        
        i_file.write("#endif")