'''
Created on Jun 22, 2018

@author: Gutza
'''
from unicodedata import numeric


class Student:
    def __init__(self, codFacultate, codGrupa, nrMatricol, nume, prenume, media):
        
        self.__codFacultate = codFacultate
        self.__codGrupa = codGrupa
        self.__nrMatricol = nrMatricol
        self.__nume = nume
        self.__prenume = prenume
        self.__media = media
        
    def getCodFacultate(self):
        return self.__codFacultate
    
    def getCodGrupa(self): 
        return self.__codGrupa
    
    def getNrMatricol(self):
        return self.__nrMatricol
    
    def getNume(self):
        return self.__nume
    
    def getPrenume(self):
        return self.__prenume
    
    def getMedia(self):
        return self.__media
    
    def setCodFacultate(self, codFacultate):
        self.__codFacultate = codFacultate
        
    def setCodGrupa(self, codGrupa):
        self.__codGrupa = codGrupa
    
    def setNrMatricol(self, nrMatricol):
        self.__nrMatricol = nrMatricol
        
    def setNume(self, nume):
        self.__nume = nume
        
    def setPrenume(self, prenume):
        self.__prenume = prenume
        
    def setMedia(self, media):
        self.__media = media
    

def testStudent():
    
    std = Student(111, 100, 54, "Gheorghe", "Gheorghescu", 10)
    assert std.getCodFacultate() == 111
    assert std.getCodGrupa() == 100
    assert std.getNrMatricol() == 54
    assert std.getNume() == "Gheorghe"
    assert std.getPrenume() == "Gheorghescu"
    assert std.getMedia() == 10
    
    std.setCodFacultate(222)
    std.setCodGrupa(200)
    std.setNrMatricol(55)
    std.setNume("Ion")
    std.setPrenume("Ionescu")
    std.setMedia(9)
    
    assert std.getCodFacultate() == 222
    assert std.getCodGrupa() == 200
    assert std.getNrMatricol() == 55
    assert std.getNume() == "Ion"
    assert std.getPrenume() == "Ionescu"
    assert std.getMedia() == 9
    
testStudent()