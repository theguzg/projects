'''
Created on Jun 22, 2018

@author: Gutza
'''

from Student.entities import Student
from Repository.filerepository import FileRepository

class StudentController:
    def __init__(self, repo):
        self.repo = repo
        
    def createStudent(self, codFacultate, codGrupa, nrMatricol, nume, prenume, media):
        
        student = Student(codFacultate, codGrupa, nrMatricol, nume, prenume, media)
        self.repo.store(student)
        
        return student
    
    def removeStudent(self, nume):
        
        self.repo.removeStd(nume)
        
    def updateStudent(self, numeVechi, codFacultate, codGrupa, nrMatricol, nume, prenume, media):
        
        self.repo.update(numeVechi, codFacultate, codGrupa, nrMatricol, nume, prenume, media)
        
    def sortCodFacultate(self):
        
        students = self.repo.getAll()
        
        return sorted(students, key=lambda student: student.getCodFacultate() ,reverse = False)
    
    def sortCodGrupa(self):
        students = self.repo.getAll()
    
        return sorted(students, key=lambda student: student.getCodGrupa() ,reverse = False)
    
    def sortMedia(self):
        students = self.repo.getAll()
        
        return sorted(students, key=lambda student: student.getMedia() ,reverse = True)
    
    def sortNumePrenume(self):
        students = self.repo.getAll()
        
        return sorted(students, key=lambda student: (student.getNume(), student.getPrenume()) ,reverse = False)
    
    def interclasare(self):
        pass
    
    def getAllStudents(self):
        return self.repo.getAll()
    
