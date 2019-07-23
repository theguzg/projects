'''
Created on Jun 22, 2018

@author: Gutza
'''
from Student.entities import Student
from utils.fileutils import clearFileContent

class RepositoryException(Exception):
    pass

class FileRepository:
    def __init__(self, numeFisier):
        self.__students = []
        self.__numeFisier = numeFisier
        self.__loadFromFile()
        
    def __loadFromFile(self):
       
        with open(self.__numeFisier, "r") as f :
            for linie in f:
                linie  = linie.strip()
                args = linie.split(';')
                std = Student(int(args[0]), int(args[1]), int(args[2]), args[3], args[4], int(args[5]))
                self.__students.append(std) 

    def __saveToFile(self):
        
        with open(self.__numeFisier, "w") as f:
            for student in self.__students:
                f.write(str(student.getCodFacultate()) + ";" + str(student.getCodGrupa()) + ";" + str(student.getNrMatricol(
                    )) + ";" + student.getNume() + ";" + student.getPrenume() + ";" + str(student.getMedia()) + "\n")
                
        
    def store(self,st):
        
        if st in self.__students:
            return False
        self.__students.append(st)
        self.__saveToFile()
        
        return True
        
    def removeStd(self, nume):
        
        for student in self.__students:
            if student.getNume() == nume:
                st = student
                break
        
        self.__students.remove(st)
        self.__saveToFile()
        
    def size(self):
        return len(self.__students)
    
    def update(self, numeVechi, codFacultate, codGrupa, nrMatricol, nume, prenume, media):
            
        i = 0
        while i < len(self.__students):
            if self.__students[i].getNume() == numeVechi:
                self.__students[i].setNume(nume)
                self.__students[i].setPrenume(prenume)
                self.__students[i].setCodFacultate(codFacultate)
                self.__students[i].setCodGrupa(codGrupa)
                self.__students[i].setNrMatricol(nrMatricol)
                self.__students[i].setMedia(media)
                
                self.__saveToFile()
                return 
            i+=1

      
    def getAll(self):
        return self.__students
    
    
def testRepo():
    
    filename = "students.txt"
    
    clearFileContent(filename)
    
    repo = FileRepository(filename)
    
    assert repo.size() == 0
    
    repo.store(Student(111, 101, 20, "Gheorghe", "Gheorghescu", 10))
    repo.store(Student(111, 102, 30, "Ion", "Ionescu", 9))
    repo.store(Student(111, 103, 40, "Boteanu", "Sebastian", 5))
    
    assert repo.size() == 3
    
def testRead():
    
    filename = "students.txt"
    
    clearFileContent(filename)
    
    repo = FileRepository(filename)
    repo.store(Student(111, 101, 20, "Gheorghe", "Gheorghescu", 10))
    repo.store(Student(111, 102, 30, "Ion", "Ionescu", 9))
    
    repo2 = FileRepository(filename)
    assert repo2.size() == 2
    
testRepo()
testRead()