'''
Created on Jun 22, 2018

@author: Gutza
'''

from Controller.controller import StudentController
from Student.entities import Student
from Repository.filerepository import FileRepository

class Console:
    def __init__(self, ctrl):
        self.__ctrl = ctrl
        
    def __showAllStudents(self):
        
        students = self.__ctrl.getAllStudents()
        
        if len(students) == 0:
            print("Inca nu este nici un student in repository !")
        else:
            for student in students:
                print(student.getCodFacultate(), student.getCodGrupa(), student.getNrMatricol(), student.getNume(), student.getPrenume(), student.getMedia())
        
    def __addStudent(self):
        codFacultate = int(input("Dati codul facultatii : "))
        codGrupa = int(input("Dati codul grupei : "))
        nrMatricol = int(input("Dati numarul matricol : "))
        nume = input("Dati numele : ")
        prenume = input("Dati prenumele : ")
        media = int(input("Dati media : "))
        
        student = self.__ctrl.createStudent(codFacultate, codGrupa, nrMatricol, nume, prenume, media)
        print("Studentul " + student.getNume() + " a fost salvat cu succes!")
        
    def __removeStudent(self):
        nume = input("Dati numele : ")
        
        self.__ctrl.removeStudent(nume)
        print("Studentul " + nume + " a fost sters cu succes!")
        
    def __updateStudent(self):
        
        numeVechi = input("Introduceti numele studentului pe care il veti modifica : ")
        nouCodFacultate = int(input("Introduceti noul cod de facultate : "))
        nouCodGrupa = int(input("Introduceti noul cod de grupa : "))
        nouNrMatricol = int(input("Introduceti noul numar matricol : "))
        nouNume = input("Introduceti noul nume : ")
        nouPrenume = input("Introduceti noul prenume : ")
        nouMedia = input("Introduceti noua medie : ")
        
        self.__ctrl.updateStudent(numeVechi, nouCodFacultate, nouCodGrupa, nouNrMatricol, nouNume, nouPrenume, nouMedia)
        
        print("Studentul " + numeVechi + " a fost updatat cu succes!")
        
    def __showCodFacultateSorted(self):
        
        students = self.__ctrl.sortCodFacultate()
        
        if len(students) == 0:
            print("There are no students yet!")
            return 
        
        for student in students:
                print(student.getCodFacultate(), student.getCodGrupa(), student.getNrMatricol(), student.getNume(), student.getPrenume(), student.getMedia())
                
    def __showCodGrupaSorted(self):
        students = self.__ctrl.sortCodGrupa()
        
        if len(students) == 0:
            print("There are no students yet!")
            return 
        
        for student in students:
                print(student.getCodFacultate(), student.getCodGrupa(), student.getNrMatricol(), student.getNume(), student.getPrenume(), student.getMedia())
        
    def __showMediaSorted(self):
        students = self.__ctrl.sortMedia()
        
        if len(students) == 0:
            print("There are no students yet!")
            return 
        
        for student in students:
                print(student.getCodFacultate(), student.getCodGrupa(), student.getNrMatricol(), student.getNume(), student.getPrenume(), student.getMedia())

    def __showNumePrenumeSorted(self):
        students = self.__ctrl.sortNumePrenume()
        
        if len(students) == 0:
            print("There are no students yet!")
            return 
        
        for student in students:
                print(student.getCodFacultate(), student.getCodGrupa(), student.getNrMatricol(), student.getNume(), student.getPrenume(), student.getMedia())
                
    def showUI(self):
        
        while True:
            print("Comenzi disponibile : ")
            print("1. Adaugare student.")
            print("2. Afisarea tuturor studentilor.")
            print("3. Sterge student.")
            print("4. Updateaza un student.")
            print("5. Studenti sortati dupa codul facultatii, crescator.")
            print("6. Studenti sortati dupa codul grupei, crescator.")
            print("7. Studenti sortati dupa medie, descrescator.")
            print("8. Studenti sortati dupa nume si prenume, crescator.")
            print("0. Exit.")
            
            cmd = int(input("Comanda : "))
            
            if cmd == 1:
                self.__addStudent()
                
            if cmd == 2:
                self.__showAllStudents()
                
            if cmd == 3:
                self.__removeStudent()
                
            if cmd == 4:
                self.__updateStudent()
                
            if cmd == 5:
                self.__showCodFacultateSorted()
                
            if cmd == 6:
                self.__showCodGrupaSorted()
                
            if cmd == 7:
                self.__showMediaSorted()
                
            if cmd == 8:
                self.__showNumePrenumeSorted()
                
            if cmd == 0:
                return